#include "City.h"
#include <iostream>
#include "Robber.h"
#include "Jewel.h"
#include "POLICE.h"
#include <ctime>
#include <cstdlib>
#include "gameHeader.h"
using namespace std;
City::City()
{
	numberOfLostJewels = content.totalJewels;//jewels remaining on the board
	for (int i = 0; i < content.CITYSIZE; i++)//creates city 
	{
		for (int j = 0; j < content.CITYSIZE; j++)
		{
			cityMap[i][j] = ' ';
		}
	}
}
void City::setCity()
{
	int index_of_all_robber_types = 0;//to intialize both ordinary and greedy robbers with the right ID's 
	for (int i = 0; i < numberOfLostJewels; i++)//sets jewel locations in the city map and sets jewels valuse based upon location
	{
		do
		{
			jewel[i].setJLocation(content.X_Coord);
			jewel[i].setJLocation(content.Y_Coord);
		} while (cityMap[jewel[i].getJLocation(content.X_Coord)][jewel[i].getJLocation(content.Y_Coord)] != ' ');//must be on empty space
		cityMap[jewel[i].getJLocation(content.X_Coord)][jewel[i].getJLocation(content.Y_Coord)] = 'J';//jewel represented by J
		jewel[i].setJValue(jewel[i].getJLocation(content.X_Coord), jewel[i].getJLocation(content.Y_Coord));
	}
	for (int i = 0; i < content.totalOrdinaryRobbers; i++)//sets ordinary orbbers locations on the map and ID
	{
		do
		{
			Orobber[i].setRLocation(content.X_Coord);
			Orobber[i].setRLocation(content.Y_Coord);
		} while (cityMap[Orobber[i].getRLocation(content.X_Coord)][Orobber[i].getRLocation(content.Y_Coord)] != ' ');//must be on empty space
		index_of_all_robber_types++;
		Orobber[i].setRobberID(index_of_all_robber_types);
		cityMap[Orobber[i].getRLocation(content.X_Coord)][Orobber[i].getRLocation(content.Y_Coord)] = 'R';//ordinary robber represented by 'R'
	}
	
	for(int i = 0; i < content.totalGreedyRobbers;i++)//sets greedy robber locations on the map and ID
		{
			do
			{
				Grobber[i].setRLocation(content.X_Coord);
				Grobber[i].setRLocation(content.Y_Coord);
			} while (cityMap[Grobber[i].getRLocation(content.X_Coord)][Grobber[i].getRLocation(content.Y_Coord)] != ' ');//must be on empty space
			index_of_all_robber_types++;
			Grobber[i].setRobberID(index_of_all_robber_types);
			cityMap[Grobber[i].getRLocation(content.X_Coord)][Grobber[i].getRLocation(content.Y_Coord)] = 'R';//greedy robber represented by 'R'
		}
	
	for (int i = 0; i < content.totalPolice; i++)//sets police on map and ID
	{
		do
		{
			Police_Officer[i].setPLocation(content.X_Coord);
			Police_Officer[i].setPLocation(content.Y_Coord);
		} while (cityMap[Police_Officer[i].getPLocation(content.X_Coord)][Police_Officer[i].getPLocation(content.Y_Coord)] != ' ');//must be on empty space
		Police_Officer[i].setPoliceID(i + 1);
		cityMap[Police_Officer[i].getPLocation(content.X_Coord)][Police_Officer[i].getPLocation(content.Y_Coord)] = 'P';//police reprsented by P
	}
	
}
void City::print()
{
	cout << endl;
	for (int i = 0; i < content.CITYSIZE; i++)//outputs city map in a way that can be easy to read
	{
		cout << i << "|";
		for (int j = 0; j < content.CITYSIZE; j++)
		{
			cout << cityMap[i][j] << ",";
		}
		cout << "|";
		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < content.CITYSIZE; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
int City::findJewelObject(const int XLocation,const int YLocation)
{
	for (int Jewelindex = 0; Jewelindex < content.totalJewels; Jewelindex++)//finds index of jewel that object collided with 
	{
		if ((XLocation == jewel[Jewelindex].getJLocation(content.X_Coord)) && (YLocation == jewel[Jewelindex].getJLocation(content.Y_Coord)))
		{
			
			jewel[Jewelindex].jewelStolen_OR_returnedToCity();//jewel has been found on this tile and will be either picked up by robber object or returned to city by cop object
			return Jewelindex;//jewel on same tile as moving object
		}
	}
	return NULL;//debugging
}
int City::findOfficer(const int XPos, const int YPos)
{
	for (int Policeindex = 0; Policeindex < content.totalPolice; Policeindex++)//finds police on the tile the robber landed on with a 'P'
	{
		if ((XPos == Police_Officer[Policeindex].getPLocation(content.X_Coord)) && (YPos == Police_Officer[Policeindex].getPLocation(content.Y_Coord)))
		{
		
			return Policeindex;//returns police officer that the robber collided with 

		}
	}
}
void City::findRobberObject(const int XPos, const int YPos, const int pindex)
{
	for (int oRobberindex = 0; oRobberindex < content.totalOrdinaryRobbers; oRobberindex++)//finds ordinary robber on tile with 'R'
	{
		if ((XPos == Orobber[oRobberindex].getRLocation(content.X_Coord)) && (YPos == Orobber[oRobberindex].getRLocation(content.Y_Coord)))
		{
			for (int Jindex = 0; Jindex < Orobber[oRobberindex].getAmountOfJewels(); Jindex++)//polices officer takes all the jewels from the robber and adds it to the confiscated jewel value amount
			{
				Police_Officer[pindex].setReturnedJewels(Police_Officer[pindex].getReturnedJewels() + Orobber[oRobberindex].getReturnAJewel(Jindex));
			}
			cityMap[Orobber[oRobberindex].getRLocation(content.X_Coord)][Orobber[oRobberindex].getRLocation(content.Y_Coord)] = 'P';//repaces 'R' with a 'P' int location the objects collide at 
			Orobber[oRobberindex].caught(Police_Officer[pindex].arrest("Ordinary Robber", Orobber[oRobberindex].getRobberID()));//arrests robber
		
		}
	}
	for (int gRobberindex = 0; gRobberindex < content.totalGreedyRobbers; gRobberindex++)//finds greedy robber on tile with 'R'
	{
		if ((XPos == Grobber[gRobberindex].getRLocation(content.X_Coord)) && (YPos == Grobber[gRobberindex].getRLocation(content.Y_Coord)))
		{
			for (int Jindex = 0; Jindex < Grobber[gRobberindex].getAmountOfJewels(); Jindex++)//polices officer takes all the jewels from the robber and adds it to the confiscated jewel value amount
			{
				Police_Officer[pindex].setReturnedJewels(Police_Officer[pindex].getReturnedJewels() + Grobber[gRobberindex].getReturnAJewel(Jindex));
			}
			Grobber[gRobberindex].caught(Police_Officer[pindex].arrest("Greedy Robber", Grobber[gRobberindex].getRobberID()));//arrests robber 
			cityMap[Grobber[gRobberindex].getRLocation(content.X_Coord)][Grobber[gRobberindex].getRLocation(content.Y_Coord)] = 'P';//repaces 'R' with a 'P' int location the objects collide at 
			

		}
	}
	return;
}