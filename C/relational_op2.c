#include<stdio.h>
main()
{
    int bobMissedDays = 8, bobTotalSales = 24000, bobNewCust = 32;
    if(bobMissedDays < 10 && bobTotalSales > 30000 || bobNewCust > 30) {
        printf("Bob Gets a Raise");
    }
    else{
        printf("Bob doesn't get a Raise");
    }
}