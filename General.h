#ifndef __PROTOTYPE__
#define __PROTOTYPE__

typedef enum {
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_MANU,
	LINKED_LIST,
	NofOptions
} MenuOptions;

typedef enum {
	SORT_CHILDREN_BY_ID,
	SORT_KINDERGARTEN_BY_NAME,
	SORT_KINDERGARTEN_BY_TYPE,
	NumOfSorts
} SortType;

typedef enum
{
	TEXT,
	BINARY
}FILETYPE;

extern FILETYPE fileType;

int menu();
char* getStrExactLength(char* inpStr);
int checkAllocation(const void* p);
void VariadicFunction(const char* str,...);

void displayKindergartensFroList();

#endif
