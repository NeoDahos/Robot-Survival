#include <Engine\Collider\CircleCollider.h>
#include <Engine\Object\Object.h>
#include <Engine\Tools.h>

namespace engine
{
	CircleCollider::CircleCollider(Object* const _parent, float _radius, bool _isTrigger) : Collider(_parent, _isTrigger)
	{
		m_radius = _radius;
		m_colliderType = ColliderType::Circle;
	}

	CircleCollider::CircleCollider(const CircleCollider& _other) : Collider(_other)
	{
		m_centerPosition = _other.m_centerPosition;
		m_radius = _other.m_radius;
	}

	CircleCollider::~CircleCollider()
	{
	}

	void CircleCollider::SetPosition(const sf::Vector2f& _position)
	{
		m_centerPosition = _position;
	}

	sf::Vector2f CircleCollider::GetPosition() const
	{
		return m_parent->GetPosition() + m_centerPosition;
	}

	bool CircleCollider::TestCollision(CircleCollider* const _other)
	{
		bool isColliding = VectorLengthSq(_other->GetPosition() - GetPosition()) <= SQUARE(m_radius + _other->m_radius);

		ManageCollision(_other, isColliding);

		return isColliding;
	}
}