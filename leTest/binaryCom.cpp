//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string str1, str2,str3;
//	cin >> str1 >> str2;
//	int strLen1 = str1.length() - 1;
//	int strLen2 = str2.length() - 1;
//	int c = 0;
//	while (strLen1 >= 0 || strLen2 >= 0 || c == 1)
//	{
//		c += strLen1 >= 0 ? str1[strLen1--] - '0' : 0;
//		c += strLen2 >= 0 ? str2[strLen2--] - '0' : 0;
//		str3 = char(c % 2 + '0') + str3;
//		c /= 2;
//	}
//	cout << str3;
//
//	system("pause");
//
//}