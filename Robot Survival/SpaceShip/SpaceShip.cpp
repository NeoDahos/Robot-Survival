#include "SpaceShip.h"
#include <Engine\EngineCore.h>

#include <SFML\Graphics\RenderTarget.hpp>

SpaceShip::SpaceShip()
{
	m_sprite.setTexture(engine::TextureMng.GetTexture("SpaceShip"));

	sf::FloatRect bounds = m_sprite.getGlobalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::Update(float _deltaTime)
{

}

void SpaceShip::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}