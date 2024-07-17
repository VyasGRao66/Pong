#pragma once
#include <SFML/Graphics.hpp>
class BotPaddle
{
private:
	sf::RectangleShape m_Shape;
	sf::Vector2f m_Position;

	float m_Speed = 400.0f;

	bool m_MovingUp = false;
	bool m_MovingDown = false;

public:
	BotPaddle(float startX, float startY);

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void ballUp();

	void ballDown();
	
	void ballStopUp();

	void ballStopDown();

	void update(sf::Time dt);

};

