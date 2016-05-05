#pragma once

#include <Engine\Object\Object.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderStates.hpp>

namespace sf
{
	class RenderTarget;
}

class SpaceShip : public engine::Object
{
public:
	SpaceShip();
	~SpaceShip();

	virtual void Update(float _deltaTime);
	virtual void Draw(sf::RenderTarget& _target, const sf::RenderStates& _states = sf::RenderStates::Default);

protected:
	sf::Sprite m_sprite;
};