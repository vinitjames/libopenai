#include "request.h"
#include <iostream>

int main(int argc, char *argv[])
{
	OpenAI::Request req{OpenAI::Authorization{"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"}};
	cpr::Response r = req.get("https://api.openai.com/v1/models");
	std::cout <<r.status_code<< " "<<r.header["content-type"]<< " "<<r.text;
    return 0;
}
