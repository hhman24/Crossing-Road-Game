#include "CPEOPLE.h"

CPEOPLE::CPEOPLE() :x(0), y(0), state(true) {}
int CPEOPLE::getX() { return x; }
int CPEOPLE::getY() { return y; }
void CPEOPLE::setX(int x) { this->x = x; }
void CPEOPLE::setY(int y) { this->y = y; }
void CPEOPLE::setState(bool isDead) { state = isDead; }

bool CPEOPLE::checkValidPos(int x, int y) {
	if (x < 1) return false;
	if (x >= MAX_X)return false;
	if (y < 2) return false;
	if (y > MAX_Y - MAX_P_Y - 1) return false;
	return true;
}
void CPEOPLE::drawPeople() {
	for (int i = 0; i < MAX_P_X; i++) {
		for (int j = 0; j < MAX_P_Y; j++) {
			BattleField[x + i][y + j - 1] = People[i][j];
		}
	}
}
void CPEOPLE::Up() {
	int step = 4;
	if (checkValidPos(x - step, y)) {
		x -= step;
		drawPeople();
		for (int i = 0; i < MAX_P_X; i++) {
			for (int j = 0; j < MAX_P_Y; j++) {
				BattleField[x + i + step][y + j - 1] = ' ';
			}
		}
	}
}

void CPEOPLE::Down() {
	int step = 4;
	if (checkValidPos(x + step, y)) {
		x += step;
		drawPeople();
		for (int i = 0; i < MAX_P_X; i++) {
			for (int j = 0; j < MAX_P_Y; j++) {
				BattleField[x + i - step][y + j - 1] = ' ';
			}
		}
	}
}

void CPEOPLE::Right() {
	if (checkValidPos(x, y + 1)) {
		++y;
		drawPeople();
		for (int i = 0; i < MAX_P_X; i++) {
			BattleField[x + i][y - 2] = ' ';
		}
	}
}
void CPEOPLE::Left() {
	if (checkValidPos(x, y - 1)) {
		--y;
		drawPeople();
		for (int i = 0; i < MAX_P_X; i++) {
			BattleField[x + i][y + 3] = ' ';
		}
	}
}

bool CPEOPLE::isImpactAnimal(vector<CANIMAL*>& cAni)
{
	int count = 0;
	for (CANIMAL* ca : cAni) {
		count++;
		if ((count<=level) &&((x == ca->getX()) && (y >= (ca->getY() - MAX_P_Y + 1) && y <= (ca->getY() + MAX_B_Y )))
			|| (count>level) && ((x == ca->getX()) && (y >= (ca->getY() - MAX_P_Y + 1) && y <= (ca->getY() + MAX_D_Y ))))
			return true;
	}
	return false;
}

bool CPEOPLE::isImpactVehicle(vector<CVEHICLE*>& cVehi)
{
	for (CVEHICLE* cv : cVehi) {
		if ((x == cv->getPosition().getX()) && (y >= (cv->getPosition().getY() - MAX_P_Y + 1) && y <= (cv->getPosition().getY() + 8)))
			return true;
	}
	return false;
}

bool CPEOPLE::isFinish() { return (x == 1) ? true : false; }
bool CPEOPLE::isDead() { return !state; }