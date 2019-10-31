#pragma once
#include "ConsoleObject.h"
#include <vector>

namespace ConsoleEngine
{
	using namespace ConsoleController;
	class ConsoleButton
		: public ConsoleObject
	{
	private:
		//	color
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

		//	state
		bool catchMouse = false;	//�Ƿ�׽�����
		bool available = true;		//�Ƿ�ɼ���
		bool active = false;		//�Ƿ��Ѽ���

		//	action
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

		//	set color
		ConsoleButton& setDefaultBackColor(int Color);
		ConsoleButton& setDefaultForeColor(int Color);
		ConsoleButton& setInactiveBackColor(int Color);
		ConsoleButton& setInactiveForeColor(int Color);
		ConsoleButton& setActiveBackColor(int Color);
		ConsoleButton& setActiveForeColor(int Color);
		ConsoleButton& setUnavailableDefaultBackColor(int Color);
		ConsoleButton& setUnavailableDefaultForeColor(int Color);
		ConsoleButton& setUnavailableInactiveBackColor(int Color);
		ConsoleButton& setUnavailableInactiveForeColor(int Color);

		//	set state
		ConsoleButton& setAvailable(const bool Usable);
		ConsoleButton& setActivateFunction(void(*ActivateFunction)());

		//	others
		const ConsoleButton& updateState();	//���°�ť״̬
		const ConsoleButton& render()const;	//����
	};
}