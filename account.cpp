#include "Head.h"
void ShowAccountMenu()
{
	using namespace std;
	system("cls");//清空一下方便显示
	cout << "--------------------------------------" << endl;

	cout << "              1.创建白名单账号              " << endl;

	cout << "              2.添加白名单账号              " << endl;

	cout << "              3.移除白名单账号              " << endl;

	cout << "              4.封禁账号                    " << endl;

	cout << "              5.修改账号权限                    " << endl;

	cout << "--------------------------------------" << endl;
	int temp;
	cout << "选择操作" << endl;
	cin >> temp;
}



std::string CreatAccount(std::string username,std::string password)
{
	std::string temp;
	int size_;
	size_ = username.size();
	if ((int)size_>10)
	{
		std::cout << "User name ??? long\n";
		return NULL;
	}





	return temp;
}