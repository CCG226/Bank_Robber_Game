
#ifndef CITY_H
#define CITY_H
#include <iostream>
#include "Jewel.h"
#include "Robber.h"
#include "POLICE.h"
#include "gameHeader.h"
using namespace std;
class City
{
public:
	City();//PRE:called when city object board is made in main. DESC: intializes city map and data. POST: city has been creted
	void setCity();//PRE:called at start of main.DESC: spits all objects onto the board in their own personal tile.. POST: game is ready.
	void print();//PRE:called at start and after every turn. DESC: prints a readable city map of whats going on. POST: shows object moevement per turn
	void Turn();// PRE:called every turn. DESC: core compenent of the game POST: proccesses movement of all entities per turn. 
	int findJewelObject(const int XLocation, const int YLocation);//PRE: called whenever a cop or robber finds a jewel on a tile. DESC: takes in x and y postion of cop or robber that landed on jewel. POST:finds and returns matching jewel index on that tile for cop or robber to take.
	int findOfficer(const int XPos, const int YPos);//PRE:called whenvever a robber runs into a cop on a tile. DEC: takes x/y position of robber. POST: finds and returns matcinng police officer index so that that cop will arrest the robber who ran into them
	void findRobberObject(const int XPos, const int Ypos,const int pindex);//PRE: called whenever a cop runs into a robber on a tile. DESC: takes x and y postion of cop and police officer index.POST: finds the 1 or more robbers on that tile and arrests them
	bool getPoliceWin() { return PoliceWin; }//PRE: called when totalcaought = total amount of robbers. DESC: returns police win as true. POST: game will end 
	bool getRobberWin() { return RobberWin; }//PRE: called when robbers reach 2022. dESC: returns robber win as true. POST: game ends
	void Summary(const string winnerPrint);// PRE: called at end of game in main. DESC: takes in winning message based on who won. POST: outprints summary of game data.
private:
	Jewel jewel[47];//amount of jewel objects in city
	Ordinary_Robber Orobber[2];//amount of  ordinary robber objects in city
	Greed_Robber Grobber[2];//amount of  greedy robber objects in city
	POLICE Police_Officer[1];//amount of cops objects in city
	char cityMap[10][10];//city size
	int numberOfLostJewels;//counts jewels that havent been picked up by robber or cop
	bool PoliceWin = false;//is true if police win
	bool RobberWin = false;//true is robbers win
	game content;//constants 

};
#endif

