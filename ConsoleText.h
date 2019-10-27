#pragma once
#include "ConsoleObject.h"
using namespace ConsoleController;

class ConsoleText	//����̨�ı�
	: public ConsoleObject
{
public:
	enum RenderMode {
		Normal,					//��ͨ
		HorizontallyCentered,	//ˮƽ����
		VerticallyCentered		//��ֱ����
	};
private:
	int backColor = black;		//����ɫ
	int foreColor = light;		//��ɫ
	RenderMode currentMode = Normal; //��ǰ���ģʽ

	explicit ConsoleText();
public:
	ConsoleText(const std::string Text);
	ConsoleText(const std::string Text, const ConsolePoint2D Position);
	ConsoleText(const std::string Text, const int x, const int y);
	ConsoleText(const ConsoleText& text2);
	ConsoleText(ConsoleText&& text2);
	const ConsoleText& operator=(const ConsoleText& text2);

	//������ɫ
	const ConsoleText& setBackColor(const int color2);
	const ConsoleText& setForeColor(const int color2);
	const ConsoleText& setRenderMode(const RenderMode newMode);

	const ConsoleText& render()const;	//����
};