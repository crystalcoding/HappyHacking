#include <wx/wx.h>
#include "mywxApp.h"
#include "mywxMain.h"
#include "Utility.h"

IMPLEMENT_APP(mywxApp)  //what is this? getting main not found if omitting this line

bool mywxApp::OnInit()
{
    wxImage::AddHandler(new wxJPEGHandler);
    wxImage::AddHandler(new wxPNGHandler);
    mywxMain *mywxmain = new mywxMain(wxT(""));
    mywxmain->Show(true);

    Utility my_utility; //not Utility my_utility();
    my_utility.paste_from_clipboard();

    return true;
}
