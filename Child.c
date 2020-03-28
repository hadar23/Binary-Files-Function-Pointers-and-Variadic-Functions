#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"
#include "sort.h"
FILETYPE fileType;
/****************************************************/
/*             Read a Child from a file		    */
/****************************************************/
void readChild(FILE* fp, Child* pChild) {
	//Child ID
	unsigned short binaryData;
	if (fileType == TEXT) {
		fscanf(fp, "%d", &pChild->id);
		fscanf(fp, "%d", &pChild->age);
	} else {
		fread(&binaryData, sizeof(short), 1, fp);
		pChild->id = binaryData & 0x1FFF;
		pChild->age = (binaryData & 0xE000) >> 13;
	}
}

/****************************************************/
/*            show a Child			    */
/****************************************************/
void showChild(const Child* pChild) {
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}

/****************************************************/
/*            get a Child From User 		    */
/****************************************************/
void getChildFromUser(Child* pChild, int id) {
	pChild->id = id;

	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}

/****************************************************/
/*		Write a Child to the open file	    */
/****************************************************/
void writeChild(FILE* fp, const Child* pChild) {
	unsigned short binarydata;
	if (fileType == TEXT)

		fprintf(fp, "%d %d\n", pChild->id, pChild->age);
	else {
		binarydata = (pChild->age << 13) | pChild->id;
		fwrite(&binarydata, sizeof(short), 1, fp);
	}
}

//linear search
int findChildById(Child** pChildList, int count, int id) {
	Child *pChild = (Child*)malloc(sizeof(Child)), *temp = NULL;
	pChild->id = id;
	pChild->age = 0;

	qsort(pChildList, count, sizeof(pChildList[0]), compareChildByiD);

	temp = (Child*) bsearch(&pChild, pChildList, count, sizeof(Child*),
			compareChildByiD);
	free(pChild);

	if (!temp)
		return -1;
	else
		return temp - (Child*) pChildList;

}

void birthday(Child* pChild) {
	pChild->age++;
}

//void	releaseChild(Child* pChild)
//{
//	//nothing to release
//}
