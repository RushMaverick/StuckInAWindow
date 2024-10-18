#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Utils.hpp"
#include <SFML/Graphics.hpp>
class Player {
	public:
		Player();
		~Player();
		sf::Sprite		getSprite() const;
		sf::Vector2f	getPosition() const;
		sf::Vector2f	getTarget() const;
		bool			getIsMoving() const;
		void			setPosition(sf::Vector2f position);
		void			setTarget(sf::Vector2f target);
		void			moveToTarget(sf::Time deltaTime);
		void			updatePosition(sf::Time deltaTime);
		sf::Vector2f 	lerp(sf::Vector2f start, sf::Vector2f end, float amount);
	private:
		std::string 	_name;
		int 			_hunger;
		bool 			_isMoving;
		float 			_moveSpeed;
		sf::Texture		_texture;
		sf::Sprite		_sprite;
		sf::Vector2f	_position;
		sf::Vector2f	_target;
};

#endif