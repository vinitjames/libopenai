#include "response.h"

#include <utility>

OpenAI::Response::Response(const std::string& url, const long& status_code,
                           const std::string& reason, std::string&& data)
    : _url{url},
      _status_code{status_code},
      _reason{reason},
      _data{std::move(data)} {}

std::string OpenAI::Response::url() const { return _url; }
std::string OpenAI::Response::data() const { return _data; }
std::string OpenAI::Response::reason() const { return _reason; }
long OpenAI::Response::status_code() const { return _status_code; }
