#include "CCAR.h"

/*void CCar::createCar(int type) // :v doc file co ki tu dac biet ko duoc nha 
{
	this->_car = new char* [this->_height];
	for (int i = 0; i < 3; i++)
	{
		this->_car[i] = new char[this->_width];
	}
	if (type == 1)
	{
		char car1[][8] = { {' ','_','_','_','_',' ',' ',' '},
						   {'/','[',']','[',']','\\','_',' '},
						   {240,'0','-','-','-','0','-',217} };

		for (int i = 0; i < this->_height; i++)
		{
			for (int j = 0; j < this->_width; j++)
			{
				this->_car[i][j] = car1[i][j];
			}
		}

	}
	else if (type == 2)
	{
		char car2[][8] = { {' ',' ',' ','_','_',' ',' ',' '},
						   {' ','_','/','|','_','\\','_',' '},
						   {192,'0','-','-','-','-','0',217} };

		for (int i = 0; i < this->_height; i++)
		{
			for (int j = 0; j < this->_width; j++)
			{
				this->_car[i][j] = car2[i][j];
			}
		}
	}


}*/

CCAR::CCAR(const Point& p, int _type, int _height, int _width) :CVEHICLE(p, _height, _width)
{
	//this->_type = _type;
	//createCar(_type);
}

CCAR::CCAR(const CCAR& car) :CVEHICLE(car)
{
	//this->_type = car._type;
	//createCar(this->_type);
}

CCAR& CCAR::operator=(const CCAR& car)
{
	if (this != &car)
	{
		CVEHICLE::operator=(car);
		//this->_type = car._type;
		//createCar(this->_type);
	}
	return *this;
}

/*char** CCar::shapeHevicle()
{
	return this->_car;
}*/

void CCAR::drawVehicle()
{
	for (int i = 0; i < MAX_C_X; i++) {
		for (int j = MAX_C_Y - 1; j >= 0; j--) {
			//BattleField[x + i][y + j] = BattleField[x + i][y + j - 1];
			BattleField[getPosition().getX() + i][getPosition().getY() + j] = Car[i][j];
		}
	}

	/*for (int i = 0; i < this->_height; i++)
	{
		for (int j = 0; j < this->_width; j++)
		{
			cout << this->_car[i][j];
		}
		cout << endl;
	}*/
}

void CCAR::soundHorn()
{
	PlaySound(TEXT("_Sound\\ES_Car_Horn.wav"), NULL, SND_SYNC);
}

void CCAR::move()
{
	int x = getPosition().getX();
	int y = getPosition().getY();
	setY(++y);
	if (y != MAX_Y - MAX_C_Y - 1) {
		drawVehicle();
		for (int i = 0; i < MAX_C_X; i++)
			BattleField[x + i][y - 1] = ' ';
	}
	else {
		y = 1;
		setY(y);
		drawVehicle();
		for (int i = 0; i < MAX_C_X; i++) {
			for (int j = 0; j < MAX_C_Y; j++) {
				BattleField[x + i][MAX_Y - MAX_C_Y - 2 + j] = ' ';
			}
		}
	}
}

CCAR::~CCAR()
{
	/*for (int i = 0; i < this->_height; i++)
	{
		if (this->_car[i] != nullptr)
		{
			delete[] this->_car[i];
		}
	}

	delete[] this->_car;*/
}