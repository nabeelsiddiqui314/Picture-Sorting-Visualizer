#pragma once
#include<SFML/Graphics.hpp>

class Application
{
public:
	Application();
	~Application() = default;
public:
	void onEvent(const sf::Event& event);
	void render(sf::RenderTarget& renderer);
private:
	sf::RectangleShape m_testShape;
};

