#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Button
{
	enum state
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
	void setColorClicked(sf::Color colorClicked);
	void setColorHover(sf::Color colorHover);
	void setColorNormal(sf::Color colorNormal);
	sf::Text getText();
	sf::RectangleShape getRect();

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
	sf::Uint32 _btnState;

	sf::RectangleShape _btnItem;
};

class Menu
{
public:
	Menu();
	sf::RectangleShape getRect(const int index);
	sf::RectangleShape getMenu();
	sf::Text getText(const int index);
	bool getIsDrawn();
	void setIsDrawn(bool state);
	void setPositionMenu(sf::Vector2f mousePos);
	~Menu();

private:
	bool _isDrawn;
	sf::RectangleShape _outline;
	void repositionMenuItems(sf::Vector2f mousePos);
	sf::Vector2f _position;
	Button menuItems[2] = {Button("First Option", 1), Button("Second Option", 2)};
};

#endif