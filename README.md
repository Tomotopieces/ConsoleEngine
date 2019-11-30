# ConsoleEngine

一个用于开发Windows Console窗口程序的WindowsAPI封装

ConsoleController请参见我的这个版本库：[ConsoleController](https://github.com/Tomotopieces/ConsoleController)

    namespace ConsoleController
      ├class MOUSE                    //鼠标
      ├class CURSOR                   //光标（与鼠标不同）
      ├class SCREEN                   //窗口
      └class CHARACTER                //字符（调整打印颜色）
    namespace ConsoleEngine
      ├class ConsoleObject            //物品（主要的基类
        ├class ConsoleText            //文本
          ├class ConsoleButton        //按钮
          └class ConsoleCharacter     //字符
        ├class ConsoleImage           //图片（由字符构成）
        └class ConsoleScene           //场景（由ConsoleObject构成)
      ├class ConsolePoint2D           //二维坐标点
      ├class ConsoleMap2D             //二维地图
      └function Rand                  //随机函数

#### 范例
    /* main.cpp */
    #include "ConsoleEngine.h"
    #include <string>
    using namespace ConsoleEngine;

    int main() {
    	Screen.setTitle("Title");
    	Screen.setSize(64, 32);
    	Screen.hideScrollBar();
    	auto temp = Screen.setBackgroundColor(blue);
    	Screen.clean();
    	Cursor.hide();

	    ConsoleScene cScene;

	    ConsoleText cText("Text");
	    cText.setPosition(0, 2);
	    cText.setBackColor(blue);
	    cText.setForeColor(white + light);
	    cText.setRenderMode(HorizontallyCentered);
	    cScene.addObject(&cText);

	    RawImage image =
	    {
		    " $ $I",
		    "$ $$M",
		    " $ $A",
		    "$ $$G",
		    " $ $E"
	    };
	    ConsoleImage cImage(image);
	    cImage.setAllColor(red, cyan + light);
	    cImage.setPosition(29, 20);
	    cScene.addObject(&cImage);

	    while (true)
		    cScene.updateState().render();
	    return 0;
    }

#### 实际效果
![ConsoleEngine](https://wx1.sinaimg.cn/mw690/007xMrgKgy1g8ipqvtk16j30f00fu3z8.jpg)
