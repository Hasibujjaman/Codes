#include<stdio.h>
int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    int ct[3][n];
    double avg[n];
    int i,j;
    for(i=0;i<3;i++){
        printf("Enter CT %d marks of %d students\n",i+1,n);
        for(j=0;j<n;j++){
            scanf("%d",&ct[i][j]);
        }
    }
    printf("Average CT marks:\n");
    for(j=0;j<n;j++){
        avg[j]=(ct[0][j]+ct[1][j]+ct[2][j])/3;
        printf("%.2lf ",avg[j]);
    }
    printf("\n");
    return 0;
}