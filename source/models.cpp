#include "models.h"
#include "endpoints.h"

OpenAI::Model::Model(std::shared_ptr<Request> req)
	:_req{std::move(req)}{}

OpenAI::Response OpenAI::Model::list() const {
	return _req->get(endpoints.at("models"));
}

OpenAI::Response OpenAI::Model::retrive(const std::string& id) const {
	return _req->get(endpoints.at("models") + "/"+  id);
}
