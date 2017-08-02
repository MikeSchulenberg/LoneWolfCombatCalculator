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
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>
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
        static const long ID_BUTTON2;
        static const long ID_PANEL4;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_PANEL5;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(LoneWolfCombatResultsFrame)
        wxPanel* Panel5;
        wxNotebook* Notebook1;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxButton* Button1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxPanel* Panel3;
        wxStaticText* StaticText5;
        wxStatusBar* StatusBar1;
        wxComboBox* ComboBox1;
        wxTextCtrl* TextCtrl1;
        wxPanel* Panel2;
        wxComboBox* ComboBox2;
        wxStaticText* StaticText4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // LONEWOLFCOMBATRESULTSMAIN_H
