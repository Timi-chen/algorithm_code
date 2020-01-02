#include "stdafx.h"
#include<iostream>
using namespace std;
class Queen {
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(int t);
	int n,     //皇后个数
		*x;    //当前解
	long sum;  //当前已找到的可行方案数
};
bool Queen::Place(int k) {
	for (int j = 1; j < k; j++)
		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
			return false;
	return true;
}
void Queen::Backtrack(int t) {
	if (t > n) {
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		    cout << endl;
		    sum++;
	}
	else {
		for (int i = 1; i <= n; i++) {
			x[t] = i;
			if (Place(t)) Backtrack(t + 1);
		}
	}
}
int nQueen(int n) {
	Queen X;
	//初始化X
	X.n = n;
	X.sum = 0;
	int* p = new int[n + 1];
	for (int i = 0; i <= n; i++)
		p[i] = 0;
	X.x = p;
	X.Backtrack(1);
	delete [] p;
	return X.sum;
}
void main() {
	int n, set;
	cout << "请输入皇后个数："; cin >> n;
	cout << "可行方案所有解：" << endl;
	set = nQueen(n);
	cout << "可行方案数：" << set << endl;
}
————————————————
版权声明：本文为CSDN博主「TPSHION」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/cjq950918/article/details/71514528
