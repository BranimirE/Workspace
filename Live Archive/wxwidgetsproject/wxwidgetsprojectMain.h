/***************************************************************
 * Name:      wxwidgetsprojectMain.h
 * Purpose:   Defines Application Frame
 * Author:    Branimir (brani.espinoza@gmail.com)
 * Created:   2014-03-01
 * Copyright: Branimir (branimire.wordpress.com)
 * License:
 **************************************************************/

#ifndef WXWIDGETSPROJECTMAIN_H
#define WXWIDGETSPROJECTMAIN_H



#include "wxwidgetsprojectApp.h"


#include "GUIFrame.h"

class wxwidgetsprojectFrame: public GUIFrame
{
    public:
        wxwidgetsprojectFrame(wxFrame *frame);
        ~wxwidgetsprojectFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // WXWIDGETSPROJECTMAIN_H
