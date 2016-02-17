//防止{}的情况，对应着解析函数中的break
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
// {a:12,b:22,c:32}
void pharse(map<string,string>& m, string s) 
{
	m.clear();
	string tmp;
	int lastpos = 0, p;
	while (lastpos+1 != s.length()) {
		p = s.find(',', lastpos+1);
		if (p == s.npos) p = s.length() - 1;
		tmp = s.substr(lastpos+1, p-lastpos-1);
		// cout << tmp << endl;
		int c = tmp.find(':');
		if (c==s.npos) break;  
		m[tmp.substr(0,c)] = tmp.substr(c+1);
		// cout << tmp.substr(0,c) << ' ' << tmp.substr(c+1) << endl;
		lastpos = p;
	}
}
void print(set<string>& s)
{
	bool first = true;
	for (set<string>::iterator it=s.begin(); it!=s.end(); it++) {
		if (first) first = false;
		else cout << ',';
		cout << *it;
	}
	cout << endl;
}
int main()
{
	bool is_change;
	map<string,string> x1, x2;
	set<string> ans;
	string s;
	// pharse(x1, "{a:12,b:22,c:32}");
	int T;
	cin >> T;
	while (T--) {
		is_change = false;
		cin >> s;
		pharse(x1, s);
		cin >> s;
		pharse(x2, s);
		// +
		ans.clear();
		for (map<string,string>::iterator it=x2.begin(); it!=x2.end(); it++) {
			if (!x1.count(it->first)) ans.insert(it->first);
		}
		if (ans.size()) {cout << '+'; print(ans); is_change = true;}
		// -
		ans.clear();
		set<string> ans2;
		ans2.clear();
		for (map<string,string>::iterator it=x1.begin(); it!=x1.end(); it++) {
			string key = it->first;
			if (!x2.count(key)) ans.insert(key);
			else if (x1[key] != x2[key]) ans2.insert(key);
		}
		if (ans.size()) {cout << '-'; print(ans); is_change = true;}
		if (ans2.size()) {cout << '*'; print(ans2); is_change = true;}
		if (!is_change) cout << "No changes\n";
		cout << endl;
	}
	return 0;
}
