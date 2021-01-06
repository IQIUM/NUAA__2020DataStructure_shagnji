/**
 * 编写算法，计算i！×2的i次方并存入数组
 **/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdexcept>
#include <string>
using namespace std;

class MyException
{
private:
    string message;

public:
    MyException(string message);
    ~MyException();
    string what() const
    {
        return message;
    }
};

MyException::MyException(string message) : message(message)
{
}

MyException::~MyException()
{
}

/* 传入一个数计算阶层 */
int calFac(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

void traverse(int array[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int array[256];
    for (int k = 0; k < 256; ++k)
    {
        array[k] = 0;
    }
    int i = 0;
    try
    {
        while (1)
        {
            long long int tmp = pow(2, i) * calFac(i);
            if (tmp > INT_MAX)
            {
                throw new MyException("求得的值大于INTMAX！！！");
            }
            array[i++] = tmp;
        }
    }
    catch (const MyException *&e)
    {
        std::cerr << e->what() << '\n';
        cout << "最终数组存储的数据为：  \n";
        traverse(array, i);
    }
    return 0;
}
