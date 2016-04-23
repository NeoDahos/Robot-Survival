#include "Scrap.h"
#include <Engine\EngineCore.h>

#include <SFML\System\String.hpp>
#include <SFML\Graphics\RenderTarget.hpp>

#include "..\Robot\Robot.h"

Scrap::Scrap(const sf::String& _spriteName, unsigned short _weight) : m_collider(32.f), m_carriersLiftPower(0)
{
	m_sprite.setTexture(engine::TextureMng.GetTexture(_spriteName));
	sf::FloatRect bounds = m_sprite.getGlobalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	m_collider.SetPosition(m_sprite.getPosition());

	m_weight = _weight;
	m_size = bounds.width / 2.f;
}

Scrap::~Scrap()
{
	m_carriers.clear();
}

sf::Vector2f Scrap::GetPosition() const
{
	return m_sprite.getPosition();
}

float Scrap::GetSize() const
{
	return m_size;
}

bool Scrap::AddCarrier(Robot* _robot)
{
	unsigned short carrierLiftPower = _robot->GetLiftPower();

	if (m_carriersLiftPower + carrierLiftPower > m_weight * 2)
		return false;

	std::list<Robot*>::iterator it = m_carriers.begin();
	std::list<Robot*>::iterator itEnd = m_carriers.end();

	while (it != itEnd && (*it) != _robot)
		++it;

	if (it != m_carriers.end())
		return false;

	m_carriers.push_back(_robot);
	m_carriersLiftPower += carrierLiftPower;

	return true;
}

bool Scrap::RemoveCarrier(Robot* _robot)
{
	std::list<Robot*>::iterator it = m_carriers.begin();
	std::list<Robot*>::iterator itEnd = m_carriers.end();

	while (it != itEnd && (*it) != _robot)
		++it;

	if (it == m_carriers.end())
		return false;

	m_carriers.erase(it);
	m_carriersLiftPower -= _robot->GetLiftPower();

	return true;
}

void Scrap::Move(sf::Vector2f _move)
{
	m_sprite.move(_move);
	m_collider.Move(_move);
}

void Scrap::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}