///Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************
* HOMEWORK 2-2; CIS263-S&Q "Stacks and Queues"
* CIS 263 MWF 1200-1250, Winter 2017
* Professor Woodring, Ira
* Partners: NONE
* @author Krueger, Cody
* @version v1.0 22FEB2017 12:45
*
* Description: This is the src file for stacks and queues.  It contains
*  functions balancedSymbols and iToP.  These functions use stacks to do
*  2 things.  The first is to access if symbols are balanced in a string
*  input.  The next takes a string containing infix expressions and
*  converts them to post fix expressions.  
*  Note: not set up in a class, just defined sequentially. 
*
* References: 
*  learncpp.com - for ascii values
*  note - my previous cpp class text was learncpp.com
*  http://www.cplusplus.com/reference/stack/stack/stack/ - stack member functions
*  DataStructuresAndAlgorithmAnalysisInCpp_2014.pdf page (103 to 108)
*  Solutions Manual (page 21 to 23)
*  note: Both of these posted on your GitHub
*
***********************************************************************/

// Includes
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


bool balancedSymbols(std::string input) {
    std::cout << "Parsing..." << std::endl;
    // Declare Variables
    std::stack<char, std::deque<char> > symbols; //FIXED does deque need a type passed? YES
    //Itterate through the string passed
    for (auto it=input.begin(); it!=input.end(); ++it) { 
        //Check element as we itterate
        //  first if it matches a open symbol
        if (*it=='{' || *it=='(' || *it=='[') {
            symbols.push(*it);
        } //If element is a closing brace...
        else if (*it=='}' || *it==')' || *it==']') {
            //Check that there even is a possible matching symbol
            if (symbols.empty()) { //FIXME what if the list is empty? (does top return -1?)
                std::cout << "ERROR! CLOSE EARLY! Close symbol before open symbol detected." << std::endl;
				return false;
            } else { 
                //Check for the matching closing symbol
                if (symbols.top()=='{' && *it=='}')
                    symbols.pop();
                else if (symbols.top()=='(' && *it==')')
                    symbols.pop();
                else if (symbols.top()=='[' && *it==']')
                    symbols.pop();
                //Note! v2 could have popped, then checked if equal to for shorter code possibly
				//No match found? throw error
				else { 
                	std::cout << "ERROR! NO MATCH! Closing symbol without match detected." << std::endl;
					return false;
				}
            }    
        }
    }
    if (!symbols.empty()) { 
        std::cout << "ERROR! EoF REACHED NO MATCH! End of File reached without matching symbol." << std::endl;
		return false;
	}
	//If this line is reached, then all cases passed and this test was a success
    std::cout << "Finished." << std::endl;
    return true;
}

std::string iToP(std::string input) {
    std::cout << "Converting..." << std::endl;
    // Declare Variables
    std::string stream;
    std::stack<char, std::deque<char> > oper; //FIXME does deque need a type passed?
    //Itterate through the string passed
    for (auto it=input.begin(); it!=input.end(); ++it) { 
        //Check element as we itterate
        //  Check first if a character is 0 through 9 in ASCII
        if (*it>=48 && *it<=57)
            //Append if true
            stream += *it;
		//If an operator, execute a series of checks
        else {
            switch (*it) 
            {
				//If a opening '(' push always
                case '(':
                    oper.push(*it);
                    break;
				//If a closing ')' output until opening '(' reached
                case ')':
                    while (oper.top()!='(' && !oper.empty()) {
                        stream += oper.top();
                        oper.pop();
                    }
                    oper.pop();
                    break;
                //Multiplication and Division, output while not lower and not opening '('
                // push *it after
                case '*':
                case '/':
                    while ((oper.top()!='+' || oper.top()!='-' || oper.top()!='(')
                            && !oper.empty()) {
                        stream += oper.top();
                        oper.pop();
                    }
                    oper.push(*it);
                    break;
                //Addition and Subtraction, output while not opening '('
                // push *it after
                case '+':
                case '-':
                    while (oper.top()!='(' && !oper.empty()) {
                        stream += oper.top();
                        oper.pop();
                    }
                    oper.push(*it);
                    break;
            } //Could make a second stack holing integers which represent
              //    precidence and then pop as preference is seen, however, that will require more memory.
        }
    } //EoFor
    //Input string is empty: output all remaining op from stack
    while (!oper.empty()) {
        stream += oper.top();
        oper.pop();
    }
    //Display success
    std::cout << "Finished." << std::endl;
    //Show output
    std::cout << stream << std::endl;
    //Return finished conversion
    return stream;
}
    

// Main Function
int main(int argc, char** argv)
{
	//std::stack<char, std::deque <char> >
	std::string input = argv[1];
	
    
    //balancedSymbols(input);
    //iToP(input);
    
    //End Program
    return 0;
};
