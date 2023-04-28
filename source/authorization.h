#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <string>

namespace OpenAI{
	class Authorization
	{
	public:
		Authorization() = default;
        Authorization(const std::string& api_key);
		std::string get_key() const;		
	private:
		std::string _api_key;
		
	};
	
}
#endif /* AUTHORIZATION_H */
