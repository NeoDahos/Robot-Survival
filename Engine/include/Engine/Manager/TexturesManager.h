#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <Engine\Export.h>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\String.hpp>
#include <SFML\System\NonCopyable.hpp>

#include <map>

namespace engine
{
	class ENGINE_API TexturesManager : public sf::NonCopyable
	{
	public:
		TexturesManager();
		~TexturesManager();

		bool AddTexture(const sf::String& _name, const sf::String& _path);
		const sf::Texture& GetTexture(const sf::String& _name);
		bool EraseTexture(const sf::String& _name);
		void ClearAllTextures();

	protected:
		std::map<sf::String, sf::Texture*> m_texturesMap;
	};
}

#endif // TEXTURE_MANAGER_H