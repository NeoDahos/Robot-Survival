#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <Engine\Collider\CircleCollider.h>
#include <Engine\Object\Object.h>

#include <list>

namespace sf
{
	class RenderTarget;
}

class Scrap;

class Robot : public engine::Object
{
public:
	enum RobotType { Player, Fighter, HeavyCarrier, LightCarrier, AmphibiousCarrier };

	Robot(RobotType _type);
	virtual ~Robot();

	unsigned short GetLiftPower() const;

	void StartWalkning();
	void StopWalkning();
	void Lift(std::list<Scrap>& _scraps);

	virtual void Update(float _deltaTime);
	virtual void Draw(sf::RenderTarget& _target, const sf::RenderStates& _states = sf::RenderStates::Default);

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