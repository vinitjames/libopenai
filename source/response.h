#ifndef RESPONSE_H
#define RESPONSE_H

#include <memory>
#include <string>

namespace OpenAI {
class Response {
 public:
  //! Default constructor
  Response(const std::string& url, const long& status_code,
           const std::string& reason, std::string&& data);

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

}  // namespace OpenAI

#endif /* RESPONSE_H */
