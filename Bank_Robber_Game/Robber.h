#ifndef ROBBER_H
#define ROBBER_H
#include <iostream>
#include "Jewel.h"
using namespace std;
class Robber//base class
{
public:
	int getFortune() { return jewelFortune; }//PRE: when individual robber wealth is outputted at end of turn. DESC: gets individual robbers jewel wealth. POST: returns their fortune 
	int getReturnAJewel(int index) {  return bag[index].getJValue(); }//PRE: called when robber is arrested. DESC: gives jewels over to city and takes in index of a jewel stolen. POST: returns a stolen jewels value
	int getAmountOfJewels() { return AmountOfStolenJewels;  }//PRE: called whenever amount of stolen jewels is needed to know how much is needed to be given to cop if robber is caught. DESC: to get amount of jewels a robber stole. POST: returns that amount
	void setRLocation(const int XorY) {robberCoord[XorY]= (rand() % Contentpack.MAX) + Contentpack.MIN;}//PRE:called at start of game.DESC: takes in 0 or 1 to represent x or y.POST: sets random x or y position of robber
	void setRNewLocation(const int XorY, const int newPosition) { robberCoord[XorY] = newPosition; }//PRE: called whenever a robber moves a direction.DESC: takes in 0 or 1 to represent x or y with the new x or y postion.POST: sets x or y postion to new x or y postion 
	int getRLocation(const int XorY) { return robberCoord[XorY]; }//PRE: called whenever a robber moves.DESC: takes in 0 or 1 to represent x or y. POST: returns objects x or y location
	void setRobberID(const int ID_number) { robber_ID = ID_number; }//PRE: called during creation of robber objects. DESC: takes in index + 1 of object created to reprsent id.POST: sets robber ID
	int getRobberID() { return robber_ID; }//PRE:whenver indvidual robber needs to be outputted or arrested. DESC: robber ID: POST: returns their ID 
	void caught(bool Captured) {
		arrested = Captured; robberCoord[Contentpack.X_Coord] = Contentpack.inJail; robberCoord[Contentpack.Y_Coord] = Contentpack.inJail; totalJewelFortune = totalJewelFortune - jewelFortune; jewelFortune = 0;}//PRE:called when police and robber collide. DESC: deletes robber from board. POST: robbers lost a member to jail
	bool getArrested() { return arrested; }//PRE: at start of turn a robber is checked to see if they have been arrested. DESC: if they have they cant move no more. POST: returns bool determining if they been caught.
	static int totalJewelFortune;//counts stolen wealth of all robbers 
	void pickUpJewel(int Jewel);//PRE: called when robber finds a jewel. DESC: takes int jewel's worth. POST: creates a jewel in robbers bag with picked up jewels worth
	Robber();//PRE: called when robbers are created at start. DESC: intializes robber object. POST: robber object constructed 
	~Robber();//PRE:Called when robbers out of scope. DESC: deallocates and returns bag pointer memory. POST: pointer of jewels has been deleted and robber object deconstructed
protected:
	int robber_ID;//id
	int robberCoord[2];// [0] = x positon. [1] = y position.
	Jewel* bag;// pointer bag of jewels
	int jewelFortune;//indivdual robber wealth stolen
	bool arrested; //if robber has been caught it is true
	game Contentpack;//constants
	int AmountOfStolenJewels;//contains amount stolen by a robber object
	int bagSize = 5;//initalize size of robber bag
	Jewel* newBag;
};
class Ordinary_Robber: public Robber//derived class
{
public: 

	int move();//PRE: called when its ordinary robbers turn to move. DESC: finds valid direction for police to move. DESC: returns a direction for them to move

private:

};
class Greed_Robber : public Robber//dervied class
{
public:
	int bagDrop(Jewel orginialJewels[], char board[][10]);//PRE: when a greedy robber runs into another robber. DESC: takes in array of jewels on board and the board itself. POST: removes half the jewels in greedy robbers bag and spreads them across the city
	int move();//PRE: called when its greedy robbers turn to move. DESC: finds valid direction for police to move. DESC: returns a direction for them to move
private:
	const int Halved = 2;//to drop half of jewels
	int AmountofJewelsDropped;//count of jewels dropped
};
#endif
