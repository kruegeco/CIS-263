
///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************  
 * EXTRA CREDIT 2-1; CIS263-EC "Dynamic Programming" (O/1 KnapSack)
 * CIS 263 MWF 1200-1250, Winter 2017
 * Professor Woodring, Ira
 * @author Krueger, Cody
 * @version v1.0 22APR2017 18:45
 *
 * Description: This is the main file for our our sudoku solver.  It acts
 *  as a driver program to begin the backtracking.  It also holds an 
 *  instance of the 2D array we begin with, representing the board. When 
 *  the solution is finished it prints this to the terminal.   
 *
 * References: TODO (update ref-v)
 *  Tim Vandyke helped me understand this
 *  Also this youtube video teaching the principles really helped me 
 *   grasp it: https://www.youtube.com/watch?v=8LusJS5-AGo
 *  For Max Function: http://www.cplusplus.com/reference/algorithm/max/
***********************************************************************/

//Includes
//#include "KnapSack.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//Function Declaration
void printTable(int board[8][51]);

//Main Start
int main(int argc, char** argv) {

  //Arrays of items
  //Was not sure if this was neede, but I sorted the items by weight first.
  // thus note item order here is {0, 1, 5, 2, 4, 6, 3}
  int iWt[7] = {0, 15, 23, 25, 30, 37, 45}; 
  int iVal[7] = {0, 100, 275, 350, 67, 168, 225};
  
	//Total Value Chart
	int tVal[7][51]; //arr[row][col]
  
  //Prefill chart
  //int i = 0
	//for (int j = 0)
	
	//Fill Chart
	for (int i = 0; i < 8; i++) {
	  for (int j = 0; j < 52; j++) {
	    if (i == 0 || j == 0) {
	      tVal[i][j] = 0;
	    }
	    else if (j < iWt[i]) {
	      tVal[i][j] = tVal[i-1][j];
	    }
	    else{
	      tVal[i][j] = std::max(iVal[i]+tVal[i-1][j-iWt[i]], tVal[i-1][j]);
	    }
	  }
	}
	
  //Chart Solution
  std::cout << "-------After Being Filled------" << std::endl;
  printTable(tVal);
  
  std::cout << "Solution: " << tVal[6][50] << std::endl;
  

	return true;
};//EoM

void printTable(int board[7][51]) {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 51; j++) {
      std::cout << "[" << board[i][j] << "]";
    }	
    std::cout << std::endl;
  }
}
