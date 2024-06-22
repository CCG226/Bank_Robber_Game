#include "Jewel.h"
void Jewel::jewelStolen_OR_returnedToCity()
{ 
	jewelLocation[contentPack.X_Coord] = contentPack.pickedUpJewel; //jewel gone from map
	jewelLocation[contentPack.Y_Coord] = contentPack.pickedUpJewel; 
}