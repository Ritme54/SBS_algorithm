#include <iostream>

using namespace std;

int main()
{
#pragma region 선택 정렬

	//주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서 결과를 교체하는 방식으로 정렬하는 알고리즘입니다.
	//시간 복잡도는 0(n^2)입니다.
	int arr[] = { 6,4,8,3,1,10,7,9 };
	//첫 번째 원소를 두 번째 원소부터 마지막 원소까지 반복해서 비교해서 가장 작은 값을 찾고 첫 번째 원소와 가장 작은 원소를 교환합니다.
	//이 과정을 반복하여 작은 순서대로 정렬시킵니다.
	int n = sizeof(arr) / sizeof(arr[0]); // sizeof(arr)는 배열의 총 바이트 크기로 이 경우 int값이므로 4*n의 값을 가지고,
	//sizeof(arr[0])는 이 배열의 요소 하나의 크기를 반환하므로 int값 반환이기 때문에 4바이트이다.
	// 즉 4*/4 이기 때문에 n=n이 된다.

	for (int i = 0; i < n - 1; i++) {
		int minindex = i; // 현재 위치를 최소값으로 가정

		for (int j = i + 1; j < n; j++) {

			if (arr[j] < arr[minindex]) {

				minindex = j; // 최소값의 인덱스를 갱신
			}


		}
		std::swap(arr[i], arr[minindex]);

		// 최소값을 현재 위치와 교환
		//if (minindex != i)
		//{
		//	int temp = arr[i];
		//	arr[i] = arr[minindex];
		//	arr[minindex] = temp;
		//} //두 값을 스왑하는 코드**잊지말자! (A와 B가 있을때 C를 추가로 만들어서 에이를 시로 비를 에이로 시를 비로 (A=C, B=A, C=B))
															//  (공백)                 (A 공백)    (B공백)	   (C공백) 
	}
	//출력
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}





#pragma endregion





	return 0;
}