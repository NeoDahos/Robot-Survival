#pragma once

#include <SFML\Graphics\Sprite.hpp>

namespace sf
{
	class RenderTarget;
}

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();

	virtual void Update(float _deltaTime);
	void Draw(sf::RenderTarget& _target);

protected:
	sf::Sprite m_sprite;
};