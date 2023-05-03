#ifndef REQUEST_H
#define REQUEST_H

#include "authorization.h"
#include "response.h"

namespace OpenAI {
class Request {
 public:
  Request() = delete;
  Request(const Authorization& auth);
  Response get(const std::string& url);
  Response post(const std::string& url, const std::string& body);
  Response del(const std::string& url);

 private:
  Authorization _auth;
};

}  // namespace OpenAI
#endif /* REQUEST_H */
