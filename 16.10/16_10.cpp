#include<iostream>
#include<iterator>
#include <vector>
using namespace std;
int main() {
	for (int i = 0; i < 4; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 4; ++i) {
		cout << i << " ";
	}

}