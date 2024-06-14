
/*
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
tcp::socket Mysocket;


void send_rcon_command(boost::asio::io_context& io_context, const std::string& host, const std::string& port, const std::string& password, const std::string& command) {
    try {
        // Resolve the host name and port number
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(host, port);

        // Create and connect the socket
        tcp::socket socket(io_context);
        
        boost::asio::connect(socket, endpoints);

        auto create_rcon_packet = [](int request_id, int type, const std::string& payload) {
            std::vector<char> packet;
            int length = 10 + payload.size(); // 4 + 4 + payload + 2
            packet.resize(length + 4); // include length field

            // Length
            std::memcpy(&packet[0], &length, sizeof(length));

            // Request ID
            std::memcpy(&packet[4], &request_id, sizeof(request_id));

            // Type
            std::memcpy(&packet[8], &type, sizeof(type));

            // Payload
            std::memcpy(&packet[12], payload.c_str(), payload.size());

            // Padding (2 bytes)
            packet[length + 2] = 0x00;
            packet[length + 3] = 0x00;

            return packet;
            };

        // Send login packet
        auto login_packet = create_rcon_packet(1, 3, password);
        boost::asio::write(socket, boost::asio::buffer(login_packet));

        // Read response
        std::vector<char> response(1024);
        size_t len = socket.read_some(boost::asio::buffer(response));
        std::cout.write(response.data(), len);

        // Send command packet
        auto command_packet = create_rcon_packet(2, 2, command);
        boost::asio::write(socket, boost::asio::buffer(command_packet));

        // Read response
        len = socket.read_some(boost::asio::buffer(response));
        std::cout.write(response.data(), len);

    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}



void SendCommand(boost::asio::io_context& io_context, tcp::socket& socket, const std::string& command) {
    try {
        auto create_rcon_packet = [](int request_id, int type, const std::string& payload) {
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
            };

        // 发送命令数据包
        auto command_packet = create_rcon_packet(2, 2, command);
        boost::asio::write(socket, boost::asio::buffer(command_packet));

        // 读取响应
        std::vector<char> response(1024);
        size_t len = socket.read_some(boost::asio::buffer(response));
        std::cout.write(response.data(), len);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

int main() {
    boost::asio::io_context io_context;
    std::string host = "103.91.209.166";
    std::string port = "27015";
    std::string password = "233";
    std::string command = "status";

    send_rcon_command(io_context, host, port, password, command);
    //SendCommand(io_context, host, port, password, command);
    return 0;
}
*/