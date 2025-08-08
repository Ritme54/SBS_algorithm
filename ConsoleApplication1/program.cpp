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
		if (n % i==0)
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

#pragma region 개수 정렬
	////데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는 지 개수를 세어 저장한 다음 정렬하는 알고리즘
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


#pragma region 코딩 과제,완전수 만들어보기
	//완전수 구하는 함수 만들기
	//완전수= N의 진약수를 모두 더했을때 N이 되는 수
	//약수를 구하는 코드






#pragma endregion





	return 0;
}


