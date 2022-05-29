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
// Drawing the user field
void showField(int mas[11][11]) {
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
							setColor(Magenta, Magenta);
							cout << "|" << mas[i][j];
						}
					}
		}
		setColor(White, Black);
		cout << "\n";
	}
}
// Hand placement of ships
void placementOfShips(int mas[11][11], int x, int y, int n, int size) {
	for (int i = 0; i < size; i++) {
		mas[x][y] = 1;
		if (n == 1)
			x++;
		else
			y++;
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
bool placeCheck(int mas[11][11], int x, int y) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++)
			if (mas[x][y] == 1) 
				//mas[i][j] = mas[x][y];
				return false;
			else
				return true;

	}
}

int main() {
	short coordShips = 3;
	char coordX;
	int  coordY, countShips = 0, aircraftCarrier = 4, cruiser = 3, destroyer = 2, sumbmarine = 1, sumS = 1;
	int const size = 11;
	int field[size][size] = { };
	

	// Ручная расстановка кораблей пользователя
	// 4 палубы
	do {
		showField(field);
		cout << "!!!IMPORTANT!!!\nSHIPS ARE PLACED FROM LEFT TO RIGHT OR TOP TO BOTTOM\nLOCATION 1 OF AIRCRAFT CARRIER ( 0 = Horizontally, 1 = Vertically): ";
		cin >> coordShips;
		system("cls");
	} while (coordShips < 0 || coordShips > 1);
	showField(field);
	cout << "PLACE AIRCRAFT CARRIER (1 оf 1) :\n";
	cin >> coordX >> coordY;
	system("cls");
	placementOfShips(field, transformation(coordX), coordY, coordShips, aircraftCarrier);

	// Трёхпалубник
	do {
		do {
			showField(field);
			cout << "FROM LEFT TO RIGHT OR TOP TO BOTTOM\nLOCATION 2 OF THE CRUISERS ( 0 = Horizontally, 1 = Vertically): ";
			cin >> coordShips;
			system("cls");
		} while (coordShips < 0 || coordShips > 1);
		showField(field);
		do {
			system("cls");
			showField(field);
			cout << "PLACE CRUISERS (" << sumS << " of 2):\n";
			cin >> coordX >> coordY;
			//placeCheck(field, transformation(coordX), coordY);
			if ((placeCheck(field, transformation(coordX), coordY) != true)) {
				cout << "THERE IS ALREADY THE SHIP HERE, REPEAT THE INPUT.\n";
				system("pause");
			}
		} while ((placeCheck(field, transformation(coordX), coordY) != true));
		placementOfShips(field, transformation(coordX), coordY, coordShips, cruiser);
		countShips++;
		sumS++;
		system("cls");
	} while (countShips < 2);
	
	// Двупаклубник
	sumS = 1;
	do {
		do {
			system("cls");
			showField(field);
			cout << "FROM LEFT TO RIGHT OR TOP TO BOTTOM\nLOCATION 3 OF THE DESTROYERS ( 0 = Horizontally, 1 = Vertically): ";
			cin >> coordShips;
			system("cls");
		} while (coordShips < 0 || coordShips > 1);
		showField(field);
		do {
			system("cls");
			showField(field);
			cout << "PLACE DESTROYERS (" << sumS << " of 3):\n";
			cin >> coordX >> coordY;
			//placeCheck(field, transformation(coordX), coordY);
			if ((placeCheck(field, transformation(coordX), coordY) != true)) {
				cout << "THERE IS ALREADY THE SHIP HERE, REPEAT THE INPUT.\n";
				system("pause");
			}
		} while ((placeCheck(field, transformation(coordX), coordY) != true));
		placementOfShips(field, transformation(coordX), coordY, coordShips, destroyer);
		countShips++;
		sumS++;
	} while (countShips < 5);

	// Однопалубник
	sumS = 1;
	do {
		do {
			system("cls");
			showField(field);
			cout << "PLACE SUBMARINES (" << sumS << " of 4):\n";
			cin >> coordX >> coordY;
			//placeCheck(field, transformation(coordX), coordY);
			if ((placeCheck(field, transformation(coordX), coordY) != true)) {
				cout << "THERE IS ALREADY THE SHIP HERE, REPEAT THE INPUT.\n";
				system("pause");
			}
		} while ((placeCheck(field, transformation(coordX), coordY) != true));
		placementOfShips(field, transformation(coordX), coordY, coordShips, sumbmarine);
		countShips++;
		sumS++;
	} while (countShips < 9);
	system("cls");
	showField(field);


	return 0;
}