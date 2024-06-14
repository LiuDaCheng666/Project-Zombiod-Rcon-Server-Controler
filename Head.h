#pragma once
#include <iostream>
//#include <../ext/asio/include/asio.hpp>
#include <boost/asio.hpp>
#include <cstdint>
#include <vector>
#include <string>
#include <Winsock2.h> // 引入Winsock2头文件
#include <iostream>
#include "Rcon.h"
#include <iomanip> // 添加这行
#include "../Github Version/ext/nlohmann/json.hpp"
#include"account.h"
#pragma comment(lib, "Ws2_32.lib") // 链接Winsock库
using boost::asio::ip::tcp;