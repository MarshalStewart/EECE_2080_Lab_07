// FleetAttack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "Fleet.h"
#include "Iship.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "ShipFactory.h"
#include "Zerg.h"
#include "IRace.h"

int main()
{
	std::stack<int> myStack;


	Fleet<double> numberBox(5.4);
	Fleet<std::string> nameBox("ship");

	ShipFactory shipFactory;


	Iship* val = shipFactory.CreateShip(ShipFactory::BattleShipType, ShipFactory::ZergRace);

	BattleShip* battleShip = dynamic_cast<BattleShip*>(val);

    Cruiser* cruiserBad = dynamic_cast<Cruiser*>(val);

    Fleet<Iship*> fleet1(battleShip);

    val = shipFactory.CreateShip(ShipFactory::CruiserType, ShipFactory::ZergRace);

    Cruiser* cruiser = dynamic_cast<Cruiser*>(val);

    fleet1.addFlotilla(cruiser);

    std::vector<Iship*> flotilla = fleet1.getFlotilla();

    std::cout << "Hello World!\n";
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
