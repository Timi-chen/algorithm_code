#include "stdafx.h"
#include<iostream>
using namespace std;
class Queen {
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(int t);
	int n,     //�ʺ����
		*x;    //��ǰ��
	long sum;  //��ǰ���ҵ��Ŀ��з�����
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
	//��ʼ��X
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
	cout << "������ʺ������"; cin >> n;
	cout << "���з������н⣺" << endl;
	set = nQueen(n);
	cout << "���з�������" << set << endl;
}
��������������������������������
��Ȩ����������ΪCSDN������TPSHION����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/cjq950918/article/details/71514528
