//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing C1-4
    @file PlainBox.cpp */
    
#include "Fleet.h"

template<typename ItemType>
Fleet<ItemType>::Fleet() 
{
}

template<typename ItemType>
Fleet<ItemType>::Fleet(const ItemType& theItem) : m_flagShip(theItem)
{
}  // end constructor

template<typename ItemType>
void Fleet<ItemType>::setFlagShip(const ItemType& theItem)
{
    m_flagShip = theItem;
}  // end setItem


template<class ItemType>
void Fleet<ItemType>::addFlotilla(const ItemType& theItem)
{ 
    m_flotilla.push_back(theItem);
}

template<class ItemType>
std::vector<ItemType> Fleet<ItemType>::getFlotilla()
{
    return m_flotilla;
}

template<class ItemType>
ItemType Fleet<ItemType>::getLeftFrontShip()
{
    return m_flotilla[0];
}

template<class ItemType>
ItemType Fleet<ItemType>::getRightFrontShip()
{
    return m_flotilla[1];
}

template<class ItemType>
ItemType Fleet<ItemType>::getLeftBackShip()
{
    return m_flotilla[2];
}

template<class ItemType>
ItemType Fleet<ItemType>::getRightBackShip()
{
    return m_flotilla.back();
}

