#ifndef SORT_H_
#define SORT_H_
#include "City.h"

const char* stringForSort[NumOfSorts];
void insertionSort(void* arr, int size, int length,
		int (*comperator)(const void*, const void*));
int compareGardenByName(const void* st1, const void* st2);
int compareChildByiD(const void* st1, const void* st2);
int compareGardenByTypeAndCountChild(const void* st1, const void* st2);
void sortingMenu(City*);
#endif /* SORT_H_ */
