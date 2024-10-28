#include "../includes/Menu.hpp"
#include <iostream>

Button::Button(const std::string text, const int index) : _index(index)
{
	_text.setString(text);
	if (!_font.loadFromFile("../../includes/fonts/Roboto-Medium.ttf"))
	{
		std::cerr << "Failed to load font!" << std::endl;
	}
	std::cout << "Button " << _index << " been created." << std::endl;
	_btnItem.setFillColor(sf::Color::White);
	_btnItem.setOutlineColor(sf::Color::Black);
	_btnItem.setOutlineThickness(1.0f);
	_btnItem.setSize({90, 20});
	sf::Rect rect = _btnItem.getGlobalBounds();
	_colorClicked = sf::Color::Red;
	_colorHover = sf::Color::Blue;
	_colorNormal = sf::Color::White;
	_text.setFont(_font);
	_text.setCharacterSize(12);
	_text.setFillColor(sf::Color::Black);
}

Button::~Button()
{
}

void Button::setText(const std::string text)
{
	_text.setString(text);
}

void Button::setPosition(sf::Vector2f pos)
{
	_btnItem.setPosition(pos);
	_text.setPosition(pos);
}

void Button::setState(int state)
{
	switch (state)
	{
	case 0:
		_btnItem.setFillColor(_colorNormal);
		break;
	case 1:
		_btnItem.setFillColor(_colorHover);
		std::cout << "Color CHANGE" << std::endl;
		break;
	case 2:
		_btnItem.setFillColor(_colorClicked);
		break;
	default:
		break;
	}
}

sf::RectangleShape Button::getRect()
{
	return _btnItem;
}

sf::Text Button::getText()
{
	return _text;
}

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

bool Menu::getIsDrawn()
{
	return _isDrawn;
}

sf::RectangleShape Menu::getMenu()
{
	return _outline;
}

Button &Menu::getButton(const int index)
{
	return (menuItems[index]);
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
