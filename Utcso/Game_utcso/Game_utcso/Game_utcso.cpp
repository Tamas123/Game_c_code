#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Home.h"

using namespace std;
char world[SIZEY][SIZEX] = { 0 };
int totalEnamies = 0;
int x, y, yi = 0;
char player = 'A';
char playerLaser = '^';
char enemyLaser = 'U';
char explosion = 'X';
int score = 0;
int victory = 1;
int laserReady = 1;
int enemyReady = 0;
char playerShilded = 'D';
char enemy = 'M';
char enemyShielded = 'O';
int drop = 0;
int i = 1;
//char direction = 'l';
//char keyPress;
int currentEnemies;
int enemySpeed;

int main() {
	
	srand(time(NULL));


	Printhome();
	createWorld();
	
	

	 currentEnemies = totalEnamies;
	 world[SIZEY - 1][SIZEX / 2] = player;

	while (currentEnemies > 0 && victory) {

		
		laserReady++;
		PrintGame();

		leserGo();
		UpdateEnemyDirection();
		UpdateBoard();
		controlPlayer();
	}

	
	endGame();


	return 0;

}