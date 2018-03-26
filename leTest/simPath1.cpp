/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main()
{

	string inStr,str,result;
	cin >> inStr;
	stringstream ss(inStr);
	vector<string> tem;
	while (getline(ss, str, '/'))
	{
		if (str == "" or str == ".")continue;
		if (str == ".." and !tem.empty())tem.pop_back();
		else if (str != "..") tem.push_back(str);
	}
	for (auto str1 : tem)result += "/" + str1;
	cout << result << endl;

	system("pause");
	return 0;
}