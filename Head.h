#pragma once
#include <iostream>
//#include <../ext/asio/include/asio.hpp>
#include <boost/asio.hpp>
#include <cstdint>
#include <vector>
#include <string>
#include <Winsock2.h> // ����Winsock2ͷ�ļ�
#include <iostream>
#include "Rcon.h"
#include <iomanip> // �������
#include "../Github Version/ext/nlohmann/json.hpp"
#include"account.h"
#pragma comment(lib, "Ws2_32.lib") // ����Winsock��
using boost::asio::ip::tcp;