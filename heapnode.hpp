#include <cstdio>

class HeapNode
{
private:
	int key;
public:
	HeapNode(int k = 0) : key(k) {}
	void setKey(int key) { key = key; }
	int getKey() { return key; }
	void display() { printf("%4d", key); }
	
};