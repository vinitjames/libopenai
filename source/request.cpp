#include "request.h"

OpenAI::Request::Request(const Authorization& auth)
	:_auth{auth}{}

cpr::Response OpenAI::Request::get(const std::string& url){
	return cpr::Get(cpr::Url{url},
					cpr::Header{{"Authorization", _auth.get_key()}});
}

cpr::Response OpenAI::Request::post(const std::string& url, const std::string& body){
	
	//return cpr::Post(cpr::Url{url},
	//				 cpr::Header{{"Authorization", _auth.get_key()}},
	//				 body);
	
}

cpr::Response OpenAI::Request::del(const std::string& url){
	return cpr::Delete(cpr::Url{url},
					   cpr::Header{{"Authorization", _auth.get_key()}});
}

