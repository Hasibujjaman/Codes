//Binary search program
#include<iostream>
using namespace std;

class Binary_Search{
    private:
        int ax[10];
        int x;
    public:
        void Set(){
            cout<<"Enter 10 array elements in ascending order: ";
            for(int i = 0; i < 10; i++){
                cin>>ax[i];
            }
        }
        void Search(){
            cout<<"Enter the element that you want to search: ";
            cin>>x;
            int beg , mid, end, flag;
            beg = 0; end = 9; flag = 0;
            while(beg<=end) {
                mid = (beg + end)/2;
                if(x == ax[mid]) {
                    flag++;
                    if(!mid) cout<<"1st element"<<endl;
                    else if(mid==1) cout<<"2nd element"<<endl;
                    else cout<<mid+1<<"th element"<<endl;
                    return;
                }
                else if(x > ax[mid])  beg = mid + 1;
                else end = mid - 1;
            }
            if(!flag) cout<<"Not found"<<endl;
        }
};

int main(){
    Binary_Search b;
    b.Set();
    b.Search();
    return 0;
}