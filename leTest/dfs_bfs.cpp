/*������������������������*/
//�����ڽӾ���
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
//�����ڽӾ���
void CreateMGraph(MGraph *G)
{
	cout << "���붥�����ͱ���: " << endl;
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
		cout << "��������±���Ȩֵ: " << endl;
		int m, n,w;
		cin >> m >> n >> w;
		G->arc[m][n] = G->arc[n][m] = w;
	}
}
//�����ڽӱ�ֻ��ʾ���ȱ�
//�߽ڵ��
typedef struct EdgeNode {
	int adjvex;
	EdgeType weight;
	struct EdgeNode * next;
}EdgeNode;
//����ڵ��
typedef struct VertxNode {
	VerTexType data;//�洢������Ϣ
	EdgeNode * firstedge;
}VertexNode,AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVextexes, numEdges;
}GraphAdjList;
void CreateALGraph(GraphAdjList * G)
{
	cout << "���붥���������: " << endl;
	EdgeNode * e;
	cin >> G->numVextexes >> G->numEdges;
	for (int i = 0; i < G->numVextexes; i++)
	{
		cin >> G->adjList[i].data;
		G->adjList[i].firstedge = NULL;//���������
	}
	int m, n;
	for (int k = 0; k < G->numEdges; k++)
	{
		//����ͼ���ڽӱ�
		cout << "����ߵĶ������±�: " << endl;
		cin >> m >> n;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = m;//�ڽӵ�m
		e->next = G->adjList[n].firstedge;//�����ڽڵ㸳������
		G->adjList[n].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = n;//�ڽӵ�n
		e->next = G->adjList[m].firstedge;
		G->adjList[m].firstedge = e;
	}
}

//������ȱ����ݹ�ķ������Ȱ���һ���Ĵ�������������������������
//�ڽӾ���
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
//�ڽӱ�������ȱ���
void DFSTable(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visit[i] = true;
	cout << GL.adjList[i].data << "������Ϣ" << endl;
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
//������ȱ��������ö���˼�룬�������Ĳ������
//�ڽӾ���
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
						cout << "������Ϣ: " << G.ver[j] << endl;
						Q.push_front(j);
					}
				}
			}
		}
	}
}
//������ȱ���
//�ڽӱ�
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
			cout << "������Ϣ: " << GL.adjList[i].data << endl;
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
						cout << "�ڵ���Ϣ: " << GL.adjList[p->adjvex].data << endl;
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



