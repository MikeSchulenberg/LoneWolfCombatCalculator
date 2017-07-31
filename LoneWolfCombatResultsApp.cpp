/***************************************************************
 * Name:      LoneWolfCombatResultsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mike Schulenberg ()
 * Created:   2017-07-31
 * Copyright: Mike Schulenberg ()
 * License:
 **************************************************************/

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
