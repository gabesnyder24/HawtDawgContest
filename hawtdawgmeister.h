// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: hawtdawgmeister.h
// Purpose: contains hawtdawgmeister class definition and function prototypes

#ifndef HAWTDAWGMEISTER_H
#define HAWTDAWGMEISTER_H

#include <iostream>
#include <cstdlib>

using namespace std;

// descr: the hawtdawgmeister() constructor initializes privates variables
// pre: n and c have been defined
// post: initializes a hawtdawgmeister with the given variables

// descr: the getName() function returns the hawtdawgmeister's name
// pre: m_name has been initialized
// post: returns the hawtdawgmeister's name

// descr: the getCash() function returns the hawtdawgmeister's monetary holdings
// pre: m_cash has been initialized
// post: returns the hawtdawgmeister's amount of cash

// descr: the addition and subtration assignment functions add or subtract to the
//        hawtdawgmeister's cash
// pre: c is defined
// post: returns the amount of cash after being modified

class hawtdawgmeister
{
  private:
    string m_name;          // name of hawtdawgmeister
    float m_cash;           // amount of money
  public:
    hawtdawgmeister(const string n, const float c) {m_name = n; m_cash = c;}
    string getName()const{return m_name;}
    float getCash()const{return m_cash;}
    hawtdawgmeister& operator +=(const float c);
    hawtdawgmeister& operator -=(const float c);
};

#endif
