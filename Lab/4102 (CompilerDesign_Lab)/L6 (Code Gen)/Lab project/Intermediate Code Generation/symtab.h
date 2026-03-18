#define INT_TYPE 1

typedef struct list_t
{
    char st_name[40];
    int st_type;
    int address;
    struct list_t *next;
} list_t;

void insert(char* name, int type);
list_t* search(char *name);
int idcheck(char* name);




