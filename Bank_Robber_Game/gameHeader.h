#ifndef GAMEHEADER_H
#define GAMEHEADER_H
#include <iostream>
using namespace std;
struct game//sturct containing constants
{
	const int TURNS = 200; //turns they game will be played
	const int ROBBER_WIN_CONDITION = 2022;//amount of money robbers want to win
	const int seed = 85;//random seed
	const int MAX = 10;//,max size boundary
	const int MIN = 0;//min size boundary
	const int X_Coord = 0;//0 index represents x coord 
	const int Y_Coord = 1;//1 index represents y coord
	const int CITYSIZE = 10;//city size
	const int totalJewels = 47;//amount of jewels spread out on board
	const int totalOrdinaryRobbers = 2;//amount of ordinary robbers
	const int totalGreedyRobbers = 2;//amount of greedy robbers
	const int totalPolice = 1;//amount of cops
	const int TOP_CITY_BOUNDARY = 0;//prevents objects from moving out of top boundary
	const int LEFT_CITY_BOUNDARY = 0;//prevents objects from moving out of left boundary
	const int RIGHT_CITY_BOUNDARY = CITYSIZE - 1;//prevents objects from moving out of right boundary
	const int BOTTOM_CITY_BOUNDARY = CITYSIZE - 1;//prevents objects from moving out of bottom boundary
	const int NorthWest = 0;//a number 0 through 7, each value represents a compass direction
	const int North = 1;//a number 0 through 7, each value represents a compass direction
	const int NorthEast = 2;//a number 0 through 7, each value represents a compass direction
	const int West = 3;//a number 0 through 7, each value represents a compass direction
	const int East = 4;//a number 0 through 7, each value represents a compass direction
	const int SouthWest = 5;//a number 0 through 7, each value represents a compass direction
	const int South = 6;//a number 0 through 7, each value represents a compass direction
	const int SouthEast = 7;//a number 0 through 7, each value represents a compass direction
	const int AllCompassDirectionOptions= 8;//all potential compass options
	const int pickedUpJewel = -1;//if jewel is picked its location is sent out of bounds
	const int inBagOrinBank = -1;//bagged jewels are not represented on map either
	const int inJail = -1;//removes robber from map if arrested
	const int maxGreedyMoves = 3;//amount of extra turns fro greedy robber
	const int ofAllRobbers = 0;// represents all remaining robbers
	const int ofAllPolice = 0;//represents entire police force
	const int EMPTY = 0;//if a bag is empty
	const int ONLY_ONE = 1;//if a robber bag contains 1 jewel
};
int ValidMoveSearch(const int X, const int Y);//PRE:called in every moving objects move() function. DESC. Takes in their x and y coords to see where they are on the map. POST: returns a random direction from them to move 
int X_Move( int X, const int Direction);//PRE:called after a valid  direction for the entity to move has been found. DESC: takes in x coord and direction and changes the x coord based upon the compass direction the entity will move. returns the new X position the entity movs based upon the random direction
int Y_Move( int Y, const int Direction);//PRE:called after a valid  direction for the entity to move has been found. DESC: takes in y coord and direction and changes the x coord based upon the compass direction the entity will move. returns the new Y position the entity movs based upon the random direction
void StateMovement(const string type, const int ID, const int Direction);//PRE:called after new coords on map have been set for entity after move. DESC: takes in name of object, their ID and the direction they moved in. POST: outputs a message based on the compass direction they moved in
#endif
