#include<iostream>
#include<string>
#include<memory>
class Report {
private:
	std::string str;
public:
	Report(const std::string s) :str(s) {
		std::cout << "Objected created!\n";
	}
	~Report() { std::cout << "Objected delete\n"; }
	void comment() const { std::cout << str << "\n"; }
};
int main() {
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
	    ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
}
//������⣺ ����ָ���ڱ�����ʱ����ͨ��new���� ���Իᱻ�Զ����գ������յ�ʱ���ִ�����������������������ں���delete ����