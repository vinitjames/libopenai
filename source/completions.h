#ifndef COMPLETIONS_H
#define COMPLETIONS_H

#include <string>
#include <memory>
#include <optional>
#include <unordered_map>
#include "response.h"
#include "request.h"

namespace OpenAI{
	class Completions final {
	public:
		Completions (std::shared_ptr<Request> req);
		struct Options {
			Options(){};
			std::optional<std::string> prompt = std::nullopt;
			std::optional<std::string> suffix = std::nullopt;
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
			std::optional<int> best_of = std::nullopt;
			std::optional<std::unordered_map<std::string, std::int8_t>> logit_bias = std::nullopt;
			std::optional<std::string> user = std::nullopt;
		};
		
		Response create(const std::string& model, const Options& opts = {});
	private:
		std::shared_ptr<Request> _req;
	};
}
#endif /* COMPLETIONS_H */
