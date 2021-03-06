#ifndef COLLIDER_H
#define COLLIDER_H
#include <Engine\Export.h>

#include <Engine\Object\Component.h>

#include <SFML\System\Vector2.hpp>

#include <list>

namespace engine
{
	class CircleCollider;
	class CollisionInfos;

	class ENGINE_API Collider : public Component
	{
	public:
		enum ColliderType { Circle };

		Collider(Object* const _parent, bool _isTrigger = false);
		Collider(const Collider& _other);

		unsigned short GetId() const;
		ColliderType GetColliderType() const;
		virtual void SetPosition(const sf::Vector2f& _position) = 0;
		virtual sf::Vector2f GetPosition() const = 0;

		auto FindCollider(unsigned short _id);

		virtual bool TestCollision(CircleCollider* const _other) = 0;

	protected:
		void ManageCollision(Collider* const _other, bool _isColliding);
		
	public:
		static unsigned short s_instanceCount;

	protected:
		std::list<unsigned short> m_collidingIds;
		ColliderType m_colliderType;
		unsigned short m_id;
		bool m_isTrigger;
	};
}

#endif // COLLIDER_H