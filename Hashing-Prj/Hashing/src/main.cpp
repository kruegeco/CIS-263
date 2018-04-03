#include "superhero.h"
#include "csv.h"
#include "my_hash.h"

///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/*********************************************************************** 
* PROJECT 2-1; CIS263-Hs "Hashing"
* CIS 263 MWF 1200-1250, Winter 2017
* Professor Woodring, Ira
* Partners: Tim Van Dyke
* @author Krueger, Cody
* @version v1.0 20MAR2017 15:45
*
* Description: This is the main file for our hashing function test.  It 
*  creates an instance of our hash, loads/parses the csv file, and keeps 
*  track of the number of collisions, printing that number to the 
*  terminal.  
*
* References: TODO (update ref-v and descript-^)
*  learncpp.com - for ascii values
*  note - my previous cpp class text was learncpp.com
*  http://www.cplusplus.com/reference/stack/stack/stack/ - stack member functions
*  DataStructuresAndAlgorithmAnalysisInCpp_2014.pdf page (103 to 108)
*  Solutions Manual (page 21 to 23)
*  note: Both of these posted on your GitHub
*
***********************************************************************/

/*************************************************************
The main method. This method uses the library csv.h to parse
through the csv "sup.csv" file on the root of the project.
It creates new instances of superheros, and then gives them 
to the hash map FIXME
csv parser: https://github.com/ben-strasser/fast-cpp-csv-parser.git
*************************************************************/
int main(int argc, char** argv) {

	//create the custom hash map
	my_hash<Superhero>* theHash = new my_hash<Superhero>();
	int counter = 0;

	//the filename
	std::string file = "sup.csv";
	
	//using the syntax from the github site, this is the csv parser we pulled in
	io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',','"'> > in(file);
	//tells the parser our columns we care about
	in.read_header(io::ignore_extra_column, "page_id", "name", "urlslug", "ID", "ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", "APPEARANCES", "FIRST APPEARANCE", "Year");
	//temp variables to get values from parser
	int page_id;
	std::string name;
	std::string urlslug;
	std::string id;
	std::string alignment;
	std::string eye_color;
	std::string hair_color;
	std::string sex;
	std::string gsm;
	std::string alive;
	int appearances;
	std::string first_appearance;
	int year;

	//parses through the file
	while(in.read_row(page_id, name, urlslug, id, alignment, eye_color, hair_color, sex, gsm, alive, appearances, first_appearance, year)) 
	{
		//makes a superhero with the values of the current line
		Superhero* S = new Superhero(page_id, name, urlslug, id, alignment, eye_color, hair_color, sex, gsm, alive, appearances, first_appearance, year);
		//gives the superheros to the hash functions
		//line below for error checking
		//std::cout << S->getName() << std::endl;
		if(theHash->insert(*S)){
			counter++;		
		}
	}

	std::cout << "Counter:" << counter << std::endl;
	std::cout << "Collisions:" << theHash->getCollisions() << std::endl;
	return 0;
};
