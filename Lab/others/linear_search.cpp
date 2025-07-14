//Linear search program
#include<iostream>
using namespace std;

class LinearSearch{
    private:
        int ax[10];
        int x;
    public:
        void Set(){
            cout<<"Enter 10 array elements: ";
            for(int i = 0; i < 10; i++){
                cin>>ax[i];
            }
        }
        void search(){
            int flag = 0; 
            cout<<"Enter an array element that you want to search: ";
            cin>>x;
            for(int i = 0; i < 10; i++){
                if(x == ax[i]){
                    flag++;
                    if(!i) cout<<i+1<<"st element"<<endl;
                    else if(i==1) cout<<i+1<<"nd element"<<endl;
                    else cout<<i+1<<"th element"<<endl; 
                }
            }
            if(!flag) cout<<"Not found"<<endl;
        }
        
};

int main(){
    LinearSearch l;
    l.Set();
    l.search();
    return 0;
}