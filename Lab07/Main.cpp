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
    // TODO print the stats available for each ship
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
        
        for (int i=0; i<50; i++)
            cout << "*";
        cout << endl;
        
        cout << "Player " << p_count << " choose fleet: \n";

        if (p_count == 1)
            fleet = fleet1;
        else
            fleet = fleet2;

        // Player chooses fleet 
        count = 0;
        while (count < 4)
        {
            // TODO print out which ship ur selecting aka front left, right etc
            for (int i=0; i<50; i++)
                cout << "-";
            cout << endl;
            cout << "Choose a faction: NAZI, USSR, USA, SPQR\n";
            cin >> input;

            if (input.compare("NAZI") == 0)
            {
                faction = ShipFactory::Race_Type::E_NAZI;
                cout << "NAZI selected\n";
            }
            else if (input.compare("USSR") == 0)
            {
                faction = ShipFactory::Race_Type::E_USSR;
                cout << "USSR selected\n";
            }
            else if (input.compare("USA") == 0)
            {
                faction = ShipFactory::Race_Type::E_USA;
                cout << "USA selected\n";
            }
            else if (input.compare("SPQR") == 0)
            {
                faction = ShipFactory::Race_Type::E_SPQR;
                cout << "SPQR selected\n";
            }
            else
            {
                cout << "Invalid input\n";
                continue;
            }
            
            cout << "Choose a ship type: StarDestroyer, StarFighter, StarBomber, StarApacheAttackHelicopter\n";
            cin >> input;

            if (input.compare("StarDestroyer") == 0)
            {
                ship = ShipFactory::Ship_Type::STAR_DESTROYER;
                cout << "StarDestroyer selected\n";
            }
            else if (input.compare("StarFighter") == 0)
            {
                ship = ShipFactory::Ship_Type::STAR_FIGHTER;
                cout << "StarFighter selected\n";
            }
            else if (input.compare("StarBomber") == 0)
            {
                ship = ShipFactory::Ship_Type::STAR_BOMBER;
                cout << "StarBomber selected\n";
            }
            else if (input.compare("StarApacheAttackHelicopter") == 0)
            {
                ship = ShipFactory::Ship_Type::STAR_APACHEATTACKHELICOPTER;
                cout << "StarApacheAttackHelicopter selected\n";
            }
            else
            {
                cout << "Invalid input\n";
                continue;
            }

            IShip* new_ship = shipFactory.CreateShip(ship, faction);

            // cout statement here instead of in faction and shiptype
            // something like "Nazi StarFighter created"
            // assign temp string variables in above if else statements

            if (count == 0)
                fleet->setFlagShip(new_ship);

            fleet->addFlotilla(new_ship);
            count++;
        }
        p_count++;
    }

    // Player Turns
    bool p_turn = false; // 0 Player 1 turn, 1 Player 2 turn
    bool player1_won = false;
    bool player2_won = false;
    std::srand(time(nullptr)); // use current time as seed for random generator
    int dice_roll = 0;
    int fleet_size = 0;
    int enemy_fleet_size = 0;
    int turn_counter = 0;
    int initiative_counter = 0;
    IShip *cur_ship;
    IRace *cur_race;
    IShip *enemy_ship;
    Fleet<IShip*> *enemy_fleet;
    vector<IShip*> flotilla;
    vector<IShip*> enemy_flotilla;

    // Create initiative vector
    vector<IShip*> initiative_flotilla;
    vector<bool> initiative_id;
    for (auto ship : fleet1->getFlotilla())
    {
        initiative_flotilla.push_back(ship);
        initiative_id.push_back(0);
    }
    for (auto ship : fleet2->getFlotilla())
    {
        initiative_flotilla.push_back(ship);
        initiative_id.push_back(1);
    }

    // Sort(insert sort) initiative vector
    for (int r=0; r<initiative_flotilla.size(); r++)
    {
        int l = r;
        int nxtItem = initiative_flotilla[r]->GetInitiativeBonus();
        while ((l > 0) && (initiative_flotilla[l-1]->GetInitiativeBonus() > nxtItem))
        {
            initiative_flotilla[l] = initiative_flotilla[l-1];
            initiative_id[l] = initiative_id[l-1];
            l--;
        }
        initiative_flotilla[l] = initiative_flotilla[r]; // nxt Item
        initiative_id[l] = initiative_id[r];
    }

    while (!player1_won && !player2_won)
    {
        for (int i=0; i<50; i++)
            cout << "#";
        cout << endl;

        initiative_counter = turn_counter;
        while (initiative_counter >= 8)
        {
            initiative_counter -= 8;
        }

        cur_ship = initiative_flotilla[initiative_counter];
        cur_race = cur_ship->GetRace();
        p_turn = initiative_id[initiative_counter];
       
        if (!p_turn)
        {
            cout << "Player 1 is up!\n";
            fleet = fleet1;
            enemy_fleet = fleet2;
            
            flotilla = fleet->getFlotilla();
            fleet_size = flotilla.size();

            enemy_flotilla = enemy_fleet->getFlotilla();
            enemy_fleet_size = enemy_flotilla.size();

        }
        else
        {
            cout << "Player 2 is up!\n";
            fleet = fleet2;
            enemy_fleet = fleet1;
            
            flotilla = fleet->getFlotilla();
            fleet_size = flotilla.size();
            
            enemy_flotilla = enemy_fleet->getFlotilla();
            enemy_fleet_size = enemy_flotilla.size();
        }


        // Summary of all ships
        int c = 0;
        for (auto ship : flotilla)
        {
            for (int i=0; i<50; i++)
                cout << "-";
            cout << endl;
            
            cout << "Ship " << c << ":" << endl 
                << "Race: " << ship->GetStrRace() << endl
                << "Ship: " << ship->GetStrShip() << endl;
            if (ship->GetHitPoints() > 0){
                cout << "Hit Points: " << ship->GetHitPoints() << endl;   
            }
            else {
                cout << "Destroyed\n";
            }
            c++; // lmo
        }
        
        // input = "";
        // cout << "Press enter to play turn" << endl;
        // cin >> input;

        // check if flotilla is dead
        for (auto ship : flotilla)
        {
            if (ship->GetHitPoints() <= 0)
            {
                fleet_size--;
            }
        }

        // Check if enemy_flotilla is dead
        for (auto ship : enemy_flotilla)
        {
            if (ship->GetHitPoints() <= 0)
            {
                enemy_fleet_size--;
            }
        }
        
        // Check if game won
        if (fleet_size == 0)
        {
            player2_won = true;
            cout 
                << "Player " << (p_turn ? "1" : "2") << " Wins\n"
                << "took " << turn_counter << " turns" << endl; 
            continue; // exits loop
        }
        else if (enemy_fleet_size == 0)
        {    
            player1_won = true;
            cout 
                << "Player " << (p_turn ? "2" : "1") << " Wins\n"
                << "took " << turn_counter << " turns" << endl; 
            continue; // exits loop
        }

        // Check if current ship is dead
        if (cur_ship->GetHitPoints() <= 0)
        {
            cout << cur_ship->GetStrRace() << " " << cur_ship->GetStrShip() 
                << " is dead" << endl;
            turn_counter++;
            continue;
        }

        // Select current ship
        // cur_ship = flotilla[fleet_size-1];
        // cur_race = cur_ship->GetRace();
        
        // Role dice
        dice_roll = rand() % 20 + 1; // 1-20
        
        // Add hit bonus
        dice_roll += cur_ship->GetHitBonus();
        
        // Check which front ship to attack
        int pos = 0; 
        if (cur_ship->GetStrRace().compare("SPQR") == 0) // SPQR special ability
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
        
            // Grab ship till we get one that's not dead
            while (enemy_ship->GetHitPoints() <= 0)
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
        
        }
        else
        {
            // Grab one of front 2
            pos = rand() % 2;
            if (pos == 0)
                enemy_ship = enemy_fleet->getLeftFrontShip();
            else
                enemy_ship = enemy_fleet->getRightFrontShip();

            // Grab ship till we get one that's not dead
            while (enemy_ship->GetHitPoints() <= 0)
            {
                // only 1 front is dead
                if (!((enemy_fleet->getLeftFrontShip()->GetHitPoints() <= 0) &&
                        (enemy_fleet->getRightFrontShip()->GetHitPoints() <= 0)))
                {
                    if (pos == 1)
                        enemy_ship = enemy_fleet->getLeftFrontShip();
                    else
                        enemy_ship = enemy_fleet->getRightFrontShip();
                }
                else
                {
                    while (enemy_ship->GetHitPoints() <= 0)
                    {
                        pos = rand() % 2;
                        if (pos == 0)
                            enemy_ship = enemy_fleet->getLeftBackShip();
                        else
                            enemy_ship = enemy_fleet->getRightBackShip();
                    }
                }
            }
        
        }
        
        // Check Special Ability
        for (int i=0; i<50; i++)
            cout << "-";
        cout << endl
            // << "Player " << (p_turn ? "2" : "1") << endl
            << "Race: "  
            << cur_ship->GetStrRace() << endl
            << "Ship: "  
            << cur_ship->GetStrShip() << endl
            << "is up to attack" << endl;
        
        if (cur_ship->GetStrRace().compare("NAZI") == 0)
        {
            dice_roll -= 3;
            // compare to AC
            if (enemy_ship->GetArmorClass() < dice_roll)
            {
                // Damage Ship
                dice_roll = rand() % cur_ship->GetDamageBonus() + 16; // 1-min damage
                int damage = enemy_ship->GetHitPoints() - (dice_roll);
                // if damage < 0  
                //     damage=0;
                enemy_ship->SetHitPoints(damage);

                cout << "Player " << (p_turn ? "1" : "2") << endl
                    << "Race: " 
                    << enemy_ship->GetStrRace() << endl
                    << "Ship: " 
                    << enemy_ship->GetStrShip() << endl
                    << "got hit for " << dice_roll << endl;
                
            }
            else 
            {
                cout << "Player " << (p_turn ? "2" : "1") << " Misses" << endl;
            }   
        }

        else if (cur_ship->GetStrRace().compare("SPQR") == 0)
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
                cout << "Player " << (p_turn ? "1" : "2") << endl
                    << "Race: " 
                    << enemy_ship->GetStrRace() << endl
                    << "Ship: " 
                    << enemy_ship->GetStrShip() << endl
                    << "got hit for " << dice_roll << endl;
                    
            }
            else 
            {
                cout << "Player " << (p_turn ? "2" : "1") << " Misses" << endl;
            }   
        }
        
        else if (cur_ship->GetStrRace().compare("USA") == 0)
        {
            // USA
            // 1/10 chance to do big damage to all enemies
            // compare to AC
            // enemy_ship = enemy_fleet->getFrontShip();
            if (enemy_ship->GetArmorClass() < dice_roll)
            {
                if (rand() % 10 != 9)
                {
                    // Damage Ship
                    dice_roll = rand() % cur_ship->GetDamageBonus() + 1; // 1-min damage
                    int damage = enemy_ship->GetHitPoints() - (dice_roll);
                    // if damage < 0  
                    //     damage=0;
                    enemy_ship->SetHitPoints(damage);
                }
                else
                {
                    dice_roll = cur_ship->GetDamageBonus();
                    // apply damage to all enemy ships
                    enemy_ship = enemy_fleet->getLeftFrontShip();
                    int damage = enemy_ship->GetHitPoints() - dice_roll;
                    enemy_ship->SetHitPoints(damage);
                    
                    enemy_ship = enemy_fleet->getRightFrontShip();
                    damage = enemy_ship->GetHitPoints() - dice_roll;
                    enemy_ship->SetHitPoints(damage);

                    enemy_ship = enemy_fleet->getLeftBackShip();
                    damage = enemy_ship->GetHitPoints() - dice_roll;
                    enemy_ship->SetHitPoints(damage);

                    enemy_ship = enemy_fleet->getLeftBackShip();
                    damage = enemy_ship->GetHitPoints() - dice_roll;
                    enemy_ship->SetHitPoints(damage);
                }
                
                cout << "Player " << (p_turn ? "1" : "2") << endl
                    << "Race: " 
                    << enemy_ship->GetStrRace() << endl
                    << "Ship: " 
                    << enemy_ship->GetStrShip() << endl
                    << "got hit for " << dice_roll << endl;
            }
            else 
            {
                cout << "Player " << (p_turn ? "2" : "1") << " Misses" << endl;
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
                dice_roll = 2*(rand() % cur_ship->GetDamageBonus() + 1); // 1-min damage
                int damage = enemy_ship->GetHitPoints() - (dice_roll);
                
                // Do Damage to Enemy
                enemy_ship->SetHitPoints(damage);
                
                // Recoil Damage
                int new_hp = cur_ship->GetHitPoints();
                new_hp -= (int)((new_hp * 0.05)+3);
                cur_ship->SetHitPoints(new_hp);
                    
                cout << "Player " << (p_turn ? "1" : "2") << endl
                    << "Race: " 
                    << enemy_ship->GetStrRace() << endl
                    << "Ship: " 
                    << enemy_ship->GetStrShip() << endl
                    << "got hit for " << dice_roll << endl;

            }
            else 
            {
                cout << "Player " << (p_turn ? "2" : "1") << " Misses" << endl;
            }   
        }

        // Move selected ship
        // fleet_size--;
        // p_turn = !p_turn;
        turn_counter++;
    }
    
    // Game Won
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
