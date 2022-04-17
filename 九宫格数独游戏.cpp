#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N][N];
//	��				��				�Ź��� �� 1 - 9�Ƿ���� 
bool vis1[10][10], vis2[10][10], vis3[10][10];

//���� 
void dfs(int i, int j) {
	//���� 
	if (i > 9) {
		//��ӡ 
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	//a[i][j] �Ƿ�ȷ�� 
	if (!a[i][j])
		for (int k = 1, pos = ((i - 1) / 3) * 3 + (j - 1) / 3 + 1; k <= 9; k++) {
			//����Ҫ��ֵ���������� 
			if (!vis1[i][k] && !vis2[j][k] && !vis3[pos][k]) {
				a[i][j] = k;
				vis1[i][k] = vis2[j][k] = vis3[pos][k] = 1;
				//���� 
				if (j <= 8) dfs(i, j + 1);
				else dfs(i + 1, 1);
				//���� 
				a[i][j] = 0;
				vis1[i][k] = vis2[j][k] = vis3[pos][k] = 0;
			}
		}
	else {
		if (j <= 8) dfs(i, j + 1);
		else dfs(i + 1, 1);
	}
}

int main() {
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			//���Ԫ���Ƿ���� 
			vis1[i][a[i][j]] = vis2[j][a[i][j]] = vis3[((i - 1) / 3) * 3 + (j - 1) / 3 + 1][a[i][j]] = 1;
		}
	dfs(1, 1);
}