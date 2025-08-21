#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 8



using namespace std;

class Kruskal
{
private:
	class Edge
	{
	private:
		int vertexX;
		int vertexY;
		int weight;
	public:
		Edge(int vertexX, int vertexY, int weight)
		{
			this->vertexX = vertexX;
			this->vertexY = vertexY;
			this->weight = weight;

		}

		const bool& operator<(const Edge& edge) const
		{


			return weight < edge.weight;
		}

		const int& X() { return vertexX; }
		const int& Y() { return vertexY; }
		const int& W() { return weight; }


	};

	vector<Edge>nodeList;

	int parent[SIZE];
	void ufInit()
	{
		for (int i = 0; i < SIZE; ++i)
		{
			parent[i] = i;
		}
	}
	int Find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]); // 경로 압축
	}

	bool Union(int x, int y)
	{

		x = Find(x);
		y = Find(y);
		if (x == y)return false;
		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
		return true;
	}
	bool same(int x, int y)
	{
		return Find(x) == Find(y);

	}
	int cost;
public:
	Kruskal()
	{
		cost = 0;
		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}

	void insert(int vertexX, int vertexY, int weight)
	{
		Edge edge(vertexX, vertexY, weight);
		nodeList.push_back(edge);


	}



	void calculate()
	{
		sort(nodeList.begin(), nodeList.end());

		for (int i = 0; i < nodeList.size(); i++)
		{
			//cout << nodeList[i].X() << endl;
			//cout << nodeList[i].Y() << endl;
			//cout << nodeList[i].W() << endl;

			if (same(nodeList[i].X(), nodeList[i].Y()) == false)
			{
				cost += nodeList[i].W();
				Union(nodeList[i].X(), nodeList[i].Y());
			}
		}
	}
		
};


		int main()
		{

#pragma region 최소 신장 트리
			//그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는 부분 그래프로,
			// 그래프의 모든 정점을 최소 비용으로 연결하는 트리입니다.

			// 그래프의 정점의 수가n개 일때, 간선의 수는 n-1개 입니다.

			//1. 정렬된 순서에 맞게 그래프에 포함시킵니다.
			//2. 포함시키기 전에 사이클이 형성되는지 확인합니다.
			//3.사이클을 형성하는 경우 간선을 포함하지 않습니다.

			Kruskal kruskal;

			kruskal.insert(1, 7, 12);
			kruskal.insert(4, 7, 13);

			kruskal.insert(2, 4, 23);
			kruskal.insert(2, 5, 65);

			kruskal.insert(1, 2, 71);
			kruskal.insert(5, 7, 79);

			kruskal.insert(1, 4, 30);
			kruskal.insert(1, 5, 15);
			kruskal.insert(3, 5, 18);

			kruskal.insert(3, 6, 36);
			kruskal.insert(5, 6, 44);

			kruskal.calculate();

#pragma endregion






			return 0;
		}
