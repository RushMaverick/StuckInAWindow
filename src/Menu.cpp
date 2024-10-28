#include "../includes/Menu.hpp"
#include "../includes/Button.hpp"
#include <iostream>

Menu::Menu()
{
	_isDrawn = false;
	_outline.setFillColor(sf::Color::Transparent);
	_outline.setOutlineColor(sf::Color::White);
	_outline.setOutlineThickness(2.0f);
	_outline.setSize({105, 55});
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
	_outline.setPosition({mousePos.x - 7.5f, mousePos.y - 5});
	repositionMenuItems(mousePos);
}

void Menu::setIsDrawn(bool state)
{
	_isDrawn = state;
}

bool Menu::getIsDrawn() const
{
	return _isDrawn;
}

sf::RectangleShape Menu::getMenu() const
{
	return _outline;
}

void Menu::checkButtonState(sf::Vector2f mousePos)
{
	for (int i = 0; i < 2; i++)
	{
		if (menuItems[i].getRect().getGlobalBounds().contains(mousePos))
		{
			menuItems[i].setState(1);
		}
		else
			menuItems[i].setState(0);
	}
}

Button &Menu::getButton(const int index)
{
	return (menuItems[index]);
}

sf::RectangleShape Menu::getRect(const int index) const
{
	return (menuItems[index].getRect());
}

sf::Text Menu::getText(const int index) const
{
	return (menuItems[index].getText());
}

Menu::~Menu()
{
	std::cout << "Menu has been destroyed." << std::endl;
}
