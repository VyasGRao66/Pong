#pragma once
#include <SFML/Graphics.hpp>

class PlayerPaddle
{
private:
	sf::RectangleShape m_Shape;
	sf::Vector2f m_Position;

	float m_Speed = 500.0f;

	bool m_MovingUp = false;
	bool m_MovingDown = false;

public:
	PlayerPaddle(float startX, float startY);

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveUp();
	void moveDown();

	void stopUp();
	void stopDown();

	void update(sf::Time dt);

};

