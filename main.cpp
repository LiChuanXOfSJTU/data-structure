#include<iostream>
#include"Queue.h"

#include <time.h>

using namespace std;

class simulator {
private:
	int busArrlow;//�ͳ�����ʱ������
	int busArrHigh;//�ͳ�����ʱ������
	int truckArrlow;//��������ʱ������
	int truckArrHigh;//��������ʱ������
	int totaltime;//��Ҫģ���ʱ��
public:
	simulator();
	void avgWaitTime();
};
simulator::simulator()
{   
	cout << "��������Ҫģ���ʱ��" << endl;
	cin >> totaltime;
	cout << "������ͳ�����ʱ���������(���� ����)" << endl;
	cin >> busArrlow >> busArrHigh;
	cout << "�������������ʱ���������(���� ����)" << endl;
	cin >> truckArrlow >> truckArrHigh;
	cout << endl;
}

void simulator::avgWaitTime()
{
	int currentTime;//��ǰʱ��
	double busNum, truckNum;//�ͳ� �����ϴ�����
	int ship;//��ǰ���ϵĳ���
	double busWaitTime, truckWaitTime;//�ͳ� �����ܵȴ�ʱ��
	linkQueue<int> busQueue;//�ͳ��ȴ�����
	linkQueue<int> truckQueue;//�����ȴ�����
	srand(time(NULL));
	int shipNum = 0;//���Ĵ�������
					//���ɿͳ�����
	currentTime = 0;
	busNum = 0;

	cout << "�ͳ�����ʱ��ֱ�Ϊ" << endl;
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
	//���ɻ�������
	currentTime = 0;
	truckNum = 0;
	cout << "��������ʱ��ֱ�Ϊ" << endl;
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
	cout << "�ͳ�����������" << endl;
	cout << endl;
	//��ʼģ��
	cout << "��ʼģ��" << endl;
	busWaitTime = truckWaitTime = 0;
	currentTime = 0;

	for (currentTime = 10; currentTime <= totaltime; currentTime += 10)//ÿ����һ�Ҵ�
	{
		shipNum += 1;
		cout << "��" << shipNum << "��������" << endl;
		ship = 0; //���ϳ�����ʼΪ0
		for (; ship < 8 && !busQueue.isEmpty() && busQueue.getHead() <= currentTime; ++ship)
		{
			busWaitTime += currentTime - busQueue.deQueue();
			busNum += 1;
		}
		cout << "����" << ship << "���ͳ�" << endl;

		int i = 0;
		for (; ship < 10 && !truckQueue.isEmpty() && truckQueue.getHead() <= currentTime; ++ship)
		{
			truckWaitTime += currentTime - truckQueue.deQueue();
			truckNum += 1;
			i++;

		}
		cout << "����" << i << "������" << endl;

		if (ship < 10)
		{
			for (; ship < 10 && !busQueue.isEmpty() && busQueue.getHead() <= currentTime; ++ship)
			{
				busWaitTime += currentTime - busQueue.deQueue();
				busNum += 1;
			}
		}
		cout << "�����ֶ�һ������" << ship << "���ͳ��ͻ���" << endl;
	}

	cout << "ģ�����" << endl;
	cout << "�ͳ��ܵȴ�ʱ��" << busWaitTime << endl;
	cout << "�ͳ��ϴ���" << busNum << endl;
	cout << "�ͳ���ƽ���ȴ�ʱ����" << busWaitTime / (busNum) << "����" << endl;
	cout << "�����ܵȴ�ʱ��" << truckWaitTime << endl;
	cout << "�����ϴ���" << truckNum << endl;
	cout << "������ƽ���ȴ�ʱ����" << truckWaitTime / (truckNum) << "����" << endl;

}


int main()
{
	simulator sim;
	
	sim.avgWaitTime();
	system("pause");
	return 0;
}