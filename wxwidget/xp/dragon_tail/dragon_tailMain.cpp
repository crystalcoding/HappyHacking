/***************************************************************
 * Name:      dragon_tailMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Glenn (glenn.chen01@gmail.com)
 * Created:   2008-11-25
 * Copyright: Glenn ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "dragon_tailMain.h"
#include <iostream>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


BEGIN_EVENT_TABLE(dragon_tailDialog, wxDialog)
    //EVT_CLOSE(dragon_tailDialog::OnClose)
    //EVT_BUTTON(idBtnQuit, dragon_tailDialog::OnQuit)
    //EVT_BUTTON(idBtnAbout, dragon_tailDialog::OnAbout)
END_EVENT_TABLE()

dragon_tailDialog::dragon_tailDialog(wxDialog *dlg, const wxString &title)
    : wxDialog(dlg, -1, title)
{
    //dashBoardRadioButton = new wxRadioButton(this, wxID_ANY, wxT("DashBoard"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
    //storyRadioButton = new wxRadioButton(this, wxID_ANY, wxT("Story"), wxDefaultPosition,wxDefaultSize);

    wxImage::AddHandler( new wxPNGHandler );
    //dashBoardImage(wxT("dashboard.png"), wxBITMAP_TYPE_PNG);
    showPanel = new wxPanel(this, wxID_ANY);



    //sizer = new wxBoxSizer(wxHORIZONTAL);
    //sizer->Add(dashBoardRadioButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    //sizer->Add(storyRadioButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    //sizer->Add(showPanel);

    wxDialog* dialog = new wxDialog(NULL, wxID_ANY, wxT("hello dialog"), wxDefaultPosition, wxSize(500, 900));
    dialog->Show(true);

    wxPaintDC dcc(dialog);
    //DoPrepareDC(dcc);
    dcc.SetPen(*wxBLACK_PEN);
    dcc.DrawLine(0,0,100,100);
    dcc.DrawCircle(100, 150, 60);

        wxClientDC* dc = new wxClientDC(dialog);
    wxPen pen(*wxRED, 10);
    dc->SetPen(pen);
    dc->DrawLine(10, 10, 100, 100);
    dc->SetPen(wxNullPen);
    dc->DrawText(wxT("testtesttesttesttesttesttesttest"), 200, 75);
    if (dc != NULL)
        wxMessageBox(wxT("bos"), wxT("hun?"), wxOK);



    //this->SetSizer(sizer);
    //sizer->Fit(this);

    /*
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxHORIZONTAL);
    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Welcome To\nwxWidgets"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->SetFont(wxFont(20, 74, 90, 90, false, wxT("Arial")));
    bSizer1->Add(m_staticText1, 0, wxALL|wxEXPAND, 5);
    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxVERTICAL);
    BtnAbout = new wxButton(this, idBtnAbout, wxT("&About"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnAbout, 0, wxALL, 5);
    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    bSizer2->Add(m_staticline1, 0, wxALL|wxEXPAND, 5);
    BtnQuit = new wxButton(this, idBtnQuit, wxT("&Quit"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnQuit, 0, wxALL, 5);
    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);
    this->SetSizer(bSizer1);
    this->Layout();
    bSizer1->Fit(this);
    */
}


dragon_tailDialog::~dragon_tailDialog()
{
}

void dragon_tailDialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void dragon_tailDialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void dragon_tailDialog::OnAbout(wxCommandEvent &event)
{
    /*
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
    */
}
