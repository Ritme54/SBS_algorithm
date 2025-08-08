#include <iostream>

using namespace std;

int box(int list[], int left, int right, int A)
{

	if (left > right)
	{
		cout << A << "is not here" << endl;
		return -1;
	}

	int mid = (left + right) / 2;

	if (list[mid] == A)
	{
		cout << "find " << list[mid] << endl;
		return A;
	}
	else if (list[mid] < A)
	{

		int result = box(list, mid + 1, right, A);
		return result;

	}
	else
	{

		int result = box(list, left, mid - 1, A);
		return result;
	}


}


int main()
{
#pragma region �̺� Ž��
	//Ž�� ������ ������ ������ ã�°��� �����ϴ� ������
	//���������� ������� �����ϴ� �˰���.
	//�ð� ���⵵ 0(log N)
	//���ϰ��� �ϴ� ���� ũ��� �߰��� ũ�� ��
	int list[] = { 2, 4, 6, 8, 10, 12 };
	int size = sizeof(list) / sizeof(list[0]);
	cout << box(list, 0, size - 1, 8) << endl;


#pragma endregion





	return 0;
}


