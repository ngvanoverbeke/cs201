// Nathan VanOverbeke
// HW5 (take 2)
// 11/10/19
#include "truncstruct.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <iostream>
#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

StringInfo _string;
const int ControlHeight = 25;
Fl_Window* window = new Fl_Window(420, 240);
Fl_Button* truncBtn = new Fl_Button(60, 160, 300, ControlHeight, "trunc");
Fl_Button* closeBtn = new Fl_Button(60, 200, 300, ControlHeight, "Close Window");
Fl_Input* inStr = new Fl_Input(120, 40, 240, ControlHeight, "Type a string");
Fl_Input* inInt = new Fl_Input(120, 80, 240, ControlHeight, "how much?\n (int)");
Fl_Output* truncResult = new Fl_Output(120, 120, 240, ControlHeight, "trunc result");

void OnCloseCallback(Fl_Widget* w, void* data) {
	Fl_Window* window = (Fl_Window*)data;
	if (window) window->hide();
}

void TruncButtonCallback(Fl_Widget* w, void* data) {
	auto MyTempStruct = trunc(_string);
	truncResult->value (MyTempStruct.str.c_str());
}

void DeyBTyping(Fl_Widget* w) {
	_string.str = inStr->value();
}

void giveMeNumbrPls(Fl_Widget* w) {
	_string.len = std::atoi(inInt->value());
	std::cout << _string.len << std::endl;
}


int main(int argc, char** argv) {
	_string.len = 0;
	_string.str = "";
	// *******Callbacks*******
	inStr->when(FL_WHEN_ENTER_KEY);
	inStr->callback(DeyBTyping);
	
	inInt->when(FL_WHEN_ENTER_KEY);
	inInt->callback(giveMeNumbrPls);

	truncBtn->callback(TruncButtonCallback, (void*)window);
	closeBtn->callback(OnCloseCallback, (void*)window);

// *******How It's Made*******
	inStr->labelfont(FL_BOLD);
	inStr->labeltype(FL_SHADOW_LABEL);


	truncResult->labelfont(FL_BOLD);
	truncResult->labeltype(FL_SHADOW_LABEL);

	inInt->labelfont(FL_BOLD);

	inInt->labeltype(FL_SHADOW_LABEL);


	window->end();
	window->show(argc, argv);
	return Fl::run();
}