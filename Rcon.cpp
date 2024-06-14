#include "Head.h"

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
/*
void printUTF8Text(const std::vector<uint8_t>& response) {
    std::string utf8_text;

    // 遍历字节并将UTF-8编码转换为字符串
    for (size_t i = 0; i < response.size();) {
        uint8_t byte = response[i];

        // 根据UTF-8的规则确定字符长度
        size_t char_length = 1;
        if ((byte & 0xC0) == 0xC0) {
            if ((byte & 0xE0) == 0xC0)
                char_length = 2;
            else if ((byte & 0xF0) == 0xE0)
                char_length = 3;
            else if ((byte & 0xF8) == 0xF0)
                char_length = 4;
        }

        // 将字符转换为字符串
        utf8_text += std::string(response.begin() + i, response.begin() + i + char_length);

        // 更新下一个字符的位置
        i += char_length;
    }

    // 输出UTF-8编码的文本
    std::cout << "Server Response (UTF-8): " << utf8_text << std::endl;
}
*/
// 解码UTF-8编码的数据并输出文本
std::string printUTF8Text(const std::vector<uint8_t>& response) {
    std::string utf8_text;

    // 遍历字节并将UTF-8编码转换为字符串
    for (size_t i = 12; i < response.size();) {
        uint8_t byte = response[i];

        // 根据UTF-8的规则确定字符长度
        size_t char_length = 1;
        if ((byte & 0xC0) == 0xC0) {
            if ((byte & 0xE0) == 0xC0)
                char_length = 2;
            else if ((byte & 0xF0) == 0xE0)
                char_length = 3;
            else if ((byte & 0xF8) == 0xF0)
                char_length = 4;
        }

        // 如果字符是可打印的ASCII字符，则添加到UTF-8文本中
        if (byte >= 32 && byte <= 126) {
            utf8_text += std::string(response.begin() + i, response.begin() + i + char_length);
        }

        // 更新下一个字符的位置
        i += char_length;
    }

    // 输出UTF-8编码的文本
    std::cout << "Server Response (UTF-8): " << utf8_text << std::endl;
    return utf8_text;
}