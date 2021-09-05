#pragma once

#include <iostream>
#include <string>

class jh_stack {
    int* mpData;
    int mSize;              // 메모리가 할당된 데이터 공간 크기
    int mCurDataNumber;     // 현재 스택에 쌓여있는 데이터 개수

    void init(const int size)
    {
        if (mpData == nullptr)
        {
            mpData = new int[size];
            std::fill(mpData, mpData + size, 0x00);
        }
    }
public:
    jh_stack(int size) : mpData(nullptr), mSize(size), mCurDataNumber(0)
    {
        init(mSize);
    }
    ~jh_stack()
    {
        if (mpData != nullptr)
            delete[] mpData;
    }
    int size() { return mCurDataNumber; }
    int top() { return (is_empty()) ? -1 : mpData[mCurDataNumber - 1]; }
    bool is_full() { return (mCurDataNumber == mSize) ? true : false; }
    bool is_empty() { return (mCurDataNumber == 0) ? true : false; }
    int push(const int data)
    {
        if (is_full())
        {
            return -1;
        }
        mpData[mCurDataNumber] = data;
        mCurDataNumber++;
        return 0;
    }
    int pop()
    {
        if (is_empty())
        {
            return -1;
        }
        else
        {
            mCurDataNumber--;
            return mpData[mCurDataNumber];
        }
    }


};

void sol_10828_main()
{
    int number_of_line = 0;
    std::cin >> number_of_line;

    jh_stack jhs(number_of_line);

    for (int i = 0; i < number_of_line; i++)
    {
        std::string str;
        std::cin >> str;

        if (str == "push")
        {
            int data = 0;
            std::cin >> data;
            jhs.push(data);
        }
        else if (str == "pop")
        {
            std::cout << jhs.pop() << std::endl;
        }
        else if (str == "size")
        {
            std::cout << jhs.size() << std::endl;
        }
        else if (str == "empty")
        {
            std::cout << jhs.is_empty() << std::endl;
        }
        else if (str == "top")
        {
            std::cout << jhs.top() << std::endl;
        }
        else
        {

        }

    }

}