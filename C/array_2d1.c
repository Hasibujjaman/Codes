#include<stdio.h>
int main(){
    int row=4;
    int col=10;
    int arr[4][10]= { //int arr[row][col] = {..........} not allowed
        {80,70,31,34,74,93,93,83,92,82},
        {81,83,91,94,97,92,84,74,84,93},
        {90,91,95,93,95,93,96,84,82,78},
        {0,0,0,0,0,0,0,0,0,0}
    };
    int arr1[row][col];
    arr1[0][0]=0;
    printf("%d\n",arr[0][0]);
    printf("%d\n",arr1[0][0]);
    int i;
    for(i=0;i<col;i++){
        arr[3][i]=arr[0][i]*.25+arr[1][i]*.25+arr[2][i]*.5;
        printf("Roll No: %d\t Total Marks: %d\n",i+1,arr[3][i]);
    }
    return 0;
}