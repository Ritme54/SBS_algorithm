#include <iostream>
#include <vector>
#include <queue>


using namespace std;

#define SIZE 8
class Graph
{
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	void insert(int i, int j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
	}

	void bfs(int start)
	{
		if (start < 0 || start >= SIZE)
		{
			return;
		}

		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}

		queue<int>queue;
		visited[start] = true;
		queue.push(start);

		while (!queue.empty())
		{
			int cur = queue.front();
			queue.pop();
			cout << cur << " ";

			for (int i = 0; i < adjacencyList[cur].size(); i++)
			{
				int next = adjacencyList[cur][i];
				if (visited[next] == false)
				{
					queue.push(next);
					visited[next] = true;
				}


			}

			//for (int next : adjacencyList//[cur])
			//{
			//	if (!visited[next])
			//	{
			//		visited[next] = true;
			//		queue.push(next);
			//	}
			//}
		}
		cout << "\n";


	}




private:

	bool visited[SIZE];
	vector<int> adjacencyList[SIZE];
};




int main()
{

#pragma region 너비 우선 탐색(Breadth First Search)
	//시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선적으로 방문하는 탐색
	//더 이상 방문하지 않은 정점이 없을 때까지 방문하지 않은 모든 정점들에 대해서 너비 우선 탐색을 적용합니다.

	Graph graph;

	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 4);
	graph.insert(2, 5);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.bfs(1);

#pragma endregion


	return 0;
}
