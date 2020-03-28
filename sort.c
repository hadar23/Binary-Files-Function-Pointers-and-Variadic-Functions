#include <stdlib.h>
#include "Kindergarten.h"
#include "Child.h"
#include "string.h"
#include "General.h"
#include "City.h"

const char* stringForSort[NumOfSorts] = { "Sort Kindergartens By Name",
		"Sort Kindergartens By Type", "Sort Child By Id" };

void insertionSort(void* arr, int size, int length,
		int (*comperator)(const void*, const void*)) {
	int i, j;
	void* key = malloc(size);
	for (i = 1; i < length; i++) {
		memcpy(key, arr + i * size, size);
		for (j = i - 1; j >= 0 && (comperator(arr + j * size, key) > 0); j--)
			memcpy(arr + (j + 1) * size, arr + j * size, size);
		memcpy(arr + (j + 1) * size, key, size);
	}
}

int compareGardenByName(const void* st1, const void* st2) {
	const Garden* pg1 = *(const Garden**) st1;
	const Garden* pg2 = *(const Garden**) st2;
	return strcmp(pg1->name, pg2->name);
}

int compareChildByiD(const void* st1, const void* st2) {
	const Child* pg1 = *(const Child**) st1;
	const Child* pg2 = *(const Child**) st2;
	return pg1->id - pg2->id;
}

int compareGardenByTypeAndCountChild(const void* st1, const void* st2) {
	int type;
	const Garden* pg1 = *(const Garden**) st1;
	const Garden* pg2 = *(const Garden**) st2;
	type = pg1->type - pg2->type;
	if (type != 0)
		return type;
	else
		return pg1->childCount - pg2->childCount;
}

void sortingMenu(City* city) {
	int i, option;
	do {
		for (i = 0; i < NumOfSorts; i++)
			printf("\n%d %s", i, stringForSort[i]);
		printf("\n");
		scanf("%d", &option);
	} while (option >= NumOfSorts || option < 0);
	switch (option) {

	case 0:
		insertionSort(city->pGardenList, sizeof(Garden*), city->count,
				compareGardenByName);
		break;
	case 1:
		insertionSort(city->pGardenList, sizeof(Garden*), city->count,
				compareGardenByTypeAndCountChild);
		break;
	case 2:
		for (i = 0; i < city->count; i++) {
			insertionSort((void*) city->pGardenList[i]->childPtrArr,
					sizeof(Child*), city->pGardenList[i]->childCount,
					compareChildByiD);
		}
		break;
	}
}

