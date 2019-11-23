#include "stdafx.h"
#include "Application.h"

Application::Application() {
	m_pictureTexture.loadFromImage(m_array.getPictureBuffer());
	m_pictureQuad.setSize({ (float)m_array.getPictureBuffer().getSize().x, (float)m_array.getPictureBuffer().getSize().y });
	m_pictureQuad.setOrigin(m_pictureQuad.getSize().x / 2, m_pictureQuad.getSize().y / 2);
	m_pictureQuad.setPosition(400, 300);
}

void Application::onEvent(const sf::Event& event) {
	
}

void Application::render(sf::RenderTarget& renderer) {
	updatePicture();
	renderer.draw(m_pictureQuad);
}

void Application::updatePicture() {
	m_pictureTexture.loadFromImage(m_array.getPictureBuffer());
	m_pictureQuad.setTexture(&m_pictureTexture);
}