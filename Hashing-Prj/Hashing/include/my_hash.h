///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/*********************************************************************** 
* PROJECT 2-2; CIS263-Hs "Hashing"
* CIS 263 MWF 1200-1250, Winter 2017
* Professor Woodring, Ira
* Partners: Tim Van Dyke
* @author Krueger, Cody
* @version v1.0 20MAR2017 15:45
*
* Description: This is the definition and header file for our hashing 
*  function, providing 3 different hashing functions that can be used on 
*  the input name.  It is all contained in the header file since it uses
*  generics.
*
* References: 
*  note - my previous cpp class text was learncpp.com
*  http://www.learncpp.com/cpp-tutorial/133-template-classes/
*  http://www.learncpp.com/cpp-tutorial/1-10a-header-guards/
*  DataStructuresAndAlgorithmAnalysisInCpp_2014.pdf page (195)
*  http://www.cplusplus.com/reference/vector/vector/vector/
*
*  for generic reference
*  for header guards reference
*  for hashing functions
*  for vector and iterator use
*
***********************************************************************/

// Header Guards
#ifndef __my_hash__
#define __my_hash__

// Includes
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

// Generic
template <typename HashedObj>

/****************************************************************
 * A class to hold all the hash methods 
 ***************************************************************/
class my_hash {
    
    // Private Section
    private:

        // Instance Variables
        /** the size of the table  */ 
        int tableSize = 17011; 

        /** the current position  */ 
        int position;

        /** pointer representing the array */
        std::vector<HashedObj>* hashMap;
	
		/** the number of collision */
		int collisions;

    /****************************************************************
     * this is the first hash function
	 * our inspiration was the textbook page 195
	 * @param std::string & key
	 * @param int tableSize
	 * @return unsigned int
     ***************************************************************/
	unsigned int hash1( const std::string & key, int tableSize )
	{
		int hashVal = 0;
		for( char ch : key )
			hashVal += ch;
		return hashVal % tableSize;
	}

	/****************************************************************
     * this is the second hash function
	 * our inspiration was the textbook page 195
	 * @param std::string & key
	 * @param int tableSize
	 * @return unsigned int
     ***************************************************************/
	unsigned int hash2( const std::string & key, int tableSize )
	{
		return ( key[0] + 27 * key[1] + 729 * key[2] ) % tableSize;
	}
	
	/****************************************************************
     * this is the third hash function
	 * our inspiration was the textbook page 195
	 * @param std::string & key
	 * @param int tableSize
	 * @return unsigned int
     ***************************************************************/
	unsigned int hash3( const std::string & key, int tableSize )
	{
		unsigned int hashVal = 0;
		for( char ch : key )
			hashVal = 37 * hashVal + ch;
		return hashVal % tableSize;
	}

    public:
	/****************************************************************
	 * This is the std, dev defined constructor for my_hash.  
	 *  It takes no parameters.
	 ***************************************************************/
	my_hash() {
		//tableSize = 17011;
		position = 0;
		hashMap = new std::vector<HashedObj> [tableSize];
	}

	/****************************************************************
     * This is the std, dev-defined destructor for AUDS.  
     ***************************************************************/
    ~my_hash() {
        delete[] hashMap;
    }
	
	/****************************************************************
	 * inserts objects into our hashmap
	 * @PARAM const HashedObj
	 * @return bool true or false depending on if it has a collision
	 ***************************************************************/
	bool insert(const HashedObj & s) {
		bool collide = false;
		std::string n = ((Superhero)s).getName();
		//position = hash1(n, tableSize);
		//position = hash2(n, tableSize);
		position = hash3(n, tableSize);
		if (!hashMap[position].empty()) {
			collisions++;
			collide = true;
		}
		hashMap[position].insert(hashMap[position].begin(),s);
		return collide;
	}

	/****************************************************************
	 * inserts objects into our hashmap
	 * @PARAM const std::string name
	 * @RETURN a REFERENCE to the hashed obj, it doesn't 
	 * remove the object
	 ***************************************************************/
	HashedObj & get(const std::string name) {
		//position = hash1(name, tableSize);
		//position = hash2(name, tableSize);
		position = hash3(name, tableSize);
		// The vector at position
		//hashMap[position] = std::vector<HashedObj>* posVect;
		if (hashMap[position].size()>1) {
			//std::vector<HashedObj>::iterator 
			auto it = hashMap[position].begin();
			for (it; it != hashMap[position].end(); ++it) {
				// If name is the same as target, return that reference
				if (*it.getName() == name) {
					return &*it;					
				}
			}				 
		}
		else
			return hashMap[position].front();
		std::cout<< "ERROR! Name not found!" << std::endl;
	}

	/****************************************************************
 	* This is the getter for collisions.
	*  @return int-collisions
 	***************************************************************/
	int getCollisions () {
		return collisions;
	}
	
};

#endif
