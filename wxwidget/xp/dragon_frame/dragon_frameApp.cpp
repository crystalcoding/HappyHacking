/***************************************************************
 * Name:      dragon_frameApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Glenn (glenn.chen01@gmail.com)
 * Created:   2008-11-26
 * Copyright: Glenn ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "dragon_frameApp.h"
#include "dragon_frameMain.h"

IMPLEMENT_APP(dragon_frameApp);

bool dragon_frameApp::OnInit()
{
    dragon_frameFrame* frame = new dragon_frameFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
