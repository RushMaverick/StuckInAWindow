#include <SFML/Graphics.hpp>
#include "../includes/Player.hpp"
#include "../includes/UI.hpp"
#include "../includes/Menu.hpp"
#include <iostream>
#include <string>

int main()
{
	sf::Clock deltaClock;

	Player player;
	UI ui;
	Menu menu;
	player.setPosition({250, 250});
	auto window = sf::RenderWindow{{500u, 500u}, "Help, I'm Stuck!"};

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Time deltaTime = deltaClock.restart();
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left:
				{
					auto position = sf::Vector2f{static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)};
					player.setTarget(position);
					menu.setIsDrawn(false);
					player.moveToTarget(deltaTime);
				}
				break;
				case sf::Mouse::Right:
					menu.setPositionMenu(sf::Vector2f{static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)});
					menu.setIsDrawn(true);
					break;
				default:
					break;
				};
			}
		}
		if (player.getIsMoving())
			player.updatePosition(deltaTime);
		window.clear();
		if (menu.getIsDrawn())
			window.draw(menu.getRect(1));
		window.draw(player.getSprite());
		window.draw(ui.getText());
		window.display();
	}
	return EXIT_SUCCESS;
}