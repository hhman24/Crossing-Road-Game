#pragma once
class CANIMAL
{
private:
	int mX, mY;
public:
	CANIMAL() :mX(0), mY(0) {}
	~CANIMAL() {}
	virtual void Move();
	virtual void Tell();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};