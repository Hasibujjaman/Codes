//Sparce matrix program
#include<iostream>
using namespace std;

class Matrix{
    private:
        int ax[4][5];
        int s[21][3];
        int n;
    public:
        void Set(){
            cout<<"Enter 20 array elements: ";
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 5; j++){
                    cin>>ax[i][j];
                }
            }
        }
        void Sprace(){
            int k = 0;
            s[0][0] = 4; s[0][1] = 4;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j< 5; j++){
                    if(!ax[i][j]) {
                        k++;
                        s[k][0] = i;
                        s[k][1] = j;
                        s[k][2] = ax[i][j];
                    }
                }
            }
            s[0][2] = k;
            n = k;
        }
        void GetS(){
            cout<<"Rows\t"<<"Columns\t"<<"Values\t"<<endl;
            for(int i = 0; i < n; i++){
                cout<<s[i][0]<<"\t"<<s[i][1]<<"\t"<<s[i][2]<<"\t"<<endl;
            }
        }
};
 int main(){
    Matrix s;
    s.Set();
    s.Sprace();
    s.GetS();
    return 0;
 }