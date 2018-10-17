#include<iostream>
#include"Queue.h"

#include <time.h>

using namespace std;

class simulator {
private:
	int busArrlow;//客车到达时间下限
	int busArrHigh;//客车到达时间上限
	int truckArrlow;//货车到达时间下限
	int truckArrHigh;//货车到达时间上限
	int totaltime;//需要模拟的时间
public:
	simulator();
	void avgWaitTime();
};
simulator::simulator()
{   
	cout << "请输入需要模拟的时间" << endl;
	cin >> totaltime;
	cout << "请输入客车到达时间的上下限(下限 上限)" << endl;
	cin >> busArrlow >> busArrHigh;
	cout << "请输入货车到达时间的上下限(下限 上限)" << endl;
	cin >> truckArrlow >> truckArrHigh;
	cout << endl;
}

void simulator::avgWaitTime()
{
	int currentTime;//当前时间
	double busNum, truckNum;//客车 货车上船数量
	int ship;//当前船上的车数
	double busWaitTime, truckWaitTime;//客车 货车总等待时间
	linkQueue<int> busQueue;//客车等待队列
	linkQueue<int> truckQueue;//货车等待队列
	srand(time(NULL));
	int shipNum = 0;//来的船的数量
					//生成客车队列
	currentTime = 0;
	busNum = 0;

	cout << "客车到达时间分别为" << endl;
	while (1)
	{
		currentTime += busArrlow + rand() % (10);
		cout << currentTime << ' ';
		if (currentTime > totaltime)
			break;
		else
			busQueue.enQueue(currentTime);
	}
	cout << endl;
	//生成货车队列
	currentTime = 0;
	truckNum = 0;
	cout << "货车到达时间分别为" << endl;
	while (1)
	{
		currentTime += truckArrlow + rand() % (10);

		cout << currentTime << ' ';
		if (currentTime > totaltime)
			break;
		else
			truckQueue.enQueue(currentTime);
	}
	cout << endl;
	cout << "客车货车入队完毕" << endl;
	cout << endl;
	//开始模拟
	cout << "开始模拟" << endl;
	busWaitTime = truckWaitTime = 0;
	currentTime = 0;

	for (currentTime = 10; currentTime <= totaltime; currentTime += 10)//每次来一艘船
	{
		shipNum += 1;
		cout << "第" << shipNum << "条船来了" << endl;
		ship = 0; //船上车辆开始为0
		for (; ship < 8 && !busQueue.isEmpty() && busQueue.getHead() <= currentTime; ++ship)
		{
			busWaitTime += currentTime - busQueue.deQueue();
			busNum += 1;
		}
		cout << "上了" << ship << "辆客车" << endl;

		int i = 0;
		for (; ship < 10 && !truckQueue.isEmpty() && truckQueue.getHead() <= currentTime; ++ship)
		{
			truckWaitTime += currentTime - truckQueue.deQueue();
			truckNum += 1;
			i++;

		}
		cout << "上了" << i << "辆货车" << endl;

		if (ship < 10)
		{
			for (; ship < 10 && !busQueue.isEmpty() && busQueue.getHead() <= currentTime; ++ship)
			{
				busWaitTime += currentTime - busQueue.deQueue();
				busNum += 1;
			}
		}
		cout << "本次轮渡一共上了" << ship << "辆客车和货车" << endl;
	}

	cout << "模拟结束" << endl;
	cout << "客车总等待时间" << busWaitTime << endl;
	cout << "客车上船数" << busNum << endl;
	cout << "客车的平均等待时间是" << busWaitTime / (busNum) << "分钟" << endl;
	cout << "货车总等待时间" << truckWaitTime << endl;
	cout << "货车上船数" << truckNum << endl;
	cout << "货车的平均等待时间是" << truckWaitTime / (truckNum) << "分钟" << endl;

}


int main()
{
	simulator sim;
	
	sim.avgWaitTime();
	system("pause");
	return 0;
}