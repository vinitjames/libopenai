#include "model.h"
#include "endpoints"


Response oai_api::Model::list() const {
	return _req.get(oai_endpoints["models"]);
}

Response oai_api::Model::retrive(const std::string& id) const {
	return _req.get(oai_endpoints["models"] +  id);
}
