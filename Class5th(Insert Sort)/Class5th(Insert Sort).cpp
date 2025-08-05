#include <iostream>

using namespace std;

int main()
{

#pragma region 삽입 정렬

	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	//자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘
	int arr[] = { 8,5,6,2,4,1,7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 0;
	int j = 0;

	for (int i = 0; i < n - 1; i++)
	{


		int key = arr[i + 1]; // 현재 위치의 다음 원소를 key로 설정
		int j = i; // 현재 위치의 인덱스를 j로 설정
		// 이미 정렬된 부분에서 key보다 큰 원소를 찾아서 한 칸씩 뒤로 이동
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j]; //arr[j + 1]에 arr[j] 값을 넣는다. 즉 뒤 위치에 앞의 값을 넣는다=값이 뒤로 밀린다.
			j--;
		}
		arr[j + 1] = key;


	}
	//시간 복잡도는 n^2

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (const auto& element : arr)
	{
		cout << element << " ";
	}


#pragma endregion






	return 0;
}