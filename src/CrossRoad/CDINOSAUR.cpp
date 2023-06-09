#include "CDINOSAUR.h"

void CDINOSAUR::drawDinosaur()
{
	for (int i = 0; i < MAX_D_X; i++) {
		for (int j = MAX_D_Y - 1; j >= 0; j--) {
			//BattleField[x + i][y + j] = BattleField[x + i][y + j - 1];
			BattleField[getX() + i][getY() + j] = Dino[i][j];
		}
	}
}

void CDINOSAUR::Move()
{
	int x = getX();
	int y = getY();
	setY(++y);
	if (y != MAX_Y - MAX_D_Y - 1) {
		drawDinosaur();
		for (int i = 0; i < MAX_D_X; i++)
			BattleField[x + i][y - 1] = ' ';
	}
	else {
		y = 1;
		setY(y);
		drawDinosaur();
		for (int i = 0; i < MAX_D_X; i++) {
			for (int j = 0; j < MAX_D_Y; j++) {
				BattleField[x + i][MAX_Y - MAX_D_Y - 2 + j] = ' ';
			}
		}
	}
}

void CDINOSAUR::Tell()
{
	PlaySound(TEXT("_Sound\\ES_Dinosaur_Snar.wav"), NULL, SND_SYNC);
}