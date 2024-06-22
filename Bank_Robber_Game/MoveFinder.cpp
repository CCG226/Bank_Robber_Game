#include <iostream>
#include <ctime>
#include <cstdlib>
#include "gameHeader.h"
using namespace std;
int ValidMoveSearch(const int X, const int Y)
{
	int Compass = 0;//temp holds direction object will move 
	game Content;//constants
	bool hasMoved = false;//ensures object finds only one direction
	if (((X == Content.TOP_CITY_BOUNDARY) && (Y  == Content.LEFT_CITY_BOUNDARY)) && hasMoved == false)//if object is in the topleft bounds
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;//randomly picks a number between 1 and 7 to reprsent direction to move, it cant be east, southeast or south or else object will go out of bounds
		} while (Compass != Content.East && Compass != Content.SouthEast && Compass != Content.South);
		hasMoved = true;
	}
	else if (((X == Content.TOP_CITY_BOUNDARY) && (Y == Content.RIGHT_CITY_BOUNDARY)) && hasMoved == false)//if object is in topright bounds
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
		} while (Compass != Content.West && Compass != Content.SouthWest && Compass != Content.South);

		hasMoved = true;
	}
	else if (((X == Content.BOTTOM_CITY_BOUNDARY) && (Y == Content.LEFT_CITY_BOUNDARY)) && hasMoved == false)//if object is in bottom left bounds
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
		} while (Compass != Content.North && Compass != Content.NorthEast && Compass != Content.East);
		hasMoved = true;
	}
	else if (((X == Content.BOTTOM_CITY_BOUNDARY) && (Y == Content.RIGHT_CITY_BOUNDARY)) && hasMoved == false)//if object is in bottom right bounds
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
		} while (Compass != Content.North && Compass != Content.NorthWest && Compass != Content.West);
		hasMoved = true;
	}
	else if ((X == Content.TOP_CITY_BOUNDARY) && hasMoved == false)//if object is in top boundary
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
		} while (Compass == Content.North || Compass == Content.NorthEast || Compass == Content.NorthWest);
		hasMoved = true;
	}
	else if ((Y == Content.LEFT_CITY_BOUNDARY) && hasMoved == false)//if object is in left boundary
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
		} while (Compass == Content.West || Compass == Content.NorthWest || Compass == Content.SouthWest);
		hasMoved = true;
	}
	else if ((X == Content.BOTTOM_CITY_BOUNDARY) && hasMoved == false)//if object is in bottom boundary
	{
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
		} while (Compass == Content.SouthEast || Compass == Content.SouthWest || Compass == Content.South);
		hasMoved = true;
	}
	else if ((Y == Content.RIGHT_CITY_BOUNDARY) && hasMoved == false)//if object is in right boundary
	{
		
		do
		{
			Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
	
		} while (Compass == Content.NorthEast || Compass == Content.SouthEast || Compass == Content.East);
		hasMoved = true;
		
	}
	else if (hasMoved == false)//if onect is somewhere in the middle
	{
		Compass = (rand() % Content.AllCompassDirectionOptions) + Content.MIN;
	
		hasMoved = true;
	}
	return Compass;//returns int reprresenting direction
}
int Y_Move(int Y, const int Direction)
{
	
		switch (Direction)//moves positon on the column based on direction and returns new postion.
		{
		case 0://0 = Northwest and so on.
			return Y - 1;
			break;
		case 1:
			return Y;
			break;
		case 2:
			return Y + 1;
			break;
		case 3:
			return Y - 1;
			break;
		case 4:
			return Y + 1;
			break;
		case 5:
			return Y - 1;
			break;
		case 6:
			return Y;
			break;
		case 7:
			return Y + 1;
			break;
		}
	
}
int X_Move(int X, const int Direction)
{
	
		switch (Direction)//moves positon on the row based on direction and returns new postion.
		{
		case 0:
			return X - 1;
			break;
		case 1:
			return X - 1;
			break;
		case 2:
			return X - 1;
			break;
		case 3:
			return X;
			break;
		case 4:
			return X;
			break;
		case 5:
			return X + 1;
			break;
		case 6:
			return X + 1;
			break;
		case 7:
			return X + 1;
			break;
		}
	
}
