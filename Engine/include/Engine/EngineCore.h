#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H
#include <Engine\Export.h>

#include <Engine\Manager\TexturesManager.h>
#include <Engine\Manager\ColliderManager.h>

#include <SFML\System\NonCopyable.hpp>

namespace engine
{
	class ENGINE_API EngineCore : public sf::NonCopyable
	{
	public:
		TexturesManager& GetTextureManager();
		ColliderManager& GetColliderManager();

	private:
		TexturesManager m_textureMng;
		ColliderManager m_colliderMng;
	};

	extern ENGINE_API EngineCore engineCore;

#define TextureMng engineCore.GetTextureManager()
#define ColliderMng engineCore.GetColliderManager()
}

#endif // ENGINE_CORE_H