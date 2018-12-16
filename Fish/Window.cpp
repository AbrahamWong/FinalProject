#include "Window.h"
#include "Frame.h"
#include "wx/dcbuffer.h"
#include "PlayerFish.h"
#define TIMER_ID 2000 

BEGIN_EVENT_TABLE(Window, wxWindow)
	EVT_PAINT(Window::OnPaint)
	EVT_KEY_DOWN(Window::OnKeyDown)
	EVT_TIMER(TIMER_ID, Window::OnTimer)
END_EVENT_TABLE()

Window::Window(Frame *parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->SetBackgroundColour(wxColour(*wxWHITE));

	timer = new wxTimer(this, TIMER_ID);
	timer->Start(50);


	srand((unsigned)time(NULL));

	this->player_fish = new PlayerFish();
	this->player_fish->SetPosX(rand() % 1000);
	this->player_fish->SetPosY(rand() % 600);
	this->player_fish->SetWidth(100);
	this->player_fish->SetHeight(50);
	this->player_fish->loadBitmap(wxT("\\PlayerFishMain.png"), 0);
	this->player_fish->loadBitmap(wxT("\\PlayerFishMain2.png"), 1);

	player_fish->SetScore();
	score = "";
	score << player_fish->GetScore();
	this->small_fish = new PlayerFish();
	this->small_fish->SetPosX(rand() % 1000);
	this->small_fish->SetPosY(rand() % 600);
	this->small_fish->SetWidth(50);
	this->small_fish->SetHeight(25);
	this->small_fish->loadBitmap(wxT("\\SmallFish.png"), 0);
	this->small_fish->loadBitmap(wxT("\\SmallFish2.png"), 1);
}


Window::~Window()
{
}

void Window::OnPaint(wxPaintEvent &event)
{
	wxAutoBufferedPaintDC pdc(this);

	pdc.SetBrush(wxBrush(wxColour(*wxWHITE)));
	pdc.SetPen(wxPen(wxColor(*wxWHITE), 1, wxPENSTYLE_SOLID));
	pdc.DrawRectangle(wxPoint(0, 0), wxSize(GetClientSize() ));
	if (this->player_fish->GetXDir() == 0) {
		this->player_fish->Draw(pdc, 1);
	}
	else {
		this->player_fish->Draw(pdc, 0);
	}
	
	if (this->small_fish->GetXDir() == 0) {
		this->small_fish->Draw(pdc, 1);
	}
	else {
		this->small_fish->Draw(pdc, 0);
	}

	pdc.DrawText(score, wxPoint(10, 10));
	Refresh();
}

void Window::OnKeyDown(wxKeyEvent &event) {
	int keycode = event.GetKeyCode();

	switch (keycode) {
	case WXK_LEFT:
		player_fish->Move(-5, 0, GetClientSize().GetWidth(), GetClientSize().GetHeight());
		player_fish->SetXDir(0);
		Refresh();
		break;
	case WXK_RIGHT:
		player_fish->Move(5, 0, GetClientSize().GetWidth(), GetClientSize().GetHeight());
		player_fish->SetXDir(1);
		Refresh();
		break;
	case WXK_DOWN:
		player_fish->Move(0, 5, GetClientSize().GetWidth(), GetClientSize().GetHeight());
		Refresh();
		break;
	case WXK_UP:
		player_fish->Move(0, -5, GetClientSize().GetWidth(), GetClientSize().GetHeight());
		Refresh();
		break;
	default:
		event.Skip();
	}

	if (this->player_fish->Intersect(small_fish)) {
		delete small_fish;
		player_fish->IncScore();
		score = "";
		score << player_fish->GetScore();
		this->small_fish = new PlayerFish();
		this->small_fish->SetPosX(rand() % 1000);
		this->small_fish->SetPosY(rand() % 600);
		this->small_fish->SetWidth(50);
		this->small_fish->SetHeight(25);
		this->small_fish->loadBitmap(wxT("\\SmallFish.png"), 0);
		this->small_fish->loadBitmap(wxT("\\SmallFish2.png"), 1);
	}
}

void Window::OnTimer(wxTimerEvent &event)
{
	static int counter = 0;
	this->small_fish->Move(0, 5, GetClientSize().GetWidth(), GetClientSize().GetHeight());
	Update();
	Refresh();
	counter++;

	wxMessageOutputDebug().Printf("wxTimer %d.", counter);
}