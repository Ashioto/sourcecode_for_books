/**
 * Source: http://blog.csdn.net/mobius_strip/article/details/27053639
 * 字典树Trie，大数计算
 * 计算Fibonacci数列有一定的模式
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

/* Trie define */
#define nodesize 4000004
#define dictsize 10
typedef struct Node1
{
	int id, flag;
	Node1 *next[dictsize];
} tnode;
tnode dict[nodesize];

class Trie
{
private:
	int size;
	tnode *root;
public:
	Trie() {
		memset(dict, 0, sizeof(dict));
		size = 0;
		root = new_node();
	}
	tnode* new_node() {
		return &dict[size++];
	}
	void insert(char* word, int L, int id) {
		tnode* now = root;
		for (int i = 0; i < L; i++) {
			if (!now->next[word[i]-'0'])
				now->next[word[i]-'0'] = new_node();
			if (!now->flag) {
				now->id = id;
				now->flag = 1;
			}
			now = now->next[word[i]-'0'];
		}
		if (!now->flag) {
			now->id = id;
			now->flag = 1;
		}
	}
	int query(char* word) {
		tnode* now = root;
		int i = 0;
		while (word[i]) {
			if (!now->next[word[i]-'0'])
				return -1;
			now = now->next[word[i]-'0'];
			i++;
		}
		return now->id;
	}
} trie;
/* Trie end */

int F[2][21000];
char FF[42];
int main()
{
	memset(F, 0, sizeof(F));
	F[0][0] = F[1][0] = 1;
	trie.insert((char*)"1", 1, 0);
	int s = 0, l = 1, r, count, p, q;
	for (int i = 2; i < 100000; i++) {
		p = i%2; q = (i+1)%2;
		for (int j = s; j < l; j++)
			F[p][j] = F[p][j] + F[q][j];
		for (int j = s; j < l; j++) {
			if (F[p][j] >= 10) {
				F[p][j]   -= 10;
				F[p][j+1] += 1;
			}
		}
		if (F[p][l]) l++;
		if (l - s > 50) s++;
		r = l-1; count = 0;
		while (r >= 0 && count < 40) {
			FF[count] = F[p][r] + '0';
			r--; count++; 
		}

		trie.insert(FF, count, i);
	}
	int T;
	while (cin >> T) {
		int kase = 0;
		char s[50];
		while (T--) {
			scanf("%s", s);
			printf("Case #%d: %d\n", ++kase, trie.query(s));
		}
	}
	return 0;
}
