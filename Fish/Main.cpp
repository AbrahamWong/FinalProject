#include "wx\wx.h"
#include "Frame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	Frame *frame = new Frame("Fish");
	frame->Show(true);
	return true;
}