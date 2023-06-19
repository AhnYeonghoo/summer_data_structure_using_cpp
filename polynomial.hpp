#define _CRT_SECURE_NO_WARNINGS
#pragma once;
#include <cstdio>

const int MAX_DEGREE = 80;

class Polynomial
{
private:
	int		degree;
	float	coef[MAX_DEGREE];

public:
	Polynomial()
	{
		this->degree = 0;
	}

	void read()
	{
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf("%d", &degree);
		printf("각 항의 계수를 입력하시오: (총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++)
		{
			scanf("%f", coef + i);
		}
	}

	void display(const char* str = " Poly = ")
	{
		printf("\t%s", str);
		for (int i = 0; i < degree; i++)
		{
			printf("%5.1f x^%d + ", coef[i], degree - i);
		}
		printf("%4.1f\n", coef[degree]);
	}

	void add(Polynomial& a, Polynomial& b)
	{
		if (a.degree > b.degree)
		{
			*this = a;
			for (int i = 0; i <= b.degree; i++)
			{
				coef[i + (degree - b.degree)] += b.coef[i];
			}
		}
		else
		{
			*this = b;
			for (int i = 0; i <= a.degree; i++)
			{
				coef[i + (degree - a.degree)] += a.coef[i];
			}
		}
	}

	bool isZero()
	{
		return degree == 0;
	}

	void negate()
	{
		for (int i = 0; i < degree; i++)
		{
			coef[i] = -coef[i];
		}
	}
};