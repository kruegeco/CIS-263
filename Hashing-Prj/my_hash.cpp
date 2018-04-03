///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/*********************************************************************** 
* PROJECT 2-2; CIS263-Hs "Hashing"
* CIS 263 MWF 1200-1250, Winter 2017
* Professor Woodring, Ira
* Partners: Tim
* @author Krueger, Cody
* @version v1.0 20MAR2017 15:45
*
* Description: This is the definition and header file for our hashing 
*  function, providing a triple hashing of the input name. 
*
* References: TODO (update ref-v and descript-^)
*  note - my previous cpp class text was learncpp.com
*  DataStructuresAndAlgorithmAnalysisInCpp_2014.pdf page (195 to 1)
*
***********************************************************************/

// Includes
#include <iostream>
#include <string>
#include "my_hash.h"



boolean insert(const Superhero & s) {
	int tableSize = 17011;
	int position = 0; 

	std::string n = s.getName();
	position = hash1(n, tableSize);
	

}

Superhero & get(const std::string name) {
	int tableSize = 17011;

}

//Helper Functions
//textbook pg 195
unsigned int hash1( const string & key, int tableSize )
{
	int hashVal = 0;
	for( char ch : key )
		hashVal += ch;
	return hashVal % tableSize;
}

//textbook pg 195
unsigned int hash2( const string & key, int tableSize )
{
	return ( key[0] + 27 * key[1] + 729 * key[2] ) % tableSize;
}

//textbook pg 195
unsigned int hash3( const string & key, int tableSize )
{
	unsigned int hashVal = 0;
	for( char ch : key )
		hashVal = 37 * hashVal + ch;
	return hashVal % tableSize;
}

