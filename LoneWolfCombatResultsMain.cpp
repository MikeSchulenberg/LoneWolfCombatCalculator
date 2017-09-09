/**
 * \file LoneWolfCombatResultsMain.cpp
 * \author Mike Schulenberg <mike.schulenberg@gmail.com>
 * \version 1.0
 *
 * \par Description
 * This class implements a GUI for a program that calculates
 * combat results for the 'Lone Wolf' adventure gamebooks
 * by Joe Dever.
 *
 */

#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
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
const long LoneWolfCombatResultsFrame::ID_TEXTCTRL2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_STATICTEXT2 = wxNewId();
const long LoneWolfCombatResultsFrame::ID_TEXTCTRL3 = wxNewId();
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

    Create(parent, wxID_ANY, _("Lone Wolf Combat Calculator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("COMBAT SKILL"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 5, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Hero"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    heroCSinput = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(30,21), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    heroCSinput->SetToolTip(_("COMBAT SKILL must be a whole number greater than 0"));
    FlexGridSizer1->Add(heroCSinput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(98,21,1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Enemy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    enemyCSinput = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(30,21), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    enemyCSinput->SetToolTip(_("COMBAT SKILL must be a whole number greater than 0"));
    FlexGridSizer1->Add(enemyCSinput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    combatRatioOutput = new wxStaticText(Panel1, ID_STATICTEXT4, _("--"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont combatRatioOutputFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    combatRatioOutput->SetFont(combatRatioOutputFont);
    FlexGridSizer1->Add(combatRatioOutput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("DIE ROLL"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Generate a random number"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton1->SetValue(true);
    RadioButton1->Disable();
    FlexGridSizer2->Add(RadioButton1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(108,20,1, wxALL|wxEXPAND, 5);
    RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Enter a number from 0 to 9"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    RadioButton2->Disable();
    FlexGridSizer2->Add(RadioButton2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    dieRollInput = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(30,21), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    dieRollInput->Disable();
    FlexGridSizer2->Add(dieRollInput, 0, wxALL, 5);
    StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer2, 0, wxLEFT|wxRIGHT|wxEXPAND, 5);
    okButton = new wxButton(Panel1, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    okButton->Disable();
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
    int __wxStatusBarWidths_1[2] = { -5, -5 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnheroCSinputText);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnheroCSinputTextEnter);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnenemyCSinputText);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnenemyCSinputTextEnter);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnRadioButton1Select);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnRadioButton2Select);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnrandomNumberInputText);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnrandomNumberInputTextEnter);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnokButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&LoneWolfCombatResultsFrame::OnAbout);
    //*)

    // Create a 'Lone Wolf' Combat Calculator object
    results = new CombatResults(this);
}

LoneWolfCombatResultsFrame::~LoneWolfCombatResultsFrame()
{
    //(*Destroy(LoneWolfCombatResultsFrame)
    //*)

    delete results;
}

/////////////////////////////////////////////////////////////
// EVENT HANDLERS
/////////////////////////////////////////////////////////////

void LoneWolfCombatResultsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void LoneWolfCombatResultsFrame::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo info;
    info.SetName(_("Lone Wolf Combat Calculator"));
    info.SetVersion(_("1.0"));
    info.SetDescription(_("This program calculates combat results for the 'Lone Wolf' adventure gamebooks by Joe Dever."));

    wxAboutBox(info);
}

void LoneWolfCombatResultsFrame::OnClose(wxCloseEvent& event)
{
    event.Skip(true);
}

// Combat Skill
//-----------------------------------------------------------

/** \brief Prepares the program for a Hero "Combat Skill" that is about to change.
 * Clears all output from the GUI except for Enemy "Combat Skill", disables the ability to
 * select a method for determining the "die roll," and disables the OK button.
 *
 * \param event An event triggered when the user inputs text in the
 * wxTextCtrl for changing the Hero "Combat Skill".
 *
 */
void LoneWolfCombatResultsFrame::OnheroCSinputText(wxCommandEvent& event)
{
    clearCurrentHeroCS();
    clearCombatRatio();
    clearAllOutput();

    /* Because the user is entering a "Combat Skill" value that has not yet been
    verified, disable the functionality that selects whether the "die roll" will
    be randomly generated or manually entered. */
    toggleRandomNumberSection(false);
    okButton->Enable(false);
}

/** \brief Changes the Hero "Combat Skill" to a value set by the user.
 * If the Enemy "Combat Skill" wxTextCtrl contains text, this function
 * processes it as well in case the user input a value without entering it.
 *
 * \param even An event triggered when the user enters text in the
 * wxTextCtrl for changing the Hero "Combat Skill".
 *
 */
void LoneWolfCombatResultsFrame::OnheroCSinputTextEnter(wxCommandEvent& event)
{
    processHeroCSinput();

    // Does the wxTextCtrl for changing the Enemy "Combat Skill" contain text?
    wxString enemyCSstr = enemyCSinput->GetValue();
    if (!enemyCSstr.IsEmpty())
    {
        processEnemyCSinput();
    }
}

/** \brief Prepares the program for an Enemy "Combat Skill" that is about to change.
 * Clears all output from the GUI except for Hero "Combat Skill", disables the ability to
 * select a method for determining the "die roll," and disables the OK button.
 *
 * \param event An event triggered when the user inputs text in the
 * wxTextCtrl for changing the Enemy "Combat Skill".
 *
 */
void LoneWolfCombatResultsFrame::OnenemyCSinputText(wxCommandEvent& event)
{
    clearCurrentEnemyCS();
    clearCombatRatio();
    clearAllOutput();

    /* Because the user is entering a "Combat Skill" value that has not yet been
    verified, disable the functionality that selects whether the "die roll" will
    be randomly generated or manually entered. */
    toggleRandomNumberSection(false);
    okButton->Enable(false);
}

/** \brief Changes the Enemy "Combat Skill" to a value set by the user.
 * If the Hero "Combat Skill" wxTextCtrl contains text, this function
 * processes it as well in case the user input a value without entering it.
 *
 * \param even An event triggered when the user enters text in the
 * wxTextCtrl for changing the Enemy "Combat Skill".
 *
 */
void LoneWolfCombatResultsFrame::OnenemyCSinputTextEnter(wxCommandEvent& event)
{
    processEnemyCSinput();

    // Does the wxTextCtrl for changing the Hero "Combat Skill" contain text?
    wxString heroCSstr = heroCSinput->GetValue();
    if (!heroCSstr.IsEmpty())
    {
        processHeroCSinput();
    }
}

// Die Roll
//-----------------------------------------------------------

/** \brief Indicates that the user has selected the option to randomly generate
 * a result for the combat die roll, rather then enter one manually.
 *
 * \param event An event triggered when the user selects the "random method"
 * of generating a value for the die roll.
 *
 */
void LoneWolfCombatResultsFrame::OnRadioButton1Select(wxCommandEvent& event)
{
    clearAllOutput();
    dieRollInput->Enable(false);
}

/** \brief Indicates that the user has selected the option to manually enter
 * die roll, rather than have the program generate one randomly.
 *
 * \param event An event triggered when the user selects the option to manually
 * enter a value for the die roll.
 *
 */
void LoneWolfCombatResultsFrame::OnRadioButton2Select(wxCommandEvent& event)
{
    clearAllOutput();
    dieRollInput->Enable(true);
}

/** \brief Prepares the program for a change in the current die roll value
 * by clearing all current output from the GUI.
 *
 * \param event An event triggered when the user inputs text in the
 * wxTextCtrl for manually entering a die roll.
 *
 */
void LoneWolfCombatResultsFrame::OnrandomNumberInputText(wxCommandEvent& event)
{
    clearAllOutput();
}

/** \brief Calculates the results of a combat exchange when the user
 * enters a manual die roll, allowing the user to do so without having
 * to take the additional action of a button click.
 *
 * \param event An event triggered when the user enters text in the
 * wxTextCtrl for manually entering a die roll.
 *
 */
void LoneWolfCombatResultsFrame::OnrandomNumberInputTextEnter(wxCommandEvent& event)
{
    calculateCombatResults();
}

//-----------------------------------------------------------

/** \brief Calculates the results of a combat exchange.
 *
 * \param event An event triggered when the user clicks the "OK" button.
 *
 */
void LoneWolfCombatResultsFrame::OnokButtonClick(wxCommandEvent& event)
{
    calculateCombatResults();
}

/////////////////////////////////////////////////////////////
// PRINT OUTPUT
/////////////////////////////////////////////////////////////

/** \brief Prints the Hero's current "Combat Skill" to the GUI.
 *
 * \param msg A string representing a "Combat Skill" value.
 *
 */
void LoneWolfCombatResultsFrame::printCurrentHeroCS(string msg) const
{
    StatusBar1->SetStatusText("Hero COMBAT SKILL: " + msg, 0);
}

/** \brief Prints the Enemy's current "Combat Skill" to the GUI.
 *
 * \param msg A string representing a "Combat Skill" value.
 *
 */
void LoneWolfCombatResultsFrame::printCurrentEnemyCS(string msg) const
{
    StatusBar1->SetStatusText("Enemy COMBAT SKILL: " + msg, 1);
}

/** \brief Prints the current "Combat Ratio" to the GUI.
 *
 * \param msg A string representing a "Combat Ratio" value.
 *
 */
void LoneWolfCombatResultsFrame::printCombatRatio(string msg)
{
    combatRatioOutput->SetLabel(_(msg));
    Layout();
}

/** \brief Prints general messages to the GUI.
 *
 * \param msg A string containing the text to be printed.
 *
 */
void LoneWolfCombatResultsFrame::printGeneralOutput(string msg)
{
    // Print on the first line of the "COMBAT RESULTS" panel
    generalOutput->SetLabel(_(msg));
    Layout();
}

/** \brief Prints to the GUI the number of "ENDURANCE" points
 * lost by the Enemy in a combat exchange.
 *
 * Optionally, this function may be used to display general messages
 * in cases where more than one line is required.
 *
 * \param msg A string describing the Enemy's "ENDURANCE" loss.
 *
 */
void LoneWolfCombatResultsFrame::printDamageToEnemy(string msg)
{
    // Print on the second line of the "COMBAT RESULTS" panel
    enemyResult->SetLabel(_(msg));
    Layout();
}

/** \brief Prints to the GUI the number of "ENDURANCE" points
 * lost by the Hero in a combat exchange.
 *
 * Optionally, this function may be used to display general messages
 * in cases where more than one line is required.
 *
 * \param msg A string describing the Hero's "ENDURANCE" loss.
 *
 */
void LoneWolfCombatResultsFrame::printDamageToHero(string msg)
{
    // Print on the third line of the "COMBAT RESULTS" panel
    heroResult->SetLabel(_(msg));
    Layout();
}

/** \brief Prints an error message to the GUI indicating that the
 * user has entered an invalid value for the Hero "COMBAT SKILL".
 *
 */
void LoneWolfCombatResultsFrame::printHeroCSError()
{
    prepCSErrorMessage();
    generalOutput->SetLabel(_("Error: invalid Hero COMBAT SKILL"));
    Layout();
}

/** \brief Prints an error message to the GUI indicating that the
 * user has entered an invalid value for the Enemy "COMBAT SKILL".
 *
 */
void LoneWolfCombatResultsFrame::printEnemyCSError()
{
    prepCSErrorMessage();
    generalOutput->SetLabel(_("Error: invalid Enemy COMBAT SKILL"));
    Layout();
}

/** \brief Prints an error message to the GUI indicating that the
 * user has used an invalid value when entering a manual die roll.
 *
 */
void LoneWolfCombatResultsFrame::printDieRollError()
{
    generalOutput->SetLabel(_("Error: DIE ROLL must be a whole number from 0 to 9"));
    Layout();
}

/** \brief Clears the GUI of all output except for "Combat Ratio".
 *
 */
void LoneWolfCombatResultsFrame::clearAllOutput()
{
    generalOutput->SetLabel(_(""));
    enemyResult->SetLabel(_(""));
    heroResult->SetLabel(_(""));
    Layout();
}

/////////////////////////////////////////////////////////////
// GENERAL FUNCTIONS
/////////////////////////////////////////////////////////////

/** \brief Enables and disables the "DIE ROLL" panel, which lets the user select which
 * method they want to use to calculate the combat result.
 *
 * \param enable True if the panel should be enabled; false if it should be disabled.
 *
 */
void LoneWolfCombatResultsFrame::toggleRandomNumberSection(bool enable) const
{
    if (enable)
    {
        RadioButton1->Enable(true);
        RadioButton2->Enable(true);
        okButton->Enable(true);

        /* If the option to manually enter a "die roll" has been selected,
        enable the wxTextCtrl that allows the user to enter a value. */
        if (RadioButton2->GetValue())
        {
            dieRollInput->Enable(true);
        }
    }

    else
    {
        RadioButton1->Enable(false);
        RadioButton2->Enable(false);
        dieRollInput->Enable(false);
    }
}

/////////////////////////////////////////////////////////////
// HELPER FUNCTIONS
/////////////////////////////////////////////////////////////

/** \brief Processes the value being input for the Hero's "Combat Skill".
 * Forwards the result to the "Combat Results" object.
 *
 */
void LoneWolfCombatResultsFrame::processHeroCSinput()
{
    wxString combatSkillStr = heroCSinput->GetValue();
    long heroCombatSkill;

    if (!combatSkillStr.ToLong(&heroCombatSkill))
    {
        printHeroCSError();
        results->invalidateHeroCombatSkill();
    }

    else
    {
        results->setHeroCombatSkill(heroCombatSkill);
    }
}

/** \brief Clears the current Hero "Combat Skill" from the GUI.
 *
 */
void LoneWolfCombatResultsFrame::clearCurrentHeroCS() const
{
    StatusBar1->SetStatusText("", 0);
}

/** \brief Processes the value being input for the enemy's "Combat Skill".
 * Forwards the result to the "Combat Results" object.
 *
 */
void LoneWolfCombatResultsFrame::processEnemyCSinput()
{
    wxString combatSkillStr = enemyCSinput->GetValue();
    long enemyCombatSkill;

    if (!combatSkillStr.ToLong(&enemyCombatSkill))
    {
        printEnemyCSError();
        results->invalidateEnemyCombatSkill();
    }

    else
    {
        results->setEnemyCombatSkill(enemyCombatSkill);
    }
}

/** \brief Clears the current Enemy "Combat Skill" from the GUI.
 *
 */
void LoneWolfCombatResultsFrame::clearCurrentEnemyCS() const
{
    StatusBar1->SetStatusText("", 1);
}

/** \brief Prepares the GUI to display an error message regarding bad
 * "Combat Skill" input.
 *
 */
void LoneWolfCombatResultsFrame::prepCSErrorMessage()
{
    clearCombatRatio();
    clearAllOutput();
    enemyResult->SetLabel(_("COMBAT SKILL must be a whole number greater than 0"));
}

/** \brief Clears the "Combat Ratio" from the GUI. This function is
 * normally called when "Combat Skill" values are being changed.
 *
 */
void LoneWolfCombatResultsFrame::clearCombatRatio()
{
    combatRatioOutput->SetLabel(_("--"));
    Layout();
}

/** \brief Processes the value being input for a manual "die roll" entry.
 * If the entry is whole number, this function passes the value to the
 * "Combat Results" object for additional processing before passing back
 * a return value.
 *
 * \return True if the value of the "die roll" entry proves to be valid;
 * false otherwise.
 *
 */
bool LoneWolfCombatResultsFrame::processManualDieRoll()
{
    wxString dieRollStr = dieRollInput->GetValue();
    long dieRoll;

    // Did the user enter a whole number?
    if (!dieRollStr.ToLong(&dieRoll))
    {
        printDieRollError();
        return false;
    }

    else
    {
        bool setDieRollSuccessful = results->setDieRoll(dieRoll);

        /* Was the input accepted by the "Combat Results" object
        accepted as a valid "die roll"? */
        if (setDieRollSuccessful)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
}

/** \brief Initiates the calculation of results for a combat exchange.
 *
 */
void LoneWolfCombatResultsFrame::calculateCombatResults()
{
    bool doCombatResults = true;

    /* If the user chose to manually enter a "die roll",
    process the user input, and calculate the combat
    result only if the "die roll" value is valid. */
    if (dieRollInput->IsEnabled())
    {
        doCombatResults = processManualDieRoll();
    }

    else
    {
        // Randomly generate a value for the "die roll"
        results->rollDie();
    }

    if (doCombatResults)
    {
        results->outputCombatResults();
    }
}
