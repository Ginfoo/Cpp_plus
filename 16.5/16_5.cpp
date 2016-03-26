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
//个人理解： 智能指针在被创建时不是通过new方法 所以会被自动回收，而回收的时候会执行其析构函数，析构函数内含有delete 方法