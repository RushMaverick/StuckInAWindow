#include "../includes/UI.hpp"

UI::UI()
{
	if (!_font.loadFromFile("../../includes/fonts/Roboto-Medium.ttf"))
	{
		std::cerr << "Failed to load font!" << std::endl;
	}
	_text.setFont(_font);
	_text.setString("Hello, World!");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold);
	_text.setPosition({10, 10});
}

UI::~UI()
{
	std::cout << "UI destroyed!" << std::endl;
}

sf::Text UI::getText() const
{
	return _text;
}

void UI::setText(std::string text)
{
	_text = sf::Text(text, _font, 24);
}