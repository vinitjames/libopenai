#ifndef REQUEST_H
#define REQUEST_H

//#include "response.h"
#include "authorization.h"
#include <cpr/cpr.h>

namespace OpenAI{
	class Request
	{
	public:
		Request() = delete;
        Request(const Authorization& auth);
		cpr::Response get(const std::string& url);
		cpr::Response post(const std::string& url, const std::string& body);		
		cpr::Response del(const std::string& url);		
	private:
		Authorization _auth;
		
	};
	
}
#endif /* REQUEST_H */
