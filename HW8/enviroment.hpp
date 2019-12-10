// Nathan VanOverbeke
// CS201
// 12/8/19
// handles the header data for enviroment.cpp
#pragma once
class enviroment {
	public:
		bool heater = false;
		int temperature = 71;
		void iteration() {
			if (heater){ temperature++; }
			else{ temperature--; }
		}
};