// Bank_Robber_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "gameHeader.h"
#include "City.h"
using namespace std;
int main()
{
  int turnCounter = 0;//counts turns
  game contentpack;//constants
  City board;//city object
  srand(contentpack.seed);//seed
  cout << "Creating city map..." << endl;
  board.setCity();//sets city
  board.print();//prints intial map
  cout << endl;
  cout << "Starting game..." << endl;
  for (int i = 0; i < contentpack.TURNS; i++)//runs for 30 turns
  {
    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << "Turn: " << i + 1 << endl;
    board.Turn();//proccesses movements and collisions 
    cout << endl;
    cout << "New city map:" << endl;
    board.print();//prints new map after collisons and movements of objects
    cout << endl;
    cout << "_______________________________________________________" << endl;
    if (board.getPoliceWin() == true)
    {
      break;
    }
    if (board.getRobberWin() == true)
    {
      break;
    }
    turnCounter++;
  }
  if (turnCounter == contentpack.TURNS)//if robbers are still active and thier are no more turns
  {
    board.Summary("the Robbers win! The cops failed to catch all of the robbers in time!");
  }
  if (board.getPoliceWin() == true)
  {
    board.Summary("The Police win! The cops have caught all the robbers and returned the jewels they stole bact to the city!");
  }
  if (board.getRobberWin() == true)
  {
    board.Summary("The Robbers win! The robbers have some how obtained $2022 worth of jewels!");
  }
 

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
