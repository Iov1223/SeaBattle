#pragma once
#include <iostream>

// The enumeration of the colors used.
enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
// Color change
void setColor(int text, int fon);
// Splash screen output
void title();
// Drawing the user field
void showField(int mas[11][11]);
// Drawing the bot field
void showFieldEnemy(int mas[11][11]);
// Placement of ships
void placementOfShips(int mas[11][11], int x, int y, int dir, int ship[], int sizeShip);
// Transformation of a letter into a number
char transformation(char a);
// Checking placement of ships 
bool placeCheck(int mas[11][11], int x, int y, int dir, int ship[], int sizeShip);
// Shots
bool shot(int mas[11][11], int x, int y);
//Cheking whether four-deck ship has been sunk
std::string sunkAC(int mas[11][11]);
// Counting and checking of three-deck ships
std::string sunkCR(int mas[11][11]);
// Counting and checking of doble-deck ships
std::string sunkDES(int mas[11][11]);
// Counting and checking of single-deck ships
std::string sunkSUB(int mas[11][11]);
// Check for victory
bool victoryCheck(int mas[11][11]);
// THE END
void theEnd();