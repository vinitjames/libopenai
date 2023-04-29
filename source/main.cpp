#include "request.h"
#include "response.h"
#include <iostream>

int main(int argc, char *argv[])
{
	OpenAI::Request req{OpenAI::Authorization{"your_api_key"}};
	OpenAI::Response r = req.get("https://api.openai.com/v1/models");
	std::cout <<r.status_code()<< " "<< r.data();
    return 0;
}
