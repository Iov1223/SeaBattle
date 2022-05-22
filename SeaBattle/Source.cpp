#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int text, int fon) { // ��������� ������ � ����.
	SetConsoleTextAttribute(hStdOut, (fon << 4) | text);
}
void SetCursor(int x, int y) //������� ��� ���� ����� ������������� ������� ������� � ������� �� ��� � � Y
{
	COORD myCoords = { x,y }; //������������� ���������
	SetConsoleCursorPosition(hStdOut, myCoords); //������ ����������� ������� �� ������ ����������
}

void drawField(int mas[11][11], int x, int y) {
	char letter = 'A';
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (i == x && j == y && x == 0 && y == 0) {
				setColor(Blue, White);
				cout << " ";
			}
			else
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
						else
							if (i == x && j == y) {
								setColor(LightGray, LightGray);
								mas[x][y] == 0;
								cout << mas[x][y] << " ";

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
	drawField(field, 0, 0);
	cout << "Arrange the ships:\n";
	cin >> a >> b;
	system("cls");
	drawField(field, a, b);
	short count = 0;
	do {
		cin >> a >> b;
		drawField(field, a, b);
		count++;
	} while (count < 4);








	return 0;
}