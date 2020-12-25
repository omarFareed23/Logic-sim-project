#include "led.h"

led::led(const GraphicsInfo& r_GfxInfo, int r_FanOut):Gate(1 , r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void led::Draw(Output* pOut)
{
	pOut->DrawLED(m_GfxInfo);
}

int led::getInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();
}

void led::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

int led::getOutputPinStatus()
{
	return -1;
}
