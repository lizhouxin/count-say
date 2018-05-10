/*解决问题，将输入若干字符，对比找出共同前缀
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	vector<string> iver;
	//vector<string>::iterator iter;
	string inStr;
	//vector<char> result;
	//set<int> sizeNum;
	//set<string> S;
	//string outStr;
	do
	{
		cin >> inStr;
		iver.push_back(inStr);
	} while (cin.get() != '\n');

	set<string> s1(iver.begin(), iver.end());
	string biggestStr = "";
	string insertStr = "";
	std::pair<set<string>::iterator, bool> res;
	biggestStr = *max_element(s1.begin(), s1.end());
	int length = biggestStr.length();
	int i = 0;
	do {
		if (i != 0)
			s1.erase(insertStr);
		insertStr = biggestStr.substr(0, i++);
		res = s1.insert(insertStr);
	} while (s1.find(insertStr) == s1.begin() && i <= length && res.second == true);

	if (res.second == false) {//there is an existed same string item in set 
		if (s1.find(insertStr) == s1.begin())
			cout << insertStr << endl;//only when there is one string ele in vector
		else 
			cout << insertStr.substr(0, i - 2) << endl;
	}
	else {
		cout << insertStr.substr(0, i - 2) << endl;
	}

	//S.insert(inStr.begin(), inStr.end());
	////for (int i = 0;i < iver.size();i++)
	////{
	////	sizeNum.insert(iver[i].size());
	////}
	//string minString = *min_element(S.begin(), S.end());
	//int minNum = minString.length();
	////for(int i = 0;i < *sizeNum.begin();i++)
	//for (int i = 0; i < minNum; i++)
	//{
	//	int j = 1;
	//	for (j = 1 ; j < iver.size();)
	//	{
	//		if (iver[j][i] == iver[j - 1][i])
	//			j++;
	//		else
	//			break;
	//	}
	//	if (j == iver.size())
	//		result.push_back(iver[j - 1][i]);
	//	else
	//		break;
	//}
	//for (int i = 0; i < result.size(); i++)
	//	outStr += result[i];
	//outStr += '\0';
	//cout << outStr;
	system("pause");

}