
#include "BUFFER.h"

buffer::buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut):Gate(1 ,r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void buffer::Operate()
{
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
}

void buffer::Draw(Output* pOut)
{
	pOut->DrawBUFF(m_GfxInfo);
}

int buffer::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int buffer::GetInputPinStatus()
{
	return m_InputPins[0].getStatus();
}

void buffer::setInputPinStatus( STATUS s)
{
	m_InputPins[0].setStatus(s);
}
