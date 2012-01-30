/***************************************************************
 * Name:      dragon_frameMain.h
 * Purpose:   Defines Application Frame
 * Author:    Glenn (glenn.chen01@gmail.com)
 * Created:   2008-11-26
 * Copyright: Glenn ()
 * License:
 **************************************************************/

#ifndef DRAGON_FRAMEMAIN_H
#define DRAGON_FRAMEMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "dragon_frameApp.h"

class dragon_frameFrame: public wxFrame
{
    public:
        dragon_frameFrame(wxFrame *frame, const wxString& title);
        ~dragon_frameFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // DRAGON_FRAMEMAIN_H
