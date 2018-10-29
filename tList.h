#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tList* list_t;

struct tList {
	char node;
	list_t next;
};

list_t tList_init(char node);
list_t tList_add(list_t lst, char node);
list_t tList_delete(list_t lst, char node);
void tList_eraseAll(list_t lst);

