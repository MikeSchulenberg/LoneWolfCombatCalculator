/**
 * \file CombatResults.cpp
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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "../include/CombatResults.h"
#include "../LoneWolfCombatResultsMain.h"

using std::stringstream;

/** Used to translate the "Combat Ratio" column from the 'Lone Wolf' Combat Results Table
to an array index. */
enum combatRatioIndexes {NEG_11_OR_GREATER = 0, NEG_10_OR_NEG_9 = 1, NEG_8_OR_NEG_7 = 2,
    NEG_6_OR_NEG_5 = 3, NEG_4_OR_NEG_3 = 4, NEG_2_OR_NEG_1 = 5,
    ZERO = 6,
    POS_1_OR_POS_2 = 7, POS_3_OR_POS_4 = 8, POS_5_OR_POS_6 = 9,
    POS_7_OR_POS_8 = 10, POS_9_OR_POS_10 = 12, POS_11_OR_GREATER = 13};

/** Tracks which column should be used when reading a combat result from an array. */
combatRatioIndexes currentIndex = ZERO;

const int NUM_ROWS = 10;        /**< The number of rows in both combat data arrays. */
const int NUM_COLS = 13;        /**< The number of columns in both combat data arrays. */

/** Stores the number of "Endurance" points lost lost by the enemy during a combat exchange.
 *
 * The row is selected by a random "die roll," either manually entered by the user or
 * generated randomly by another function belonging to this class. The column is selected
 * based on the combat ratio, a number representing the difference between the enemy's and
 * the Hero's "Combat Skills".
 *
 * A numerical result indicates the amount of "Endurance" lost by the enemy.
 * A result of "K" indicates the enemy is killed regardless of their "Endurance" score.
 */
const string DAMAGE_TO_ENEMY[NUM_ROWS][NUM_COLS] =
{
    {"6", "7", "8", "9", "10", "11", "12", "14", "16", "18",  "K",  "K",  "K"},     // dieRoll == 0
    {"0", "0", "0", "0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9"},     // dieRoll == 1
    {"0", "0", "0", "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9", "10"},     // dieRoll == 2
    {"0", "0", "1", "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9", "10", "11"},     // dieRoll == 3
    {"0", "1", "2", "3",  "4",  "5",  "6",  "7",  "8",  "9", "10", "11", "12"},     // dieRoll == 4
    {"1", "2", "3", "4",  "5",  "6",  "7",  "8",  "9", "10", "11", "12", "14"},     // dieRoll == 5
    {"2", "3", "4", "5",  "6",  "7",  "8",  "9", "10", "11", "12", "14", "16"},     // dieRoll == 6
    {"3", "4", "5", "6",  "7",  "8",  "9", "10", "11", "12", "14", "16", "18"},     // dieRoll == 7
    {"4", "5", "6", "7",  "8",  "9", "10", "11", "12", "14", "16", "18",  "K"},     // dieRoll == 8
    {"5", "6", "7", "8",  "9", "10", "11", "12", "14", "16", "18",  "K",  "K"}      // dieRoll == 9
};

/** Stores the number of "Endurance" points lost lost by the Hero during a combat exchange.
 *
 * The row is selected by a random "die roll," either manually entered by the user or
 * generated randomly by another function belonging to this class. The column is selected
 * based on the combat ratio, a number representing the difference between the enemy's and
 * the Hero's "Combat Skills".
 *
 * A numerical result indicates the amount of "Endurance" lost by the Hero.
 * A result of "K" indicates the Hero is killed regardless of their "Endurance" score.
 */
const string DAMAGE_TO_HERO[NUM_ROWS][NUM_COLS] =
{
    {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},              // dieRoll == 0
    {"K", "K", "8", "6", "6", "5", "5", "5", "4", "4", "4", "3", "3"},              // dieRoll == 1
    {"K", "8", "7", "6", "5", "5", "4", "4", "3", "3", "3", "3", "2"},              // dieRoll == 2
    {"8", "7", "6", "5", "5", "4", "4", "3", "3", "3", "2", "2", "2"},              // dieRoll == 3
    {"8", "7", "6", "5", "4", "4", "3", "3", "2", "2", "2", "2", "2"},              // dieRoll == 4
    {"7", "6", "5", "4", "4", "3", "2", "2", "2", "2", "2", "2", "1"},              // dieRoll == 5
    {"6", "6", "5", "4", "3", "2", "2", "2", "2", "1", "1", "1", "1"},              // dieRoll == 6
    {"5", "5", "4", "3", "2", "2", "1", "1", "1", "0", "0", "0", "0"},              // dieRoll == 7
    {"4", "4", "3", "2", "1", "1", "0", "0", "0", "0", "0", "0", "0"},              // dieRoll == 8
    {"3", "3", "2", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}               // dieRoll == 9
};

CombatResults::CombatResults(LoneWolfCombatResultsFrame* newView)
    : view(newView), enemyCombatSkill(0), heroCombatSkill(0), combatRatio(0), dieRoll(0)
{
    // Intentionally empty
}

CombatResults::~CombatResults()
{
    // Intentionally empty
}

/////////////////////////////////////////////////////////////
// MUTATORS
/////////////////////////////////////////////////////////////

void CombatResults::setEnemyCombatSkill(int newCombatSkill)
{
    enemyCombatSkill = newCombatSkill;
    calculateCombatRatio();     // Combat ratio should be recalculated after a change in "Combat Skill"
}

void CombatResults::setHeroCombatSkill(int newCombatSkill)
{
    heroCombatSkill = newCombatSkill;
    calculateCombatRatio();     // Combat ratio should be recalculated after a change in "Combat Skill"
}

void CombatResults::setDieRoll(int newDieRoll)
{
    dieRoll = newDieRoll;
}

/////////////////////////////////////////////////////////////
// ACCESSORS
/////////////////////////////////////////////////////////////

int CombatResults::getEnemyCombatSkill() const
{
    return enemyCombatSkill;
}

int CombatResults::getHeroCombatSkill() const
{
    return heroCombatSkill;
}

int CombatResults::getCombatRatio() const
{
    return combatRatio;
}

int CombatResults::getDieRoll() const
{
    return dieRoll;
}

/////////////////////////////////////////////////////////////
// CORE FUNCTIONS
/////////////////////////////////////////////////////////////

void CombatResults::rollDie()
{
    // Generate a random number from 0 to 9
    srand((int) time(0));
    dieRoll = (rand() % 9);
}

void CombatResults::outputCombatResults()
{
    outputRandomNumber();
    outputDamageToEnemy();
    outputDamageToHero();
}

/////////////////////////////////////////////////////////
// HELPER FUNCTIONS
/////////////////////////////////////////////////////////

void CombatResults::calculateCombatRatio()
{
    combatRatio = heroCombatSkill - enemyCombatSkill;
    translateRatioToIndex();

    /* Convert the combat ratio to a string,
    then forward the string to the GUI. */
    string combatRatioStr = to_string(combatRatio);
    view->printCombatRatio(combatRatioStr);
}

void CombatResults::translateRatioToIndex()
{
    switch (combatRatio)
    {
    case -10 :
    case -9 :
        currentIndex = NEG_10_OR_NEG_9;
        break;
    case -8 :
    case -7 :
        currentIndex = NEG_8_OR_NEG_7;
        break;
    case -6 :
    case -5 :
        currentIndex = NEG_6_OR_NEG_5;
        break;
    case -4 :
    case -3 :
        currentIndex = NEG_4_OR_NEG_3;
        break;
    case -2 :
    case -1 :
        currentIndex = NEG_2_OR_NEG_1;
        break;
    case 0 :
        currentIndex = ZERO;
        break;
    case 1 :
    case 2 :
        currentIndex = POS_1_OR_POS_2;
        break;
    case 3 :
    case 4 :
        currentIndex = POS_3_OR_POS_4;
        break;
    case 5 :
    case 6 :
        currentIndex = POS_5_OR_POS_6;
        break;
    case 7 :
    case 8 :
        currentIndex = POS_7_OR_POS_8;
        break;
    case 9 :
    case 10 :
        currentIndex = POS_9_OR_POS_10;
        break;
    default :
        if (combatRatio > 10)
        {
            currentIndex = POS_11_OR_GREATER;
        }

        else
        {
            currentIndex = NEG_11_OR_GREATER;
        }
    }
}

void CombatResults::outputRandomNumber()
{
    string dieRollStr = to_string(dieRoll);
    view->printGeneralOutput("Random Number: " + dieRollStr);
}

void CombatResults::outputDamageToEnemy() const
{
    string damagetoEnemy = DAMAGE_TO_ENEMY[dieRoll][currentIndex];
    string resultStr;

    if (damagetoEnemy == "K")
    {
        resultStr = "The enemy dies!";
    }

    else
    {
        resultStr = "The enemy loses " + damagetoEnemy + " ENDURANCE.";
    }

    view->printDamageToEnemy(resultStr);
}

void CombatResults::outputDamageToHero() const
{
    string damagetoHero = DAMAGE_TO_HERO[dieRoll][currentIndex];
    string resultStr;

    if (damagetoHero == "K")
    {
        resultStr = "The Hero dies!";
    }

    else
    {
        resultStr = "The Hero loses " + damagetoHero + " ENDURANCE.";
    }

    view->printDamageToHero(resultStr);
}

string CombatResults::to_string(int value)
{
    stringstream ss;
    ss << value;
    return ss.str();
}
