#include <string>
#include <memory>

namespace OpenApi{
	class Response
	{
	public:
		//! Default constructor
		Response();

		std::string url() const;
		//std::nlohmann::json data();
		long status_code();
		std::string reason();

	private:
		struct respImpl;
	    std::unique_ptr<respImpl> resp_ptr;
		
	};
	
}
