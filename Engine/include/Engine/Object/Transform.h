#ifndef TRASNFORM_H
#define TRANSFORM_H

#include <Engine\Object\Component.h>

#include <SFML\Graphics\Transformable.hpp>

namespace engine
{
	class Transform : public Component, public sf::Transformable
	{
	public:
		Transform(Object* const _parent);
		~Transform();
	};
}

#endif // TRANSFORM_H