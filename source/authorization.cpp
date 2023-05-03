#include "authorization.h"

OpenAI::Authorization::Authorization(const std::string& api_key)
    : _api_key{api_key} {}

std::string OpenAI::Authorization::get_key() const {
  return "Bearer " + _api_key;
}
