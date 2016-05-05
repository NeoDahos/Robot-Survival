#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <Engine\Collider\CircleCollider.h>
#include <Engine\Object\Object.h>

#include <list>

namespace sf
{
	class String;
	class RenderTarget;
}

class Robot;

class Scrap : public engine::Object
{
public:
	Scrap(const sf::String& _spriteName, unsigned short _weight);
	~Scrap();

	float GetSize() const;

	bool AddCarrier(Robot* _robot);
	bool RemoveCarrier(Robot* _robot);

	virtual void Draw(sf::RenderTarget& _target, const sf::RenderStates& _states = sf::RenderStates::Default);

protected:
	std::list<Robot*> m_carriers;

	sf::Sprite m_sprite;
	engine::CircleCollider m_collider;
	float m_size;
	unsigned short m_carriersLiftPower;
	unsigned short m_weight;
};