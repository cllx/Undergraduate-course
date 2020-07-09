#include<iostream>
#define InitPysiBlocks 4
#define MaxPages 16
using namespace std;
unsigned int PysicalBlocks[InitPysiBlocks] = { 0 };
unsigned int PageSequence[30] = { 1,2,3,6,4,7,3,2,1,4,7,5,6,5,2,1 };
//FIFO�㷨
unsigned FIFO(unsigned *py, unsigned *pg)
{
	int i,j;
	//��ʼ����������
	for (i = 0; i < InitPysiBlocks; i++)
	{
		py[i] = pg[i];
	}
	cout << "FIFO�û��������£�" << endl;
	cout << py[0] << " " << py[1] << " " << py[2] << " " << py[3] << endl;
	//�ж��»�ȡ���ݽ�����ʱ��
	int time[4] = { 3,2,1,0 };
	//��ʼ���
	for (i = 4; i < MaxPages; i++)
	{
		for (j = 0; j < InitPysiBlocks; j++)
		{
			//����»�ȡ���Ѵ��ڣ�ֱ�����
			if (py[0] == pg[i] || py[1] == pg[i] || py[2] == pg[i] || py[3] == pg[i])
			{
				cout << py[0] << " " << py[1] << " " << py[2] << " " << py[3] << endl;
				break;
			}
			else
			{
				for (int k = 0; k < 4; k++)
				{
					if (time[k] == 3)
					{
						time[k] = 0;
						py[k] = pg[i];
					}
					else
					{
						time[k]++;
					}
				}
				cout << py[0] << " " << py[1] << " " << py[2] << " " << py[3] << endl;
				break;
			}
		}
	}
	cout << "�û�����" << endl;
	return 0;
}
//LRU�㷨
//LRU��������:���س�ĳһ���±�����������Ԫ���±�
int Max(unsigned *py, int te)
{
	int i,max = 0;
	int index = -1;
	for (i = 0; i < InitPysiBlocks; i++)
	{
		if (i == te)
		{
			continue;
		}
		else
		{
			if (py[i] > max)
			{
				max = py[i];
				index = i;
			}
			else
			{
				continue;
			}
		}
	}
	return index;
}
unsigned LRU(unsigned *py, unsigned *pg)
{
	int i,j,k;
	//��ʼ����������
	for (i = 0; i < InitPysiBlocks; i++)
	{
		py[i] = pg[i];
	}
	cout << "LRU�û��������£�" << endl;
	cout << py[0] << " " << py[1] << " " << py[2] << " " << py[3] << endl;
	//�ж��»�ȡ���ݽ�����ʱ��
	unsigned time[4] = { 3,2,1,0 };
	//ͳ�����д���
	int count[4] = { 0 };
	//��ʼ���
	for (i = InitPysiBlocks; i < 16; i++)
	{
		for (j = 0; j < InitPysiBlocks; j++)
		{

			//����»�ȡ���Ѵ��ڣ�ֱ�����,������Ӧ�����б�Ϊ1
			if (py[0] == pg[i] || py[1] == pg[i] || py[2] == pg[i] || py[3] == pg[i])
			{
				cout << py[0] << " " << py[1] << " " << py[2] << " " << py[3] << endl;
				if (py[0] == pg[i])
				{
					count[0] = 1;
				}
				else if (py[1] == pg[i])
				{
					count[1] = 1;
				}
				else if (py[2] == pg[i])
				{
					count[2] = 1;
				}
				else if (py[3] == pg[i])
				{
					count[3] = 1;
				}
				else
				{
					count[4] = 0;
				}
				break;
			}
			else
			{

				if (count[0] == 1)
				{
					//�������������ֵ
					int temp = Max(time, 0);
					py[temp] = pg[i];
					for (k = 0; k < InitPysiBlocks; k++)
					{
						time[k]++;
					}
					time[temp] = 0;
					count[0] = 0;
				}
				else if (count[1] == 1)
				{
					//�������������ֵ
					int temp = Max(time, 1);
					py[temp] = pg[i];
					for (k = 0; k < InitPysiBlocks; k++)
					{
						time[k]++;
					}
					time[temp] = 0;
					count[1] = 0;
				}
				else if (count[2] == 1)
				{
					//�������������ֵ
					int temp = Max(time, 2);
					py[temp] = pg[i];
					for (k = 0; k < InitPysiBlocks; k++)
					{
						time[k]++;
					}
					time[temp] = 0;
					count[2] = 0;
				}
				else if (count[3] == 1)
				{
					//�������������ֵ
					int temp = Max(time, 3);
					py[temp] = pg[i];
					for (k = 0; k < InitPysiBlocks; k++)
					{
						time[k]++;
					}
					time[temp] = 0;
					count[3] = 0;
				}
				else
				{
					//�������������ֵ
					int temp = Max(time, -1);
					py[temp] = pg[i];
					for (k = 0; k < InitPysiBlocks; k++)
					{
						time[k]++;
					}
					time[temp] = 0;
				}
				cout << py[0] << " " << py[1] << " " << py[2] << " " << py[3] << endl;
				break;
			}
		}
	}
	cout << "�û�����" << endl;
	return 0;
}
int main()
{
	FIFO(PysicalBlocks, PageSequence);
	LRU(PysicalBlocks, PageSequence);
	return 0;
}
