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
						cout << mas[i][j] << " ";//"_|"; 
					}
		}
		setColor(White, Black);
		cout << "\n";
	}
}
// Placement of ships
void placementOfShips(int mas[11][11], int x, int y) {
	setColor(LightGray, LightGray);
	for (int i = 0; i < 2; i++) {
		setColor(LightGray, LightGray);
		mas[x][y] = 1;
		y++;
	}
	//setColor(White, Black);
}


int main() {
	int a, b, n = 1;

	int const size = 11;
	int field[size][size] = { };
	
	while (n <= 3) {
		showField(field);
		cout << "Arrange the ships:\n";
		cin >> a >> b;
		system("cls");
		placementOfShips(field, a, b);
		n++;
	}
	showField(field);
	system("pause");
	cout << "Arrange the ships:\n";
	
	return 0;
}