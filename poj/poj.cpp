// poj.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<iostream>
#include<algorithm>

using namespace std;

int maxLength(int a[100][100], int r, int c, int m, int n) {
	if (r == 1) {
		if (c == 1)
			return 1;
		else {
			if (n == 0) {
				if (a[m][n + 1] > a[m][n])
					return 0;
			}
			if (n == c - 1) {
				if (a[m][n - 1] > a[m][n])
					return 0;
			}
			return 1 + max(maxLength(a, r, c, m, n - 1), maxLength(a, r, c, m, n + 1));
		}
	}
	else {
		if (c == 1) {
			if (m == 0) {
				if (a[m + 1][n] > a[m][n])
					return 0;
			}
			if (m == r - 1) {
				if (a[m - 1][n] > a[m][n])
					return 0;
			}
			return 1 + max(maxLength(a, r, c, m - 1, n), maxLength(a, r, c, m + 1, n));
		}
		else {
			if (m == r - 1) {
				if (n == c - 1) {
					int u = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
					int l = a[m][n - 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n - 1) : 0;
					return max(u, l);
				}
				else {
					if (n == 0) {
						int u = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
						int _r = a[m][n + 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n + 1) : 0;
						return max(u, _r);
					}
					else {
						int u = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
						int _r = a[m][n + 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n + 1) : 0;
						int l = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
						return max(u, max(l, _r));
					}
				}
			}
			else {
				if (m == 0) {
					if (n == c - 1) {
						int d = a[m + 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m + 1, n) : 0;
						int l = a[m][n - 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n - 1) : 0;
						return max(d, l);
					}
					else {
						if (n == 0) {
							int d = a[m + 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m + 1, n) : 0;
							int _r = a[m][n + 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n + 1) : 0;
							return max(d, _r);
						}
						else {
							int _r = a[m][n + 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n + 1) : 0;
							int l = a[m][n - 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n - 1) : 0;
							int d = a[m + 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m + 1, n) : 0;
							return max(_r, max(l, d));
						}
					}
				}
				else {
					if (n == c - 1) {
						int u = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
						int d = a[m + 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m + 1, n) : 0;
						int l = a[m][n - 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n - 1) : 0;
						return max(u, max(d, l));
					}
					else {
						if (n == 0) {
							int d = a[m + 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m + 1, n) : 0;
							int u = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
							int l = a[m][n - 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n - 1) : 0;
							return max(d, max(u, l));
						}
						else {
							int u = a[m - 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m - 1, n) : 0;
							int l = a[m][n - 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n - 1) : 0;
							int _r = a[m][n + 1] < a[m][n] ? 1 + maxLength(a, r, c, m, n + 1) : 0;
							int d = a[m + 1][n] < a[m][n] ? 1 + maxLength(a, r, c, m + 1, n) : 0;
							return max(max(_r, u), max(l, d));
						}
					}

				}
			}
		}
	}
}

int main() {
	int r, c;
	cin >> r >> c;
	int map[100][100];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];
	int result = 0;
	for (int i = 0; i<r; i++)
		for (int j = 0; j < c; j++) {
			result = max(result, 1 + maxLength(map, r, c, i, j));
		}
	cout << result << endl;
	return 0;
}
