#include "../includes/Menu.hpp"
#include <iostream>

MenuItem::MenuItem(const std::string name, const int index) : _name(name), _index(index)
{
	std::cout << "MenuItem " << _index << " has been created." << std::endl;
	_rectangle.setSize(sf::Vector2f(50, 50));
}

sf::RectangleShape MenuItem::getRect()
{
	return (_rectangle);
}

void MenuItem::setPosition(sf::Vector2f menuPos)
{
	_rectangle.setPosition(menuPos);
}

MenuItem::~MenuItem()
{
	std::cout << "MenuItem " << _index << " has been destroyed." << std::endl;
}

Menu::Menu()
{
	_isDrawn = false;
	std::cout << "Menu has been created." << std::endl;
}

void Menu::setPositionMenu(sf::Vector2f mousePos)
{
	_position = mousePos;
	menuItems[1].setPosition(_position);
}

void Menu::setIsDrawn(bool state)
{
	_isDrawn = state;
}

bool Menu::getIsDrawn()
{
	return _isDrawn;
}

sf::RectangleShape Menu::getRect(const int index)
{
	return (menuItems[index].getRect());
}

Menu::~Menu()
{
	std::cout << "Menu has been destroyed." << std::endl;
}
