#include "../includes/Utils.hpp"

float	lengthVector2(sf::Vector2f &vec) {
	float length = sqrt(vec.x * vec.x + vec.y * vec.y);
	return length;
}; 

sf::Vector2f normalizeVector2(sf::Vector2f &vec) {
	sf::Vector2f normalizedVec = vec / lengthVector2(vec);
	return normalizedVec;
};