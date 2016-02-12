/**
 * 这道题做的挺差
 * 原因应该是对二维数组的使用比较混乱
 * http://blog.csdn.net/u014004096/article/details/41490339
 * 一、明确二维数组每一维度是什么
 * 二、如果可以在一个循环里做的事情不要放在后面做
 */
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;

void print(string& s, int n)
{
	int blank_n = n - s.length();
	cout << s ;
	for (int i = 0; i < blank_n; i++)
		cout << " ";
}
vector<string> v[1010];
int word_length[40];
int main()
{
	memset(word_length, 0, sizeof(word_length));
	string s;
	int n = 0;
	int max_n = 0;
	while (getline(cin, s)) {
		stringstream ss(s);
		string tmp;
		while (ss >> tmp)
			v[n].push_back(tmp);
		if (v[n].size() > max_n)
			max_n = v[n].size();
		// cout << v[n].size() <<((int)v[n].size()>-1)<<(v[n].size()>0)<< endl;
		n++;
		// cout << tmp << ',' << s << endl;
	}
	// cout << v[0][0] << ' ' << v[0][1] << endl;
	// cout << max_n << endl;
	int i, j;
	int k = 0;
	for (i = 0; i < max_n; i++) { // for each word
		for (j = 0; j < n; j++) {  // for each line
			if (v[j].size() > i) {
				if (v[j][i].length() > word_length[i])
					word_length[i] = v[j][i].length();
				// cout << "l:" << v[j][i].length() << v[j][i] <<endl;
			}
		}
	}
	// for (i = 0; i < 10; i++)
	// 	cout << word_length[i] << ' ';
	for (i = 0; i < n; i++) {
		for (j = 0; j < v[i].size()-1; j++)
			print(v[i][j], word_length[j]+1);
		cout << v[i][j] << endl;
	}
	return 0;
}
