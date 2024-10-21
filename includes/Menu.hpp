#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <SFML/Graphics.hpp>

class MenuItem
{
public:
	MenuItem(const std::string name, const int index); // Create sprite texture and text to set inside it.
	sf::RectangleShape getRect();
	sf::Text getText();
	void setPosition(sf::Vector2f menuPos);
	~MenuItem();

private:
	sf::Text _name;
	sf::Font _font;
	sf::RectangleShape _rectangle;
	int _index;
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
	MenuItem menuItems[2] = {MenuItem("First Option", 1), MenuItem("Second Option", 2)};
};

#endif