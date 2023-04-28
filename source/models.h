#include <string>
#include <memory>
#include "Response.h"
#include "Request.h"

namespace OpenAPI{
	class Model final {
	public:
		Response list() const;
		Response retrive(const std::string& id) const;
	private:
		std::shared_ptr<Request> _req;
	};
}
