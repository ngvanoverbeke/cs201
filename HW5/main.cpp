// Nathan VanOverbeke
// HW5 (take 2)
// 11/10/19
// This program takes a string and a length for the output string from a user
// it then truncates off the end of the string, all using a beautiful ui design

#include "truncstruct.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

// *******Definitions*******
StringInfo _string;
const int ControlHeight = 25;
Fl_Window* window = new Fl_Window(420, 240);
Fl_Button* truncBtn = new Fl_Button(60, 160, 300, ControlHeight, "trunc");
Fl_Button* closeBtn = new Fl_Button(60, 200, 300, ControlHeight, "Close Window");
Fl_Input* inStr = new Fl_Input(120, 40, 240, ControlHeight, "Type a string");
Fl_Input* inInt = new Fl_Input(120, 80, 240, ControlHeight, "how much?\n (int)");
Fl_Output* truncResult = new Fl_Output(120, 120, 240, ControlHeight, "trunc result");


// *******Callback Definitions*******

// closes the window and program if the user clicks the "close" button
void onCloseCallback(Fl_Widget* w, void* data) {
	Fl_Window* window = (Fl_Window*)data;
	if (window) window->hide();
}

// callback function for when the "truncate" button is pressed
void truncButtonCallback(Fl_Widget* w, void* data) {
	auto StructResult = trunc(_string);
	truncResult->value (StructResult.str.c_str());
}

void inStringCallback(Fl_Widget* w) {
	_string.str = inStr->value();
}

void inIntCallback(Fl_Widget* w) {
	_string.len = std::atoi(inInt->value());
}

// *******main (it does everything)*******

int main(int argc, char** argv) {
	_string.len = 0;
	_string.str = "";

// *******Callbacks*******

	// "WHEN_CHANGED" will update the contents of the string box whenever the contents of it change
	inStr->when(FL_WHEN_CHANGED);
	inStr->callback(inStringCallback);
	
	// same as above, but for the truncate length box
	inInt->when(FL_WHEN_CHANGED);
	inInt->callback(inIntCallback);

	// callback functions for the truncate and close button
	truncBtn->callback(truncButtonCallback, (void*)window);
	closeBtn->callback(onCloseCallback, (void*)window);


// *******How It's Made*******
// this stuff changes the way the box and it's features are drawn/created

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