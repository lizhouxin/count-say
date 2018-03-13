#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;

	while (getline(cin,s))
	{
		int len = 0, tail = s.length() - 1;
		while (tail >= 0 && s[tail] == ' ') tail--;
		while (tail >= 0 && s[tail] != ' ') {
			len++;
			tail--;
		}
		cout << len << endl;
	}
	
	system("pause");
}