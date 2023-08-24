// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: hawtDawg.h
// Purpose: contains hawtDawg class definition and function prototypes

#ifndef HAWTDAWG_H
#define HAWTDAWG_H

#include "HW07.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// descr: the hawtDawg constructors initialize the private variables
// pre: default constructor(none). a, o, and p are positive numbers and all
//      parameters have been declared
// post: initializes a hawtDawg with (given variables or by default)

// descr: the getPrice() function returns the cost of the hawtDawg
// pre: hawtDawg object has been declared
// post: returns the cost of the hawtDawg

// descr: the get_hasPathogen() function returns whether the hawtDawg has a
//        pathogen or not
// pre: hawtDawg object has been declared
// post: returns whether the hawtDawg has a pathogen or not

// descr: the operator <<() function returns an output stream for the hawtDawg
//        type
// pre: h has been initialized
// post: returns output that has been formatted for the hawtDawg type

class hawtDawg
{
  private:
    int m_animals;          // number of different animals in hawtDawg
    int m_onions;           // ounces of onion in hawtDawg
    int m_pickles;          // number of pickles in hawtDawg
    bool m_hasRelish;       // whether or not hawtDawg has relish
    bool m_hasCheese;       // whether or not hawtDawg has cheese
    bool m_hasPathogen;     // whether or not hawtDawg contains a virulent pathogen
    float m_price;          // cost of hawtDawg
  public:
    hawtDawg(const int a,const int o,const int p,const bool r,const bool c,const bool pa);
    hawtDawg();
    float getPrice()const{return m_price;}
    bool get_hasPathogen()const{return m_hasPathogen;}
    friend ostream& operator<<(ostream& os, const hawtDawg& h);
};

#endif
