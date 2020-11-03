// FleetAttack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
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
    Fleet<IShip*> *fleet = nullptr;
    Fleet<IShip*> *fleet1 = new Fleet<IShip*>();
    Fleet<IShip*> *fleet2 = new Fleet<IShip*>();

    // Select a Fleet
    while (p_count < 3)
    {
        cout << "Player " << p_count << " choose fleet: \n";

        if (p_count == 1)
            fleet = fleet1;
        else
            fleet = fleet2;

        // Player chooses fleet 
        count = 0;
        while (count < 4)
        {
            cout << "Choose a faction: NAZI, USSR, USA, SPQR\n";
            cin >> input;

            if (input.compare("NAZI") == 0)
                faction = ShipFactory::Race_Type::E_NAZI;

            else if (input.compare("USSR") == 0)
                faction = ShipFactory::Race_Type::E_USSR;

            else if (input.compare("USA") == 0)
                faction = ShipFactory::Race_Type::E_USA;

            else if (input.compare("SPQR") == 0)
                faction = ShipFactory::Race_Type::E_SPQR;

            else
            {
                cout << "Invalid input\n";
                continue;
            }
            
            cout << "Choose a ship type: StarDestroyer, StarFighter, StarBomber, StarApacheAttackHelicopter\n";
            cin >> input;

            if (input.compare("StarDestroyer"))
                ship = ShipFactory::Ship_Type::STAR_DESTROYER;

            else if (input.compare("StarFighter"))
                ship = ShipFactory::Ship_Type::STAR_FIGHTER;
            
            else if (input.compare("StarBomber"))
                ship = ShipFactory::Ship_Type::STAR_BOMBER;
            
            else if (input.compare("StarApacheAttackHelicopter"))
                ship = ShipFactory::Ship_Type::STAR_APACHEATTACKHELICOPTER;

            else
            {
                cout << "Invalid input\n";
                continue;
            }

            IShip* new_ship = shipFactory.CreateShip(ship, faction);
            if (count == 0)
                fleet->setFlagShip(new_ship);

            fleet->addFlotilla(new_ship);
            count++;
            p_count++;
        }
    }

    // Player Turns
    bool p_turn = false; // 0 Player 1 turn, 1 Player 2 turn
    bool player1_won = false;
    bool player2_won = false;
    std::vector<IShip*> flotilla;
    std::srand(time(nullptr)); // use current time as seed for random generator
    int dice_roll = 0;
    int fleet_size = 0;
    IShip *cur_ship;
    IRace *cur_race;
    IShip *enemy_ship;
    Fleet<IShip*> *enemy_fleet;
    vector<IShip*> *enemy_flotilla;
 
    while (player1_won || player2_won)
    {
        if (!p_turn)
        {
            cout << "Player 1 is up!\n";
            fleet = fleet1;
            enemy_fleet = fleet2;
        }
        else
        {
            cout << "Player 2 is up!\n";
            fleet = fleet2;
            enemy_fleet = fleet1;
        }

        flotilla = fleet->getFlotilla();
        fleet_size = flotilla.size();
        cur_ship = nullptr; 

        // Check if game won
        if (fleet_size == 0)
        {
            if (!p_turn)
                player1_won = true;
            else
                player2_won = true;
        }

        // Select current ship
        cur_ship = flotilla[fleet_size-1];
        cur_race = cur_ship->GetRace();
        
        // Role dice
        dice_roll = rand() % 20 + 1; // 1-20
        
        // Add hit bonus
        dice_roll += cur_ship->GetHitBonus();
        
        // Check which front ship to attack

        int pos = 0; 
        if (cur_ship->GetRace()->GetHitBonusModification() == 0) // SPQR special ability
        {
            pos = rand() % 4;
            if (pos == 0)
                enemy_ship = enemy_fleet->getLeftFrontShip();
            else if (pos == 1)
                enemy_ship = enemy_fleet->getRightFrontShip();
            else if (pos == 2)
                enemy_ship = enemy_fleet->getLeftBackShip();
            else
                enemy_ship = enemy_fleet->getRightBackShip();
        }
        else
        {
            pos = rand() % 2;
            if (pos == 0)
                enemy_ship = enemy_fleet->getLeftFrontShip();
            else
                enemy_ship = enemy_fleet->getRightFrontShip();
        }
        
        // The ship we grabbed is dead
        while (enemy_ship->GetHitPoints() <= 0)
        {
            // Check if both front ships are dead
            if ((enemy_fleet->getLeftFrontShip()->GetHitPoints() <= 0) &&
                    enemy_fleet->getRightFrontShip()->GetHitPoints() <= 0)
                pos = rand() % 4 + 2; // set position to back ships
            else // Give other front ship
            {
                if (pos == 0)
                {
                    enemy_ship = enemy_fleet->getRightFrontShip();
                    break; // Exit while loop
                }
                else
                {
                    enemy_ship = enemy_fleet->getLeftFrontShip(); 
                    break;
                }
            }
            
            // Give a random back ship
            if (pos == 2)
                enemy_ship = enemy_fleet->getLeftBackShip();
            else
                {enemy_ship = enemy_fleet->getRightBackShip();}

            // if random one is dead, check if both are dead
            if ((enemy_fleet->getLeftFrontShip()->GetHitPoints() <= 0) &&
                    enemy_fleet->getRightFrontShip()->GetHitPoints() <= 0)
            {
                std::cout << "Game break, should've won last turn\n";
                return; // Game's broken
            }
            else // Give other back ship
            {
                if (pos == 2)
                    enemy_ship = enemy_fleet->getRightBackShip();
                else
                    enemy_ship = enemy_fleet->getLeftBackShip();  
            }
            
        }

        // Check Special Ability
        if (cur_race->GetHitBonusModification() == 0)
        {
            /* NAZI */
            // compare to AC
            if (enemy_ship->GetArmorClass() < dice_roll)
            {
                // Damage Ship
                dice_roll = rand() % cur_ship->GetDamageBonus() + 1; // 1-min damage
                int damage = enemy_ship->GetHitPoints() - (dice_roll);
                // if damage < 0  
                //     damage=0;
                enemy_ship->SetHitPoints(damage);
            }
        
        }

        else if (cur_race->GetHitBonusModification() == 0)
        {
            // SPQR
            // Can attack backrow, already implemented by this point
            
            // compare to AC
            if (enemy_ship->GetArmorClass() < dice_roll)
            {
                // Damage Ship
                dice_roll = rand() % cur_ship->GetDamageBonus() + 1; // 1-min damage
                int damage = enemy_ship->GetHitPoints() - (dice_roll);
                // if damage < 0  
                //     damage=0;
                enemy_ship->SetHitPoints(damage);
            }
        }
        
        else if (cur_race->GetHitBonusModification() == 0)
        {
            // USA
            // 1/10 chance to do big damage to all enemies
            // compare to AC
            // enemy_ship = enemy_fleet->getFrontShip();
            if (enemy_ship->GetArmorClass() < dice_roll)
            {
                // Damage Ship
                dice_roll = rand() % cur_ship->GetDamageBonus() + 1; // 1-min damage
                int damage = enemy_ship->GetHitPoints() - (dice_roll);
                // if damage < 0  
                //     damage=0;
                enemy_ship->SetHitPoints(damage);
            }
        }
        
        else
        {
            // USSR
            // recoil damage and damage bonus
            // compare to AC
            // enemy_ship = enemy_fleet->getFrontShip();
            if (enemy_ship->GetArmorClass() < dice_roll)
            {
                // Damage Ship
                dice_roll = rand() % cur_ship->GetDamageBonus() + 1; // 1-min damage
                int damage = enemy_ship->GetHitPoints() - (dice_roll);
                
                if (damage > 0)
                {
                    // Do Damage to Enemy
                    enemy_ship->SetHitPoints(damage);
                    
                    // Recoil Damage
                    int new_hp = cur_ship->GetHitPoints();
                    new_hp -= (int)(new_hp * 0.1);
                    cur_ship->SetHitPoints(new_hp);
                }
            }
        }

        // Move selected ship
        fleet_size--;
        p_turn != p_turn;
    }
    



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
