#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<map>

using namespace std;

int main()
{
	stack<char> str1;
//	stack<char> str2;
	string inStr;
	cin >> inStr;
	map<char, char> tem = { {']','['},{')','('},{'}','{'} };

	for (int i = 0; i < inStr.size(); i++)
	{
		if (inStr[i] == '[' || inStr[i] == '{' || inStr[i] == '(')
			str1.push(inStr[i]);
		else if (inStr[i] == ']' || inStr[i] == '}' || inStr[i] == ')')
		{
			if (str1.empty() || tem[inStr[i]] != str1.top())
				cout << "false" << endl;
			else
				str1.pop();
		}
	}
	cout << "true" << endl;
	/*for (int i = 0; i < inStr.size(); i++)
		str1.push(inStr[i]);
	string tstr1,tstr2,tstr3;
	while (!str1.empty())
	{
		if (str2.empty())
		{
			str2.push(str1.top());
			str1.pop();
		}
		tstr1 = (char)str1.top() + '\0';
		tstr2 = (char)str2.top() + '\0';
		tstr3 = tstr1 + tstr2;
		if (tstr3 == "{}" || tstr3 == "[]" || tstr3 == "()")
		{
			str1.pop();
			str2.pop();
		}
		else
		{
			str2.push(str1.top());
			str1.pop();
		}
			
	}
	if (str2.empty())
		cout << "true" << endl;
	else
		cout << "false" << endl;*/

	system("pause");
	return 0;
}