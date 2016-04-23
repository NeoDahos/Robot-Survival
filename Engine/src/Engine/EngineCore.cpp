#include <Engine\EngineCore.h>

namespace engine
{
	EngineCore engineCore;

	TexturesManager& EngineCore::GetTextureManager()
	{
		return m_textureMng;
	}

	ColliderManager& EngineCore::GetColliderManager()
	{
		return m_colliderMng;
	}
}