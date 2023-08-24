// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: hawtdawgmeister.cpp
// Purpose: contains function definitions for the hawtdawgmeister class

#include "HW07.h"
#include "hawtdawgmeister.h"
#include <iostream>

using namespace std;

hawtdawgmeister& hawtdawgmeister::operator +=(const float c)
{
  m_cash += c;         // adds the given float value to the hawtdawgmeister's
  //                      current amount of cash
  return *this;
}

hawtdawgmeister& hawtdawgmeister::operator -=(const float c)
{
  m_cash -= c;       // subtracts the given float value to the hawtdawgmeister's
  //                    current amount of cash
  return *this;
}
