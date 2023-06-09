#include "CBIRD.h"

void CBIRD::drawBird()
{
	for (int i = 0; i < MAX_B_X; i++) {
		for (int j = 0; j < MAX_B_Y; j++) {
			BattleField[getX() + i][getY() + j] = Bird[i][j];
		}
	}
}

void CBIRD::Move()
{
	int x = getX();
	int y = getY();
	setY(--y);
	if (y != 0) {
		drawBird();
		for (int i = 0; i < MAX_B_X; i++)
			BattleField[x + i][y + MAX_B_Y] = ' ';
	}
	else {
		y = MAX_Y - MAX_B_Y - 2;
		setY(y);
		drawBird();
		for (int i = 0; i < MAX_B_X; i++) {
			for (int j = 0; j < MAX_B_Y; j++) {
				BattleField[x + i][j + 1] = ' ';
			}
		}
	}
}

void CBIRD::Tell()
{
	PlaySound(TEXT("_Sound\\ES_Bird_Screech.wav"), NULL, SND_SYNC);
}