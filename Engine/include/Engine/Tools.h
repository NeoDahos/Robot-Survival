#ifndef TOOLS_H
#define TOOLS_H
#include <Engine\Export.h>

#include <SFML\System\Vector2.hpp>

namespace engine
{
#define PI 3.14159265359f
#define SQUARE( Arg ) ( (Arg) * (Arg) )

	ENGINE_API float VectorAngle(const sf::Vector2f& _vector1, const sf::Vector2f& _vector2);
	ENGINE_API float VectorOrientedAngle(const sf::Vector2f& _vector1, const sf::Vector2f& _vector2);
	ENGINE_API float CrossProduct(const sf::Vector2f& _vector1, const sf::Vector2f& _vector2);

	ENGINE_API float VectorLength(const sf::Vector2f& _v);
	ENGINE_API float VectorLengthSq(const sf::Vector2f& _v);
	ENGINE_API sf::Vector2f VectorNormalization(sf::Vector2f& _v);
	ENGINE_API void VectorNormalize(sf::Vector2f& _vector);
}

#endif // TOOLS_H