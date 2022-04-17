#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 12500
typedef int ElementType;
typedef struct {
	int row, col;
	ElementType e;
}Triple;

struct TSMatrix {
	Triple data[MAXSIZE + 1];
	int m, n, len;
	TSMatrix() {
		m = 0;
		n = 0;
		len = 0;
	}
};

void FastTransPoseTSMatrix(TSMatrix A, TSMatrix* B) {
	int col, t, p, q;
	int num[MAXSIZE], position[MAXSIZE];
	B->len = A.len; B->n = A.m; B->m = A.n;
	if (B->len) {
		for (col = 1; col <= A.n; col++) {
			num[col] = 0;
		}
		for (t = 1; t <= A.len; t++) {
			num[A.data[t].col] ++;
		}
		position[1] = 1;
		for (col = 2; col <= A.n; col++) {
			position[col] = position[col - 1] + num[col - 1];
		}
		for (p = 1; p <= A.len; p++) {
			col = A.data[p].col;
			q = position[col];
			//			cout << q << " " << A.data[p].e << endl;
			B->data[q].row = A.data[p].col;
			B->data[q].col = A.data[p].row;
			B->data[q].e = A.data[p].e;
			position[col] ++;
		}
	}
	return;
}
int main() {
	TSMatrix A, B;
	int n, m;
	cin >> n >> m;
	int k = 0;
	A.m = m; A.n = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				A.data[++k].e = tmp;
				A.data[k].row = i;
				A.data[k].col = j;
				A.len++;
			}
		}
	}
	FastTransPoseTSMatrix(A, &B);
	int pos = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (B.data[pos].col == j && B.data[pos].row == i) {
				cout << B.data[pos].e << " ";
				pos++;
			}
			else cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
}