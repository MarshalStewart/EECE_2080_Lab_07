// FleetAttack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "Fleet.h"
#include "IShip.h"
#include "IRace.h"
#include "ShipFactory.cpp"

using namespace std;

int main()
{
    cout << "Welcome to our game\n";
    int count = 0;
    int p_count = 1;
    string input = "";
	ShipFactory shipFactory;
    ShipFactory::Race_Type faction;
    ShipFactory::Ship_Type ship;
    Fleet<IShip*> *fleet;
    Fleet<IShip*> *fleet1;
    Fleet<IShip*> *fleet2;

    // Select a Fleet
    while (p_count < 3)
    {
        cout << "Player " << p_count << " choose fleet: \n";

        if (p_count  == 1)
            fleet = fleet1;
        else
            fleet = fleet2;

        // Player chooses fleet 
        while (count < 4)
        {
            cout << "Choose a faction: NAZI, USSR, USA, SPQR\n";
            cin >> input;

            if (input.compare("NAZI") == 0)
                faction = ShipFactory::Race_Type::E_NAZI;

            else if (input.compare("USSR") == 0)
                faction = ShipFactory::Race_Type::E_NAZI;

            else if (input.compare("USA") == 0)
                faction = ShipFactory::Race_Type::E_NAZI;

            else if (input.compare("SPQR") == 0)
                faction = ShipFactory::Race_Type::E_NAZI;

            else
            {
                cout << "Invalid input\n";
                continue;
            }
            
            cout << "Choose a ship type: StarDestroyer, StarFighter, StarBomber, StarApacheAttackHelicopter\n";
            cin >> input;

            if (input.compare("StarDestroyer"))
            {
                ship = ShipFactory::Ship_Type::STAR_DESTROYER;
                IShip* new_ship = shipFactory.CreateShip(ship, faction);
                // Star_Destroyer* new_ship = dynamic_cast<Star_Destroyer*>(tmp);
                (count == 0) ? fleet->setFlagShip(new_ship) : fleet->addFlotilla(new_ship);
            }

            else if (input.compare("StarFighter"))
            {
                ship = ShipFactory::Ship_Type::STAR_FIGHTER;
                IShip* new_ship = shipFactory.CreateShip(ship, faction);
                // Star_Fighter* new_ship = dynamic_cast<Star_Fighter*>(tmp);
                (count == 0) ? fleet->setFlagShip(new_ship) : fleet->addFlotilla(new_ship);

            } 
            else if (input.compare("StarBomber"))
            {
                ship = ShipFactory::Ship_Type::STAR_BOMBER;
                IShip* new_ship = shipFactory.CreateShip(ship, faction);
                // Star_Bomber* new_ship = dynamic_cast<Star_Bomber*>(tmp);
                (count == 0) ? fleet->setFlagShip(new_ship) : fleet->addFlotilla(new_ship);

            }
            
            else if (input.compare("StarApacheAttackHelicopter"))
            {
                ship = ShipFactory::Ship_Type::STAR_APACHEATTACKHELICOPTER;
                IShip* new_ship = shipFactory.CreateShip(ship, faction);
                // Star_ApacheAttackHelicopter* new_ship = dynamic_cast<Star_ApacheAttackHelicopter*>(tmp);
                (count == 0) ? fleet->setFlagShip(new_ship) : fleet->addFlotilla(new_ship);

            }

            else
            {
                cout << "Invalid input\n";
                continue;
            }
            
            count++;
        }
    }




    // std::vector<IShip*> flotilla = fleet1.getFlotilla();

    // std::cout << "Hello World!\n";
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
