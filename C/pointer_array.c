#include <stdio.h> 
#include <string.h>
int search(char *p[], char *name);
char *names[] = { "Herb","Rex","Dennis","John ",NULL}; /* null pointer constant ends the list */

int main(void) {
if(search(names, "Dennis") != - 1)
printf("Dennis is in list.\n");
if(search(names, "Bill") == -1) printf("Bill not found.\n");
return 0; 
}

/* Look up a name. */
int search(char *p[], char *name) {
register int t;
for(t=0; p[t]; ++t) if(!strcmp(p[t], name)) return t;
return -1; /* not found */ 
}