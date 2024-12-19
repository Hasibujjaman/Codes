// Topic 8
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm> // for find() method
using namespace std;

void Display(list<int> *p){
    list <int> :: iterator i;
    for( i = p->begin(); i != p->end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}
void DisplayRev(list <int> q){
    list <int> :: reverse_iterator i;
    for(i = q.rbegin(); i != q.rend(); i++){
        cout<<*i<<" ";
    } 
    cout<<endl;
}

bool is_odd(int x){
    return (x%2);
}

int main(){
    list <int> li;
    for(int i = 1; i <= 16; i+=2) li.push_back(i);
    li.push_front(-1);
    li.push_front(-3);
    Display(&li);
    DisplayRev(li);
    cout<<"Front element: "<<li.front()<<endl;
    cout<<"Back element: "<<li.back()<<endl;
    li.pop_back();
    cout<<"After popping back element:"<<endl;
    Display(&li);
    li.pop_front();
    cout<<"After popping front element:"<<endl;
    Display(&li);
    int x = 5;
    list <int> :: iterator j;
    j = find(li.begin(), li.end(), x);
    if(j == li.end()) cout<<x<<" not found in list"<<endl;
    else cout<<x<<" found in list . Index : "<<distance(li.begin(),j)<<endl;
    x = 15;
    j = li.end();
    li.insert(j,x);
    Display(&li);
    x = 17;
    j--;
    li.insert(next(j,1),x);
    Display(&li);
    cout<<"5 is counted: "<<count(li.begin(),li.end(),5)<<" time(s)"<<endl;
    cout<<"Odd numbers: "<<count_if(li.begin(),li.end(),is_odd)<<endl;
    x = -1;
    j = find(li.begin(),li.end(),x);
    li.erase(j);
    Display(&li);
    list<int>::iterator end = li.begin();
    advance(end, 4); // end+=4; doesn't work
    li.erase(li.begin(), end);
    Display(&li);
    li.remove(17);
    Display(&li);
    li.remove_if(is_odd);
    Display(&li);
    list<int> lli;
    int arr[8];
    for(int i = 1, j = 0; i <= 16; i+=2,j++) {
        lli.push_back(i);
        arr[j] = i + 1;
    }
    li.assign(lli.begin(),lli.end());
    Display(&li);
    li.assign(arr,arr+8);
    Display(&li);
    li.sort();
    Display(&li);
    li.unique();
    Display(&li);
}