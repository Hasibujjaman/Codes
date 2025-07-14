//DS Assignment Q1
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
    int a;
    int power;
    Node *next;

    Node(int a, int power, Node *next){
        this->a = a;
        this->power = power;
        this->next = next;
    }
};



void InsN(Node *head, int a, int power){
    Node *newNode = new Node(a, power, NULL);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
}

void PL(Node *head){
    head =  head->next;
    Node * tmp = head;
    cout << "\n\nAnswer: ";
    while(head!=NULL){
    cout<< ((head->a > 0 && (tmp!= head))? "+ ": "") << head->a;
    if (head->power != 0) cout << "a" << "^" << head->power << " ";
    head = head->next;
  }
  cout << "\n\n";
}
void Add(Node *first, Node *second){
    Node *result = NULL;
    while (first && second) {
        int a, power;
        if(first->power == second->power) {
            a = first->a+second->a;
            power = first->power;
            first = first->next;
            second = second->next;
        }
        else if (first->power > second->power) {
            a = first->a;
            power = first->power;
            first = first->next;
        }
        else {
            a = second->a;
            power = second->power;
            second = second->next;
        }
        if(result == NULL) result = new Node(a, power, NULL);
        else InsN(result, a, power);
   }
   while(first){
        if(result == NULL) result = new Node(first->a, first->power, NULL);
        else InsN(result, first->a, first->power);
        first = first->next;
   }

   while(second){
        if(result == NULL) result = new Node(second->a, second->power, NULL);
        else InsN(result, second->a, second->power);
        second = second->next;
   }
   PL(result);
}

int main(){

    int part1{0}, part2{0};


    // Poly 1
    Node *poly1 = new Node(0, 0, NULL);       
    cout << "\nParts for polynomial 1 : ";
    cin >> part1;
    for (int i{0}; i < part1; i++) {
        cout << "Insert details of part " << i+1 << " as (a power) : ";
        int a, power;
        cin >> a >> power;
        InsN(poly1, a, power);
    }

    // Poly 2
    Node *poly2 = new Node(0, 0, NULL);       
    cout << "\nParts for polynomial 2 : ";
    cin >> part2;

cout << "P1 : " << part1 << " part2 : " << part2 << endl;

    for (int i{0}; i < part2; i++) {
        cout << "Insert details of part " << i+1 << " as (a power) : ";
        int a, power;
        cin >> a >> power;
        InsN(poly2, a, power);
    }

    Add(poly1, poly2);

    return 0;
}