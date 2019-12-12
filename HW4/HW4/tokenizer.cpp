// Nathan VanOverbeke
// CS 201
// HW 4
// 10/13/2019
// This program will take input from the user; a bunch of text that ends with "end"
// and it will, if possible, tokenize the text into seperate strings/identifiers

#include "tokenizer.hpp";


int main() {
	std::vector<std::string> tokens;

	std::cout << "Please type a string. When done press enter." << std::endl;

	do{
		std::string userInString;
		bool white = readLine(userInString);

		if (!white) {
			tokens.push_back("");
		}
			stringToTokenWS(userInString, tokens);

	} while ((tokens[tokens.size()-1] != "end") && (tokens[tokens.size()-1] != "End") && (tokens[tokens.size()-1] != "END"));

	AnalyzeTokens(tokens);
}