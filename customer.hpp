
struct Customer
{
	int id;
	int arrival;
	int service;
	Customer(int i = 0, int arr = 0, int serv = 0)
		: id(i), arrival(arr), service(serv) {}
};