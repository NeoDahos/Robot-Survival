#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H
#include <Engine\Export.h>

#include <Engine\Collider\Collider.h>

#include <SFML\System\Vector2.hpp>

namespace engine
{
	class ENGINE_API CircleCollider : public Collider
	{
	public:
		CircleCollider(float _radius, bool _isTrigger = false);
		~CircleCollider();

		virtual void SetPosition(const sf::Vector2f& _position);

		virtual void Move(const sf::Vector2f& _moveVector);

		virtual bool TestCollision(CircleCollider* const _other);

	protected:
		sf::Vector2f m_centerPosition;
		float m_radius;
	};
}

#endif // CIRCLE_COLLIDER_H