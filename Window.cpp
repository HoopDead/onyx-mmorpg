#include "Window.hpp"


Window::Window(const std::string& windowName)
	: m_window(sf::VideoMode(1920, 1080), windowName) {
	m_window.setVerticalSyncEnabled(true);
	Log("Called Window Constructor");
}

void Window::Update() {

	sf::Event event;

	if (m_window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
	}

	sf::Vector2u windowSize = { 1920, 1080 };
	m_window.setSize(windowSize);


}

const sf::View& Window::GetView() const {
	return m_window.getView();
}

sf::Vector2f Window::GetCenter() const {
	return m_window.getView().getCenter();
}

sf::FloatRect Window::GetViewSpace() const {
	const sf::View& view = GetView();
	const sf::Vector2f& viewCenter = view.getCenter();
	const sf::Vector2f viewSize = view.getSize();

	const sf::Vector2f viewSizeHalf(viewSize.x / 2.f, viewSize.y / 2.f);
	const sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);

	return viewSpace;
}

void Window::SetView(const sf::View& view) {
	m_window.setView(view);
}

void Window::BeginDraw() {
	m_window.clear(sf::Color::Black);
}

void Window::Draw(const sf::Drawable& drawable) {
	m_window.draw(drawable);
}

void Window::EndDraw() {
	m_window.display();
}

bool Window::IsOpen() const {
	return m_window.isOpen();
}

Window::~Window() {
	Log("Called Window Destructor");
}