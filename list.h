#ifndef LIST_H_
#define LIST_H_
#include "City.h"


typedef void* DATA;

//NODE
typedef struct d_node{
	DATA key;
	struct d_node* next;
}D_NODE;

typedef struct
{
	D_NODE head;
}DLIST;

int listInit(DLIST* plist);
D_NODE* listInsert(D_NODE* pnode,DATA value);
void displayKindergartensFroList(const DLIST*);
DLIST createLinkedListForKindergartenType(const City* city, int type);
void releaseKindergartensLinkedList(DLIST* list);
void gardensLinkedList(const City* pCity);

#endif /* LIST_H_ */
