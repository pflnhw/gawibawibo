#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "SerialClass.h" // �Ƶ��̳�� ���� �ø��� ���

using namespace std;

int gamestart();
int menu();
int main();
void result();

// Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int gamevalue = 0;

// �ø��� ���
void mySerial() {
	Serial* SP = new Serial("\\\\.\\COM3");

	char incomingData[256] = "";
	int dataLength = 255;
	int readResult = 0;

	while (SP->IsConnected()) {
		SP->WriteData("ON", dataLength);
		Sleep(500);
		SP->WriteData("OFF", dataLength);
		Sleep(500);
		break;
	}
}

// Ŀ�� �̵� �Լ�
void select(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Ŀ�� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// ���� ���� ��
int gawibawibo(int j) {
	system("cls");
	int x = 22;
	int y = 14;
	if (gamevalue == 0) {
		cout << endl << endl << endl;
		cout << "       ##      ##                           " << endl;
		cout << "        ##    ##                            " << endl;
		cout << "         ##  ##                             " << endl;
		cout << "        ########            ##       ##    ###### " << endl;
		cout << "      ############           ##     ##    ##      " << endl;
		cout << "      ############            ##   ##     ####### " << endl;
		cout << "      ############             ## ##           ## " << endl;
		cout << "       ##########               ###       ######  " << endl;
		result();
		gamevalue = 3;
	}
	else if (gamevalue == 1) {
		cout << endl << endl << endl << endl;
		cout << "         # # # #                           " << endl;
		cout << "        #########            ##       ##    ###### " << endl;
		cout << "      #############           ##     ##    ##      " << endl;
		cout << "      #############            ##   ##     ####### " << endl;
		cout << "      #############             ## ##           ## " << endl;
		cout << "        #########                ###       ######  " << endl;
		result();
		gamevalue = 3;
	}
	else if (gamevalue == 2) {
		cout << endl << endl;
		cout << "            # # # #                           " << endl;
		cout << "            # # # #                           " << endl;
		cout << "            # # # #                           " << endl;
		cout << "           #########            ##       ##    ###### " << endl;
		cout << "     ##  ############            ##     ##    ##      " << endl;
		cout << "      ## #############            ##   ##     ####### " << endl;
		cout << "       ##############              ## ##           ## " << endl;
		cout << "           #########                ###       ######  " << endl;
		result();
		gamevalue = 3;
	}
	else if (gamevalue == 3) {
		return 3;
	}
	select(x - 2, y);
	cout << ">   �� �� ";
	select(x, y + 1);
	cout << "  �� �� ";
	select(x, y + 2);
	cout << "  ��   ";
	select(x, y + 3);
	cout << "  �� ��   ";
}


// ���� ȭ��
void title() {
	system("mode con cols=60 lines=20 | title tetris");
	cout << endl << endl << endl << endl;
	cout << "            #     ###   #        #     ###   #  #   #  " << endl;
	cout << "      ####  #   ##   ## #  #   # #   ##   ## #  #####  " << endl;
	cout << "         #  ### ##   ## #  ##### ### ##   ## #  #   #  " << endl;
	cout << "         #  #     ###   #  #   # #     ###   #  #####  " << endl;
	cout << "         #  #   ####### #  ##### #   ####### #    #    " << endl;
	cout << "            #      #    #        #      #    # ####### " << endl;
}

// Ű���� ��Ʈ��
int keycontrol() {
	char temp = _getch(); // Ű���� �Է� ����

	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == 'a' || temp == 'A') return LEFT;
	else if (temp == 'd' || temp == 'D') return RIGHT;
	else if (temp == ' ') return SUBMIT;
}

// �޴� �����
int menu() {
	int x = 22;
	int y = 14;
	select(x - 2, y);
	cout << ">   �� �� �� �� ";
	select(x, y + 1);
	cout << "  �� �� �� �� ";
	select(x, y + 2);
	cout << "     �� ��   ";
	while (1) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (y > 14) {
				select(x - 2, y);
				cout << ' ';
				select(x - 2, --y);
				cout << '>';
			}
			break;
		}
		case DOWN: {
			if (y < 16) {
				select(x - 2, y);
				cout << ' ';
				select(x - 2, ++y);
				cout << '>';
			}
			break;
		}
		case SUBMIT: {
			return y - 14;
		}
		}
	}
}

// �� �� �� ��
int gamestart() {
	int x = 22;
	int y = 14;
	system("cls");
	select(x - 2, y);
	cout << ">   �� �� ";
	select(x, y + 1);
	cout << "  �� �� ";
	select(x, y + 2);
	cout << "  ��   ";
	select(x, y + 3);
	cout << "  �� ��   ";
	while (1) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (y > 14) {
				select(x - 2, y);
				cout << ' ';
				select(x - 2, --y);
				cout << '>';
			}
			break;
		}
		case DOWN: {
			if (y < 17) {
				select(x - 2, y);
				cout << ' ';
				select(x - 2, ++y);
				cout << '>';
			}
			break;
		}
		case SUBMIT: {
			gamevalue = y - 14;
			gawibawibo(gamevalue);
			if (gawibawibo(gamevalue) == 3) return 0;
			
		}
		}
	}
}

// �� �� �� ��
void info() {
	system("cls");
	cout << endl << endl;
	cout << "[���۹�]" << endl;
	cout << "�̵� : W, A, S, D" << endl;
	cout << "���� : �����̽��� " << endl;
	cout << "�����̽��ٸ� ������ ����ȭ������ �̵��մϴ�." << endl;
	while (1) {
		if (keycontrol() == SUBMIT) break;
	}
}

// ���� ���
void result() {
	int x = 22;
	int y = 14;
	select(x, y);
	cout << "    ";
	cout << "  3 ";
	Sleep(1000);
	select(x, y);
	cout << "    ";
	cout << "  2 ";
	Sleep(1000);
	select(x, y);
	cout << "    ";
	cout << "  1 ";
	Sleep(1000);
	system("cls");
	srand(time(NULL));
	int random = rand()%3;
		if (random == 0) {
			cout << endl << endl << endl << endl;
			cout << "          ##                ##  #######  ##     ## " << endl;
			cout << "           ##      ##      ##     ###    ####   ## " << endl;
			cout << "            ##    ####    ##      ###    ## ##  ## " << endl;
			cout << "             ##  ##  ##  ##       ###    ##  ## ## " << endl;
			cout << "              ####    ####        ###    ##   #### " << endl;
			cout << "               ##      ##       #######  ##     ## " << endl;
		}
		else if (random == 1) {
			cout << endl << endl << endl << endl;
			cout << "          ##           #####     ####### ########   " << endl;
			cout << "          ##        ##      ##  ##       ##         " << endl;
			cout << "          ##        ##      ##  ######## ########   " << endl;
			cout << "          ##        ##      ##        ## ##         " << endl;
			cout << "          ##        ##      ##        ## ##         " << endl;
			cout << "          #########   ######    ######## ########   " << endl;
			mySerial();
		}
		else if (random == 2) {
			cout << endl << endl << endl << endl;
			cout << "     #######     ######        ###     ##                ## " << endl;
			cout << "     ##    ###   ##   ##     ### ###    ##      ##      ## " << endl;
			cout << "     ##      ##  ##    ##   ##     ##    ##    ####    ## " << endl;
			cout << "     ##      ##  ########   #########     ##  ##  ##  ##" << endl;
			cout << "     ##    ###   ##    ##   ##     ##      ####    ####" << endl;
			cout << "     #######     ##     ##  ##     ##       ##      ## " << endl;
		}
	select(x - 2, y+3);
	cout << ">   Ȯ �� ";
	while (1) {
		if (keycontrol() == SUBMIT) break;
	}
}

int main() {
	while (1) {
		title();
		int menucode = menu();
		system("cls");
		// �� �� �� ��
		if (menucode == 0) {
			gamestart();
		}
		// �� �� �� ��
		else if (menucode == 1) {
			info();
		}
		// �� �� �� ��
		else if (menucode == 2) {
			return 0;
		}
	}
	return 0;
}