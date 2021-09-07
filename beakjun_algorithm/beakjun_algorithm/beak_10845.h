#pragma once
#include <iostream>

class jh_queue {
	int* mpData;	// 큐 데이터
	int mSize;		// 큐의 크기
	int mDataCount;
	int mFront;
	int mRear;
	


	void init(int size)
	{
		if (mpData == nullptr)
		{
			mpData = new int[size];
			std::fill(mpData, mpData + size, 0x00);
		}
			
	}
public :
	jh_queue(int size): mpData(nullptr), mSize(size), mDataCount(0), mFront(0), mRear(0)
	{
		init(mSize);
	}
	~jh_queue()
	{
		if (mpData != nullptr)
		{
			delete[] mpData;
		}
	}
	bool is_empty() { return (mDataCount) ? false : true; }
	bool is_full() { return (mDataCount >= mSize) ? true : false; }
	const int front() const { return (mDataCount) ? mpData[mFront] : -1; }
	const int back() const { return (mDataCount) ? mpData[mRear-1] : -1; }
	const int size() const { return mDataCount; }
	void push(int val)
	{
		if (is_full() == false)
		{
			mpData[mRear] = val;
			mRear++;
			mDataCount++;
			if (mRear == mSize) mRear = 0;
		}
		else
		{
			//std::cout << "queue is full" << std::endl;
		}
	}
	int pop()
	{
		int rtn = 0;
		if (is_empty() == true)
		{
			//std::cout << "queue is empty" << std::endl;
			rtn = -1;
		}
		else
		{
			rtn = mpData[mFront];
			mpData[mFront] = 0;
			mFront++;
			mDataCount--;
			if (mFront == mSize) mRear = 0;
		}
		return rtn;
	}


};


int sol_10845_main()
{
	int number_of_line = 0;
	std::cin >> number_of_line;

	jh_queue jhq(number_of_line);

	for (int i = 0; i < number_of_line; i++)
	{
		std::string str;
		std::cin >> str;

		if (str == "push")
		{
			int data = 0;
			std::cin >> data;
			jhq.push(data);
		}
		else if (str == "pop")
		{
			std::cout << jhq.pop() << std::endl;
		}
		else if (str == "size")
		{
			std::cout << jhq.size() << std::endl;
		}
		else if (str == "empty")
		{
			std::cout << jhq.is_empty() << std::endl;
		}
		else if (str == "empty")
		{
			std::cout << jhq.is_empty() << std::endl;
		}
		else if(str == "front")
		{
			std::cout << jhq.front() << std::endl;
		}
		else if (str == "back")
		{
			std::cout << jhq.back() << std::endl;
		}

	}
	return 0;
}