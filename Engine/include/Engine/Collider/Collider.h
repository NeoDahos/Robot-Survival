#ifndef COLLIDER_H
#define COLLIDER_H
#include <Engine\Export.h>


#include <SFML\System\Vector2.hpp>
#include <SFML\System\NonCopyable.hpp>

#include <list>
#include <functional>

namespace engine
{
	class CircleCollider;
	class CollisionInfos;

	class ENGINE_API Collider : sf::NonCopyable
	{
	public:
		enum ColliderType { Circle };

		Collider(bool _isTrigger = false);

		unsigned short GetId() const;
		ColliderType GetType() const;
		virtual void SetPosition(const sf::Vector2f& _position) = 0;

		virtual void Move(const sf::Vector2f& _moveVector) = 0;
		auto FindCollider(unsigned short _id);

		virtual bool TestCollision(CircleCollider* const _other) = 0;

	protected:
		void ManageCollision(Collider* const _other, bool _isColliding);
		
	public:
		static unsigned short s_instanceCount;

	protected:
		std::list<unsigned short> m_collidingIds;
		std::function<void(const CollisionInfos&)> m_onCollisionEnter;
		std::function<void(const CollisionInfos&)> m_onCollisionStay;
		std::function<void(const CollisionInfos&)> m_onCollisionExit;
		std::function<void(const CollisionInfos&)> m_onTriggerEnter;
		std::function<void(const CollisionInfos&)> m_onTriggerStay;
		std::function<void(const CollisionInfos&)> m_onTriggerExit;
		ColliderType m_type;
		unsigned short m_id;
		bool m_isTrigger;
	};
}

#endif // COLLIDER_H