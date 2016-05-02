#ifndef COLLISION_INFOS_H
#define COLLISION_INFOS_H
#include <Engine\Export.h>

#include <SFML\System\NonCopyable.hpp>

namespace engine
{
	class Collider;

	class ENGINE_API CollisionInfos : public sf::NonCopyable
	{
	public:
		Collider* m_other;
	};
}

#include <Engine\Collider\Collider.h>

#endif // COLLISION_INFOS_H