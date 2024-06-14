#pragma once
std::vector<char> CreateRconPacket(int request_id, int type, const std::string& payload);
std::string printUTF8Text(const std::vector<uint8_t>& response);