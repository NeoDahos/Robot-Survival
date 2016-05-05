#include <Engine\Object\Transform.h>

namespace engine
{
	Transform::Transform(Object* const _parent) : Component(_parent)
	{
		m_isUnique = true;
		m_componentType = TransformComponent;
	}

	Transform::Transform(const Transform& _other) : Transform(nullptr)
	{
	}

	Transform::~Transform()
	{
	}
}