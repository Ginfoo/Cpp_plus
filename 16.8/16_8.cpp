#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
using namespace std;
struct Review {
	string title;
	int rating;
};
bool fillReview(Review& rr);
void showReview(const Review& rr);
void show(vector<Review>& books);
void fill(vector<Review>& books);
void del(vector<Review>& books);
int main() {
	vector<Review> books;
	cout << "�������ִ�г���" << endl;
	fill(books);
	show(books);
	cout << "ѡ������ִ�еĲ��� 1���������  2��ɾ������ " << endl;
	int fo;
	cin >> fo;
	switch (fo)
	{
	case 1: {fill(books); break; }
	case 2: {del(books); break;
	}

	default:
		break;
	}
	show(books);
}
bool fillReview(Review& rr) {
	bool f = true;
	cout << "������������ ";
	getline(cin, rr.title);
	if (rr.title.length() == 0) { f = false; }
	else {
		cout << "�����鱾�������� ";
		cin >> rr.rating;
		if (!cin) {
			f = false;
		}

	}

	while (cin.get() != '\n') continue;
	return f;
}
void showReview(const Review& rr) {
	cout << setw(30) << left << rr.title << setw(5) << right << rr.rating << endl;
}
void fill(vector<Review>& books) {
	Review temp;
	while (cin.get() != '\n') continue;
	while (fillReview(temp)) books.push_back(temp);
	
}
void show(vector<Review>& books) {
	int num = books.size();
	if (num > 0) {
		int i = 1;
		cout << "�����������Ϊ�� " << endl;
		cout << setw(6) << left << "���" << setw(30) << left << "���� " << setw(3) << right << "����" << endl;
		for (auto & x : books) {
			cout << setw(6) << left << i++;
			showReview(x);
		}
	}
}
void del(vector<Review>& books) {
	cout << "��������Ҫɾ������ţ�  " << endl;
	vector<int> c;
	int a;
	cin >> a;
	if (a > 0 && a < books.size())
		books.erase(books.begin() + a - 1, books.begin() + a);



}