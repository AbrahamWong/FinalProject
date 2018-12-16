#pragma once
#include "wx/wx.h"
#include "wx/dcbuffer.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void loadBitmap(wxString path, int n);
	void Draw(wxAutoBufferedPaintDC &pdc, int n);

	void SetPosX(int t);
	void SetPosY(int t);
	void SetWidth(int t);
	void SetHeight(int t);

	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();

	void SetXDir(int t);
	void SetYDir(int t);

	int GetXDir();
	int GetYDir();

private:
	int posX;
	int posY;
	int width;
	int height;

	int xDirection = 1;
	int yDirection = 1;

	wxBitmap *bitmap1;
	wxBitmap *bitmap2;

};

