# Lone Wolf Combat Calculator
This program calculates combat results for the 'Lone Wolf' adventure game-books by Joe Dever. It can also be used with the 'Lone Wolf Adventure Game' published by Cubicle 7.

## Version
1.0

## Development
This program was written in C++ using Code::Blocks, the included wxSmith plugin, and the wxWidgets library.

## Download an Executable Version for Windows
[Lone Wolf Combat Calculator](https://www.dropbox.com/s/e47y3g8rjnzcbou/LoneWolfCombatCalculator.zip?dl=0)

##### ZIP File Contents
- LoneWolfCombatCalculator.exe
- readme.txt
- wxmsw30u_gcc_custom.dll

## Using the Program
Run LoneWolfCombatCalculator.exe to start the program.

The program interface has 3 parts: the COMBAT SKILL panel, the DIE ROLL panel, and the COMBAT RESULTS panel.

Use the COMBAT SKILL panel to enter Combat Skill values for the Hero and for the Enemy. These values must be whole numbers equal to 1 or greater. Entering Combat Skill values for both combatants displays the Combat Ratio between them and enables the DIE ROLL panel.

Use the DIE roll panel to switch between "random" and "manual" combat resolution modes. "Random" mode automatically generates a value from 0 to 9 during the resolution stage. "Manual" mode requires user input of a whole number from 0 to 9.

The COMBAT RESULTS panel displays the result of the current combat exchange. Input error messages will also appear here.
