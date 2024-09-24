#include "../includes/Player.hpp"

Player::Player() : _name("Hero"), _hunger(100), _isMoving(false) {
	std::cout << "Player " << _name << " created!" << std::endl;
	if (!_texture.loadFromFile("sprites/hero.png"))
		std::cerr << "Failed to load texture!" << std::endl;
	_sprite.setTexture(_texture);
	_sprite.setScale(2.0f, 2.0f);
	_sprite.setPosition(250, 250);
}

Player::~Player() {
	std::cout << "Player " << _name << " destroyed!" << std::endl;
}

sf::Sprite Player::getSprite() const {
	return _sprite;
}