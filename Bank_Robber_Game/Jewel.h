#ifndef JEWEL_H
#define JEWEL_H
#include <iostream>
#include "gameHeader.h"
using namespace std;
class Jewel
{
public:
	void jewelStolen_OR_returnedToCity();//PRE:Called when ever a entity picks up a jewel in puts it in bag or bank. DESC: removes jewel from board. POST: jewel no longer exists on map
	void setJLocation(const int XorY) { jewelLocation[XorY] = (rand() % contentPack.MAX) + contentPack.MIN; }// PRE:called wheneber a jewel is being placed on map in setCity or dropped from greedy robber bag. DESC takes in a 0 or 1 to represent x or y. POST: randomly sets the x and y postion of the jewel on the map
	int getJLocation(const int XorY) { return jewelLocation[XorY]; }//PRe: called whenever a jewel location is being set on map. DESC: returns x or y positon of jewel on map. POST: used to place 'J' on map
	void setJValue(const int Xpoint, const int Ypoint) { jewelValue = (Xpoint) + (Ypoint); }//PRE: called whenever a jewel is being put in their postion on the map.DESC: takes in x and y location of jewel. POST:adds the x and y locations and sets it to jewelvalue
	int getJValue() { return jewelValue; }//PRE: called whenver jewel is picked up by entity.DESC: allows entity to add jewel worth to their wealth or city. POST: returns jewel value
	void isStolen() { StolenIndicator = true;  }//PRE:called whenever robber finds jewel. DESC: jewel is now considered stolen and removed from map. POST: allows for stolen jewels to be put back on map if greedy robber drops bag
	bool getStolenI() { return StolenIndicator; }//PRE:called whenever greedy robber drops their bag. DESC: returns whether or not a jewel of 47 was stolen. POST: used for stolen jewels to be put back on map if greedy robber drops bag
	Jewel() { jewelValue = 0; jewelLocation[0] = contentPack.inBagOrinBank; jewelLocation[1] = contentPack.inBagOrinBank; StolenIndicator = false; }//PRE: whenever jewel is created at start of game or in robber bag. DESC: intializes jewel data. POST: jewel object noew exists
	Jewel operator=(const Jewel& expandingBag)//PRE: called whenever robber picks up jewel. DESC: sets contents of Lostjewel on map to contents of a new jewel created in robbers bag. POST: robber now has a jewel in their bag
	{
		jewelValue = expandingBag.jewelValue;
		jewelLocation[0] = contentPack.inBagOrinBank;
		jewelLocation[1] = contentPack.inBagOrinBank;

		return expandingBag;
	}
private:
	int jewelValue;//value of jewel
	int jewelLocation[2];// [0] = x positon. [1] = y position.
	bool StolenIndicator;//if not stolen then false
	game contentPack;//constants 

};

#endif

