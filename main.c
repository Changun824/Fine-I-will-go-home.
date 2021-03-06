/*
프로그램명: Learning support Program 용도: 학습에 있어 도움을 줌
활용 계획: Life support program등 헬스케어로 나아가고자 함.
프로그램 기간: 2016-11월 14일~ 2016-12월 9일
팀명: 됐어, 나집에갈래     7조
팀원: 2013244007 안창언
2013244010 홍성호
2013244068 형성재
2013244111 이석훈
과목명: 오픈 소스 소프트웨어  분반: 12분반  담당교수: 김봉재 교수님
*/

#include<stdio.h> //표준 입출력 라이브러리
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <string.h>
#define UP 72//위쪽 방향키
#define DOWN 80//아래쪽 방향키
//================================================================-changun
#define LEFT 75// 왼쪽 방향키
#define RIGHT 77//오른쪽 방향키
#define MAX 100 //Changun 씀 행렬 계산을 위해 사용
//================================================================-changun
#define ENTER 13//엔터키
#define ESC 27//ESC 키
//=====sung ho===========
#define WORDCOUNT 1000
#define SUBJECT 8 //과목 수
//=====sung ho===========

//================================================================== - sungho
typedef struct wordlist {
	char name[100]; //단어
	char mean[200]; //뜻
}VOCA;
VOCA a[WORDCOUNT];

typedef struct subject {
	char name[20];//과목이름
	int day_study;//일일 공부시간
	int week_study[7];//월화수목금토일 공부시간
}STAT;
STAT b[SUBJECT];
//================================================================ - sungho

//================================================================-sungjae
typedef struct user {//사용자 입력 시간 구조체
	int hour;//시
	int min;//분
	int sec;//초
}USER;
typedef struct plan {
	char pi1[50], pi2[50], pi3[50], pi4[50], pi5[50], pi6[50], pi7[50], pi8[50], pi9[50], pi10[50], pi11[50], pi12[50], pi13[50], pi14[50], pi15[50], pi16[50];
	//pi1~16배열은 1주차부터 16주차까지의 계획저장 변수
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10], c11[10], c12[10], c13[10], c14[10], c15[10], c16[10];
	//달성 체크시 사용
}PLAN;//PLAN구조체는 계획 문자열 저장하기 위해서 사용
typedef struct tt {
	char st1[50], st2[50], st3[50], st4[50], st5[50], st6[50], st7[50], st8[50];
	//1~10교시까지의 과목이름을 입력받기 위한 배열
}TT;
//================================================================-sungjae


//함수 넣는존
//===============================================================-main
void main_menu();
int menu_switch();
//===============================================================-main
//===================================================-changun
void Calculator_Menu(); //계산기 메인 메뉴
void Matrix_Menu(); //행렬 계산 메뉴
int calculator_key();// 계산기 메뉴에서 =>를 위한 함수
void Matrix_add(); //행렬 덧셈
int Matrix_key();  // 행렬 좌표 값
void Matrix_mul(); // 행렬 곱셈
void stop_watch(); //스톱워치
void stopwatch_menu(); //스톱 워치 메뉴
void main_Calculator(); //계산기 메인 메뉴
int calculator_switch();// 일반 계산기에서 좌우로 움직일 함수
int arithmetic_menu();  //일반 계산기 몸통
int calculator(); //사칙연산 계산 함수
int stack_push2(); //뺄셈을 위한 스택 함수
void stack_pop(int num); //스택 함수
int stack_push(); //덧셈을 위한 스택 함수
void stack_calculator_Menu(); // 일반 계산기 메뉴
int stack_fix[MAX], top = 0; //stack을 활용하기 위한 전역변수
void inverse_matrix_Menu();// 역행렬 계산
						   //==================================================-changun
						   //================================================-SungHo
void gotoxy(int x, int y);//좌표 함수
void menu_scr(void);//단어장 메뉴화면을 출력하는 함수
void Function(int y);//단어장 해당 메뉴에 접속하는 함수
int MenuChoice(void); //단어장 메뉴를 가리키는 화살표를 이동시키는 함수
void AddWord(void);//단어장 단어추가 기능
void SearchWord(void);//단어장 단어검색 기능
void WordListCheck(void);//단어장 저장내용 확인기능
void ProgramRead(void);//단어장 파일만드는 함수
void Quiz(void);//단어장 단어 퀴즈 기능
void del(void);//단어장 단어삭제 기능
void Statistics_Menuscr(void);//학습량 통계 메뉴
void Stat_Function(int y);//학습량 통계 메뉴 인터페이스
void Stat_ProgramRead(void);//학습량 통계 최초 파일 생성 함수
int Stat_Menuchoice(void);//학습량 통계 메뉴 인터페이스
void AddSubject(void);//학습량 통계표 과목 추가
void DelSubject(void);//학습량 통계 과목 삭제기능
int WhatDay(void);//오늘 요일 계산 함수
void Measure(void);//학습량 측정 기능
void StudyCheck(void);//학습량 확인 기능
void WeekStudyReset(int day);//주간 학습량 초기화
int DayReset(void);//일일 학습량 초기화
void Decision(void);//일일 학습량 초기화 인터페이스 메뉴
void YesorNo(int x);//일일 학습량 초기화 인터페이스
					//================================================-SungHo
					//================================================-seokhoon
void calender();
//================================================-seokhoon
//===============================================-sungjae
int learnchoice();//학습계획표 키보드 값으로 메뉴선택
int threemenu1();//계획입력메뉴 키보드 값으로 선택
int threemenu2();//달성체크메뉴 키보드 값으로 선택
int threemenu3();//달성률메뉴 키보드 값으로 선택
int threemenu4();//시간표메뉴 키보드 값으로 선택
int alarm();//알람함수
int timer();//타이머함수
int learn_menu();//학습계획표 메뉴함수
void learningplanner();//학습계획표 기능선택함수
int planinsertmenu();//계획 입력메뉴
int planinsert();//계획 입력 함수
int achievementcheckmenu();//달성체크메뉴
int achievementcheck();//달성체크함수
int achievementlookmenu();//달성률메뉴
int achievementrate();//달성률보기함수
int timetablemenu();//시간표 메뉴 출력
int timetable();//시간표 메뉴선택함수
int timetablein();//시간표 입력 함수
int timetablelook();//시간표 보기 함수
					//===============================================-sungjae

					//==================================main메뉴존
int main()
{
	int main_switch = 0;  //메인문에 스위치 값을 받기 위한 변수 - 사용자 입력 값
	int main_end = 0;   //메인문을 종료시키기 위한 변수
	int num = 0; //메인메뉴
	system("mode con: cols=70 lines=30"); //크기
	system("title Learing Support Program");  //제목 변화
	system("color 3F");
	while (1)  //프로그램 반복
	{  //while 중괄호
		system("cls");

		main_menu();        //프로그램 메인 메뉴
		num = menu_switch(); //메뉴에서 나오는 좌표를 입력 받아 키보드로 움직이는 것 처럼 나타냄
		switch (num)
		{
		case 5:                 //===========-sungjae
			system("cls");
			learningplanner();
			break;    //학습 계획표 =================-sungjae
		case 6:          //학습 통계표 =================-sungho
			system("cls");
			Stat_ProgramRead();
			DayReset();
			WeekStudyReset(WhatDay());
			Statistics_Menuscr();
			Stat_Menuchoice();
			break;//학습 통계표 =================-sungho
		case 7: // 계산기 =======================================changun
			system("cls");
			main_Calculator();
			break;// 계산기 =======================================changun
		case 8:  //단어장 =================-sungho
			system("cls");
			ProgramRead();
			menu_scr();
			MenuChoice();
			break;          //단어장 =================-sungho
		case 9: //타이머 =================-sungjae
			system("cls");
			timer();
			break;//타이머 =================-sungjae
		case 10:  //알람 =================-sungjae
			system("cls");
			alarm();
			break;  //알람 =================-sungjae
		case 11:  // 스탑워치 =======================================changun
			system("cls");
			stop_watch();
			break;// 스탑워치 =======================================changun
		case 12:  //달력 ================-seokhoon
			system("cls");
			calender();//달력   ================-seokhoon
		case 13:
			main_end = 100;
			break;
		default:
			printf("잘못 누르셨습니다.\n");
			break;
		}

		if (main_end == 100)    //종료를 위해 쓰인 if문과 변수
		{
			system("cls");
			printf("프로그램을 종료합니다.\n");
			exit(1);  //탈출 명령어
		}//if문 - 종료 중괄호
	} //while 중괄호
	return 0;
}
//=============================================================-main
void main_menu()
{
	system("title Learing Support Program");  //제목 변화
	system("color 3F");
	printf("=====================================================================\n");
	printf("                    Learing Support Program \n");
	printf("=====================================================================\n");
	gotoxy(18, 5);
	printf(" 1. 학  습  계  획  표\n");
	gotoxy(18, 6);
	printf(" 2. 학  습  통  계  표\n");
	gotoxy(18, 7);
	printf(" 3. 계  산  기 \n");
	gotoxy(18, 8);
	printf(" 4. 단  어  장\n");
	gotoxy(18, 9);
	printf(" 5. 타  이  머\n");
	gotoxy(18, 10);
	printf(" 6. 알   람\n");
	gotoxy(18, 11);
	printf(" 7. 스 톱 워 치\n");
	gotoxy(18, 12);
	printf(" 8. 달   력\n");
	gotoxy(18, 13);
	printf(" 9. 종   료\n");
}
int menu_switch()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 16, y = 5;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			main_menu(); //메뉴창을 띄우고
			y -= 1;	   //화살표("=>")의 y좌표를 1칸 아래로 내림
			if (y <= 5)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 고정
				y = 5;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			main_menu();//메뉴창을 띄우고
			y += 1;	   //화살표("=>")의 y좌표를 1칸 위로 올림
			if (y >= 13)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 함
				y = 13;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}

}
//=============================================================-main
//===============================-changun
void main_Calculator()   //계산기 메인 메뉴
{
	int C_M = 0, CM_M = 0, End_C = 0; //End_C:메인문에서 계산기메뉴를 종료하기 위한 변수 C_M : 계산기 메뉴 CM_M : 행렬계산 메뉴 AC_M : 일반 계산기 메뉴
	while (1)
	{
		Calculator_Menu();  //계산기 메뉴를 호출하고 사용자 입력값을 돌려받음
		C_M = calculator_key();    //좌표값을 돌려주는 함수
		switch (C_M)
		{
		case 4:
			Matrix_Menu();       //행렬 계산기 메뉴 몸통
			CM_M = Matrix_key(); //행렬 계산기에서 나온 좌표값
			switch (CM_M)   //======행렬 계산기 스위치
			{
			case 4:
				Matrix_add();    //행렬 계산기 더하기
				break;
			case 6:
				system("cls");
				Matrix_mul();    //행렬 곱셈 함수
				break;
			case 8:
				inverse_matrix_Menu();      //역행렬 메뉴
				break;
			case 10:
				main(); //메인으로 돌아가게함
				break;
			default:
				printf("잘못 누르셨습니다.\n");
				break;
			} //==============행렬 계산기 스위치
			break;
		case 6:
			system("cls");
			arithmetic_menu(); //일반 계산기 메뉴
			break;
		case 8:
			End_C = 10; //End_c에 10을 넣어줘서 반복문 탈출
			break;
		default:
			break;
		}//C_M _ switch문 중괄호
		if (End_C == 10)
			break;//계산기 while에 따른 브레이크
	}//main_switch_num_case 3: while 중괄호
}

void Calculator_Menu()  //계산기 메뉴
{
	system("title Calculator");  //제목 변화
	system("color 1F");
	system("cls");
	printf("=====================================================================\n");
	printf("                      C a l c u l a t o r \n");
	printf("=====================================================================\n");
	gotoxy(4, 4);
	printf(" 1.행렬 계산기\n\n");
	gotoxy(4, 6);
	printf(" 2.일반 계산기\n\n");
	gotoxy(4, 8);
	printf(" 3.되돌아가기\n\n");
}
int calculator_key()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 2, y = 4;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			Calculator_Menu(); //메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 4)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 고정
				y = 4;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			Calculator_Menu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 8)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 함
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}

void Matrix_Menu()        //행렬 계산기 메뉴
{
	system("title Matrix Calculator");  //제목 변화
	system("cls");
	printf("=====================================================================\n");
	printf("              M a t r i x  C a l c u l a t o r\n");
	printf("=====================================================================\n");
	gotoxy(4, 4);
	printf(" 1.행렬 덧셈\n\n");
	gotoxy(4, 6);
	printf(" 2.행렬 곱셈\n\n");
	gotoxy(4, 8);
	printf(" 3.역행렬 계산\n\n");
	gotoxy(4, 10);
	printf(" 4.나가기\n");
}

int Matrix_key()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 2, y = 4;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			Matrix_Menu(); //메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 4)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 고정
				y = 4;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			Matrix_Menu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 10)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 함
				y = 10;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}

void Matrix_add()  //행렬 덧셈
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int exsum[MAX][MAX];
	int matrix_mrow;
	int matrix_mcolumn;
	int i = 0, j = 0;
	system("cls");
	system("title 행렬 덧셈");  //제목 변화
	printf("=====================================================================\n");
	printf("                     M a t r i x   A d d \n");
	printf("=====================================================================\n");
	printf("더해줄 행렬은 같은 크기여야 합니다.\n");
	printf("\n");
	printf("덧셈 할 행렬의 행의 크기를 입력해주세요:");
	printf("\n");
	scanf_s("%d", &matrix_mrow);
	printf("덧셈 할 행렬의 열의 크기를 입력해주세요:");
	printf("\n");
	scanf_s("%d", &matrix_mcolumn);
	system("pause");

	system("cls");
	system("title 첫번째 행렬 입력");  //제목 변화
	printf("=====================================================================\n");
	printf("                     F i r s t   M a t r i x\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("첫번째 행렬 \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("행렬 A[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력
	system("cls");
	system("title 두번째 행렬 입력");  //제목 변화
	printf("=====================================================================\n");
	printf("                    S e c o n d   M a t r i x \n");
	printf("=====================================================================\n");
	printf("\n");
	printf("두번째 행렬 \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("행렬 B[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//두번째 행렬 입력
	system("cls");
	system("title 두행렬의 합");  //제목 변화
	printf("=====================================================================\n");
	printf("                    M a t r i x  Add\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("\n");
	printf("첫번째 행렬\n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exone[i][j]);
		} //행을 출력
	}//열을 출력
	printf("\n");
	printf("\n");
	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_mrow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", extwo[i][j]);
		} //행을 출력
	}//열을 출력


	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			exsum[i][j] = exone[i][j] + extwo[i][j];
		}//두번째 행렬 입력

	}
	printf("\n");
	printf("\n");
	printf("덧셈한 행렬 \n");
	printf("\n");
	for (i = 0; i < matrix_mrow; i++)
	{
		for (j = 0; j < matrix_mcolumn; j++)
		{
			printf("%d\t", exsum[i][j]);
		} //행을 출력
		printf("\n");
	}//열을 출력
	system("PAUSE");

}// void Matrix_add() 함수 종료 중괄호

void Matrix_mul()  //행렬 곱셈 함수
{
	int exone[MAX][MAX];
	int extwo[MAX][MAX];
	int sum[MAX][MAX];
	int matrix_arow, matrix_acolumn;
	int matrix_bcolumn, matrix_brow;
	int i = 0, j = 0, z = 0;
	system("cls");
	system("title 행렬 곱셈");
	printf("=====================================================================\n");
	printf("                      MATRIX MULTIPCATION\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("곱하기를 할 A[m][n], B[m][n]은 A[n]과 B[m]이 같아야 합니다\n ");
	printf("\n");
	printf("곱셈 할 행렬의 A행렬의 크기를 입력해주세요 A[m][n]:");
	printf("\n");
	scanf_s("%d %d", &matrix_arow, &matrix_acolumn);

	printf("곱셈 할 행렬의 B행렬의 크기를 입력해주세요:");
	printf("\n");
	scanf_s("%d %d", &matrix_brow, &matrix_bcolumn);
	if (matrix_acolumn != matrix_brow)
	{
		system("cls");
		system("title Error");
		printf("=====================================================================\n");
		printf("                      MATRIX MULTIPCATION\n");
		printf("=====================================================================\n");
		printf("곱하기가 불가능한 행렬 입니다.\n");
		return;
	}
	system("cls");
	system("title Amatrix");
	printf("=====================================================================\n");
	printf("                         A MATRIX\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("첫번째 행렬 \n");
	for (i = 0; i < matrix_arow; i++)
		for (j = 0; j < matrix_acolumn; j++)
		{
			printf("exone[%d][%d]", i, j);
			scanf("%d", &exone[i][j]);
		}//첫번째 행렬 입력
	system("cls");
	system("title Bmatrix");
	printf("=====================================================================\n");
	printf("                         B MATRIX\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("두번째 행렬 \n");
	for (i = 0; i < matrix_brow; i++)
		for (j = 0; j < matrix_bcolumn; j++)
		{
			printf("extwo[%d][%d]", i, j);
			scanf("%d", &extwo[i][j]);
		}//두번째 행렬 입력
	printf("\n");
	//곱을 위한 포문
	for (i = 0; i < matrix_arow; i++)
	{
		for (j = 0; j < matrix_bcolumn; j++)
		{
			sum[i][j] = 0;
			for (z = 0; z < matrix_brow; z++)
			{
				sum[i][j] = sum[i][j] + exone[i][z] * extwo[z][j];
			}
		}//곱해줄 행렬 계산
	}//곱에 필요한 for문

	system("cls");
	system("title MATRIX MULTIPCATION");
	printf("=====================================================================\n");
	printf("                         MATRIX MULTIPCATION\n");
	printf("=====================================================================\n");
	printf("\n");
	printf("첫번째 행렬\n");
	for (i = 0; i < matrix_arow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_acolumn; j++)
			printf("%d \t", exone[i][j]);
	} //첫번째 행렬 중괄호

	printf("\n");
	printf("두번째 행렬\n");
	for (i = 0; i < matrix_brow; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_bcolumn; j++)
			printf("%d \t", extwo[i][j]);
	} //두번째 행렬 중괄호

	printf("\n");
	printf("행렬을 곱한 값\n");
	for (i = 0; i < matrix_acolumn; i++)
	{
		printf("\n");
		for (j = 0; j < matrix_brow; j++)
			printf("%d \t", sum[i][j]);
	} //합을 출력하는 중괄호
	printf("\n");
	system("PAUSE");
}//행렬 곱셈 함수 종료
int arithmetic_menu()
{
	int a = 0, num = 0, count = 0, sum = 0;
	system("cls");
	system("title 사칙연산 계산기");
	while (1)
	{
		stack_calculator_Menu();
		a = calculator_switch();
		switch (a)
		{
		case 2:
			calculator();
			break;
		case 17:
			printf("\n");
			for (; top != 0;)
			{
				sum = stack_push();

			}
			printf("%d \n", sum);
			sum = 0;
			printf("\n");
			system("pause");
			break;
		case 32:
			printf("\n");
			for (; top != -1;)
			{
				sum = stack_push2();
				stack_pop(sum);
			}
			printf("%d", sum);
			sum = 0;
			printf("\n");
			system("pause");
			break;
		case 47:
			sum = 0, stack_fix[MAX] = 0, top = 0;
			printf("클리어 되었습니다.\n");
			break;
		case 62:
			printf("\n");
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void inverse_matrix_Menu()
{
	float matrix[2][2];
	float inverse[2][2];
	float  det = 0;
	int i = 0, j = 0;
	system("cls");
	system("title 역행렬 계산");
	printf("=====================================================================\n");
	printf("                   i n v e r s e m a t r i x \n");
	printf("=====================================================================\n");

	printf("2X2행렬만 됩니다. \n");
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		printf("%d행 입력 \n", i + 1);
		for (j = 0; j < 2; j++)
		{
			printf("행렬 A[%d][%d]", i, j);
			scanf("%f", &matrix[i][j]);
		}// 행렬의 요소를 입력
	}
	det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	if (det == 0.0)
	{
		printf("역행렬이 존재하지 않습니다.\n");
		return 1;
	}// det를 구하기( a*d - b*c)

	 // 여인자행렬의 전치행렬구하기
	inverse[0][0] = matrix[1][1] / det;
	inverse[0][1] = -matrix[0][1] / det;
	inverse[1][0] = -matrix[1][0] / det;
	inverse[1][1] = matrix[0][0] / det;

	system("cls");
	printf("=====================================================================\n");
	printf("                   i n v e r s e m a t r i x \n");
	printf("=====================================================================\n");
	// 역행렬 출력
	printf("\n");
	printf("==================== 역 행 렬 ===================\n");
	printf("입력한 행렬:");
	for (i = 0; i < 2; i++)
	{
		printf("\n");
		for (j = 0; j < 2; j++)
		{
			printf("%.2f ", matrix[i][j]);
		}
	}

	printf("\n");
	printf("이 행렬의 역행렬\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%.2f ", inverse[i][j]);
		}
		printf("\n");
	}
	system("pause");
}




void stack_calculator_Menu()
{
	system("cls");
	printf("=====================================================================\n");
	printf("                      C a l c u l a t o r \n");
	printf("=====================================================================\n");
	gotoxy(4, 3);
	printf("사칙 연산      모두더하기      모두 빼기      클 리 어      나가기\n");
	printf("\n");
}

void stack_pop(int num)
{
	stack_fix[top] = num;
	top++;
}
int stack_push()
{
	int x = 0, y = 0, sum = 0;
	top--;
	x = stack_fix[top];
	stack_fix[top] = 0;
	top--;
	y = stack_fix[top];
	stack_fix[top] = 0;
	sum = x + y;

	stack_pop(sum);
	return sum;
}
int stack_push2()
{
	int x = 0, y = 0, sum = 0;
	top--;
	x = stack_fix[top];
	stack_fix[top] = 0;
	top--;
	y = stack_fix[top];
	sum = y - x;
	return sum;
}



int calculator_switch()
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 2, y = 3;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키를 입력 받으면
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case LEFT: //위쪽 방향키를 입력받으면
			system("cls");
			stack_calculator_Menu(); //메뉴창을 띄우고
			x -= 15;	   //화살표("=>")의 x좌표를 15칸 왼쪽으로 이동
			if (x <= 2)  //화살표("=>")의 x좌표가 메뉴 왼쪽으로는 고정
				x = 2;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case RIGHT://아래쪽 방향키를 입력받으면
			system("cls");
			stack_calculator_Menu();//메뉴창을 띄우고
			x += 15;	   //화살표("=>")의 x좌표를 15칸 오른쪽으로 이동
			if (x >= 62)  //화살표("=>")의 x좌표가 메뉴 오른쪽더 안가게 이동
				x = 62;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("color 07");
			return 0;

		case ENTER://엔터키를 입력받으면
			return x;
		}

	}

}



int calculator()
{
	int a, b, sum = 0;
	char letter;
	while (1)
	{
		printf("\n");
		printf("\n");
		printf("＃나가려면 e를 입력하세요.\n");
		printf("연산자입력 : ");
		scanf("\n%c", &letter);
		if (letter == 'e')
			break;
		printf("첫번째 수 입력:");
		scanf_s("%d", &a);
		printf("두번째 수 입력:");
		scanf_s("%d", &b);

		switch (letter)
		{
		case '+':
			sum = a + b;
			printf("%d + %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		case '-':
			sum = a - b;
			printf("%d - %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		case '*':
			sum = a*b;
			printf("%d * %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		case '/':
			sum = a / b;
			printf("%d / %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;
		case '%':
			sum = a%b;
			printf("%d %% %d = %d \n", a, b, sum);
			stack_pop(sum);
			break;

		default:
			printf("연산자 입력 오류! \n");
			break;
		}
	}
	return 0;
}

void stop_watch()  //스탑 워치 함수
{
	int hour = 0, min = 0, sec = 0, frame = 0;
	char ch;
	FILE *fp;
	fp = fopen("stopwatch.txt", "w");
	system("cls");
	system("title Stop Watch");  //제목 변화
	system("color 5F");
	printf("=====================================================================\n");
	printf("                       S t o p  W a t c h \n");
	printf("=====================================================================\n");
	system("pause");
	stopwatch_menu();
	while (1)
	{
		printf("%2d : %2d : %2d : %2d", hour, min, sec, frame);
		Sleep(10);
		frame++;
		if (frame == 100)
		{
			sec++;
			frame = 0;
		}
		if (sec == 60)
		{
			min++;
			sec = 0;
		}
		if (min == 60)
		{
			hour++;
			min = 0;
		}

		if (kbhit())
		{
			ch = getch();
			switch (ch)
			{
			case 'S': case 's':
				ch = getch();
				break;
			case 'R': case 'r':
				system("cls");
				stopwatch_menu();
				hour = min = sec = frame = 0;
				break;
			case 'Q': case 'q':
				fprintf(fp, "%2d : %2d : %2d : %2d", hour, min, sec, frame);
				printf("\n");
				fclose(fp);
				return;
			case 'W': case 'w':
				printf("\n");
				printf("\t\t ");
				break;
			default:
				break;
			} //키보드로 부터 입력 받은 값에 대한 switch
		} // if문 키보드로 부터 무엇인가 입력 받았다면
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}// 시간에 대한 반복문 중괄호
} // 스탑워치 메인 코드 함수
void stopwatch_menu()  //스탑 워치 메뉴
{
	system("cls");
	printf("=====================================================================\n");
	printf("                       S t o p  W a t c h \n");
	printf("=====================================================================\n");
	printf("S:시작/멈춤 \nW: 기록\nR:리셋\nQ:나가기\n");
	printf("시 : 분 : 초 :0.01초\n");
}



//================================================-changun

//================================================-SungHo
void gotoxy(int x, int y) //좌표함수 콘솔창내 커서의 좌표지정
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int MenuChoice(void)
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 47, y = 11;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			menu_scr();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 11)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 11;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			menu_scr();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 19)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 19;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			system("mode con: cols=70 lines=30"); //크기
			system("title Learing Support Program");  //제목 변화
			system("color 3F");
			return 0;

		case ENTER://엔터키를 입력받으면
			Function(y);
		}

	}

}

void menu_scr(void)//메뉴 화면을 출력
{
	system("title 단어장");//콘솔의 제목을 바꿔줌
	system("color EC");//콘솔창의 배경색과 텍스트의 색을 바꿔줌  (배경:텍스트) E:노랑C:빨강
	system("mode con: cols=115 lines=30");
	printf("=======================================");
	gotoxy(50, 11);
	printf("◆단어 검색\n");
	gotoxy(50, 13);
	printf("◆단어 추가\n");
	gotoxy(50, 15);
	printf("◆단어장 확인\n");
	gotoxy(50, 17);
	printf("◆단어 퀴즈\n");
	gotoxy(50, 19);
	printf("◆단어 삭제\n");
	gotoxy(46, 23);
	printf("※프로그램 종료 [ESC]\n");

}

void Function(int y)
{
	if (y == 11)//단어 검색 화살표("=>")의 y좌표를 가져와서 화살표가 가리키는 메뉴를 실행
	{
		system("cls");
		SearchWord();
	}
	if (y == 13)//단어 추가 실행
	{
		system("cls");
		AddWord();
	}
	if (y == 15)//단어 확인 실행
	{
		system("cls");
		WordListCheck();
	}
	if (y == 17)//단어 퀴즈 실행
	{
		system("cls");
		Quiz();
	}
	if (y == 19)//단어 퀴즈 실행
	{
		system("cls");
		del();
	}

}

void AddWord(void)//단어 추가 기능
{
	int i = 0, key; //i for문 실행에 쓰일 변수 ,key: ENTER키나 ESC키로 받은 값을 저장받음
	int count;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "a")) == NULL)
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (1)
	{
		printf("추가하실 단어를 입력해주세요\n");
		gets(a[i].name);
		printf("단어의 뜻을 입력해주세요\n");
		gets(a[i].mean);
		i++;
		printf("단어를 더 추가합니까? 추가[ENTER] 종료[ESC]\n");//단어를 한 개 추가하고 나서 계속 추가할 것인지 키를 입력받아 사용자의 의사를 묻는다
		key = getch();										    //ENTER는 더 추가 ESC를 입력하면 종료 N
		if (key == 0xE0 || key == 0)
			key = getch();
		if (key == 27)//ESC키를 입력하면
		{
			system("cls");
			break;   //루프를 종료:[단어 검색]기능을 종료
		}
		else if (key == 13)//ENTER키를 입력하면 콘솔창을 깨끗하게 지우고 다시 처음 루프로 가서 추가할 단어를 입력받음
		{
			system("cls");
		}
		else {//ENTER 와 ESC가 아닌 키를 입력했을 경우
			while (1)
			{
				system("cls");
				printf("추가[ENTER] 또는 종료[ESC] 키를 입력하세요\n"); //ENTER나 ESC를 입력할때까지 안내 메세지를 띄우고
				key = getch();
				if (key == 0xE0 || key == 0);
				key = getch();
				if (key == 13)//Enter를 입력받으면 이 루프를 빠져나가 단어를 새로 입력받고
				{
					system("cls");
					break;
				}
				else if (key == 27)//ESC를 누르면
				{
					system("cls");
					goto label;   //이중 루프를 빠져나가서 기능이 종료되게끔 한다.
				}
			}

		}

	}
label:
	count = i;
//goto 문으로 빠져나오는 곳
	for (i = 0; i<count; i++) {//추가된 단어와 뜻을 단어와 뜻이 저장되어 있는 텍스트 파일 안에 전부 이어써준다.
		fputs(a[i].name, fp);
		fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
		fputs(a[i].mean, fp);
		fputc('\n', fp);
	}
	fclose(fp);
	menu_scr();
}

void SearchWord(void)//단어검색
{
	int i = 0, count;//count는 불러온 단어의 개수를 저장할 변수
	int key;//입력받은 키 값을 저장하기 위한 변수
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//읽기모드로 단어와 뜻이 저장된 파일을 연다.
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))//단어와 뜻을 불러온다.
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';//fgets의 특성상  붙게되는 개행문자의 제거를 위해 널 문자로 덮어씌움
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';//fgets의 특성상  붙게되는 개행문자의 제거를 위해 널 문자로 덮어씌움
		i++;
	}
	fclose(fp);
	count = i - 1;//불러온 단어의 개수 저장
	while (1) {
		int found = 0;//찾는 단어가 있었는지 없었는지 체크하기 위한 변수 단어를 찾을때마다 1씩 증가하고 찾는 단어가 있었을때 값이 1감소되기 때문에 찾는 단어가 없었다면 count의 값과 같아짐
		char target[100];
		char esc[8] = "종료.";
		printf("찾을 단어 또는 단어의 의미를 입력해주세요.종료하려면 [종료.]입력\n");
		gets(target);
		if (!strcmp(esc, target)) {//esc에 종료.를 저장해 두었는데 만약 "종료."를 입력한다면 기능을 종료
			system("cls");
			break;
		}
		for (i = 0; i<count; i++)//불러온 단어의 수만큼 순차 검색을 해서
		{
			found++;
			if (!strcmp(a[i].name, target) || !strcmp(a[i].mean, target))//찾으려고 입력한 값[단어나 뜻]과 같은것이 불러온 단어중에 있다면
			{
				system("cls");//콘솔창을 한 번 지우고
				printf("%s: %s\n", a[i].name, a[i].mean);//찾은 단어와 뜻을 출력해줌
				found--;//찾는 단어가 있었다는걸 체크하기 위해 found값을 1감소
			}
			if (found == count)//다 찾았봤지만 찾는 단어가 없어서 found값이 count값과 같아졌다면
				printf("찾는 단어가 없습니다\n");
		}
		while (1) {
			printf("더 찾으시겠습니까? [ENTER]찾기,[ESC]종료\n");
			key = getch();
			if (key == 27)//ESC를 입력받았을때
			{
				system("cls");
				goto label;//이중루프 탈출
			}
			else if (key == 13)//ENTER를 입력받았을때
			{
				system("cls");
				break;
			}
			else
			{
				printf("[ENTER]찾기,[ESC]종료\n");
			}
		}
	}
label://goto 문이 빠져나오는 라벨
	menu_scr();
}

void WordListCheck(void)//저장된 단어를 전부 확인하는 기능
{
	int i = 0;
	int key;//키 값을 저장하기 위한 변수
	int count;//불러온 단어의 수를 저장
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//단어와 뜻이 저장 되어있는 파일을 읽기모드로 연다
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))//파일내의 단어와 뜻을 전부 읽어옴
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);//파일을 닫음
	count = i - 1;//count에 불러온 단어의 개수를 저장
	for (i = 0; i<count; i++)//불러온 단어의 수만큼 단어와 뜻을 전부 출력해줌
		printf("[ %s : %s ]\n", a[i].name, a[i].mean);
	printf("\n종료하시겠습니까?ESC입력\n");
	while (1) {
		key = getch();//키 값을 int형으로 입력받음
		if (key == 27)//ESC키를 입력 받았을때
		{
			system("cls");
			break;//루프를 빠져나와 기능종료
		}
	}
	menu_scr();//메뉴로 돌아감
}

void ProgramRead(void)//프로그램 최초 실행시 파일을 생성해준다.
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("Voca.txt", "a")) == NULL)//이어쓰기 모드로 파일을 열어준다 만약 파일이 없다면 파일을 생성한다.
	{
		fprintf(stderr, "Voca.txt 파일을 열 수 없습니다.\n", "Voca.txt");
		exit(1);
	}
	fclose(fp);//파일 닫음
}
void Quiz(void) {//퀴즈 기능
	int i = 0, count, j = 0, k, good = 0;//count는 불러온 단어의 수가 저장됨,good은 정답의 개수가 저장됨
	int key;//키 값을 저장할 변수
	char input[100];//사용자에게 입력받은 문자가 저장됨
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//단어와 뜻이 저장되어 있는 파일을 읽기모드로 연다
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))//파일에서 단어와 뜻을 전부 읽어와서 구조체 변수에 저장
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0'; //fgets의 개행문자를 제거하기 위해 널문자로 덮어써준것
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);//파일을 닫아줌
	count = i - 1;//count에 불러온 단어의 개수를 저장
	printf("단어 퀴즈는 단어장 안에 있는 단어중 5개의 단어의 설명이 랜덤으로 나옵니다\n\n");
	Sleep(2500);//실행 지연 함수 2.5초
	printf("단어의 설명을 보고 어떤 단어를 설명하고 있는지 해당하는 단어를 키보드로 입력해주세요\n\n");
	Sleep(2500);
	printf("그럼 시작합니다.\n");
	Sleep(1500);//1.5초
	for (j = 0; j<5; j++) {//퀴즈는 5문제로 구성했기에 5번 루프
		srand((unsigned)time(NULL));//시드값을 넣은 난수를 생성해줌
		i = rand() % count;//0부터 count[불러온 단어의 개수]까지의 수중 랜덤으로 생성된 난수를 i에 저장
		system("cls");
		printf("[%s]는 무엇일까요?:\n", a[i].mean);//i를 인덱스값으로 하는 단어의 뜻을 퀴즈의 문제로 출력해 사용자에게 보여줌
		gets(input);//답을 입력받음
		if (!strcmp(a[i].name, input))//입력받은 답과 해당 인덱스의 단어가 같다면
		{
			printf("정답입니다\n");
			Sleep(1000);
			good++;
		}
		else//틀렸다면
		{
			for (k = 2; k>0; k--)//두 번의 기회를 더 주기 위해 2번루프
			{

				printf("틀리셨습니다. 잘 생각해 보세요\n");
				printf("남은 기회 [%d]번", k - 1);
				gets(input);
				if (!strcmp(a[i].name, input))//맞으면 빠져나감
				{
					system("cls");
					printf("정답입니다\n");
					good++;
					break;
				}
			}
		}
	}
	printf("5문제중 맞은 개수는 %d개 입니다\n", good);//정답의 개수를 출력해줌
	while (1)
	{
		printf("다시 하시겠습니까? 예ENTER 아니오ESC\n");
		key = getch();//키 값을 입력받음
		if (key == 13)//ENTER
		{
			system("cls");
			Quiz();//다시 QUIZ함수 실행
		}
		if (key == 27)//ESC키 입력
		{
			system("cls");
			break;//콘솔창을 한번 지워주고 종료
		}
		else
		{
			system("cls");
			printf("잘못 누르셨습니다 다시하기 ENTER 아니오ESC");
		}
	}
	menu_scr();//메뉴로 복귀
}
void del(void)//단어 삭제 함수
{
	int i = 0, count;//count는 불러온 단어의 개수가 저장됨
	char target[100];//사용자가 입력한 문자가 저장됨
	FILE *fp;
	if ((fp = fopen("Voca.txt", "r")) == NULL)//읽기모드 단어와 뜻이 저장되어 있는 텍스트 파일을 연다
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	while (!feof(fp))//저장된 단어와 뜻을 읽어옴
	{
		fgets(a[i].name, 100, fp);
		a[i].name[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].mean, 100, fp);
		a[i].mean[strlen(a[i].mean) - 1] = '\0';
		i++;
	}
	fclose(fp);//파일 닫음
	count = i - 1;//count에 불러온 단어의 수가 저장됨
	printf("삭제하실 단어를 입력하세요\n");
	gets(target);//삭제할 단어를 입력받음
	for (i = 0; i<count; i++)//불러온 단어의 개수 만큼 순차검색해서
	{
		if (!strcmp(a[i].name, target))//입력한 값과 일치하는것이 있다면
		{
			printf("[%s]를 단어장에서 제거합니다.\n", a[i].name);
			strcpy(a[i].name, "\0");//해당 단어가 저장된 변수를 널값으로 바꿔줌
			strcpy(a[i].mean, "\0");//해당 뜻이 저장된 변수를 널값으로 바꿔줌
		}

	}
	if ((fp = fopen("Voca.txt", "w")) == NULL)//단어장의 /텍스트 파일을 다시 쓰기 모드로 연다
	{
		fprintf(stderr, "파일 Voca.txt를 열 수 없습니다\n", "Voca.txt");
	}
	for (i = 0; i<count; i++)
	{
		if ((strcmp(a[i].name, "\0")) != 0)//만약 단어가 저장된 변수의 값이 널값이 아닐경우만 갱신된 정보를 덮어씀
		{
			fputs(a[i].name, fp);
			fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
			fputs(a[i].mean, fp);
			fputc('\n', fp);
		}
	}
	fclose(fp);//파일을 닫음
	printf("메뉴로 돌아갑니다\n");
	Sleep(1000);
	system("cls");
	menu_scr();//메뉴로 돌아감
}


void Statistics_Menuscr(void) //메뉴를 출력해주는 함수
{
	system("title 나의 학습량");//콘솔의 제목을 바꿔줌
	system("color 9F");//콘솔창의 배경색과 텍스트의 색을 바꿔줌  (배경:텍스트) 9:파랑F:하얀색
	system("mode con: cols=115 lines=30");//콘솔 크기 고정
	printf("==========================================================================");
	gotoxy(50, 11);
	printf("◆과목 추가\n");
	gotoxy(50, 13);
	printf("◆과목 삭제\n");
	gotoxy(50, 15);
	printf("◆학습량 측정\n");
	gotoxy(50, 17);
	printf("◆학습량 확인\n");
	gotoxy(46, 23);
	printf("※프로그램 종료 [ESC]\n");
}

int Stat_Menuchoice(void) // 메뉴 선택
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 47, y = 11;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();//키 값을 int형으로 입력받음
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			Statistics_Menuscr();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 11)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 11;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			Statistics_Menuscr();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 17)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 17;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC://ESC키를 입력받으면
			system("cls");
			system("mode con: cols=70 lines=30"); //크기
			system("title Learing Support Program");  //제목 변화
			system("color 3F");
			return 0;//종료

		case ENTER://엔터키를 입력받으면
			Stat_Function(y);//Function함수를 실행
		}

	}
}

void Stat_Function(int y) // 메뉴 인터페이스 =>의 y값에 따라 ENTER를 받았을때 실행할 메뉴를 결정
{
	if (y == 11)//과목 추가
	{
		system("cls");
		AddSubject();
	}
	if (y == 13)//과목 삭제
	{
		system("cls");
		DelSubject();

	}
	if (y == 15)//학습량 측정
	{
		system("cls");
		Measure();

	}
	if (y == 17)//학습량 확인
	{
		system("cls");
		StudyCheck();

	}
}
void Stat_ProgramRead(void) // 처음에 이어쓰기 모드로 열어서 파일이 없으면 생성해줌
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("SubJect.txt", "a")) == NULL)//학습 과목을 저장할 파일
	{
		fprintf(stderr, "SubJect.txt 파일을 열 수 없습니다.\n", "SubJect.txt");
		exit(1);
	}
	fclose(fp);//파일을 닫아줌

	if ((fp = fopen("StudyNum.txt", "a")) == NULL) //학습량 수치를 저장할 파일
	{
		fprintf(stderr, "StudyNum.txt 파일을 열 수 없습니다.\n", "StudyNum.txt");
		exit(1);
	}
	fclose(fp);//파일을 닫아줌
}

void AddSubject(void) //과목 추가
{

	int i = 0, j, key,count; //i for문 실행에 쓰일 변수 ,key: ENTER키나 ESC키로 받은 값을 저장받음
	int esc;//이중 반복문 탈출용
	int fullcount = 0;//과목은 8개 까지만 저장 가능하도록 만듬 꽉차면 fullcount가8

	FILE *fp;
	if ((fp = fopen("SubJect.txt", "r")) == NULL)//과목이 저장되어 있는 텍스트 파일을 읽기모드로 열어줌
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
		exit(1);
	}
	while (!feof(fp))//과목이 저장된 파일을 읽어서 순서대로 구조체 배열에 넣어줌
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';
		i++;
	}
	fclose(fp);//파일을 닫아줌

	printf("과목을 추가가 가능한지 확인하겠습니다.\n\n");
	for (i = 0; i<SUBJECT; i++)
	{
		esc = 0;//루프 탈출용 1이 되면 탈출하게 할거라 0으로 초기화

		if ((strcmp(b[i].name, "\0")) == 0) //과목 이름이 들어가는 변수에 널값이라면 아무것도 없다면
		{
			printf("과목을 추가하실 수 있습니다.\n\n");
			printf("추가하실 과목의 이름을 입력해 주세요\n\n");
			gets(b[i].name);//과목이름을 넣어줌

			while (1)//계속할건지를 묻는 루프
			{
				printf("계속 과목을 추가하시겠습니까?\n\n예[Enter],아니오[ESC]\n");
				key = getch();
				if (key == 13)//enter를 누르면
				{
					system("cls");//이 루프를 탈출해서 다시 과목추가 진행
					break;
				}
				else if (key == 27)//esc를 누르면 이루프를 탈출하고 esc값도 1로 변해서 다음루프도 탈출함
				{
					esc = 1;
					break;
				}
				else
				{
					system("cls");//enter나 esc만 받음
				}
			}
			if (esc == 1)
			{
				break;//마지막 루프 탈출
			}
		}
		else//읽어온 구조체 배열내의 과목이름을 저장하는 변수 찾아봤는데 널값이 아닐경우
		{
			fullcount++;//fullcount값을 1증가
			if (fullcount == 8)//과목이 8개로 꽉 차있을경우
			{
				printf("학습하고 있는 과목이 8개를 초과합니다\n\n");
				Sleep(1500);
				printf("문어발식 공부는 학습에 크게 도움이 되지 않습니다.\n\n");
				Sleep(1500);
				printf("학습중인 과목을 바꾸고 싶으시면 [과목 삭제]메뉴에서 다른 과목을 한 가지 제거 해주세요\n\n");
				printf("3초 후에 메뉴로 돌아갑니다.\n");
				Sleep(3000);
				break;
			}
		}
	}

	if ((fp = fopen("SubJect.txt","w")) == NULL)//과목이 저장되는 텍스트 파일을 쓰기 모드로 열어줌
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
	}
	for (i = 0; i<SUBJECT; i++)//과목추가의 최고한도인 8개 만큼 순차검색을 한다
	{
		if ((strcmp(b[i].name, "\0")) != 0)//만약 과목이름이 저장된 변수가 널값이 아니라면 텍스트 파일에 저장해줌
		{
			fputs(b[i].name, fp);
			fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
		}
	}
	fclose(fp);//파일을 닫음
	printf("과목을 전부 추가했습니다.\n");
	Sleep(500);
	Statistics_Menuscr();//메뉴로 돌아감

}


void DelSubject(void) // 과목 삭제
{
	int i = 0, count;
	int j;
	char target[100];
	FILE *fp,*fp2;
	if ((fp = fopen("SubJect.txt", "r")) == NULL) //텍스트 파일내 과목을 전부 읽어와서
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
	}
	while (!feof(fp))//읽어온걸 순서대로 저장
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';//개행 문자 제거를 위해 맨끝 하나는 널값으로 제거
		i++;
	}
	fclose(fp);//파일을 닫음
	count = i - 1;
	if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //학습량이 저장되어 있는 텍스트 파일을 읽기 모드로 연다
	{
		fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
	}
	for(i=0;i<count;i++)//읽어온걸 순서대로 저장
	{
		fscanf(fp2,"%d",&b[i].day_study);//해당 과목의 일일 공부량 수치와
		for (j = 0; j<7; j++)//해당 과목의 월화수목금토일 각각의 공부량 수치
			fscanf(fp2,"%d",&b[i].week_study[j]);
	}
	fclose(fp2);//파일을 닫음
	printf("삭제하실 과목을 입력하세요\n");
	gets(target);//삭제할 과목을 타겟에 받음
	for (i = 0; i<count; i++)//불러온 단어 수 만큼 순차 검색을 함
	{
		if (!strcmp(b[i].name,target))//읽어와서 저장되어 있는 값이 삭제할 단어와 일치하면
		{
			printf("[%s]를 통계표에서 제거합니다.\n",b[i].name);
			strcpy(b[i].name, "\0");//과목이름을 null값으로 덮어 씌워줌
			b[i].day_study=0;
			for(j=0;j<7;j++)
				b[i].week_study[j]=0;
		}

	}
	if ((fp = fopen("SubJect.txt","w")) == NULL)//쓰기모드로 과목이 저장되어 있는 파일을 연다
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
	}
	for (i = 0; i<count; i++)//불러온 단어의 수 만큼 순차 검색을 해서
	{
		if ((strcmp(b[i].name, "\0")) != 0)//삭제한 단어가 아닌 것만 텍스트 파일에 저장
		{
			fputs(b[i].name, fp);
			fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
		}
	}
	fclose(fp);//파일을 닫음
	if ((fp2 = fopen("StudyNum.txt","w")) == NULL)//쓰기 모드로 학습량이 저장되어 있는 파일을 연다
	{
		fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
	}
	for (i = 0; i<count; i++) //불러온 단어의 수만큼 검색을해서
	{
		if ((strcmp(b[i].name, "\0")) != 0)
		{
			fprintf(fp2, "%d ", b[i].day_study);//삭제된 단어가 아닌 학습량만 학습량 파일에 저장
			for (j = 0; j<7; j++)
				fprintf(fp2, "%d ", b[i].week_study[j]);
		}
	}
	fclose(fp2);//파일을 닫아줌
	for (i = 0; i<SUBJECT; i++)
	{
		strcpy(b[i].name, "\0");  //삭제할때 변수에 찌거기값이 남아서 초기화 안하면 과목 추가에서 추가가능 여부를 확인할때 남은 찌꺼기를 읽어서  문제 발생
		b[i].day_study = 0;
		for (j = 0; j<7; j++)
			b[i].week_study[j] = 0;
	}
	printf("메뉴로 돌아갑니다\n");
	Sleep(1000);
	system("cls");
	Statistics_Menuscr();//메뉴 출력

}

void Measure(void) //학습량 측정
{
	int hour = 0, min = 0, sec = 0, frame = 0;
	int i = 0, j,count;
	char ch;
	char target[20];
	int measutime = 0;//측정시간 분으로 환산
	FILE *fp,*fp2;
	if ((fp = fopen("SubJect.txt", "r")) == NULL) //학습과목이 저장되어 있는 텍스트 파일을 읽기 모드로 연다
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
	}
	while (!feof(fp))//읽어온걸 순서대로 저장
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';//개행 문자 제거를 위해 맨끝 하나는 널값으로 제거
		i++;
	}
	fclose(fp);//파일을 닫음
	count=i-1;
	if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //학습량이 저장된 텍스트 파일을 읽기모드로 연다
	{
		fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
	}
	for(i=0;i<count;i++)//읽어온걸 순서대로 저장
	{
		fscanf(fp2,"%d",&b[i].day_study);//해당 과목의 일일 공부량 수치와
		for (j = 0; j<7; j++)//해당 과목의 월화수목금토일 각각의 공부량 수치
			fscanf(fp2,"%d",&b[i].week_study[j]);
	}
	fclose(fp2);//파일을 닫음
	stopwatch_menu();//스탑워치 메뉴 함수를 불러옴
	while (1)
	{
		printf("%2d : %2d : %2d : %2d", hour, min, sec, frame);
		Sleep(10);
		frame++;
		if (frame == 100)
		{
			sec++;
			frame = 0;
		}
		if (sec == 60)
		{
			min++;
			sec = 0;
		}
		if (min == 60)
		{
			hour++;
			min = 0;
		}

		if (kbhit())
		{
			ch = getch();
			switch (ch)
			{
			case 'S': case 's':   //정지 s를 누르면 getch 때문에 키입력을 받느라 멈추다가 뭔가 입력 받으면 다시 돌아감
				ch = getch();
				break;
			case 'R': case 'r':   //리셋
				system("cls");
				stopwatch_menu();
				hour = min = sec = frame = 0;
				break;
			case 'Q': case 'q':   //나가기
				goto label;//루프 탈출

			case 'W': case 'w':  //기록 단순히 그 순간의 초를 보여줌
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				printf("%2d : %2d : %2d : %2d\n", hour, min, sec, frame);
				printf("학습량을 저장할 과목을 입력하세요\n");
				measutime = (hour * 60) + min;//측정 시간을 분으로 환산해서 측정시간변수에 저장
				gets(target);
				for (i = 0; i<SUBJECT; i++)
				{
					if (!strcmp(b[i].name,target))
					{
						printf("학습량을 저장했습니다.\n");
						b[i].day_study += measutime;//분으로 환산된 측정시간을 일일 공부량daystudy에 저장
						b[i].week_study[WhatDay()] += measutime;//해당과목에서 오늘에 해당하는 요일에 측정값 저장 whatday는 오늘의 요일값을 반환
					}
				}
				break;
			default:
				break;
			} //키보드로 부터 입력 받은 값에 대한 switch
		} // if문 키보드로 부터 무엇인가 입력 받았다면
		printf("\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}// 시간에 대한 반복문 중괄호
label:
	if ((fp = fopen("SubJect.txt","w")) == NULL)//쓰기모드로 과목 파일을 연다
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
	}
	for (i = 0; i<count; i++)//갱신된 정보 덮어쓰기
	{
		if ((strcmp(b[i].name, "\0")) != 0)
		{
			fputs(b[i].name, fp);
			fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
		}
	}
	fclose(fp);//파일을 닫음
	if ((fp2 = fopen("StudyNum.txt","w")) == NULL)//쓰기 모드로 학습량 파일을 연다
	{
		fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
	}
	for (i = 0; i<count; i++) //갱신된 학습량 파일에 다시 써줌
	{
		if ((strcmp(b[i].name, "\0")) != 0)
		{
			fprintf(fp2, "%d ", b[i].day_study);
			for (j = 0; j<7; j++)
				fprintf(fp2, "%d ", b[i].week_study[j]);
		}
	}
	fclose(fp2);//파일 닫음
	Statistics_Menuscr();//메뉴로 돌아감
}

void StudyCheck(void)//학습량을 확인
{
	int i = 0, j, key,count;
	int weeksum = 0, weekhour = 0, weekminute = 0;//weeksum주간공부량 합 weekhour주간 총 공부시간[시] weekminute 주간 총 공부 시간[분]
	int dayhour = 0;//일일 학습시간 [시]
	int dayminute = 0;//일일 학습시간 [분]
	double weekaverhour = 0;//주간 평균 학습량 [시]
	double weekaverminute = 0;//주간 평균 학습량 [분]
	FILE *fp,*fp2;
	if ((fp = fopen("SubJect.txt", "r")) == NULL) //읽기모드로 과목이 저장된 파일을 연다
	{
		fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
	}
	while (!feof(fp))//파일내 정보를 읽어옴
	{
		fgets(b[i].name, 100, fp);
		b[i].name[strlen(b[i].name) - 1] = '\0';//개행 문자 제거를 위해 맨끝 하나는 널값으로 제거
		i++;
	}
	fclose(fp);//파일 닫음
	count=i-1;//불러온 과목의 개수를 저장
	if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) // 학습량이 저장된 텍스트 파일을 읽기모드로 연다
	{
		fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
	}
	for(i=0;i<SUBJECT;i++)//정보를 순서대로 읽어옴
	{
		fscanf(fp2,"%d",&b[i].day_study);//해당 과목의 일일 공부량 수치와
		for (j = 0; j<7; j++)//해당 과목의 월화수목금토일 각각의 공부량 수치
			fscanf(fp2,"%d",&b[i].week_study[j]);
	}
	fclose(fp2);//파일을 닫음

	printf("======학습량 확인========\n");
	for (i = 0; i<count; i++)
	{
		dayhour += b[i].day_study / 60;//일일 공부량 시간 텍스트에 저장되어 있는 분으로 환산된 일일 공부량을 60으로 나눠줘서 구함
		dayminute = b[i].day_study % 60;//일일 공부량 분 텍스트에 저장되어 있는 분으로 환산된 일일 공부량을 60으로 나머지 계산해서 구함
		printf("%s의 일일 학습량: %d시간 %d분\n", b[i].name, dayhour, dayminute);
	}
	for (i = 0; i<count; i++)
	{
		weeksum = 0;//주간 해당 과목의 공부량의 합
		for (j = 0; j<7; j++)//월화수목금토일의 분으로 환산된 공부량을 전부 더해서 weeksum에 저장
			weeksum += b[i].week_study[j];
		weekhour = weeksum / 60;//weeksum을 60으로 나눠서 주간 총 공부량 [시]계산
		weekminute = weeksum % 60;//weeksum을 60으로 나머지계산해서 주간 총 공부량 [분]계산
		printf("%s의 주간 학습량: %d시간 %d분\n", b[i].name, weekhour, weekminute);
		weekaverhour = (weeksum / 7) / 60;//weeksum을 7로 나누어서 분으로 환산된 주간 평균 학습량을 구하고 주간 평균  공부시간 [시]를 구함
		weekaverminute = (weeksum / 7) % 60;//weeksum을 7로 나누어서 분으로 환산된 주간 평균 학습량을 구하고 주간 평균 공부시간 [분]을 구함
		printf("%s의 주간 평균 학습량: 약%f시간 %f분\n", b[i].name, weekaverhour, weekaverminute);
	}
	while (1)
	{
		printf("종료는 ESC\n");
		key = getch();//키 값을 입력받음
		if (key == 27)
		{
			system("cls");
			break;
		}

	}
	Statistics_Menuscr();//메뉴로 돌아감

}
int WhatDay(void)//요일 계산을 해주는 함수
{
	time_t timer;
	struct tm *t;

	timer = time(NULL); // 현재 시각을 초 단위로 얻기

	t = localtime(&timer);// 초 단위의 시간을 분리하여 구조체에 넣기
	return t->tm_wday; // 일요일=0, 월요일=1, 화요일=2, 수요일=3, 목요일=4, 금요일=5, 토요일=6 타임 함수에 선언되어 있음
}

void WeekStudyReset(int day)//주간 학습량 초기화 (월요일마다 주간 학습량이 자동으로 초기화됨) (int day)는 WhatDay()함수의 결과값을 매개변수로 받음 즉 요일값임
{
	int i = 0;
	int j,count;
	int log;//월요일에 학습량을 초기화 했는지 확인해주는 변수 매번 월요일에 프로그램을 킬때마다 초기화 하지 않기 위함
	int first; //파일을 최초로 만들었을때 빈파일에 데이터 0을 넣어주기 위해 만듦
	FILE *fp, *fp2;
	if ((fp = fopen("Reset.txt", "a")) == NULL)//초기화 여부를 알려줄 파일을 만드는 부분 파일을 이어쓰기 모드로 열어서 파일이 없으면 만들어줌
	{
		fprintf(stderr, "파일 Reset.txt를 열 수 없습니다\n", "Reset.txt");
		exit(1);
	}
	fclose(fp);//파일을 닫음


	if ((fp2 = fopen("Reset.txt", "r")) == NULL)//Reset 파일의 데이터(0또는 1만 저장될거임)를 first변수로 불러옴
	{
		fprintf(stderr, "파일 Reset.txt를 열 수 없습니다\n", "Reset.txt");
	}
	fscanf(fp2, "%d", &first);
	fclose(fp2);//파일을 닫아주고

	if ((fp2 = fopen("Reset.txt", "w")) == NULL)//다시 쓰기모드로 열어준다
	{
		fprintf(stderr, "파일 Reset.txt를 열 수 없습니다\n", "Reset.txt");
	}
	if (!first == 0 || 1)//최초에 파일이 비어있을때 데이터(0)를 넣어주기 위한 if문
	{
		first = 0;                 //아까 first에 불러왔던 데이터가 0또는 1이 아니라면 파일에 0을 넣어주기 위해 first에 0을 넣어줌
		fprintf(fp2, "%d", first);//0을 넣어준 first의 값을 파일에 저장
	}
	fclose(fp2);//파일 닫음

	if ((fp = fopen("Reset.txt", "r")) == NULL)//여기부터 월요일 마다 실행될 부분
	{
		fprintf(stderr, "파일 Reset.txt를 열 수 없습니다\n", "Reset.txt");//주간학습량의 초기화 여부가 있는 Reset파일을 열어서
	}
	fscanf(fp, "%d", &log); //log라는 변수에 가져옴
	fclose(fp);
	if (day == 1)//매개변수로 받은값이 1이라면 즉 오늘이 월요일이라면 (1은 월요일 2는 화요일 '''')
	{
		if (log == 0)//초기화 여부 확인 오늘이 월요일인데 (0=학습량을 초기화 하지 않았다면) 초기화하면 log가 1이될거임
		{
			if ((fp = fopen("SubJect.txt", "r")) == NULL) //읽기모드로 과목이 저장되어 있는 파일을 연다
			{
				fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
			}
			while (!feof(fp))//순서대로 정보를 읽어옴
			{
				fgets(b[i].name, 100, fp);
				b[i].name[strlen(b[i].name) - 1] = '\0';//개행 문자 제거를 위해 맨끝 하나는 널값으로 제거
				i++;
			}
			fclose(fp);
			count=i-1;//읽어온 과목 수를 저장
			if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //읽기모드로 학습량이 저장된 파일을 연다
			{
				fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
			}
			for(i=0;i<count;i++)//읽어온 과목의 개수만큼 순서대로 읽어옴
			{
				fscanf(fp2,"%d",&b[i].day_study);//해당 과목의 일일 공부량 수치와
				for (j = 0; j<7; j++)//해당 과목의 월화수목금토일 각각의 공부량 수치
					fscanf(fp2,"%d",&b[i].week_study[j]);
			}
			fclose(fp2);//파일을 닫음

			for (i = 0; i<count; i++)//주간 학습량을 전부 0으로 초기화 해줌
			{
				for (j = 0; j<7; j++)
					b[i].week_study[j] = 0;
			}

			if ((fp = fopen("SubJect.txt","w")) == NULL)//쓰기 모드로 과목파일을 연다
			{
				fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
			}
			for (i = 0; i<count; i++)//읽어온 과목의 수만큼 쓰기동작을 시행
			{
				if ((strcmp(b[i].name, "\0")) != 0)
				{
					fputs(b[i].name, fp);
					fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
				}
			}
			fclose(fp);//파일을 닫음
			if ((fp2 = fopen("StudyNum.txt","w")) == NULL)//학습량이 저장된 파일을 연다
			{
				fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
			}
			for (i = 0; i<count; i++) //갱신된 학습량을 파일에 저장
			{
				if ((strcmp(b[i].name, "\0")) != 0)
				{
					fprintf(fp2, "%d ", b[i].day_study);
					for (j = 0; j<7; j++)
						fprintf(fp2, "%d ", b[i].week_study[j]);
				}
			}
			fclose(fp2);//파일을 닫음

			log = 1;//log변수를 1로 바꾸고 (오늘 초기화가 행해졌다는걸 의미)
			if ((fp = fopen("Reset.txt", "w")) == NULL)
			{
				fprintf(stderr, "파일 Reset.txt를 열 수 없습니다\n", "Reset.txt");
			}
			fprintf(fp, "%d", log);//0이었던 파일내 정보를 1로 덮어씌움
			fclose(fp);//종료 이제 다시 불러와도 log가 1이기 때문에 초기화가 진행되지 않음
		}
	}
	if (day == 2)//오늘이 화요일 이라면
	{
		log = 0;//월요일이 지나간 화요일이기 때문에 다시 log값을 0으로 바꿔서 저장해주는 부분 다음 월요일에 한 번의 초기화가 다시 진행될 수 있게하기 위함
		if ((fp = fopen("Reset.txt", "w")) == NULL)
		{
			fprintf(stderr, "파일 Reset.txt를 열 수 없습니다\n", "Reset.txt");
		}
		fprintf(fp, "%d", log);
		fclose(fp);//파일을 닫음
	}

}

int DayReset(void)//일일 학습량 초기화
{
	int i = 0, key;
	int x = 28, y = 11;//화살표의 시작 좌표
	printf("안녕하세요 학습량을 측정하고 확인할 수 있는 학습 통계 프로그램입니다.\n\n");
	Sleep(1300);
	printf("오늘 처음 사용하십니까?\n\n");
	Sleep(1500);
	system("cls");
	Decision();


	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case LEFT: //왼쪽 방향키를 입력받으면
			system("cls");
			Decision();//메뉴창을 띄우고
			x -= 40;	   //화살표("▶")의 x좌표를 40칸 왼쪽으로 이동
			if (x <= 28)  //화살표("▶")의 x좌표가 계속 왼쪽 방향키를 받아도 왼쪽 메뉴에서 고정되도록 28까지만 이동 되도록 고정
				x = 28;
			gotoxy(x, y);
			printf("▶");//바뀐 좌표에 화살표 출력
			break;

		case RIGHT://아래쪽 방향키를 입력받으면
			system("cls");
			Decision();//메뉴창을 띄우고
			x += 40;	   //화살표("▶")의 x좌표를 40칸 오른쪽으로 이동
			if (x >= 68)  //화살표("▶")의 x좌표가 계속 오른쪽 방향키를 받아도 오른쪽 메뉴에서 고정되도록 68까지만 이동 되도록 고정
				x = 68;
			gotoxy(x, y);
			printf("▶");//바뀐 좌표에 화살표 출력
			break;

		case ENTER://엔터키를 입력받으면
			YesorNo(x);//해당하는 기능을 실행해주는 함수를 띄우고 종료
			return 0;
		}

	}

}

void Decision(void)//초기화 여부 메뉴
{
	system("mode con: cols=115 lines=25");
	gotoxy(30, 11);
	printf(" ◎예ENTER[일일 학습량 초기화]         ◎아니요[그대로 실행]\n\n");
}

void YesorNo(int x)
{
	int i = 0, j,count;
	FILE *fp,*fp2;
	if (x == 28)//예 초기화를 선택했을때
	{
		system("cls");
		printf("학습량을 초기화 합니다.\n");
		Sleep(1000);
		if ((fp = fopen("SubJect.txt", "r")) == NULL) //읽기모드로 과목이 저장된 파일을 연다
			{
				fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
			}
			while (!feof(fp))//순서대로 읽어옴
			{
				fgets(b[i].name, 100, fp);
				b[i].name[strlen(b[i].name) - 1] = '\0';//개행 문자 제거를 위해 맨끝 하나는 널값으로 제거
				i++;
			}
			fclose(fp);//파일을 닫음
			count=i-1;
			if ((fp2 = fopen("StudyNum.txt", "r")) == NULL) //학습량이 저장된 파일을 읽기모드로 연다
			{
				fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
			}
			for(i=0;i<count;i++)//과목을 불러온 수 만큼 순서대로 정보를 읽어옴
			{
				fscanf(fp2,"%d",&b[i].day_study);//해당 과목의 일일 공부량 수치와
				for (j = 0; j<7; j++)//해당 과목의 월화수목금토일 각각의 공부량 수치
					fscanf(fp2,"%d",&b[i].week_study[j]);
			}
			fclose(fp2);//파일을 닫음
			for (i = 0; i<count; i++)//과목별 일일 학습량을 초기화해줌
				b[i].day_study = 0;

			if ((fp = fopen("SubJect.txt","w")) == NULL)//쓰기 모드로 과목이 저장된 파일을 연다
				{
					fprintf(stderr, "파일 SubJect.txt를 열 수 없습니다\n", "SubJect.txt");
				}
				for (i = 0; i<count; i++)//갱신된 정보를 파일에 저장
				{
					if ((strcmp(b[i].name, "\0")) != 0)
					{
						fputs(b[i].name, fp);
						fputc('\n', fp);//fputs 는 텍스트로 저장할때 엔터값을 안받기에 개행을 위해 붙여줌
					}
				}
				fclose(fp);//파일을 닫음
				if ((fp2 = fopen("StudyNum.txt","w")) == NULL)//쓰기 모드로 학습량이 저장된 파일을 연다
				{
					fprintf(stderr, "파일 StudyNum.txt를 열 수 없습니다\n", "StudyNum.txt");
				}
				for (i = 0; i<count; i++) //갱신된 정보를 저장
				{
					if ((strcmp(b[i].name, "\0")) != 0)
					{
						fprintf(fp2, "%d ", b[i].day_study);
						for (j = 0; j<7; j++)
							fprintf(fp2, "%d ", b[i].week_study[j]);
					}
				}
				fclose(fp2);//파일을 닫음
	}

	if (x == 43)//아니오 선택
	{
		system("cls");
		printf("프로그램을 실행 합니다.\n");
		Sleep(1000);
	}
}
//================================================-SungHo

//================================================-seokhoon
void calender() {
	int year = 0;//년을 입력받음
	int month = 0;//월을 입력받음
	int day = 1;//달력의 시작일을 찾기 위한 변수이다(시작일 전 공백을 찍는 횟수)
	int everyday = 0;//입력 달 까지의 그 년의 총 날짜 수
	int monthday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//1~12월까지 일자수
																		   //배열의 첫번째는 배열의 0번 이므로 0을 넣고 1번 부터 날짜를 넣어 달과 배열의 번지를 맞추려했다.
	int yoonyear = 0;//윤년 스위치
	int preyear = 0;//입력 년 전 까지의 총 날짜 수
	int i;
	int j;
	int z;//1년 부터 입력한 년 까지 반복
	int w;
	int key; // esc
	char swch = 'h';//날짜를 w a s d로 이동시킬 스위치이다
	int start = 0;
	system("cls");
	printf("몇 년도를 입력하시겠나요?\n");
	scanf("%d", &year);
	printf("몇 월을 원하시나요?\n");
	scanf("%d", &month);

	if (month > 12) {
		printf("12월까지입니다!\n");
		return;
	}

	while (1) {

		monthday[2] = 28;
		yoonyear = 0;
		preyear = 0;
		everyday = 0;
		day = 1;




		if (((year) % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {//윤년인 경우
																		//윤년 4년에 한번, 100의 배수인 해는 평년, 400의 배수해는 윤년
			yoonyear = 1;//윤년이면 yoonyear를 1로 바꿔준다
		}

		for (z = 1; z < year; z++) {//입력한 년 전 까지의 총 일 수를 구하는것이다
			if (((z) % 4 == 0 && (z % 100 != 0 || z % 400 == 0))) {
				preyear = (preyear + 366) % 7;
				/*1년 부터 전부 계산하되 윤년인 날짜가 나오면 366일 임으로 366을 더한다, 나누기 7을 하는 이유는
				위 과정이 달력에서 시작일을 결정하는 것 이므로 한 줄에 출력 되는 7일을 미리 나누어 주는것이다
				미리 나누어주는 이유는 입력 년이 너무 크면 int 자료형의 크기를 초과 할 수도 있기 때문이다
				*/
			}
			else {
				preyear = (preyear + 365) % 7;
				/*평년일때는 365일 임으로 365을 더한다*/
			}
		}

		if (yoonyear == 1) {//yoonyear=1이면 윤년
			monthday[2] = 29;//2월 달에 해당하는 monnthday의 배열값을 28에서 29로 수정한다
		}

		preyear = preyear + 1;

		for (j = 1; j < month; j++) {//입력한 년의 입력한 월 까지의 날짜를 계산한다
			everyday += (monthday[j]) % 7;
			/*monthday에 0번째를 제외한 1번째 부터 입력한 월 까지의 번지의 값들을 전부 더하면
			입력한 년의 입력한 월 까지의 날짜를 구할 수 있다. 윤년인 경우에도 위에서 2번째를 28에서
			29로 수정하였으므로 정상적으로 계산이 가능하다 7일을 미리 나누어 주는 이유는 위의 주석과 같다*/
		}

		day = (preyear + everyday) % 7;
		/*day는 입력한 년 월의 전의 날짜를 모두 더한것에 7을 나눈것이다. 1월 1일 월요일을 시작으로
		달력의 1일 시작일은 그 전의 모든 날짜들의 영향을 받아 한칸씩 밀리기 때문이다. 다만 달력의
		한줄은 7칸 이므로 모든 날짜를 7로 나눈 나머지가 달력 첫줄 7칸에서 밀리는 갯수가 된다*/
		printf("%14d년 %d월\n", year, month);
		printf("  일  월  화  수  목  금  토\n"); //월화수목금토 출력
		for (w = 0; w < day; w++) {
			printf("    ");
		}

		for (i = 1; i <= monthday[month]; i++) {
			printf("%4d", i);//1는 1부터 입력한 월의 monthday번째의 크기만큼 1씩 증가하며 출력한다
			if ((i + day) % 7 == 0) {//7번째 칸 내림

				printf("\n"); //각 주의 간격

			}
		}
		printf("\n");
		printf("저번달 = a   다음달 = d   작년 = s   내년 = w\n");
		printf("메뉴로 돌아가기 = ESC(엔터한번치고)\n");
		printf("\n");
		getchar();//getchar를 getchar앞에 사용한 이유는 계속 enter키가 자동으로 입력되었기 때문이다
		swch = getchar();  //swch값을 getchar로 받음
		if (swch == 'w') {
			year++;   //w를 입력시 년 증가
		}


		else if (swch == 's') {
			year--;//s를 입력시 년 증가 -1년은 기원전 이므로 따로 처리할 필요가 없다
		}


		else if (swch == 'd') {
			month++;//d를 입력시 월 증가
			if (month > 12) {
				//상식적으로 13월은 없다 month가 13이상 되면 년을 한번 증가시키고 1로 초기화 시킨다
				year++;
				month = 1;
			}
		}
		else if (swch == 'a')
		{//a를 입력시 월 감소
			month--;
			if (month < 1) {
				//0월은 없다 month가 0이하 되면 년을 한번 줄이고 12로 초기화 시킨다
				year--;
				month = 12;
			}

		}
		key = getch();
		if (key == 27) {
			main();
			break;
		}


	}


}
//==================================================-seokhoon
//====================================================-sungjae
int learnchoice(void)
{
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 18, y = 8;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			learn_menu();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 8)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			learn_menu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 18)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 18;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}

}
int threemenu1() {//학습계획입력 선택시 뭐로 할지 메뉴를 키보드로 입력받는 함수
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 18, y = 8;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			planinsertmenu();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 8)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			planinsertmenu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 12)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 12;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}
int threemenu2() {
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 18, y = 8;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			achievementcheckmenu();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 8)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			achievementcheckmenu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 12)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 12;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}
int threemenu3() {
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 18, y = 8;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			achievementlookmenu();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 8)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			achievementlookmenu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 12)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 12;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}
int threemenu4() {
	int key;//입력받은 키의 int값을 저장할 변수
	int x = 18, y = 8;//화살표의 시작 좌표 지정 x :x축 좌표  y:y축 좌표

	while (1)
	{
		key = getch();
		if (key == 0xE0 || key == 0)
			key = getch();
		switch (key)
		{
		case UP: //위쪽 방향키를 입력받으면
			system("cls");
			timetablemenu();//메뉴창을 띄우고
			y -= 2;	   //화살표("=>")의 y좌표를 2칸 아래로 내림
			if (y <= 8)  //화살표("=>")의 y좌표가 메뉴 위쪽으로는 올라가지 않도록 단어검색과 같은 높이인 11까지만 올라가도록 고정
				y = 8;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case DOWN://아래쪽 방향키를 입력받으면
			system("cls");
			timetablemenu();//메뉴창을 띄우고
			y += 2;	   //화살표("=>")의 y좌표를 2칸 위로 올림
			if (y >= 12)  //화살표("=>")의 y좌표가 메뉴 아래쪽으로는 내려가지 않도록 단어퀴즈와 같은 높이인 17까지만 내려가도록 고정
				y = 12;
			gotoxy(x, y);
			printf("=>");//바뀐 좌표에 화살표 출력
			break;

		case ESC:
			system("cls");
			return 0;

		case ENTER://엔터키를 입력받으면
			return y;
		}

	}
}
int alarm()      //시간을 알려주는 함수/메인에서 주소를 받아와 저장해주기 위해 포인터로 쓰임.
{
	int key = 0;
	USER utime;//사용자 입력 시간저장구조체
	time_t now;//현재시간을 받기위한 구조체
	struct tm *time_;//현재시간을 받기위한 구조체
	printf("========================\n");
	printf("==========ALARM=========\n");
	printf("========================\n");
	printf("알람이 울리는 시간을 입력해주세요...\n");
	printf("hour : "); scanf("%d", &utime.hour);//사용자가 입력하는 시
	printf("min : "); scanf("%d", &utime.min);//사용자가 입력하는 분
	while (1) {//무한루프로 사용자 입력시간과 비교함
		now = time(NULL);
		time_ = localtime(&now);//로컬시간을 불러와줌
		if (_kbhit()) {//키보드 값을 입력하면?
			key = _getch();//입력값을 int형변수 key에 저장
			if (key == ESC)//입력값이 ESC라면?
				return 0;//종료
		}
		printf("현재 시간 : %2d시 %2d분 %2d초\n", time_->tm_hour, time_->tm_min, time_->tm_sec);//로컬시간 보여줌
		printf("입력 시간 : %2d시 %2d분\n", utime.hour, utime.min);//사용자 입력시간보여줌
		printf("ESC를 입력하시면 종료됩니다.....\n");
		Sleep(200);
		system("cls");//화면지움
		if (utime.hour == time_->tm_hour&&utime.min == time_->tm_min)//사용자 입력시간과 같다면 빠져나옴
			break;
	}
	while (1) {
		printf("알람 종료!!");
		printf("ESC를 누르면 종료됩니다.");
		if (_kbhit()) {//키보드 값을 입력하면?
			key = _getch();//입력값을 int형변수 key에 저장
			if (key == ESC)//입력값이 ESC라면?
				break;//while문 종료
		}
		Beep(262, 200);/* 도 음계 *///알람음 출력
		Beep(294, 200); /* 레 음계 */
		Beep(330, 200); /* 미 음계 */
		Beep(349, 200); /* 파 음계 */
		Beep(392, 200); /* 솔 음계 */
		Beep(440, 200); /* 라 음계 */
		Beep(494, 200); /* 시 음계 */
		Beep(524, 200); /* 도 음계 */
		Sleep(500);//0.5초 지연
		system("cls");
	}
	return 0;
}
int timer() {
	int inmin = 0, insec = 0, inhour = 0, key = 0;
	//inmin은 분,insec은 초,inhour는 시 를 저장하는변수 //key는 종료시 키값을 받는 변수
	printf("타이머의 시간을 입력해주세요\n");
	printf("min : ");
	scanf("%d", &inmin);
	printf("sec : ");
	scanf("%d", &insec);

	while (1) {
		if (inmin >= 60)//분이 60이 넘는다면
		{
			inmin -= 60;//분 -60을 해주고
			inhour++;//시간에 1을 더한다
		}
		else
			break;//아니라면 빠져나온다
	}
	while (1) {
		if (insec >= 60) {//초가 60이 넘는다면
			insec -= 60;//초에서 -60을 해주고
			inmin++;//분에 1을 더한다
		}
		else
			break;//아니라면 빠져나온다
	}
	if (inmin >= 60)//위에 똑같은 식이 잇지만 분이 60일경우가 잇어 다시써준다
	{
		inmin -= 60;
		inhour++;
	}
	while (1)
	{
		if (_kbhit()) {//키보드 값을 입력하면?
			key = _getch();//입력값을 int형변수 key에 저장
			if (key == ESC)//입력값이 ESC라면?
				return 0;//종료
		}
		if (insec == 0 && inmin == 0 && inhour != 0)//시간이 흐를때 분이 0이되면 시간을 1빼고
		{
			inhour--;
			inmin = 60;//분을 60으로 만들어준다
		}
		if (insec == 0)//초가 0이되면
		{
			inmin--;//분에서 1을 빼주고
			insec = 60;//초를 60로 초기화시켜준다
		}

		printf("■■■■■■■■■■■■■\n");
		printf("■■■■■ Timer■■■■■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("■      ■      ■      ■\n");
		printf("■  %2d  ■  %2d  ■  %2d  ■\n", inhour, inmin, insec);//타이머 시간 출력
		printf("■      ■      ■      ■\n");
		printf("■■■■■■■■■■■■■\n");
		printf("ESC를 누르면 종료됩니다.\n");
		Sleep(1000);//1초지연
		insec -= 1;//시간이 흐름을 나타냄
		system("cls");//화면 초기화

		if (insec == 0 && inmin == 0 && inhour == 0)//모두 0이되면
			break;//타이머종료/
	}

	while (1) {
		if (_kbhit()) {//키보드 값을 입력하면?
			key = _getch();//입력값을 int형변수 key에 저장
			if (key == ESC)//입력값이 ESC라면?
				break;//while문 종료
		}
		printf("타이머 종료!!!!\n");
		printf("ESC를 누르면 종료됩니다.");
		Beep(262, 200);/* 도 음계 *///알람음 출력
		Beep(294, 200); /* 레 음계 */
		Beep(330, 200); /* 미 음계 */
		Beep(349, 200); /* 파 음계 */
		Beep(392, 200); /* 솔 음계 */
		Beep(440, 200); /* 라 음계 */
		Beep(494, 200); /* 시 음계 */
		Beep(524, 200); /* 도 음계 */
		Sleep(500);
		system("cls");
	}
	return 0;
}
int learn_menu() {
	gotoxy(11, 5);
	printf("==================================\n");
	gotoxy(11, 6);
	printf("         Learning  Planner        \n");
	gotoxy(11, 7);
	printf("==================================\n");
	gotoxy(20, 8);
	printf("1. 계획 입력\n");
	gotoxy(20, 10);
	printf("2. 계획 달성 체크\n");
	gotoxy(20, 12);
	printf("3. 달성률 보기\n");
	gotoxy(20, 14);
	printf("4. 시간표\n");
	gotoxy(20, 16);
	printf("5. 종료...\n");

	return 0;
}
void learningplanner()
{
	int b;//b는 사용자가 메뉴선택하는 변수
	system("color 3F");
	learn_menu();//학습계획표메뉴출력
	b = learnchoice();//키값을 받아서 메뉴선택한 y좌표를 b에 저장
	system("cls");
	if (b == 16)
		return;
	switch (b)
	{
	case 8:
		planinsert();//계획입력
		break;
	case 10: achievementcheck();//달성 체크
		break;
	case 12: achievementrate();//달성보기
		break;
	case 14: timetable();//시간표
		break;
	default:
		break;
	}

}
int planinsertmenu() {
	gotoxy(20, 8);
	printf("1. 1학기 계획입력\n");
	gotoxy(20, 10);
	printf("2. 2학기 계획입력\n");
	gotoxy(20, 12);
	printf("3. 종료\n");
	return 0;
}
int planinsert()//계획입력함수
{
	int a = 0;//메뉴선택 변수
	PLAN insert;//계획 저장 구조체
	FILE *fpin1 = fopen("plan1.txt", "w+");//1학기 계획을 파일에 저장하기 위해서 만든 파일포인터
	FILE *fpin2 = fopen("plan2.txt", "w+");//2학기 계획을 파일에 저장하기 위해서 만든 파일포인터
	planinsertmenu();//계획입력메뉴 출력
	a = threemenu1();//키값을 받아서 메뉴선택한 y좌표를 a에 저장
	system("cls");
	if (a == 8)
	{

		printf("1주차 계획 :  ");
		scanf("%s", insert.pi1, 50);
		printf("2주차 계획 :  ");
		scanf("%s", insert.pi2, 50);
		printf("3주차 계획 :  ");
		scanf("%s", insert.pi3, 50);
		printf("4주차 계획 :  ");
		scanf("%s", insert.pi4, 50);
		printf("5주차 계획 :  ");
		scanf("%s", insert.pi5, 50);
		printf("6주차 계획 :  ");
		scanf("%s", insert.pi6, 50);
		printf("7주차 계획 :  ");
		scanf("%s", insert.pi7, 50);
		printf("8주차 계획 :  ");
		scanf("%s", insert.pi8, 50);
		printf("9주차 계획 :  ");
		scanf("%s", insert.pi9, 50);
		printf("10주차 계획 : ");
		scanf("%s", insert.pi10, 50);
		printf("11주차 계획 : ");
		scanf("%s", insert.pi11, 50);
		printf("12주차 계획 : ");
		scanf("%s", insert.pi12, 50);
		printf("13주차 계획 : ");
		scanf("%s", insert.pi13, 50);
		printf("14주차 계획 : ");
		scanf("%s", insert.pi14, 50);
		printf("15주차 계획 : ");
		scanf("%s", insert.pi15, 50);
		printf("16주차 계획 : ");
		scanf("%s", insert.pi16, 50);
		fprintf(fpin1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", insert.pi1, insert.pi2, insert.pi3, insert.pi4, insert.pi5, insert.pi6, insert.pi7, insert.pi8, insert.pi9, insert.pi10, insert.pi11, insert.pi12, insert.pi13, insert.pi14, insert.pi15, insert.pi16);
		//입력받은 문자열 파일에 저장
		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 10)
	{
		printf("1주차 계획 :  ");
		scanf("%s", insert.pi1, 50);
		printf("2주차 계획 :  ");
		scanf("%s", insert.pi2, 50);
		printf("3주차 계획 :  ");
		scanf("%s", insert.pi3, 50);
		printf("4주차 계획 :  ");
		scanf("%s", insert.pi4, 50);
		printf("5주차 계획 :  ");
		scanf("%s", insert.pi5, 50);
		printf("6주차 계획 :  ");
		scanf("%s", insert.pi6, 50);
		printf("7주차 계획 :  ");
		scanf("%s", insert.pi7, 50);
		printf("8주차 계획 :  ");
		scanf("%s", insert.pi8, 50);
		printf("9주차 계획 :  ");
		scanf("%s", insert.pi9, 50);
		printf("10주차 계획 : ");
		scanf("%s", insert.pi10, 50);
		printf("11주차 계획 : ");
		scanf("%s", insert.pi11, 50);
		printf("12주차 계획 : ");
		scanf("%s", insert.pi12, 50);
		printf("13주차 계획 : ");
		scanf("%s", insert.pi13, 50);
		printf("14주차 계획 : ");
		scanf("%s", insert.pi14, 50);
		printf("15주차 계획 : ");
		scanf("%s", insert.pi15, 50);
		printf("16주차 계획 : ");
		scanf("%s", insert.pi16, 50);
		fprintf(fpin2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", insert.pi1, insert.pi2, insert.pi3, insert.pi4, insert.pi5, insert.pi6, insert.pi7, insert.pi8, insert.pi9, insert.pi10, insert.pi11, insert.pi12, insert.pi13, insert.pi14, insert.pi15, insert.pi16);
		//입력받은 문자열 파일에 저장
		fclose(fpin1);
		fclose(fpin2);
		return 0;
	}
	else if (a == 12)//3누르면 종료
		return 0;
	printf("잘못 입력하셨습니다.\n");
	fclose(fpin1);
	fclose(fpin2);
	return 0;
}
int achievementcheckmenu() {
	gotoxy(20, 8);
	printf("1. 1학기 달성체크\n");
	gotoxy(20, 10);
	printf("2. 2학기 달성체크\n");
	gotoxy(20, 12);
	printf("3. 종료\n");
	return 0;
}
int achievementcheck() {
	int f = 0;
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10], c11[10], c12[10], c13[10], c14[10], c15[10], c16[10];
	PLAN out;
	FILE *fpout1, *fpout2, *chrate1, *chrate2;
		if ((fpout1 = fopen("plan1.txt", "r")) == NULL) //1학기 읽어오는 파일포인터
		{
			system("cls");
			gotoxy(8, 5);
			printf("1학기 파일이 없습니다.\n");
			gotoxy(8, 6);
			printf("생성해주세요.\n");
			gotoxy(8, 7);
			printf("3초후에 종료됩니다....\n");
			Sleep(3000);
			return 0;
		}
		if ((fpout2 = fopen("plan2.txt", "r")) == NULL)//2학기 읽어오는 파일포인터
		{
			system("cls");
			gotoxy(8, 5);
			printf("2학기 파일이 없습니다.\n");
			gotoxy(8, 6);
			printf("생성해주세요.\n");
			gotoxy(8, 7);
			printf("3초후에 종료됩니다....\n");
			Sleep(3000);
			return 0;
		}
		chrate1 = fopen("rate1.txt", "w+");//1학기 달성체크
		chrate2 = fopen("rate2.txt", "w+");//2학기 달성체크
	achievementcheckmenu();//달성체크메뉴 출력
	f = threemenu2();//키값을 받아서 메뉴선택한 y좌표를 f에 저장
	if (f == 12)
		return 0;
	switch (f) {
	case 8:
		fscanf(fpout1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		system("cls");
		printf("1주차 : %s-->달성했으면 y / 아니면 n\n", out.pi1);
		scanf(" %s", c1);
		system("cls");
		printf("2주차 : %s-->달성했으면 y / 아니면 n\n", out.pi2);
		scanf(" %s", c2);
		system("cls");
		printf("3주차 : %s-->달성했으면 y / 아니면 n\n", out.pi3);
		scanf(" %s", c3);
		system("cls");
		printf("4주차 : %s-->달성했으면 y / 아니면 n\n", out.pi4);
		scanf(" %s", c4);
		system("cls");
		printf("5주차 : %s-->달성했으면 y / 아니면 n\n", out.pi5);
		scanf(" %s", c5);
		system("cls");
		printf("6주차 : %s-->달성했으면 y / 아니면 n\n", out.pi6);
		scanf(" %s", c6);
		system("cls");
		printf("7주차 : %s-->달성했으면 y / 아니면 n\n", out.pi7);
		scanf(" %s", c7);
		system("cls");
		printf("8주차 : %s-->달성했으면 y / 아니면 n\n", out.pi8);
		scanf(" %s", c8);
		system("cls");
		printf("9주차 : %s-->달성했으면 y / 아니면 n\n", out.pi9);
		scanf(" %s", c9);
		system("cls");
		printf("10주차 : %s-->달성했으면 y / 아니면 n\n", out.pi10);
		scanf(" %s", c10);
		system("cls");
		printf("11주차 : %s-->달성했으면 y / 아니면 n\n", out.pi11);
		scanf(" %s", c11);
		system("cls");
		printf("12주차 : %s-->달성했으면 y / 아니면 n\n", out.pi12);
		scanf(" %s", c12);
		system("cls");
		printf("13주차 : %s-->달성했으면 y / 아니면 n\n", out.pi13);
		scanf(" %s", c13);
		system("cls");
		printf("14주차 : %s-->달성했으면 y / 아니면 n\n", out.pi14);
		scanf(" %s", c14);
		system("cls");
		printf("15주차 : %s-->달성했으면 y / 아니면 n\n", out.pi15);
		scanf(" %s", c15);
		system("cls");
		printf("16주차 : %s-->달성했으면 y / 아니면 n\n", out.pi16);
		scanf(" %s", c16);
		fprintf(chrate1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16);
		//사용자가 입력한 달성체크 저장
		break;
	case 10:

		fscanf(fpout2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", out.pi1, out.pi2, out.pi3, out.pi4, out.pi5, out.pi6, out.pi7, out.pi8, out.pi9, out.pi10, out.pi11, out.pi12, out.pi13, out.pi14, out.pi15, out.pi16);
		system("cls");
		printf("1주차 : %s-->달성했으면 y / 아니면 n\n", out.pi1);
		scanf(" %s", c1);
		system("cls");
		printf("2주차 : %s-->달성했으면 y / 아니면 n\n", out.pi2);
		scanf(" %s", c2);
		system("cls");
		printf("3주차 : %s-->달성했으면 y / 아니면 n\n", out.pi3);
		scanf(" %s", c3);
		system("cls");
		printf("4주차 : %s-->달성했으면 y / 아니면 n\n", out.pi4);
		scanf(" %s", c4);
		system("cls");
		printf("5주차 : %s-->달성했으면 y / 아니면 n\n", out.pi5);
		scanf(" %s", c5);
		system("cls");
		printf("6주차 : %s-->달성했으면 y / 아니면 n\n", out.pi6);
		scanf(" %s", c6);
		system("cls");
		printf("7주차 : %s-->달성했으면 y / 아니면 n\n", out.pi7);
		scanf(" %s", c7);
		system("cls");
		printf("8주차 : %s-->달성했으면 y / 아니면 n\n", out.pi8);
		scanf(" %s", c8);
		system("cls");
		printf("9주차 : %s-->달성했으면 y / 아니면 n\n", out.pi9);
		scanf(" %s", c9);
		system("cls");
		printf("10주차 : %s-->달성했으면 y / 아니면 n\n", out.pi10);
		scanf(" %s", c10);
		system("cls");
		printf("11주차 : %s-->달성했으면 y / 아니면 n\n", out.pi11);
		scanf(" %s", c11);
		system("cls");
		printf("12주차 : %s-->달성했으면 y / 아니면 n\n", out.pi12);
		scanf(" %s", c12);
		system("cls");
		printf("13주차 : %s-->달성했으면 y / 아니면 n\n", out.pi13);
		scanf(" %s", c13);
		system("cls");
		printf("14주차 : %s-->달성했으면 y / 아니면 n\n", out.pi14);
		scanf(" %s", c14);
		system("cls");
		printf("15주차 : %s-->달성했으면 y / 아니면 n\n", out.pi15);
		scanf(" %s", c15);
		system("cls");
		printf("16주차 : %s-->달성했으면 y / 아니면 n\n", out.pi16);
		scanf(" %s", c16);
		fprintf(chrate2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16);
		//사용자가 입력한 달성체크 저장
		break;
	default:
		break;
	}
	fclose(fpout1);
	fclose(fpout2);
	fclose(chrate1);
	fclose(chrate2);
	return 0;
}
int achievementlookmenu() {
	gotoxy(20, 8);
	printf("1. 1학기 달성률\n");
	gotoxy(20, 10);
	printf("2. 2학기 달성률\n");
	gotoxy(20, 12);
	printf("3. 종료\n");
	return 0;
}
int achievementrate() {
	int ratesum = 0;//달성 여부 확인용 정수형 변수
	int ac;//사용자 메뉴선택변수
	int key;//키값을 받아 종료시에 사용
	PLAN ch;//달성체크파일에서 받아오기위해 사용한 구조체
	FILE *rate1 = fopen("rate1.txt", "r");//1학기 달성체크파일 읽기
	FILE *rate2 = fopen("rate2.txt", "r");//2학기 달성체크파일 읽기
	achievementlookmenu();//메뉴출력
	ac = threemenu3();//키값을 받아서 메뉴선택한 y좌표를 ac에 저장
	system("cls");
	if (ac == 12)
		return 0;
	switch (ac) {
	case 8:
		fscanf(rate1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", ch.c1, ch.c2, ch.c3, ch.c4, ch.c5, ch.c6, ch.c7, ch.c8, ch.c9, ch.c10, ch.c11, ch.c12, ch.c13, ch.c14, ch.c15, ch.c16);
		if (strcmp(ch.c1, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c2, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c3, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c4, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c5, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c6, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c7, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c8, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c9, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c10, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c11, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c12, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c13, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c14, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c15, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c16, "y") == 0)//대답이 y라면
			ratesum++;
		gotoxy(20, 10);
		printf("1학기 달성률 %.2lf%%\n", ((float)ratesum / 16) * 100);//달성률 보여주기
		fclose(rate1);
		fclose(rate2);
		break;
	case 10:
		fscanf(rate2, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", ch.c1, ch.c2, ch.c3, ch.c4, ch.c5, ch.c6, ch.c7, ch.c8, ch.c9, ch.c10, ch.c11, ch.c12, ch.c13, ch.c14, ch.c15, ch.c16);
		if (strcmp(ch.c1, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c2, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c3, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c4, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c5, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c6, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c7, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c8, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c9, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c10, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c11, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c12, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c13, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c14, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c15, "y") == 0)//대답이 y라면
			ratesum++;
		if (strcmp(ch.c16, "y") == 0)//대답이 y라면
			ratesum++;
		gotoxy(20, 10);
		printf("2학기 달성률 %.2lf%% \n", ((float)ratesum / 16) * 100);//달성률 보여주기
		fclose(rate1);
		fclose(rate2);
		break;
	default:
		break;
	}
	gotoxy(20, 11);
	printf("ESC를 입력하시면 종료됩니다.");
	while (1) {
		if (_kbhit()) {//키보드 값을 입력하면?
			key = _getch();//입력값을 int형변수 key에 저장
			if (key == ESC)//입력값이 ESC라면?
				return 0;//종료
		}
	}
	return 0;
}
int timetablemenu() {
	gotoxy(11, 5);
	printf("==========================================\n");
	gotoxy(11, 6);
	printf("===============time table=================\n");
	gotoxy(11, 7);
	printf("==========================================\n");
	gotoxy(20, 8);
	printf("1.시간표 입력\n");
	gotoxy(20, 10);
	printf("2.시간표 보기\n");
	gotoxy(20, 12);
	printf("종료........");
	return 0;
}
int timetable() {
	int x = 0;
	timetablemenu();//시간표메뉴출력
	x = threemenu4();//키값을 받아서 메뉴선택한 y좌표를 x에 저장
	switch (x)
	{
	case 8: timetablein();//시간표 입력
		break;
	case 10: timetablelook();//시간표 출력
		break;
	case 12:
		return 0;
	default:
		break;
	}
	return 0;
}
int timetablein() {//시간표 입력함수

	TT mon, thu, wes, thr, fri;//요일별로 쓸 구조체
	FILE *timetable = fopen("timetable.txt", "w+");//시간표를 파일에 저장하기 위한 파일포인터
	system("cls");
	gotoxy(4, 4);
	printf("월요일부터 금요일까지의 시간표를 입력하셔야 합니다.(5글자이하)\n\n");
	printf("\t\t월요일1교시 : "); scanf("%s", mon.st1);
	printf("\t\t월요일2교시 : "); scanf("%s", mon.st2);
	printf("\t\t월요일3교시 : "); scanf("%s", mon.st3);
	printf("\t\t월요일4교시 : "); scanf("%s", mon.st4);
	printf("\t\t월요일5교시 : "); scanf("%s", mon.st5);
	printf("\t\t월요일6교시 : "); scanf("%s", mon.st6);
	printf("\t\t월요일7교시 : "); scanf("%s", mon.st7);
	printf("\t\t월요일8교시 : "); scanf("%s", mon.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t화요일1교시 : "); scanf("%s", thu.st1);
	printf("\t\t화요일2교시 : "); scanf("%s", thu.st2);
	printf("\t\t화요일3교시 : "); scanf("%s", thu.st3);
	printf("\t\t화요일4교시 : "); scanf("%s", thu.st4);
	printf("\t\t화요일5교시 : "); scanf("%s", thu.st5);
	printf("\t\t화요일6교시 : "); scanf("%s", thu.st6);
	printf("\t\t화요일7교시 : "); scanf("%s", thu.st7);
	printf("\t\t화요일8교시 : "); scanf("%s", thu.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t수요일1교시 : "); scanf("%s", wes.st1);
	printf("\t\t수요일2교시 : "); scanf("%s", wes.st2);
	printf("\t\t수요일3교시 : "); scanf("%s", wes.st3);
	printf("\t\t수요일4교시 : "); scanf("%s", wes.st4);
	printf("\t\t수요일5교시 : "); scanf("%s", wes.st5);
	printf("\t\t수요일6교시 : "); scanf("%s", wes.st6);
	printf("\t\t수요일7교시 : "); scanf("%s", wes.st7);
	printf("\t\t수요일8교시 : "); scanf("%s", wes.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t목요일1교시 : "); scanf("%s", thr.st1);
	printf("\t\t목요일2교시 : "); scanf("%s", thr.st2);
	printf("\t\t목요일3교시 : "); scanf("%s", thr.st3);
	printf("\t\t목요일4교시 : "); scanf("%s", thr.st4);
	printf("\t\t목요일5교시 : "); scanf("%s", thr.st5);
	printf("\t\t목요일6교시 : "); scanf("%s", thr.st6);
	printf("\t\t목요일7교시 : "); scanf("%s", thr.st7);
	printf("\t\t목요일8교시 : "); scanf("%s", thr.st8);
	system("cls");
	gotoxy(0, 6);
	printf("\t\t금요일1교시 : "); scanf("%s", fri.st1);
	printf("\t\t금요일2교시 : "); scanf("%s", fri.st2);
	printf("\t\t금요일3교시 : "); scanf("%s", fri.st3);
	printf("\t\t금요일4교시 : "); scanf("%s", fri.st4);
	printf("\t\t금요일5교시 : "); scanf("%s", fri.st5);
	printf("\t\t금요일6교시 : "); scanf("%s", fri.st6);
	printf("\t\t금요일7교시 : "); scanf("%s", fri.st7);
	printf("\t\t금요일8교시 : "); scanf("%s", fri.st8);
	system("cls");
	fprintf(timetable, "%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n"
		, mon.st1, mon.st2, mon.st3, mon.st4, mon.st5, mon.st6, mon.st7, mon.st8, thu.st1, thu.st2, thu.st3, thu.st4, thu.st5, thu.st6, thu.st7, thu.st8
		, wes.st1, wes.st2, wes.st3, wes.st4, wes.st5, wes.st6, wes.st7, wes.st8, thr.st1, thr.st2, thr.st3, thr.st4, thr.st5, thr.st6, thr.st7, thr.st8
		, fri.st1, fri.st2, fri.st3, fri.st4, fri.st5, fri.st6, fri.st7, fri.st8);
	printf("시간표 입력 완료!!\n");
	fclose(timetable);
	return 0;
}
int timetablelook() {
	int inkey = 0;//키보드값을 받아서 정수형의 저장하는 변수
	TT mon, thu, wes, thr, fri;//요일별로 쓸 구조체
	FILE *timetablelook;//시간표 파일 읽어오는데 사용하는 파일포인터
	if ((timetablelook = fopen("timetable.txt", "r")) == NULL)
	{
		system("cls");
		gotoxy(8, 5);
		printf("시간표 파일이 없습니다.\n");
		gotoxy(8, 6);
		printf("생성해주세요.\n");
		gotoxy(8, 7);
		printf("3초후에 종료됩니다....\n");
		Sleep(3000);
		return 0;
	}
	fscanf(timetablelook, "%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n%s %s %s %s %s %s %s %s\n"
		, mon.st1, mon.st2, mon.st3, mon.st4, mon.st5, mon.st6, mon.st7, mon.st8, thu.st1, thu.st2, thu.st3, thu.st4, thu.st5, thu.st6, thu.st7, thu.st8
		, wes.st1, wes.st2, wes.st3, wes.st4, wes.st5, wes.st6, wes.st7, wes.st8, thr.st1, thr.st2, thr.st3, thr.st4, thr.st5, thr.st6, thr.st7, thr.st8
		, fri.st1, fri.st2, fri.st3, fri.st4, fri.st5, fri.st6, fri.st7, fri.st8);
	system("cls");
	gotoxy(0, 5);
	printf("┌───┬─────┬─────┬─────┬─────┬─────┐");//┬┌┐┴￢ㄷ
	gotoxy(0, 6);
	printf("│───│    월    │    화    │    수    │    목    │    금    │");
	gotoxy(0, 7);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 8);
	printf("│ 1교시│%10s│%10s│%10s│%10s│%10s│", mon.st1, thu.st1, wes.st1, thr.st1, fri.st1);
	gotoxy(0, 9);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 10);
	printf("│ 2교시│%10s│%10s│%10s│%10s│%10s│", mon.st2, thu.st2, wes.st2, thr.st2, fri.st2);
	gotoxy(0, 11);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 12);
	printf("│ 3교시│%10s│%10s│%10s│%10s│%10s│", mon.st3, thu.st3, wes.st3, thr.st3, fri.st3);
	gotoxy(0, 13);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 14);
	printf("│ 4교시│%10s│%10s│%10s│%10s│%10s│", mon.st4, thu.st4, wes.st4, thr.st4, fri.st4);
	gotoxy(0, 15);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 16);
	printf("│ 5교시│%10s│%10s│%10s│%10s│%10s│", mon.st5, thu.st5, wes.st5, thr.st5, fri.st5);
	gotoxy(0, 17);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 18);
	printf("│ 6교시│%10s│%10s│%10s│%10s│%10s│", mon.st6, thu.st6, wes.st6, thr.st6, fri.st6);
	gotoxy(0, 19);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 20);
	printf("│ 7교시│%10s│%10s│%10s│%10s│%10s│", mon.st7, thu.st7, wes.st7, thr.st7, fri.st7);
	gotoxy(0, 21);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 22);
	printf("│ 8교시│%10s│%10s│%10s│%10s│%10s│", mon.st8, thu.st8, wes.st8, thr.st8, fri.st8);
	gotoxy(0, 23);
	printf("├───┼─────┼─────┼─────┼─────┼─────┤");
	gotoxy(0, 24);
	printf("ESC를 누르시면 종료됩니다.");
	while (1) {
		if (_kbhit()) {//키보드 값을 입력하면?
			inkey = _getch();//입력값을 int형변수 key에 저장
			if (inkey == ESC)//입력값이 ESC라면?
				break;//while문 종료
		}

	}
	fclose(timetablelook);
	return 0;
}//====================================================-sungjae
