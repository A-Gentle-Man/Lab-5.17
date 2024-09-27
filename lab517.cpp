#include <iostream>                     // for I/O
#include <cstring>                      // for strlen()
#include <cstdlib>                      // for random numbers
#include <unistd.h>                     // for sleep()
#include "ZyLab.h"                      // for ZyLab Setup
using namespace std;

int main(int argc, char **argv) {

   const int DEFAULT_NUMBER_OF_ROUNDS = 2;
   int       numRounds = DEFAULT_NUMBER_OF_ROUNDS;

   // if a command line argument is given, use that string to init the
   // "random" sequence and set the number of rounds to play the game
   if (argc == 2) {
      numRounds = strlen(argv[1]);
   }

   string    s;                         // A string used to pause the game
   char      c;                         // The player's typed characters
   char     *seq = new char[numRounds]; // Sequence of numRounds colors to match
   char      colors[] = "RGBY";         // Allowable colors
   bool      lost = false;              // Indicates whether we win or lose
   int       round;                     // Indicates the current round

   // Initialize random number generator
   srand(time(0));

   // Determine the random color sequence using either argv[1] or
   // randomly determined letters from 'R', 'G', 'B', and 'Y'
   for (int j = 0; j < numRounds; j++) {
      seq[j] = (argc == 2) ? argv[1][j] : colors[rand() % 4];
   }

   // Wait until the player is ready
   cout << "Welcome to Simon, press enter to play .... ";
   getline(cin, s, '\n');

   round = 1;
   while(!lost && (round < (numRounds + 1))) {
      cout << "Simon says: ";
      for(int k = 0; k < round; k++) {
         cout << seq[k] << flush;
         sleep(1);
         cout << "\010." <<flush;
      }
      cout << endl;
      cout << "Please enter " << round << " characters to match: ";
      for(int k = 0; k < round; k++) {
	      cin >> c;
	      if (c != seq[k]) {
		      lost = true;
		      break;
	      }
      }
      if(!lost) {
      	system(string("clear"));
      	round++;
      }
      else {
	break;
      }
   }

   if(lost) {
	   cout << endl;
	   cout << "Sorry, you lost." << endl;
   	   cout << "The correct sequence was: ";
	   for(int k = 0; k < round; k++) {
		   cout << seq[k];
	   }
   }
   else {
	   cout << "Congrats! you win!";
   }
   cout << endl;
        
   return 0;
}
