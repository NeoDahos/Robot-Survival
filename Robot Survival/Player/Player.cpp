#include "Player.h"
#include "..\Global.h"

#include <Engine\Tools.h>

#include <SFML\Graphics\RenderTarget.hpp>

Player::Player() : Robot(RobotType::Player)
{
}

Player::~Player()
{
}

void Player::Update(float _deltaTime)
{
	const sf::Vector2f& mousePos = static_cast<sf::Vector2f>(global::mousePosInWindow);
	sf::Vector2f moveDirection = mousePos - global::windowCenter;
	engine::VectorNormalize(moveDirection);

	ComputeOrientation(moveDirection);

	if (m_isWalking)
	{
		sf::Vector2f moveVector = (moveDirection * m_walkingSpeed) * _deltaTime;
		m_sprite.move(moveVector);
		m_collider.Move(moveVector);
	}

	Robot::Update(_deltaTime);
}