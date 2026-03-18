// Roll: 2003001
//Q1.  Consider following Code Snippet:

// function main () 

// start

//        suppose A is an integer

//        suppose  B is an integer

//        A equal 2

//        B equal 3 add A sub 5

//        print(B)

// end

// Design Lexical Analysis, Syntax Analysis, Intermediate Code Generation and Code Generation part of compiler based on the code snippet.


#include "symtab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

list_t *head = NULL;
int address = 0;
extern int lineno; 

void insert(char* name, int type)
{
    if(search(name)==NULL)
    {
        list_t* temp = (list_t*)malloc(sizeof(list_t));

        strcpy(temp->st_name, name);
        temp->st_type = type;
        temp->address = address;
        address++;

        printf("In line no %d, Inserting %s with type INT in symbol table.\n", lineno, name);

        temp->next = head;
        head = temp;
    }
    else
    {
        printf("In line no %d, Same variable %s is declared more than once.\n", lineno, name);
    }
}

list_t* search(char *name)
{
    list_t* current = head;

    while(current!=NULL)
    {
       if(strcmp(name, current->st_name)!=0)
        current = current->next;
       else
        break;
    }

    return current;
}

int idcheck(char* name)
{
    list_t *id = search(name);
    if(id==NULL)
    {
        printf("In line no %d, ID %s is not declared.\n", lineno, name);
        return -1;
    }
    else
    {
        return id->address;
    }
}

