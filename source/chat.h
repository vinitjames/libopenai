#ifndef CHAT_H
#define CHAT_H

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "request.h"
#include "response.h"

namespace OpenAI {

struct Message {
  std::string role;
  std::string content;
  std::string name;
};

class ChatHistory {
  void add_message();

 private:
  std::vector<Message> _history;
};

class Chat final {
 public:
  Chat(std::shared_ptr<Request> req);
  struct Options {
    Options(){};
    std::optional<int> max_tokens = std::nullopt;
    std::optional<double> temperature = std::nullopt;
    std::optional<double> top_p = std::nullopt;
    std::optional<int> n = std::nullopt;
    std::optional<bool> stream = std::nullopt;
    std::optional<int> logprobs = std::nullopt;
    std::optional<bool> echo = std::nullopt;
    std::optional<std::string> stop = std::nullopt;
    std::optional<double> presence_penalty = std::nullopt;
    std::optional<double> frequency_penalty = std::nullopt;
    std::optional<std::unordered_map<std::string, std::int8_t>> logit_bias =
        std::nullopt;
    std::optional<std::string> user = std::nullopt;
  };

  Response create_completion(const std::string& model,
                             const std::string& message,
                             const Options& opts = {});
  ChatHistory get_history() const;
  void clear();

 private:
  std::shared_ptr<Request> _req;
  ChatHistory _chat_hist;
};
}  // namespace OpenAI

#endif /* CHAT_H */
