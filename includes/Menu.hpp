#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Button;
class Menu
{
public:
	Menu();
	sf::RectangleShape getRect(const int index) const;
	sf::RectangleShape getMenu() const;
	sf::Text getText(const int index) const;
	Button &getButton(const int index);
	bool getIsDrawn() const;
	void setIsDrawn(bool state);
	void setPositionMenu(sf::Vector2f mousePos);
	void checkButtonState(sf::Vector2f mousePos);
	~Menu();

private:
	bool _isDrawn;
	sf::RectangleShape _outline;
	void repositionMenuItems(sf::Vector2f mousePos);
	sf::Vector2f _position;
	Button menuItems[3] = {Button("First Option", 1), Button("Second Option", 2), Button("Third Option", 3)};
};

#endif