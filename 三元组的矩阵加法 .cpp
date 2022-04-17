#include<bits/stdc++.h>
using namespace std;
int main() {
	map<pair<int, int>, int> a;
	for (int m, n, x, y, val; (!m ? scanf("%d%d", &m, &n) : 1), cin >> x >> y >> val; !(a[make_pair(x, y)] += val) ? a.erase(make_pair(x, y)) : 1);
	for (map<pair<int, int>, int>::iterator it = a.begin(); (!a.size() ? printf("-1 -1 -1") : 1) && it != a.end(); it++) if (it->second) cout << it->first.first << " " << it->first.second << " " << it->second << endl;
}