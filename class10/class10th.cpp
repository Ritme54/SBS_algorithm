#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//int con(int list[], int n)
//{
//
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (list[j] > list[j + 1]) {
//				//swap
//				int temp = list[j];
//				list[j] = list[j + 1];
//				list[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << list[i] << " ";
//	}
//
//	return 0;
//}

int box(int n)
{
	int k = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (n % i == 0)
		{
			for (int k = 1; k < n % i; k++)
			{

			}

			cout << i << " ";
		}
	}

	return 0;
}



int main()
{

#pragma region ���� ����
	////�������� ���� ������ �ʰ� �� ���ҿ� �����Ͱ� �� �� �ִ� �� ������ ���� ������ ���� �����ϴ� �˰���
	//
	//int list[] = { 1, 3, 2, 2, 4, 5, 1, 2 };
	//int n = sizeof(list) / sizeof(list[0]);
	//
	//con(list, n);
	//
	//
	//for (int i = 0; i < n - 1; i++)
	//{
	//	int cnt = count(list, list + n, k)
	//}

	box(7);

	int A = 6;
	int B = 2;
	int C = A / B;
	//cout << C << " ";





#pragma endregion


#pragma region �ڵ� ����,������ ������
	//������ ���ϴ� �Լ� �����
	//������= N�� ������� ��� �������� N�� �Ǵ� ��
	//����� ���ϴ� �ڵ�






#pragma endregion





	return 0;
}


