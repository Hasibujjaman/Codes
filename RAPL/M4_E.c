#include<stdio.h>
int main(){
    int n,arr[n][n];
    scanf("%d",&n);
    int x1,x2,y,sum,max,temp,flag;
    max = -128;
    x1 = x2 = y = 0;
    flag = 0;
    for(int i = 0; i < n; i++){
        //sum = arr[i][0];
        flag = 0;

        for(int j = 0; j < n; j++){
            scnaf("%d",&arr[i][j]);
            temp = arr[i][j];
            if(!flag){
               sum =  temp; 
            }
            else{
                sum += temp;
            }

            if(sum>max){
                if(flag) {
                    x2 = x1 + 1;
                }
                else x1 = j;
                
                flag = 1;
                max = sum;
                //x1 = j;
                y = i;

            }
            else{
                flag = 0;

            }

        }

    }


}