#ifndef MODELS_H
#define MODELS_H

#include <memory>
#include <string>

#include "request.h"
#include "response.h"

namespace OpenAI {
class Model final {
 public:
  Model() = delete;
  Model(std::shared_ptr<Request> req);
  Response list() const;
  Response retrive(const std::string& id) const;

 private:
  std::shared_ptr<Request> _req;
};
}  // namespace OpenAI
#endif /* MODELS_H */
