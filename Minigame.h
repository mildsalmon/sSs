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



int RPS()				// 가위바위보
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
		
		cout << "한 판 더 ?" << endl;
		cout << "계속할시 (이긴 횟수 * 2)만큼 소지금에 곱해집니다." << endl;
		cout << "계속하기는 1번, 그만하기는 0번을 눌러주세요." << endl;

		while (by)
		{
			int ch;
			cin >> ch;
			switch (ch)
			{
			case 1:
				stop = stop + 1;
				cout << "근데... 자신있어?" << endl;
				system("pause");
				stop = 1;
				by = 0;
			case 0:
				cout << "넌.. 딱, 그정도인가 보다." << endl;
				win = 0;
				system("pause");
				by = 0;
			default:
				cout << "잘못누르셨습니당." << endl;
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
	cout << "가위~" << endl;
	Sleep(1000);
	cout << "바위~" << endl;
	Sleep(1000);
	cout << endl;
}

void Fail()
{
	cout << "\n" << "잘못 선택하였습니다. 다시 선택하세요.\n";
	fflush(stdin);
}

int chos()
{
	int cho;

	cout << "가위 바위 보 중 마음의 결정을 하세요~\n";
	cout << "1 : 가위, 2 : 바위, 3 : 보 \n";
	cout << "선택 : ";
	cin >> cho;

	return cho;
}

void bye()
{
	cout << "다음에 만나요~\n";
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
		cout << " 나 ☞ 가위	 [VS]	 가위 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 비겼습니다 .... \n\n";
	}
	else if (cCom == 2)
	{
		cout << " %s ☞ 가위	 [VS]	 바위 ☜ %s \n\n";
		Sleep(1000);
		cout << "	 ★★ 컴퓨터 우승! ★★ \n\n";
	}
	else if (cCom == 3)
	{
		cout << " %s ☞ 가위	 [VS]	 보 ☜ %s \n\n";
		Sleep(1000);
		cout << "	 ★★ 나 우승! ★★ \n\n";
		win = win + 1;
	}
}

void play2(int cCom, int win)
{
	if (cCom == 1)
	{
		cout << " 나 ☞ 바위	 [VS]	 바위 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 비겼습니다 .... \n\n";
	}
	else if (cCom == 2)
	{
		cout << " 나 ☞ 바위	 [VS]	 보 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 ★★ 컴퓨터 우승! ★★ \n\n";
	}
	else if (cCom == 3)
	{
		cout << " 나 ☞ 바위	 [VS]	 가위 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 ★★ 나 우승! ★★ \n\n";
		win = win + 1;
	}
}

void play3(int cCom, int win)
{
	if (cCom == 1)
	{
		cout << " 나 ☞ 보	 [VS]	 보 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 비겼습니다 .... \n\n";
	}
	else if (cCom == 2)
	{
		cout << " 나 ☞ 보	 [VS]	 가위 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 ★★ 컴퓨터 우승! ★★ \n\n";
	}
	else if (cCom == 3)
	{
		cout << " 나 ☞ 보	 [VS]	 바위 ☜ 컴퓨터 \n\n";
		Sleep(1000);
		cout << "	 ★★ 나 우승! ★★ \n\n";
		win = win + 1;
	}
}

void start()
{
	cout << "☆★☆가위 바위 보 게임☆★☆\n";
	cout << "나 VS 컴퓨터\n\n";
}

int result()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cell(int accumulate)			// 사칙연산 게임		// 선언시 acc는 1으로		// 게임설명 : 돈을 배팅하고 문제 맞힌 수 만큼 배팅한 돈에 곱해짐
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

	cout << "종목을 선택하십시오. ( +, -, /, * )" << endl;
	cin >> cho;
	cout << "문제 수를 입력하세요." << endl;
	cin >> cho_num;

	for (i = 0; i < cho_num; i++)
	{
		switch (cho) {
		case '+':
			cout << "덧셈을 선택하셨습니다." << endl;
			cout << rand_num1 << "+" << rand_num2 << "=";
			answer_result = rand_num1 + rand_num2;
			cin >> input_result;
			break;
		case '-':
			cout << "뺄셈을 선택하셨습니다." << endl;
			cout << rand_num1 << "-" << rand_num2 << "=";
			answer_result = rand_num1 - rand_num2;
			cin >> input_result;
			break;
		case '*':
			cout << "곱셈을 선택하셨습니다." << endl;
			cout << rand_num1 << "*" << rand_num2 << "=";
			answer_result = rand_num1 * rand_num2;
			cin >> input_result;
			break;
		case '/':
			cout << "나눗셈을 선택하셨습니다." << endl;
			if (rand_num2 == 0)
			{
				rand_num2 = rand_num2 + 1;
			}
			cout << rand_num1 << "/" << rand_num2 << "=";
			answer_result = rand_num1 / rand_num2;
			cin >> input_result;
			break;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			return 0;
		}
		if (answer_result == input_result)
		{
			cout << "정답입니다." << endl;
			count = count + 1;
			cout << "현재 스코어는 " << count << "입니다." << endl;
		}
		else {
			cout << "에휴" << endl;
		}
		rand_num1 = rand() % ((cho_num + count)*accumulate);
		rand_num2 = rand() % ((cho_num + cho_num)*accumulate);
	}

	if (count == cho_num)
	{
		cout << "좀 하는데?\n 널 위한 x" << doubleshot << "판이 있다구 ~ " << endl;
		cout << "쫄려?" << endl;
		cout << "쫄리면 0번, 남자면 1번을 눌러주세용~" << endl;
		doubleshot = doubleshot * 2;
		cin >> cho_doubleshot;
		if (cho_doubleshot == 1)
		{
			accumulate = doubleshot * count;
			cout << "그래 ~ 본전은 뽑아야지 ~" << endl;
			cell(accumulate);
		}
		else if (cho_doubleshot == 0)
		{
			cout << "아 ~ 그정도 밖에 안되는구나?" << endl;
			accumulate = accumulate - 1;
			doubleshot = 2;
			return accumulate;
		}
	}
	else {
		doubleshot = 2;
		cout << "에휴. ㅉㅉㅉ" << endl;
		return 0;
	}
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void say()		// 탕수육 게임
{
	char Input_say[] = { 0, };

	cout << "탕수육 게임입니다." << endl;
	cout << "게임 진행을 원하시는 문장을 입력해주세용 :";
	cin >> Input_say;


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void baseball()			// 야구 게임
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
		cout << "숫자 세개를 입력해주세요." << endl << "숫자와 숫자사이는 띄어쓰기를 해주세요" << endl << "숫자는 중복 입력이 불가합니다" << endl;
		cin >> Input_Num[0] >> Input_Num[1] >> Input_Num[2];
		if ((Input_Num[0] == Input_Num[1]) || ((Input_Num[0] == Input_Num[2]) || (Input_Num[1] == Input_Num[2])))
		{
			cout << endl << "다시 입력해주세요" << endl;
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
		cout << i << "회차" << Strike_Count << " S" << Ball_Count << " B" << endl;

		if (Strike_Count == 3)
		{
			break;
		}

		Strike_Count = 0;
		Ball_Count = 0;
	}

	cout << (Strike_Count == 3 ? "승리하셨습니다" : "패배 ㅉ") << endl;


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