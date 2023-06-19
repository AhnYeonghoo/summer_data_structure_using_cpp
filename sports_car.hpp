#pragma once;
#include "car.hpp"

class SportsCar : public Car
{
public:
	bool b_turbo;
	void setTurbo(bool btur)
	{
		this->b_turbo = btur;
	}

	void speedUp()
	{
		if (this->b_turbo) this->speed += 20;
		else Car::speedUp();
	}
};