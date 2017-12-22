#ifndef RESOURCE_H
#define RESOURCE_H

#include "building/building.h"

// warehouse functions
int Resource_determineWarehouseWorkerTask(building *warehouse, int *resource);

// granary functions
void Resource_gatherGranaryGettingInfo();

int Resource_getGranaryForStoringFood(
	int forceOnStockpile, int x, int y, int resource, int distanceFromEntry, int roadNetworkId,
	int *understaffed, int *xDst, int *yDst);
int Resource_getGettingGranaryForStoringFood(
	int x, int y, int resource, int distanceFromEntry, int roadNetworkId,
	int *xDst, int *yDst);
int Resource_getGranaryForGettingFood(int srcBuildingId, int *xDst, int *yDst);
int Resource_getAmountStoredInGranary(building *granary, int resource);
int Resource_addToGranary(int buildingId, int resource, int countAsProduced);
int Resource_removeFromGranary(int buildingId, int resource, int amountInUnits);
int Resource_determineGranaryWorkerTask(building *granary);
int Resource_takeFoodFromGranaryForGettingDeliveryman(int dstBuildingId, int srcBuildingId, int *resource);

// other functions
int Resource_getWorkshopForRawMaterial(int x, int y, int resource, int distanceFromEntry, int roadNetworkId, int *xDst, int *yDst);
int Resource_getBarracksForWeapon(int xUnused, int yUnused, int resource, int roadNetworkId, int *xDst, int *yDst);

void Resource_addWeaponToBarracks(building *barracks);

enum {
	StorageFigureTask_Getting = 0,
	StorageFigureTask_Delivering = 1,
};

#endif
