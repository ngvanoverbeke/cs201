// Nathan VanOverbeke
// 9/27/2019
// CS 201
//

#include <string>
#include <vector>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;


int main(){
	string UserString;
	string LoweCase;
	string UpperCase;
	string NotACase;
	vector<string> UserVector;

	cout << "Please type a string:	";
	
	getline(cin, UserString);

	UserVector.push_back(UserString);

	for (int i = 0; i < UserString.size(); i++){
		char c = UserString.at(i);
		if (c >= 'a' && c <= 'z') {
			LoweCase.push_back(c);
		}
		else if (c >= 'A' && c <= 'Z') {
			UpperCase.push_back(c);
		}
		else {
			NotACase.push_back(c);
		}

	}
	cout << LoweCase << endl;
	cout << UpperCase << endl;
	cout << NotACase << endl;
	return(0);
		
}