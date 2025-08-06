#include <iostream>
#include <cmath>


using namespace std;


int box(int n)
{
	if (n<=1)
	{
		return false; //n 는 1보다 작거나 같으면 안된다.
	}
	if (n==2)
	{
		return true; //2는 소수이므로 n은 2일때 소수이다.
	}
	if (n%2==0)
	{
		return false; //n을 2로 나눴을때 나머지가 0이면 소수가 아니다.
	}
	for (int i = 3; i <= sqrt(n); i+=2) // i가 3부터 n의 제곱근까지 2씩 증가한 수일때
	{
		if (n%i==0)
		{
			return false; //n을 i로 나누었을때 나머지가 0이면 소수가 아니다.
		}
	}
		return true; //전부 통과하면 소수이다.
		
		
}


int main()
{
#pragma region 에라토스테네스의 체

	//int j = 0;
	//int n = 50;
	//for (int i = 2; i <= n; i++)
	//{
	//	for (j = 2; j < i; j++)
	//	{
	//		if (i%j==0)
	//		{
	//			break;
	//		}
	//	}
	//	if (i==j)
	//	{
	//		cout << i << " ";
	//
	//
	//	}
	//}
	//0(N^1/2) 시간 복잡도

	for (int i = 2; i < 50; i++)
	{
		if (box(i))
		{
			cout << i<< endl;
		}
	}


#pragma endregion

	return 0;
}