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
	cout << "你想玩猜单词游戏吗？<y/n>  ";
	cin >> play;
	play = tolower(play);
	while (play == 'y') {
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = length + 1;
		cout << "你要猜的单词有" << length << "个字母，现在你一共有" << guesses << "次机会,开始吧！" << endl;
		cout << "你的要猜的单词是：" << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "输入你猜的一个字母: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
				cout << "你已经猜过了" << endl;
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "对不起，这个单词不含这个字母" << endl;
				--guesses;
				badchars += letter;
				char ch;
				cout << "是否需要提示： <y/n>";
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
				cout << "恭喜，这个单词含有字母: " << letter << endl;
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "你所要猜的单词是： " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0) {
					cout << "你猜过： " << badchars << endl;

				}
				cout << "你还有：" << guesses << " 次机会" << endl;
			}
		}
		if (guesses > 0) {
			cout << "恭喜你  猜对了 " << endl;
		}
		else {
			cout << "对不起 ，你要猜的单词是： " << target << endl;
		}

		cout << "是否继续游戏 <y/n>:   ";
		cin >> play;
		play = tolower(play);
	}
	cout << "再见 " << endl;
}
