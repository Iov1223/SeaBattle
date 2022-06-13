#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;


// The enumeration of the colors used.
enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  // Getting the output descriptor to the console

void setColor(int text, int fon) { // Changing the text and background.
	SetConsoleTextAttribute(hStdOut, (fon << 4) + text);
}
/*void setCursor(int x, int y) {
	COORD myCoords = { x,y }; //инициализация координат
	SetConsoleCursorPosition(hStdOut, myCoords); //Способ перемещения курсора на нужные координаты
}*/

void title() { // Вывод названия игры (заставка).
	cout << " @@@@   @@@@@   @@@@       @@@@    @@@@   @@@@@@@  @@@@@@@  @      @@@@@\n";
	cout << "@    @  @   @  @    @      @   @  @    @  @  @  @  @  @  @  @      @   @\n";
	cout << "@       @      @    @      @   @  @    @     @        @     @      @\n";
	cout << " @@@@   @@@@   @@@@@@      @@@@   @@@@@@     @        @     @      @@@@\n";
	cout << "     @  @      @    @      @   @  @    @     @        @     @      @\n";
	cout << "@    @  @   @  @    @      @   @  @    @     @        @     @   @  @   @\n";
	cout << " @@@@   @@@@@  @    @      @@@@   @    @     @        @     @@@@@  @@@@@\n";
	cout << "\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE...\n";
}
// Drawing the user field
void showField(int mas[11][11]) {
	cout << "      YOUR FIELD\n";
	char letter = 'A';
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (j == 0 && i == 0) {
				setColor(Blue, White);
				cout << " ";
			}
			else
				if (i == 0) {
					setColor(Blue, White);
					cout << " " << j;
				}
				else
					if (j == 0) {
						setColor(Blue, White);
						cout << letter++ << " ";
					}
					else {
						setColor(White, LightBlue);
						if (mas[i][j] == 0)
							cout << "_|";
						else {
							setColor(White, DarkGray);
							cout << mas[i][j] << "|";
						}
					}
		}
		setColor(White, Black);
		cout << "\n";
	}
}
// Drawing the bot field
void showFieldEnemy(int mas[11][11]) {
	char letter = 'A';
	cout << "      BOT FIELD\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (j == 0 && i == 0) {
				setColor(White, LightRed);
				cout << " ";
			}
			else
				if (i == 0) {
					setColor(White, LightRed);
					cout << " " << j;
				}
				else
					if (j == 0) {
						setColor(White, LightRed);
						cout << letter++ << " ";
					}
					else {
						setColor(White, LightBlue);
						if (mas[i][j] == 0)
							cout << "_|";
						else {
							setColor(White, LightBlue);
							cout << mas[i][j] << "|";
						}
					}
		}
		setColor(White, Black);
		cout << "\n";
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
// Перевод буквы в цифру
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
// Проверка расстановки
bool placeCheck(int mas[11][11], int x, int y, int dir, int ship[], int sizeShip) {
	if (x == 0 || y == 0)
		return false;
	if (dir == 1 && x + sizeShip > 11)
		return false;
	else
		if (dir == 0 && y + sizeShip > 11)
			return false;
	if (mas[x][y] == 1 ||
		mas[x - 1][y] == 1 ||
		mas[x + 1][y] == 1 ||
		mas[x][y - 1] == 1 ||
		mas[x][y + 1] == 1 ||
		mas[x - 1][y - 1] == 1 ||
		mas[x + 1][y + 1] == 1 ||
		mas[x - 1][y + 1] == 1 ||
		mas[x + 1][y - 1] == 1 ||
		mas[x - 1][y] == 1)
		return false;
	if (dir == 1)
		x += (sizeShip - 1);
	else
		if (dir == 0)
			y += (sizeShip - 1);
	if (mas[x][y] == 1 ||
		mas[x - 1][y] == 1 ||
		mas[x + 1][y] == 1 ||
		mas[x][y - 1] == 1 ||
		mas[x][y + 1] == 1 ||
		mas[x - 1][y - 1] == 1 ||
		mas[x + 1][y + 1] == 1 ||
		mas[x - 1][y + 1] == 1 ||
		mas[x + 1][y - 1] == 1 ||
		mas[x - 1][y] == 1)
		return false;

	return true;
}

bool shot(int mas[11][11], int x, int y) {
	if (mas[x][y] == 1) {
		mas[x][y] = 2;
		cout << "***YOU HIT THE BULL'S-EYE***\nTRY AGAIN:\n";
		return true;
	}
	else
		if (mas[x][y] == 0) {
			cout << "~~~UH, NOT LUCK~~~\nTRY NEXT TIME.\n";
			return false;
		}
		//else
		//	if (mas[x][y] = 2) 
			//	return true;
}


int main() {
	srand(time(NULL));
	// Screensaver
	bool n = false;
	/*while (!n) {
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
	}*/

	short direction = 3;
	char coordX;
	short  coordY;
	short countShips = 0, sumS = 1, sw = 0;
	int const size = 11, ac = 4, cr = 3, des = 2, sub = 1;
	int aircraftCarrier[ac] = { 1, 1, 1, 1 }, cruiser[cr] = { 1, 1, 1 }, destroyer[des] = { 1, 1 }, submarine[sub] = { 1 };
	int field[size][size] = { }, enemyField[size][size] = { };

	do {
		system("cls");
		cout << "CHOOSING THE METHOD OF PLACING SHIPS:\n";
		cout << "1. PLACEMENT IN AUTOMATIC MODE.\n";
		cout << "2. PLACEMENT IN HAND MODE.\n";
		cout << "3. ESCAPE.\n\n";
		cout << "INPUT: ";
		cin >> sw;

		switch (sw) {
		case 1:
			// Автоматическая расстановка кораблей пользователя
			// 4 палубы
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

			// 3 палубы
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

			// 2 палубы
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

			// 1 палуба
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
			// Ручная расстановка кораблей пользователя
			// 4 палубы
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
			// 3 палубы
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

			// 2 палубы
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

			// 1 палуба
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


	// Поле противника
	// 4 палубы
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

	// 3 палубы
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

	// 2 палубы
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

	// 1 палуба
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

	short turn, user, H_T = rand() % (3 - 1) + 1;
	cout << "EVERYTHING IS READY. YOU CAN START THE GAME!\n";
	cout << "LET'S PLAY THE FIRST MOVE. GUESS HEADS OR TAILS.\n1. HEADS.\n2. TAILS.\n\INPUT: ";
	cin >> user;
	if (user != H_T) {
		cout << "BOT MOVE.\n";
		turn = 2;
	}
	else {
		cout << "YOUR MOVE.\n";
		turn = 1;
	}

	// Ход пользователя

	/*n = false;
	do {
		cout << "INPUT LETTER (next press \"ENTER\"): ";
		cin >> coordX;
		cout << "INPUT NUMBER (next press \"ENTER\"): ";
		cin >> coordY;
		if (shot(enemyField, transformation(coordX), coordY) == true) {
			//	cout << "***YOU HIT THE BULL'S-EYE***\nTRY AGAIN:\n";
			system("pause");
		}
		else {
			//cout << "~~~UH, NOT LUCK~~~\nTRY NEXT TIME.\n";
			n = true;
			system("pause");
		}
		system("cls");
		showField(field);
		showFieldEnemy(enemyField);
	} while (n == false);*/


	// Ход бота
	do {
		n = false;
		do {
			//int x = rand() % (char(75) - char(65)) + char(65);
			coordX = rand() % (char(75) - char(65)) + char(65);
			cout << "BOT INPUT LETTER: " << coordX << endl;
			coordY = rand() % (11 - 1) + 1;
			cout << "BOT INPUT NUMBER: " << coordY << endl;
			system("pause");
			if (shot(field, transformation(coordX), coordY) == true) {
				//cout << "***YOU HIT THE BULL'S-EYE***\nTRY AGAIN:\n";
				system("pause");
			}
			else {
				//cout << "~~~UH, NOT LUCK~~~\nTRY NEXT TIME.\n";
				n = true;
				system("pause");
			}
			system("cls");
			showField(field);
			showFieldEnemy(enemyField);
		} while (n != true);
	} while (true);

	return 0;
}