#include "BotPaddle.h"

BotPaddle::BotPaddle(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(5, 40));
	m_Shape.setFillColor(sf::Color::White);
	m_Shape.setOutlineColor(sf::Color::Red);
	m_Shape.setOutlineThickness(5);

	m_Shape.setPosition(m_Position);
}

sf::FloatRect BotPaddle::getPosition() {

	return m_Shape.getGlobalBounds();
}

sf::RectangleShape BotPaddle::getShape() {

	return m_Shape;
}

void BotPaddle::ballUp() {

	m_MovingUp = true;
}

void BotPaddle::ballDown() {

	m_MovingDown = true;
}

void BotPaddle::ballStopUp() {

	m_MovingUp = false;
}

void BotPaddle::ballStopDown() {

	m_MovingDown = false;
}

void BotPaddle::update(sf::Time dt) {

	if (m_MovingUp) {

		m_Position.y -= m_Speed * dt.asSeconds();
	}

	if (m_MovingDown) {

		m_Position.y += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}


