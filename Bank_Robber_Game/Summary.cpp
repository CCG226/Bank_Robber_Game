#include "City.h"
#include <iostream>
#include "Robber.h"
#include "Jewel.h"
#include "POLICE.h"
#include "gameHeader.h"
using namespace std;
void City::Summary(const string winnerPrint)//outputs winning team and summarizes object data from the game 
{
	cout << "\n\n\n" << endl;
	cout << winnerPrint << endl;
	cout << "Summary of the chase:\n" << endl;
	for (int i = 0; i < content.totalPolice; i++)
	{
		cout << "Police ID: " << Police_Officer[i].getPoliceID() << endl;
		cout << "Confiscated jewels amount: " << Police_Officer[i].getReturnedJewels() << endl;
		cout << "Final number of robbers caught: " << Police_Officer[i].totalCaught << endl;
		cout << endl;

	}
	for (int i = 0; i < content.totalOrdinaryRobbers; i++)
	{
		cout << "Ordinary Robber ID: " << Orobber[i].getRobberID() << endl;
		cout << "Stolen jewels amount: $" << Orobber[i].getFortune() << endl;
		cout << endl;
	}
	for (int i = 0; i < content.totalGreedyRobbers; i++)
	{
		cout << "Greedy Robber ID: " << Grobber[i].getRobberID() << endl;
		cout << "Stolen jewels amount: $" << Grobber[i].getFortune() << endl;
		cout << endl;
	}
	cout << "Total amount of jewels stolen by robber not in jail: $" << Orobber[content.ofAllRobbers].totalJewelFortune<< endl;
}