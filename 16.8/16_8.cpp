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
	cout << "按任意键执行程序" << endl;
	fill(books);
	show(books);
	cout << "选择你想执行的操作 1：继续添加  2：删除内容 " << endl;
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
	cout << "请输入书名： ";
	getline(cin, rr.title);
	if (rr.title.length() == 0) { f = false; }
	else {
		cout << "输入书本的评级： ";
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
		cout << "你输入的内容为： " << endl;
		cout << setw(6) << left << "序号" << setw(30) << left << "书名 " << setw(3) << right << "评级" << endl;
		for (auto & x : books) {
			cout << setw(6) << left << i++;
			showReview(x);
		}
	}
}
void del(vector<Review>& books) {
	cout << "请输入你要删除的序号：  " << endl;
	vector<int> c;
	int a;
	cin >> a;
	if (a > 0 && a < books.size())
		books.erase(books.begin() + a - 1, books.begin() + a);



}