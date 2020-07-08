#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

using namespace std;

int cCom_cho();
void bye();
int chos();
void Fail();
void Intro();
void baseball();
int cell(int accumulate);
int RPS();
int result();
void play(int cCom, int win);
void play2(int cCom, int win);
void play3(int cCom, int win);
void start();



int RPS()				// ����������
{
	int cho;
	int cCom;
	bool by = 1;
	bool win = 1;
	int stop = 0;

	srand(time(NULL));

	cout << "\n\n";

	start();

	while (win)
	{
		cho = chos();
		cCom = cCom_cho();

		if (cCom == 0)
		{
			// cCom = rand() % 4;

			while (cCom == 0)
			{
				cCom = cCom_cho();
			}
			//for( cCom = 0; 0 < cCom; )
			//{
			//	cCom = rand() % 4;
			//}
		}

		if (cho == 1)
		{
			//printf("%d\n",cCom);
			Intro();
			play(cCom, win);
		}
		else if (cho == 2)
		{
			//cCom = rand() % 4;
			Intro();
			play2(cCom, win);
		}
		else if (cho == 3)
		{
			//cCom = rand() % 4;
			Intro();
			play3(cCom, win);
		}
		else
		{
			Fail();
		}
		
		cout << "�� �� �� ?" << endl;
		cout << "����ҽ� (�̱� Ƚ�� * 2)��ŭ �����ݿ� �������ϴ�." << endl;
		cout << "����ϱ�� 1��, �׸��ϱ�� 0���� �����ּ���." << endl;

		while (by)
		{
			int ch;
			cin >> ch;
			switch (ch)
			{
			case 1:
				stop = stop + 1;
				cout << "�ٵ�... �ڽ��־�?" << endl;
				system("pause");
				stop = 1;
				by = 0;
			case 0:
				cout << "��.. ��, �������ΰ� ����." << endl;
				win = 0;
				system("pause");
				by = 0;
			default:
				cout << "�߸������̽��ϴ�." << endl;
				break;
			}
		}
	}
	bye();
	return stop * 2;
}

void Intro()
{
	Sleep(1000);
	cout << "����~" << endl;
	Sleep(1000);
	cout << "����~" << endl;
	Sleep(1000);
	cout << endl;
}

void Fail()
{
	cout << "\n" << "�߸� �����Ͽ����ϴ�. �ٽ� �����ϼ���.\n";
	fflush(stdin);
}

int chos()
{
	int cho;

	cout << "���� ���� �� �� ������ ������ �ϼ���~\n";
	cout << "1 : ����, 2 : ����, 3 : �� \n";
	cout << "���� : ";
	cin >> cho;

	return cho;
}

void bye()
{
	cout << "������ ������~\n";
	//system("pause");
}

int cCom_cho()
{
	int cCom;

	cCom = rand() % 4;

	return cCom;
}

void play(int cCom, int win)
{
	if (cCom == 1)
	{
		cout << " �� �� ����	 [VS]	 ���� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �����ϴ� .... \n\n";
	}
	else if (cCom == 2)
	{
		cout << " %s �� ����	 [VS]	 ���� �� %s \n\n";
		Sleep(1000);
		cout << "	 �ڡ� ��ǻ�� ���! �ڡ� \n\n";
	}
	else if (cCom == 3)
	{
		cout << " %s �� ����	 [VS]	 �� �� %s \n\n";
		Sleep(1000);
		cout << "	 �ڡ� �� ���! �ڡ� \n\n";
		win = win + 1;
	}
}

void play2(int cCom, int win)
{
	if (cCom == 1)
	{
		cout << " �� �� ����	 [VS]	 ���� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �����ϴ� .... \n\n";
	}
	else if (cCom == 2)
	{
		cout << " �� �� ����	 [VS]	 �� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �ڡ� ��ǻ�� ���! �ڡ� \n\n";
	}
	else if (cCom == 3)
	{
		cout << " �� �� ����	 [VS]	 ���� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �ڡ� �� ���! �ڡ� \n\n";
		win = win + 1;
	}
}

void play3(int cCom, int win)
{
	if (cCom == 1)
	{
		cout << " �� �� ��	 [VS]	 �� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �����ϴ� .... \n\n";
	}
	else if (cCom == 2)
	{
		cout << " �� �� ��	 [VS]	 ���� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �ڡ� ��ǻ�� ���! �ڡ� \n\n";
	}
	else if (cCom == 3)
	{
		cout << " �� �� ��	 [VS]	 ���� �� ��ǻ�� \n\n";
		Sleep(1000);
		cout << "	 �ڡ� �� ���! �ڡ� \n\n";
		win = win + 1;
	}
}

void start()
{
	cout << "�١ڡٰ��� ���� �� ���ӡ١ڡ�\n";
	cout << "�� VS ��ǻ��\n\n";
}

int result()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cell(int accumulate)			// ��Ģ���� ����		// ����� acc�� 1����		// ���Ӽ��� : ���� �����ϰ� ���� ���� �� ��ŭ ������ ���� ������
{
	int rand_num1 = rand() % 2, rand_num2 = rand() % 4;
	int input_result = 0;
	int answer_result = 0;
	char cho = 0;
	int cho_num = 0;
	int i = 0;
	int count = 0;
	int static doubleshot = 2;
	int cho_doubleshot = 0;

	srand(time(NULL));

	cout << "������ �����Ͻʽÿ�. ( +, -, /, * )" << endl;
	cin >> cho;
	cout << "���� ���� �Է��ϼ���." << endl;
	cin >> cho_num;

	for (i = 0; i < cho_num; i++)
	{
		switch (cho) {
		case '+':
			cout << "������ �����ϼ̽��ϴ�." << endl;
			cout << rand_num1 << "+" << rand_num2 << "=";
			answer_result = rand_num1 + rand_num2;
			cin >> input_result;
			break;
		case '-':
			cout << "������ �����ϼ̽��ϴ�." << endl;
			cout << rand_num1 << "-" << rand_num2 << "=";
			answer_result = rand_num1 - rand_num2;
			cin >> input_result;
			break;
		case '*':
			cout << "������ �����ϼ̽��ϴ�." << endl;
			cout << rand_num1 << "*" << rand_num2 << "=";
			answer_result = rand_num1 * rand_num2;
			cin >> input_result;
			break;
		case '/':
			cout << "�������� �����ϼ̽��ϴ�." << endl;
			if (rand_num2 == 0)
			{
				rand_num2 = rand_num2 + 1;
			}
			cout << rand_num1 << "/" << rand_num2 << "=";
			answer_result = rand_num1 / rand_num2;
			cin >> input_result;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			return 0;
		}
		if (answer_result == input_result)
		{
			cout << "�����Դϴ�." << endl;
			count = count + 1;
			cout << "���� ���ھ�� " << count << "�Դϴ�." << endl;
		}
		else {
			cout << "����" << endl;
		}
		rand_num1 = rand() % ((cho_num + count)*accumulate);
		rand_num2 = rand() % ((cho_num + cho_num)*accumulate);
	}

	if (count == cho_num)
	{
		cout << "�� �ϴµ�?\n �� ���� x" << doubleshot << "���� �ִٱ� ~ " << endl;
		cout << "�̷�?" << endl;
		cout << "�̸��� 0��, ���ڸ� 1���� �����ּ���~" << endl;
		doubleshot = doubleshot * 2;
		cin >> cho_doubleshot;
		if (cho_doubleshot == 1)
		{
			accumulate = doubleshot * count;
			cout << "�׷� ~ ������ �̾ƾ��� ~" << endl;
			cell(accumulate);
		}
		else if (cho_doubleshot == 0)
		{
			cout << "�� ~ ������ �ۿ� �ȵǴ±���?" << endl;
			accumulate = accumulate - 1;
			doubleshot = 2;
			return accumulate;
		}
	}
	else {
		doubleshot = 2;
		cout << "����. ������" << endl;
		return 0;
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void say()		// ������ ����
{
	char Input_say[] = { 0, };

	cout << "������ �����Դϴ�." << endl;
	cout << "���� ������ ���Ͻô� ������ �Է����ּ��� :";
	cin >> Input_say;


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void baseball()			// �߱� ����
{
	int i = 0;
	int j = 0;
	int k = 0;

	srand(time(NULL));

	int Rand_Num[3] = { rand() % 10, rand() % 10, rand() % 10 };
	//int Rand_Num2 = rand() % 10;
	//int Rand_Num3 = rand() % 10;

	int Input_Num[3] = { 0, };
	//int Input_Num2 = 0;
	//int Input_Num3 = 0;

	int Strike_Count = 0;
	int Ball_Count = 0;

	int Break = 1;

	while (Rand_Num[0] == Rand_Num[1])
	{
		Rand_Num[1] = rand() % 10;
	}

	while ((Rand_Num[0] == Rand_Num[2]) || (Rand_Num[1] == Rand_Num[2]))
	{
		Rand_Num[2] = rand() % 10;
	}

	while (Break == 0)
	{
		cout << "���� ������ �Է����ּ���." << endl << "���ڿ� ���ڻ��̴� ���⸦ ���ּ���" << endl << "���ڴ� �ߺ� �Է��� �Ұ��մϴ�" << endl;
		cin >> Input_Num[0] >> Input_Num[1] >> Input_Num[2];
		if ((Input_Num[0] == Input_Num[1]) || ((Input_Num[0] == Input_Num[2]) || (Input_Num[1] == Input_Num[2])))
		{
			cout << endl << "�ٽ� �Է����ּ���" << endl;
		}
		else
		{
			Break = 1;
		}
	}


	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (Input_Num[j] == Rand_Num[j])
			{
				Strike_Count = Strike_Count + 1;
			}
		}
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (j != k && Input_Num[j] == Rand_Num[k])
				{
					Ball_Count = Ball_Count + 1;
				}
			}
		}
		cout << i << "ȸ��" << Strike_Count << " S" << Ball_Count << " B" << endl;

		if (Strike_Count == 3)
		{
			break;
		}

		Strike_Count = 0;
		Ball_Count = 0;
	}

	cout << (Strike_Count == 3 ? "�¸��ϼ̽��ϴ�" : "�й� ��") << endl;


}
//
//#include <algorithm>
//using namespace std;
//int n, k;
//int q;
//char board[1005][30];
//char last[30];
//int idx[30];
//int main()
//{
//	scanf("%d%d", &n, &k);
//	scanf("%s", last);
//	for (int i = 0;i<k;++i) {
//		scanf("%s", board[i]);
//		if (board[i][0] == '?')q = i;
//	}
//	for (int i = 0;i<n;++i) {
//		idx[last[i] - 'A'] = i;
//	}
//	for (int i = 0;i<n - 1;++i) {
//		board[q][i] = '*';
//	}
//	for (int i = 0;i<n;++i) {
//		int ux = i;
//		int dx = idx[i];
//		for (int x = 0;x<q;++x) {
//			if (board[x][ux] == '-') {
//				ux++;
//			}
//			else if (ux>0 && board[x][ux - 1] == '-') {
//				ux--;
//			}
//		}
//		for (int x = k - 1;x>q;--x) {
//			if (board[x][dx] == '-') {
//				dx++;
//			}
//			else if (dx>0 && board[x][dx - 1] == '-') {
//				dx--;
//			}
//		}
//		if (abs(ux - dx)>1) {
//			for (int j = 0;j<n - 1;++j) {
//				board[q][j] = 'x';
//			}
//			break;
//		}
//		if (ux - dx == 1) {
//			board[q][dx] = '-';
//		}
//		else if (dx - ux == 1) {
//			board[q][ux] = '-';
//		}
//	}
//	printf("%s
//		",board[q]);
//}