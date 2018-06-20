/*Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

void recurChosen(map<int,string> &iver,vector<string> &res,string original,string chosen)
{
	if (original.length() == 0)
	{
		res.push_back(chosen);
		return;
	}
	char tem = original[0];
	for (int i = 0; i < iver[tem].size(); i++)
	{
		original.erase(0, 1);
		chosen.push_back(iver[tem][i]);
		recurChosen(iver, res, original, chosen);
		chosen.pop_back();
		original.insert(0, 1, tem);
	}
}

int main()
{
	map<int, string>iver = {
	{'2',"abc"},
	{'3',"def"},
	{'4',"ghi"},
	{'5',"jkl"},
	{'6',"mno"},
	{'7',"pqrs"},
	{'8',"tuv"},
	{'9',"wxyz"}
	};
	vector<string> res;
	string original, chosen;
	cin >> original;
	recurChosen(iver, res, original, chosen);

	system("pause");
}