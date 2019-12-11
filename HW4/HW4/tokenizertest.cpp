#include "tokenizer.hpp"

// uses getline to return a bool and makes string useable by other functions
bool readLine(std::string& str) {
	
	std::getline(std::cin, str);
	if (str.empty()) {
		return false;
	}
	else {
		return true;
	}
}

// seperates a string into a given vector of strings, again, setting up for future functions
unsigned int stringToTokenWS(const std::string &input, std::vector<std::string>& tokens) {
	unsigned int total = tokens.size();
	std::istringstream tempStream(input);
	std::string temp;
	while (tempStream >> temp){
		tokens.push_back(temp);
		total++;
	}
	return total;
}

// this does all the fancy work of figuring out what each string within the vector is;
// is will tell you if it is whitespace, an identifier, an integer, a string, or other
void AnalyzeTokens(const std::vector<std::string>& tokens) {
	int loop = tokens.size();
	bool num = true;
	bool alpha = true;

	for (int i = 0; i < loop; i++) {
		num = true;
		alpha = true;
		for (unsigned int n = 0; n < tokens[i].size(); n++) {
			if (isdigit(tokens[i][n]) == false){
				num = false;
			}
		}

		for (unsigned int n = 0; n < tokens[i].size(); n++) {
			if (isalpha(tokens[i][n]) == false){
				alpha = false;
			}
		}

		if (tokens[i].empty()){
			std::cout << "[whitespace]		\"" << tokens[i] << "\"" << std::endl;
		}

		else if (alpha) {
			std::cout << "[identifier]		\"" << tokens[i] << "\"" << std::endl;
		}

		else if (num){
			std::cout << "[integer]		\"" << tokens[i] << "\"" << std::endl;
		}

		else if (tokens[i][0] == '\"' && tokens[i][tokens[i].size()-1]) {
			std::cout << "[string]		\"" << tokens[i] << "\"" << std::endl;
		}
		else {
			std::cout << "[other]		\"" << tokens[i] << "\"" << std::endl;
		}
	}
}