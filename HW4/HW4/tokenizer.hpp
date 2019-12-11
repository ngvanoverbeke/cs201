#pragma once
#include <string>
#include <sstream>
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

bool readLine(std::string & str);
unsigned int stringToTokenWS(const std::string& input, std::vector<std::string>& tokens);
void AnalyzeTokens(const std::vector<std::string>& tokens);