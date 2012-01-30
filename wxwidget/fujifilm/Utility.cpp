#include "wx/wx.h"
#include "wx/clipbrd.h"
#include "wx/dataobj.h"
#include "wx/image.h"
#include "wx/bitmap.h"
#include "wx/wfstream.h"

#include "Utility.h"
#include <iostream>

using namespace std;

Utility::Utility() {}

bool Utility::paste_from_clipboard()
{
    if(wxTheClipboard->Open())
    {
         wxMessageBox(wxT("open a clipboard"));

        /*
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);
            wxMessageBox(data.GetText());

            //copy an image using it's path and name, save to the current folder
            wxFileInputStream stream(wxT(data.GetText().Mid(7)));
            wxImage image;
            image.LoadFile(stream, wxBITMAP_TYPE_JPEG);
            image.SaveFile(wxT("my_paste_image.png"), wxBITMAP_TYPE_PNG);

        }
        */

        if (wxTheClipboard->IsSupported(wxDF_BITMAP))
        {
            wxBitmapDataObject data;
            if(wxTheClipboard->GetData(data))
            {
                wxMessageBox(wxT("get data is true"));
            }
            else{
                wxMessageBox(wxT("get data is false"));
            }
            wxMessageBox(wxT("paste a bitmap"));


            wxTheClipboard->GetData(data);
            wxBitmap bitmap(data.GetBitmap());
            //bitmap.ConvertToImage();
            bitmap.SaveFile(wxT("mycopypasteimage.bmp"), wxBITMAP_TYPE_BMP);


            cout << "support bitmap copy";
        }

        wxTheClipboard->Close();
    }
}
