// Programmer: Gabriel Snyder
// Student ID: gls8hz
// Date: 4/21/21
// File: HW07.cpp
// Purpose: contains function definitions for the program

#include "HW07.h"
#include "Customer.h"
#include "hawtDawg.h"
#include "hawtdawgmeister.h"
#include <iostream>

using namespace std;

bool percentResult(const int p)
{
  // if the randomly generated percent is less than or equal to the given
  //    percent than it is successful
  return (rand() % (PERCENT_MAX - PERCENT_MIN + 1) + PERCENT_MIN) <= p;
}

int rand_num(const int max, const int min)
{
  return rand() % (max - min + 1) + min;
}

int get_file_size()
{
  int file_size = 0;            // counts the size of the file
  string value;                 // stores the string into a placeholder
  ifstream fin;                 // input file stream
  fin.open(FILE_NAME);          // opens file
  // each line is read in until there is an empty string, counts each line
  while(getline(fin, value))
  {
    file_size++;                // increments file size
  }
  fin.close();                  // close file
  return file_size;
}

string generate_name()
{
  static int count = 0;         // count the number of names generated
  if(count==get_file_size())    // resets counter once end of file has been reached
    count = 0;
  int index = count;            // index of the name to be returned
  string value;                 // holds the inputted names
  ifstream fin;                 // input filestream
  fin.open(FILE_NAME);          // opens file
  // traverses the file until the index has been reached
  for(int i = 0; i<index;i++)
  {
    fin.clear();
    fin >> value;               // scans file and assigns it to value
  }
  fin >> value;                 // collects name at the index
  count++;                      // increments counter
  fin.close();                  // closes file
  return value;
}

void vomitChain(Customer c[], const int size, const int start, hawtdawgmeister meister)
{
  bool vomit = true;            // whether person has vomitted
  int count = start;            // index of vomitter
  string barf = BARF[rand_num(BARF_STATEMENTS-1, 0)];       // barf statement
  cout << "\t\t" << c[count].getName() << " barfs " << barf << endl;
  // loops until someone doesn't vomit or no contestant is next in the chain
  while(vomit && count < size-1)
  {
    count++;                     // increments counter
    if(!c[count].isAlive())      // checks if contestant is dead
    {
      vomit=false;               // ends the chain
    }
    else
    {
      // checks if the contestant decides not to vomit
      if(!percentResult(VOMIT_CHANCE))
      {
        cout << "\t\t" << c[count].getName() << " doesn't barf" << endl;
        // non-vomitting contestant has a chance to start a food fight
        if(percentResult(START_FOODFIGHT_CHANCE))
        {
          // ffChain outputs messages and can affect a customers values
          // such as health or money and affects the hawtdawgmeister's money
          // as well.
          ffChain(c,size, count, meister);
        }
        vomit=false;             // ends the chain
      }
      else
      {
        // barf statement is randomly chosen from a list of statements
        barf = BARF[rand_num(BARF_STATEMENTS-1, 0)];
        cout << "\t\t" << c[count].getName() << " barfs " << barf << endl;
      }
    }
  }
  // --------- Checks the other side of contestant array
  vomit = true;                   // resets whether person has vomitted
  count = start;                  // index of vomitter reset to starting person
  // loops until someone decides not to vomit or no contestant is next in the chain
  while(vomit && count > 0)
  {
    count--;                   // decrements counter
    if(!c[count].isAlive())    // checks if contestant is dead
    {
      vomit=false;             // ends the chain
    }
    else
    {
      // checks if the contestant decides not to vomit
      if(!percentResult(VOMIT_CHANCE))
      {
        cout << "\t\t" << c[count].getName() << " doesn't barf" << endl;
        // non-vomitting contestant has a chance to start a food fight
        if(percentResult(START_FOODFIGHT_CHANCE))
        {
          // ffChain outputs messages and can affect a customers values
          // such as health or money and affects the hawtdawgmeister's money
          // as well.
          ffChain(c,size, count, meister);
        }
        vomit=false;             // ends the chain
      }
      else
      {
        // barf statement is randomly chosen from a list of statements
        barf = BARF[rand_num(BARF_STATEMENTS-1, 0)];
        cout << "\t\t" << c[count].getName() << " barfs " << barf << endl;
      }
    }
  }
  return;
}
void ffChain(Customer c[], const int size, const int start, hawtdawgmeister meister)
{
  // target is randomly chosen, can include themselves, hawtdawgmeister is target
  //        if target = size
  int target= rand_num(size,0);
  int fighter = start; // index of fighter is initialized to given starting spot
  bool toss = true;      // whether another hawtDawg can be thrown or not
  // loops until a hawtdawg can't/won't be thrown
  while(toss)
  {
    hawtDawg dawg;         // projectile object
    // if the target is the hawtdawgmeister then the fighter gets banned and
    //    ends the fight
    if(target == size && c[fighter].getCash() >= dawg.getPrice())
    {
      c[fighter].toss(dawg, meister);     // dawg thrown
      cout << "\t\t\t" << c[fighter].getName() << " tosses dawg at "
           << meister.getName() << endl;
      c[fighter].BanHammer(meister);      // fighter banned
      toss = false;                       // fight stops
    }
    else if(c[target].isAlive() && c[fighter].getCash() >= dawg.getPrice())
    {
      c[fighter].toss(dawg, meister);    //dawg thrown
      cout << "\t\t\t" << c[fighter].getName() << " tosses dawg at "
           << c[target].getName() << endl;
      fighter = target;                 // next thrower becomes previous target
      // next fighter can choose to toss or not toss (determined by chance)
      toss = percentResult(CONT_FOODFIGHT_CHANCE);
      target = rand_num(size,0);           // new target is assigned
    }
    else          // can't throw if target is dead or fighter can't afford dawg
    {
      toss = false;                  // can't throw
    }
  }
  return;
}

void declareWinner(Customer c[], Customer r[], const int size)
{
  int index =0;      // used to fill and traverse the survivor array r
  int maxHPIndex=0;     // index of contestant with highest health value
  int numSurvivors = 0;    // number of remaining contestants(size of array r)
  int numWinners=1;        // number of winners
  // traverses contestant array and fills survivor array with alive and
  // non-banned contestants, and increments the number of survivors
  for(int i=0;i<size;i++)
  {
    // if alive and not banned
    if(c[i].isAlive() && !c[i].isBanned())
    {
      r[index]=c[i];          // fills survivor array
      index++;                // traverses using index
      numSurvivors++;         // increment survivors(size of survivor array)
    }
  }
  cout << "\n\t----------SURVIVORS----------" <<endl;

  if(numSurvivors)                // if there is at least one survivor
  {
    // outputs list of survivors and finds the one with highest health value
    cout << r[0] << endl;
    for(int i=1;i<numSurvivors;i++)
    {
      cout << r[i] << endl;
      // checks for max health value
      if(r[maxHPIndex].getHealth() <= r[i].getHealth())
      {
        maxHPIndex=i;     // sets new potential winner's index to one with
        //                   higher or equal health
      }
    }
    // outputs the winner's podium
    cout << "\n\t----------POSSOM DEF[EATIN'] PODIUM---------"<<endl;
    // traverses array of survivors and checks if there is more than one winner
    for(int i=0;i<numSurvivors;i++)
    {
      // if there are more than one contestant with the highest health
      if(r[maxHPIndex].getHealth() == r[i].getHealth() && maxHPIndex!=i)
      {
        numWinners++;            // increment number of winners
      }
    }
    // reset index of survivor array to the start
    index =0;
    // loops until there are no more winners to output or the size of array has
    // been reached
    while(numWinners>1 && index < numSurvivors)
    {
      // if the health of the survivor is the same as the one with the highest
      //   and isnt the survivor with the highest then output them as a winner
      if(r[maxHPIndex].getHealth() == r[index].getHealth() && maxHPIndex!=index)
      {
        cout<< "\t" << r[index].getName() << " is the Winner!! " << endl;
        numWinners--;         // decrements the number of winner left to output
      }
      index++;            // increments index to next survivor
    }
    // outputs the final winner with the highest health
    cout << "\t" << r[maxHPIndex].getName() << " is the Winner!! " << endl;
  }
  else       // if nobody survived
  {
    cout << "\n\tNOBODY SURVIVED..." <<endl;
  }
  return;
}
