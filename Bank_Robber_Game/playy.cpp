#include "City.h"
#include <iostream>
#include "Robber.h"
#include "Jewel.h"
#include "POLICE.h"
#include <ctime>
#include <cstdlib>
#include "gameHeader.h"
using namespace std;
void City::Turn()
{
	
	game contentpack;//constants
	int ORDirection = 0;//temp holds direction object will move in
	int NewORobberXCorrdinate = 0;//temp holds new x coordinate a object will move too
	int NewORobberYCorrdinate = 0;//temp holds new y coordinate a object will move too
	int OldCoordsX = 0;//temp holds previous x coordinate of a object after move 
	int OldCoordsY = 0;//temp holds previous y coordinate of a object after move 
	int foundJewel = 0;//deals with moving object & jewel collison
	int findPolice = 0;//deals with police & moving robber collison
	int findRobber = 0;//deals with robber & moving police collison
	for (int i = 0; i < contentpack.totalOrdinaryRobbers; i++)//ordinary robbers go first, proccesses their movement
	{
		
		if (Orobber[i].getArrested() == false)//cant move if in jail
		{
			
			ORDirection = Orobber[i].move();//finds direction
			
			NewORobberXCorrdinate = X_Move(Orobber[i].getRLocation(contentpack.X_Coord), ORDirection);//sets new x coords based on direction
			NewORobberYCorrdinate = Y_Move(Orobber[i].getRLocation(contentpack.Y_Coord), ORDirection);//sets new y coords based on direction
		
			StateMovement("Ordinary Robber", Orobber[i].getRobberID(), ORDirection);//states movement made by object
			OldCoordsX = Orobber[i].getRLocation(contentpack.X_Coord);//holds previous x coords
			OldCoordsY = Orobber[i].getRLocation(contentpack.Y_Coord);//holds previous y coords
			Orobber[i].setRNewLocation(contentpack.X_Coord, NewORobberXCorrdinate);//sets new location for x position of object
			Orobber[i].setRNewLocation(contentpack.Y_Coord, NewORobberYCorrdinate);//sets new location for y position of object
			if (cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] == 'J')//if object runs int a jewel
			{

				foundJewel = findJewelObject(Orobber[i].getRLocation(contentpack.X_Coord), Orobber[i].getRLocation(contentpack.Y_Coord));//finds jewel index at this position
				jewel[foundJewel].isStolen();//jewel is considered stolen 
				cout << "Ordinary Robber " << Orobber[i].getRobberID() << " found a jewel worth $" << jewel[foundJewel].getJValue() << endl;
				Orobber[i].pickUpJewel(jewel[foundJewel].getJValue());//jewel added to theives bag
				numberOfLostJewels--;// one less jewel on map
				cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old position 
				cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] = 'R';// replaces 'J' with 'R' on map as jewel has been picked up
			}
			else if (cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] == 'P')// if object runs int a police officer
			{
				
				findPolice = findOfficer(Orobber[i].getRLocation(contentpack.X_Coord), Orobber[i].getRLocation(contentpack.Y_Coord));//finds police object at this position
				//
				for (int Jindex = 0; Jindex < Orobber[i].getAmountOfJewels(); Jindex++)//polices officer takes all the jewels from the robber and adds it to the confiscated jewel value amount
				{
					
					Police_Officer[findPolice].setReturnedJewels(Police_Officer[findPolice].getReturnedJewels() + Orobber[i].getReturnAJewel(Jindex));
				}
				//
				Orobber[i].caught(Police_Officer[findPolice].arrest("Ordinary Robber", Orobber[i].getRobberID()));//police officer arrests robber and robber is deleted (put in jail) )
				cout << "Police Officer " << Police_Officer[findPolice].getPoliceID() << " now has returned $" << Police_Officer[findPolice].getReturnedJewels() << " back to the city" << endl;
				cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] = 'P';//replaces 'R' with a 'P' where the robber was arrested
				cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old positon
				
			}
			else if (cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] == 'R')//if object runs into a robber
			{
				cout << "Ordinary Robber " << Orobber[i].getRobberID() << " has ran into a fellow ally!!!" << endl;//nothing happens
				cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old positon
			}
			else if (cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] == ' ')//if object lands on an empty tile 
			{
				cityMap[Orobber[i].getRLocation(contentpack.X_Coord)][Orobber[i].getRLocation(contentpack.Y_Coord)] = 'R';// replaces ' ' with 'R' on map as jewel has been picked up
				cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old position
			}
		}
		else if (Orobber[i].getArrested() == true)//robber stuck in jail
		{
			cout << "Ordinary Robber " << Orobber[i].getRobberID() << " is in jail and cannot move" << endl;
		}
		
	}
	for (int i = 0; i < contentpack.totalGreedyRobbers; i++)//greedy robber goes second, processes thier moves
	{
		int consuctiveMoves = 0;//counts consuctive moves greedy robber makes after findig jewel and ensuring they dont move more than 3 times
		if (Grobber[i].getArrested() == false)
		{
			do
			{
				ORDirection = Grobber[i].move();//finds direction

				NewORobberXCorrdinate = X_Move(Grobber[i].getRLocation(contentpack.X_Coord), ORDirection);//sets new  x coords based on direction
				NewORobberYCorrdinate = Y_Move(Grobber[i].getRLocation(contentpack.Y_Coord), ORDirection);//sets new y coords based on direction

				StateMovement("Greedy Robber", Grobber[i].getRobberID(), ORDirection);//states movement made by object
				OldCoordsX = Grobber[i].getRLocation(contentpack.X_Coord);//holds previous x coords
				OldCoordsY = Grobber[i].getRLocation(contentpack.Y_Coord);//holds previous y coords
				Grobber[i].setRNewLocation(contentpack.X_Coord, NewORobberXCorrdinate);//sets new location for x position of object
				Grobber[i].setRNewLocation(contentpack.Y_Coord, NewORobberYCorrdinate);//sets new location for y position of object
				if (cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] == 'J')//if object runs int a jewel
				{
					
					foundJewel = findJewelObject(Grobber[i].getRLocation(contentpack.X_Coord), Grobber[i].getRLocation(contentpack.Y_Coord));//finds jewel index at this position
					jewel[foundJewel].isStolen();//jewel is considered stolen 
					cout << "Greedy Robber " << Grobber[i].getRobberID() << " found a jewel worth $" << jewel[foundJewel].getJValue() << endl;
					Grobber[i].pickUpJewel(jewel[foundJewel].getJValue());//jewel added to theives bag
					numberOfLostJewels--;// one less jewel on map
					cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old position 
					consuctiveMoves++;//counts greedy robbers move to let them move again
					if (consuctiveMoves < contentpack.maxGreedyMoves)//can still move agian if less then 3 moves and they just found a jewel
					{
						cout << "Since Greedy Robber is so thrilled to find a jewel he is going to move again!!!" << endl;
					}
					else if (consuctiveMoves == contentpack.maxGreedyMoves)//if 3 moves have been made there too tired to move again
					{
						cout << "Greedy robber is worn out for the turn after moving three times." << endl;
					}
				}
			}while ((cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] == 'J') && (consuctiveMoves < contentpack.maxGreedyMoves));//if greedy robber just found a jewel and havent moved 3 times yet they move again.
			
		if (cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] == 'P')// if object runs int a police officer
		{

			findPolice = findOfficer(Grobber[i].getRLocation(contentpack.X_Coord), Grobber[i].getRLocation(contentpack.Y_Coord));//finds police object at this position
			for (int Jindex = 0; Jindex < Grobber[i].getAmountOfJewels(); Jindex++)//police officer takes all the jewels from the robber and adds it to the confiscated jewel value amount
			{				
				Police_Officer[findPolice].setReturnedJewels(Police_Officer[findPolice].getReturnedJewels() + Grobber[i].getReturnAJewel(Jindex));
			}
			Grobber[i].caught(Police_Officer[findPolice].arrest("Greedy Robber", Grobber[i].getRobberID()));//police officer arrests robber and robber is deleted (put in jail) )
			cout << "Police Officer " << Police_Officer[findPolice].getPoliceID() << " now has returned $" << Police_Officer[findPolice].getReturnedJewels() << " back to the city" << endl;
			cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] = 'P';//replaces 'R' with a 'P' where the robber was arrested
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old positon

		}
		else if (cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] == 'R')//if object runs into a robber
		{
			cout << "Greedy Robber " << Grobber[i].getRobberID() << " has ran into a fellow ally and dropped his jewel bag in excitment!!!" << endl;
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old positon
			if (Grobber[i].getAmountOfJewels() != contentpack.EMPTY && Grobber[i].getAmountOfJewels() != contentpack.ONLY_ONE)//greedy robber losses have thier bag if they have 2 or more jewels
			{
				numberOfLostJewels = numberOfLostJewels + Grobber[i].bagDrop(jewel, cityMap);//half the jewels from the bag are re added to the city map as lost

			}
			else
			{
				cout << "wait, their is either zero or only one jewel in the robbers bag, so he dosent drop any!!" << endl;
			}
		}
		else if (cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] == ' ')//if object lands on an empty tile
		{
			cityMap[Grobber[i].getRLocation(contentpack.X_Coord)][Grobber[i].getRLocation(contentpack.Y_Coord)] = 'R';// replaces ' ' with 'R' on map as jewel has been picked up
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old position
		}
		
		
		}
		else if (Grobber[i].getArrested() == true)//robber stuck in jail
		{
			cout << "Greedy Robber " << Grobber[i].getRobberID() << " is in jail and cannot move" << endl;
		}
	
	}
	for (int i = 0; i < contentpack.totalPolice; i++)//police object moves last, proccesses thier movement 
	{
		ORDirection = Police_Officer[i].move();//finds direction

		NewORobberXCorrdinate = X_Move(Police_Officer[i].getPLocation(contentpack.X_Coord), ORDirection);//sets new x coords based on direction
		NewORobberYCorrdinate = Y_Move(Police_Officer[i].getPLocation(contentpack.Y_Coord), ORDirection);//sets new y coords based on direction

		StateMovement("Police Officer",Police_Officer[i].getPoliceID(), ORDirection);//states movement made by object
		OldCoordsX = Police_Officer[i].getPLocation(contentpack.X_Coord);//holds previous x coords
		OldCoordsY = Police_Officer[i].getPLocation(contentpack.Y_Coord);//holds previous y coords
		Police_Officer[i].setPNewLocation(contentpack.X_Coord, NewORobberXCorrdinate);//sets new location for x position of object
		Police_Officer[i].setPNewLocation(contentpack.Y_Coord, NewORobberYCorrdinate);//sets new location for y position of object
		if (cityMap[Police_Officer[i].getPLocation(contentpack.X_Coord)][Police_Officer[i].getPLocation(contentpack.Y_Coord)] == 'J')//if object runs int a jewel
		{
			foundJewel = findJewelObject(Police_Officer[i].getPLocation(contentpack.X_Coord), Police_Officer[i].getPLocation(contentpack.Y_Coord));//finds jewel index at this position
			cout << "Police Officer " << Police_Officer[i].getPoliceID() << " returned a jewel worth $" << jewel[foundJewel].getJValue() << endl;
			Police_Officer[i].setReturnedJewels(jewel[foundJewel].getJValue() + Police_Officer[i].getReturnedJewels());//jewel returned to city
			numberOfLostJewels--;// one less jewel on map
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'P' from map in old position 
			cityMap[Police_Officer[i].getPLocation(contentpack.X_Coord)][Police_Officer[i].getPLocation(contentpack.Y_Coord)] = 'P';// replaces 'J' with 'P' on map as jewel has been picked up
		}
		else if (cityMap[Police_Officer[i].getPLocation(contentpack.X_Coord)][Police_Officer[i].getPLocation(contentpack.Y_Coord)] == 'P')// if object runs int a police officer
		{
			cout << "Police Officer " << Police_Officer[i].getPoliceID() << " has ran into a fellw ally!!" << endl;
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'P' from map in old positon
 		}
		else if (cityMap[Police_Officer[i].getPLocation(contentpack.X_Coord)][Police_Officer[i].getPLocation(contentpack.Y_Coord)] == 'R')//if object runs into a robber
		{
			findRobberObject(Police_Officer[i].getPLocation(contentpack.X_Coord), Police_Officer[i].getPLocation(contentpack.Y_Coord),i);
			cout << "Police Officer " << Police_Officer[findPolice].getPoliceID() << " now has returned $" << Police_Officer[findPolice].getReturnedJewels() << " back to the city" << endl;
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'R' from map in old positon
		}
		else if (cityMap[Police_Officer[i].getPLocation(contentpack.X_Coord)][Police_Officer[i].getPLocation(contentpack.Y_Coord)] == ' ')//if object lands on an empty tile
		{
			cityMap[Police_Officer[i].getPLocation(contentpack.X_Coord)][Police_Officer[i].getPLocation(contentpack.Y_Coord)] = 'P';// replaces ' ' with 'P' on map as jewel has been picked up
			cityMap[OldCoordsX][OldCoordsY] = ' ';//removes 'P' from map in old position
		}
	}
	cout << endl;
	cout << "There are " << numberOfLostJewels << " Remaining Jewels " << endl;//jewels still lost on the city map
	cout << "current wealth amount of jewels stolen by the robbers is : $" << Orobber[contentpack.ofAllRobbers].totalJewelFortune << endl;//stolen robber wealth
	if (Orobber[contentpack.ofAllRobbers].totalJewelFortune == content.ROBBER_WIN_CONDITION)//if robbers make $2022 they win, game over
	{
		RobberWin = true;

	}
	if (Police_Officer[contentpack.ofAllRobbers].totalCaught == (contentpack.totalGreedyRobbers + contentpack.totalOrdinaryRobbers))//if cops catch all robbers they win, game over
	{
		PoliceWin = true;
	}
	return;
}
