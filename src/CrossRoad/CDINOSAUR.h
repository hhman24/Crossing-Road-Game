#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "CANIMAL.h"

#define MAX_X 25
#define MAX_Y 81
#define MAX_D_X 3
#define MAX_D_Y 8

extern char BattleField[MAX_X][MAX_Y];
extern char Dino[MAX_D_X][MAX_D_Y];

class CDINOSAUR :public CANIMAL
{
public:
	CDINOSAUR() {}
	~CDINOSAUR() {}
	void drawDinosaur();
	void Move();
	void Tell();
};