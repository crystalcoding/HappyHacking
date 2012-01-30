#include "mywxMain.h"
//#include "fuji.xpm"
#include "wx/image.h"
#include <wx/splash.h>

mywxMain::mywxMain(const wxString& title):
 wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(549, 220),
         (wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxRESIZE_BOX | wxMAXIMIZE_BOX)))
 {

     Centre();

     wxBitmap bitmap;
     if (bitmap.LoadFile(wxT("fujiesys.png"), wxBITMAP_TYPE_PNG))
     {
        wxSplashScreen* splash = new wxSplashScreen(bitmap,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        1000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxSIMPLE_BORDER|wxSTAY_ON_TOP);
     }
     wxYield();

     //SetIcon(wxIcon(fuji_xpm));
     //wxImage image(wxT("horse.jpg"), wxBITMAP_TYPE_JPEG);
     wxBitmap bmp(wxT("fujiesys.png"), wxBITMAP_TYPE_PNG);
     wxStaticBitmap *sb = new wxStaticBitmap(this, -1, bmp);
     //wxClientDC* clientDC = NULL;


     //dc.DrawBitmap(bmp, 250, 150, true);


     CreateStatusBar(2);
     SetStatusText(wxT("Fujifilm E-systems"));
 }
