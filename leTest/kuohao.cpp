//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//void ParenthesisMatch(vector<string> &str, string str1,int m,int n)
//{
//	if (m == 0 && n == 0)
//	{
//		str.push_back(str1);
//		return;
//	}
//	if (m != 0)ParenthesisMatch(str, str1 + "(", m - 1, n + 1);
//	if (n != 0)ParenthesisMatch(str, str1 + ")", m, n - 1);
//}
//
//int main()
//{
//	vector<string> str;
//	int num;
//	cin >> num;
//	
//	ParenthesisMatch(str, "", num, 0);
//	system("pause");
//	return 0;
//}