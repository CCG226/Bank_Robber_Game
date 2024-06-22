#include "Robber.h"
#include <iostream>
using namespace std;
int Robber::totalJewelFortune = 0;//keeps track of all stolen wealth as static
Robber::Robber()//intializes 
{
	robber_ID = 0;
	jewelFortune = 0;
	arrested = false;
	robberCoord[0] = 0;
	robberCoord[1] = 0;
	AmountOfStolenJewels = 0;
	bag = new Jewel[bagSize];
}
int Ordinary_Robber::move()
{
	game Content;
	int TempDirection = 0;
	TempDirection = ValidMoveSearch(robberCoord[Content.X_Coord], robberCoord[Content.Y_Coord]);//finds a valid spot for the ordinary robber to move
	return TempDirection;//returns that direction
}
int Greed_Robber::move()
{
	game Content;
	int temp = 0;
	temp = ValidMoveSearch(robberCoord[Content.X_Coord], robberCoord[Content.Y_Coord]);//finds a valid spot for the greedy robber to move
	return temp;//returns that direction
}
void Robber::pickUpJewel(int JewelWorth)
{
	
	const int DOUBLE = 2;//to double bag size
	if (AmountOfStolenJewels == bagSize)//if bag is full of jewels
	{
		bagSize = bagSize * DOUBLE;//doubles bag size
		newBag = new Jewel[bagSize];// create new bag with double the size
		for (int i = 0; i < bagSize; i++)
		{
			newBag[i] = bag[i];//put all the jewels content from the old bag int the new bag via overloading assingment operator
		}
		delete[] bag;
		bag = newBag;//bag becomes new bag with corresponding content
	}
	bag[AmountOfStolenJewels].setJValue(JewelWorth, NULL);//adds jewel value to picjet up jewel, x = value of lost jewel, y = 0, so new bag jewel value = lost jewel value + 0;
	bag[AmountOfStolenJewels].jewelStolen_OR_returnedToCity();//in bag, not on map
	totalJewelFortune = totalJewelFortune + JewelWorth;//adds picked up jewel worth to total of all robbers
	jewelFortune = jewelFortune + JewelWorth;//adds picked up jewel worth to this robbers fortune
	AmountOfStolenJewels++;//robbers now have a jewel
	cout << "and now has " << AmountOfStolenJewels << " jewels worth $" << jewelFortune << endl;
}
int Greed_Robber::bagDrop(Jewel orginialJewels[],char board[][10])
{
	AmountofJewelsDropped = AmountOfStolenJewels / Halved;//amount of jewels in bag / 2
	
	for (int i = AmountofJewelsDropped - 1; i >= Contentpack.EMPTY; i--)//removes jewels dropped from bag from total jewel fortune and this greedy robbers fortune
	{
		jewelFortune = jewelFortune - bag[AmountofJewelsDropped].getJValue();
		totalJewelFortune = totalJewelFortune - bag[AmountofJewelsDropped].getJValue();
	}
	int jewelDecrement = AmountofJewelsDropped - 1;//removes from top jewel in bag array to half way point
	
	for (int i = 0; i < Contentpack.totalJewels; i++)//deleting jewels in bag and reallocating them back to the map
	{
		if (orginialJewels[i].getStolenI() == true)//finds mssing jewel indexs 
		{
			bag[jewelDecrement].setJValue(0, 0);
			bag[jewelDecrement].jewelStolen_OR_returnedToCity();
			do//adding dropped jewels back to map 
			{
				orginialJewels[i].setJLocation(Contentpack.X_Coord);
				orginialJewels[i].setJLocation(Contentpack.Y_Coord);
			} while (board[orginialJewels[i].getJLocation(Contentpack.X_Coord)][orginialJewels[i].getJLocation(Contentpack.Y_Coord)] != ' ');
			board[orginialJewels[i].getJLocation(Contentpack.X_Coord)][orginialJewels[i].getJLocation(Contentpack.Y_Coord)] = 'J';
			orginialJewels[i].setJValue(orginialJewels[i].getJLocation(Contentpack.X_Coord), orginialJewels[i].getJLocation(Contentpack.Y_Coord));
			jewelDecrement--;
		}
		if (jewelDecrement == -1)
		{
			break;
		}
	}
	
	cout << "They dropped a total of " << AmountofJewelsDropped << " out of the "<< AmountOfStolenJewels <<" jewels in thier bag!!" << endl;
	cout << "Now the greedy robber only has made $" << jewelFortune << endl;
	AmountOfStolenJewels = AmountofJewelsDropped;//bag is reduced to half full
	return AmountofJewelsDropped;
}
Robber::~Robber()//deallocate pointer 
{
	delete[] bag;
	
}
