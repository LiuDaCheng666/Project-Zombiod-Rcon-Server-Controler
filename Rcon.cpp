#include "Head.h"

std::vector<char> CreateRconPacket(int request_id, int type, const std::string& payload) {
    std::vector<char> packet;
    int length = 10 + payload.size(); // 4 + 4 + payload + 2
    packet.resize(length + 4); // ���������ֶ�

    // ����
    std::memcpy(&packet[0], &length, sizeof(length));

    // ���� ID
    std::memcpy(&packet[4], &request_id, sizeof(request_id));

    // ����
    std::memcpy(&packet[8], &type, sizeof(type));

    // ����
    std::memcpy(&packet[12], payload.c_str(), payload.size());

    // ��� (2 �ֽ�)
    packet[length + 2] = 0x00;
    packet[length + 3] = 0x00;

    return packet;
} //����ԭ��
/*
void printUTF8Text(const std::vector<uint8_t>& response) {
    std::string utf8_text;

    // �����ֽڲ���UTF-8����ת��Ϊ�ַ���
    for (size_t i = 0; i < response.size();) {
        uint8_t byte = response[i];

        // ����UTF-8�Ĺ���ȷ���ַ�����
        size_t char_length = 1;
        if ((byte & 0xC0) == 0xC0) {
            if ((byte & 0xE0) == 0xC0)
                char_length = 2;
            else if ((byte & 0xF0) == 0xE0)
                char_length = 3;
            else if ((byte & 0xF8) == 0xF0)
                char_length = 4;
        }

        // ���ַ�ת��Ϊ�ַ���
        utf8_text += std::string(response.begin() + i, response.begin() + i + char_length);

        // ������һ���ַ���λ��
        i += char_length;
    }

    // ���UTF-8������ı�
    std::cout << "Server Response (UTF-8): " << utf8_text << std::endl;
}
*/
// ����UTF-8��������ݲ�����ı�
std::string printUTF8Text(const std::vector<uint8_t>& response) {
    std::string utf8_text;

    // �����ֽڲ���UTF-8����ת��Ϊ�ַ���
    for (size_t i = 12; i < response.size();) {
        uint8_t byte = response[i];

        // ����UTF-8�Ĺ���ȷ���ַ�����
        size_t char_length = 1;
        if ((byte & 0xC0) == 0xC0) {
            if ((byte & 0xE0) == 0xC0)
                char_length = 2;
            else if ((byte & 0xF0) == 0xE0)
                char_length = 3;
            else if ((byte & 0xF8) == 0xF0)
                char_length = 4;
        }

        // ����ַ��ǿɴ�ӡ��ASCII�ַ�������ӵ�UTF-8�ı���
        if (byte >= 32 && byte <= 126) {
            utf8_text += std::string(response.begin() + i, response.begin() + i + char_length);
        }

        // ������һ���ַ���λ��
        i += char_length;
    }

    // ���UTF-8������ı�
    std::cout << "Server Response (UTF-8): " << utf8_text << std::endl;
    return utf8_text;
}