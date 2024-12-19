#include <stdio.h>
main()
{
    int custAge = 38;
    char* legalAge = (custAge > 21) ? "true" : "false"; // character array, conditional operator. 
    printf("Is the customer of legal age? %s\n", legalAge);

    int numofproduct = 10;
    printf("I bought %s products\n", (numofproduct > 1) ? "many" : "one");

}