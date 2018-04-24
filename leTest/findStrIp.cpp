//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
////采用深度优先遍历及递归的方法找到合适的IP如给定"25525511135"
////得到255.255.111.35或255.255.11.135
//void DFSip(vector<string> &res,string &s,int start,int num,string cur)
//{
//	int numSize = s.size() - start;
//	if (numSize < num || numSize > 3 * num)return;
//	if (1 == num)
//	{
//		if (numSize == 1 || (s[start] != '0' && atoi(s.substr(start).c_str()) <= 255))
//			res.push_back(cur + s.substr(start));
//	}
//	else
//	{
//		DFSip(res, s, start + 1, num - 1, cur + s.substr(start, 1) + ".");
//		if (s[start] != '0')
//		{
//			DFSip(res, s, start + 2, num - 1, cur + s.substr(start, 2) + ".");
//			if (atoi(s.substr(start, 3).c_str()) <= 255)
//				DFSip(res, s, start + 3, num - 1, cur + s.substr(start, 3) + ".");
//		}
//	}
//}
//int main()
//{
//	string inStr;
//	cin >> inStr;
//	vector<string> res;
//	DFSip(res, inStr, 0, 4, " ");
//	system("pause");
//	return 0;
//}