#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<typename T>
void print(T arg)
{
	cout << arg << endl;
}

template<typename T, typename... Types>
void print(T arg, Types... args)
{
	cout << arg << ", ";
	print(args...);
}

template<typename String>
string strCat(const String& s)
{
	return string(s);
}


size_t getStringSize(const char* s) { return strlen(s); }
size_t getStringSize(const string& s) { return s.size(); }

template<typename String, typename... Strings>
size_t getStringSize(const String& s, Strings... strs)
{
	return getStringSize(s) + getStringSize(strs...);
}

void appendToString(string* concat_str) { return; }

template<typename String, typename... Strings>
void appendToString(string* concat_str, const String& s, Strings... strs)
{
	concat_str->append(s);
	appendToString(concat_str, strs...);
}


// ��� ȣ�� ���Ḧ ���� ���̽� ���̽�
int sumAll() { return 0; }

template<typename... Ints>
int sumAll(int num, Ints... nums)
{
	return num + sumAll(nums...);
}

template<typename... Ints>
double average(Ints... nums)
{
	return static_cast<double>(sumAll(nums...)) / sizeof...(nums);
}

template<typename String, typename... Strings>
string strCat(const String& s, Strings... strs)
{
	size_t total_size = getStringSize(s, strs...);
	
	string concat_str;
	concat_str.reserve(total_size);

	concat_str = s;

	appendToString(&concat_str, strs...);

	return concat_str;
}

template<typename Int, typename... Ints>
Int diffFrom(Int start, Ints... nums)
{
	return (start - ... - nums);
}

int main()
{
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);
	cout << strCat(string("this"), " ", "is", " ", string("a"),
		" ", string("sentence"));

	cout << endl;
	cout << average(1, 4, 2, 3, 10) << endl;
	cout << diffFrom(100, 1, 4, 2, 3, 10) << endl;

	return 0;
}