#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	vector<string> inStr;
	vector<vector<string>> outStr;
	string str1;
	do
	{
		cin >> str1;
		inStr.push_back(str1);
	} while (cin.get() != '\n');
	unordered_map<string, multiset<string>> mp;
	for (string s : inStr)
	{
		string tem;
		tem = s;
		sort(tem.begin(), tem.end());
		mp[s].insert(s);
	}
	for (auto m : mp)
	{
		vector<string> tem(m.second.begin(), m.second.end());
		outStr.push_back(tem);
	}
	system("pause");
	return 0;
}