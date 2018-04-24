////#include<iostream>
////#include<string>
////
////using namespace std;
////
////int main()
////{
////	string str = "1";
////	int input = 0;
////	while(cin >> input)
////	{
////		if (input == 0) cout << "" << endl;
////		if (input == 1) cout << "1" << endl;
////		while (--input)
////		{
////			string cur = "";
////			for (int i = 0; i < str.size(); i++)
////			{
////				int count = 1;
////				while ((i + 1 < str.size()) && (str[i] == str[i + 1]))
////				{
////					count++;
////					i++;
////				}
////				cur += to_string(count) + str[i];
////			}
////			str = cur;
////			cur.clear();
////		}
////		cout << str << endl;
////		str = "1";
////	}
////	system("pause");
////}
//#include <iostream>
//using namespace std;
//void Throw() { throw 1; }
//void NoBlockThrow() { Throw(); }
//void BlockThrow() noexcept { Throw(); }
//
//int main() {
//	try {
//		Throw();
//	}
//	catch (...) {
//		cout << "Found throw." << endl;     // Found throw.
//	}
//
//	try {
//		NoBlockThrow();
//	}
//	catch (...) {
//		cout << "Throw is not blocked." << endl;    // Throw is not blocked.
//	}
//
//	try {
//		BlockThrow();   // terminate called after throwing an instance of 'int'
//	}
//	catch (...) {
//		cout << "Found throw 1." << endl;
//	}
//	system("pause");
//}