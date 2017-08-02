/***************************************************************
 * Name:      LoneWolfCombatResultsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mike Schulenberg ()
 * Created:   2017-07-31
 * Copyright: Mike Schulenberg ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "LoneWolfCombatResultsMain.h"
#include <wx/msgdlg.h>

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
const long LoneWolfCombatResultsFrame::ID_BUTTON2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_PANEL4 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_PANEL2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT5 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_TEXTCTRL1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_BUTTON1 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_PANEL5 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_PANEL3 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_NOTEBOOK1 = wxNewId();
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
    wxBoxSizer* BoxSizer4;
    wxMenuItem* MenuItem2;
    wxGridBagSizer* GridBagSizer1;
    wxGridBagSizer* GridBagSizer2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(500,54));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Hero COMBAT SKILL"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox1 = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(50,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    GridBagSizer1->Add(ComboBox1, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(120,20,1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Enemy COMBAT SKILL"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridBagSizer1->Add(StaticText2, wxGBPosition(0, 4), wxDefaultSpan, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox2 = new wxComboBox(Panel1, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(50,21), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    GridBagSizer1->Add(ComboBox2, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Combat Ratio"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    GridBagSizer1->Add(StaticText3, wxGBPosition(1, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    GridBagSizer1->Add(StaticText4, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxSize(181,151), 0, _T("ID_NOTEBOOK1"));
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Panel4 = new wxPanel(Panel2, ID_PANEL4, wxDefaultPosition, wxSize(185,131), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4->Add(20,31,0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel4, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(BoxSizer4);
    SetSizer(BoxSizer4);
    Layout();
    BoxSizer2->Add(Panel4, 1, wxALL|wxEXPAND, 0);
    Panel2->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel2);
    BoxSizer2->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Panel5 = new wxPanel(Panel3, ID_PANEL5, wxDefaultPosition, wxSize(170,160), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    GridBagSizer2 = new wxGridBagSizer(0, 6);
    StaticText5 = new wxStaticText(Panel5, ID_STATICTEXT5, _("Die Roll"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridBagSizer2->Add(StaticText5, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(Panel5, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(62,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridBagSizer2->Add(TextCtrl1, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel5, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    GridBagSizer2->Add(Button1, wxGBPosition(1, 0), wxGBSpan(1, 5), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel5->SetSizer(GridBagSizer2);
    SetSizer(GridBagSizer2);
    Layout();
    BoxSizer3->Add(Panel5, 1, wxALL|wxEXPAND, 0);
    Panel3->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel3);
    BoxSizer3->SetSizeHints(Panel3);
    Notebook1->AddPage(Panel2, _("Die Roller"), false);
    Notebook1->AddPage(Panel3, _("Manual Entry"), false);
    GridBagSizer1->Add(Notebook1, wxGBPosition(3, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(GridBagSizer1);
    GridBagSizer1->Fit(Panel1);
    GridBagSizer1->SetSizeHints(Panel1);
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
    SetSizer(BoxSizer1);
    Layout();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnAbout);
    //*)
}

LoneWolfCombatResultsFrame::~LoneWolfCombatResultsFrame()
{
    //(*Destroy(LoneWolfCombatResultsFrame)
    //*)
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
