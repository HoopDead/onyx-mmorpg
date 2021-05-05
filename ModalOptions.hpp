#pragma once

#include "ModalTemplate.hpp"
#include "Window.hpp"
#include "TextTemplate.hpp"
#include "TextCollection.hpp"
#include "TextAction_ExitOptionsModal.hpp"

class ModalOptions : public ModalTemplate {
public:

	ModalOptions();

	void Initialise() override;

	void Update(float deltaTime) override;

	void Draw(Window& window) override;

	void Activate();

	void Deactivate();

	bool IsActive() const;

	~ModalOptions();

private:

	bool m_isActive;
	sf::RectangleShape m_modalRect;
	TextCollection m_textCollection;
	std::shared_ptr<TextTemplate> ExitModalButton;

};