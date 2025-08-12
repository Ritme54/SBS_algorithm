#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combine(int  list[], int start, int middle, int end)
{
	int count = 0;
	int left = start;
	int right = middle + 1;

	int* container = new int[end - start + 1];
	//두 부분의 배열을 병합한다.
	while (left <= middle && right <= end)
	{
		if (list[left] <= list[right])
		{
			container[count++] = list[left++];
		}
		else
		{
			container[count++] = list[right++];
		}
	}
	//남은 왼쪽 배열의 요소들을 복사합니다.
	while (left <= middle)
	{
		container[count++] = list[left++];

	}
	while (right <= end)
	{
		container[count++] = list[right++];
	}
	//원본 배열에 정렬된 임시 배열의 값을 복사
	for (int i = 0; i < end - start + 1; i++)
	{
		list[start + i] = container[i];

	}
	delete[] container;

}

//남은 함수는 영상보고 만들기





int main()
{

#pragma region 







#pragma endregion








	return 0;
}


