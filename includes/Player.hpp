#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {

	public:
		Player();
		~Player();
		sf::Sprite getSprite() const;
	private:
		std::string _name;
		int 		_hunger;
		bool 		_isMoving;
		sf::Texture _texture;
		sf::Sprite 	_sprite;
};

#endif