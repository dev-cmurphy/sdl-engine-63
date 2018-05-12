#pragma once
#include "Component.h"
#include "TextureManager.h"

class VisualComponent : public Component {
	friend class VisualSystem;

public:
	VisualComponent();
	VisualComponent(std::string textureID);
	virtual ~VisualComponent();
	
protected:
	std::string m_textureID;
	virtual void Activate();
	virtual void Deactivate();

	// data
};