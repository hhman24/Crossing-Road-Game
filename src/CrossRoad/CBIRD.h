#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "CANIMAL.h"

#define MAX_X 25
#define MAX_Y 81
#define MAX_B_X 3
#define MAX_B_Y 13

using namespace std;

extern char BattleField[MAX_X][MAX_Y];
extern char Bird[MAX_B_X][MAX_B_Y];

class CBIRD :public CANIMAL
{
public:
	CBIRD() {}
	~CBIRD() {}
	void drawBird();
	void Move();
	void Tell();
};

