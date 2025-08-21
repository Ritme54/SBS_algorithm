#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 6

#define INFINITY 1000000



using namespace std;
//cosnt long long INFINITY = 1e18

class Dijkstra
{
private:
	int graph[SIZE][SIZE] =
	{
		{0,2,5,1, INFINITY, INFINITY},
		{2,0,3,2, INFINITY, INFINITY},
		{5,3,0,3, 1,		 5		},
		{1,2,3,0, 1, INFINITY},
		{INFINITY,INFINITY,1,1, 0, 2},
		{INFINITY,INFINITY,5,INFINITY, 2, 0}

	};
	bool visited[SIZE];
	int dist[SIZE];
	int parent[SIZE];
	int lastMinIndex_;

	const int& find()
	{

		int best = INFINITY;
		lastMinIndex_ = -1;
		for (int v = 0; v < SIZE; v++)
		{
			if (!visited[v] && dist[v] < best)
			{
				best = dist[v];
				lastMinIndex_ = v;
			}
		}
		return lastMinIndex_;
	}
	vector<int> getPath(int s, int t) const
	{
		vector<int> path;
		if (t < 0 || t >= SIZE) return path;
		if (dist[t] >= INFINITY) return path;
		for (int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
		reverse(path.begin(), path.end());
		if (path.empty() || path.front() != s) path.clear();
		return path;
	}



public:
	Dijkstra()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
			//	cout << graph[i][j] << " ";
			}

			//cout << endl;
		}
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < SIZE; i++)
		{
			dist[i] = INFINITY;
		}
		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = -1;
		}
		lastMinIndex_ = -1;
	}
	void update(int start)
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			dist[i] = INFINITY;
			parent[i] = -1;
		}
		dist[start] = 0;

		for (int iter = 0; iter < SIZE; ++iter)
		{
			const int& u = find();
			if (u == -1)
			{
				break;
			}
			visited[u] = true;

			for (int v = 0; v < SIZE; ++v)
			{
				if (visited[v])
				{
					continue;
				}
				if (graph[u][v] == INFINITY)
				{
					continue;
				}
				if (dist[v] > dist[u] + graph[u][v])
				{
					dist[v] = dist[u] + graph[u][v];
					parent[v] = u;
				}
			}
		}
		cout << "최단 거리 : " << start << endl;
		for (int v = 0; v < SIZE; v++)
		{
			if (dist[v] >= INFINITY)
			{
				cout << "-" << v << "도달 불가" << endl;
			}
			else
			{
				cout << "-" << v << ":" << dist[v] << endl;
			}



		}





		int target = 5;
		auto path = getPath(start, target);
		cout << "[경로 " << start << " -> " << target << "] ";
		if (path.empty()) cout << "도달 불가\n";
		else
		{
			for (int i = 0; i < (int)path.size(); ++i)
			{
				if (i) cout << " -> ";
				cout << path[i];
			}
			cout << "\n";
		}
	}

};



int main()
{
#pragma region 다익스트라 알고리즘
	//지작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘
	//1.거리 배열에서 weight[시작 노드]의 값들로 초기화 합니다.
	//2. 시작점을 방문 처리합니다.
	//3.거리 배열에서 최소 비용 노드를 찾고 방문 처리합니다. 단. 이미 방문한 노드는 제외합니다.
	//4. 최소 비용 노드를 거처갈 지 고민해서 거리 배열을 갱신합니다. 단, 이미 방문한 노드는 제외합니다.

	//5. 모든 노드를 방문할 떄까지 3~4를 반복합니다.
	//방문하지 않은 노드 중에서 가장 작은 거릴 가진 노드를 방문하고, 그 노드와 연결된 다른 노드까지의 거리를 계산합니다.

	Dijkstra dijkstra;
	dijkstra.update(0);





#pragma endregion




	return 0;
}
