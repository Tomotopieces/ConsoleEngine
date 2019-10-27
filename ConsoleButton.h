#pragma once
#include "ConsoleObject.h"
#include <vector>
using namespace ConsoleController;

class ConsoleButton	//����̨��ť
	: public ConsoleObject
{
private:
	int defaultBackColor = light;		//Ĭ�� ����ɫ
	int defaultForeColor = black;		//Ĭ�� ��ɫ
	int inactiveBackColor = white;			//δ���� ����ɫ
	int inactiveForeColor = black;			//δ���� ��ɫ
	int activeBackColor = white + light;		//���� ����ɫ
	int activeForeColor = black;				//���� ��ɫ
	int unavailableDefaultBackColor = red;			//���ɼ��� Ĭ�� ����ɫ
	int unavailableDefaultForeColor = black;		//���ɼ��� Ĭ�� ��ɫ
	int unavailableInactiveBackColor = red + light;		//���ɼ��� δ���� ����ɫ
	int unavailableInactiveForeColor = black;			//���ɼ��� δ���� ��ɫ

	bool catchMouse = false;	//�Ƿ�׽�����
	bool available = true;		//�Ƿ�ɼ���
	bool active = false;		//�Ƿ��Ѽ���

	void(*activateFunction)();	//�����

	const bool CatchMouse();	//��׽�����

	explicit ConsoleButton();
public:
	ConsoleButton(const std::string Text);
	ConsoleButton(const std::string Text, const ConsolePoint2D Position);
	ConsoleButton(const std::string Text, const int x, const int y);
	ConsoleButton(const std::string Text, void(*ActivateFunction)());
	ConsoleButton(const ConsoleButton& option2);
	ConsoleButton(ConsoleButton&& option2);
	const ConsoleButton& operator=(const ConsoleButton& option2);

	//������ɫ
	const ConsoleButton& setDefaultBackColor(int color2);
	const ConsoleButton& setDefaultForeColor(int color2);
	const ConsoleButton& setInactiveBackColor(int color2);
	const ConsoleButton& setInactiveForeColor(int color2);
	const ConsoleButton& setActiveBackColor(int color2);
	const ConsoleButton& setActiveForeColor(int color2);
	const ConsoleButton& setUnavailableDefaultBackColor(int color2);
	const ConsoleButton& setUnavailableDefaultForeColor(int color2);
	const ConsoleButton& setUnavailableInactiveBackColor(int color2);
	const ConsoleButton& setUnavailableInactiveForeColor(int color2);

	const ConsoleButton& setAvailable(const bool Usable);
	const ConsoleButton& setActivateFunction(void(*ActivateFunction)());

	const ConsoleButton& updateState();	//���°�ť״̬

	const ConsoleButton& render()const;	//����
};