#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int text, int fon) { // Изменение текста и фона.
	SetConsoleTextAttribute(hStdOut, (fon << 4) | text);
}
void SetCursor(int x, int y) //функция для того чтобы устанавливать позицию курсора в консоли по оси Х и Y
{
	COORD myCoords = { x,y }; //инициализация координат
	SetConsoleCursorPosition(hStdOut, myCoords); //Способ перемещения курсора на нужные координаты
}

void drawField(int mas[11][11]) {
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
						cout << "_|";
					}


		}
		setColor(White, Black);
		cout << "\n";
	}
}
/*void drawField(int mas[11][11], int x, int y) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (i == x && j == y)
				cout << " #";
			else
				cout << " ";
		}
		cout << "\n";
	}
}*/

int main() {
	int a, b;

	int const size = 11;
	int field[size][size] = { 0 };
	drawField(field);
	cout << "Arrange the ships:\n";
	cin >> a >> b;
	system("cls");
	
	







	return 0;
}