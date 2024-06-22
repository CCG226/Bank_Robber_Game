#ifndef POLICE_H
#define POLICE_H
#include <iostream>
#include "gameHeader.h"
using namespace std;
class POLICE
{
public:
	void setPNewLocation(const int XorY, const int newPosition) { policeCoord[XorY] = newPosition; }//PRE: called whenever a police officer moves a direction.DESC: takes in 0 or 1 to represent x or y with the new x or y postion.POST: sets x or y postion to new x or y postion 
	void setReturnedJewels(int Value) { confiscatedJewels = Value;  }// PRE: called when cop picks up jewel from tile or robber. DESC: takes in jewel value. POST: adds jewel worthback to city
	int getReturnedJewels() { return confiscatedJewels; }//PRE: called during output statemnet of how much a cop has returned to the city.
	void setPoliceID(const int ID_number) { policeID = ID_number; }//PRE: called during police officer creation in setCity. DESC: takes in index in which police object is created + 1. POST: sets officers ID num.
	int getPoliceID() { return policeID; }//PRE: called whenver a indivdual cop is being outputted. DESC: output statement with thier id. POST: returns cop ID
	void setPLocation(const int XorY) { policeCoord[XorY] = (rand() % pack.MAX) + pack.MIN; }//PRE: called whenver a POLICE object is created during city creation.DESC: takes in 0 or 1 to represent x or y. POST: randomly sets police object on map at start
	int getPLocation(const int XorY) { return policeCoord[XorY]; }//PRE: called whenever a cop moves.DESC: takes in 0 or 1 to represent x or y. POST: returns objects x or y location
	bool arrest(const string RobberType,const int ID);//PRE: called when a cop runs into a robber or vice versa. DESC: takes in name of robber type and that robbers id. POST:arrests and confiscated jewels and adds a count  to totalCaught.
	int move();//PRE: called when its police turn to move. DESC: finds valid direction for police to move. DESC: returns a direction for them to move
	POLICE();// PRE: called during police object creation at start. DESC: intialzes cop data. POST: cop is ready to play. 
	static int totalCaught;//keeps track of robbers caught
private:
	int policeID;// police id 
	int policeCoord[2];// [0] = x positon. [1] = y position.
	int confiscatedJewels;//keeps track of jewels taken back from arrested robber or picked up on map.
	game pack;//constants 


};
#endif

