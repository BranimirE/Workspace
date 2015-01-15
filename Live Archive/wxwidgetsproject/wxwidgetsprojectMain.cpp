/***************************************************************
 * Name:      wxwidgetsprojectMain.cpp
 * Purpose:   Code for Application Frame
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

#include "wxwidgetsprojectMain.h"

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


wxwidgetsprojectFrame::wxwidgetsprojectFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

wxwidgetsprojectFrame::~wxwidgetsprojectFrame()
{
}

void wxwidgetsprojectFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxwidgetsprojectFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wxwidgetsprojectFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
