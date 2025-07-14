//Job Sequencing/Schedualing
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent a job
struct Job {
    string id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profits (used for sorting)
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find the job sequence with maximum profit
void jobSequence(const vector<Job>& jobs) {
    // Sort jobs based on profits in non-increasing order
    vector<Job> sortedJobs = jobs;
    sort(sortedJobs.begin(), sortedJobs.end(), compareJobs);

    int n = jobs.size();
    vector<string> result(n," "); // Array to store the result sequence
    vector<bool> slot(n, false); // Array to keep track of available slots
    int maxProfit(0);

    // Fill the result array
    for (int i = 0; i < n; ++i) {
        // Find the first available slot with a deadline greater than or equal to the job's deadline
        // we start from the last possible slot so that we can get the vacant slot with maximum deadline
        // because we need the slots with minimal deadlines available so that we can put the upcoming jobs there
        for (int j = min(n, sortedJobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = sortedJobs[i].id;
                slot[j] = true;
                maxProfit += sortedJobs[i].profit;
                break;
            }
        }
    }

    // Display the job sequence
    cout << "Job sequence for maximum profit: ";
    for (string job : result) {
        cout << job << " ";
    }
    cout <<"\nProfit made: "<<maxProfit<<endl;
}

int main() {
    // File handling
    ifstream inputFile("jobsequence.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    // Read the number of jobs from the file
    int numberOfJobs;
    inputFile >> numberOfJobs;

    vector<Job> jobs(numberOfJobs);
    // Read job data from the file
    for (int i = 0; i < numberOfJobs; ++i) {
        jobs[i].id = to_string(i+1);
        inputFile >> jobs[i].profit;
    }
    for (int i = 0; i < numberOfJobs; ++i) {
        inputFile >> jobs[i].deadline;
    }
    
    cout<<endl;
    // Close the file
    inputFile.close();

    // Find and display the job sequence with maximum profit
    jobSequence(jobs);
    cout<<endl;
    return 0;
}
