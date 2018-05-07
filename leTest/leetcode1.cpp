/*In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.
Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
	string inStr;
	cin >> inStr;
	int m = 0, n = 0;
	pair<int, int>num;
	
	int size = inStr.size();
	vector<vector<int> > np(size);
	for (int i = 0; i < size; i++)
		np[i].resize(2);
	int tem = 0;
	while (size > m || size > n )
	{
		m++;
		if (inStr[m] != inStr[n])
		{
			if ((m - n) >= 3)
			{
				np[tem++][0] = n;
				np[tem++][1] = m - 1;
				//np.push_back(make_pair(n, m - 1));
			}
			n = m;
		}	
	}
	system("pause");
}