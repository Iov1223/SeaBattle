#include "SeaBattle.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  // Getting the output descriptor to the console
// Color change
void setColor(int text, int fon) { // Changing the text and background.
	SetConsoleTextAttribute(hStdOut, (fon << 4) + text);
}
// Splash screen output
void title() { // Вывод названия игры (заставка).
	std::cout << " @@@@   @@@@@   @@@@       @@@@    @@@@   @@@@@@@  @@@@@@@  @      @@@@@\n";
	std::cout << "@    @  @   @  @    @      @   @  @    @  @  @  @  @  @  @  @      @   @\n";
	std::cout << "@       @      @    @      @   @  @    @     @        @     @      @\n";
	std::cout << " @@@@   @@@@   @@@@@@      @@@@   @@@@@@     @        @     @      @@@@\n";
	std::cout << "     @  @      @    @      @   @  @    @     @        @     @      @\n";
	std::cout << "@    @  @   @  @    @      @   @  @    @     @        @     @   @  @   @\n";
	std::cout << " @@@@   @@@@@  @    @      @@@@   @    @     @        @     @@@@@  @@@@@\n";
	std::cout << "\n\n\n\t\t\tPRESS SPACE TO CONTINUE...\n";
}
// Drawing the user field
void showField(int mas[11][11]) {
	std::cout << "      YOUR FIELD\n";
	char letter = 'A';
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (j == 0 && i == 0) {
				setColor(Blue, White);
				std::cout << " ";
			}
			else
				if (i == 0) {
					setColor(Blue, White);
					std::cout << " " << j;
				}
				else
					if (j == 0) {
						setColor(Blue, White);
						std::cout << letter++ << " ";
					}
					else {
						if (mas[i][j] == 9) {
							setColor(White, Red);
							std::cout << "* ";
						}
						else
							if (mas[i][j] == 8) {
								setColor(LightRed, LightGray);
								std::cout << "* ";
							}
							else
								if (mas[i][j] == 0) {
									setColor(White, LightBlue);
									std::cout << "_|";
								}
								else
									if (mas[i][j] == 4 || mas[i][j] == 3 || mas[i][j] == 2 || mas[i][j] == 1) {
										setColor(DarkGray, DarkGray);
										std::cout << mas[i][j] << "|";
									}
					}
		}
		setColor(White, Black);
		std::cout << "\n";
	}
}
// Drawing the bot field
void showFieldEnemy(int mas[11][11]) {
	char letter = 'A';
	std::cout << "      BOT FIELD\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (j == 0 && i == 0) {
				setColor(White, LightMagenta);
				std::cout << " ";
			}
			else
				if (i == 0) {
					setColor(White, LightMagenta);
					std::cout << " " << j;
				}
				else
					if (j == 0) {
						setColor(White, LightMagenta);
						std::cout << letter++ << " ";
					}
					else {
						if (mas[i][j] == 9) {
							setColor(White, Red);
							std::cout << "* ";
						}
						else
							if (mas[i][j] == 8) {
								setColor(LightRed, LightGray);
								std::cout << "* ";
							}
							else
								if (mas[i][j] == 0) {
									setColor(White, LightBlue);
									std::cout << "_|";
								}
								else
									if (mas[i][j] == 4 || mas[i][j] == 3 || mas[i][j] == 2 || mas[i][j] == 1) {
										setColor(White, LightBlue);
										std::cout << " " << "|";
									}

					}
		}
		setColor(White, Black);
		std::cout << "\n";
	}
}
// Placement of ships
void placementOfShips(int mas[11][11], int x, int y, int dir, int ship[], int sizeShip) {
	for (int i = 0; i < sizeShip; i++) {
		if (dir == 1)
			mas[x + i][y] = ship[i];
		else
			mas[x][y + i] = ship[i];
	}
}
// Transformation of a letter into a number
char transformation(char a) {
	if (a == 'A' || a == 'a')
		a = 1;
	else
		if (a == 'B' || a == 'b')
			a = 2;
		else
			if (a == 'C' || a == 'c')
				a = 3;
			else
				if (a == 'D' || a == 'd')
					a = 4;
				else
					if (a == 'E' || a == 'e')
						a = 5;
					else
						if (a == 'F' || a == 'f')
							a = 6;
						else
							if (a == 'G' || a == 'g')
								a = 7;
							else
								if (a == 'H' || a == 'h')
									a = 8;
								else
									if (a == 'I' || a == 'i')
										a = 9;
									else
										if (a == 'J' || a == 'j')
											a = 10;
	return a;
}
// Checking placement of ships 
bool placeCheck(int mas[11][11], int x, int y, int dir, int ship[], int sizeShip) {
	if (x == 0 || y == 0)
		return false;
	if (dir == 1 && x + sizeShip > 11)
		return false;
	else
		if (dir == 0 && y + sizeShip > 11)
			return false;
	if (mas[x][y] != 0 ||
		mas[x - 1][y] != 0 ||
		mas[x + 1][y] != 0 ||
		mas[x][y - 1] != 0 ||
		mas[x][y + 1] != 0 ||
		mas[x - 1][y - 1] != 0 ||
		mas[x + 1][y + 1] != 0 ||
		mas[x - 1][y + 1] != 0 ||
		mas[x + 1][y - 1] != 0 ||
		mas[x - 1][y] != 0)
		return false;
	if (dir == 1)
		x += (sizeShip - 1);
	else
		if (dir == 0)
			y += (sizeShip - 1);
	if (mas[x][y] != 0 ||
		mas[x - 1][y] != 0 ||
		mas[x + 1][y] != 0 ||
		mas[x][y - 1] != 0 ||
		mas[x][y + 1] != 0 ||
		mas[x - 1][y - 1] != 0 ||
		mas[x + 1][y + 1] != 0 ||
		mas[x - 1][y + 1] != 0 ||
		mas[x + 1][y - 1] != 0 ||
		mas[x - 1][y] != 0)
		return false;

	return true;
}
// Shots
bool shot(int mas[11][11], int x, int y) {
	if (mas[x][y] == 4 || mas[x][y] == 3 || mas[x][y] == 2 || mas[x][y] == 1) {
		mas[x][y] = 9;
		std::cout << "\n***YOU HIT THE BULL'S-EYE***\n\nTRY AGAIN:\n";
		return true;
	}
	else
		if (mas[x][y] == 0) {
			mas[x][y] = 8;
			std::cout << "\n~~~OOPS, NOT LUCK~~~\n\nTRY NEXT TIME.\n";
			return false;
		}

		else
			if (mas[x][y] == 8 || mas[x][y] == 9) // Cancels the shot if the shot is fired at a cell where it has already been fired.
				return true;
}
//Cheking whether four-deck ship has been sunk
std::string sunkAC(int mas[11][11]) {
	int count = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++)
			if (mas[i][j] == 4)
				count++;

	}
	if (count == 0)
		return "THE SHIP IS FLOODED!";
	return "1";
}
// Counting and checking of three-deck ships
std::string sunkCR(int mas[11][11]) {
	int count = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++)
			if (mas[i][j] == 3)
				count++;

	}
	if (count == 6 || count > 3)
		return "2";
	if (count == 3 || count > 0)
		return "1";
	if (count == 0)
		return "ALL THE SHIPS ARE FLOODED!";
}
// Counting and checking of doble-deck ships
std::string sunkDES(int mas[11][11]) {
	int count = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++)
			if (mas[i][j] == 2)
				count++;

	}
	if (count == 6 || count == 5)
		return "3";
	if (count == 4 || count == 3)
		return "2";
	if (count == 2 || count == 1)
		return "1";
	if (count == 0)
		return "ALL THE SHIPS ARE FLOODED!";
}
// Counting and checking of single-deck ships
std::string sunkSUB(int mas[11][11]) {
	int count = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++)
			if (mas[i][j] == 1)
				count++;

	}
	if (count == 4)
		return "4";
	if (count == 3)
		return "3";
	if (count == 2)
		return "2";
	if (count == 1)
		return "1";
	if (count == 0)
		return "ALL THE SHIPS ARE FLOODED!";
}
// Check for victory
bool victoryCheck(int mas[11][11]) {
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++)
			if (mas[i][j] == 4 || mas[i][j] == 3 || mas[i][j] == 2 || mas[i][j] == 1)
				return false;
	}
	return true;
}
// THE END
void theEnd() { // Вывод названия игры (заставка).
	std::cout << "@@@@@@@  @   @  @@@@@      @@@@@  @    @  @@@@    @\n";
	std::cout << "@  @  @  @   @  @   @      @   @  @    @  @   @   @\n";
	std::cout << "   @     @   @  @          @      @@   @  @    @  @\n";
	std::cout << "   @     @@@@@  @@@@       @@@@   @ @  @  @    @  @\n";
	std::cout << "   @     @   @  @          @      @  @ @  @    @  @\n";
	std::cout << "   @     @   @  @   @      @   @  @   @@  @   @    \n";
	std::cout << "   @     @   @  @@@@@      @@@@@  @    @  @@@@    @\n";
	std::cout << "\n\n\t    PRESS ANY KEY TO CLOSE...\n";
}