/**
 * \file LoneWolfCombatResultsApp.cpp
 * \author Mike Schulenberg <mike.schulenberg@gmail.com>
 * \version 1.0
 *
 * \par Description
 * This class initializes the GUI for a program that calculates
 * combat results for the 'Lone Wolf' adventure gamebooks
 * by Joe Dever.
 *
 */

#include "wx_pch.h"
#include "LoneWolfCombatResultsApp.h"

//(*AppHeaders
#include "LoneWolfCombatResultsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LoneWolfCombatResultsApp);

bool LoneWolfCombatResultsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LoneWolfCombatResultsFrame* Frame = new LoneWolfCombatResultsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
