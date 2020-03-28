#include <stdio.h>

#include "City.h"
#include "Kindergarten.h"

char* dataFile = '\0';

void readCity(City* pCity) {

	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}

	selectDataFile();

	pCity->pGardenList = readAllGardensFromFile(dataFile, &pCity->count);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void selectDataFile() {
	if (fileType == TEXT)
		dataFile = TEXT_FILE;
	else
		dataFile = BIN_FILE;
}

void showCityGardens(City* pCity) {
	showAllGardens(pCity->pGardenList, pCity->count);
}

void showSpecificGardenInCity(City* pCity) {
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity) {
	selectDataFile();
	writeGardensToFile(pCity->pGardenList, pCity->count, dataFile);
}

void cityAddGarden(City* pCity) {
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL) //Allocation error
		printf("Error adding kindergarten\n");
}

void addChildToSpecificGardenInCity(City* pCity) {
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void birthdayToChild(City* pCity) {
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int countChova(City* pCity) {
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void releaseCity(City* pCity) {
	release(pCity->pGardenList, pCity->count);
}
