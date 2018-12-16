#pragma once
#include <wx\wx.h>
#include "GameObject.h"

class Frame;
class PlayerFish;

class Window : public wxWindow
{
public:
	Window(Frame *parent);
	~Window();

	void OnPaint(wxPaintEvent &event);
	void OnKeyDown(wxKeyEvent &event);
	void OnTimer(wxTimerEvent &event);

private:
	wxTimer *timer;
	PlayerFish *player_fish;
	PlayerFish *small_fish;
	wxString score;

	DECLARE_EVENT_TABLE()
};

