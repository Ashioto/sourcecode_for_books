/**
 * TLE....
 * 原因不知道为什么，已经修改了一次了，把一个遍历操作的clear改掉了
 * 但是还是超时
 * 不过结果是对的，也算是一次不错的优先队列的练习
 */
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Trade
{
	int size, price, id;
	Trade(int s=-1, int p=-1, int i=-1) {
		size = s;
		price = p;
		id = i;
	}
};

struct buyCmp 
{	
	bool operator() (const Trade &a, const Trade &b) {
		if (a.price != b.price) return a.price < b.price;
		else return a.id > b.id;
	}
};
struct sellCmp
{	
	bool operator() (const Trade &a, const Trade &b) {
		if (a.price != b.price) return a.price > b.price;
		else return a.id > b.id;
	}
};

priority_queue<Trade, vector<Trade>, buyCmp> buy;
priority_queue<Trade, vector<Trade>, sellCmp> sell;
bool flag[10000+10];  //flase:buy  true:sell
bool is_active[10000+10];
void clear(int id)
{
	bool _flag = flag[id];
	vector<Trade> v;
	if (!_flag) {
		// buy
		Trade t = buy.top(); 
		while (t.id!=id && !buy.empty()) {
			v.push_back(t);
			buy.pop();
			t = buy.top();
		}
		if (!buy.empty())
			buy.pop();
		for (int i = 0; i < v.size(); i++) {
			buy.push(v[i]);
		}
	} else {
		// sell
		Trade t = sell.top();
		while (t.id!=id && !sell.empty()) {
			v.push_back(t);
			sell.pop();
			t = sell.top();
		}
		if (!sell.empty())
			sell.pop();
		for (int i = 0; i < v.size(); i++) {
			sell.push(v[i]);
		}
	}
}

void trade(bool flag)
{
	if (buy.empty() || sell.empty())
		return;
	vector<Trade> v;
	Trade b = buy.top(), s = sell.top();
	while (!is_active[b.id] && !buy.empty()) {buy.pop(); b = buy.top();}
	while (!is_active[s.id] && !sell.empty()) {sell.pop(); s = sell.top();}
	while (b.price >= s.price && !buy.empty() && !sell.empty()) {
		buy.pop(); sell.pop();
		if (b.size == s.size) {
			// size price
			v.push_back(Trade(b.size, !flag?min(b.price, s.price):max(b.price, s.price)));
		} else {
			if (b.size < s.size) {
				v.push_back(Trade(b.size, !flag?min(b.price, s.price):max(b.price, s.price)));
				sell.push(Trade(s.size-b.size, s.price, s.id));
			} else {
				v.push_back(Trade(s.size, !flag?min(b.price, s.price):max(b.price, s.price)));
				buy.push(Trade(b.size-s.size, b.price, b.id));
			}
		}
		b = buy.top(); s = sell.top();
		while (!is_active[b.id] && !buy.empty()) {buy.pop(); b = buy.top();}
		while (!is_active[s.id] && !sell.empty()) {sell.pop(); s = sell.top();}
	}
	// process v;
	map<int, int> m;
	for (int i = 0; i < v.size(); i++) {
		Trade t = v[i];
		m[t.price] += t.size;
	}
	// print trade information
	std::map<int,int>::reverse_iterator rit;
	for (rit = m.rbegin(); rit!=m.rend(); rit++) {
		cout << "TRADE " << rit->second << ' ' << rit->first << endl;
	}

}
void quote()
{
	vector<Trade> v;
	Trade bid, ask;
	if (!buy.empty()) {
		Trade b = buy.top();
		while (!is_active[b.id] && !buy.empty()) {buy.pop(); b = buy.top();}
		bid.price = b.price;
		bid.size = 0;
		while (b.price == bid.price && !buy.empty()) {
			buy.pop();
			bid.size += b.size;
			v.push_back(b);
			b = buy.top();
			while (!is_active[b.id] && !buy.empty()) {buy.pop(); b = buy.top();}
		}
		for (int i = 0; i < v.size(); i++)
			buy.push(v[i]);
	}

	if (!sell.empty()) {
		v.clear();
		Trade s = sell.top();
		while (!is_active[s.id] && !sell.empty()) {sell.pop(); s = sell.top();}
		ask.price = s.price;
		ask.size = 0;
		while (s.price == ask.price && !sell.empty()) {
			sell.pop();
			ask.size += s.size;
			v.push_back(s);
			s = sell.top();
			while (!is_active[s.id] && !sell.empty()) {sell.pop(); s = sell.top();}
		}
		for (int i = 0; i < v.size(); i++) 
			sell.push(v[i]);
	}
	if (buy.empty()) {bid.size = 0; bid.price = 0;}
	if (sell.empty()) {ask.size = 0; ask.price = 99999;}
	cout << "QUOTE " << bid.size << ' ' << bid.price << " - " << ask.size << ' ' << ask.price << endl;
}
int main()
{
	int T;
	string s;
	bool first = true;
	while (cin >> T) {
		if (first) first = false;
		else cout << '\n';
		while (!buy.empty()) buy.pop();
		while (!sell.empty()) sell.pop();
		memset(is_active, true, sizeof(is_active));
		int id = 0;
		while (T--) {
			cin >> s;
			if (s == "BUY") {
				int size, price;
				cin >> size >> price;
				buy.push(Trade(size, price, id));
				flag[id] = false;
				trade(flag[id]);
			} else if (s == "SELL") {
				int size, price;
				cin >> size >> price;	
				sell.push(Trade(size, price, id));
				flag[id] = true;
				trade(flag[id]);
			} else if (s == "CANCEL") {
				int num;
				cin >> num; num --;
				// clear(num);
				is_active[num] = false;
			}
			quote();
			id++;
		}
		// cin.get();
	}
}
