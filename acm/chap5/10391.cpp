/**
 * 复合词
 * 此题需要换个思路，可以由A+B=C中的A和B考虑，也可以由C考虑
 * 本题由C考虑比较好，时间复杂度大概为O（n）
 */
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
set<string> dict;
void process(string& s)
{
	int len = s.length();
	for (int i = 1; i <= len; i++) {
		string stringA = s.substr(0,i);
		string stringB = s.substr(i,len-i);
		// cout << stringA << " " << stringB << '\n';
		if (dict.count(stringA) && dict.count(stringB)) {
			cout << s << endl;
			return;
		}
	}
}
int main()
{
	string s;
	while (cin >> s) 
		dict.insert(s);
	for (set<string>::iterator it=dict.begin(); it!=dict.end(); it++) {
		s = *it;
		process(s);
	}
	return 0;

}
