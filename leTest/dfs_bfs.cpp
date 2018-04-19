/*深度优先搜索，广度优先搜索*/
//创建邻接矩阵
#include<iostream>
#include<queue>
using namespace std;

typedef char VerTexType;
typedef int EdgeType;
#define MAXVEX 10
#define INFINITY 65535
typedef struct {
	VerTexType ver[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;
//创建邻接矩阵
void CreateMGraph(MGraph *G)
{
	cout << "输入顶点数和边数: " << endl;
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++)
	{
		cin >> G->ver[i];
	}
	for (int i = 0;i < G->numVertexes;i++)
		for (int j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	for (int i = 0; i < G->numEdges; i++)
	{
		cout << "输入边上下标与权值: " << endl;
		int m, n,w;
		cin >> m >> n >> w;
		G->arc[m][n] = G->arc[n][m] = w;
	}
}
//创建邻接表，只表示出度表
//边节点表
typedef struct EdgeNode {
	int adjvex;
	EdgeType weight;
	struct EdgeNode * next;
}EdgeNode;
//顶点节点表
typedef struct VertxNode {
	VerTexType data;//存储顶点信息
	EdgeNode * firstedge;
}VertexNode,AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVextexes, numEdges;
}GraphAdjList;
void CreateALGraph(GraphAdjList * G)
{
	cout << "输入顶点数与边数: " << endl;
	EdgeNode * e;
	cin >> G->numVextexes >> G->numEdges;
	for (int i = 0; i < G->numVextexes; i++)
	{
		cin >> G->adjList[i].data;
		G->adjList[i].firstedge = NULL;//建立顶点表
	}
	int m, n;
	for (int k = 0; k < G->numEdges; k++)
	{
		//无向图的邻接表
		cout << "输入边的顶点上下标: " << endl;
		cin >> m >> n;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = m;//邻接点m
		e->next = G->adjList[n].firstedge;//将当期节点赋给顶点
		G->adjList[n].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = n;//邻接点n
		e->next = G->adjList[m].firstedge;
		G->adjList[m].firstedge = e;
	}
}

//深度优先遍历递归的方法，先按照一定的次序遍历，类似于树的先序遍历
//邻接矩阵
bool visit[MAXVEX];
void DFS(MGraph G, int i)
{
	int j;
	visit[i] = true;
	cout << G.ver[i] << endl;
	for (j = 0; j < G.numVertexes; j++)
	{
		if (!visit[j] && 1 == G.arc[i][j])
		{
			DFS(G, j);
		}
	}
}
void DFSTraverse(MGraph G)
{
	for (int i = 0; i < G.numVertexes; i++)
	{
		visit[i] = false;
	}
	for (int i = 0; i < G.numVertexes; i++)
	{
		if (!visit[i])
		{
			DFS(G, i);
		}
	}
}
//邻接表深度优先遍历
void DFSTable(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visit[i] = true;
	cout << GL.adjList[i].data << "顶点信息" << endl;
	p = GL.adjList[i].firstedge;
	while (p)
	{
		if (!visit[p->adjvex])
			DFSTable(GL, p->adjvex);
		p = p->next;
	}
}
void DFSTraverseTable(GraphAdjList GL)
{
	for (int i = 0; i < GL.numVextexes; i++)
	{
		visit[i] = false;
	}
	for (int i = 0; i < GL.numVextexes; i++)
	{
		if (!visit[i])
		{
			DFSTable(GL, i);
		}
	}
}
//广度优先遍历，利用队列思想，按照树的层序遍历
//邻接矩阵
void BFSTraverse(MGraph G)
{
	deque<int> Q(MAXVEX,0);
	for (int i = 0; i < G.numVertexes; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < G.numVertexes; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			cout << G.ver[i];
			Q.push_back(i);
			while (!Q.empty())
			{
				Q.pop_front();
				for (int j = 0; j < G.numVertexes; j++)
				{
					if (1 == G.arc[i][j] && !visit[j])
					{
						cout << "顶点信息: " << G.ver[j] << endl;
						Q.push_front(j);
					}
				}
			}
		}
	}
}
//广度优先遍历
//邻接表
void BSFTraverTable(GraphAdjList GL)
{
	EdgeNode * p;
	deque<int> Q;
	for (int i = 0; i < GL.numVextexes; i++)
	{
		visit[i] = false;
	}
	for (int i = 0; i < GL.numVextexes; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			cout << "顶点信息: " << GL.adjList[i].data << endl;
			Q.push_back(i);
			while (!Q.empty())
			{
				Q.pop_front();
				p = GL.adjList[i].firstedge;
				while (p)
				{
					if (!visit[p->adjvex])
					{
						visit[p->adjvex] = true;
						cout << "节点信息: " << GL.adjList[p->adjvex].data << endl;
						Q.push_back(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
	
}

int main()
{


	system("pause");
	return 0;
}



