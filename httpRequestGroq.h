#pragma once
#include <string>
#include <curl/curl.h>
#include <iostream>

class RequestGroq
{
public:
	void sendRequest(const std::string& prompt, std::string &response);
};