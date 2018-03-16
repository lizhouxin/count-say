//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//void HeapAjust(vector<int> &vec,int num,int length)
//{
//	int temp,j;
//	temp = vec[num];
//	for (j = 2 * num; j <= length; j *= 2)
//	{
//		if (j < length && vec[j] < vec[j + 1])
//			j = j + 1;
//		if (vec[num] >= vec[j])
//			break;
//		vec[num] = vec[j];
//		num = j;
//		vec[num] = temp;
//	}
//	
//}
//int main()
//{
//	vector<int> inVec;
//	int m;
//	inVec.push_back(0);
//	do
//	{
//		cin >> m;
//		inVec.push_back(m);
//	} while (cin.get() != '\n');
//
//	//´î½¨´ó¶¥ÍÆ
//	int length = inVec.size() - 1;
//	for (int i = length / 2; i > 0; i--)
//	{
//		HeapAjust(inVec, i, length);
//	}
//
//	for (int i = length; i > 1; i--)
//	{
//		swap(inVec[1], inVec[i]);
//		HeapAjust(inVec, 1, i - 1);
//	}
//	for(int i = 1;i <= length;i++)
//	cout << inVec[i] << " ";
//	system("pause");
//}