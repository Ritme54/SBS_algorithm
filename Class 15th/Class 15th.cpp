#include <iostream>
#include <vector>

#define SIZE 8


using namespace std;

class Graph
{

private:
	bool visited[SIZE];
	vector<int> adjacencyList[SIZE];
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

	void dfs(int node)
	{
		visited[node] = true;
		cout << node << " ";
		for (int next : adjacencyList[node])
		{
			if (!visited[next])
			{
				dfs(next);
			}
		}
	}

	void search(int start)
	{
		if (start < 0 || start >= SIZE)
		{
			return;
		}for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
		dfs(start);
		cout << "\n";
	}

	~Graph()
	{

	}
};



int main()
{

#pragma region 깊이 우선 탐색(Depth First Search)
	//root 노드에서 다음 분기로 넘어가기전에 해당 분기를 완벽하게 탐색하는 방법.

	//관문 체크를 위해서 bool 타입으로 
#pragma endregion

	Graph graph;

	graph.insert(1, 2);
	graph.insert(1, 3);

	graph.insert(2, 3);
	graph.insert(2, 3);
	graph.insert(2, 4);

	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.insert(4, 5);
	graph.insert(6, 7);

	graph.search(1);



	return 0;
}
