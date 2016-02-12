#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
int COUNT = 0;
map<string,int> id;
int ID(string s)
{
	if (!id.count(s))
		id[s] = ++COUNT;
	return id[s];
}
int main()
{
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		int m, n;
		ss >> m >> n;
		cout << "String is :" << s << endl;
		for (int i = 0; i < m; i++) {
			getline(cin, s);
			cout << "S:" << s << endl;
			int lastpos = -1;
			for (int j = 0; j < n; j++) {
				int p = s.find(',', lastpos+1);
				if (p == string::npos) p = s.length();
				string tmp = s.substr(lastpos+1, p-lastpos-1);
				cout << tmp << ' ' << ID(tmp) << endl;
				lastpos = p;
			}
		}
	}
	return 0;
}

/**
  * data.in
2 4
12,34,ab,cd
22,34,dd,ee
  */