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

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef struct 
{
	int n;
	string lines[1510];
	map<string,set<int> > index;
} Article;
Article articles[102];

void line_to_lower(string& s)
{
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i]))
			s[i] = tolower(s[i]);
		else
			s[i] = ' ';
	}
}
void update_index(int M)
{
	int i, j, k;
	string s;
	for (i = 0; i < M; i++) {
		for (j = 0; j < articles[i].n; j++) {
			//each article, each line
			s = articles[i].lines[j];
			line_to_lower(s);
			stringstream ss(s);
			string word;
			while (ss >> word) {
				articles[i].index[word].insert(j);
			}
		}
	}
}
void print_whole_article(Article& art)
{
	for (int i = 0; i < art.n; i++) {
		cout << art.lines[i] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	// freopen("in_1.txt","w",stdout);
	int M, N;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> M;
	int i, j, k = 0;
	for (i = 0; i < M; i++) {
		while (getline(cin,s) && s != "**********") {
			articles[i].lines[k++] = s;
		}
		articles[i].n = k;
		k = 0;
	}

	update_index(M);
	// set<int> test = articles[0].index["media"];
	// cout << *test.begin() ;

	getline(cin, s);
	stringstream sss(s);
	sss >> N;
	int p;
	string keyword;
	while (N--) {
		getline(cin, s);
		bool is_found = false;
		if (s[0] == 'N') {
			bool N_first = true;
			keyword = s.substr(4,s.length()-4);  //NOT(space)XXX
			for (i = 0; i < M; i++) {
				if (!articles[i].index[keyword].size()) {
					if (N_first) N_first = false;
					else cout << "----------" << endl;
					is_found = true;
					print_whole_article(articles[i]);
				}
			}
		} else if (s.find("AND") != string::npos) {
			p = s.find(" AND ");
			string _stringA = s.substr(0, p);
			string _stringB = s.substr(p+5, s.length()-p-5);
			bool AND_first = true;
			for (i = 0; i < M; i++) {
				if (articles[i].index[_stringA].size() && articles[i].index[_stringB].size()) {
					if (AND_first) AND_first = false;
					else cout << "----------" << endl;
					is_found = true;
					set<int> _x1 = articles[i].index[_stringA];
					set<int> _x2 = articles[i].index[_stringB];
					set<int> _x;
					set_union(ALL(_x1), ALL(_x2), INS(_x));
					for (set<int>::iterator it=_x.begin(); it!=_x.end(); it++) {
						cout << articles[i].lines[*it] << endl;
					}
				}
			}
		} else if (s.find("OR") != string::npos) {
			p = s.find(" OR ");
			string _stringA = s.substr(0, p);
			string _stringB = s.substr(p+4, s.length()-p-4);
			bool OR_first = true;
			for (i = 0; i < M; i++) {
				if (articles[i].index[_stringA].size() || articles[i].index[_stringB].size()) {
					if (OR_first) OR_first = false;
					else cout << "----------" << endl;
					set<int> _x1 = articles[i].index[_stringA];
					set<int> _x2 = articles[i].index[_stringB];
					set<int> _x;
					set_union(ALL(_x1), ALL(_x2), INS(_x));
					for (set<int>::iterator it=_x.begin(); it!=_x.end(); it++) {
						cout << articles[i].lines[*it] << endl;
						is_found = true;
					}
				}
			}
		} else {
			bool ELSE_first = true;
			for (i = 0; i < M; i++) {
				if (articles[i].index[s].size()) {
					if (ELSE_first) ELSE_first = false;
					else cout << "----------" << endl;
					set<int> x = articles[i].index[s];
					for (set<int>::iterator it = x.begin(); it!=x.end(); it++) {
						cout << articles[i].lines[*it] << endl;
						is_found = true;
					}
				}
			}
		}

		if (!is_found)
			cout << "Sorry, I found nothing." << endl;
		cout << "==========" << endl;
	}

	return 0;
}