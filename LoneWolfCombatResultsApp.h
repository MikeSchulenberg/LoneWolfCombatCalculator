/**
 * \file LoneWolfCombatResultsApp.h
 * \author Mike Schulenberg <mike.schulenberg@gmail.com>
 * \version 1.0
 *
 * \par Description
 * This class initializes the GUI for a program that calculates
 * combat results for the 'Lone Wolf' adventure gamebooks
 * by Joe Dever.
 *
 */

#ifndef LONEWOLFCOMBATRESULTSAPP_H
#define LONEWOLFCOMBATRESULTSAPP_H

#include <wx/app.h>

class LoneWolfCombatResultsApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // LONEWOLFCOMBATRESULTSAPP_H
