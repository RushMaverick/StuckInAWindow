#include "../includes/Player.hpp"
#include <cmath>

Player::Player() : _name("Hero"), _hunger(100), _moveSpeed(100.0f), _isMoving(false)
{
	std::cout << "Player " << _name << " created!" << std::endl;
	if (!_texture.loadFromFile("../../includes/sprites/hero.png"))
		std::cerr << "Failed to load texture!" << std::endl;
	_sprite.setTexture(_texture);
	_sprite.setScale(2.0f, 2.0f);
	_target = {0, 0};
}

Player::~Player()
{
	std::cout << "Player " << _name << " destroyed!" << std::endl;
}

sf::Sprite Player::getSprite() const
{
	return _sprite;
}

void Player::setPosition(sf::Vector2f position)
{
	_position = position;
	_sprite.setPosition(position.x, position.y);
}

void Player::setTarget(sf::Vector2f target)
{
	_target = target;
}

sf::Vector2f Player::getPosition() const
{
	return _position;
}

sf::Vector2f Player::getTarget() const
{
	return _target;
}

bool Player::getIsMoving() const
{
	return _isMoving;
}

void Player::moveToTarget(sf::Time deltaTime)
{
	_isMoving = true;
	sf::Vector2f direction = _target - _sprite.getPosition();

	float length = lengthVector2(direction);
	if (length <= 1.0f)
	{
		_isMoving = false;
		return;
	}

	sf::Vector2f normalizedDir = normalizeVector2(direction);
	float speed = deltaTime.asSeconds() * _moveSpeed;
	// easing functions to accelerate up to a speed?

	_position += normalizedDir * speed;
	_sprite.setPosition(_position);
}

void Player::updatePosition(sf::Time deltaTime)
{
	if (_isMoving)
		moveToTarget(deltaTime);
}

sf::Vector2f Player::lerp(sf::Vector2f start, sf::Vector2f end, float amount)
{
	return start + amount * (end - start);
}
