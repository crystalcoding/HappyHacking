/***************************************************************
 * Name:      dragon_tailMain.h
 * Purpose:   Defines Application Frame
 * Author:    Glenn (glenn.chen01@gmail.com)
 * Created:   2008-11-25
 * Copyright: Glenn ()
 * License:
 **************************************************************/

#ifndef DRAGON_TAILMAIN_H
#define DRAGON_TAILMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "dragon_tailApp.h"

#include <wx/image.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/statline.h>
class dragon_tailDialog: public wxDialog
{
    public:
        dragon_tailDialog(wxDialog *dlg, const wxString& title);
        ~dragon_tailDialog();

    protected:
        wxRadioButton* dashBoardRadioButton;
        wxRadioButton* storyRadioButton;

        wxBoxSizer* sizer;

        wxImage dashBoardImage;
        wxPanel* showPanel;
        /*
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;
        */

     private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // DRAGON_TAILMAIN_H
