#include "Head.h"
void ShowAccountMenu()
{
	using namespace std;
	system("cls");//���һ�·�����ʾ
	cout << "--------------------------------------" << endl;

	cout << "              1.�����������˺�              " << endl;

	cout << "              2.��Ӱ������˺�              " << endl;

	cout << "              3.�Ƴ��������˺�              " << endl;

	cout << "              4.����˺�                    " << endl;

	cout << "              5.�޸��˺�Ȩ��                    " << endl;

	cout << "--------------------------------------" << endl;
	int temp;
	cout << "ѡ�����" << endl;
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