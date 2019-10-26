#pragma once
#include "ConsoleObject.h"
using namespace ConsoleFunction;

class ConsoleText
	: public ConsoleObject
{
private:
	int backColor = black;		//����ɫ
	int foreColor = light;		//��ɫ

	explicit ConsoleText();
public:
	ConsoleText(const std::string Text);
	ConsoleText(const ConsoleText& text2);
	ConsoleText(ConsoleText&& text2);
	const ConsoleText& operator=(const ConsoleText& text2);

	const ConsoleText& setBackColor(int color2);
	const ConsoleText& setForeColor(int color2);

	enum RenderMode {
		Normal,					//��ͨ
		HorizontallyCentered,	//ˮƽ����
		VerticallyCentered
	};	//��ֱ����
	const ConsoleText& Render(RenderMode renderMode = Normal)const;
};