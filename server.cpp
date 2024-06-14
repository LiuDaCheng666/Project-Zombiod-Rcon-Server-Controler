#include "Head.h"
using json = nlohmann::json;

void ShowServerMenu() {
	using namespace std;
	system("cls");//清空一下方便显示
	cout << "--------------------------------------" << endl;
	cout << "              1.链接服务器RCON              " << endl;
	cout << "              2.登入连接（先配置好链接信息）              " << endl;
	cout << "              3.保存服务器存档              " << endl;
	cout << "              4.重启服务器              " << endl;
	cout << "              5.重载服务器设置              " << endl;
	cout << "              6.重载服务器LUA文件             " << endl;
	cout << "              7.结束服务器运行              " << endl;
	cout << "              8.发送全服消息              " << endl;
	cout << "              9.更改玩家权限              " << endl;
	cout << "--------------------------------------" << endl;
	int temp;
	cout << "选择操作" << endl;
	cin >> temp;
}//读入IP信息并写入json文件
std::string SetupRcon(std::string server_ip, std::string server_rcon_port, std::string server_rcon_password) {
	std::string filename = "server_config.json"; // json 文件的名称
	std::string key, value;
	std::cout << "请输入服务器IP地址:\n";
	getline(std::cin, server_ip); // 使用getline来读取整行输入

	std::cout << "请输入服务器RCON端口:\n";
	getline(std::cin, server_rcon_port); // 同上

	std::cout << "请输入服务器RCON密码:\n";
	getline(std::cin, server_rcon_password); // 同上
	json j; // 创建一个 json 对象
	j["Server IP"] = server_ip;
	j["RCON Port"] = server_rcon_port;
	j["RCON Password"] = server_rcon_password;

	// 打开文件用于写入，如果文件存在则截断（即清空原有内容）
	std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
	if (outfile.is_open()) {
		// 使用 json::dump 将 json 对象转换为字符串，并写入文件
		outfile << j.dump(4); // 第二个参数是美化用的缩进，这里是4个空格
		outfile.close();
		std::cout << "服务器配置已保存到 " << filename << std::endl;
	}
	else {
		std::cerr << "无法打开文件 " << filename << std::endl;
	}

	// 构建并返回构建的字符串
	return j.dump(4);
}
std::string SignInRcon() {
	std::string filename = "server_config.json"; // JSON 文件的名称
	std::ifstream infile(filename); // 使用 ifstream 打开文件
	std::string rcon_info;

	if (infile.is_open()) {
		// 读取整个文件内容到一个字符串
		std::string file_content((std::istreambuf_iterator<char>(infile)),
			(std::istreambuf_iterator<char>()));
		infile.close();

		// 将字符串解析为 json 对象
		json j = json::parse(file_content);

		// 提取 RCON 配置信息
		std::string server_ip = j["Server IP"];
		std::string server_rcon_port = j["RCON Port"];
		std::string server_rcon_password = j["	RCON Password"];

		// 构建返回的 RCON 配置信息字符串
		rcon_info = "Server IP: " + server_ip + "\n";
		rcon_info += "RCON Port: " + server_rcon_port + "\n";
		rcon_info += "RCON Password: " + server_rcon_password + "\n";
	}
	else {
		std::cerr << "无法打开文件 " << filename << std::endl;
		rcon_info = "Error: Unable to read the configuration file.";
	}

	return rcon_info;
}
std::string SAVE() {
	return "save";
}