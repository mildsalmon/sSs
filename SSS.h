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
int look=4; // ĳ���� ����
boolean Night = 1; // �ð��� ������?
int cnt = 0;				// �ð�
int Hour = 5, Min = 10, Day = 0;		// �ð�
int OMG = 0;
int OMG2 = 0;

int value1=100;			// ���齺Ʈ���� ���ġ
int value2=2;			// �Ա� ��� ���ġ

#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)	// �Ͼ��
#define FOREGROUND_PINK (FOREGROUND_RED | FOREGROUND_BLUE)						// ��ũ��
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN)					// �����
#define FOREGROUND_SKY (FOREGROUND_BLUE | FOREGROUND_GREEN)						// �ϴû�
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
////////////////////////////////////////////////////Ŭ���� �����///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Character {
protected:
	int exp;					// �ҵ����
	int Max_exp;				// ����ġ �ƽ���
	int money;					// �ڱ� (�޷�)
	int hungry;					// ���
	int Max_hungry;				// ��� �ƽ�
	int stress;					// ��Ʈ����
	int Max_stress;				// ��Ʈ���� �ƽ�
	int level;					// ����
	char name[100];				// �̸�
	int Account;				// ���� ����

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

	void House_Eat()				// ���� ��Ա� �Լ�
	{
		gotoxy(40, 11);
		printf("������� %d ��ŭ �����Ͽ����ϴ�.",value2);
		hungry = hungry + value2;
		Min = Min + 20;												///////////////////////
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void House_Sleep()				// ���ڱ� �Լ�
	{
		//gotopt(78, 11, "�Ƿε��� 100 ��ŭ �ö󰬽��ϴ�.");
		//fatigue = fatigue + 100;
		gotoxy(40, 11);
		printf("��Ʈ������ %d ��ŭ �ö󰬽��ϴ�.", value1);
		stress = stress + value1;
		Hour = Hour + 7;											///////////////////////
		gotoxy(60, 13);
		system("pause");
		return;
	}

	//void House_Play()				// ��� �Լ�
	//{
	//	if (money+Account < 100)
	//	{
	//		gotopt(60, 11, "���� �ݾ��� �����Ͽ� �� �� �����ϴ�.");
	//		gotoxy(60, 13);
	//		system("pause");
	//		return;
	//	}
	//	//gotopt(78, 11, "�Ƿε��� 50 ��ŭ ���������ϴ�.");
	//	//fatigue = fatigue - 50;
	//	gotopt(78, 11, "100$�� �����Ͽ����ϴ�.");
	//	gotopt(78, 13, "��Ʈ������ 50 ��ŭ �����Ͽ����ϴ�.");
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
		char command[20];												//����� ��ɾ�
		int gaga;
		int count = 0;
		string command_st;

		for (i = 0; booting[i]; i++) {
			printf("%c", booting[i]);									//�����ϴ� �ִϸ��̼�
			Sleep(200);
		}

		system("cls");
		printf("SSSsoft VIKINIos [Version 17.a.00004]\n");
		printf("(c) 2017 SSSsoft Corporation. All rights reserved.\n");	//cmd �����Ѱ���
		Setcursor();
		while (1) {
			printf("C:\\user\\%s>", this->name);
			cin.getline(command, 20);							//���Ŀ� �ʿ��� ��ɾ�� else if�� �߰��ϸ��
			command_st = command;						//���Ŀ� �ʿ��� ��ɾ�� else if�� �߰��ϸ��
			if (strcmp(command, "help") == 0)
			{
				printf("iotservice   \t�繰���ͳ� ���񽺸� �̿��մϴ�.\n");
				printf("ipconfig     \t��ǻ���� ip�� Ȯ���մϴ�.\n");
				printf("time         \t���� �ð��� Ȯ���մϴ�.\n");
				printf("color        \t�ܼ��� �⺻���� ������ �����մϴ�.\n");
				printf("game         \t������ �÷��� �մϴ�.\n");
				printf("save-all     \t�����͸� �����մϴ�.\n");
				printf("update       \t��Ű��os�� �ֽŹ������� ������Ʈ �մϴ�.\n");
				printf("exit         \t�����մϴ�.\n");
			}
			else if (strcmp(command, "iotservice") == 0)
			{
				printf("\n<< �繰���ͳ� ���� >>\n");
				printf(":: 1.����� ���׷��̵� (100$)\n");
				printf(":: 2.ħ�� ��Ʈ���� ���׷��̵� (200$)\n");
				printf(":: �� ���� ���� �غ���\n");
				printf("������ �̿��� ���񽺸� �����ϼ��� :");
				int select=0;
				scanf("%d", &select);
				switch (select) {
				case 1:
					if (money >= 100) {
						printf("\n����� ���׷��̵� �ϼ̽��ϴ�.\n");
						printf("�� ��ǰ�� �����մϴ�.\n");
						printf("�̿��� �ּż� �����մϴ�.\n\n");
						money -= 100;
						value2++;
					}
					else
						printf("\n������ �ܰ� �����Ѱ� �����ϴ�\n\n");
					break;
				case 2:
					if (money >= 200) {
						printf("\nħ�� ��Ʈ������ ���׷��̵� �ϼ̽��ϴ�.\n");
						printf("�� ��ǰ�� �����մϴ�.\n");
						printf("�̿��� �ּż� �����մϴ�.\n\n");
						money -= 200;
						value1 += 100;
					}
					else
						printf("\n������ �ܰ� �����Ѱ� �����ϴ�\n\n");
					break;
				default :
					printf("\n�ش� ���񽺴� �������� �ʽ��ϴ�.\n\n");
					break;
				}
			}
			else if (strcmp(command, "ipconfig") == 0)
			{
				printf("\nVikini IP ����\n\n");
				printf("�̴��� ����� �̴���:\n");
				printf("   IPv6 �ּ� . . . :ed10::1434:e13d:19e3:a22e\%13\n");
				printf("   �̵�� ���� . . . . . . . . : �̵�� ���� ����\n\n");
			}
			else if (strcmp(command, "time") == 0)
			{
				printf("\n����ð� %d�� %d�� �Դϴ�.\n\n", Hour, Min);
			}
			else if (strcmp(command, "save-all") == 0)
			{
				printf("\n::: %s���� ������ :::\n", this->name);
				printf("  ��Ʈ���� : %d \t. . . ����� : %d\n", stress,hungry);
				printf("  �����ܾ� : %d \t. . . ������ : %d\n", Account,money);
				Save();
				printf("���������� ����Ǿ����ϴ�.\n\n");
			}
			else if (strcmp(command, "update") == 0) 
			{
				printf("\n�̹� �ֽŹ����� �̿��ϴ� ���Դϴ�.\n\n");
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
					printf("color help�� �Է��ϸ� ������ ���ɴϴ�.\n");
				}
				else if (strcmp(command, "color help") == 0)
				{
					printf("�ܼ��� �⺻ ������� ������ �����մϴ�.\n\n");
					printf("COLOR[attr]\n\n");
					printf("	attr        �ܼ� ����� �� Ư���� �����մϴ�.\n");
					printf("�� Ư���� �� �ڸ��� 16������ �����˴ϴ�.ù° �ڸ���\n");
					printf("������ �ش��ϰ� ��° �ڸ��� ������� �ش��մϴ�.�� �ڸ���\n");
					printf("���� ���� �� �� �ֽ��ϴ�.\n\n");
					printf("	0 = ������     8 = ȸ��\n");
					printf("	1 = �Ķ���     9 = ���� �Ķ���\n");
					printf("	2 = ���       A = ���� ���\n");
					printf("	3 = û�ϻ�     B = ���� û�ϻ�\n");
					printf("	4 = ������     C = ���� ������\n");
					printf("	5 = ���ֻ�     D = ���� ���ֻ�\n");
					printf("	6 = �����     E = ���� �����\n");
					printf("	7 = ���       F = ���� ���\n\n");
					printf("�μ��� �������� ������ �� ����� CMD.EXE�� ���۵Ǿ��� ����\n");
					printf("���� �����մϴ�.�� ���� ���� �ܼ� â���� �������ų�\n");
					printf("/ T ����� ����ġ�� ������Ʈ�� ������\n");
					printf("�����ɴϴ�.\n\n");
					printf("������� ����� ���� �����Ͽ� COLOR ����� �����Ϸ��� �� ���\n");
					printf("COLOR ����� ERRORLEVEL�� 1��\n");
					printf("�����մϴ�.\n\n");
					printf("���� ��� \"COLOR fc\"�� ���� ��� ���� ���� �������� �����մϴ�.\n\n");
					//	cin >> color_input1 >> color_input2;
				}
				else if (command_st.size() == 8)
				{
					char cmd[64];
					char color1 = command_st.at(6), color2 = command_st.at(7);
					snprintf(cmd, sizeof(cmd), "color %c%c", color1, color2) > 0 && system(cmd);
					system("cmd");		// �ش� ��ɾ�� �ش� OS �� �������� �ܼ� cmd�� ���ϴ� ��
										//color_wow[7] = command_st.at(7);
										//color_wow[8] = command_st.at(8);
										//system("color color_wow");
										//system("command_st");
				}
			}
			else if ((strcmp(command, "game") == 0))
			{
				printf("�÷����� ������ �������ּ���.\n");
				printf("���������� ���, ��Ģ���� ���, �߱����� ���, ��ٸ�Ÿ�� ���\n");
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
					printf("�������Դϴ�.");
					break;
				}
			}

			/////�ӽ� ġƮŰ/////
			else if (strcmp(command, "show_me_the_money") == 0)
			{
				printf("\nġƮŰ �ߵ� ::: 1000$ ����.\n\n");
				money += 1000;
			}
			else if (strcmp(command, "im_hungry!!!") == 0)
			{
				printf("\nġƮŰ �ߵ� ::: ����� ��� ���ġ 100����\n\n");
				value2 += 100;
			}
			else if (strcmp(command, "bed_is_science") == 0)
			{
				printf("\nġƮŰ �ߵ� ::: ħ�� ��Ʈ���� ���ġ 1000����\n\n");
				value1 += 1000;
			}
			else
			{
				printf("�˼����� ��ɾ� �Դϴ�. \"help\"�� ������ �� �� �ֽ��ϴ�.\n");
			}
		}
	}

	void Company_Jipge()
	{
		if (money >= 5) {
			gotopt(60, 11, "5$�� �����Ͽ����ϴ�.");
			gotopt(60, 13, "��Ⱑ 30 ��ŭ �����Ͽ����ϴ�.");
			money -= 5;
			hungry += 30;
			Min = Min + 20;											///////////////////////
		}
		else {
			gotopt(60, 11, "���Թ��Ŵ� 5$�Դϴ�.");
			gotopt(60, 13, "�ܰ� Ȯ���� ������.");
		}
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void Company_Work()
	{
		if (stress >= 500) {
			gotopt(60, 11, "500 ��Ʈ������ �Ҹ��ϰ� 100$�� �������ϴ�.");
			money += 100;
			stress -= 500;
			Hour = Hour + 10;											///////////////////////
		}
		else {
			gotopt(60, 11, " �Ƿε��� ���ڶ��ϴ�.");
			gotopt(60, 13, "������ �����ٰ� ������.");
		}
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void SSK_Alcohol()
	{
		if (money >= 5) {
			gotopt(60, 11, "5$�� �����ϰ� ��Ʈ������ 20 �����߽��ϴ�");
			money -= 5;
			stress -= 20;
			Hour = Hour + 2;											///////////////////////
		}
		else {
			gotopt(60, 11, "���� 5$�Դϴ�.");
			gotopt(60, 13, "�ܰ� Ȯ���غ�����.");
		}                          //���� ���� ���� ȿ��
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void SSK_KTandG()
	{
		if (money >= 5) {
			gotopt(60, 11, "5$�� �����ϰ� ��Ʈ������ 20 �����߽��ϴ�.");
			money -= 5;
			stress -= 20;
			Min = Min + 10;											///////////////////////
		}
		else {
			gotopt(60, 11, "���� 5$�Դϴ�.");
			gotopt(60, 13, "�ܰ� Ȯ���غ�����.");
		}					//��踦 �������� ȿ��
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
			gotopt(60, 11, "100$�� �����ϰ� �ζ���÷�� �����մϴ�.");
			Sleep(2000);
			system("cls");
			gotopt(60, 11, "�α��α��α��α�");
			Sleep(2000);
			LottoResult = rand() % 100;                      
			if ((LottoResult % 50) == (rand() % 10)) {
				system("cls");
				gotopt(60, 11, "��÷�Ǽ̽��ϴ�!!!! ���ϵ帳�ϴ�!!!!");
				money *= 2;
				stress += 30;
			}
			else {
				system("cls");
				gotopt(60, 11, "����... ���̳�");
			}
		}
		else {
			gotopt(60, 11, "���� �����մϴ�.");
		}               //�ζǸ� �������� ȿ��
		gotoxy(60, 13);
		system("pause");
		return;
	}

	void Bank_Deposit()
	{
		int temp = 0;

		gotopt(60, 10, "�Ա��� �ݾ��� �Է����ּ��� :");
		cin >> temp;
		if (temp > money)
		{
			system("cls");
			gotopt(60, 10, "�Է��Ͻ� �ݾ��� ������ ������ ��� �ݾ׺��� ŭ�ϴ�");
		}
		else {
			system("cls");
			gotopt(60, 10, "�ԱݵǼ̽��ϴ�.");
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

		gotopt(60, 10, "����� �ݾ��� �Է����ּ��� :");
		cin >> temp;
		if (temp > Account)
		{
			system("cls");
			gotopt(60, 10, "�Է��Ͻ� �ݾ��� ������ �ܰ� �ݾ׺��� ŭ�ϴ�");
		}
		else {
			system("cls");
			gotopt(60, 10, "��ݵǼ̽��ϴ�.");
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
		gotopt(60, 10, "�׽�Ʈ ���� ����Դϴ�.");
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
		printf("����������������������������������������������������������������������������������������");
		//gotoxy(15, 4);
		//printf("��");
		//gotoxy(15, 5);
		//printf("��");
		//gotoxy(15, 6);
		//printf("��");
		//gotoxy(100, 4);
		//printf("��");
		//gotoxy(100, 5);
		//printf("��");
		//gotoxy(100, 6);
		//printf("��");
		gotoxy(17, 4);
		printf("�̸�     : %s          ", name);
		gotoxy(45, 4);
		//printf("�Ƿε�   : %d / %d     ", fatigue, Max_fatigue);
		gotoxy(17, 5);
		////printf("����     : %d          ", level);
		gotoxy(75, 5);
		printf("����     : %d $", Account);
		gotoxy(45, 5);
		printf("�����   : %d / %d     ", hungry, Max_hungry);
		gotoxy(17, 6);
		printf("�ҵ����   : %d����     ", Exp_Level());
		gotoxy(45, 6);
		printf("��Ʈ���� : %d / %d     ", stress, Max_stress);
		gotoxy(75, 6);
		printf("������   : %d $", money);
		gotoxy(15, 7);
		printf("����������������������������������������������������������������������������������������");
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

		gotopt(x, ++y, "   ĳ������ �̸��� ���ϼ���.");
		gotopt(x, ++y, "������������������������������");
		gotopt(x, ++y, "��                          ��"); temp1 = y;
		gotopt(x, ++y, "������������������������������");
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

class Normal_Spongebob : public Character		// �븻 ��������
{
public:
	Normal_Spongebob()
	{
		exp = 0;						// �븻 �������� �ʱ� ����ġ = 0
		Max_exp = 10;					// �븻 �������� �ʱ� ����ġ �ƽ��� = 10
		money = 0;						// �븻 �������� �ʱ� �ڱ� = 0
		hungry = 100;					// �븻 �������� �ʱ� ��������� = 100
		Max_hungry = 100;				// �� ��� �ƽ�
		stress = 1000;						// �븻 �������� �ʱ� ��Ʈ���� = 0
		Max_stress = 1000;
		level = 0;						// �븻 �������� �ʱ� ���� = 0
		Account = 0;						
	}

	void Ending_Check()
	{
		if (money >= 1000000)
		{
			gotopt(60, 11, "������ �����Ͻðڽ��ϱ�?");
			gotopt(60, 13, "Yes (y) or No (n)");
			char ch = _getch();
			if (ch == 'y')
			{
				system("cls");
				ending_count = 1;
			}
			else if (ch == 'n') {
				system("cls");
				gotopt(60, 11, "���� : �� �ɴ�");
			}
			else
			{
				system("cls");
				gotopt(60, 11, "�߸������̽��ϴ�");
			}
		}
		else {
			system("cls");
			gotopt(60, 11, "���� : ���ϳ�?");
			gotopt(60, 15, "���ֻ���Կ���");
			gotopt(60, 17, "�ڱ��� �������ϼ̽��ϴ�");
			money = 0;
			getch();
			system("cls");
			gotopt(60, 11, "���� :");
			gotopt(60, 13, "���� �� ���Ը� �Ѻ�?");
			gotopt(60, 15, "�������� �� �� �뿹�� !");
			gotoxy(60, 19);
			system("pause");
			stress = stress + 500;
			exp = exp + (Max_exp / 2);
		}
		return;
	}
};

//class Hard_Spongebob : public Character		// �ϵ� ��������
//{
//public:
//	Hard_Spongebob(char *Input_name)
//	{
//		exp = 0;						// �ϵ� �������� �ʱ� ����ġ = 0
//		Max_exp = 10;					// �ϵ� �������� �ʱ� ����ġ �ƽ��� = 10
//		money = 0;						// �ϵ� �������� �ʱ� �ڱ� = 0
//		hungry = 100;					// �ϵ� �������� �ʱ� ��������� = 100
//		fatigue = 1000;					// �ϵ� �������� �ʱ� �Ƿε� = 1000
//		stress = 0;						// �ϵ� �������� �ʱ� ��Ʈ���� = 1000
//		level = 0;						// �ϵ� �������� �ʱ� ���� = 0
//		this->name[0] = *Input_name;	// �ϵ� �������� �̸� ����
//	}
//};

class Normal_Star : public Character			// �븻 ����
{
public:
	Normal_Star()
	{
		exp = 0;						// �븻 ���� �ʱ� ����ġ = 0
		Max_exp = 5;					// �븻 ���� �ʱ� ����ġ �ƽ��� = 5
		money = 0;						// �븻 ���� �ʱ� �ڱ� = 0
		hungry = 80;					// �븻 ���� �ʱ� ��������� = 80
		Max_hungry = 80;
		stress = 2000;						// �븻 ���� �ʱ� ��Ʈ���� = 2000
		Max_stress = 2000;
		level = 0;						// �븻 ���� �ʱ� ���� = 0
		Account = 0;
	}

	void Ending_Check()
	{
		if (money >= 1000000)
		{
			gotopt(60, 11, "������ �����Ͻðڽ��ϱ�?");
			gotopt(60, 13, "Yes (y) or No (n)");
			char ch = _getch();
			if (ch == 'y')
			{
				system("cls");
				ending_count = 1;
			}
			else if (ch == 'n') {
				system("cls");
				gotopt(60, 11, "���� : �� �ɴ�");
			}
			else
			{
				system("cls");
				gotopt(60, 11, "�߸������̽��ϴ�");
			}
		}
		else {
			system("cls");
			gotopt(60, 11, "���� : ���ϳ�?");
			gotopt(60, 15, "���ֻ���Կ���");
			gotopt(60, 17, "�ڱ��� �������ϼ̽��ϴ�");
			money = 0;
			getch();
			system("cls");
			gotopt(60, 11, "���� :");
			gotopt(60, 13, "���� �� ���Ը� �Ѻ�?");
			gotopt(60, 15, "�������� �� �� �뿹�� !");
			stress = stress + 500;
			exp = exp + (Max_exp / 2);
		}
		return;
	}
};

//class Hard_Star : public Character			// �ϵ� ����
//{
//public:
//	Hard_Star(char *Input_name)
//	{
//		exp = 0;						// �ϵ� ���� �ʱ� ����ġ = 0
//		Max_exp = 5;					// �ϵ� ���� �ʱ� ����ġ �ƽ��� = 5
//		money = 0;						// �ϵ� ���� �ʱ� �ڱ� = 0
//		hungry = 80;					// �ϵ� ���� �ʱ� ��������� = 80
//		fatigue = 800;					// �ϵ� ���� �ʱ� �Ƿε� = 800
//		stress = 0;						// �ϵ� ���� �ʱ� ��Ʈ���� = 2000
//		level = 0;						// �ϵ� ���� �ʱ� ���� = 0
//		this->name[0] = *Input_name;	// �ϵ� ���� �̸� ����
//	}
//};

class Normal_Squidward : public Character		// �븻 ¡¡��
{
public:
	Normal_Squidward()
	{
		exp = 0;						// �븻 ¡¡�� �ʱ� ����ġ = 0
		Max_exp = 15;					// �븻 ¡¡�� �ʱ� ����ġ �ƽ��� = 15
		money = 100;					// �븻 ¡¡�� �ʱ� �ڱ� = 100
		hungry = 80;					// �븻 ¡¡�� �ʱ� ��������� = 80
		Max_hungry = 80;
		stress = 800;						// �븻 ¡¡�� �ʱ� ��Ʈ���� = 800
		Max_stress = 800;
		level = 0;						// �븻 ¡¡�� �ʱ� ���� = 0
		Account = 0;
	}

	void Ending_Check()
	{
		if (money >= 1000000)
		{
			gotopt(60, 11, "������ �����Ͻðڽ��ϱ�?");
			gotopt(60, 13, "Yes (y) or No (n)");
			char ch = _getch();
			if (ch == 'y')
			{
				system("cls");
				ending_count = 1;
			}
			else if (ch == 'n') {
				system("cls");
				gotopt(60, 11, "���� : �� �ɴ�");
			}
			else
			{
				system("cls");
				gotopt(60, 11, "�߸������̽��ϴ�");
			}
		}
		else {
			system("cls");
			gotopt(60, 11, "���� : ���ϳ�?");
			gotopt(60, 15, "���ֻ���Կ���");
			gotopt(60, 17, "�ڱ��� �������ϼ̽��ϴ�");
			money = 0;
			getch();
			system("cls");
			gotopt(60, 11, "���� :");
			gotopt(60, 13, "���� �� ���Ը� �Ѻ�?");
			gotopt(60, 15, "�������� �� �� �뿹�� !");
			stress = stress + 500;
			exp = exp + (Max_exp / 2);
		}
		return;
	}
};

//class Hard_Squidward : public Character		// �ϵ� ¡¡��
//{
//public:
//	Hard_Squidward(char *Input_name)
//	{
//		exp = 0;						// �ϵ� ¡¡�� �ʱ� ����ġ = 0
//		Max_exp = 15;					// �ϵ� ¡¡�� �ʱ� ����ġ �ƽ��� = 15
//		money = 100;					// �ϵ� ¡¡�� �ʱ� �ڱ� = 100
//		hungry = 80;					// �ϵ� ¡¡�� �ʱ� ��������� = 80
//		fatigue = 800;					// �ϵ� ¡¡�� �ʱ� �Ƿε� = 800
//		stress = 0;						// �ϵ� ¡¡�� �ʱ� ��Ʈ���� = 800
//		level = 0;						// �ϵ� ¡¡�� �ʱ� ���� = 0
//		this->name[0] = *Input_name;	// �ϵ� ¡¡�� �̸� ����
//	}
//};

// �ϵ� (1) �븻 (0) && ��¡��


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////�Լ� ������////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///		�θ� Ŭ������ ��� �Լ��� ����

//void House(Character *character)		// �� �Լ�
//{
//	int y = 10;
//	system("cls");
//	gotopt(60, 10, "��Ա�");
//	gotopt(60, 13, "���ڱ�");
//	gotopt(60	, 16, " ��� ");
//	gotopt(56, y, "��");
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

void Company(Character *character)			// ���Ը��� �Լ�
{
	int y = 10;
	system("cls");
	gotopt(60, 10, "�մ����� ����");
	gotopt(60, 13, "�˹��Ϸ� ����");
	gotopt(60, 16, "���Ը��� �μ�");
	gotopt(56, y, "��");
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
					cout << "���Ը��� ��༭�� ���� �㿡�� ���� �� �ֽ��ϴ�." << endl;	///////////////////////
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

void SSK(Character *character)			// ���۸���  �Լ�							// �̿ϼ�
{
		int y = 10;
		//int LottoResult; //�������庯��
		//int i; /////////////////////////////////////////for�� ������ ����
		system("cls");
		gotopt(60, 10, "�� (���� : 5$)");
		gotopt(60, 13, "��� (���� : 5$)");
		gotopt(60, 16, "�ζ� (���� : 100$)");
		gotopt(56, y, "��");
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

void Bank(Character *character)		// ���� �Լ�
{
	int y = 10;
	system("cls");
	gotopt(60, 10, "�Ա��ϱ�");
	gotopt(60, 13, "����ϱ�");
	gotopt(60, 16, "�۱��ϱ�");
	gotopt(56, y, "��");
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

int Menu_Choice_W(int y)			// �޴�â���� W�� �������� �߻��ϴ� �׼� �Լ�
{
	if (y == 10) {
		gotopt(56, y, "  ");
		y = y + 6;
		gotopt(56, y, "��");
	}
	else if (y == 13) {
		gotopt(56, y, "  ");
		y = y - 3;
		gotopt(56, y, "��");
	}
	else if (y == 16) {
		gotopt(56, y, "  ");
		y = y - 3;
		gotopt(56, y, "��");
	}
	return y;
}

int Menu_Choice_S(int y)			// �޴�â���� S�� �������� �߻��ϴ� �׼� �Լ�
{
	if (y == 10) {
		gotopt(56, y, "  ");
		y = y + 3;
		gotopt(56, y, "��");
	}
	else if (y == 13) {
		gotopt(56, y, "  ");
		y = y + 3;
		gotopt(56, y, "��");
	}
	else if (y == 16) {
		gotopt(56, y, "  ");
		y = y - 6;
		gotopt(56, y, "��");
	}
	return y;
}

//
//
//void Event()		// �̺�Ʈ �Լ�							// �̿ϼ�
//{
//	// While �� �ȿ� ��� �����ϴ� ������ ����� �� ������ 1000�� �� �� �����Լ��� ���ظ� �߻�
//	Event_NaturalDisasters();
//	Event_Burglar();	// static
//}
//
//void Event_NaturalDisasters()	// �ڿ����� �Լ�							// �̿ϼ�
//{
//
//}
//
//void Event_Burglar()			// ���� �Լ�							// �̿ϼ�
//{
//
//}

int Die_Check(Character *character)			// ���� üũ �Լ�							// �̿ϼ�
{
	int i;
	i = Die(character);
	return i;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////�� ������////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gotoxy(int x, int y)			// �ش� ��ǥ�� �ܼ� Ŀ�� �̵�
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

void gotopt(int x, int y, char c[102])		// ��ǥ, ��� ( �ش� ��ǥ�� �̵� �� ��� )
{
	gotoxy(x, y);
	printf("%s", c);
}

void cls1() {			// Ư�� ��ǥ Ŭ����
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

//char map[21][44] = {							// �� ���� ����
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

char map[21][44] = {							// �� ���� ����
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

void Create_Map()			// �� �迭 �׷���ȭ
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 44; j++)
		{
			switch (map[i][j])
			{
			case 0:
				gotopt(basicX + j * 2, basicY + i, "��");
				break;
			case 1:
				gotopt(basicX + j * 2, basicY + i, "��");
				break;
			case 2:
				gotopt(basicX + j * 2, basicY + i, "|");
				break;
			case 3:
				gotopt(basicX + j * 2, basicY + i, "��");
				break;
			case 4:
				gotopt(basicX + j * 2, basicY + i, "��");
				break;
			case 5:
				gotopt(basicX + j * 2, basicY + i, "\\");
				break;
			case 6:
				gotopt(basicX + j * 2, basicY + i, "��");
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
	gotopt(39, 1, "<���۹�> ��:w, �Ʒ�:s, ��:a, ��:d, ����:f");
}

const int houseX = 35;
const int houseY = 15;

char houseMap[11][24] = {							// �� ���� ����
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

void Create_house()			// �� �迭 �׷���ȭ
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			switch (houseMap[i][j])
			{
			case 0:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			case 1:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			case 2:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			case 3:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			case 4:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			case 5:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			case 7:
				gotopt(houseX + j * 2, houseY + i, "��");
				break;
			}
		}
	}
	gotopt(39, 1, "<���۹�> ��:w, �Ʒ�:s, ��:a, ��:d, ����:f");
	gotopt(39, 10, "�� : ����� , �� : ��ǻ�� , �� : ħ��");
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
	gotopt(posX, posY, "��");
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
		gotopt(posX, posY, "��");
	}
	else if (look == 1 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_PINK | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "��");
	}
	else if (look == 2 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_SKY | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "��");
	}
	if (look == 0 && Night == 0) {
		gotopt(posX, posY, "��");
	}
	else if (look == 1 && Night == 0) {
		gotopt(posX, posY, "��");
	}
	else if (look == 2 && Night == 0) {
		gotopt(posX, posY, "��");
	}
	if (Night==1)
		SetConsoleTextAttribute(hOut, FOREGROUND_WHITE);


	hungry_check = hungry_check + 1;

	if (x == 13 && y == 7) {
		gotopt(x, y, "��");
		Company(character);
	}
	if (x == 31 && y == 6) {
		gotopt(x, y, "��");
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
	gotopt(posX, posY, "��");
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
		if (x == 1 && y == 2)				// ħ�� ��ȣ�ۿ�
		{
			system("cls");
			character->House_Sleep();
			character->Save();
			system("cls");
			Create_house();
		}
		else if (x == 14 && y == 2)			// ��ǻ�� ��ȣ�ۿ�
		{
			system("cls");
			character->Computer_Play();
			system("cls");
			Create_house();
		}
		else if (x == 19 && y == 2)			// ����� ��ȣ�ۿ�
		{
			system("cls");
			character->House_Eat();
			system("cls");
			Create_house();
		}
		else if (x == 12 && y == 9)			// ������ ������
		{
			system("cls");
			Create_Map();
			inHouse = 0;
			return;
		}
	}
	if (look == 0 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_YELLOW | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "��");
	}
	else if (look == 1 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_PINK | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "��");
	}
	else if (look == 2 && Night == 1) {
		SetConsoleTextAttribute(hOut, FOREGROUND_SKY | FOREGROUND_INTENSITY);
		gotopt(posX, posY, "��");
	}
	if (look == 0 && Night == 0) {
		gotopt(posX, posY, "��");
	}
	else if (look == 1 && Night == 0) {
		gotopt(posX, posY, "��");
	}
	else if (look == 2 && Night == 0) {
		gotopt(posX, posY, "��");
	}
	if (Night == 1)
		SetConsoleTextAttribute(hOut, FOREGROUND_WHITE);


	hungry_check = hungry_check + 1;
}

void title() {
	gotopt(13, 12, "�� ���α׷��� �Ѷ���б� ���л�[�����, ������, ������, ������]�� �����Ͽ� ���۵� �����Դϴ�.");
	int x = 44; int y = 20;
	int temp1, temp2, choose, choose_back;
	gotopt(x, ++y, "������������������������������");
	gotopt(x, ++y, "��                          ��");
	gotopt(x + 10, y, "���� ����"); temp1 = y;
	gotopt(x, ++y, "��                          ��");
	gotopt(x, ++y, "��                          ��");
	gotopt(x + 10, y, "���� ����"); temp2 = y;
	gotopt(x, ++y, "������������������������������");
	gotopt(x - 5, y += 2, "<���۹�> ��:w, �Ʒ�:s, ��:a, ��:d, ����:f");
	char ch;
	choose = temp1;
	while (1) {
		choose_back = choose;
		gotopt(x + 6, choose, "��");
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
		gotopt(x + 6, choose_back, "��");
	}
}

void showStory() {
	int x = 10, y = 5, l = 0; char findDot;
	char story[] = "�������κ��� 30����, ��Ű�� ��Ƽ�� ��� ��������, ¡¡��, ���̴� �������̿� 4�� ���� ������ �� ���� ���� �翬�ϴٴ� ���� �����ϴ� ���Ի����� ���Ը��ƿ��� �뵿�� ������ϰ� �־���.	�Ϸ�� ���Ի����� �׵鿡�� ���� ���������� ���� ���� �ƴٸ�, �ٷΰ�༭�� �ۼ����ڰ� �Ͽ���. �׵��� ���� ���Ի������ �ڱ���� �������شٸ� ��༭�� �պκи� ������ �о�� ��ٷ� ������ �ߴ�. ���̱��� ������ ��ġ�� ���Ի����� �µ��� ������ �޶�����.	�׷� ���Ի����� �µ��� ���� ¡¡�̴� ��༭ �պκ��� ���Ի����� ���ϰ� ����� �ڱ���� �Ժη� ���ϸ� ��༭ �����̶�� ���ߴ�. �ڿ��� ¡¡�̰� �� ��༭�� ���� ���̰� ������ ��༭ �޸鿡�� ���ڰ� ���ִ°ž�.�������� ? �� �̶�� ���ߴ�. �� ���� ���� ���������� ¡¡�̰� �� ��༭ ��鿡 ���� ���� �о���µ�, �� ������ �̷���. - ��༭ -. �ֽ�ȸ�� ���Ը���( ���� �������̶� �Ѵ� )�� ��������, ¡¡��, ����( ���� �������̶� �Ѵ� )�� ������ ���� �ٷΰ���� ü���Ѵ�. ��, �������� �������� ���� �Ҵ緮�� ���� ä���� �ϸ�, �̸� ä���� ���� �� ������ �����ϰų� �ش� ���� �޿��� ���� �ʴ� ���� ��Ģ���� �Ѵ�.	...	- �޸� -.�������� ���������� 100�Ⱓ ���ؾ� �ϸ�, �ش� �Ⱓ�� ä���� ���ϰ� ���� ������ �ÿ��� ���� �Ⱓ��ŭ �������� ������ ����� �����ؾ��Ѵ�.�������� ���Ը��Ƹ� ������ ����� ���ϸ�, ���Ի����� ���� ��ĥ�ÿ��� ���谡��(��, �ǹ���)�� �ش� �Ǹ��� ����Ѵ�. �������� �ٹ��ð��� ������ �� ( 19�� ~ 06�� ���� ) �̴�.	... �� ����� �������� 15��ڿ� ��������, ¡¡��, ���̴� ��Ű�Ͻ�Ƽ�� ���� �߹ݵ��ָ� �ϰԵȴ�. �� ����� �� ���Ի����� ��������, ¡¡��, ������ ���ڷ� ������Ų ����� ź����Ų��.	����� �� � �Ǹ��� ���� ���Ը��ƿ��� 85�⵿�� ���� �ؾ��ϴ� ��Ȳ�ε�. ����� ������ �� ����� ���Ը��Ƹ� �μ��ϴ� �����.";
	char ch;

	gotopt(40, 3, "���� ���丮 ������ 'p' Ű�� �����ּ���.");

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
	char story[] = " ����. ���� ���� ������";
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
		gotopt(56, 6, "- �޴��� -");
		gotopt(42, 8, "������ ��� �� ǥ�õ� ��Ҵ� ���Դϴ�.");
		gotopt(40, 10, "���� ��� �� ǥ�õ� ��Ҵ� ���Ը����Դϴ�.");
		gotopt(40, 12, "���� �ϴ� 24 ǥ�õ� ��Ҵ� ���۸����Դϴ�.");
		gotopt(41, 14, "������ �ϴ� $ ǥ�õ� ��Ҵ� �����Դϴ�.");
		gotopt(38, 16, "�� �ǹ��� ���� ������ �Ʒ� ��ȣ�� �Է����ּ���.");
		gotopt(30, 18, "�� ���, ���Ը��� ���, ���۸��� ���, ���� ���, ���ӽ��� ���");
		gotoxy(58, 20);
		cout << " : ";
		cin >> kaka;
		switch (kaka) {
		case 1:
			system("cls");
			gotopt(30, 8, "'���ڱ�'�� �����Ͻø� �����Ͱ� ����ǰ�, ��Ʈ������ 100 ����մϴ�.");
			gotopt(42, 10, "'��Ա�'�� �����Ͻø� ������� 2 ����մϴ�.");
			gotopt(32, 12, "'���'�� �����Ͻø� 100$�� �����ϰ�, ��Ʈ������ 50 ����մϴ�.");
			gotoxy(46, 15);
			system("pause");
			break;
		case 2:
			system("cls");
			gotopt(20, 8, "���Ը��ƿ� ���� '�մ����� ����'�� �����Ͻø� 5$�� �����ϰ�, ��Ⱑ 30 ����մϴ�.");
			gotopt(15, 10, "���Ը��ƿ� ���� '�˹��Ϸ� ����'�� �����Ͻø� ��Ʈ������ 500 �϶��ϰ�, 100$�� ���޹޽��ϴ�.");
			gotopt(18, 12, "���Ը��ƿ� ���� '���Ը��� �μ�'�� �����Ͻø� 1000000$�� �����ϰ�, ������ �����մϴ�.");
			gotoxy(45, 15);
			system("pause");
			break;
		case 3:
			system("cls");
			gotopt(23, 8, "���۸��Ͽ� ���� '��'�� �����Ͻø� 5$�� �����ϰ�, ��Ʈ������ 20 ����մϴ�.");
			gotopt(22, 10, "���۸��Ͽ� ���� '���'�� �����Ͻø� 5$�� �����ϰ�, ��Ʈ������ 20 ����մϴ�.");
			gotopt(22, 12, "���۸��Ͽ� ���� '�ζ�'�� �����Ͻø� 100$�� �����ϰ�, �ζ� ��÷�� �����մϴ�.");
			gotopt(17, 15, "Ȯ���� 50���� 1\t��÷�� �������� 2��� �����帳�ϴ�.\t�� ����� ��ƺ������� ~ !!");
			gotoxy(45, 18);
			system("pause");
			break;
		case 4:
			system("cls");
			gotopt(29, 8, "���࿡ ���� '�Ա��ϱ�'�� �����Ͻø� ���¿� ���� �Ա��մϴ�.");
			gotopt(28, 10, "���࿡ ���� '����ϱ�'�� �����Ͻø� ���¿��� ���� �����մϴ�.");
			gotopt(25, 12, "���࿡ ���� '�۱��ϱ�'�� �����Ͻø� �ٸ� �������� ���� �۱��մϴ�.");
			gotopt(34, 15, "������, '�۱��ϱ�' ����� ���� �׽�Ʈ���� ����Դϴ�.");
			gotoxy(43, 18);
			system("pause");
			break;
		case 5:
			bye = 0;
			system("cls");
			gotopt(30, 8, "ȯ���� ����, ���� ���� ����, �������̿� ���� ��༭�� ���� ġ�� ����.");
			gotopt(43, 10, "��Ű�� ��Ƽ�� ���Ű��� �������� ȯ���մϴ�.");
			gotoxy(45, 13);
			system("pause");
			break;
		default:
			system("cls");
			kaka = 0;
			gotopt(53, 8, "�߸� �����̽��ϴ�.");
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
		cout << "���λ� �ϼ̽��ϴ�" << endl;
		Sleep(2000);
		return 1;
	}
	if (character->Hungry_Check() <= 0)
	{
		system("cls");
		gotoxy(60, 13);
		cout << "������� 0 �� �Ǿ� �����ϼ̽��ϴ�." << endl;
		Sleep(1000);
		system("cls");
		gotoxy(60, 13);
		cout << "��Ÿ����� �����ϼż� �������� ������ �����˴ϴ�." << endl;
		Sleep(1000);
		system("cls");
		gotoxy(60, 13);
		cout << "����� �� ����ϴ�. �ƻ����� �ʵ��� �����Ͻʼ���~." << endl;
		Sleep(1000);
		character->Hungry_Max();
		character->Money_Half();
		system("cls");
		return 2;
	}
	else
		return 0;
}


//�ð�����