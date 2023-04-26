#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// 키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int gamevalue = 0;

// 커서 이동 함수
void select(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 커서 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// 가위 바위 보
int gawibawibo(int j) {
	system("cls");
	if (gamevalue == 0) {
		cout << endl;
		cout << endl;
		cout << "       ##      ## " << endl;
		cout << "        ##    ##" << endl;
		cout << "         ##  ##" << endl;
		cout << "       #########" << endl;
		cout << "     #############" << endl;
		cout << "     #############" << endl;
		cout << "     #############" << endl;
		cout << "       #########" << endl;
	}
	else if (gamevalue == 1) {
		cout << endl;
		cout << endl;
		cout << "        # # # #" << endl;
		cout << "       #########" << endl;
		cout << "     #############" << endl;
		cout << "     #############" << endl;
		cout << "     #############" << endl;
		cout << "       #########" << endl;
	}
	else if (gamevalue == 2) {
		cout << endl;
		cout << endl;
		cout << "            # # # #" << endl;
		cout << "            # # # #" << endl;
		cout << "            # # # #" << endl;
		cout << "     ##    #########" << endl;
		cout << "     ##  ##############" << endl;
		cout << "      #################" << endl;
		cout << "        ###############" << endl;
		cout << "           #########" << endl;
	}
	else if (gamevalue == 3) {
		return 0;
	}
	int x = 22;
	int y = 14;
	select(x - 2, y);
	cout << ">   가 위 ";
	select(x, y + 1);
	cout << "  바 위 ";
	select(x, y + 2);
	cout << "  보   ";
	select(x, y + 3);
	cout << "  종 료   ";
}


// 시작 화면
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

// 키보드 컨트롤
int keycontrol() {
	char temp = _getch(); // 키보드 입력 저장

	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == 'a' || temp == 'A') return LEFT;
	else if (temp == 'd' || temp == 'D') return RIGHT;
	else if (temp == ' ') return SUBMIT;
}

// 메뉴 만들기
int menu() {
	int x = 22;
	int y = 14;
	select(x - 2, y);
	cout << ">   게 임 시 작 ";
	select(x, y + 1);
	cout << "  게 임 정 보 ";
	select(x, y + 2);
	cout << "     종 료   ";
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

// 게 임 시 작
int gamestart() {
	system("cls");
	int x = 22;
	int y = 14;
	select(x - 2, y);
	cout << ">   가 위 ";
	select(x, y + 1);
	cout << "  바 위 ";
	select(x, y + 2);
	cout << "  보   ";
	select(x, y + 3);
	cout << "  종 료   ";
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
		}
		}
	}
}

// 게 임 정 보
void info() {
	system("cls");
	cout << endl << endl;
	cout << "[조작법]" << endl;
	cout << "이동 : W, A, S, D" << endl;
	cout << "선택 : 스페이스바 " << endl;
	cout << "스페이스바를 누르면 메인화면으로 이동합니다." << endl;
	while (1) {
		if (keycontrol() == SUBMIT) break;
	}
}

int main() {
	while (1) {
		title();
		int menucode = menu();
		system("cls");
		// 게 임 시 작
		if (menucode == 0) {
			gamestart();
		}
		// 게 임 정 보
		else if (menucode == 1) {
			info();
		}
		// 게 임 종 료
		else if (menucode == 2) {
			return 0;
		}
	}
	return 0;
}