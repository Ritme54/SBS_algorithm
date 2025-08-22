#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& grid,
	vector<vector<bool>>& visited,
	int x, int y,
	int end)
{
	if (x < 0 || x >= static_cast<int>(grid.size()) || y < 0 || y >= static_cast<int>(grid[0].size()))
	{
		return false; //x또는y가 범위를 벗어나면 실패
	}
	if (grid[x][y] == 1)
	{
		return false;// 현재 칸이 벽(1)인 경우 실패
	}
	if (visited[x][y])
	{
		return false; // 현재 칸이 방문한 적 있으면(재귀 도중 되돌아온 경우)실패
	}
	if (grid[x][y] == end)
	{
		return true; // 현재 칸이 목표 칸일 경우 성공 반환
	}
	visited[x][y] = true;//칸을 방문 처리함
	static int dx[4] = { -1,1,0,0 };
	static int dy[4] = { 0,0,-1,1 };
	for (int b = 0; b < 4; ++b)
	{
		const int nx = x + dx[b];
		const int ny = y + dy[b];
		if (dfs(grid, visited, nx, ny, end))
		{
			return true;
		}
	}
	return false;
}




int map()
{
	vector<vector<int>>grid =
	{
		{2,1,0,0},
		{0,1,0,1},
		{0,0,0,0},
		{1,1,1,3},
	};
	const int start = 2;
	const int end = 3;
	int startX = -1, startY = -1;
	int endX = -1, endY = -1;
	vector<vector<bool>> visited(
		grid.size(),
		vector<bool>(grid[0].size(), false)
	);
	for (int i = 0; i < static_cast<int>(grid.size()); i++)
	{
		for (int j = 0; j < static_cast<int>(grid[i].size()); j++)
		{
			if (grid[i][j] == start)
			{
				startX = i;
				startY = j;
			}
			if (grid[i][j] == end)
			{
				endX = i;
				endY = j;
			}
		}

	}
	cout << "맵" << endl;
	for (int i = 0; i < static_cast<int>(grid.size()); i++)
	{
		for (int j = 0; j < static_cast<int>(grid[i].size()); j++)
		{
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}
	if (startX == -1 || startY == -1)
	{
		cout << "시작 없음" << endl;
		return -1;
	}
	if (endX == -1 || endY == -1)
	{
		cout << "목표 없음" << endl;
		return -1;
	}

	cout << "탐색" << startX << "," << startY << endl;
	cout << "목표" << endX << ","<< endY << endl;
	const bool reached = dfs(grid, visited, startX, startY, end);
	if (reached) {                                                   // 도달 가능한 경로가 있으면
		cout << "목적지에 도달했습니다." << "\n";                     // 성공 메시지
	}
	else {                                                         // 모든 분기가 실패하면
		cout << "목적지에 도달하지 못했습니다." << "\n";              // 실패 메시지
	}
	return 0;
}



int main()                                                           // C++ 프로그램의 진입점입니다.
{
	map();                                                           // 한 번 호출로 맵 출력 + DFS 탐색 + 결과 출력이 진행됩니다.
	return 0;                                                        // 운영체제에 정상 종료를 알립니다.
}