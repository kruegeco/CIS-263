Cody Krueger and Tim Van Dyke
*note counter is in main.cpp and collisions is in my_hash.h
they seperately count the same thing to cross reference results.

hash1 function:
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

Counter:14077
Collisions:14077


hash2 function:
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

Counter:13893
Collisions:13893


hash3 function
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

Counter:5894
Collisions:5894

*note all hash functions are almost directly from the textbook.
