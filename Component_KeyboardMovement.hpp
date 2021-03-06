#pragma once

#include "Component.hpp"
#include "Input.hpp"
#include "Logs.hpp"
#include "Component_Velocity.hpp"
#include "Object.hpp"

class Component_KeyboardMovement : public Component {

public:
	/*
	* Constructor of Keyboard Movement component
	* Intialises all members of class and sets owner of this Component
	* @Param: Object* owner - pointer to owner of an object
	* @Return: -
	*/
	Component_KeyboardMovement(Object* owner);

	/*
	* SetInput Method
	* Sets a Input for Component
	* @Param: Input* input - pointer to Input class
	* @Return: -
	*/
	void SetInput(std::shared_ptr<Input> input);

	/*
	* SetMovementSpeed Method
	* Sets a movement speed for player
	* @Param: int moveSpeed - value of speed to set for player
	* @Return: -
	*/
	void SetMovementSpeed(int moveSpeed);

	/*
	* Update Method - overriden from Compontent.hpp
	* Updates the movement speed of player and calls for transform method of owner object
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime) override;

	/*
	* Awake method overriden from Component class
	* Initialises m_animation for Component
	* @Param: -
	* @Return: -
	*/
	void Awake() override;

	/*
	* Destructor of Component Keyboard Movement
	* Created only for test purposes
	*/
	~Component_KeyboardMovement();

private:
	int m_moveSpeed;
	std::shared_ptr<Input> m_input;
	std::shared_ptr<Component_Velocity> m_velocity;
};