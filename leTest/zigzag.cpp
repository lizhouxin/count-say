//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string inStr;
//	int nSize = 3;
//	cin >> inStr;
//	const int len = inStr.length();
//	string *str = new string[nSize];
//	int step = 1,row = 0;
//	for (int i = 0; i < len; i++)
//	{
//		str[row].push_back(inStr[i]);
//		if (row == 0)
//			step = 1;
//		else if (row == nSize - 1)
//			step = -1;
//		row += step;
//	}
//	inStr.clear();
//	for (int i = 0; i < nSize; i++)
//	{
//		inStr.append(str[i]);
//	}
//	delete [] str;
//	cout << inStr << endl;
//
//	system("pause");
//	return 0;
//}