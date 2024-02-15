#include<iostream>
using namespace std;

struct kStacks {
	int* arr, * next, * top;
	int k, freeTop, cap;
	kStacks(int n, int k) {
		this->k = k;
		cap = n;
		arr = new int[cap];
		next = new int[cap];
		top = new int[k];
		for (int i = 0; i < k; i++)
			top[i] = -1;
		freeTop = 0;
		for (int i = 0; i < cap - 1; i++)
			next[i] = i + 1;
		next[cap - 1] = -1;
	}
	void push(int sn, int x) {
		int i = freeTop;
		arr[i] = x;
		freeTop = next[i];
		next[i] = top[sn];
		top[sn] = i;
	}
	int pop(int sn) {
		int i = top[sn];
		top[sn] = next[i];
		next[i] = freeTop;
		freeTop = i;
		return arr[i];
	}
};

int main() {
	kStacks ks(5,2);
	ks.push(1, 11);
	ks.push(1, 12);
	ks.push(1, 13);
	ks.push(0, 21);
	ks.push(0, 22);
	cout << ks.pop(1) << "\n";
	cout << ks.pop(1) << "\n";
	cout << ks.pop(1) << "\n";
	cout << ks.pop(0) << "\n";
	cout << ks.pop(0) << "\n";
	return 0;
}