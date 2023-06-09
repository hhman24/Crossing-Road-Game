#pragma once
#include <iostream>
#include <vector>
#include "CANIMAL.h"
#include "CVEHICLE.h"

#define MAX_X 25
#define MAX_Y 81
#define MAX_P_X 3
#define MAX_P_Y 4
#define MAX_B_Y 13
#define MAX_D_Y 8

extern char BattleField[MAX_X][MAX_Y];
extern char People[MAX_P_X][MAX_P_Y];
extern int level;

using namespace std;

class CPEOPLE {
private:
	int x, y;
	bool checkValidPos(int x, int y);
	bool state;
public:
	CPEOPLE();
	int getX();
	int getY();
	void drawPeople();
	void setX(int x);
	void setY(int y);
	void setState(bool isDead);
	void Up();
	void Right();
	void Left();
	void Down();
	bool isImpactAnimal(vector<CANIMAL*>& cAni);
	bool isImpactVehicle(vector<CVEHICLE*>& CVehi);
	bool isFinish();
	bool isDead();
	~CPEOPLE() = default;
};


