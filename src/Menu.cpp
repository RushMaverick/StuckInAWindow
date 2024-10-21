#include "../includes/Menu.hpp"
#include <iostream>

MenuItem::MenuItem(const std::string name, const int index) : _index(index)
{
	_name.setString(name);
	if (!_font.loadFromFile("fonts/Roboto-Medium.ttf"))
	{
		std::cerr << "Failed to load font!" << std::endl;
	}
	_name.setFont(_font);
	_name.setFillColor(sf::Color::Green);
	_name.setCharacterSize(12);
	std::cout << "MenuItem " << _index << " has been created." << std::endl;
	_rectangle.setSize(sf::Vector2f(70, 20));
}

sf::RectangleShape MenuItem::getRect()
{
	return (_rectangle);
}

sf::Text MenuItem::getText()
{
	return (_name);
}

void MenuItem::setPosition(sf::Vector2f menuPos)
{
	_rectangle.setPosition(menuPos);
	_name.setPosition(menuPos);
}

MenuItem::~MenuItem()
{
	std::cout << "MenuItem " << _index << " has been destroyed." << std::endl;
}

Menu::Menu()
{
	_isDrawn = false;
	_outline.setFillColor(sf::Color::Transparent);
	_outline.setOutlineColor(sf::Color::White);
	_outline.setOutlineThickness(2.0f);
	_outline.setSize({75, 55});
	std::cout << "Menu has been created." << std::endl;
}

void Menu::repositionMenuItems(sf::Vector2f mousePos)
{
	for (int i = 0; i < 2; i++)
	{
		menuItems[i].setPosition(mousePos); // This needs to add to mousePos.y to have it spawn rectangle.y downwards, so it is underneath.
		mousePos.y += 25;
	}
}

void Menu::setPositionMenu(sf::Vector2f mousePos)
{
	_position = mousePos;
	_outline.setPosition(_position);
	repositionMenuItems(_position);
	// menuItems[0].setPosition(_position);
}

void Menu::setIsDrawn(bool state)
{
	_isDrawn = state;
}

bool Menu::getIsDrawn()
{
	return _isDrawn;
}

sf::RectangleShape Menu::getMenu()
{
	return _outline;
}

sf::RectangleShape Menu::getRect(const int index)
{
	return (menuItems[index].getRect());
}

sf::Text Menu::getText(const int index)
{
	return (menuItems[index].getText());
}

Menu::~Menu()
{
	std::cout << "Menu has been destroyed." << std::endl;
}
