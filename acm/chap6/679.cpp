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

/* TLE */
/*
const int maxn = 20;
int s[1<<maxn];
int main()
{
	int D, I;
	while (scanf("%d %d", &D, &I) == 2) {
		memset(s, 0, sizeof(s));
		int n = (1<<D) - 1, k;
		for (int i = 0; i < I; i++) {
			k = 1;
			while (true) {
				// cout << "i,k :" << i << ',' << k << endl;
				s[k] = !s[k];
				k = s[k] ? 2*k : 2*k+1;
				if (k > n)
					break;
			}
		}
		printf("%d\n", k/2);
	}
	return 0;
}
*/
int main()
{
	int D, I;
	while (scanf("%d %d", &D, &I) == 2) {
		int k = 1;
		for (int i = 0; i < D-1; i++) {
			if (I%2) {k = k*2; I = (I+1)/2;}
			else {k = k*2+1; I = I / 2;}
		}
		printf("%d\n", k);
	}
	return 0;
}