#pragma once;
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_STRING = 100;

class Student
{
private:
	int m_id;				 // 학번
	char m_name[MAX_STRING]; // 이름
	char m_dept[MAX_STRING]; // 소속학과

public:
	Student(int i = 0, const char* n = "", const char* d = "")
	{
		set(i, n, d);
	}
	
	void set(int i, const char* n, const char* d)
	{
		m_id = i;
		strcpy(m_name, n);
		strcpy(m_dept, d);
	}

	void display()
	{
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", m_id, m_name, m_dept);
	}
};