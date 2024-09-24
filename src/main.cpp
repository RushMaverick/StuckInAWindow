#include <SFML/Graphics.hpp>
#include "../includes/Player.hpp"
#include <iostream>
#include <string> 

int main() {
	Player player;
	auto window = sf::RenderWindow{ { 500u, 500u }, "Help, I'm Stuck!" };

	window.setFramerateLimit(144);

	while (window.isOpen()){
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(player.getSprite());
		window.display();
	}
	return EXIT_SUCCESS;
}