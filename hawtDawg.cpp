// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: hawtDawg.cpp
// Purpose: contains function definitions for the hawtDawg class

#include "HW07.h"
#include "hawtDawg.h"
#include <iostream>

using namespace std;

hawtDawg::hawtDawg(const int a,const int o,const int p,const bool r,const bool c,const bool pa)
{
  // initializes each variable to the given values
  m_animals = a;
  m_onions = o;
  m_pickles = p;
  m_hasRelish = r;
  m_hasCheese = c;
  m_hasPathogen = pa;
  // calculates price based on the cost of each variable
  m_price = (COST_ANIMAL * a) + (COST_ONION * o) + (COST_PICKLE * p) +
            COST_BREAD + (COST_RELISH * r) + (COST_CHEESE * c);
}

hawtDawg::hawtDawg()
{
  // randomly initializes each variable using a range
  m_animals = rand_num(MAX_HAWT_DOG_ING, MIN_HAWT_DOG_ING);
  m_onions = rand_num(MAX_HAWT_DOG_ING, MIN_HAWT_DOG_ING);
  m_pickles = rand_num(MAX_HAWT_DOG_ING, MIN_HAWT_DOG_ING);
  // these are assigned randomly based on chance
  m_hasRelish = percentResult(RELISH_CHANCE);
  m_hasCheese = percentResult(CHEESE_CHANCE);
  m_hasPathogen = percentResult(VIRULENT_PATH_CHANCE);
  // calculates price based on the cost of each variable
  m_price = (COST_ANIMAL * m_animals) + (COST_ONION * m_onions) +
            (COST_PICKLE * m_pickles) + COST_BREAD + (COST_RELISH * m_hasRelish)
             + (COST_CHEESE * m_hasCheese);
}

ostream& operator<<(ostream& os, const hawtDawg& h)
{
  // cost of the hawtdawg
  os << "(cost: $"<< h.getPrice() << ")";
  return os;
}
