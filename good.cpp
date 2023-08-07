#include <iostream>

class Solution
{
public:
    void print();
    
private:
    int x, y;
    
};

void Solution::print()
{
    std::cout << "Hello World" << std::endl;
}

int main()
{
    Solution s;
    s.print();
    return 0;
}