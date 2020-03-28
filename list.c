#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// create new list
int listInit(DLIST* plist) {
	if (plist == NULL)
		return 0;
	plist->head.next = NULL;
	return 1;

}

// add new node after *pNode
D_NODE* listInsert(D_NODE* pnode, DATA value) {
	D_NODE* tmp;
	if (!pnode)
		return NULL;
	if (!checkAllocation(tmp = (D_NODE*) malloc(sizeof(D_NODE))))
		return NULL;
	if (tmp)
	{
		tmp->key = value;
		tmp->next = pnode->next;
		pnode->next = tmp;
	}
	return tmp;
}

DLIST createLinkedListForKindergartenType(const City* city, int type) {
	DLIST list;
	int i;
	listInit(&list); // make new list

	for (i = 0; i < city->count; i++) {
		if (city->pGardenList[i]->type == type) {
			listInsert(&(list.head), city->pGardenList[i]);
		}
	}

	return list;

}

void displayKindergartensFroList(const DLIST* list) {
	int i;
	D_NODE* node;
	if(!list)return;
	for (node = list->head.next, i = 1; node; node = node->next, i++) {
		printf("\nKindergartens %d: \n", i);
		showGarden((Garden*) node->key);
		printf("\n");
	}

}

void gardensLinkedList(const City* pCity) {
	DLIST list;
	GardenType type;
	type = getTypeOption();
	list = createLinkedListForKindergartenType(pCity, type);
	displayKindergartensFroList(&list);
	releaseKindergartensLinkedList(&list);

}

void releaseKindergartensLinkedList(DLIST* list) {
	D_NODE *node = list->head.next;
	if (!list)
		return;

	for (; node != NULL; node = node->next)
		free(node);
}
