#include "Robot.h"

#include <Engine\EngineCore.h>
#include <Engine\Object\Transform.h>
#include <Engine\Tools.h>

#include <SFML\Graphics\RenderTarget.hpp>

#include "..\Scrap\Scrap.h"

unsigned short Robot::s_instanceCount = 0;

Robot::Robot(RobotType _type) : m_collider(this, 32.f), m_walkingSpeed(250.f), m_liftedScrap(nullptr), m_isWalking(false)
{
	sf::FloatRect bounds;
	m_liftLaser.setTexture(engine::TextureMng.GetTexture("LiftLaser"));
	bounds = m_liftLaser.getLocalBounds();
	m_liftLaser.setOrigin(bounds.width / 2.f, 0.f);
	m_maxLiftDistance = bounds.height;

	m_type = _type;

	switch (m_type)
	{
	case Fighter:
		m_liftPower = 0;
		break;
	case Player:
		m_sprite.setTexture(engine::TextureMng.GetTexture("Player"));
	case LightCarrier:
	case AmphibiousCarrier:
		m_liftPower = 1;
		break;
	case HeavyCarrier:
		m_liftPower = 2;
		break;
	default:
		m_liftPower = 0;
		break;
	}
	
	bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	m_collider.SetPosition(GetPosition());
	m_id = s_instanceCount;
	s_instanceCount++;
}

Robot::~Robot()
{
}

unsigned short Robot::GetLiftPower() const
{
	return m_liftPower;
}

void Robot::StartWalkning()
{
	m_isWalking = true;
}

void Robot::StopWalkning()
{
	m_isWalking = false;
}

void Robot::Lift(std::list<Scrap>& _scraps)
{
	if (m_liftedScrap == nullptr)
	{
		sf::Vector2f selfPosition = GetPosition();
		Scrap* scrapToLift = nullptr;
		float minDist = m_maxLiftDistance * m_maxLiftDistance;
		float distance = 0.f;

		for (auto&& scrap : _scraps)
		{
			distance = engine::VectorLengthSq(scrap.GetPosition() - selfPosition);
			if (distance <= minDist)
			{
				minDist = distance;
				scrapToLift = &scrap;
			}
		}

		if (scrapToLift != nullptr)
		{
			if(scrapToLift->AddCarrier(this))
				m_liftedScrap = scrapToLift;
		}
	}
	else
	{
		m_liftedScrap->RemoveCarrier(this);
		m_liftedScrap = nullptr;
	}
}

void Robot::Update(float _deltaTime)
{
	if (m_liftedScrap != nullptr)
	{
		sf::Vector2f position = GetPosition();
		sf::Vector2f laserDirection = m_liftedScrap->GetPosition() - position;
		float angle = engine::VectorOrientedAngle(sf::Vector2f(0.f, 1.f), laserDirection);

		m_liftLaser.setPosition(position);
		m_liftLaser.setRotation(angle);

		float laserLength = engine::VectorLength(laserDirection);

		if (laserLength > m_maxLiftDistance)
		{
			laserLength = m_maxLiftDistance;
			sf::Vector2f moveVector = (engine::VectorNormalization(laserDirection) * -m_walkingSpeed) * _deltaTime;
			m_liftedScrap->Move(moveVector);
		}

		float scale = laserLength / m_maxLiftDistance;
		m_liftLaser.setScale(1.f, scale);
	}
}

void Robot::Draw(sf::RenderTarget& _target, const sf::RenderStates& _states)
{
	if(m_liftedScrap != nullptr)
		_target.draw(m_liftLaser, _states.transform * m_transform->getTransform());

	_target.draw(m_sprite, _states.transform * m_transform->getTransform());
}

void Robot::MoveTo(const sf::Vector2f& _destination)
{

}

void Robot::ComputeOrientation(const sf::Vector2f& _moveDirection)
{
	float angle;
	if (engine::VectorLengthSq(_moveDirection) > 0.f)
	{
		angle = engine::VectorOrientedAngle(sf::Vector2f(0.f, -1.f), _moveDirection);
		m_sprite.setRotation(angle);
	}
}