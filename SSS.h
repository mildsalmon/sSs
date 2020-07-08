#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "Minigame.h"

using namespace std;

typedef struct LoadData {
	char name[20];
	int stress;
	int hungry;
	int money;
	int sum;
	int Hour;
	int Min;
	int Day;
	int Account;
};

int ending_count = 0;
int look=4; // 캐릭터 외형
boolean Night = 1; // 시간이 밤인지?
int cnt = 0;				// 시간
int Hour = 5, Min = 10, Day = 0;		// 시간
int OMG = 0;
int OMG2 = 0;

int value1=100;			// 수면스트레스 상승치
int value2=2;			// 먹기 허기 상승치

#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)	// 하얀색
#define FOREGROUND_PINK (FOREGROUND_RED | FOREGROUND_BLUE)						// 핑크색
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN)					// 노랑색
#define FOREGROUND_SKY (FOREGROUND_BLUE | FOREGROUND_GREEN)						// 하늘색
#define basicX 15
#define basicY 7

class Character;
//void House(Character *character);
//void House_Eat(Character *character);
//void House_Sleep(Character *character);
//void House_Play(Character *character);
//void Company();
//void Company_Eat();
//void Company_Work();
//void SSK();
void Event();
void Event_NaturalDisasters();
void Event_Burglar();
void Die_Check();
void Ending_Check();
void gotoxy(int x, int y);
void Setcursor();
void Nocursor();
void gotopt(int x, int y, char c[102]);
void Load();
void cls1();
void Create_Map();
void Create_house();
//void ptState(Character *character);
void MoveCharacter(Character *character, char ch);
void houseMoveCharacter(Character *character, char ch);
void title();
void choose1();
char *makeINFO2();
void showStory();
void Ending();
int Menu_Choice_S(int y);
int Menu_Choice_W(int y);
int Die(Character *character);
int Die_Check(Character *character);
void checktime();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////클래스 선언부///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Character {
protected:
	int exp;					// 소득분위
	int Max_exp;				// 경험치 맥스량
	int money;					// 자금 (달러)
	int hungry;					// 허기
	int Max_hungry;				// 허기 맥스
	int stress;					// 스트레스
	int Max_stress;				// 스트레스 맥스
	int level;					// 레벨
	char name[100];				// 이름
	int Account;				// 은행 계좌

public:
	//	int Fatigue_Check()
	//{
	//	return this->fatigue;
	//}

	int Stress_Down()
	{
		return this->stress = this->stress - 5;
	}
	int Stress_Check()
	{
		return this->stress;
	}
	int Hungry_Check()
	{
		return this->hungry;
	}
	int Hungry_Down()
	{
		return this->hungry = this->hungry - 1;
	}
	void Hungry_Max()
	{
		this->hungry = this->Max_hungry;
		return;
	}
	int Money_Check()
	{
		return this->money;
	}
	int Money_Half()
	{
		return this->money = this->money / 2;
	}

	//virtual void House_Eat() = 0;
	//virtual void House_Sleep() = 0;
	//virtual void House_Play() = 0;

	//virtual void Company_Jipge() = 0;
	//virtual void Company_Work() = 0;
	virtual void Ending_Check() = 0;

	//virtual void SSK_Alcohol() = 0;
	//virtual void SSK_KTandG() = 0;
	//virtual void SSK_Lotto() = 0;

	int Exp_Level()
	{
		if (this->money+Account >= 0 && this->money+Account <= 100)
			return 0;
		if (this->money+Account > 100 && this->money+Account <= 300)
			return 1;
		if (this->money+Account > 300 && this->money+Account <= 500)
			return 2;
		if (this->money+Account > 500 && this->money+Account <= 1000)
			return 3;
		if (this->money+Account > 1000 && this->money+Account <= 5000)
			return 4;
		if (this->money+Account > 5000 && this->money+Account <= 10000)
			return 5;
		if (this->money+Account > 10000 && this->money+Account <= 40000)
			return 6;
		if (this->money+Account > 40000 && this->money+Account <= 70000)
			return 7;
		if (this->money+Account > 70000 && this->money+Account <= 90000)
			return 8;
		if (this->money+Account > 90000 && this->money+Account <= 100000)
			return 9;
		if (this->money+Account > 100000 && this->money+Account <= 10000000)
			return 10;
	}

	void House_Eat()				// 무료 밥먹기 함수
	{
		gotoxy(40, 11);
		printf("배고픔이 %d 만큼 증가하였습니다.",value2);
		hungry = hungry + value2;
		Min = Min + 20;												///////////////////////
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void House_Sleep()				// 잠자기 함수
	{
		//gotopt(78, 11, "피로도가 100 만큼 올라갔습니다.");
		//fatigue = fatigue + 100;
		gotoxy(40, 11);
		printf("스트레스가 %d 만큼 올라갔습니다.", value1);
		stress = stress + value1;
		Hour = Hour + 7;											///////////////////////
		gotoxy(60, 13);
		system("pause");
		return;
	}

	//void House_Play()				// 놀기 함수
	//{
	//	if (money+Account < 100)
	//	{
	//		gotopt(60, 11, "소지 금액이 부족하여 놀 수 없습니다.");
	//		gotoxy(60, 13);
	//		system("pause");
	//		return;
	//	}
	//	//gotopt(78, 11, "피로도가 50 만큼 내려갔습니다.");
	//	//fatigue = fatigue - 50;
	//	gotopt(78, 11, "100$를 지불하였습니다.");
	//	gotopt(78, 13, "스트레스가 50 만큼 증가하였습니다.");
	//	stress = stress + 50;
	//	money = money - 100;											///////////////////////
	//	gotoxy(60, 16);
	//	system("pause");
	//	return;
	//}

	void Computer_Play()
	{
		int i;
		system("cls");
		system("color 9E");
		char booting[12] = "boot.....";
		char command[20];												//사용자 명령어
		int gaga;
		int count = 0;
		string command_st;

		for (i = 0; booting[i]; i++) {
			printf("%c", booting[i]);									//부팅하는 애니메이션
			Sleep(200);
		}

		system("cls");
		printf("SSSsoft VIKINIos [Version 17.a.00004]\n");
		printf("(c) 2017 SSSsoft Corporation. All rights reserved.\n");	//cmd 따라한거임
		Setcursor();
		while (1) {
			printf("C:\\user\\%s>", this->name);
			cin.getline(command, 20);							//이후에 필요한 명령어는 else if로 추가하면됨
			command_st = command;						//이후에 필요한 명령어는 else if로 추가하면됨
			if (strcmp(command, "help") == 0)
			{
				printf("iotservice   \t사물인터넷 서비스를 이용합니다.\n");
				printf("ipconfig     \t컴퓨터의 ip를 확인합니다.\n");
				printf("time         \t현재 시간을 확인합니다.\n");
				printf("color        \t콘솔의 기본색과 배경색을 설정합니다.\n");
				printf("game         \t게임을 플레이 합니다.\n");
				printf("save-all     \t데이터를 저장합니다.\n");
				printf("update       \t비키니os를 최신버전으로 업데이트 합니다.\n");
				printf("exit         \t종료합니다.\n");
			}
			else if (strcmp(command, "iotservice") == 0)
			{
				printf("\n<< 사물인터넷 서비스 >>\n");
				printf(":: 1.냉장고 업그레이드 (100$)\n");
				printf(":: 2.침대 매트리스 업그레이드 (200$)\n");
				printf(":: 더 나은 서비스 준비중\n");
				printf("고객님이 이용할 서비스를 선택하세요 :");
				int select=0;
				scanf("%d", &select);
				switch (select) {
				case 1:
					if (money >= 100) {
						printf("\n냉장고를 업그레이드 하셨습니다.\n");
						printf("곧 물품이 도착합니다.\n");
						printf("이용해 주셔서 감사합니다.\n\n");
						money -= 100;
						value2++;
					}
					else
						printf("\n고객님의 잔고가 부족한것 같습니다\n\n");
					break;
				case 2:
					if (money >= 200) {
						printf("\n침대 매트리스를 업그레이드 하셨습니다.\n");
						printf("곧 물품이 도착합니다.\n");
						printf("이용해 주셔서 감사합니다.\n\n");
						money -= 200;
						value1 += 100;
					}
					else
						printf("\n고객님의 잔고가 부족한것 같습니다\n\n");
					break;
				default :
					printf("\n해당 서비스는 존재하지 않습니다.\n\n");
					break;
				}
			}
			else if (strcmp(command, "ipconfig") == 0)
			{
				printf("\nVikini IP 구성\n\n");
				printf("이더넷 어댑터 이더넷:\n");
				printf("   IPv6 주소 . . . :ed10::1434:e13d:19e3:a22e\%13\n");
				printf("   미디어 상태 . . . . . . . . : 미디어 연결 끊김\n\n");
			}
			else if (strcmp(command, "time") == 0)
			{
				printf("\n현재시간 %d시 %d분 입니다.\n\n", Hour, Min);
			}
			else if (strcmp(command, "save-all") == 0)
			{
				printf("\n::: %s님의 데이터 :::\n", this->name);
				printf("  스트레스 : %d \t. . . 배고픔 : %d\n", stress,hungry);
				printf("  계좌잔액 : %d \t. . . 소지금 : %d\n", Account,money);
				Save();
				printf("성공적으로 저장되었습니다.\n\n");
			}
			else if (strcmp(command, "update") == 0) 
			{
				printf("\n이미 최신버전을 이용하는 중입니다.\n\n");
			}
			else if (strcmp(command, "exit") == 0)
			{
				if (Night == 0)
					system("color F0");
				else
					system("color 0F");
				Nocursor();
				return;
			}
			else if (command_st.find("color") != string::npos)
			{
				if (strcmp(command, "color") == 0)
				{
					printf("color help를 입력하면 사용법이 나옵니다.\n");
				}
				else if (strcmp(command, "color help") == 0)
				{
					printf("콘솔의 기본 전경색과 배경색을 설정합니다.\n\n");
					printf("COLOR[attr]\n\n");
					printf("	attr        콘솔 출력의 색 특성을 지정합니다.\n");
					printf("색 특성은 두 자리의 16진수로 지정됩니다.첫째 자리는\n");
					printf("배경색에 해당하고 둘째 자리는 전경색에 해당합니다.각 자리는\n");
					printf("다음 값이 될 수 있습니다.\n\n");
					printf("	0 = 검은색     8 = 회색\n");
					printf("	1 = 파란색     9 = 연한 파란색\n");
					printf("	2 = 녹색       A = 연한 녹색\n");
					printf("	3 = 청록색     B = 연한 청록색\n");
					printf("	4 = 빨간색     C = 연한 빨간색\n");
					printf("	5 = 자주색     D = 연한 자주색\n");
					printf("	6 = 노란색     E = 연한 노란색\n");
					printf("	7 = 흰색       F = 밝은 흰색\n\n");
					printf("인수가 지정되지 않으면 이 명령은 CMD.EXE가 시작되었을 때의\n");
					printf("색을 복원합니다.이 값은 현재 콘솔 창에서 가져오거나\n");
					printf("/ T 명령줄 스위치나 레지스트리 값에서\n");
					printf("가져옵니다.\n\n");
					printf("전경색과 배경을 같게 지정하여 COLOR 명령을 실행하려고 할 경우\n");
					printf("COLOR 명령은 ERRORLEVEL을 1로\n");
					printf("설정합니다.\n\n");
					printf("예를 들면 \"COLOR fc\"는 밝은 흰색 위에 연한 빨간색을 생성합니다.\n\n");
					//	cin >> color_input1 >> color_input2;
				}
				else if (command_st.size() == 8)
				{
					char cmd[64];
					char color1 = command_st.at(6), color2 = command_st.at(7);
					snprintf(cmd, sizeof(cmd), "color %c%c", color1, color2) > 0 && system(cmd);
					system("cmd");		// 해당 명령어는 해당 OS 즉 윈도우의 콘솔 cmd를 띄웁니다 ㅋ
										//color_wow[7] = command_st.at(7);
										//color_wow[8] = command_st.at(8);
										//system("color color_wow");
										//system("command_st");
				}
			}
			else if ((strcmp(command, "game") == 0))
			{
				printf("플레이할 게임을 선택해주세요.\n");
				printf("가위바위보 ①번, 사칙연산 ②번, 야구게임 ③번, 사다리타기 ④번\n");
				cout << " : ";
				cin >> gaga;
				switch (gaga)
				{
				case 1:
					this->money = this->money + (this->money * RPS());
					break;

				case 2:

					count = cell(1);
					if (count == 0)
					{
						break;
					}
					this->money = this->money + (this->money * count);
					break;

				case 3:
					baseball();
					break;

				case 4:
					printf("구현중입니다.");
					break;
				}
			}

			/////임시 치트키/////
			else if (strcmp(command, "show_me_the_money") == 0)
			{
				printf("\n치트키 발동 ::: 1000$ 증가.\n\n");
				money += 1000;
			}
			else if (strcmp(command, "im_hungry!!!") == 0)
			{
				printf("\n치트키 발동 ::: 냉장고 허기 상승치 100증가\n\n");
				value2 += 100;
			}
			else if (strcmp(command, "bed_is_science") == 0)
			{
				printf("\n치트키 발동 ::: 침대 스트레스 상승치 1000증가\n\n");
				value1 += 1000;
			}
			else
			{
				printf("알수없는 명령어 입니다. \"help\"로 도움말을 볼 수 있습니다.\n");
			}
		}
	}

	void Company_Jipge()
	{
		if (money >= 5) {
			gotopt(60, 11, "5$를 지불하였습니다.");
			gotopt(60, 13, "허기가 30 만큼 증가하였습니다.");
			money -= 5;
			hungry += 30;
			Min = Min + 20;											///////////////////////
		}
		else {
			gotopt(60, 11, "집게버거는 5$입니다.");
			gotopt(60, 13, "잔고를 확인해 보세요.");
		}
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void Company_Work()
	{
		if (stress >= 500) {
			gotopt(60, 11, "500 스트레스를 소모하고 100$를 벌었습니다.");
			money += 100;
			stress -= 500;
			Hour = Hour + 10;											///////////////////////
		}
		else {
			gotopt(60, 11, " 피로도가 모자랍니다.");
			gotopt(60, 13, "집에서 쉬었다가 오세요.");
		}
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void SSK_Alcohol()
	{
		if (money >= 5) {
			gotopt(60, 11, "5$를 소진하고 스트레스가 20 감소했습니다");
			money -= 5;
			stress -= 20;
			Hour = Hour + 2;											///////////////////////
		}
		else {
			gotopt(60, 11, "술은 5$입니다.");
			gotopt(60, 13, "잔고를 확인해보세요.");
		}                          //술을 샀을 때의 효과
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void SSK_KTandG()
	{
		if (money >= 5) {
			gotopt(60, 11, "5$를 소진하고 스트레스가 20 감소했습니다.");
			money -= 5;
			stress -= 20;
			Min = Min + 10;											///////////////////////
		}
		else {
			gotopt(60, 11, "담배는 5$입니다.");
			gotopt(60, 13, "잔고를 확인해보세요.");
		}					//담배를 샀을때의 효과
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void SSK_Lotto()
	{
		int LottoResult = 1;
		srand(time(NULL));

		if (money >= 100) {
			money -= 100;
			gotopt(60, 11, "100$를 소진하고 로또추첨을 시작합니다.");
			Sleep(2000);
			system("cls");
			gotopt(60, 11, "두구두구두구두구");
			Sleep(2000);
			LottoResult = rand() % 100;                      
			if ((LottoResult % 50) == (rand() % 10)) {
				system("cls");
				gotopt(60, 11, "당첨되셨습니다!!!! 축하드립니다!!!!");
				money *= 2;
				stress += 30;
			}
			else {
				system("cls");
				gotopt(60, 11, "에휴... 꽝이네");
			}
		}
		else {
			gotopt(60, 11, "돈이 부족합니다.");
		}               //로또를 샀을때의 효과
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void Bank_Deposit()
	{
		int temp = 0;

		gotopt(60, 10, "입금할 금액을 입력해주세요 :");
		cin >> temp;
		if (temp > money)
		{
			system("cls");
			gotopt(60, 10, "입력하신 금액이 고객님이 가지고 계신 금액보다 큼니다");
		}
		else {
			system("cls");
			gotopt(60, 10, "입금되셨습니다.");
			Account = Account + temp;
			money = money - temp;
		}
		gotoxy(60, 13);
		system("pause");
		return;
	}
	void Bank_Withdraw()
	{
		int temp = 0;

		gotopt(60, 10, "출금할 금액을 입력해주세요 :");
		cin >> temp;
		if (temp > Account)
		{
			system("cls");
			gotopt(60, 10, "입력하신 금액이 고객님의 잔고 금액보다 큼니다");
		}
		else {
			system("cls");
			gotopt(60, 10, "출금되셨습니다.");
			money = money + temp;
			Account = Account - temp;
		}
		gotoxy(60, 13);
		system("pause");
		return;
	}
	void Bank_Remittance()
	{
		system("cls");
		gotopt(60, 10, "테스트 중인 기능입니다.");
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void ptState()
	{

		//if ((fatigue + 3) % 10 == 0)
		//	hungry--;
		//if ((fatigue + 6) % 10 == 0)
		//	hungry--;
		//if ((fatigue + 9) % 10 == 0)
		//	hungry--;

		if (this->hungry >= this->Max_hungry)
		{
			this->hungry = this->Max_hungry;
		}
		if (this->stress >= this->Max_stress)
		{
			this->stress = this->Max_stress;
		}
		if (this->exp >= this->Max_exp)
		{
			this->level = this->level + 1;
			this->exp = this->exp - this->Max_exp;
			if (this->level < 11)
			{
				this->Max_exp = this->Max_exp + 10;
			}
			else if (this->level < 101)
			{
				this->Max_exp = this->Max_exp + 100;
			}
		}

		gotoxy(15, 3);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		//gotoxy(15, 4);
		//printf("┃");
		//gotoxy(15, 5);
		//printf("┃");
		//gotoxy(15, 6);
		//printf("┃");
		//gotoxy(100, 4);
		//printf("┃");
		//gotoxy(100, 5);
		//printf("┃");
		//gotoxy(100, 6);
		//printf("┃");
		gotoxy(17, 4);
		printf("이름     : %s          ", name);
		gotoxy(45, 4);
		//printf("피로도   : %d / %d     ", fatigue, Max_fatigue);
		gotoxy(17, 5);
		////printf("레벨     : %d          ", level);
		gotoxy(75, 5);
		printf("계좌     : %d $", Account);
		gotoxy(45, 5);
		printf("배고픔   : %d / %d     ", hungry, Max_hungry);
		gotoxy(17, 6);
		printf("소득분위   : %d분위     ", Exp_Level());
		gotoxy(45, 6);
		printf("스트레스 : %d / %d     ", stress, Max_stress);
		gotoxy(75, 6);
		printf("소지금   : %d $", money);
		gotoxy(15, 7);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	}

	void Save()
	{
		ofstream save("SAVE.dll", ios::trunc);
		//money += Account;
		save << name << "\t\t" << look << "\t\t" << stress << "\t\t" << hungry << "\t\t" << money << "\t\t" << (look + stress + hungry + money) / 35 << "\t\t" << Hour << "\t\t" << Min << "\t\t" << Day << "\t\t" << Account;
		//money -= Account;
		save.close();
	}



	void statusLoad(int str, char *c, int hun, int mon, int hour, int min, int day, int acc) {
		stress = str;
		strcpy(name, c);
		hungry = hun;
		money = mon;
		Hour = hour;
		Min = min;
		Day = day;
		Account = acc;
	}

	void makeINFO2() {
		int x = 44, y = 17;
		int temp1;
		//	char *name = new char;

		gotopt(x, ++y, "   캐릭터의 이름을 정하세요.");
		gotopt(x, ++y, "┌─────────────┐");
		gotopt(x, ++y, "│                          │"); temp1 = y;
		gotopt(x, ++y, "└─────────────┘");
		Setcursor();
		gotoxy(x + 6, temp1);
		cin >> this->name;
		Nocursor();
	}

	void settime() {
		if (Min >= 60) {
			Min -= 60;
			Hour++;
			this->hungry = this->hungry - 1;
		}
		if (Hour >= 24) {
			Day = Day + 1;
			Hour -= 24;
			this->Account = this->Account + (this->Account * 0.001);
		}
		checktime();
	}

	void checktime() {
		if (Hour > 5 && Hour < 19) {
			if (Night == 1)
				system("color F0");
			Night = 0;
		}
		else {
			if (Night == 0)
			{
				system("color 0F");
				OMG2 = 1;
			}
			Night = 1;
		}
	}
};

class Normal_Spongebob : public Character		// 노말 스폰지밥
{
public:
	Normal_Spongebob()
	{
		exp = 0;						// 노말 스폰지밥 초기 경험치 = 0
		Max_exp = 10;					// 노말 스폰지밥 초기 경험치 맥스량 = 10
		money = 0;						// 노말 스폰지밥 초기 자금 = 0
		hungry = 100;					// 노말 스폰지밥 초기 배고픔지수 = 100
		Max_hungry = 100;				// 노 허기 맥스
		stress = 1000;						// 노말 스폰지밥 초기 스트레스 = 0
		Max_stress = 1000;
		level = 0;						// 노말 스폰지밥 초기 레벨 = 0
		Account = 0;						
	}

	void Ending_Check()
	{
		if (money >= 1000000)
		{
			gotopt(60, 11, "엔딩을 진행하시겠습니까?");
			gotopt(60, 13, "Yes (y) or No (n)");
			char ch = _getch();
			if (ch == 'y')
			{
				system("cls");
				ending_count = 1;
			}
			else if (ch == 'n') {
				system("cls");
				gotopt(60, 11, "진주 : ㅋ 쪼다");
			}
			else
			{
				system("cls");
				gotopt(60, 11, "잘못누르셨습니다");
			}
		}
		else {
			system("cls");
			gotopt(60, 11, "진주 : 뭐하냐?");
			gotopt(60, 15, "진주사장님에게");
			gotopt(60, 17, "자금을 몰수당하셨습니다");
			money = 0;
			getch();
			system("cls");
			gotopt(60, 11, "진주 :");
			gotopt(60, 13, "감히 내 가게를 넘봐?");
			gotopt(60, 15, "스폰지밥 넌 내 노예야 !");
			gotoxy(60, 19);
			system("pause");
			stress = stress + 500;
			exp = exp + (Max_exp / 2);
		}
		return;
	}
};

//class Hard_Spongebob : public Character		// 하드 스폰지밥
//{
//public:
//	Hard_Spongebob(char *Input_name)
//	{
//		exp = 0;						// 하드 스폰지밥 초기 경험치 = 0
//		Max_exp = 10;					// 하드 스폰지밥 초기 경험치 맥스량 = 10
//		money = 0;						// 하드 스폰지밥 초기 자금 = 0
//		hungry = 100;					// 하드 스폰지밥 초기 배고픔지수 = 100
//		fatigue = 1000;					// 하드 스폰지밥 초기 피로도 = 1000
//		stress = 0;						// 하드 스폰지밥 초기 스트레스 = 1000
//		level = 0;						// 하드 스폰지밥 초기 레벨 = 0
//		this->name[0] = *Input_name;	// 하드 스폰지밥 이름 설정
//	}
//};

class Normal_Star : public Character			// 노말 뚱이
{
public:
	Normal_Star()
	{
		exp = 0;						// 노말 뚱이 초기 경험치 = 0
		Max_exp = 5;					// 노말 뚱이 초기 경험치 맥스량 = 5
		money = 0;						// 노말 뚱이 초기 자금 = 0
		hungry = 80;					// 노말 뚱이 초기 배고픔지수 = 80
		Max_hungry = 80;
		stress = 2000;						// 노말 뚱이 초기 스트레스 = 2000
		Max_stress = 2000;
		level = 0;						// 노말 뚱이 초기 레벨 = 0
		Account = 0;
	}

	void Ending_Check()
	{
		if (money >= 1000000)
		{
			gotopt(60, 11, "엔딩을 진행하시겠습니까?");
			gotopt(60, 13, "Yes (y) or No (n)");
			char ch = _getch();
			if (ch == 'y')
			{
				system("cls");
				ending_count = 1;
			}
			else if (ch == 'n') {
				system("cls");
				gotopt(60, 11, "진주 : ㅋ 쪼다");
			}
			else
			{
				system("cls");
				gotopt(60, 11, "잘못누르셨습니다");
			}
		}
		else {
			system("cls");
			gotopt(60, 11, "진주 : 뭐하냐?");
			gotopt(60, 15, "진주사장님에게");
			gotopt(60, 17, "자금을 몰수당하셨습니다");
			money = 0;
			getch();
			system("cls");
			gotopt(60, 11, "진주 :");
			gotopt(60, 13, "감히 내 가게를 넘봐?");
			gotopt(60, 15, "스폰지밥 넌 내 노예야 !");
			stress = stress + 500;
			exp = exp + (Max_exp / 2);
		}
		return;
	}
};

//class Hard_Star : public Character			// 하드 뚱이
//{
//public:
//	Hard_Star(char *Input_name)
//	{
//		exp = 0;						// 하드 뚱이 초기 경험치 = 0
//		Max_exp = 5;					// 하드 뚱이 초기 경험치 맥스량 = 5
//		money = 0;						// 하드 뚱이 초기 자금 = 0
//		hungry = 80;					// 하드 뚱이 초기 배고픔지수 = 80
//		fatigue = 800;					// 하드 뚱이 초기 피로도 = 800
//		stress = 0;						// 하드 뚱이 초기 스트레스 = 2000
//		level = 0;						// 하드 뚱이 초기 레벨 = 0
//		this->name[0] = *Input_name;	// 하드 뚱이 이름 설정
//	}
//};

class Normal_Squidward : public Character		// 노말 징징이
{
public:
	Normal_Squidward()
	{
		exp = 0;						// 노말 징징이 초기 경험치 = 0
		Max_exp = 15;					// 노말 징징이 초기 경험치 맥스량 = 15
		money = 100;					// 노말 징징이 초기 자금 = 100
		hungry = 80;					// 노말 징징이 초기 배고픔지수 = 80
		Max_hungry = 80;
		stress = 800;						// 노말 징징이 초기 스트레스 = 800
		Max_stress = 800;
		level = 0;						// 노말 징징이 초기 레벨 = 0
		Account = 0;
	}

	void Ending_Check()
	{
		if (money >= 1000000)
		{
			gotopt(60, 11, "엔딩을 진행하시겠습니까?");
			gotopt(60, 13, "Yes (y) or No (n)");
			char ch = _getch();
			if (ch == 'y')
			{
				system("cls");
				ending_count = 1;
			}
			else if (ch == 'n') {
				system("cls");
				gotopt(60, 11, "진주 : ㅋ 쪼다");
			}
			else
			{
				system("cls");
				gotopt(60, 11, "잘못누르셨습니다");
			}
		}
		else {
			system("cls");
			gotopt(60, 11, "진주 : 뭐하냐?");
			gotopt(60, 15, "진주사장님에게");
			gotopt(60, 17, "자금을 몰수당하셨습니다");
			money = 0;
			getch();
			system("cls");
			gotopt(60, 11, "진주 :");
			gotopt(60, 13, "감히 내 가게를 넘봐?");
			gotopt(60, 15, "스폰지밥 넌 내 노예야 !");
			stress = stress + 500;
			exp = exp + (Max_exp / 2);
		}
		return;
	}
};

//class Hard_Squidward : public Character		// 하드 징징이
//{
//public:
//	Hard_Squidward(char *Input_name)
//	{
//		exp = 0;						// 하드 징징이 초기 경험치 = 0
//		Max_exp = 15;					// 하드 징징이 초기 경험치 맥스량 = 15
//		money = 100;					// 하드 징징이 초기 자금 = 100
//		hungry = 80;					// 하드 징징이 초기 배고픔지수 = 80
//		fatigue = 800;					// 하드 징징이 초기 피로도 = 800
//		stress = 0;						// 하드 징징이 초기 스트레스 = 800
//		level = 0;						// 하드 징징이 초기 레벨 = 0
//		this->name[0] = *Input_name;	// 하드 징징이 이름 설정
//	}
//};

// 하드 (1) 노말 (0) && 스징뚱


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////함수 구현부////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///		부모 클래스의 멤버 함수로 변경

//void House(Character *character)		// 집 함수
//{
//	int y = 10;
//	system("cls");
//	gotopt(60, 10, "밥먹기");
//	gotopt(60, 13, "잠자기");
//	gotopt(60	, 16, " 놀기 ");
//	gotopt(56, y, "▷");
//	char ch;
//	while (1)
//	{
//		ch = _getch();
//		switch (ch) {
//		case 'w':
//			y = Menu_Choice_W(y);
//			break;
//
//		case 's':
//			y = Menu_Choice_S(y);
//			break;
//
//		case 'f':
//			if (y == 10) {
//				system("cls");
//				character->House_Eat();
//				OMG = 1;
//				return;
//			}
//			else if (y == 13) {
//				system("cls");
//				character->House_Sleep();
//				character->Save();
//				OMG = 1;
//				return;
//			}
//			else if (y == 16) {
//				system("cls");
//				character->House_Play();
//				OMG = 1;
//				return;
//			}
//			break;
//		}
//	}
//}

void Company(Character *character)			// 집게리아 함수
{
	int y = 10;
	system("cls");
	gotopt(60, 10, "손님으로 입장");
	gotopt(60, 13, "알바하러 입장");
	gotopt(60, 16, "집게리아 인수");
	gotopt(56, y, "▷");
	char ch;
	while (1) {
		ch = _getch();
		switch (ch) {
		case 'w':
			y = Menu_Choice_W(y);
			break;

		case 's':
			y = Menu_Choice_S(y);
			break;

		case 'f':
			if (y == 10) {
				system("cls");
				character->Company_Jipge();
				OMG = 1;
				return;
			}
			else if (y == 13) {
				if (Hour > 5 && Hour < 19)												///////////////////////
				{
					system("cls");								///////////////////////											///////////////////////
					gotoxy(40, 16);														///////////////////////
					cout << "집게리아 계약서로 인해 밤에만 일할 수 있습니다." << endl;	///////////////////////
					gotoxy(60, 19);
					system("pause");
					OMG = 1;
					return;
				}
				else {					
					system("cls");
					character->Company_Work();
					OMG = 1;
					return;								///////////////////////
				}
			}
			else if (y == 16) {
				system("cls");
				character->Ending_Check();
				OMG = 1;
				return;
			}
			break;
		}
	}
}

void SSK(Character *character)			// 슈퍼마켓  함수							// 미완성
{
		int y = 10;
		//int LottoResult; //난수저장변수
		//int i; /////////////////////////////////////////for문 돌리는 변수
		system("cls");
		gotopt(60, 10, "술 (가격 : 5$)");
		gotopt(60, 13, "담배 (가격 : 5$)");
		gotopt(60, 16, "로또 (가격 : 100$)");
		gotopt(56, y, "▷");
		char ch;
		while (1) {
			ch = _getch();
			switch (ch) {
			case 'w':
				y = Menu_Choice_W(y);
				break;

			case 's':
				y = Menu_Choice_S(y);
				break;

			case 'f':
				if (y == 10) {
					system("cls");
					character->SSK_Alcohol();
					OMG = 1;
					return;
				}
				else if (y == 13) {
					system("cls");
					character->SSK_KTandG();
					OMG = 1;
					return;
				}
				else if (y == 16) {
					system("cls");
					character->SSK_Lotto();
					OMG = 1;
					return;
				}
				break;
		}
	}
}

void Bank(Character *character)		// 은행 함수
{
	int y = 10;
	system("cls");
	gotopt(60, 10, "입금하기");
	gotopt(60, 13, "출금하기");
	gotopt(60, 16, "송금하기");
	gotopt(56, y, "▷");
	char ch;
	while (1)
	{
		ch = _getch();
		switch (ch) {
		case 'w':
			y = Menu_Choice_W(y);
			break;

		case 's':
			y = Menu_Choice_S(y);
			break;

		case 'f':
			if (y == 10) {
				system("cls");
				character->Bank_Deposit();
				OMG = 1;
				return;
			}
			else if (y == 13) {
				system("cls");
				character->Bank_Withdraw();
				OMG = 1;
				return;
			}
			else if (y == 16) {
				system("cls");
				character->Bank_Remittance();
				OMG = 1;
				return;
			}
			break;
		}
	}
}

int Menu_Choice_W(int y)			// 메뉴창에서 W를 눌렀을시 발생하는 액션 함수
{
	if (y == 10) {
		gotopt(56, y, "  ");
		y = y + 6;
		gotopt(56, y, "▷");
	}
	else if (y == 13) {
		gotopt(56, y, "  ");
		y = y - 3;
		gotopt(56, y, "▷");
	}
	else if (y == 16) {
		gotopt(56, y, "  ");
		y = y - 3;
		gotopt(56, y, "▷");
	}
	return y;
}

int Menu_Choice_S(int y)			// 메뉴창에서 S를 눌렀을시 발생하는 액션 함수
{
	if (y == 10) {
		gotopt(56, y, "  ");
		y = y + 3;
		gotopt(56, y, "▷");
	}
	else if (y == 13) {
		gotopt(56, y, "  ");
		y = y + 3;
		gotopt(56, y, "▷");
	}
	else if (y == 16) {
		gotopt(56, y, "  ");
		y = y - 6;
		gotopt(56, y, "▷");
	}
	return y;
}

//
//
//void Event()		// 이벤트 함수							// 미완성
//{
//	// While 문 안에 계쏙 증가하는 변수를 만들고 그 변수가 1000이 될 시 랜덤함수로 재해를 발생
//	Event_NaturalDisasters();
//	Event_Burglar();	// static
//}
//
//void Event_NaturalDisasters()	// 자연재해 함수							// 미완성
//{
//
//}
//
//void Event_Burglar()			// 강도 함수							// 미완성
//{
//
//}

int Die_Check(Character *character)			// 죽음 체크 함수							// 미완성
{
	int i;
	i = Die(character);
	return i;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////맵 구현부////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gotoxy(int x, int y)			// 해당 좌표에 콘솔 커서 이동
{
	COORD Pos = { x ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Setcursor()
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}


void Nocursor()						// 
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotopt(int x, int y, char c[102])		// 좌표, 출력 ( 해당 좌표로 이동 후 출력 )
{
	gotoxy(x, y);
	printf("%s", c);
}

void cls1() {			// 특정 좌표 클리어
	int xz = 78; int yz = 8;
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
	gotopt(xz, yz++, "                     ");
}

//char map[21][44] = {							// 맵 구현 변수
//	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,5,0,0,0,0,6,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,2,0,4,4,4,4,4,4,4,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,2,0,4,4,4,4,4,4,4,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,2,0,4,4,4,0,4,4,4,0,0,0,0,0,4,4,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
//	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
//};

char map[21][44] = {							// 맵 구현 변수
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,5,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,2,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,2,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4,4,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,2,0,4,4,4,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

void Create_Map()			// 맵 배열 그래픽화
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 44; j++)
		{
			switch (map[i][j])
			{
			case 0:
				gotopt(basicX + j * 2, basicY + i, "　");
				break;
			case 1:
				gotopt(basicX + j * 2, basicY + i, "＃");
				break;
			case 2:
				gotopt(basicX + j * 2, basicY + i, "|");
				break;
			case 3:
				gotopt(basicX + j * 2, basicY + i, "♥");
				break;
			case 4:
				gotopt(basicX + j * 2, basicY + i, "▒");
				break;
			case 5:
				gotopt(basicX + j * 2, basicY + i, "\\");
				break;
			case 6:
				gotopt(basicX + j * 2, basicY + i, "㈜");
				break;
			case 7:
				gotopt(basicX + j * 2, basicY + i, "24");
				break;
			case 8:
				gotopt(basicX + j * 2, basicY + i, "$");
				break;
			}
		}
	}
	gotopt(39, 1, "<조작법> 위:w, 아래:s, 좌:a, 우:d, 선택:f");
}

const int houseX = 35;
const int houseY = 15;

char houseMap[11][24] = {							// 맵 구현 변수
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,5,0,0,0,0,1,0,7,0,1,0,0,0,4,0,0,0,1,3,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1 }
};

void Create_house()			// 맵 배열 그래픽화
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			switch (houseMap[i][j])
			{
			case 0:
				gotopt(houseX + j * 2, houseY + i, "　");
				break;
			case 1:
				gotopt(houseX + j * 2, houseY + i, "▒");
				break;
			case 2:
				gotopt(houseX + j * 2, houseY + i, "〓");
				break;
			case 3:
				gotopt(houseX + j * 2, houseY + i, "□");
				break;
			case 4:
				gotopt(houseX + j * 2, houseY + i, "▣");
				break;
			case 5:
				gotopt(houseX + j * 2, houseY + i, "▤");
				break;
			case 7:
				gotopt(houseX + j * 2, houseY + i, "▽");
				break;
			}
		}
	}
	gotopt(39, 1, "<조작법> 위:w, 아래:s, 좌:a, 우:d, 선택:f");
	gotopt(39, 10, "□ : 냉장고 , ▣ : 컴퓨터 , ▤ : 침대");
}

boolean inHouse = 0;

void MoveCharacter(Character *character,char ch)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static int x = 22;
	static int y = 10;
	static int posX = basicX + (x * 2);
	static int posY = basicY + y;
	static int hungry_check = 1;
	gotopt(posX, posY, "　");
	switch (ch) {
	case 'w':
		if (map[y - 1][x] == 0) {
			y--;
			posY--;
			character->Stress_Down();
			if (hungry_check % 4 == 0)
			{
				character->Hungry_Down();
				hungry_check = 0;
			}
		}
		break;
	case 's':
		if (map[y + 1][x] == 0) {
			y++;
			posY++;
			character->Stress_Down();
			if (hungry_check % 4 == 0)
			{
				character->Hungry_Down();
				hungry_check = 0;
			}
		}
		break;
	case 'a':
		if (map[y][x - 1] == 0) {
			x--;
			posX -= 2;
			character->Stress_Down();
			if (hungry_check % 4 == 0)
			{
				character->Hungry_Down();
				hungry_check = 0;
			}
		}
		break;
	case 'd':
		if (map[y][x + 1] == 0) {
			x++;
			posX += 2;
			character->Stress_Down();
			if (hungry_check % 4 == 0)
			{
				character->Hungry_Down();
				hungry_check = 0;
			}
		}
		break;
	}
	if (look == 0 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_YELLOW | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "■");
	}
	else if (look == 1 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_PINK | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "★");
	}
	else if (look == 2 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_SKY | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "▲");
	}
	if (look == 0 && Night == 0) {
		gotopt(posX, posY, "■");
	}
	else if (look == 1 && Night == 0) {
		gotopt(posX, posY, "★");
	}
	else if (look == 2 && Night == 0) {
		gotopt(posX, posY, "▲");
	}
	if (Night==1)
		SetConsoleTextAttribute(hOut, FOREGROUND_WHITE);


	hungry_check = hungry_check + 1;

	if (x == 13 && y == 7) {
		gotopt(x, y, "　");
		Company(character);
	}
	if (x == 31 && y == 6) {
		gotopt(x, y, "　");
		system("cls");
		inHouse = 1;
		Create_house();
	}
	if (x == 11 && y == 17) {
		gotopt(x, y, "  ");
		SSK(character);
	}
	if (x == 33 && y == 16)
	{
		gotopt(x, y, "  ");
		Bank(character);
	}
}

void houseMoveCharacter(Character *character, char ch)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static int x = 12;
	static int y = 8;
	static int posX = houseX + (x * 2);
	static int posY = houseY + y;
	static int hungry_check = 1;
	gotopt(posX, posY, "　");
	switch (ch) {
	case 'w':
		if (houseMap[y - 1][x] == 0) {
			y--;
			posY--;
		}
		break;
	case 's':
		if (houseMap[y + 1][x] == 0) {
			y++;
			posY++;
		}
		break;
	case 'a':
		if (houseMap[y][x - 1] == 0) {
			x--;
			posX -= 2;
		}
		break;
	case 'd':
		if (houseMap[y][x + 1] == 0) {
			x++;
			posX += 2;
		}
		break;
	case 'f':
		if (x == 1 && y == 2)				// 침대 상호작용
		{
			system("cls");
			character->House_Sleep();
			character->Save();
			system("cls");
			Create_house();
		}
		else if (x == 14 && y == 2)			// 컴퓨터 상호작용
		{
			system("cls");
			character->Computer_Play();
			system("cls");
			Create_house();
		}
		else if (x == 19 && y == 2)			// 냉장고 상호작용
		{
			system("cls");
			character->House_Eat();
			system("cls");
			Create_house();
		}
		else if (x == 12 && y == 9)			// 집에서 나가기
		{
			system("cls");
			Create_Map();
			inHouse = 0;
			return;
		}
	}
	if (look == 0 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_YELLOW | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "■");
	}
	else if (look == 1 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_PINK | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "★");
	}
	else if (look == 2 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_SKY | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "▲");
	}
	if (look == 0 && Night == 0) {
		gotopt(posX, posY, "■");
	}
	else if (look == 1 && Night == 0) {
		gotopt(posX, posY, "★");
	}
	else if (look == 2 && Night == 0) {
		gotopt(posX, posY, "▲");
	}
	if (Night == 1)
		SetConsoleTextAttribute(hOut, FOREGROUND_WHITE);


	hungry_check = hungry_check + 1;
}

void title() {
	gotopt(13, 12, "이 프로그램은 한라대학교 재학생[배재욱, 이지훈, 김학진, 신지웅]이 협업하여 제작된 게임입니다.");
	int x = 44; int y = 20;
	int temp1, temp2, choose, choose_back;
	gotopt(x, ++y, "┌─────────────┐");
	gotopt(x, ++y, "│                          │");
	gotopt(x + 10, y, "게임 시작"); temp1 = y;
	gotopt(x, ++y, "│                          │");
	gotopt(x, ++y, "│                          │");
	gotopt(x + 10, y, "게임 종료"); temp2 = y;
	gotopt(x, ++y, "└─────────────┘");
	gotopt(x - 5, y += 2, "<조작법> 위:w, 아래:s, 좌:a, 우:d, 선택:f");
	char ch;
	choose = temp1;
	while (1) {
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
				return;
			}
			if (choose == temp2) {
				exit(0);
			}
		}
		gotopt(x + 6, choose_back, "　");
	}
}

void showStory() {
	int x = 10, y = 5, l = 0; char findDot;
	char story[] = "지금으로부터 30년전, 비키니 시티에 사는 스폰지밥, 징징이, 뚱이는 열정페이와 4대 보험 미적용 등 각종 법을 당연하다는 듯이 무시하는 집게사장의 집게리아에서 노동을 착취당하고 있었다.	하루는 집게사장이 그들에게 이제 정직원으로 일할 때가 됐다며, 근로계약서를 작성하자고 하였다. 그들은 이제 집게사장님이 자기들을 인정해준다며 계약서의 앞부분만 빠르게 읽어보고 곧바로 싸인을 했다. 뚱이까지 싸인을 마치자 집게사장의 태도가 완전히 달라졌다.	그런 집게사장의 태도를 보고 징징이는 계약서 앞부분을 집게사장을 향하게 들고서는 자기들을 함부로 대하면 계약서 위반이라고 말했다. 뒤에서 징징이가 든 계약서를 보던 뚱이가 “원래 계약서 뒷면에도 글자가 써있는거야.스폰지밥 ? ” 이라고 말했다. 이 말을 들은 스폰지밥이 징징이가 든 계약서 양면에 적힌 글을 읽어나가는데, 그 내용은 이렇다. - 계약서 -. 주식회사 집게리아( 이하 “갑”이라 한다 )는 스폰지밥, 징징이, 뚱이( 이하 “을”이라 한다 )은 다음과 같이 근로계약을 체결한다. 단, “을”은 “갑”이 정한 할당량을 매일 채워야 하며, 이를 채우지 못할 시 벌금을 지불하거나 해당 일의 급여를 받지 않는 것을 원칙으로 한다.	...	- 뒷면 -.“을”은 “갑”에서 100년간 일해야 하며, 해당 기간을 채우지 못하고 생을 마감할 시에는 남은 기간만큼 “을”의 가족이 계약을 이행해야한다.“갑”은 집게리아를 소유한 사람을 뜻하며, 집게사장이 생을 마칠시에는 직계가족(즉, 건물주)이 해당 권리를 대신한다. “을”의 근무시간은 무조건 밤 ( 19시 ~ 06시 사이 ) 이다.	... 이 사건을 기준으로 15년뒤에 스폰지밥, 징징이, 뚱이는 비키니시티를 떠나 야반도주를 하게된다. 이 모습을 본 집게사장이 스폰지밥, 징징이, 뚱이의 정자로 수정시킨 당신을 탄생시킨다.	당신은 그 어떤 권리도 없이 집게리아에서 85년동안 일을 해야하는 상황인데. 당신이 자유가 될 방법은 집게리아를 인수하는 방법뿐.";
	char ch;

	gotopt(40, 3, "게임 스토리 생략은 'p' 키를 눌러주세요.");

	for (int i = 0; story[i]; i++) {
		if (_kbhit())
		{
			ch = getch();
			if (ch == 'p' || ch == 'P')
			{
				for (; story[i]; i++)
				{
					findDot = story[i];
					switch (findDot)
					{
					case '.':
						l++;
						break;
					case ',':
						l++;
						break;
					case ' ':
						l++;
						break;
					}
					gotoxy(x + l, y);
					cout << findDot;
					switch (findDot)
					{
					case ' ':
						break;
					case '.':
						l = 0;
						y += 2;
						break;
					default:
						l += 1;
						break;
					}
					if (l > 90) {
						l = 0;
						y += 2;
					}
				}
				break;
			}
		}
		findDot = story[i];
			switch (findDot)
			{
			case '.':
				l++;
				break;
			case ',':
				l++;
				break;
			case ' ':
				l++;
				break;
			}
			gotoxy(x + l, y);
			cout << findDot;
			switch (findDot)
			{
			case ' ':
				break;
			case '.':
				l = 0;
				y += 2;
				break;
			default:
				l += 1;
				break;
			}
			if (l > 90) {
				l = 0;
				y += 2;
			}
			Sleep(50);
	}
	cout << endl << endl << "\t\t\t\t\t";
	system("pause");
}

void Ending_Story()
{
	int x = 10, y = 5, l = 0; char findDot;
	char story[] = " ㅊㅊ. 이제 님이 사장임";
	for (int i = 0; story[i]; i++) {
		findDot = story[i];
		switch (findDot)
		{
		case '.':
			l++;
			break;
		case ',':
			l++;
			break;
		case ' ':
			l++;
			break;
		}
		gotoxy(x + l, y);
		printf("%c", findDot);
		switch (findDot)
		{
		case ' ':
			break;
		case '.':
			l = 0;
			y += 2;
			break;
		default:
			l += 1;
			break;
		}
		if (l > 90) {
			l = 0;
			y += 2;
		}
		Sleep(50);
	}

	gotoxy(38, 23);
	//system("pause");
}

void menual()
{
	int kaka = 0;
	bool bye = 1;

	while (bye)
	{
		system("cls");
		gotopt(56, 6, "- 메뉴얼 -");
		gotopt(42, 8, "오른쪽 상단 ♥ 표시된 장소는 집입니다.");
		gotopt(40, 10, "왼쪽 상단 ㈜ 표시된 장소는 집게리아입니다.");
		gotopt(40, 12, "왼쪽 하단 24 표시된 장소는 슈퍼마켓입니다.");
		gotopt(41, 14, "오른쪽 하단 $ 표시된 장소는 은행입니다.");
		gotopt(38, 16, "각 건물에 대한 설명은 아래 번호를 입력해주세요.");
		gotopt(30, 18, "집 ①번, 집게리아 ②번, 슈퍼마켓 ③번, 은행 ④번, 게임시작 ⑤번");
		gotoxy(58, 20);
		cout << " : ";
		cin >> kaka;
		switch (kaka) {
		case 1:
			system("cls");
			gotopt(30, 8, "'잠자기'를 선택하시면 데이터가 저장되고, 스트레스가 100 상승합니다.");
			gotopt(42, 10, "'밥먹기'를 선택하시면 배고픔이 2 상승합니다.");
			gotopt(32, 12, "'놀기'를 선택하시면 100$를 지불하고, 스트레스가 50 상승합니다.");
			gotoxy(46, 15);
			system("pause");
			break;
		case 2:
			system("cls");
			gotopt(20, 8, "집게리아에 들어가서 '손님으로 입장'을 선택하시면 5$를 지불하고, 허기가 30 상승합니다.");
			gotopt(15, 10, "집게리아에 들어가서 '알바하러 입장'을 선택하시면 스트레스가 500 하락하고, 100$를 지급받습니다.");
			gotopt(18, 12, "집게리아에 들어가서 '집게리아 인수'를 선택하시면 1000000$를 지불하고, 엔딩을 진행합니다.");
			gotoxy(45, 15);
			system("pause");
			break;
		case 3:
			system("cls");
			gotopt(23, 8, "슈퍼마켓에 들어가서 '술'를 선택하시면 5$를 지불하고, 스트레스가 20 상승합니다.");
			gotopt(22, 10, "슈퍼마켓에 들어가서 '담배'를 선택하시면 5$를 지불하고, 스트레스가 20 상승합니다.");
			gotopt(22, 12, "슈퍼마켓에 들어가서 '로또'를 선택하시면 100$를 지불하고, 로또 추첨을 진행합니다.");
			gotopt(17, 15, "확률은 50분의 1\t당첨시 소지금을 2배로 만들어드립니다.\t전 재산을 쏟아부으세요 ~ !!");
			gotoxy(45, 18);
			system("pause");
			break;
		case 4:
			system("cls");
			gotopt(29, 8, "은행에 들어가서 '입금하기'를 선택하시면 계좌에 돈을 입금합니다.");
			gotopt(28, 10, "은행에 들어가서 '출금하기'를 선택하시면 계좌에서 돈을 인출합니다.");
			gotopt(25, 12, "은행에 들어가서 '송금하기'를 선택하시면 다른 유저에게 돈을 송금합니다.");
			gotopt(34, 15, "하지만, '송금하기' 기능은 아직 테스트중인 기능입니다.");
			gotoxy(43, 18);
			system("pause");
			break;
		case 5:
			bye = 0;
			system("cls");
			gotopt(30, 8, "환상의 나라, 법이 없는 나라, 열정페이와 위법 계약서가 판을 치는 나라.");
			gotopt(43, 10, "비키니 시티에 오신것을 진심으로 환영합니다.");
			gotoxy(45, 13);
			system("pause");
			break;
		default:
			system("cls");
			kaka = 0;
			gotopt(53, 8, "잘못 누르셨습니다.");
			gotoxy(45, 13);
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			system("pause");
			continue;
		}
	}
}


int Die(Character *character)							
{
	if (character->Stress_Check() <= -100)
	{
		gotoxy(60, 13);
		cout << "과로사 하셨습니다" << endl;
		Sleep(2000);
		return 1;
	}
	if (character->Hungry_Check() <= 0)
	{
		system("cls");
		gotoxy(60, 13);
		cout << "배고픔이 0 이 되어 기절하셨습니다." << endl;
		Sleep(1000);
		system("cls");
		gotoxy(60, 13);
		cout << "길거리에서 기절하셔서 가진돈의 절반이 몰수됩니다." << endl;
		Sleep(1000);
		system("cls");
		gotoxy(60, 13);
		cout << "당신은 곧 깨어납니다. 아사하지 않도록 조심하십세요~." << endl;
		Sleep(1000);
		character->Hungry_Max();
		character->Money_Half();
		system("cls");
		return 2;
	}
	else
		return 0;
}


//시간관련