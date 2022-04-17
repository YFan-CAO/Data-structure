#include<bits/stdc++.h>

const int N = 1e3 + 10;
int next[N], f[N];
int main() {
	std::string a, b;
	while (std::cin >> b >> a) {
		int n = a.length(), m = b.length();
		a = " " + a; b = " " + b;
		for (int i = 2, j = 0; i <= n; i++) {
			while (j > 0 && a[i] != a[i + 1]) j = next[j];
			if (a[i] == a[j + 1]) j++;
			next[i] = j;
		}
		int ans = 0;
		for (int i = 1, j = 0; i <= m; i++) {
			while (j > 0 && (j == n || b[i] != a[j + 1])) j = next[j];
			if (b[i] == a[j + 1]) j++;
			f[i] = j;
			if (f[i] == n) ans = i;
		}
		if (ans != 0) std::cout << ans - n + 1 << std::endl;
		else std::cout << ans << std::endl;
	}
}

