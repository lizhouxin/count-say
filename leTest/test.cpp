//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string str = "1";
//	int input = 0;
//	while(cin >> input)
//	{
//		if (input == 0) cout << "" << endl;
//		if (input == 1) cout << "1" << endl;
//		while (--input)
//		{
//			string cur = "";
//			for (int i = 0; i < str.size(); i++)
//			{
//				int count = 1;
//				while ((i + 1 < str.size()) && (str[i] == str[i + 1]))
//				{
//					count++;
//					i++;
//				}
//				cur += to_string(count) + str[i];
//			}
//			str = cur;
//			cur.clear();
//		}
//		cout << str << endl;
//		str = "1";
//	}
//	system("pause");
//}