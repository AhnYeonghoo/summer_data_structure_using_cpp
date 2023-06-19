#pragma once;
#include <cstdio>
#include <cstring>
class Car
{
protected:
	int speed;
	char name[40];
	
public:
	int gear;
	Car() = default;
	~Car() {}
	
	Car(int s, char* n, int g)
		: speed(s), gear(g)
	{
		strcpy(name, n);
	}

	void changeGear(int g = 4)
	{
		this->gear = g;
	}
	
	void speedUp()
	{
		this->speed += 5;
	}
	
	void display()
	{
		printf("[%s] : ���=%d��, �ӵ�=%dkmph\n", name, gear, speed);
	}

	void whereAmI()
	{
		printf("��ü �ּ� = %x\n", this);
	}
};