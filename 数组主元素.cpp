#include<bits/stdc++.h>
using namespace std;
int main() {
	int n = 0, a[1000] = { 0 }, maxn = 0;
	for (int x; cin >> x, x != 0; ++a[x], n++) maxn = max(x, maxn);
	for (int i = 1, flag = 0; ((i > maxn && !flag) ? puts("-1"), 1 : 1) && i <= maxn; i++) (a[i] > n / 2) ? (printf("%d ", i), flag++) : 1;
}