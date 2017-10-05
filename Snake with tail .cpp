#include<iostream>
#include<windows.h>
#include <cstdlib>
//#include<math.h>
//#include<string.h>
#include<ctime>

using namespace std;

/*** DEFINE THE SIZE OF GAME BORDER ***/
#define Height 20
#define Length 50
////////////////////////////////////////
void colorcahnger(int color);
void clearscreen();
void movement(int left, int right, int up, int down, int &y, int &x);

/*bool iskeydown(int vk)
{
	return GetAsyncKeyState(vk) & 0x8000;
}*/
int FoodEatenNum = 0;// Foodeaten counter
int main()
{

	int highscore = 0;
MessageBox(0, (LPCWSTR)L"This programm Is \" SNAKE \" Game And Writen By I.OS.", (LPCWSTR)L" \" Iman Ostovar \" Hello", MB_ICONQUESTION);

///////////////////////////////////HELLO PART /////////////////////////////////////////////////////////////////////////////
	char name[30];
Restart://###################################################################################################################
rename:
	name[0] = '0';
	printf("Enter Your Name  ;-)    ----->  ");
	fflush(stdin);
	gets_s(name);
//	fflush(stdin);
	if (name[0] == '0' || name[0] == '\n' || name[0] == ' ')
		goto rename;
	//scanf_s("%s", name);
	clearscreen();
	colorcahnger(0xFC);
	printf("\n\n\t******\tHi \" %s \"\t******\n\tFrom I.Os.\n\t\tENJOY IT\n\tWait Please\n", name);
	Sleep(500);
	colorcahnger(0x09);
	printf("Loading");
	Sleep(500);
	colorcahnger(0x0a);
	printf("\r\tLoading");
	Sleep(500);
	colorcahnger(0x0b);
	printf("\r\t\tLoading");
	Sleep(500);
	colorcahnger(0x0c);
	printf("\r\t\t\tLoading");
	Sleep(500);
	colorcahnger(0x0d);
	printf("\r\t\t\t\tLoading");
	Sleep(500);
	colorcahnger(0x0e);
	printf("\r\t\t\t\t\tLoading");
	colorcahnger(0x0F);
	fflush(stdin);
	clearscreen();
	//=======================================================
	//*** Part _1 ****// 
	//Making Border
	//=======================================================

	//***************************** Define Border **************************

	char border[Height][Length];
	
	// horizontal lines
	for (int i = 0; i < Length; i++)
	{
		border[0][i] = '*';
		border[Height-1][i] = '*';

	}

	// Vertical Lines & rest
	for (int i = 1; i < Height-1; ++i) 
	{
		for (int j = 0; j < Length+1; ++j) 
		{
			border[i][0] = '*';
			border[i][Length-1] = '*';
			if (j < Length)
				border[i][j] = ' ' ;

		}
	}
	
	
	//=======================================================
	//*** Part _2 ****// 
	//Initial Generate Food & Snake
	//=======================================================


	const char snake = '&';
	int y = Height/2, x = Length/2 ; //used to coordinate the snake
	int xgh[50], ygh[50];
	ygh[0] = y;
	xgh[0] = x;
	bool left = 0, right = 0, up = 0, down = 0; //used to determine which direction the snake should go
	FoodEatenNum = 0; //reset counter amount of food eaten
    bool eaten = 0; //used to check if the snake ate food
	
	
	
	//generates the food
	char food = 'x';
	int a, b; //used to position the food
	//srand(time(0));
	a = rand() % (Height-2) + 1;
	Sleep(200);
	b = rand() % (Length-2) + 1;
	border[a][b] = food;
	
	
	
	
	
		int fec = 500, score=0;


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//=======================================================
	//*** Part _3 ****// 
	//Game Loop
	//=======================================================

		/*the game loop*/	while (1)
		{
			clearscreen();
			border[y][x] = snake; //places the snake

			///////////////////////////////////////////////////////////////////////////////////////
			//***************************** Show Border & Food & Snake **************************//
			///////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i < Height; ++i)
			{
				printf("\n");
				for (int j = 0; j < Length; ++j)
				{
					cout << (border[i][j]);

				}
			}
			colorcahnger(0xCF);
			printf("\nThe speed is : ");
			colorcahnger(0xAC);
			for (int j = 0; j < FoodEatenNum; j++)
			{
				printf("*");
				score = (int)exp(j) + 1;
				if (score>highscore)
					highscore = score;
			}
			colorcahnger(0x0a);
			cout << "\n\tFood eaten: " << FoodEatenNum << endl; //displays ammount of food eaten
			colorcahnger(0x0d);
			cout << "\n\t" << name << "'s Score is : " << score;
			colorcahnger(0x0F);

			/******************************************************************************************************/
			//checks if the snake moves in another direction
			if (GetAsyncKeyState(VK_LEFT))
			{
				right = 0, up = 0, down = 0;
				left = 1;
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				left = 0, up = 0, down = 0;
				right = 1;
			}
			else if (GetAsyncKeyState(VK_UP))
			{
				right = 0, left = 0, down = 0;
				up = 1;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				left = 0, up = 0, right = 0;
				down = 1;
			}
			/************************************************************************************************************/
			//moves the snake & it's tail
			border[y][x] = ' ';
			if (FoodEatenNum == 0)
				border[ygh[FoodEatenNum]][xgh[FoodEatenNum]] = ' ';
			else
				border[ygh[FoodEatenNum - 1]][xgh[FoodEatenNum - 1]] = ' ';

			for (int i = FoodEatenNum; i >= 0; i--)
			{
				xgh[i] = xgh[i - 1];
				ygh[i] = ygh[i - 1];

			}
			xgh[0] = x; ygh[0] = y;

			movement(left, right, up, down, y, x);
			for (int i = 0; i < FoodEatenNum; i++)
				//moves the snake tail
				border[ygh[i]][xgh[i]] = '_';
			if (border[y][x]=='_')
			{
				colorcahnger(0x0C);
				Beep(1000, 1000);
				cout << "\n\n\tYou Crashed With your tail !!!!!" << endl;
				colorcahnger(0x0F);
				goto RepeatCheck;
			}
		else
		{
			border[y][x] = snake;
		}
		if (!(y == Height / 2 && x == Length / 2))
			Beep(750,50);
			
		//checks if the player crashed into the border
		if (x == 0 || y == 0 || x == Length-1 || y == Height-1) 
		{
			for (int i = 100; i < 3000; i = i + 150)
				Beep(i, 100);
			colorcahnger(0x0C);
			cout << "\n\n\tYou Crashed into Borders !!!!!" << endl;
			colorcahnger(0x0F);

			//getchar();
			goto RepeatCheck;
		}
		if (border[y][x] == border[a][b]) {
			FoodEatenNum ++;
			eaten =1;
		}
		//if the snake ate food, generate a new one
		if (eaten ) {
			eaten = 0;
			remakefood:
			a = rand() % Height - 1;
			Sleep(25);
			b = rand() % Length + 1;
			if (border[a][b] == ' ')
				border[a][b] = food;
			else
				goto remakefood;
			Beep(fec,100);
			fec=fec + 50;
		}
	}
// FINISH GAME LOOP
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//*****  Check Wether player Wants to Continue Or NOT *****// 
RepeatCheck://########################################################################################################################
	//system("cls");
	printf("\nDo you want play GAME Another Time *(Y/N)* :\t");
	fflush(stdin);
	char Tekrar = getchar();
	
	if (Tekrar == 'y' || Tekrar == 'Y')
	{
		system("cls");
		goto Restart;
	}
	else if (Tekrar == 'n' || Tekrar == 'N')
	{
		if (highscore == score)
		{
			printf("/t***  You Can break The HIGHSCORE  ***\n\t********  Congratulations  ********");
		}
		cout << "\n" << name << "   Your Score is : " << score;

		cout << "\nThe HighScore : " << highscore<<"\n";

		printf("*******************\tGood Luck\t********************\n\n");
		getchar();
		return 0;
	}
	else 
	{
		printf("\n\t\tINVALID INPUT\n ");
		goto RepeatCheck;
	}
	
	return 0;

}

void movement(int left, int right, int up, int down, int &y, int &x) 
{
	if (left )
	{
		x --;
		if (200 - 10 * FoodEatenNum>0)
		Sleep(200-10*FoodEatenNum);

		return;
	}
	else if (right)
	{
		x ++;
		if (200 - 10 * FoodEatenNum>0)
		Sleep(200 - 10 * FoodEatenNum);
		return;
	}
	else if (up )
	{
		y --;
		if (200 - 10 * FoodEatenNum>0)
		Sleep(200 - 10 * FoodEatenNum);
		return;
	}
	else if (down )
	{
		y ++;
		if (200 - 10 * FoodEatenNum>0)
		Sleep(200 - 10 * FoodEatenNum);
		return;
	}
}
void clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);

}
void colorcahnger(int color)
{
	HANDLE hColor;
	COORD Position;

	hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hColor, color);

}