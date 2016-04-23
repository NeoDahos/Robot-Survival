#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <list>

#include <Engine\Collider\CircleCollider.h>

namespace sf
{
	class String;
	class RenderTarget;
}

class Robot;

class Scrap
{
public:
	Scrap(const sf::String& _spriteName, unsigned short _weight);
	~Scrap();

	sf::Vector2f GetPosition() const;
	float GetSize() const;

	bool AddCarrier(Robot* _robot);
	bool RemoveCarrier(Robot* _robot);
	void Move(sf::Vector2f _move);

	void Draw(sf::RenderTarget& _target);

protected:
	std::list<Robot*> m_carriers;

	sf::Sprite m_sprite;
	engine::CircleCollider m_collider;
	float m_size;
	unsigned short m_carriersLiftPower;
	unsigned short m_weight;
};