#include "GameObject.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

GameObject::GameObject()
{
	this->xDirection = 0;
}

GameObject::~GameObject()
{
}

void GameObject::loadBitmap(wxString path, int n)
{
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + path;
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	if (n == 0) {
		this->bitmap1 = new wxBitmap(image.Scale(this->width, this->height));
	}
	else {
		this->bitmap2 = new wxBitmap(image.Scale(this->width, this->height));
	}
	
	wxMessageOutputDebug().Printf("yok");
}


void GameObject::Draw(wxAutoBufferedPaintDC &pdc, int n)
{
	if (n == 0) {
		if (bitmap1 != nullptr)
		{
			pdc.DrawBitmap(*bitmap1, wxPoint(this->posX, this->posY), true);
		}
		else {
			pdc.SetPen(*wxBLACK_PEN);
			pdc.SetBrush(*wxBLUE_BRUSH);
			pdc.DrawCircle(wxPoint(this->posX, this->posY), this->width);
		}
	}
	else {
		if (bitmap2 != nullptr)
		{
			pdc.DrawBitmap(*bitmap2, wxPoint(this->posX, this->posY), true);
		}
		else {
			pdc.SetPen(*wxBLACK_PEN);
			pdc.SetBrush(*wxBLUE_BRUSH);
			pdc.DrawCircle(wxPoint(this->posX, this->posY), this->width);
		}
	}
}

void GameObject::SetPosX(int t) {
	this->posX = t;
}

void GameObject::SetPosY(int t) {
	this->posY = t;
}

void GameObject::SetWidth(int t) {
	this->width = t;
}

void GameObject::SetHeight(int t) {
	this->height = t;
}

int GameObject::GetPosX() {
	return this->posX;
}

int GameObject::GetPosY() {
	return this->posY;
}

int GameObject::GetWidth() {
	return this->width;
}

int GameObject::GetHeight() {
	return this->height;
}

void GameObject::SetXDir(int n) {
	this->xDirection = n;
}

void GameObject::SetYDir(int n) {
	this->yDirection = n;
}

int GameObject::GetXDir() {
	return this->xDirection;
}

int GameObject::GetYDir() {
	return this->yDirection;
}