#include <Engine\Collider\CircleCollider.h>
#include <Engine\Tools.h>

namespace engine
{
	CircleCollider::CircleCollider(float _radius, bool _isTrigger) : Collider(_isTrigger)
	{
		m_radius = _radius;
		m_type = ColliderType::Circle;
	}

	CircleCollider::~CircleCollider()
	{
	}

	void CircleCollider::SetPosition(const sf::Vector2f& _position)
	{
		m_centerPosition = _position;
	}

	void CircleCollider::Move(const sf::Vector2f& _moveVector)
	{
		m_centerPosition += _moveVector;
	}

	bool CircleCollider::TestCollision(CircleCollider* const _other)
	{
		bool isColliding = VectorLengthSq(_other->m_centerPosition - m_centerPosition) <= SQUARE(m_radius + _other->m_radius);

		ManageCollision(_other, isColliding);

		return isColliding;
	}
}