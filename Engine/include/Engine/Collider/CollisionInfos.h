#ifndef COLLISION_INFOS_H
#define COLLISION_INFOS_H
#include <Engine\Export.h>

#include <SFML\System\NonCopyable.hpp>

namespace engine
{
	class Collider;
	class Object;

	class ENGINE_API CollisionInfos : public sf::NonCopyable
	{
	public:
		Collider* m_collider;
		Object* m_object;
	};
}

#include <Engine\Collider\Collider.h>
#include <Engine\Object\Object.h>

#endif // COLLISION_INFOS_H