#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI();
	~UI();
	sf::Text getText() const;
	void setText(std::string text);

private:
	sf::Text _text;
	sf::Font _font;
	sf::Vector2i _position;
};

#endif