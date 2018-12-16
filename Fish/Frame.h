#pragma once
#include "wx/wx.h"

class Window;

class Frame : public wxFrame
{
public:
	Frame(const wxString &title);
	~Frame();

private:
	Window *menu;
};

