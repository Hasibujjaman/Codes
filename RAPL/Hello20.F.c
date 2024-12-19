#include<stdio.h>
long long gcd(long long a,long long b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(){
    long long A,B,C,D,c,d,cd,r,lcm,x;
    scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
    r=B-A+1; //total numbers between A,B
    lcm=(C*D)/gcd(C,D); // LCM of C,D
    A--;
    c=B/C-A/C; // Divisors of C between A,B
    d=B/D-A/D; // Divisors of D between A,B
    cd=B/lcm-A/lcm; // Divisors of C&D betweem A,B
    x=r-c-d+cd;
    printf("%lld\n",x);
    return 0;
}