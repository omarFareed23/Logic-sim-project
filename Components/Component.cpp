#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}


bool Component::ClickedHere(int x, int y)
{
	return false;
}

Component::Component()
{}

Component::~Component()
{}

