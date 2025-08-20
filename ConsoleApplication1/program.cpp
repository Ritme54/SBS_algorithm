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
	int ufFind(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = ufFind(parent[x]); // 경로 압축
	}

	bool ufUnion(int a, int b)
	{
		a = ufFind(a);
		b = ufFind(b);
		if (a == b) return false; // 같은 집합이면 사이클 발생 → 채택 금지

		return true;
	}

public:
	Kruskal()
	{

	}

	void insert(int vertexX, int vertexY, int weight)
	{
		Edge edge(vertexX, vertexY, weight);
		nodeList.push_back(edge);


	}

	void calculate()
	{
		sort(nodeList.begin(), nodeList.end());


		// 2) 분리 집합 초기화
		ufInit();

		// 3) 간선을 순회하며 MST 구성
		vector<Edge> mst;
		int cost = 0;

		for (int i = 0; i < nodeList.size(); i++)
		{
			//cout << nodeList[i].X() << endl;
			//cout << nodeList[i].Y() << endl;
			//cout << nodeList[i].W() << endl;			

			int u = nodeList[i].X();
			int v = nodeList[i].Y();
			int w = nodeList[i].W();

			// 두 정점이 다른 집합일 때만 간선 채택(사이클 방지)
			if (ufUnion(u, v))
			{
				mst.push_back(nodeList[i]);
				cost += w;
			}
		}
		cout << "MST 간선 목록 (X - Y : W)\n";
		for (size_t i = 0; i < mst.size(); ++i)
		{
			cout << mst[i].X() << " - " << mst[i].Y() << " : " << mst[i].W() << "\n";
		}
		cout << "MST 총 가중치: " << cost << "\n";

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
