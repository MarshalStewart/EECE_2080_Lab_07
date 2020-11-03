//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing C1-3
    @file PlainBox.h */

#ifndef FLEET_
#define FLEET_

#include <vector>

template<typename ItemType> // Indicates this is a template definition
// Declaration for the class Fleet 
class Fleet
{
private:
   // Data field
   ItemType m_flagShip;
   std::vector<ItemType> m_flotilla;
   
public:

   // Parameterized constructor
   Fleet();
   Fleet(const ItemType& flagship);
   
   // Mutator method that can change the value of the data field
   void setFlagShip(const ItemType& theItem);
   
   void addFlotilla(const ItemType& theItem);

   std::vector<ItemType> getFlotilla();

   // Damage a ship, return true if dead
   bool damageShip(int damage);

   // Damage an entire Flotilla
   void damageFlotilla(int damage);

   // Get rear member
   ItemType getLeftBackShip();
   ItemType getRightBackShip();

   // Get front member
   ItemType getLeftFrontShip();
   ItemType getRightFrontShip();

private:

}; 

#include "Fleet.cpp" // Include the implementation file
#endif