/***************************************************************
 * Name:      dragon_tailApp.cpp
 * Purpose:   Code for Application Class
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

#include "dragon_tailApp.h"
#include "dragon_tailMain.h"

IMPLEMENT_APP(dragon_tailApp);

bool dragon_tailApp::OnInit()
{

    dragon_tailDialog* dlg = new dragon_tailDialog(0L, _("TSv3.0 Report Updater"));
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
