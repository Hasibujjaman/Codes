#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int marks[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }
    for(i=0;i<n;i++){ 
        if(marks[i]>=90&&marks[i]<=100) printf("Student %d: A+\n",i+1);
        else if(marks[i]>=80&&marks[i]<=89) printf("Student %d: A\n",i+1);
        else if(marks[i]>=70&&marks[i]<=79) printf("Student %d: A-\n",i+1);
        else if(marks[i]>=60&&marks[i]<=69) printf("Student %d: B+\n",i+1);
        else if(marks[i]>=50&&marks[i]<=59) printf("Student %d: B-\n",i+1);
        else if(marks[i]>=40&&marks[i]<=49) printf("Student %d: C\n",i+1);
        else if(marks[i]>=35&&marks[i]<=39) printf("Student %d: D\n",i+1);
        else printf("Student %d: F\n",i+1);
    }
    return 0;
}