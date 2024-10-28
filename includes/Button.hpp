#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Button
{
	enum class ButtonState
	{
		normal,
		hover,
		clicked
	};

public:
	Button() = delete;
	Button(const std::string text, const int index);
	~Button();
	void setText(const std::string text);
	void setPosition(sf::Vector2f pos);
	void setState(int state);
	ButtonState getState(int index);
	sf::Text getText() const;
	sf::RectangleShape getRect() const;

private:
	int _index;
	sf::Color _colorClicked;
	sf::Color _colorHover;
	sf::Color _colorNormal;
	sf::Color _textColor;

	sf::Vector2f _position;
	sf::Vector2f _size;
	unsigned int _fontSize;

	sf::Text _text;
	sf::Font _font;
	ButtonState _btnState;

	sf::RectangleShape _btnItem;
};

#endif