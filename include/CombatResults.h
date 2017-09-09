/**
 * \file CombatResults.h
 * \author Mike Schulenberg <mike.schulenberg@gmail.com>
 * \version 1.0
 *
 * \par Description
 * This class calculates combat results for the 'Lone Wolf'
 * adventure gamebooks by Joe Dever.
 *
 */

#ifndef COMBATRESULTS_H
#define COMBATRESULTS_H

#include <string>

#include "../include/ForwardDeclarations.h"

using std::string;

class CombatResults
{
    public:
        CombatResults(LoneWolfCombatResultsFrame* newView);
        ~CombatResults();

        /////////////////////////////////////////////////////////////
        // MUTATORS
        /////////////////////////////////////////////////////////////

        void setEnemyCombatSkill(int newCombatSkill);
        void setHeroCombatSkill(int newCombatSkill);

        bool setDieRoll(int newDieRoll);

        /////////////////////////////////////////////////////////////
        // CORE FUNCTIONS
        /////////////////////////////////////////////////////////////

        void invalidateEnemyCombatSkill();
        void invalidateHeroCombatSkill();

        void rollDie();

        void outputCombatResults();

    private:
        LoneWolfCombatResultsFrame* view;   // The program's GUI.
        int enemyCombatSkill;               // The enemy's "Combat Skill".
        int heroCombatSkill;                // The Hero's "Combat Skill".
        int combatRatio;                    // The difference between the enemy's and Hero's "Combat Skills".
        int dieRoll;                        // A random number used to determine a combat result.

        const int INVALID_VALUE = -999;     /* Used to indicate that a field is currently storing
                                                an invalid value. */

        /////////////////////////////////////////////////////////////
        // HELPER FUNCTIONS
        /////////////////////////////////////////////////////////////

        bool verifyCombatSkill(int combatSkill) const;
        bool verifyDieRoll(int dieRoll) const;

        void calculateCombatRatio();
        void translateRatioToIndex() const;

        void outputEnemyCombatSkill();
        void outputHeroCombatSkill();
        void outputCombatRatio();

        void outputDieRoll();
        void outputDamageToEnemy() const;
        void outputDamageToHero() const;

        string to_string(int value) const;
};

#endif // COMBATRESULTS_H
