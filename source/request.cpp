#include "request.h"
#include <cpr/cpr.h>

namespace {
	OpenAI::Response create_response(cpr::Response res){
		return OpenAI::Response{res.url.str(), res.status_code, res.reason, std::move(res.text)};
	}
}

OpenAI::Request::Request(const Authorization& auth)
	:_auth{auth}{}

OpenAI::Response OpenAI::Request::get(const std::string& url){
	return create_response(cpr::Get(cpr::Url{url},
									cpr::Header{{"Authorization", _auth.get_key()}}));
}

OpenAI::Response OpenAI::Request::post(const std::string& url, const std::string& json_string){
	
	return create_response(cpr::Post(cpr::Url{url},
									 cpr::Header{{"Authorization", _auth.get_key()},
												 {"Content-Type", "application/json"}},
									 cpr::Body{json_string}));
	
}

OpenAI::Response OpenAI::Request::del(const std::string& url){
	return create_response(cpr::Delete(cpr::Url{url},
									   cpr::Header{{"Authorization", _auth.get_key()}}));
	
}

