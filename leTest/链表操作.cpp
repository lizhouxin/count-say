#include<iostream>

using namespace std;
template <typename T>
struct Node {
	T data;
	Node<T>* next;
	//Node() { next = NULL; }
};

template <typename T1, typename T2>
struct StaNode {
	T1 data;
	T2 cur;
};
typedef Node<int>* link_type0;
typedef Node<int> value_type0;
typedef  StaNode<int, int>* link_type;
typedef  StaNode<int, int> value_type;

//��̬����
link_type0 dyLink(link_type0 head)
{
		link_type0 t;
		head->next = NULL;
		//ͷ��ڵ�
		//for (int i = 0; i < 5; i++)
		//{
		//	t = new value_type;
		//	//t = (link_type)malloc(sizeof(value_type));
		//	t->data = i + 1;
		//	t->next = head->next;
		//	head->next = t;
		//}
		//β��ڵ�
		link_type0 p = new value_type0;
		p = head;
		for (int i = 0; i < 5; i++)
		{
			t = new value_type0;
			t->data = i + 1;
			t->next = NULL;
			p->next = t;
			p = p->next;
		}
		cout << "����ڵ㣺" << endl;
		p = head->next;
		while(p)
		{
			cout << p->data << endl;
			p = p->next;
		}
		//ɾ���ڵ�
		p = head;
		while (p->next && p->next->data != 3)
		{
			p = p->next;
		}
		if (!p->next)
			cout << -1 << endl;
		p->next = p->next->next;
		link_type0 p1 = new value_type0;
		p1 = head->next;
		while(p1)
		{
			cout << p1->data << endl;
			p1 = p1->next;
		}
		//ɾ����������
		/*p = head;
		link_type0 q;
		while (p)
		{
			q = p->next;
			free(p);
			p = q;
		}
		head->next = NULL;*/
		p = NULL;
		free(p);
		free(p1);
		return head;
}
//��̬����
const int MAX_SIZE = 100;
void StaticLink(link_type head)
{
	//0��Ϊͷָ�룬99��Ϊβָ��
	for (int i = 0; i < MAX_SIZE - 1; i++)
		head[i].cur = i + 1;
	head[MAX_SIZE - 1].cur = 0;
	//����
	head[1].data = 10;
	head[99].cur = head[0].cur;
	//head[99].cur = 0;
	//for (int i = 1; i < 100; i++)
	//	head[i].data = i + 10;

	//for (int i = 1; i < 100; i++)
	//	cout << head[i].data << "   ";
}
link_type0 reverseLink(link_type0 head)
{
	link_type0 p, q, pr;
	q = NULL;
	p = head->next;
	head->next = NULL;
	while (p)
	{
		pr = p->next;
		p->next = q;
		q = p;
		p = pr;
	}
	head->next = q;

	cout << "��ת֮��" << endl;
	link_type0 p1 = new value_type0;
	p1 = head->next;
	while (p1)
	{
		cout << p1->data << endl;
		p1 = p1->next;
	}
	return head;
}
int main()
{
	link_type0 head0 = new value_type0;//��̬
	link_type0 head1 = new value_type0;
	link_type0 head2 = new value_type0;
	//link_type head = new value_type[MAX_SIZE];//��̬
	head1 = dyLink(head0);
	//StaticLink(head);
	head2 = reverseLink(head1);
	system("pause");
}