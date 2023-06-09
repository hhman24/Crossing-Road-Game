#include "CTRUCK.h"
/*void CTruck::createTruck(int type) // :v doc file co ki tu dac biet ko duoc nha 
{
	this->_truck = new char* [this->_height];
	for (int i = 0; i < 3; i++)
	{
		this->_truck[i] = new char[this->_width];
	}
	if (type == 1)
	{
		char car1[][8] = { {' ',' ',' ',' ',' ',' ',' ',' '},
						   {'[','_',']','_','|','\\','_',' '},
						   {'[','o','o','-','-','o','_','|'} };

		for (int i = 0; i < this->_height; i++)
		{
			for (int j = 0; j < this->_width; j++)
			{
				this->_truck[i][j] = car1[i][j];
			}
		}

	}
	else if (type == 2)
	{
		char car2[][8] = { {' ','_','_','_',' ',' ',' ',' '},
						   {'[','_','_','_',']','\\','_',' '},
						   {'=','0','0','-','-','0','_','|'} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->_truck[i][j] = car2[i][j];
			}
		}
	}


}*/

CTRUCK::CTRUCK(const Point& p, int _type, int _height, int _width) :CVEHICLE(p, _height, _width)
{
	//this->_type = _type;
	//createTruck(_type);
}

CTRUCK::CTRUCK(const CTRUCK& car) :CVEHICLE(car)
{
	//this->_type = car._type;
	//createTruck(this->_type);
}

CTRUCK& CTRUCK::operator=(const CTRUCK& car)
{
	if (this != &car)
	{
		CVEHICLE::operator=(car);
		//this->_type = car._type;
		//createTruck(this->_type);
	}
	return *this;
}

/*char** CTruck::shapeHevicle()
{
	return this->_truck;
}*/

void CTRUCK::drawVehicle()
{
	for (int i = 0; i < MAX_T_X; i++) {
		for (int j = MAX_T_Y - 1; j >= 0; j--) {
			BattleField[getPosition().getX() + i][getPosition().getY() + j] = Truck[i][j];
		}
	}

	/*for (int i = 0; i < this->_height; i++)
	{
		for (int j = 0; j < this->_width; j++)
		{
			cout << this->_truck[i][j];
		}
		cout << endl;
	}*/
}

void CTRUCK::soundHorn()
{
	PlaySound(TEXT("_Sound\\ES_Truck_Horn.wav"), NULL, SND_SYNC);
}

void CTRUCK::move()
{
	int x = getPosition().getX();
	int y = getPosition().getY();
	setY(--y);
	if (y != 0) {
		drawVehicle();
		for (int i = 0; i < MAX_T_X; i++)
			BattleField[x + i][y + MAX_T_Y] = ' ';
	}
	else {
		y = MAX_Y - MAX_T_Y - 2;
		setY(y);
		drawVehicle();
		for (int i = 0; i < MAX_T_X; i++) {
			for (int j = 0; j < MAX_T_Y; j++) {
				BattleField[x + i][j + 1] = ' ';
			}
		}
	}
}

CTRUCK::~CTRUCK()
{
	/*for (int i = 0; i < this->_height; i++)
	{
		if (this->_truck[i] != nullptr)
		{
			delete[] this->_truck[i];
		}
	}

	delete[] this->_truck;*/
}