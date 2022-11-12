#include "framework.h"

Camera& Camera::Get() {
	return m_hInstance;
}

const sf::View& Camera::GetView() {
	return m_view;
}

void Camera::Update(const float& dt) {
	m_elapsedTime += dt;
	while (m_elapsedTime > m_updateTime) {
		ApplayEffect();
		m_elapsedTime -= m_updateTime;
	}
}

void Camera::ApplayEffect() {
	if (m_duration > 0.0f) {
		m_duration -= 0.1f;

		//m_view.setCenter(sf::Vector2f(WNDSIZE_W, WNDSIZE_H) / 2.0f + (sf::Vector2f) GetPlayer());

		m_currentPosition++;
		if (m_currentPosition > 9)
			m_currentPosition = 0;

		if (m_duration <= 0.0f)
			m_duration = 0.0f;
	}

	if (m_duration == 0.0f) {
		m_view.setCenter(sf::Vector2f(WNDSIZE_W, WNDSIZE_H) / 2.0f);
	}
}

void Camera::InitView() {
	m_view.setSize(sf::Vector2f(WNDSIZE_W, WNDSIZE_H));
	m_view.setCenter(sf::Vector2f(WNDSIZE_W, WNDSIZE_H) / 2.0f);
}

Camera Camera::m_hInstance;