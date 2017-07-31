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

using std::string;

class CombatResults
{
    public:
        CombatResults();
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

        /** \brief Randomly generates the die roll used for determining
         * a combat result.
         *
         */
        void rollDie();

        /** \brief Outputs the number of "Endurance" points lost by the enemy.
         *
         */
        void outputDamageToEnemy() const;

        /** \brief Outputs the number of "Endurance" points lost by the Hero.
         *
         */
        void outputDamageToHero() const;

    private:
        int enemyCombatSkill;       /**< The enemy's "Combat Skill". */
        int heroCombatSkill;        /**< The Hero's "Combat Skill". */
        int combatRatio;            /**< The difference between the enemy's and Hero's "Combat Skills". */
        int dieRoll;                /**< A random number used to determine a combat result. */

        /////////////////////////////////////////////////////////////
        // HELPER FUNCTIONS
        /////////////////////////////////////////////////////////////

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
};

#endif // COMBATRESULTS_H
