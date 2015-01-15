/***************************************************************
 * Name:      wxwidgetsprojectApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Branimir (brani.espinoza@gmail.com)
 * Created:   2014-03-01
 * Copyright: Branimir (branimire.wordpress.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxwidgetsprojectApp.h"
#include "wxwidgetsprojectMain.h"

IMPLEMENT_APP(wxwidgetsprojectApp);

bool wxwidgetsprojectApp::OnInit()
{
    wxwidgetsprojectFrame* frame = new wxwidgetsprojectFrame(0L);
    
    frame->Show();
    
    return true;
}
