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

bool solve(int& W)
{
	int W1, D1, W2, D2;
	cin >> W1 >> D1 >> W2 >> D2;
	bool b1 = true, b2 = true; // key point
	if (!W1) b1 = solve(W1);
	if (!W2) b2 = solve(W2);
	W = W1 + W2;
	return b1 && b2 && (W1*D1 == W2*D2);
}

int main()
{
	int T, W;
	cin >> T;
	while (T--) {
		if (solve(W))
			cout << "YES\n"; 
		else cout << "NO\n";
		if (T)
			cout << "\n";
	}
	return 0;
}