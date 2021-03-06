/*  Created by
    Ethan Roberts
	CS 415 Operating Systems
	
	This program will accept a string from a "terminal" and parse that string.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//cite: http://www.cplusplus.com/reference/string/string/push_back/
// used for converting single char to string for pushing into string vector
vector<string> parseCommandLine(string aCommandLine)
{
	vector<string>tokenVector;
	vector<string>::iterator it;
	string tempWord = "";
	string tempLetter = "";
	int pushCount = 0;


	for (int i = 0; i < aCommandLine.length(); ++i) {

		if (aCommandLine[i] >= 'A' && aCommandLine[i] <= 'z') {   //get only letters, no symbols
			tempLetter.push_back(aCommandLine[i]);
			tempWord += tempLetter;
			tempLetter.clear();
		}
		else if (pushCount == 0 && tempWord != "") {
			tokenVector.push_back(tempWord);
			++pushCount;
			tempWord = "";   //reset for next iteration
		}
		else if (pushCount >= 1 && tempWord != "") {
			tokenVector.push_back(tempWord);
			tempWord = "";
		}

	}
	if (tempWord != "") {   //get remaining token 
		tokenVector.push_back(tempWord); 
	}

	return tokenVector;
}



int main()
{
	vector<string>tokenVector;


	tokenVector = parseCommandLine("oh >> boy > hithere ");  //returning vector with tokens

	cout << "Vector size: " << tokenVector.size() << "\n";
	cout << "Returns tokens: ";
	for (auto value : tokenVector) {
		cout << value << "   ";
	}




	cout << "\n\n\n";
	tokenVector.clear();
	tokenVector = parseCommandLine("ls >> cmd | dir <<");  //returning vector with tokens

	cout << "Vector size: " << tokenVector.size() << "\n";
	cout << "Returns tokens: ";
	for (auto value : tokenVector) {
		cout << value << "   ";
	}





	cout << "\n\n\n";
	tokenVector.clear();
	tokenVector = parseCommandLine(">> chmod | myTextFile << linux >> >>  bigCommand <<");  //returning vector with tokens

	cout << "Vector size: " << tokenVector.size() << "\n";
	cout << "Returns tokens: ";
	for (auto value : tokenVector) {
		cout << value << "   ";
	}


    return 0;
}

