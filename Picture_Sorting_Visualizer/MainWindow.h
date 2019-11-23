#pragma once
#include <SFML/Graphics.hpp>

class MainWindow
{
public:
	MainWindow(std::uint32_t width, std::uint32_t height, const std::string& title);
	~MainWindow() = default;
public:
	void display();
private:
	sf::RenderWindow m_window;
};

