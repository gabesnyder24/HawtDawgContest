// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: main.cpp
// Purpose: Extravagent program that simulates a hawtdawg eating contest
//          and outputs results of each round and the winner(s) at the end

#include "HW07.h"
#include "Customer.h"
#include "hawtDawg.h"
#include "hawtdawgmeister.h"
#include <iostream>

using namespace std;

int main()
{
  srand(time(0));                    // seeds rand function
  bool repeat = true;                // whether to continue to next round or not
  int round = STARTING_ROUND_NUM;    // the round number
  int dawgsEaten = 0;                // number of hawtdawgs eaten
  Customer players[NUM_CONTESTANTS];     // array of contestants
  Customer runners[NUM_CONTESTANTS];     // holds the runner ups
  hawtdawgmeister Cletus("Cletus", 0.0);    // hawtdawgmeister is cletus

  // formats for dollars
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "WELCOME TO THE ROADKILL EATIN' CONTEST!!" << endl;
  cout << "LET THE MADNESS BEGIN!!" << endl;
  cout << "\nThe contestants are " << endl;
  // traverses array and outputs the contestants info
  for(int i = 0; i< NUM_CONTESTANTS;i++)
  {
    cout << players[i] << endl;       // outputs the contestant
  }
  // loops until no one eats a hawtdawg
  while(repeat)
  {
    cout << "\n------------------------ ROUND #" << round << "-------------------\n"<<endl;
    dawgsEaten=0;               // number of dawgs eaten this round
    // loops through all contestants
    for(int i=0; i<NUM_CONTESTANTS; i++)
    {

      hawtDawg dawg;               // initializes hawtdawg
      // checks if player is alive, can afford dawg and isn't banned
      if(players[i].isQualified(dawg))
      {
        dawgsEaten++;          // increments number of dawgs eaten this round
        // dawg is eaten by contestant and checks if they vomit or not
        if(players[i].eat(dawg, Cletus))
        {
          // starts vomit chain if the person vomits, which outputs messages and
          // can call the vomitChain function which can also start a foodfight
          // which outputs messages and can change monetary holdings of the
          // objects
          vomitChain(players, NUM_CONTESTANTS, i, Cletus);
        }
      }
    }
    // shows cletus' money after each round
    cout << "\t\tCletus Money: $" << Cletus.getCash() << endl;
    repeat = dawgsEaten;    // if dawgsEaten = 0 then the contest stops
    round++;            // round number increases
  }
  // indicates that the contest is over
  cout << "\tNo one ate a dawg."<< endl;
  // winner is outputted and the runners array is filled with survivors
  declareWinner(players, runners, NUM_CONTESTANTS);
  cout << "\n\nThanks for stoppin' by! Y'all come back now ya hear?" << endl;
  cout << "\nSponsored by BART CORP. " << endl;
  return 0;
}
