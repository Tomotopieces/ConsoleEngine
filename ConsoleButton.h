#pragma once
#include "ConsoleFunc.h"
#include "Game.h"
#include <string>
#include <vector>
using namespace ConsoleFunction;

class ConsoleButton {
private:
	std::string name;

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

	void(*activateFunction)();
	ConsolePoint2D position = { 0,0 };

	const bool CatchMouse();

	explicit ConsoleButton();
public:
	ConsoleButton(const std::string Name);
	ConsoleButton(const std::string Name, void(*ActivateFunction)());
	ConsoleButton(const ConsoleButton& option2);
	ConsoleButton(ConsoleButton&& option2);
	const ConsoleButton& operator=(const ConsoleButton& option2);

	const std::string getName()const;
	const ConsolePoint2D getPosition()const;
	const ConsoleButton& setName(const std::string name2);

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
	const ConsoleButton& setPosition(const ConsolePoint2D position2);
	const ConsoleButton& setPosition(const int x, const int y);

	const bool updateState();	//update active

	const ConsoleButton& Render()const;
};

class ConsoleButtonList {
private:
	std::vector<ConsoleButton> buttonList;
public:
	ConsoleButtonList();

	ConsoleButtonList& AddButton(ConsoleButton newButton, const ConsolePoint2D position);
	ConsoleButtonList& AddButton(ConsoleButton newButton, const int x, const int y);

	const ConsoleButtonList& Render()const;
	const ConsoleButtonList& UpdateButtonState();
};