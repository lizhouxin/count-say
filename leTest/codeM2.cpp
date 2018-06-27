/*1£¬ÕÒµ½ÔªÒô×ÖÄ¸
2£¬¼ÆËã×Ö·û´®12+12*13*/
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stack>
//#include<sstream>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//
//int main()
//{
//	string ori = "aeiou",inStr;
//	cin >> inStr;
//	int len = inStr.size();
//	int first = 0, rail = len - 1;
//	char tem;
//	while (rail - first > 0)
//	{
//		if (ori.find(inStr[rail]) == string::npos)
//			--rail;
//		else
//		{
//			if (ori.find(inStr[first]) != string::npos)
//			{
//				tem = inStr[first];
//				inStr[first] = inStr[rail];
//				inStr[rail] = tem;
//				--rail;
//			}
//			++first;
//		}
//	}
//	system("pause");
////}
//int main()
//{
//	string inStr;
//	cin >> inStr;
//	long long term = 0, total = 0,n;
//	char op;
//	istringstream in('+'+ inStr + '+');
//	while (in >> op)
//	{
//		if (op == '+' or op == '-')
//		{
//			total += term;
//			in >> term;
//			term *= 44 - op;
//		}
//		else
//		{
//			in >> n;
//			if (op == '*')
//			{
//				term *= n;
//			}
//			else
//			{
//				term /= n;
//			}
//		}
//	}
//	cout << total;
//
//	system("pause");
//}
//
//int main()
//{
//	string inStr;
//	cin >> inStr;
//	inStr += '|';
//	char sign = '+';
//	int d = 0;
//	vector<int> iver;
//
//	for (auto c : inStr)
//	{
//		if (c >= '0' and c <= '9') d = d * 10 + c - '0';
//		else
//		{
//			switch (sign)
//			{
//				case '+' : break;
//				case '-': d *= -1; break;
//				case '*': d *= iver.back(), iver.pop_back();break;
//				case '/': d = iver.back() / d, iver.pop_back();break;
//			}
//			iver.push_back(d), d = 0; sign = c;
//		}
//	}
//	int res = accumulate(iver.begin(), iver.end(), 0);
//	system("pause");
//}