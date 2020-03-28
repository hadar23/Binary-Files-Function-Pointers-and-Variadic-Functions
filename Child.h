#ifndef __CHILD__
#define __CHILD__

#include <stdio.h>

typedef struct {
	int id;
	int age;
} Child;

void readChild(FILE* fp, Child* pChild);
void getChildFromUser(Child* pChild, int id);
void showChild(const Child* pChild);
void writeChild(FILE* fp, const Child* pChild);
int findChildById(Child** pChildList, int count, int id);
void birthday(Child* pChild);
//void	releaseChild(Child* pChild);
#endif
