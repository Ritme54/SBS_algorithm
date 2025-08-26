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
<<<<<<< Updated upstream

=======
	void insert(int vertex, int edge)
	{
	
		adjacencyList[vertex].push_back(edge);
		degree[edge]++;
		cout << vertex << " : " << degree[edge] << endl;
	}
	
	
private:
	int degree[SIZE];
	bool visited[SIZE];
	queue<int>queue;
	vector<int> adjacencyList[SIZE];
>>>>>>> Stashed changes
};

class backtracking
{
private:
	int n;
	vector<int> solution;
	bool isValid[SIZE];
public:
	backtracking(int n) : n(n) // 생성자
	{
		solution.resize(n); // 백터의 크기를 n으로 설정
		for (int i = 0; i < SIZE; i++)// 초기화
		{
			isValid[i] = true;
		}
	}

	void search(int depth)
	{
		if (depth == n) // 깊이가 n에 도달하면 해답을 찾은 것
		{
			for (int i = 0; i < n; i++)
			{
				cout << solution[i] << " ";
			}
			cout << endl;
			return;
		}
		for (int i = 0; i < SIZE; i++) // 가능한 모든 경우를 탐색
		{
			if (isValid[i]) // 유효한 경우인지 확인
			{
				solution[depth] = i; // 현재 깊이에 해당하는 값을 설정
				isValid[i] = false; // 해당 값은 사용했으므로 유효하지 않게 설정
				search(depth + 1); // 다음 깊이로 진행
				isValid[i] = true; // 백트래킹: 이전 상태로 되돌림


<<<<<<< Updated upstream
=======
			}
			else // 유효하지 않은 경우
			{
				continue; // 다음 반복으로 넘어감
			}


		}

	}



};
		

>>>>>>> Stashed changes
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



<<<<<<< Updated upstream
=======
	//3.간선 제거 이후에 진입 차수가 0이 된 정점을 Queue에 삽입합니다.

	//4. Queue가 비어있을 때까지 2번, 3번 작업을 반복합니다.

	//Graph graph;
	//graph.insert(1,2);
	//graph.insert(1,5);
	//graph.insert(2,3);
	//graph.insert(3,4);
	//graph.insert(4,6);
	//graph.insert(5,6);
	//graph.insert(6,7);
>>>>>>> Stashed changes


#pragma endregion


<<<<<<< Updated upstream
=======
#pragma region 퇴각 검색(백트래킹 알고리즘) [숙제]

	//퇴각 검색(Backtracking) : 문제를 해결하기 위해 가능한 모든 경우를 탐색하는 알고리즘입니다.
	//해당 문제는 퇴각 검색을 통해 해결할 수 있습니다.
	//시간 복잡도 : O(n!)
	//1. 현재 상태에서 가능한 모든 경우를 탐색합니다.
	//2. 각 경우에 대해 유효성을 검사합니다.
	//3. 유효한 경우에 대해서만 다음 단계로 진행합니다.
	//4. 모든 경우를 탐색하거나 유효하지 않은 경우가 발생하면 이전 단계로 되돌아갑니다.
	//5. 최종적으로 원하는 해답을 찾습니다.

	int n = 2; 
	backtracking bt(n);
	bt.search(1);
	


#pragma endregion

>>>>>>> Stashed changes


	return 0;
}
