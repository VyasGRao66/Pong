#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(5, 40));
	m_Shape.setFillColor(sf::Color::White);
	m_Shape.setOutlineColor(sf::Color::Blue);
	m_Shape.setOutlineThickness(5);

	m_Shape.setPosition(m_Position);

}

sf::FloatRect PlayerPaddle::getPosition() {

	return m_Shape.getGlobalBounds();
}

sf::RectangleShape PlayerPaddle::getShape() {

	return m_Shape;
}

void PlayerPaddle::moveUp() {

	m_MovingUp = true;
}

void PlayerPaddle::moveDown() {

	m_MovingDown = true;
}

void PlayerPaddle::stopUp() {

	m_MovingUp = false;
}

void PlayerPaddle::stopDown() {

	m_MovingDown = false();
}

void PlayerPaddle::update(sf::Time dt) {

	if (m_MovingUp) {
		m_Position.y -= m_Speed * dt.asSeconds();
	}

	if (m_MovingDown) {

		m_Position.y += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}