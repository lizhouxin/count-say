#include<vector>
#include<stack>
#include<iostream>
#include<string>
using namespace std;

template <typename T, typename T1>
class stackClass {
private:
	T data;
public:
	stackClass(T x) : data(x){};
	virtual ~stackClass() {};
	vector<T1> infixToPostfix(const T & str);
	int postfixCompute(vector<T1> &str1);
};
//中缀变后缀
template <typename T, typename T1>
vector<T1> stackClass<T, T1>::infixToPostfix(const T &str)
{
	vector<T1> iver;
	stack<T1> sta;
	int num = str.size();
	for (int i = 0; i < num; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
				iver.push_back(str[i]);
		else
		{
			switch (str[i]) {
			case '(':
				while (i < num && str[i] != ')')
				{
					if(str[i] >= '0' && str[i] <= '9')
						iver.push_back(str[i]);
					else
					{
						sta.push(str[i]);
						iver.push_back(' ');
					}	
					i++;
				}
				if (i >= num)
				{
					cout << "error" << endl;
					break;
				}
				while (!sta.empty() && sta.top() != '(')
				{
					iver.push_back(sta.top());
					sta.pop();
				}
				if(!sta.empty())
					sta.pop();
				break;
			case '+':
			case '-':
				while (!sta.empty())
				{
					iver.push_back(sta.top());
					sta.pop();
				}
				sta.push(str[i]);
				iver.push_back(' ');
				break;
			case '*':
			case '/':
				if (sta.top() == '*' || sta.top() == '/')
				{
					iver.push_back(sta.top());
					sta.pop();
				}
				sta.push(str[i]);
				iver.push_back(' ');
				break;
			default: cout << "The falut";
			}	
		}
		if(i == num - 1)
			while (!sta.empty())
			{
				iver.push_back(sta.top());
				sta.pop();
			}
	}
	cout << "ok" << endl;
	return iver;
}
//后缀表达式计算
template <typename T, typename T1>
int stackClass<T, T1>::postfixCompute(vector<T1> &str1)
{
	int num = str1.size();
	stack<int> sta;
	int tem = 0,a = 0, b = 0;
	for (int i = 0; i < num;)
	{
		while (i < num && str1[i] >= '0' && str1[i] <= '9')
		{
			tem = tem * 10 + str1[i] - '0';
			i++;
			if(str1[i] < '0' || str1[i]  > '9')
				sta.push(tem);
		}
		tem = 0;
		while (i < num && str1[i] == ' ')
			i++;
		if (str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/')
		{
			if (sta.size() >= 2)
			{
				a = sta.top();
				sta.pop();
				b = sta.top();
				sta.pop();
				switch (str1[i]) {
				case '+':
					sta.push(b + a);
					break;
				case '-':
					sta.push(b - a);
					break;
				case '*':
					sta.push(b * a);
					break;
				case '/':
					sta.push(b / a);
					break;
				default:
					cout << "error compute" << endl;
				}
			}
			else
				cout << "error compute" << endl;
			i++;
		}
	}
	if (sta.empty())
		return -1;
	else
		return sta.top();
	cout << "compute is ok" << endl;
}
int main()
{
	string str;
	cin >> str;
	//for (int i = 0; i < str.size(); i++)
	//	cout << str[i];
	//char tem[] = { 9,'+','(',3,'-',1,')','*',3,'+',10,'/',2};
	stackClass<string, char> ptr("nihao");
	vector<char> iver;
	int res = 0;
	iver = ptr.infixToPostfix(str);
	res = ptr.postfixCompute(iver);
	cout << "The result is : " << res << endl;
	system("pause");
}
//9+(3-1)*3+10/2