#include <unordered_map>
#include <string>

namespace oai_api {
	const std::unordered_map<std::string, const std::string> oai_endpoints
		{
			{"models", "https://api.openai.com/v1/models"},
			{"completions", "https://api.openai.com/v1/completions"},
			{"chats", "https://api.openai.com/v1/chat/completions"},
			{"edits", "https://api.openai.com/v1/edits"},
			{"images", "https://api.openai.com/v1/images"},
			{"embeddings", "https://api.openai.com/v1/embeddings"},
			{"audio", "https://api.openai.com/v1/audio"},
			{"files", "https://api.openai.com/v1/files"},
			{"fine-tune", "https://api.openai.com/v1/fine-tunes"},
			{"moderation", "https://api.openai.com/v1/moderations"},
			{"engines", "https://api.openai.com/v1/engines"}
		};	
}

