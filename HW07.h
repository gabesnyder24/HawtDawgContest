// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: HW07.h
// Purpose: contains function prototypes and constants for the program

#ifndef HW07_H
#define HW07_H

#include "Customer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_HAWT_DOG_ING = 4;   // maximum hot dot ingredients (animals, onions, pickles)
const int MIN_HAWT_DOG_ING = 0;   // maximum hot dot ingredients(animals, onions, pickles)
const int VIRULENT_PATH_CHANCE = 10;  // chance for hawtdawg to contain a pathogen
const int RELISH_CHANCE = 50;   // chance for hawtdawg to contain relish
const int CHEESE_CHANCE = 50;   // chance for hawtdawg to have cheese
const float COST_ANIMAL = 0.75;  // cost per animal in dawg
const float COST_ONION = 0.50;   // price of onion per ounce
const float COST_PICKLE = 0.25;  // price of pickle slice
const float COST_BREAD = 0.50;   // price of bread
const float COST_RELISH = 0.25;  // price of relish
const float COST_CHEESE = 0.50;  // price of cheese
const int CUST_MAX_CASH = 75; // maximum cash a customer can start with
const int CUST_MIN_CASH = 25; // minimum cash a customer can start with
const int CUST_MAX_WGT = 300; // maximum weight a customer can start with
const int CUST_MIN_WGT = 70; // minimum weight a customer can start with
const short CUST_MAX_HEALTH = 100; // maximum health a customer can start with
const short CUST_MIN_HEALTH = 1; // minimum health a customer can start with
const int CUST_WEIGHT_GAIN = 4;  // Weight gained by customer after eating dawg
const int NUM_CONTESTANTS = 15;  // starting number of contestants
const int CUST_EAT_HEALTH_LOSS = 2;  // Health lost from eating dawg
const int CUST_EAT_PATHOGEN_HEALTH_DIVISOR = 2; // Divides the health by val after
//                                                 eating pathogen dawg
const int STARTING_ROUND_NUM = 1;    // starting round
const int PERCENT_MIN = 1;    // MIN PERCENTAGE OUTCOME
const int PERCENT_MAX = 100;  // MAX PERCENTAGE OUTCOME
const int VOMIT_CHANCE = 50;  // chance for neighbor to throw up
const int START_FOODFIGHT_CHANCE = 70;  // chance of starting a foodfight
const int CONT_FOODFIGHT_CHANCE = 80;  // chance of starting a foodfight
const int CUST_THROW_HEALTH_INC = 2;    //Increase of health of customer after throwing
const string FILE_NAME = "names.dat";  // file name of file with names in it
const int BARF_STATEMENTS = 12;        // number of barf statements
// statements used to emphasize barfing
const string BARF[BARF_STATEMENTS] = {"BLAHBLAHBLAH!","BLECHBLECH!","PPHLEEB!",
  "CAW! CAAAW!","SPAM I AM!","I DO NOT LIKE!","GLOBGLORB!","FLOP BLUB!",
  "HURCH GLOP!","VLOOGH!","SHLOUG GLUH!","QWERTY GLOB!"};

// descr: the percentResult() function calculates and returns the outcome of
//        a probability
// pre: p is a number between 1 and 100 (inclusive)
// post: returns whether the outcome was successful or not(like rolling D&D die)
bool percentResult(const int p);
// descr: the rand_num() function returns a random number given a max and min (int)
// pre: max and min are declared and max is greater than min
// post: returns a random integer within the range
int rand_num(const int max, const int min);
// descr: the get_file_size() function returns the size of a file
// pre: none
// post: returns the number of lines in a file with strings in it
int get_file_size();
// descr: the generate_name() function returns a name from a file
// pre: none
// post: returns a name
string generate_name();
// descr: the vomitChain() function simulates the chain reaction of contestants
//        vomiting
// pre: c is a filled array of customers with size being the number of customers
//      in that array; start is the index of the first puker, and meister is
//      initialized as the hawtdawgmeister
// post: outputs messages corresponding to puking contestants and has a chance
//       to trigger the ffChain.
void vomitChain(Customer c[], const int size, const int start, hawtdawgmeister meister);
// descr: the ffChain() function simulates the event of a food fight
// pre: c is a filled array of customers with size being the number of customers
//      in that array; start is the index of the thrower, and meister is
//      initialized as the hawtdawgmeister
// post: outputs messages corresponding to contestants throwing dawgs at others
//       and changes the values of contestants health and money
void ffChain(Customer c[], const int size, const int start , hawtdawgmeister meister);
// descr: the declareWinner() function handles the output and decides who the
//        winner(s) is
// pre: array c has been initialized and r has the same size as c and size is
//      the size of the array
// post: outputs winner message and changes the values of the r array
void declareWinner(Customer c[], Customer r[], const int size);


#endif
