#include <Engine\Object\Component.h>
#include <Engine\Object\Object.h>

namespace engine
{
	Component::Component(Object* const _parent)
	{
		m_parent = _parent;
	}

	Component::~Component()
	{
	}
	
	Component::ComponentType Component::GetComponentType()
	{
		return m_componentType;
	}

	void Component::SetParent(Object* const _parent)
	{
		m_parent = _parent;
	}
}