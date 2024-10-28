#include "../includes/Button.hpp"
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
		break;
	case 2:
		_btnItem.setFillColor(_colorClicked);
		break;
	default:
		break;
	}
}

sf::RectangleShape Button::getRect() const
{
	return _btnItem;
}

sf::Text Button::getText() const
{
	return _text;
}

Button::ButtonState Button::getState(int index)
{
	return _btnState;
}