// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: Customer.cpp
// Purpose: contains function definitions for the program

#include "HW07.h"
#include "Customer.h"
#include "hawtDawg.h"
#include "hawtdawgmeister.h"
#include <iostream>


using namespace std;

Customer::Customer()
{
  // random name from file
  m_name = generate_name();
  // random cash value between max and min plus some random change
  m_cash = (rand() % (CUST_MAX_CASH - CUST_MIN_CASH) + CUST_MIN_CASH) +
           + (rand() / static_cast<float>(RAND_MAX));
  // random weight
  m_weight = rand_num(CUST_MAX_WGT, CUST_MIN_WGT);
  m_isAlive = true;        // theyre alive
  // random health value
  m_health = rand_num(CUST_MAX_HEALTH, CUST_MIN_HEALTH);
  // not banned.... yet
  m_isBanned = false;
}

ostream& operator <<(ostream& os, const Customer& cust)
{
  // returns customer info to ostream: name, weight, and cash
  os << "\t" << cust.m_name << " " << cust.m_weight << " lbs, health " << cust.m_health
     << ", money $" << cust.m_cash;
  return os;
}

void Customer::BanHammer(hawtdawgmeister& meister)
{
  m_isBanned = true;      // they banned
  meister+=m_cash;        // they robbed of money
  m_cash = 0.0;           // they broke
  return;
}

bool Customer::isQualified(const hawtDawg& h)const
{
  // checks to see if customer isn't banned, is alive and can afford hawtDawg
  return !(m_isBanned) && m_isAlive && m_cash>= h.getPrice();
}

bool Customer::eat(const hawtDawg& h, hawtdawgmeister& cletus)
{
  bool vomit = false;         // whether the customer vomits or not
  m_cash -= h.getPrice();              // purchases the hawtDawg(loses cash)
  cletus += h.getPrice();              // hawtdawgmeister gets cash from sale
  m_weight += CUST_WEIGHT_GAIN;        // customer gains weight
  m_health-=CUST_EAT_HEALTH_LOSS;     // customer loses health
  if(m_health<1)                 // if customer has less than 1 health, they die
  {
    die();
  }
  cout << "\t" <<m_name << " eats a dawg" << h << " wt " << m_weight << ", health value "
       << m_health << " with $" << m_cash << " left ... " ;
  if(h.get_hasPathogen())        // checks if dawg has virulent pathogen
  {
    // the chance that they either die or vomit and lose portion of health is
    // decided a probility with percent chance being their current health value
    if(percentResult(m_health))
    {
      vomit = true;            // they vomit
      m_health /= CUST_EAT_PATHOGEN_HEALTH_DIVISOR;     // health is divided
    }
    else
      die();       // they die
  }
  // outputs whether they are alive or dead after eating and whether they vomit
  cout << (m_isAlive? "ALIVE": "DEAD") << (vomit?" and barfs":"")<<endl;
  return vomit;
}

void Customer::toss(const hawtDawg& h, hawtdawgmeister& cletus)
{
  m_cash -= h.getPrice();     // customer loses cash when paying for tossed dawg
  cletus += h.getPrice();     // cletus gets the money from the payment
  m_health += CUST_THROW_HEALTH_INC;        // customer gains health
  return;
}

void Customer::die()
{
  m_isAlive = false;           // the customer is no longer alive
  m_health = 0;                // customers health represents this fact
  return;
}
