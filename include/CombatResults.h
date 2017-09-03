/**
 * \file CombatResults.h
 * \author Mike Schulenberg <mike.schulenberg@gmail.com>
 * \version 1.0
 *
 * \section LICENSE
 * // TODO: add license text
 *
 * \section DESCRIPTION
 *
 * This class calculates the combat results for Joe Dever's
 * 'Lone Wolf' gamebooks, as well as the 'Lone Wolf Adventure
 * Game' published by Cubicle 7.
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

        /** \brief Sets the "Combat Skill" for the enemy.
         *
         * \param newCombatSkill The value to use for "Combat Skill".
         * Must be at least 1.
         *
         */
        void setEnemyCombatSkill(int newCombatSkill);

        /** \brief Sets the "Combat Skill" for the Hero.
         *
         * \param newCombatSkill The value to use for "Combat Skill".
         * Must be at least 1.
         *
         */
        void setHeroCombatSkill(int newCombatSkill);

        /** \brief Allows the user to manually enter a die roll,
         * as opposed to a random result.
         *
         * \param newDieRoll The value to use for determining
         * a combat result. Must be a number from 0 to 9, inclusive.
         *
         */
        void setDieRoll(int newDieRoll);

        /////////////////////////////////////////////////////////////
        // ACCESSORS
        /////////////////////////////////////////////////////////////

        // TODO: delete accessors if unnecessary

        /** \brief Returns the "Combat Skill" for the enemy.
         *
         */
        int getEnemyCombatSkill() const;

        /** \brief Returns the "Combat Skill" for the Hero.
         *
         */
        int getHeroCombatSkill() const;

        /** \brief Returns the ratio between the "Combat Skills"
         * of the enemy and the Hero.
         *
         */
        int getCombatRatio() const;

        /** \brief Returns the die roll used for determining
         * a combat result.
         *
         */
        int getDieRoll() const;

        /////////////////////////////////////////////////////////////
        // CORE FUNCTIONS
        /////////////////////////////////////////////////////////////

        /** \brief Sets the enemy "Combat Skill" to a value known to be invalid
         * to assist with user input verification.
         *
         */
        void invalidateEnemyCombatSkill();

        /** \brief Sets the Hero "Combat Skill" to a value known to be invalid
         * to assist with user input verification.
         *
         */
        void invalidateHeroCombatSkill();

        /** \brief Randomly generates the die roll used for determining
         * a combat result.
         *
         */
        void rollDie();

        /** \brief Outputs the results of the combat exchange and forwards it
         * to the GUI.
         *
         */
        void outputCombatResults();

    private:
        LoneWolfCombatResultsFrame* view;   /**< The program's GUI. */
        int enemyCombatSkill;               /**< The enemy's "Combat Skill". */
        int heroCombatSkill;                /**< The Hero's "Combat Skill". */
        int combatRatio;                    /**< The difference between the enemy's and Hero's "Combat Skills". */
        int dieRoll;                        /**< A random number used to determine a combat result. */

        const int INVALID_VALUE = -999;       /**< Used to indicate that a field is currently storing
                                                an invalid value. */

        /////////////////////////////////////////////////////////////
        // HELPER FUNCTIONS
        /////////////////////////////////////////////////////////////

        /** \brief Verifies that the "Combat Skill" entered by the user is valid.
         *
         */
        bool verifyCombatSkill(int combatSkill) const;

        /** \brief Verifies that the "random number" manually entered by the user is valid.
         *
         */
        bool verifyDieRoll(int dieRoll) const;

        /** \brief Calculates the difference between the enemy's and Hero's "Combat Skills".
         * A negative number favors the enemy. A positive number favors the Hero.
         *
         */
        void calculateCombatRatio();

        /** \brief Translates the combat ratio into an index. This index is used to select a column
         * in the 2D arrays that store combat result data.
         *
         */
        void translateRatioToIndex();

        /** \brief Outputs the current enemy "Combat Skill" to the GUI.
         *
         */
        void outputEnemyCombatSkill();

        /** \brief Outputs the current Hero "Combat Skill" to the GUI.
         *
         */
        void outputHeroCombatSkill();

        /** \brief Outputs the current "Combat Ratio" to the GUI.
         *
         */
        void outputCombatRatio();

        /** \brief Outputs the random number used to determine the result of the combat exchange.
         * This number may either be generated internally by a function, or entered manually by
         * the user.
         *
         */
        void outputDieRoll();

        /** \brief Outputs the number of "Endurance" points lost by the enemy.
         *
         */
        void outputDamageToEnemy() const;

        /** \brief Outputs the number of "Endurance" points lost by the Hero.
         *
         */
        void outputDamageToHero() const;

        /** \brief Converts a value to a string.
         *
         * \param value An integer to be converted to a string.
         *
         */
        string to_string(int value);
};

#endif // COMBATRESULTS_H
