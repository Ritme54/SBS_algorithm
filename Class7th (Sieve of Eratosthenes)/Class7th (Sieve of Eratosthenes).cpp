#include <iostream>
#include <cmath>


using namespace std;


int box(int n)
{
	int* container = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		container[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (container[i] == 0)
		{
			continue;
		}
		for (int j = i * 2; j <= n; j += i)
		{
			container[j] = 0;
		}
	}
	for (int i = 2; i < n; i++)
	{
		if (container[i] != 0)
		{
			cout << container[i] << " ";
		}
	}

	return 0;
	delete[] container;


}


int main()
{
#pragma region 에라토스테네스의 체


	//0(N^1/2) 시간 복잡도

	box(33);


#pragma endregion

	return 0;
}





//if (n<=1)
	//{
	//	return false; //n 는 1보다 작거나 같으면 안된다.
	//}
	//if (n==2)
	//{
	//	return true; //2는 소수이므로 n은 2일때 소수이다.
	//}
	//if (n%2==0)
	//{
	//	return false; //n을 2로 나눴을때 나머지가 0이면 소수가 아니다.
	//}
	//for (int i = 3; i <= sqrt(n); i+=2) i가 3부터 n의 제곱근까지 2씩 증가한 /수/일때
	//{
	//	if (n%i==0)
	//	{
	//		return false; //n을 i로 나누었을때 나머지가 0이면 소수가 아니/다.
	//	}
	//}
	//	return true; //전부 통과하면 소수이다.

