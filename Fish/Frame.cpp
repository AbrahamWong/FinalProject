#include "Frame.h"
#include "Window.h"


Frame::Frame(const wxString &title) : wxFrame(NULL, wxID_ANY, title)
{
	this->menu = new Window(this);

	this->SetInitialSize(wxSize(1280, 720));
}


Frame::~Frame()
{
}
