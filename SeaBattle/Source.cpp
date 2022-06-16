#include "SeaBattle.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;



int main() {
	srand(time(NULL));
	// Screensaver
	bool n = false, m = false;
	while (!n) {
		setColor(3, 0);
		title();
		if (_kbhit())
			n = true;
		Sleep(1000);
		system("cls");

		setColor(4, 0);
		title();
		if (_kbhit())
			n = true;
		Sleep(1000);
		system("cls");

		setColor(15, 0);
	}

	short direction = 3;
	char coordX;
	short  coordY = 0;
	short countShips = 0, sumS = 1, sw = 0; //countShips - 
	int const size = 11, ac = 4, cr = 3, des = 2, sub = 1;
	int aircraftCarrier[ac] = { 4, 4, 4, 4 }, cruiser[cr] = { 3, 3, 3 }, destroyer[des] = { 2, 2 }, submarine[sub] = { 1 };
	int field[size][size] = { }, enemyField[size][size] = { };

	do {
		system("cls");
		cout << "CHOOSING THE METHOD OF PLACING SHIPS:\n";
		cout << "1. PLACEMENT IN AUTOMATIC MODE.\n";
		cout << "2. PLACEMENT IN HAND MODE.\n";
		cout << "3. ESCAPE.\n\n";
		cout << "INPUT:";
		cin >> sw;

		switch (sw) {
		case 1:
			// Automatic placement of user ships
			// four-deck ship
			do {
				showField(field);
				cout << "PLACEMENT IN THE PROCESS .\n";
				direction = rand() % 2;
			} while (direction < 0 || direction > 1);
			do {
				system("cls");
				showField(field);
				cout << "PLACEMENT IN THE PROCESS . .\n";
				coordX = rand() % (11 - 1) + 1;
				coordY = rand() % (11 - 1) + 1;
			} while ((placeCheck(field, transformation(coordX), coordY, direction, aircraftCarrier, ac) == false));
			placementOfShips(field, transformation(coordX), coordY, direction, aircraftCarrier, ac);
			system("cls");

			// three-deck ship
			do {
				do {
					showField(field);
					cout << "PLACEMENT IN THE PROCESS . . .\n";
					direction = rand() % 2;
				} while (direction < 0 || direction > 1);
				do {
					system("cls");
					showField(field);
					cout << "PLACEMENT IN THE PROCESS .\n";
					coordX = rand() % (11 - 1) + 1;
					coordY = rand() % (11 - 1) + 1;
				} while ((placeCheck(field, transformation(coordX), coordY, direction, cruiser, cr) == false));
				placementOfShips(field, transformation(coordX), coordY, direction, cruiser, cr);
				countShips++;
				sumS++;
				system("cls");
			} while (countShips < 2);

			// double-deck ship
			sumS = 1;
			do {
				do {
					system("cls");
					showField(field);
					cout << "PLACEMENT IN THE PROCESS . .\n";
					direction = rand() % 2;
				} while (direction < 0 || direction > 1);
				do {
					system("cls");
					showField(field);
					cout << "PLACEMENT IN THE PROCESS . . .\n";
					coordX = rand() % (11 - 1) + 1;
					coordY = rand() % (11 - 1) + 1;
				} while ((placeCheck(field, transformation(coordX), coordY, direction, destroyer, des) == false));
				placementOfShips(field, transformation(coordX), coordY, direction, destroyer, des);
				countShips++;
				sumS++;
			} while (countShips < 5);

			// single-deck ship
			sumS = 1;
			do {
				do {
					system("cls");
					showField(field);
					cout << "PLACEMENT IN THE PROCESS .\n";
					coordX = rand() % (11 - 1) + 1;
					coordY = rand() % (11 - 1) + 1;
				} while ((placeCheck(field, transformation(coordX), coordY, 0, submarine, sub) == false));
				placementOfShips(field, transformation(coordX), coordY, direction, submarine, sub);
				countShips++;
				sumS++;
			} while (countShips < 9);
			system("cls");
			showField(field);
			cout << "EVERYTHING IS READY.\n";
			system("pause");
			system("cls");
			break;

		case 2:
			// Manual placement of user ships
			// four-deck ship
			system("cls");
			do {
				showField(field);
				cout << "!!!IMPORTANT!!!\nSHIPS ARE PLACED FROM LEFT TO RIGHT OR TOP TO BOTTOM\nLOCATION 1 OF AIRCRAFT CARRIER ( 0 = Horizontally, 1 = Vertically): ";
				cin >> direction;
				system("cls");
			} while (direction < 0 || direction > 1);
			showField(field);
			do {
				system("cls");
				showField(field);
				cout << "PLACE AIRCRAFT CARRIER (" << sumS << " of 1):\n";
				cin >> coordX >> coordY;
				if ((placeCheck(field, transformation(coordX), coordY, direction, aircraftCarrier, ac) == false)) {
					cout << "IMPOSSIBLE TO PLACE THE SHIP, REPEAT THE INPUT.\n";
					system("pause");
				}
			} while ((placeCheck(field, transformation(coordX), coordY, direction, aircraftCarrier, ac) == false));
			placementOfShips(field, transformation(coordX), coordY, direction, aircraftCarrier, ac);
			system("cls");
			// three-deck ship
			do {
				do {
					showField(field);
					cout << "FROM LEFT TO RIGHT OR TOP TO BOTTOM\nLOCATION 2 OF THE CRUISERS ( 0 = Horizontally, 1 = Vertically): ";
					cin >> direction;
					system("cls");
				} while (direction < 0 || direction > 1);
				showField(field);
				do {
					system("cls");
					showField(field);
					cout << "PLACE CRUISERS (" << sumS << " of 2):\n";
					cin >> coordX >> coordY;
					if ((placeCheck(field, transformation(coordX), coordY, direction, cruiser, cr) == false)) {
						cout << "IMPOSSIBLE TO PLACE THE SHIP, REPEAT THE INPUT.\n";
						system("pause");
					}
				} while ((placeCheck(field, transformation(coordX), coordY, direction, cruiser, cr) == false));
				placementOfShips(field, transformation(coordX), coordY, direction, cruiser, cr);
				countShips++;
				sumS++;
				system("cls");
			} while (countShips < 2);

			// doble-deck ship
			sumS = 1;
			do {
				do {
					system("cls");
					showField(field);
					cout << "FROM LEFT TO RIGHT OR TOP TO BOTTOM\nLOCATION 3 OF THE DESTROYERS ( 0 = Horizontally, 1 = Vertically): ";
					cin >> direction;
					system("cls");
				} while (direction < 0 || direction > 1);
				showField(field);
				do {
					system("cls");
					showField(field);
					cout << "PLACE DESTROYERS (" << sumS << " of 3):\n";
					cin >> coordX >> coordY;
					if ((placeCheck(field, transformation(coordX), coordY, direction, destroyer, des) == false)) {
						cout << "IMPOSSIBLE TO PLACE THE SHIP, REPEAT THE INPUT.\n";
						system("pause");
					}
				} while ((placeCheck(field, transformation(coordX), coordY, direction, destroyer, des) == false));
				placementOfShips(field, transformation(coordX), coordY, direction, destroyer, des);
				countShips++;
				sumS++;
			} while (countShips < 5);

			// single-deck ship
			sumS = 1;
			do {
				do {
					system("cls");
					showField(field);
					cout << "PLACE SUBMARINES (" << sumS << " of 4):\n";
					cin >> coordX >> coordY;
					if ((placeCheck(field, transformation(coordX), coordY, 0, submarine, sub) == false)) {
						cout << "IMPOSSIBLE TO PLACE THE SHIP, REPEAT THE INPUT.\n";
						system("pause");
					}
				} while ((placeCheck(field, transformation(coordX), coordY, 0, submarine, sub) == false));
				placementOfShips(field, transformation(coordX), coordY, direction, submarine, sub);
				countShips++;
				sumS++;
			} while (countShips < 9);
			system("cls");
			showField(field);
			break;

		case 3: cout << "WE FINISH WITHOUT STARTING!!!\n"; return 0;
		}
	} while (sw < 1 || sw > 3);


	// Fild of enemy
	// four-deck ship
	countShips = 0;
	do {
		showFieldEnemy(enemyField);
		cout << "PLACEMENT IN THE PROCESS .\n";
		direction = rand() % 2;
	} while (direction < 0 || direction > 1);
	do {
		system("cls");
		showFieldEnemy(enemyField);
		cout << "PLACEMENT IN THE PROCESS . .\n";
		coordX = rand() % (11 - 1) + 1;
		coordY = rand() % (11 - 1) + 1;
	} while ((placeCheck(enemyField, transformation(coordX), coordY, direction, aircraftCarrier, ac) == false));
	placementOfShips(enemyField, transformation(coordX), coordY, direction, aircraftCarrier, ac);
	system("cls");

	// three-deck ship
	do {
		do {
			showFieldEnemy(enemyField);
			cout << "PLACEMENT IN THE PROCESS . . .\n";
			direction = rand() % 2;
		} while (direction < 0 || direction > 1);
		do {
			system("cls");
			showFieldEnemy(enemyField);
			cout << "PLACEMENT IN THE PROCESS .\n";
			coordX = rand() % (11 - 1) + 1;
			coordY = rand() % (11 - 1) + 1;
		} while ((placeCheck(enemyField, transformation(coordX), coordY, direction, cruiser, cr) == false));
		placementOfShips(enemyField, transformation(coordX), coordY, direction, cruiser, cr);
		countShips++;
		sumS++;
		system("cls");
	} while (countShips < 2);

	// doble-deck ship
	sumS = 1;
	do {
		do {
			system("cls");
			showFieldEnemy(enemyField);
			cout << "PLACEMENT IN THE PROCESS . .\n";
			direction = rand() % 2;
		} while (direction < 0 || direction > 1);
		do {
			system("cls");
			showFieldEnemy(enemyField);
			cout << "PLACEMENT IN THE PROCESS . . .\n";
			coordX = rand() % (11 - 1) + 1;
			coordY = rand() % (11 - 1) + 1;
		} while ((placeCheck(enemyField, transformation(coordX), coordY, direction, destroyer, des) == false));
		placementOfShips(enemyField, transformation(coordX), coordY, direction, destroyer, des);
		countShips++;
		sumS++;
	} while (countShips < 5);

	// single-deck ship
	sumS = 1;
	do {
		do {
			system("cls");
			showFieldEnemy(enemyField);
			cout << "PLACEMENT IN THE PROCESS .\n";
			coordX = rand() % (11 - 1) + 1;
			coordY = rand() % (11 - 1) + 1;
		} while ((placeCheck(enemyField, transformation(coordX), coordY, 0, submarine, sub) == false));
		placementOfShips(enemyField, transformation(coordX), coordY, direction, submarine, sub);
		countShips++;
		sumS++;
	} while (countShips < 9);
	system("cls");
	showField(field);
	showFieldEnemy(enemyField);

	// Who moves first
	short turn, user, H_T = rand() % (3 - 1) + 1;
	cout << "EVERYTHING IS READY. YOU CAN START THE GAME!\n";
	cout << "LET'S PLAY THE FIRST MOVE. GUESS HEADS OR TAILS.\n1. HEADS.\n2. TAILS.\n\INPUT: ";
	cin >> user;
	if (user != H_T) {
		cout << "\nBOT MOVE.\n\n";
		turn = 2;
		system("pause");
		system("cls");
	}
	else {
		cout << "\nYOUR MOVE.\n\n";
		turn = 1;
		system("pause");
		system("cls");
	}

	showField(field);
	showFieldEnemy(enemyField);
	
	switch (turn) {
    // user's move
	case 1:
		do {
			n = false;
			do {
				if (victoryCheck(enemyField) == true) {
					cout << "YEAH, DUDE. YEAH YOU ARE A REAL MAN :)\n      !!!YOU WON!!!\n\n";
					system("pause");
					break;
				}
				cout << "      BOT SHIPS:\n";
				cout << "AIRCRAFT CARRIER: " << sunkAC(enemyField) << "\n";
				cout << "CRUISERS: " << sunkCR(enemyField) << "\n";
				cout << "DESTROYERS: " << sunkDES(enemyField) << "\n";
				cout << "SUBMARINES: " << sunkSUB(enemyField) << "\n\n";
				cout << "      YOUR MOVE.\n";
				cout << "INPUT LETTER (next press \"ENTER\"): ";
				cin >> coordX;
				cout << "INPUT NUMBER (next press \"ENTER\"): ";
				cin >> coordY;
				if (shot(enemyField, transformation(coordX), coordY) == true) {
					system("pause");
				}
				else {
					n = true;
					system("pause");
				}
				system("cls");
				showField(field);
				showFieldEnemy(enemyField);
			} while (n == false);
			if (victoryCheck(enemyField) == true) 
				break; 

    // bot's move
	case 2:
			n = false;
			do {
				if (victoryCheck(field) == true) {
					cout << "WELL, WELL, WELL, HOW DID YOU MAKE SUCH A MISTAKE :(\n      !!!BOT WON!!!\n\n";
					system("pause");
					break;
				}
				cout << "      YOUR SHIPS:\n";
				cout << "AIRCRAFT CARRIER: " << sunkAC(field) << "\n";
				cout << "CRUISERS: " << sunkCR(field) << "\n";
				cout << "DESTROYERS: " << sunkDES(field) << "\n";
				cout << "SUBMARINES: " << sunkSUB(field) << "\n\n";
				cout << "      BOT MOVE.\n\n";
				coordX = rand() % (char(75) - char(65)) + char(65);
				cout << "BOT INPUT LETTER: " << coordX << endl;
				coordY = rand() % (11 - 1) + 1;
				cout << "BOT INPUT NUMBER: " << coordY << endl;
				system("pause");
				if (shot(field, transformation(coordX), coordY) == true) {
					system("pause");
				}
				else {
					n = true;
					system("pause");
				}
				system("cls");
				showField(field);
				showFieldEnemy(enemyField);
			} while (n == false);
			if (victoryCheck(field) == true)
				break;
		} while (true);
	}
	system("pause");
	system("cls");
	// the end
	n = false;
	while (!n) {
		setColor(Yellow, Black);
		theEnd();
		if (_kbhit())
			n = true;
		Sleep(1000);
		system("cls");

		setColor(LightCyan, Black);
		theEnd();
		if (_kbhit())
			n = true;
		Sleep(1000);
		system("cls");

		setColor(White, Black);
	}

	return 0;
}