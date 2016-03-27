#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using std::string;
const int NUM = 26;
const string wordlist[NUM] = {
	"apiary","beetle","cereal","danger","ensign","florid",
	"garage","health","insult","jackal","keeper","loaner","manage",
	"nonce","onset","plaid","quilt","remote","stolid","train","useful",
	"valid","whence","xenon","yearn","zippy"
};
int main() {
	using namespace std;
	srand(time(0));
	char play;
	cout << "������µ�����Ϸ��<y/n>  ";
	cin >> play;
	play = tolower(play);
	while (play == 'y') {
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = length + 1;
		cout << "��Ҫ�µĵ�����" << length << "����ĸ��������һ����" << guesses << "�λ���,��ʼ�ɣ�" << endl;
		cout << "���Ҫ�µĵ����ǣ�" << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "������µ�һ����ĸ: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
				cout << "���Ѿ��¹���" << endl;
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "�Բ���������ʲ��������ĸ" << endl;
				--guesses;
				badchars += letter;
				char ch;
				cout << "�Ƿ���Ҫ��ʾ�� <y/n>";
				cin >> ch;
				ch = tolower(ch);
				if (ch == 'y') {
					for (int i = 0; i < length; i++) {
						if (attempt[i] != target[i]) {
							attempt[i] = target[i];
							int k = target.find(target[i], i + 1);
							while (k != string::npos) {
								attempt[k] = target[k];
								k = target.find(target[k], k + 1);
								--guesses;
							}
							break;
						}
					}
				}
			}
			else {
				cout << "��ϲ��������ʺ�����ĸ: " << letter << endl;
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "����Ҫ�µĵ����ǣ� " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0) {
					cout << "��¹��� " << badchars << endl;

				}
				cout << "�㻹�У�" << guesses << " �λ���" << endl;
			}
		}
		if (guesses > 0) {
			cout << "��ϲ��  �¶��� " << endl;
		}
		else {
			cout << "�Բ��� ����Ҫ�µĵ����ǣ� " << target << endl;
		}

		cout << "�Ƿ������Ϸ <y/n>:   ";
		cin >> play;
		play = tolower(play);
	}
	cout << "�ټ� " << endl;
}
