#ifndef REQUEST_H
#define REQUEST_H

#include "response.h"
#include "authorization.h"

namespace OpenAI{
	class Request
	{
	public:
		Request() = delete;
        Request(const Authorization& auth);
		Response get(const std::string& url);
		Response post(const std::string& url, const std::string& body);		
		Response del(const std::string& url);		
	private:
		Authorization _auth;
		
	};
	
}
#endif /* REQUEST_H */
