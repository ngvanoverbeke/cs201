#include "tokenizer.hpp"

bool readLine(std::string& str) {
	std::cout << "Please type some text. When done type end/End/END" << std::endl;
	std::getline(std::cin, str);
	if (str.empty()) {
		return false;
	}
	else {
		return true;
	}
}

//unsigned stringToTokenWS(std::vector<std::string>& tokens) {

//}

void AnalyzeTokens(const std::vector<std::string>& tokens) {

}