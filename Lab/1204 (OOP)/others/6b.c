#include<stdio.h>

struct cricket{
    int Trun,Twick,Tcatch;
    char NIC[3][30];
};

int main(){
    int n;
    printf("Enter number of cricketers: ");
    scanf("%d",&n);
    struct cricket str[n];
    for(int i=0;i<n;i++){
        printf("Enter Runs,Wickets,Catches,Name,ID,Country of %dth person: ",i+1);
        scanf("%d %d %d",&str[i].Trun,&str[i].Twick,&str[i].Tcatch);
        scanf(" %[^\n]/s",str[i].NIC[0]);
        //gets(str[i].NIC[0]);
        scanf("%s",str[i].NIC[1]);
        scanf("%s",str[i].NIC[2]);
    }
    printf("%s %s %s\n", str[0].NIC[0], str[0].NIC[1], str[0].NIC[2]);
    printf("%s %s %s\n", str[1].NIC[0], str[1].NIC[1], str[1].NIC[2]);
    // printf("Here\n");
    double avgR,avgW,avgC;
    int sumR = 0,sumW = 0,sumC = 0;
    for(int j=0;j<n;j++){
        sumR+=str[j].Trun;
        sumW+=str[j].Twick;
        sumC+=str[j].Tcatch;
    }
    printf("Average runs: %lf\nAverage wickets: %lf\nAverage catches: %lf\n",(double)sumR/n,(double)sumW/n,(double)sumC/n);
    return 0;
}