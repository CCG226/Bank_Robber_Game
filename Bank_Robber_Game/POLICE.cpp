#include "POLICE.h"
#include <iostream>
using namespace std;
int POLICE::totalCaught = 0;
POLICE::POLICE()//intializes 
{
	totalCaught = 0;
	policeID = 0;
	confiscatedJewels = 0;
	policeCoord[0] = 0;
	policeCoord[1] = 0;

}
bool POLICE::arrest(const string RobberType, const int ID)
{
	totalCaught++;//adds robber caught to total caught index
	cout << RobberType << " " << ID << " has been caught by Police officer " << policeID << " !!!" << endl;
  cout << "Officer has now accumulated and returned a value of $" << confiscatedJewels << " back to the city." << endl;
	cout << "Officers have caught " << totalCaught << " Robbers now" << endl;
	return true;//returns true as parameter to caught() robber function to deactive and delete that robber from the board
}
int POLICE::move()
{
	game Content;
	int temp = 0;
	temp = ValidMoveSearch(policeCoord[Content.X_Coord], policeCoord[Content.Y_Coord]);//finds a valid spot for police officer to move
	return temp;//returns direction to move 
}