#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<vector<int>> iver(3, vector<int>(4, 0));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < iver[0].size(); j++)
		{
			cin >> iver[i][j];
		}
	}
	int m = iver.size(), n = iver[0].size(), res = 0,cur = 0;
	res += (1 << n - 1) * m;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)cur += iver[i][j] == iver[i][0];
		res += max(cur, m - cur) * (1 << n - 1 - i);
	}
	cout << res;
	system("pause");
}