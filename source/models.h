#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <memory>
#include "response.h"
#include "request.h"

namespace OpenAI{
	class Model final {
	public:
		Model() = delete;
		Model(std::shared_ptr<Request> req);
		Response list() const;
		Response retrive(const std::string& id) const;
	private:
		std::shared_ptr<Request> _req;
	};
}
#endif /* MODELS_H */
