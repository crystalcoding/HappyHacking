#include "wx/wx.h"

class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title);
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
};

MyFrame::MyFrame(const wxString& title)
  : wxFrame(NULL, wxID_ANY, title)
{
  SetIcon(wxIcon(wxT("bomb.xpm")));
  wxMenu *fileMenu = new wxMenu;
  wxMenu *helpMenu = new wxMenu;

  helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
		   wxT("Show about dialog"));
  fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-x"),
		   wxT("Quit this program"));

  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(fileMenu, wxT("&File"));
  menuBar->Append(helpMenu, wxT("&Help"));

  SetMenuBar(menuBar);
  CreateStatusBar(2);
  SetStatusText(wxT("Welcome to wxWIdgets!"));
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
  wxString msg;
  msg.Printf(wxT("Hello and welcome to %s"),
	     wxVERSION_STRING);
  wxMessageBox(msg, wxT("About Minimal"),
	       wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
  Close();
}

class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

bool MyApp::OnInit()
{
  MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));
  frame->Show(true);

  frame->Connect(wxID_EXIT, 
		 wxEVT_COMMAND_MENU_SELECTED,
		 wxCommandEventHandler(MyFrame::OnQuit));

  frame->Connect(wxID_ABOUT, 
		 wxEVT_COMMAND_MENU_SELECTED,
		 wxCommandEventHandler(MyFrame::OnAbout));
  return true;
}

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)
