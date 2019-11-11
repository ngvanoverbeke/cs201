// Nathan VanOverbeke
// HW5 (take 2)
// 11/10/19

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#pragma comment(lib, "fltk.lib")
#pragma comment(lib, "comctl32.lib")

void OnCloseCallback(Fl_Widget* w, void* data) {
	Fl_Window* window = (Fl_Window*)data;
	if (window) window->hide();
}

int main(int argc, char** argv) {
	Fl_Window* window = new Fl_Window(340, 240);
	
	Fl_Box* box = new Fl_Box(20, 40, 300, 100, "Hello, World!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);

	const int ControlHeight = 25;

	Fl_Button* closeBtn = new Fl_Button(20, 160, 300, ControlHeight, "Close Window");
	closeBtn->callback(OnCloseCallback, (void*)window);

	window->end();
	window->show(argc, argv);
	return Fl::run();
}