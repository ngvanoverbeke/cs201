// Nathan VanOverbeke
// HW5 (take 2)
// 11/10/19
#include "truncstruct.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

StringInfo _string;
const int ControlHeight = 25;
Fl_Window* window = new Fl_Window(340, 240);
Fl_Button* truncBtn = new Fl_Button(20, 160, 300, ControlHeight, "trunc");
Fl_Button* closeBtn = new Fl_Button(20, 180, 300, ControlHeight, "Close Window");
Fl_Input* inStr = new Fl_Input(80, 40, 240, ControlHeight, "Type a string");
Fl_Input* inInt = new Fl_Input(80, 80, 240, ControlHeight, "how much? (int)");


void OnCloseCallback(Fl_Widget* w, void* data) {
	Fl_Window* window = (Fl_Window*)data;
	if (window) window->hide();
}

void daTruncCloseCallback(Fl_Widget* w, void* data) {
	trunc(_string);
}

void DeyBTyping(Fl_Widget* w) {
	_string.str = inStr->value();
}

void giveMeNumbrPls(Fl_Widget* w) {
	_string.len = std::atoi(inStr->value());
}

int main(int argc, char** argv) {
	
	inStr->when(FL_WHEN_ENTER_KEY);
	inStr->callback(DeyBTyping);
	
	inInt->when(FL_WHEN_ENTER_KEY);
	inInt->callback(giveMeNumbrPls);

	inStr->labelfont(FL_BOLD + FL_ITALIC);

	inStr->labeltype(FL_SHADOW_LABEL);


	inInt->labelfont(FL_BOLD + FL_ITALIC);

	inInt->labeltype(FL_SHADOW_LABEL);

	

	truncBtn->callback(daTruncCloseCallback, (void*)window);
	closeBtn->callback(OnCloseCallback, (void*)window);

	window->end();
	window->show(argc, argv);
	return Fl::run();
}