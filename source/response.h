#ifndef RESPONSE_H
#define RESPONSE_H


#include <string>
#include <memory>

namespace OpenAI{
	class Response
	{
	public:
		//! Default constructor
		Response(const std::string&  url,
				 const long& status_code,
				 const std::string& reason,
				 std::string&& data);

		std::string url() const;
		std::string data() const;
		long status_code() const;
		std::string reason() const;
		

	private:
		std::string _url;
		long _status_code;
		std::string _reason;
		std::string _data;
		
	};
	
}

#endif /* RESPONSE_H */
