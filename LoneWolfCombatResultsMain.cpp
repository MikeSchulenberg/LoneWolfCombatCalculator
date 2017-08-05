/***************************************************************
 * Name:      LoneWolfCombatResultsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mike Schulenberg ()
 * Created:   2017-07-31
 * Copyright: Mike Schulenberg ()
 * License:
 **************************************************************/

 #include <wx/msgdlg.h>
 #include <string>

#include "wx_pch.h"
#include "LoneWolfCombatResultsMain.h"
#include "include/CombatResults.h"

//(*InternalHeaders(LoneWolfCombatResultsFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(LoneWolfCombatResultsFrame)
const long LoneWolfCombatResultsFrame::ID_STATICTEXT1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_COMBOBOX1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_COMBOBOX2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT3 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT4 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_RADIOBUTTON1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_RADIOBUTTON2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_TEXTCTRL1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_BUTTON1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT7 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT5 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT6 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_PANEL1 = wxNewId();
const long LoneWolfCombatResultsFrame::idMenuQuit = wxNewId();
const long LoneWolfCombatResultsFrame::idMenuAbout = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LoneWolfCombatResultsFrame,wxFrame)
    //(*EventTable(LoneWolfCombatResultsFrame)
    //*)
END_EVENT_TABLE()

LoneWolfCombatResultsFrame::LoneWolfCombatResultsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LoneWolfCombatResultsFrame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Lone Wolf Combat Results"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("COMBAT SKILL"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 5, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Hero"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    heroCSinput = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(50,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    heroCSinput->Append(_("1"));
    heroCSinput->Append(_("2"));
    heroCSinput->Append(_("3"));
    FlexGridSizer1->Add(heroCSinput, 1, wxALL, 5);
    FlexGridSizer1->Add(102,20,1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Enemy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    enemyCSinput = new wxComboBox(Panel1, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(50,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    FlexGridSizer1->Add(enemyCSinput, 1, wxALL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Combat Ratio"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    combatRatioOutput = new wxStaticText(Panel1, ID_STATICTEXT4, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont combatRatioOutputFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    combatRatioOutput->SetFont(combatRatioOutputFont);
    FlexGridSizer1->Add(combatRatioOutput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("RANDOM NUMBER"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Generate a random number"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton1->SetValue(true);
    FlexGridSizer2->Add(RadioButton1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(139,20,1, wxALL|wxEXPAND, 5);
    RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Enter a number from 0 to 9"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    FlexGridSizer2->Add(RadioButton2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(50,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->Disable();
    FlexGridSizer2->Add(TextCtrl1, 0, wxALL, 5);
    StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer2, 0, wxLEFT|wxRIGHT|wxEXPAND, 5);
    okButton = new wxButton(Panel1, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(okButton, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("COMBAT RESULTS"));
    generalOutput = new wxStaticText(Panel1, ID_STATICTEXT7, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT7"));
    StaticBoxSizer3->Add(generalOutput, 1, wxALL|wxEXPAND, 5);
    enemyResult = new wxStaticText(Panel1, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT5"));
    StaticBoxSizer3->Add(enemyResult, 1, wxALL|wxEXPAND, 5);
    heroResult = new wxStaticText(Panel1, ID_STATICTEXT6, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT6"));
    StaticBoxSizer3->Add(heroResult, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer3, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnComboBox1Selected);
    Connect(ID_COMBOBOX2,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnComboBox2Selected);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnRadioButton1Select);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnRadioButton2Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnokButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnAbout);
    //*)

    results = new CombatResults(this);
}

LoneWolfCombatResultsFrame::~LoneWolfCombatResultsFrame()
{
    //(*Destroy(LoneWolfCombatResultsFrame)
    //*)

    delete results;
}

void LoneWolfCombatResultsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LoneWolfCombatResultsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void LoneWolfCombatResultsFrame::OnClose(wxCloseEvent& event)
{
    event.Skip(true);
}

void LoneWolfCombatResultsFrame::OnRadioButton1Select(wxCommandEvent& event)
{
    TextCtrl1->Enable(false);
}

void LoneWolfCombatResultsFrame::OnRadioButton2Select(wxCommandEvent& event)
{
    TextCtrl1->Enable(true);
}

void LoneWolfCombatResultsFrame::OnComboBox1Selected(wxCommandEvent& event)
{
    wxString combatSkillStr = heroCSinput->GetValue();
    int heroCombatSkill = atoi(combatSkillStr.c_str());
    results->setHeroCombatSkill(heroCombatSkill);

    // debug
    generalOutput->SetLabel(_("ComboBox1 Selected"));
    Layout();
}

void LoneWolfCombatResultsFrame::OnComboBox2Selected(wxCommandEvent& event)
{
    wxString combatSkillStr = enemyCSinput->GetValue();
    int enemyCombatSkill = atoi(combatSkillStr.c_str());
    results->setEnemyCombatSkill(enemyCombatSkill);

    // debug
    generalOutput->SetLabel(_("ComboBox2 Selected"));
    Layout();
}

void LoneWolfCombatResultsFrame::OnokButtonClick(wxCommandEvent& event)
{
    results->outputCombatResults();
}

void LoneWolfCombatResultsFrame::printCombatRatio(string msg)
{
    combatRatioOutput->SetLabel(_(msg));
}

void LoneWolfCombatResultsFrame::printGeneralOutput(string msg)
{
    generalOutput->SetLabel(_(msg));
    Layout();
}
