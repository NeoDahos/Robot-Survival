#include <Engine\Manager\TexturesManager.h>

namespace engine
{
	TexturesManager::TexturesManager()
	{
	}

	TexturesManager::~TexturesManager()
	{
	}

	bool TexturesManager::AddTexture(const sf::String& _name, const sf::String& _path)
	{
		sf::Texture* texture = new sf::Texture;
		if (texture->loadFromFile(_path))
		{
			m_texturesMap.emplace(_name, texture);
			return true;
		}

		return false;
	}

	const sf::Texture& TexturesManager::GetTexture(const sf::String& _name)
	{
		return *m_texturesMap[_name];
	}

	bool TexturesManager::EraseTexture(const sf::String& _name)
	{
		if (m_texturesMap.find(_name) != m_texturesMap.end())
		{
			delete m_texturesMap[_name];
			m_texturesMap.erase(_name);

			return true;
		}

		return false;
	}

	void TexturesManager::ClearAllTextures()
	{
		std::map<sf::String, sf::Texture*>::iterator it = m_texturesMap.begin();
		std::map<sf::String, sf::Texture*>::iterator itEnd = m_texturesMap.end();

		for (it; it != itEnd; ++it)
		{
			if ((*it).second)
				delete (*it).second;
		}

		m_texturesMap.clear();
	}
}