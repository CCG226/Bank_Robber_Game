#include <iostream>
#include <ctime>
#include <cstdlib>
#include "gameHeader.h"
using namespace std;
void StateMovement(const string type,const int ID,const int Direction)
{
	
	switch (Direction)//prints movement based on direction an object makes
	{
	case 0:
		cout << type << " " << ID << " moved a space in the NorthWest direction." << endl;
		break;
	case 1:
		cout << type << " " << ID << " moved a space in the North direction." << endl;
		break;
	case 2:
		cout << type << " " << ID << " moved a space in the NorthEast direction." << endl;
		break;
	case 3:
		cout << type << " " << ID << " moved a space in the West direction." << endl;
		break;
	case 4:
		cout << type << " " << ID << " moved a space in the East direction." << endl;
		break;
	case 5:
		cout << type << " " << ID << " moved a space in the SorthWest direction." << endl;
		break;
	case 6:
		cout << type << " " << ID << " moved a space in the South direction." << endl;
		break;
	case 7://7 == southEast and so on
		cout << type << " " << ID << " moved a space in the SouthEast direction." << endl;
		break;
	}
}