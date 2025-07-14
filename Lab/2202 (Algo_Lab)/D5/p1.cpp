//Fractional Knapsack 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int originalIndex;
    double profit;
    double weight;
    double weightFraction = 0.0; // Xi
};

// Compare items based on weight alone in descending order
bool compareItems1(const Item &item1, const Item &item2)
{
    return item1.weight > item2.weight;
}
// Compare items based on profit alone in descending order
bool compareItems2(const Item &item1, const Item &item2)
{
    return item1.profit > item2.profit;
}
// Compare items based on profit per unit weight in descending order
bool compareItems3(const Item &item1, const Item &item2)
{
    return (item1.profit / item1.weight) > (item2.profit / item2.weight);
}
// Compare items based on original index
bool compareItems4(const Item &item1, const Item &item2)
{
    return item1.originalIndex < item2.originalIndex;
}

void fractionalKnapsack(int n, double weightCap, vector<Item> &items, int choice)
{
    //vector<Item> items = originalItems; // a copy of the original one so that origal one remains intact
    if (choice == 1)
    {
        // Sort items based on weight alone in descending order
        sort(items.begin(), items.end(), compareItems1);
    }
    else if (choice == 2)
    {
        // Sort items based on profit alone in descending order
        sort(items.begin(), items.end(), compareItems2);
    }
    else
    {
        // Sort items based on profit per unit weight in descending order
        sort(items.begin(), items.end(), compareItems3);
    }

    double totalprofit = 0.0;   // Total profit of items selected
    double currentWeight = 0.0; // Current weight in the knapsack

    for (int i = 0; i < items.size(); i++)
    {
        if (currentWeight + items[i].weight <= weightCap)
        {
            // Add the entire item if it fits in the knapsack
            totalprofit += items[i].profit;
            currentWeight += items[i].weight;
            items[i].weightFraction = 1;
        }
        else
        {
            // Add a fraction of the item if it doesn't fit entirely
            double remainingBostaCap = weightCap - currentWeight;
            double fraction = remainingBostaCap / items[i].weight;
            items[i].weightFraction = fraction;
            totalprofit += fraction * items[i].profit;
            break; // Knapsack is full
        }
    }
    sort(items.begin(), items.end(), compareItems4);
    // for (const Item &item : items)
    // {
    //     //cout << "Item " << item.originalIndex + 1 << ":\tWeight Fraction: " << item.weightFraction << "\tWeight taken: " << item.weightFraction * item.weight << "\tBenifit acquired: " << item.weightFraction * item.profit << endl;
    //     cout<<item.weightFraction<<" ";
    //     item.weightFraction = 0.0;

    // }
    for(int i = 0; i < items.size(); i++){
        cout<<"item "<<i+1<<":\tprofit acquired: "<<items[i].weightFraction*items[i].profit<<"\tWeight taken: "<<items[i].weightFraction*items[i].weight<<"\tweight fraction: "<<items[i].weightFraction<<"\tprofit to weight ratio: "<<items[i].profit/items[i].weight<<endl;
        //cout<<items[i].weightFraction<<" ";
        items[i].weightFraction = 0;
    }
    cout << "\nTotal profit in the knapsack: " << totalprofit << endl<< endl;
}

int main()
{   cout<<endl;
    ifstream inputFile("knapsack.txt"); // Replace with your input file name

    if (!inputFile.is_open())
    {
        cout << "Error opening the file.\n";
        return 1;
    }

    int n;    // Number of items
    double W; // Weight capacity of the knapsack
    int k = 0;
    while (!inputFile.eof())
    {
        ++k;
        printf("\n\n\n\n############## Knapsack %d ###############\n\n",k);
        inputFile >> n >> W; // reading number of items and knapsack capacity

        vector<Item> items(n);
        vector<double> weightFractions(n); // Xi

        // reading weights
        for (int i = 0; i < n; ++i)
        {
            items[i].originalIndex = i;

            inputFile >> items[i].weight;
        }
        // reading profits
        for (int i = 0; i < n; ++i)
        {
            inputFile >> items[i].profit;
        }
        cout<<"Feasible Solution 1 (Blind for weight):"<<endl;
        cout<<"--------------------------------------"<<endl;
        fractionalKnapsack(n, W, items, 1);

        cout<<"Feasible Solution 2 (Blind for profit):"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        fractionalKnapsack(n, W, items, 2);
        cout<<"Optimal Solution (Maximum profit):"<<endl;
        cout<<"-----------------------------------"<<endl;
        fractionalKnapsack(n, W, items, 3);
    }
    inputFile.close();

    return 0;
}
