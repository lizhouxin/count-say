/*解决问题统计字符串中子串不重复字符个数
如ABA  num = 8
如ABC  num = 10*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


//int gcd(int a, int b)
//{
//	if (b == 0)
//		return a;
//	gcd(b, a % b);
//}
int main()
{
	/*string S;
	cin >> S;
	int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
	memset(index, -1, sizeof(int) * 52);
	for (int i = 0; i < N; ++i) {
		int c = S[i] - 'A';
		res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
		index[c][0] = index[c][1];
		index[c][1] = i;
	}
	for (int c = 0; c < 26; ++c)
		res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
	cout << res;
	system("pause");*/
	//int num, a, b;
	//cin >> a >> b;
	//num = gcd(a, b);
	//cout << num << endl;
	//cout << 3 % 18;
	string S;
	cin >> S;
	int index[26][2], sum = 0, size = S.size(),mod = pow(10,9) + 7;
	memset(index, -1, sizeof(int) * 52);
	for (int i = 0; i < size; i++)
	{
		int c = S[i] - 'A';
		sum = (sum + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
		index[c][0] = index[c][1];
		index[c][1] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		sum = (sum + (size - index[i][1]) * (index[i][1] - index[i][0]) % mod) % mod;
	}
	cout << sum;
	system("pause");
}



//int DeleteRepeatCharacters(char* str)
//{
//	if (str == NULL)
//		return NULL;
//	const int hashsize = 256;
//	int hashtable[hashsize] = { 0 };
//	char* fast = str;
//	char* slow = str;
//	while (*fast != '\0')
//	{
//		if (hashtable[*fast] >= 1)
//		{
//			hashtable[*fast]++;
//			fast++;
//		}
//		else
//		{
//			hashtable[*fast] = 1;
//			fast++;
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < hashsize; i++)
//	{
//		if (hashtable[i] == 1)
//			sum++;
//	}
//	return sum;
//}
//int main()
//{
//	string inStr;
//	//string str1;
//	vector<string> str1;
//	vector<string> str2;
//	cin >> inStr;
//	for (int i = 0; i < inStr.size(); i++)
//		for (int j = 1; j <= inStr.size() - i; j++)
//		{
//			string tem = inStr.substr(i, j);
//			str1.push_back(tem);
//		}
//	int sum = 0;
//	str2 = str1;
//	for (int i = 0; i < str2.size(); i++)
//	{
//		char* tem;
//		tem = (char*)str2[i].data();
//		sum += DeleteRepeatCharacters(tem);
//	}
//
//	/*vector<string> iver;
//	for (int i = 0; i < str2.size(); i++)
//	{
//		sort(str2[i].begin(), str2[i].end());
//		unique_copy(str2[i].begin(), str2[i].end(), back_inserter(iver));
//	}*/
//	//map<string, int> mapNum;
//	//map<string, int>::iterator iter;
//	//for (int i = 0; i < str2.size(); i++)
//	//{
//	//	sort(str2[i].begin(),str2[i].end());
//	//	str2[i].erase(unique(str2[i].begin(), str2[i].end()), str2[i].end());
//	//	int num1 = str2[i].size();
//	//	mapNum.insert(make_pair(str1[i], num1));
//	//	cout << str1[i] << "   "<<num1 << endl;
//	//	//sum += num1;
//	//}
//	//for (iter = mapNum.begin(); iter != mapNum.end(); iter++)
//	//{
//	//	sum += iter->second;
//	//}
//	//cout << sum << endl;
//	system("pause");
//}


//#include<iostream>
//using namespace std;
//char* DeleteRepeatCharacters(char* str)
//{
//	if (str == NULL)
//		return NULL;
//	const int hashsize = 256;
//	bool hashtable[hashsize];
//	for (int i = 0; i<hashsize; i++)
//		hashtable[i] = false;
//	char* fast = str;
//	char* slow = str;
//	while (*fast != '\0')
//	{
//		if (hashtable[*fast] == true)
//		{
//			fast++;
//		}
//		else
//		{
//			hashtable[*fast] = true;
//			*slow = *fast;//只有slow的值被修改
//			slow++;
//			fast++;
//		}
//	}
//	//*slow = '\0';
//	return str;//注意这里返回是str不是返货fast或者是slow
//}

//}
//int main()
//{
//	char str[] = "google";
//	//char *StrResult;
//	int sum = 0;
//	sum = DeleteRepeatCharacters(str);
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}