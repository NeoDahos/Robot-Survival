#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <list>

#include "..\Scrap\Scrap.h"
#include <Engine\Collider\CircleCollider.h>

namespace sf
{
	class RenderTarget;
}

class Robot
{
public:
	enum RobotType { Player, Fighter, HeavyCarrier, LightCarrier, AmphibiousCarrier };

	Robot(RobotType _type);
	virtual ~Robot();

	sf::Vector2f GetPosition() const;
	unsigned short GetLiftPower() const;

	void StartWalkning();
	void StopWalkning();
	void Lift(std::list<Scrap>& _scraps);

	virtual void Update(float _deltaTime);
	void Draw(sf::RenderTarget& _target);

protected:
	void ComputeOrientation(const sf::Vector2f& _moveDirection);

private:
	void MoveTo(const sf::Vector2f& _destination);
	
protected:
	static unsigned short s_instanceCount;

	sf::Sprite m_sprite;
	sf::Sprite m_liftLaser;
	engine::CircleCollider m_collider;
	float m_walkingSpeed;
	float m_maxLiftDistance;
	unsigned short m_liftPower;
	unsigned short m_id;
	RobotType m_type;
	Scrap* m_liftedScrap;
	bool m_isWalking;
};