/***************************************************************
 * Name:      LoneWolfCombatResultsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mike Schulenberg ()
 * Created:   2017-07-31
 * Copyright: Mike Schulenberg ()
 * License:
 **************************************************************/

#ifndef LONEWOLFCOMBATRESULTSMAIN_H
#define LONEWOLFCOMBATRESULTSMAIN_H

//(*Headers(LoneWolfCombatResultsFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)

class LoneWolfCombatResultsFrame: public wxFrame
{
    public:

        LoneWolfCombatResultsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~LoneWolfCombatResultsFrame();

    private:

        //(*Handlers(LoneWolfCombatResultsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        void OnClose(wxCloseEvent& event);

        //(*Identifiers(LoneWolfCombatResultsFrame)
        static const long ID_STATICTEXT1;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT2;
        static const long ID_COMBOBOX2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(LoneWolfCombatResultsFrame)
        wxRadioButton* RadioButton1;
        wxStaticText* StaticText2;
        wxRadioButton* RadioButton2;
        wxButton* Button1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxStaticText* enemyResult;
        wxStaticText* heroResult;
        wxStatusBar* StatusBar1;
        wxComboBox* ComboBox1;
        wxTextCtrl* TextCtrl1;
        wxComboBox* ComboBox2;
        wxStaticText* StaticText4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LONEWOLFCOMBATRESULTSMAIN_H
