#include "SpaceShip.h"
#include <Engine\EngineCore.h>
#include <Engine\Object\Transform.h>

#include <SFML\Graphics\RenderTarget.hpp>

SpaceShip::SpaceShip()
{
	m_sprite.setTexture(engine::TextureMng.GetTexture("SpaceShip"));

	sf::FloatRect bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

	Move(sf::Vector2f(-300.f, 0.f));
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::Update(float _deltaTime)
{

}

void SpaceShip::Draw(sf::RenderTarget& _target, const sf::RenderStates& _states)
{
	_target.draw(m_sprite, _states.transform * m_transform->getTransform());
}