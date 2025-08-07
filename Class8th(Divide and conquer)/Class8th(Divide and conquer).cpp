// Class8th(Divide and conquer).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
#include <iostream>

using namespace std;


int max(int list[], int left, int right)
{

	if (left == right)
	{
		return list[left];
	}
	else
	{
		int leftMax = max(list, left, (left + right) / 2);
		int rightMax = max(list, (left + right) / 2 + 1, right);
		if (leftMax < rightMax)
		{
			return rightMax;
		}
		else
		{
			return leftMax;
		}

	}







}

int main()
{


#pragma region 분할 정복

	//주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분 문제에 대한 답을 재귀 호출을 이용하여 계산한 다음 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘
	// 분할(Divide) : 주어진 문제를 두 개 혹은 그 이상의 형식으로 나눈다.
	// 정복(Conquer) : 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를 더 이상 나누어서 문제가 필요없을 때까지 계속 분할
	// 통합(Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성

	int list[] = { 20,15,99,1 };
	int size = sizeof(list) / sizeof(list[0]);
	cout << max(list, 0, size - 1) << endl;
#pragma endregion




	return 0;
}


