#include "Head.h"
using json = nlohmann::json;

void ShowServerMenu() {
	using namespace std;
	system("cls");//���һ�·�����ʾ
	cout << "--------------------------------------" << endl;
	cout << "              1.���ӷ�����RCON              " << endl;
	cout << "              2.�������ӣ������ú�������Ϣ��              " << endl;
	cout << "              3.����������浵              " << endl;
	cout << "              4.����������              " << endl;
	cout << "              5.���ط���������              " << endl;
	cout << "              6.���ط�����LUA�ļ�             " << endl;
	cout << "              7.��������������              " << endl;
	cout << "              8.����ȫ����Ϣ              " << endl;
	cout << "              9.�������Ȩ��              " << endl;
	cout << "--------------------------------------" << endl;
	int temp;
	cout << "ѡ�����" << endl;
	cin >> temp;
}//����IP��Ϣ��д��json�ļ�
std::string SetupRcon(std::string server_ip, std::string server_rcon_port, std::string server_rcon_password) {
	std::string filename = "server_config.json"; // json �ļ�������
	std::string key, value;
	std::cout << "�����������IP��ַ:\n";
	getline(std::cin, server_ip); // ʹ��getline����ȡ��������

	std::cout << "�����������RCON�˿�:\n";
	getline(std::cin, server_rcon_port); // ͬ��

	std::cout << "�����������RCON����:\n";
	getline(std::cin, server_rcon_password); // ͬ��
	json j; // ����һ�� json ����
	j["Server IP"] = server_ip;
	j["RCON Port"] = server_rcon_port;
	j["RCON Password"] = server_rcon_password;

	// ���ļ�����д�룬����ļ�������ضϣ������ԭ�����ݣ�
	std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
	if (outfile.is_open()) {
		// ʹ�� json::dump �� json ����ת��Ϊ�ַ�������д���ļ�
		outfile << j.dump(4); // �ڶ��������������õ�������������4���ո�
		outfile.close();
		std::cout << "�����������ѱ��浽 " << filename << std::endl;
	}
	else {
		std::cerr << "�޷����ļ� " << filename << std::endl;
	}

	// ���������ع������ַ���
	return j.dump(4);
}
std::string SignInRcon() {
	std::string filename = "server_config.json"; // JSON �ļ�������
	std::ifstream infile(filename); // ʹ�� ifstream ���ļ�
	std::string rcon_info;

	if (infile.is_open()) {
		// ��ȡ�����ļ����ݵ�һ���ַ���
		std::string file_content((std::istreambuf_iterator<char>(infile)),
			(std::istreambuf_iterator<char>()));
		infile.close();

		// ���ַ�������Ϊ json ����
		json j = json::parse(file_content);

		// ��ȡ RCON ������Ϣ
		std::string server_ip = j["Server IP"];
		std::string server_rcon_port = j["RCON Port"];
		std::string server_rcon_password = j["	RCON Password"];

		// �������ص� RCON ������Ϣ�ַ���
		rcon_info = "Server IP: " + server_ip + "\n";
		rcon_info += "RCON Port: " + server_rcon_port + "\n";
		rcon_info += "RCON Password: " + server_rcon_password + "\n";
	}
	else {
		std::cerr << "�޷����ļ� " << filename << std::endl;
		rcon_info = "Error: Unable to read the configuration file.";
	}

	return rcon_info;
}
std::string SAVE() {
	return "save";
}