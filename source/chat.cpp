#include "chat.h"

#include "endpoints.h"
#include "nlohmann/json.hpp"

namespace {
nlohmann::json convert_options_to_json(const OpenAI::Chat::Options& options) {
  nlohmann::json opts_json;
  if (options.max_tokens) {
    opts_json["max_tokens"] = options.max_tokens.value();
  }
  if (options.temperature) {
    opts_json["temperature"] = options.temperature.value();
  }
  if (options.top_p) {
    opts_json["top_p"] = options.top_p.value();
  }
  if (options.n) {
    opts_json["n"] = options.n.value();
  }
  if (options.stream) {
    opts_json["stream"] = options.stream.value();
  }
  if (options.logprobs) {
    opts_json["logprobs"] = options.logprobs.value();
  }
  if (options.echo) {
    opts_json["echo"] = options.echo.value();
  }
  if (options.stop) {
    opts_json["stop"] = options.stop.value();
  }
  if (options.presence_penalty) {
    opts_json["presence_penalty"] = options.presence_penalty.value();
  }
  if (options.frequency_penalty) {
    opts_json["frequency_penalty"] = options.frequency_penalty.value();
  }
  if (options.logit_bias) {
    opts_json["logit_bias"] = options.logit_bias.value();
  }
  if (options.user) {
    opts_json["user"] = options.user.value();
  }

  return opts_json;
}
}  // namespace

OpenAI::Chat::Chat(std::shared_ptr<Request> req) : _req{std::move(req)} {}

OpenAI::Response OpenAI::Chat::create_completion(const std::string& model,
                                                 const std::string& message,
                                                 const Options& options) {
  nlohmann::json body_json = convert_options_to_json(options);
  body_json["model"] = model;
  body_json["messages"] = get_message_history();
  body_json["messages"].append(create_message(message, user));
  OpenAI::Response response =
      _req->post(OpenAI::endpoints.at("chats"), body_json.dump());

  return response;
}
