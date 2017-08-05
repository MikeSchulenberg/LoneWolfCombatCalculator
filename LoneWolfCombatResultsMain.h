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

#include "include/ForwardDeclarations.h"

using std::string;

class LoneWolfCombatResultsFrame: public wxFrame
{
    public:

        LoneWolfCombatResultsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~LoneWolfCombatResultsFrame();

        void printCombatRatio(string msg);
        void printGeneralOutput(string msg);

    private:

        //(*Handlers(LoneWolfCombatResultsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRadioButton1Select(wxCommandEvent& event);
        void OnRadioButton2Select(wxCommandEvent& event);
        void OnComboBox1Selected(wxCommandEvent& event);
        void OnComboBox2Selected(wxCommandEvent& event);
        void OnokButtonClick(wxCommandEvent& event);
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
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(LoneWolfCombatResultsFrame)
        wxStaticText* combatRatioOutput;
        wxRadioButton* RadioButton1;
        wxComboBox* enemyCSinput;
        wxStaticText* StaticText2;
        wxRadioButton* RadioButton2;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxStaticText* enemyResult;
        wxComboBox* heroCSinput;
        wxStaticText* heroResult;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxButton* okButton;
        wxStaticText* generalOutput;
        //*)

        DECLARE_EVENT_TABLE()

        CombatResults* results;
};

#endif // LONEWOLFCOMBATRESULTSMAIN_H
