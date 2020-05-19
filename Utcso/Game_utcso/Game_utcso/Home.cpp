#include "Home.h"
#include<stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include<time.h>

extern char world[SIZEY][SIZEX];
extern int totalEnamies;
extern char enemy;
extern char enemyShielded;
extern char playerShilded;
extern int x, y, yi;
extern int victory;
extern int enemyReady;
extern char enemyLaser;
extern char playerLaser;
extern int score;
extern char explosion;
extern char player;
extern int laserReady;
extern int drop;
extern int i;
extern int enemySpeed;

void Printhome()
{
	printf("\n \n     Welcome soldier! \n \n \n \n");
	Sleep(1000);
	printf(" This game is created by MTL \n \n \n \n");
	Sleep(1000);
	printf("        Good luck. \n \n \n \n");
	Sleep(1000);
	printf("   Press any key to start \n \n \n \n");

	_getch();
}
void Printhometeteje() {
	printf("|----------------------------------------|");
	printf("\n");
	printf("|              score:     %d              |", score);
	printf("\n");
	printf("|----------------------------------------|");


	printf("\n");
}

//srand(time(NULL));


extern int enemySpeed;

void createWorld()
{


	for (x = 0; x < SIZEX; x++) {

		for (y = 0; y < SIZEY; y++)
		{

			if ((y + 1) % 2 == 0 && y < 7 && x > 4 && x < SIZEX - 5 && x % 2 == 0) {

				world[y][x] = enemy;
				totalEnamies++;

			}
			else if ((y + 1) % 2 == 0 && y >= 7 && y < 9 && x > 4 && x < SIZEX - 5 && x % 2 == 0)
			{
				world[y][x] = enemyShielded;
				totalEnamies = totalEnamies + 2;
			}

			else
			{
				world[y][x] = ' ';
			}
			/*world[18][2] = 'D';
			world[17][2] = 'D';
			world[18][3] = 'D';
			world[17][3] = 'D';
			world[18][4] = 'D';
			world[17][4] = 'D';

			world[18][9] = 'D';
			world[17][9] = 'D';
			world[18][8] = 'D';
			world[17][8] = 'D';
			world[18][7] = 'D';
			world[17][7] = 'D';

			world[18][15] = 'D';
			world[17][15] = 'D';
			world[18][14] = 'D';
			world[17][14] = 'D';
			world[18][16] = 'D';
			world[17][16] = 'D';

			world[18][21] = 'D';
			world[17][21] = 'D';
			world[18][22] = 'D';
			world[17][22] = 'D';
			world[18][23] = 'D';
			world[17][23] = 'D';

			world[18][28] = 'D';
			world[17][28] = 'D';
			world[18][29] = 'D';
			world[17][29] = 'D';
			world[18][30] = 'D';
			world[17][30] = 'D';

			world[18][35] = 'D';
			world[17][35] = 'D';
			world[18][36] = 'D';
			world[17][36] = 'D';
			world[18][37] = 'D';
			world[17][37] = 'D';*/
		}

	}
}



void PrintGame()
{
	system("cls");

	int x, y, yi;

	Printhometeteje();

	for (y = 0; y < SIZEY; y++)
	{
		printf("|");
		for (x = 0; x < SIZEX; x++)
		{
			printf("%c", world[y][x]);
		}

		printf("|");
		printf("\n");

	}
}

void leserGo()
{
	int currentEnemies = totalEnamies;
	enemySpeed = 1 + 10 * currentEnemies / totalEnamies;

	
	for (x = 0; x < SIZEX; x++) {
		for (y = SIZEY - 1; y >= 0; y--) {
			if (i % 2 == 0 && world[y][x] == enemyLaser
				&& (world[y + 1][x] != enemy & world[y + 1][x] != enemyShielded)) {
				world[y + 1][x] = enemyLaser;
				world[y][x] = ' ';
			}
			else if (i % 2 == 0 && world[y][x] == enemyLaser
				&& (world[y + 1][x] == enemy || world[y + 1][x] == enemyShielded)) {
				world[y][x] = ' ';
			}
		}
	}
	for (x = 0; x < SIZEX; x++) {
		for (y = 0; y < SIZEY; y++) {
			if ((i % 5) == 0 && (world[y][x] == enemyShielded
				| world[y][x] == enemy) && (rand() % 15) > 13
				&& world[y + 1][x] != playerLaser) {
				for (yi = y + 1; yi < SIZEY; yi++) {
					if (world[yi][x] == enemy
						| world[yi][x] == enemyShielded) {
						enemyReady = 0;
						break;
					}
					enemyReady = 1;
				}
				if (enemyReady) {
					world[y + 1][x] = enemyLaser;
				}
			}
			if (world[y][x] == playerLaser && world[y - 1][x] == enemy) {
				world[y][x] = ' ';
				world[y - 1][x] = explosion;
				currentEnemies--;
				score = score + 50;
			}
			else if (world[y][x] == playerLaser
				&& world[y - 1][x] == enemyShielded) {
				world[y][x] = ' ';
				world[y - 1][x] = enemy;
				currentEnemies--;
				score = score + 50;
			}
			else if (world[y][x] == playerLaser
				&& world[y - 1][x] == enemyLaser) {
				world[y][x] = ' ';
			}
			else if (world[y][x] == explosion) {
				world[y][x] = ' ';
			}
			else if ((i + 1) % 2 == 0 && world[y][x] == enemyLaser
				&& world[y + 1][x] == player) {
				world[y + 1][x] = explosion;
				world[y][x] = ' ';
				victory = 0;
			}
			else if (world[y][x] == playerLaser
				&& world[y - 1][x] != enemyLaser) {
				world[y][x] = ' ';
				world[y - 1][x] = playerLaser;
				
			}
		}
	}
}

void UpdateEnemyDirection(){

	char direction = 'l';

	for (y = 0; y < SIZEY; y++) {
		if (world[y][0] == enemy) {
			direction = 'r';
			drop = 1;
			break;
		}
		if (world[y][SIZEX - 1 == enemy]) {
			direction = 'l';
			drop = 1;
			break;
		}
	}
}

void UpdateBoard()
{
	int enemySpeed = 1 + 10 * totalEnamies / totalEnamies;

	char direction = 'l';
	//int i = 1;
	if (i % enemySpeed == 0) {

		if (direction == 'l') {
			for (x = 0; x < SIZEX; x++)
			{
				for (y = 0; y < SIZEY; y++)
				{
					if (drop && (world[y - 1][x + 1] == enemy) || world[y - 1][x + 1] == enemyShielded)
					{
						world[y][x] = world[y - 1][x + 1];
						world[y - 1][x + 1] = ' ';
					}
					else if (!drop && (world[y][x + 1] == enemy || world[y][x + 1] == enemyShielded))
					{
						world[y][x] = world[y][x + 1];
						world[y][x + 1] = ' ';
					}
				}
			}
		}
		else
		{
			for (x = SIZEX; x > 0; x--)
			{
				for (y = SIZEY; y > 0; y--)
				{
					if (drop && (world[y - 1][x - 1] == enemy || world[y - 1][x - 1] == enemyShielded))
					{
						world[y][x] = world[y - 1][x - 1];
						world[y - 1][x - 1] = ' ';
					}
					else if (!drop && (world[y][x - 1] == enemy || world[y][x - 1] == enemyShielded))
					{
						world[y][x] = world[y][x - 1];
						world[y][x - 1] = ' ';
					}

				}
			}
		}

		for (x = 0; x < SIZEX; x++)
		{
			if (world[SIZEY - 1][x] == enemy) {
				victory;
			}
		}

	}
}

void controlPlayer()
{
	char keyPress;
	if (_kbhit())
	{
		keyPress = _getch();
	}
	else
	{
		keyPress = ' ';
	}

	if (keyPress == 'a')
	{
		for (x = 0; x < SIZEX; x = x + 1)
		{
			if (world[SIZEY - 1][x + 1] == player)
			{
				world[SIZEY - 1][x] = player;
				world[SIZEY - 1][x + 1] = ' ';
			}

		}
	}

	if (keyPress == 'd')
	{
		for (x = SIZEX; x > 0; x = x - 1)
		{
			if (world[SIZEY - 1][x - 1] == player)
			{
				world[SIZEY - 1][x] = player;
				world[SIZEY - 1][x - 1] = ' ';
			}
		}
	}
	if (keyPress == 'w' && laserReady > 2) {
		for (x = 0; x < SIZEX; x = x + 1) {
			if (world[SIZEY - 1][x] == player) {
				world[SIZEY - 2][x] = playerLaser;
				laserReady = 0;
			}
		}
	}
	i++;
	Sleep(10);


}

void endGame()
{
	system("cls");
	printf("|----------------------------------------|");
	printf("\n");
	printf("|              score:     %d              |", score);
	printf("\n");
	printf("|----------------------------------------|");

	printf("\n");
	for (y = 0; y < SIZEY; y++) {
		printf("|");
		for (x = 0; x < SIZEX; x++) {
			printf("%c", world[y][x]);
		}
		printf("|");
		printf("\n");
	}

	Sleep(1000);
	system("cls");
	if (victory != 0) {
		printf("\n \n \n \n \n \n               CONGRATULATIONS! \n \n \n \n \n");
		Sleep(1000);
		printf("\n \n               Score: %d", score);
		Sleep(1000);
		int bonus = totalEnamies * 20 - i;
		printf("\n \n               Bonus: %d", bonus);
		Sleep(1000);
		printf("\n \n               Total Score: %d", score + bonus);
		printf("\n \n \n \n               Well done");
		Sleep(1000);
		printf(", Hero.");
		Sleep(1000);
		_getch();
	}
	else {
		printf("\n \n \n \n \n \n               You have failed.");
		Sleep(1000);
		printf("\n \n \n \n \n \n               Windows is doomed.");
		Sleep(1000);
		printf("\n \n               Final Score: %d", score);
		_getch();
	}
}



//int totalEnemis(int totalEnemies,int curentEnemis)
//{
//	//curentEnemis 
//	//return totalEnemies;
//}

