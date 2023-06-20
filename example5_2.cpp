struct MyNewType
{
	int i;
	float f;
};

void main_example5_2()
{
	MyNewType s, * ps;
	ps = &s;
	ps->i = 2;
	ps->f = 3.14f;
}