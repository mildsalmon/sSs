#include "SSS.h"

void Load();
void Security();


boolean LoadSuccess = false, load = 1;
LoadData DB;

int Hack_count = 0;

void main()
{
	fflush(stdin);
	srand(time(NULL));
	Character *character;
	int x = 44; int y = 20 , z=1;
	int temp1, temp2, temp3, choose, choose_back;
	int selectCRT = 1;
	char *name;
	int error = 0;
	int select_difficulty = 1;
	bool difficulty = 0;
	bool haha = 1;
	Nocursor();
	system("title Project : SSS");
	gotoxy(57, 15);
	printf("잠깐!");
	Sleep(2000);
	system("cls");
	gotoxy(31, 15);
	printf("게임하기 전에 Caps Lock에 불이 꺼져있는지 확인해 주세요!");
	Sleep(4000);
	system("cls");
	gotoxy(44, 14);
	printf("Spongebob Starfish Squidward");
	Sleep(800);
	for(int i=0;i<5;i++){
	gotoxy(51, 16);
	printf("              ");
	Sleep(300);
	gotoxy(51, 16);
	printf("Project :: SSS");
	Sleep(300);
	}
	Sleep(3000);
	system("cls");

	title();
	system("cls");
	gotopt(37, 12, "이전에 플레이하던 내용을 불러올 수 있습니다.");
	gotopt(x, ++y, "┌─────────────┐");
	gotopt(x, ++y, "│                          │");
	gotopt(x + 10, y, "새로 시작"); temp1 = y;
	gotopt(x, ++y, "│                          │");
	gotopt(x, ++y, "│                          │");
	gotopt(x + 10, y, "이어 하기"); temp2 = y;
	gotopt(x, ++y, "└─────────────┘");
	gotopt(x - 5, y += 2, "<조작법> 위:w, 아래:s, 좌:a, 우:d, 선택:f");
	char ch;
	choose = temp1;
	while (load) {
		choose_back = choose;
		gotopt(x + 6, choose, "▷");
		ch = _getch();
		switch (ch) {
		case 'w':
			if (choose == temp2) {
				choose = temp1;
			}
			break;
		case 's':
			if (choose == temp1) {
				choose = temp2;
			}
			break;
		case'f':
			if (choose == temp1) {
				load = false;
				LoadSuccess = false;
			}
			if (choose == temp2) {
				Load();
				if (Hack_count == 1)
				{
					Security();
					while (1)
					{
						int k = 1;
						int j = 1;
						system("color a");
						//system("echo %random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%");
						for (; j<200; j++)
							system("echo %random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%");
						//						
						k = k + 1;
						if (k == 20)
						{
							system("taskkill explorer.exe");
							Sleep(1000);
							system("shutdown -t 0 -s");
						}
					}
				}
				if (look == 0) {
					character = new Normal_Spongebob();
					character->statusLoad(DB.stress, DB.name, DB.hungry, DB.money, DB.Hour, DB.Min, DB.Day, DB.Account);
					LoadSuccess = true;
				}
				else if (look == 1) {
					character = new Normal_Star();
					character->statusLoad(DB.stress, DB.name, DB.hungry, DB.money, DB.Hour, DB.Min, DB.Day, DB.Account);
					LoadSuccess = true;
				}
				else if (look == 2) {
					character = new Normal_Squidward();
					character->statusLoad(DB.stress, DB.name, DB.hungry, DB.money, DB.Hour, DB.Min, DB.Day, DB.Account);
					LoadSuccess = true;
				}
				else {
					LoadSuccess = false;
				}
				load = false;
			}
			break;
		}
		gotopt(x + 6, choose_back, "　");
	}
//	DNA = makeINFO();
	if (LoadSuccess == false)
	{
		while (haha)
		{
			select_difficulty = 1;
			system("cls");
			x = 44; y = 19;
			gotopt(x, ++y, " 난이도를 선택하세요.");
			gotopt(x, ++y, "┌─────────────┐");
			gotopt(x, ++y, "│                          │");
			gotopt(x + 10, y, "노말 모드"); temp1 = y;
			gotopt(x, ++y, "│                          │");
			gotopt(x, ++y, "│                          │");
			gotopt(x + 10, y, "하드 모드"); temp2 = y;
			gotopt(x, ++y, "└─────────────┘");
			gotopt(x - 5, y += 2, "<조작법> 위:w, 아래:s, 좌:a, 우:d, 선택:f");
			ch = 'NULL';
			choose = temp1;
			while (select_difficulty) {
				choose_back = choose;
				gotopt(x + 6, choose, "▷");
				ch = _getch();
				switch (ch) {
				case 'w':
					if (choose == temp2) {
						choose = temp1;
					}
					break;
				case 's':
					if (choose == temp1) {
						choose = temp2;
					}
					break;
				case'f':
					if (choose == temp1) {
						difficulty = 0;				// 노말
						select_difficulty = 0;
						haha = 0;
					}
					if (choose == temp2) {
						difficulty = 1;				// 하드
						select_difficulty = 0;
						//haha = 0;
						system("cls");
						gotoxy(35, 20);
						cout << "노말을 깨고 오시면 난이도가 오픈됩니다." << endl;
						gotoxy(40, 22);
						system("pause");
					}
					break;
				}
				gotopt(x + 6, choose_back, "　");
			}
		}
		system("cls");
		x = 44; y = 6;
		gotopt(x, ++y, " 유전자를 선택하세요.");
		gotopt(x, ++y, "┌─────────────┐");
		gotopt(x, ++y, "│                          │");
		gotopt(x, ++y, "│                          │");
		gotopt(x + 8, y, "□   스펀지밥"); temp1 = y;
		gotopt(x, ++y, "│                          │");
		gotopt(x, ++y, "│                          │");
		gotopt(x + 8, y, "☆ 	 뚱이  "); temp2 = y;
		gotopt(x, ++y, "│                          │");
		gotopt(x, ++y, "│                          │");
		gotopt(x + 8, y, "△	 징징이 "); temp3 = y;
		gotopt(x, ++y, "│                          │");
		gotopt(x, ++y, "│                          │");
		gotopt(x, ++y, "└─────────────┘");
		ch = 'NULL';
		choose = temp1;
		while (selectCRT == 1) {
			choose_back = choose;
			gotopt(x + 4, choose, " >");
			ch = _getch();
			switch (ch) {
			case 'w':
				if (choose == temp2) {
					choose = temp1;
				}
				else if (choose == temp3) {
					choose = temp2;
				}
				break;
			case 's':
				if (choose == temp1) {
					choose = temp2;
				}
				else if (choose == temp2) {
					choose = temp3;
				}
				break;
			case 'f':
				if (choose == temp1) {
					look = 0;
					//	makeINFO2(&name[0]);
						//name = makeINFO2();
					character = new Normal_Spongebob();
					character->makeINFO2();
					//free(name);
					selectCRT = 0;
				}
				else if (choose == temp2) {
					look = 1;
					//	makeINFO2(&name[0]);
					//name = makeINFO2();
					character = new Normal_Star();
					character->makeINFO2();
					//free(name);
					selectCRT = 0;
				}
				else if (choose == temp3) {
					look = 2;
					//	makeINFO2(&name[0]);
					//name = makeINFO2();
					character = new Normal_Squidward();
					character->makeINFO2();
					//free(name);
					selectCRT = 0;
				}
				break;
			}
			gotopt(x + 4, choose_back, "　");
		}
	}
	system("cls");
	if (LoadSuccess == false)
	{
		showStory();
		system("cls");
		menual();
	}
	if (LoadSuccess == true)
	{
		inHouse = 1;
	}
	system("cls");
	if (inHouse == 0)
	{
		Create_Map();
		Nocursor();
	}
	else if (inHouse == 1)
	{
		Create_house();
		Nocursor();
	}
	while (1)
	{
		fflush(stdin);
		Sleep(70);                             // 게임 레이팅
		character->ptState();
		if (kbhit()) {                         // 키보드 입력이 있으면
			ch = getch();                      // 키보드 입력받음
			if(inHouse==0)
				MoveCharacter(character, ch);       // 키보드 입력 함수로 보냄
			else
				houseMoveCharacter(character, ch);
		}
		if (cnt % 200 == 0) {                  // 시간 비율
			gotoxy(72, 3);
			printf("  %d 일차  ━━  %d : %d    ",Day, Hour, Min++);

		}
		if (Night == 1 && OMG2 == 1)
		{
			MoveCharacter(character, '0');
			OMG2 = 0;
		}
		character->settime();

		error = Die_Check(character);
		if (error == 1)
			break;
		if (error == 2)
		{
			Create_house();
			inHouse = 1;
		}
		if (ending_count == 1)
			break;
		//else
		//	continue;
		//cnt++;
		if (OMG == 1)
		{
			system("cls");
			Create_Map();
			OMG = 0;
		}
	}
	if (ending_count == 1)
	{
		Ending_Story();
	}
	return;
}

void Load()
{
	ifstream load("SAVE.dll");
	if (load.is_open() == false)
	{
		system("cls");
		gotoxy(40, 14);
		cout << "SAVE.dll 파일이 없습니다." << endl;
		LoadSuccess = false;
		gotoxy(40, 16);
		system("pause");
		return;
	}
	while (load.eof() != true)
	{
		load >> DB.name >> look >> DB.stress >> DB.hungry >> DB.money >> DB.sum >> DB.Hour >> DB.Min >> DB.Day >> DB.Account;
		if (((look + DB.stress + DB.hungry + DB.money) / 35) != DB.sum)
		{
			system("cls");
			gotoxy(40, 14);
			cout << "해킹이 감지되었습니다" << endl;
			Hack_count = 1;
			return;
		}
		LoadSuccess = true;
	}
}

void Security()
{
	system("del SAVE.dll");
}