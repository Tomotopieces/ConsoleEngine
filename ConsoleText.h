#pragma once
#include "ConsoleObject.h"
using namespace ConsoleController;

enum RenderMode {
	Normal,					//��ͨ
	HorizontallyCentered,	//ˮƽ����
	VerticallyCentered		//��ֱ����
};

class ConsoleText	//����̨�ı�
	: public ConsoleObject
{
protected:
	int backColor = black;		//����ɫ
	int foreColor = light;		//��ɫ
	RenderMode currentMode = Normal; //��ǰ���ģʽ
private:
	explicit ConsoleText();
public:
	ConsoleText(const std::string Text);
	ConsoleText(const std::string Text, const ConsolePoint2D Position);
	ConsoleText(const std::string Text, const int x, const int y);
	ConsoleText(const ConsoleText& text2);
	ConsoleText(ConsoleText&& text2);
	virtual const ConsoleText& operator=(const ConsoleText& text2);

	const int getBackColor()const;
	const int getForeColor()const;

	//������ɫ
	const ConsoleText& setBackColor(const int color2);
	const ConsoleText& setForeColor(const int color2);

	const ConsoleText& setRenderMode(const RenderMode newMode);

	virtual const ConsoleText& render()const;	//����
};