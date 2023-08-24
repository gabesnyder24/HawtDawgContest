// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: Customer.h
// Purpose: contains Customer class definition and function prototypes

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "HW07.h"
#include "hawtDawg.h"
#include "hawtdawgmeister.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// descr: the Customer() constructor initializes a customer object
// pre: none
// post: initializes a customer object

// descr: the getName() function returns the name of the customer
// pre: calling object has been initialized
// post: returns name of calling object

// descr: the isAlive() function returns whether the customer is alive or not
// pre: calling object has been initialized
// post: returns whether the calling object is alive or not

// descr: the isBanned() function returns whether the customer was banned or not
// pre: calling object has been initialized
// post: returns whether the calling object was banned or not

// descr: the getCash() function returns the amount of cash the customer has
// pre: calling object has been initialized
// post: returns the calling objects amount of cash

// descr: the getHealth() function returns the amount of health the customer has
// pre: calling object has been initialized
// post: returns the calling objects amount of health

// descr: the operator <<() function returns an output stream for the customer
//        type
// pre: cust has been initialized
// post: returns output that has been formatted for the customer type

// descr: the BanHammer() function disqualifies the customer from the contest
//        and gives all their money to the hawtdawgmeister
// pre: the calling object and meister are initialized
// post: modifies the calling object to reflect being banned

// descr: the isQualified() function returns whether the customer is still
//        eligible as a contestant
// pre: h has been initialized
// post: returns whether the customer is a contestant

// descr: the eat() function returns whether the customer has vomitted and
//        outputs messages that correspond to the customer's information
// pre: calling object has been initialized
// post: outputs messages, changes customers and hawtdawgmeister's values, and
//       returns whether the customer has vomitted

// descr: the toss() function modifies the customers and the hawtdawgmeister's
//        values to reflect a hawtDawg being tossed
// pre: calling object, h, and meister have been initialized
// post: changes the customers cash and health values and the meister's cash

// descr: the die() function sets the values of the customer to reflect being
//        dead
// pre: calling object has been initialized
// post: modifies the customers health and isAlive status

class Customer
{
  private:
    string m_name;          // customer's name
    float m_cash;           // customer's amount of money
    short m_health;         // customer's amount of health
    int m_weight;           // customer's weight
    bool m_isAlive;         // whether customer is alive or not
    bool m_isBanned;        // whether customer is disqualified or not
  public:
    Customer();
    string getName()const{return m_name;}
    bool isAlive()const{return m_isAlive;}
    bool isBanned()const{return m_isBanned;}
    float getCash()const{return m_cash;}
    int getHealth()const{return m_health;}
    friend ostream& operator <<(ostream& os, const Customer& cust);
    void BanHammer(hawtdawgmeister& meister);
    bool isQualified(const hawtDawg& h)const;
    bool eat(const hawtDawg& h, hawtdawgmeister& meister);
    void toss(const hawtDawg& h, hawtdawgmeister& meister);
    void die();
};

#endif
