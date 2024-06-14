#include "Head.h"



/*
std::vector<char> CreateRconPacket(int request_id, int type, const std::string& payload) {
    std::vector<char> packet;
    int length = 10 + payload.size(); // 4 + 4 + payload + 2
    packet.resize(length + 4); // 包括长度字段

    // 长度
    std::memcpy(&packet[0], &length, sizeof(length));

    // 请求 ID
    std::memcpy(&packet[4], &request_id, sizeof(request_id));

    // 类型
    std::memcpy(&packet[8], &type, sizeof(type));

    // 负载
    std::memcpy(&packet[12], payload.c_str(), payload.size());

    // 填充 (2 字节)
    packet[length + 2] = 0x00;
    packet[length + 3] = 0x00;

    return packet;
} //函数原型
*/
int showMainMeun()//显示主菜单
{
    using namespace std;
    system("cls");//清空一下方便显示
    cout << "--------------------------------------" << endl;
    cout << "                主菜单              " << endl;
    cout << "                                  " << endl;
    cout << "              1.软件配置              " << endl;

    cout << "              2.账号操作              " << endl;

    cout << "              3.物品给予              " << endl;

    cout << "              4.特殊事件类                    " << endl;

    cout << "                                  " << endl;

    cout << "--------------------------------------" << endl;
    cout << "选择功能" << endl;
    int temp;
    cin >> temp;
    /*
    switch (temp) 
    {
    case 1:
    case 2:
    case 3:
    case 4:
    }
    */
    return temp;
}


class RconClient {
public:
    RconClient(boost::asio::io_context& io_context, const std::string& host, const std::string& port)
        : socket_(io_context) {
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, port);
        boost::asio::connect(socket_, endpoints);
    }

    void sendPacket(const std::vector<char>& packet) {
        boost::asio::write(socket_, boost::asio::buffer(packet));
    }

    std::vector<uint8_t> receivePacket() {
        std::vector<uint8_t> buffer(4096);
        size_t length = socket_.read_some(boost::asio::buffer(buffer));
        buffer.resize(length);
        return buffer;
    }

private:
    tcp::socket socket_;
};


void Log(std::string LOG)
{
    std::cout <<"[Log]" << LOG << std::endl;
}

int main() {
    
    
    while (true)
    {
        int chose;
        chose = showMainMeun();
        switch (chose)
        {
        case 1:
            std::cout << "选择了软件配置类" << std::endl;
            break;
        case 2:
            ShowAccountMenu();
            break;
        default:
            break;
        }

















    }


    
    return 1;
    //以下为测试代码
    try {
        boost::asio::io_context io_context;

        RconClient client(io_context, "103.91.209.166", "27015");
        auto Packet = CreateRconPacket(1,3,"233");
        client.sendPacket(Packet);
        auto response = client.receivePacket();
        printUTF8Text(response);
        Packet = CreateRconPacket(1, 2, "servermsg 我卢本伟没有开挂");
        client.sendPacket(Packet);
         response = client.receivePacket();
        printUTF8Text(response);
        Packet = CreateRconPacket(1, 2, "players");
        client.sendPacket(Packet);
         response = client.receivePacket();
        printUTF8Text(response);
        client.sendPacket(Packet);
         response = client.receivePacket();
        printUTF8Text(response);
        client.sendPacket(Packet);
         response = client.receivePacket();
        printUTF8Text(response);

    }
    
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    
    return 0;
}

