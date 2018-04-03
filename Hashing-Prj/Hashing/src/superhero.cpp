#include "superhero.h"
///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/*********************************************************************** 
* PROJECT 2-4; CIS263-Hs "Hashing"
* CIS 263 MWF 1200-1250, Winter 2017
* Professor Woodring, Ira
* Partners: Cody Krueger
* @author Timothy Van Dyke
* @version v1.0 20MAR2017 15:45
*
* Description: This is the code for the get method and constructor are 
*
* References: TODO (update ref-v and descript-^)
*
***********************************************************************/

/**********************************************
The constructor for superheros
**********************************************/
Superhero::Superhero(int page_id, std::string name, std::string urlslug, std::string id, std::string alignment, std::string eye_color, std::string hair_color, std::string sex, std::string gsm, std::string alive, int appearances, std::string first_appearance, int year) {
	this->page_id = page_id;
	this->name = name;
	this->urlslug = urlslug;
	this->id = id;
	this->alignment = alignment;
	this->eye_color = eye_color;
	this->hair_color = hair_color;
	this->sex = sex;
	this->gsm = gsm;
	this->alive = alive;
	this->appearances = appearances;
	this->first_appearance = first_appearance;
	this->year = year;
}

/**********************************************
a getter for name
**********************************************/
std::string Superhero::getName() {
	return name;
}
