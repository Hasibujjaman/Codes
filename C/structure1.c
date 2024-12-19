#include<stdio.h>
int n;
struct student
{
    int roll;
    char name[50];
    float cg;
}; // can also be declared like this: struct student{....} obj1,obj2,...;
void list_hcg(struct student[]);
//struct all[120];  //global declaration
int main(){
    printf("Enter number of students: ");
    scanf("%d",&n);
    struct student all[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter Roll of Student no. %d: ",i+1);
        scanf("%d",&all[i].roll);
        printf("Enter name of Student no. %d: ",i+1);
        //fflush(stdin); can help flush the buffer
        fflush(stdin);
        scanf("%[^\n]s",all[i].name);
        printf("Enter CGPA of Studen no. %d: ",i+1);
        scanf("%f",&all[i].cg);
    }
    list_hcg(all);
    return 0;
}

void list_hcg(struct student all[]){
    float high=0;
    for(int i=0;i<n;i++){
        if(high < all[i].cg) high = all[i].cg;
    }
    printf("Highest GPA: %f\nStudent list:\n",high);
    for(int i=0;i<n;i++){
        if(all[i].cg==high) printf("Name: %s\tRoll: %d\n",all[i].name,all[i].roll);
    }
    return;
}