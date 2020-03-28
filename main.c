#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"
#include "sort.h"
#include "list.h"

const char* typeName[2] = { "TEXT", "BINARY" };

FILETYPE fileType;
int main(int argc, char* argv[]) {
	City utz = { NULL, 0 };

	int uReq;

	if (argc != 2 || (*argv[1] != '1' && *argv[1] != '0')) {
		printf("you have to enter 0 for text file or 1 for binary file");
		return -1;
	}

	fileType = (*argv[1] == '0' ? TEXT : BINARY);

	//first time read
	readCity(&utz);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY:
			readCity(&utz);
			break;

		case SHOW_CITY:
			showCityGardens(&utz);
			break;

		case SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY:
			saveCity(&utz);
			break;

		case ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",
					countChova(&utz));
			break;

		case SORT_MANU:
			printf("\nSelect sort :\n");
			sortingMenu(&utz);
			break;
		case LINKED_LIST:
			gardensLinkedList(&utz);
			break;

		}
	} while (uReq != EXIT);

	releaseCity(&utz); //free all allocations

	return EXIT_SUCCESS;
}

