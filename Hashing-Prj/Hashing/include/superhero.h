#include <iostream>
#include <string>
#include <cstdbool>
#ifndef Superhero_H
#define Superhero_H

///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/*********************************************************************** 
* PROJECT 2-3; CIS263-Hs "Hashing"
* CIS 263 MWF 1200-1250, Winter 2017
* Professor Woodring, Ira
* Partners: Cody Krueger
* @author Tim Van Dyke
* @version v1.0 20MAR2017 15:45
*
* Description: This is the header file for the superhero type 
*
***********************************************************************/
class Superhero
{
private:
	//all the values for superhero
	//where they are on the page
	int page_id;

	//their name
	std::string name;

	//alias/realname
	std::string urlslug;

	//whether or not they are known to the world
	std::string id;

	//whether they are "good" or "bad"
	std::string alignment;

	//their eye color
	std::string eye_color;

	//their hair color
	std::string hair_color;
	
	//male or female
	std::string sex;

	//I honestly don't know what this is
	std::string gsm;

	//whether they are alive or dead
	std::string alive;

	//some number
	int appearances;

	//the date they were first seen
	std::string first_appearance;
	
	//the year they were first seen
	int year;


public:
	/*****************************************************
	The constructor for superheros
        @PARAM int page_id
        @PARAM std::string name
        @PARAM std::string urlslug
        @PARAM std::string id
        @PARAM std::string alignment
        @PARAM std::stirng eye_color
        @PARAM std::string hair_color
        @PARAM std::string sex
        @PARAM std::string gsm
        @PARAM std::string alive
        @PARAM int appearances
        @PARAM std::string first_appearance
        @PARAM int year
	*****************************************************/
	Superhero(int page_id, std::string name, std::string urlslug, std::string id, std::string alignment, std::string eye_color, std::string hair_color, std::string sex, std::string gsm, std::string alive, int appearances, std::string first_appearance, int year); 
	
	/*****************************************************
	@return this superhero's name
	*****************************************************/
	std::string getName();
};
	
#endif
