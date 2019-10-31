# ConsoleEngine

一个用于开发Windows Console窗口程序的WindowsAPI封装

ConsoleController请参见我的这个版本库：[ConsoleController](https://github.com/Tomotopieces/ConsoleController)

    namespace ConsoleController
      ├class Mouse                    //鼠标
      ├class Cursor                   //光标（与鼠标不同）
      ├class Screen                   //窗口
      └class Character                //字符（调整打印颜色）
    namespace ConsoleEngine
      ├class ConsoleObject            //物品（主要的基类
        ├class ConsoleText            //文本
          └class ConsoleCharacter     //字符
        ├class ConsoleImage           //图片（由字符构成）
        ├class ConsoleButton          //按钮
        └class ConsoleScene           //场景（由ConsoleObject构成)
      ├class ConsolePoint2D           //二维坐标点
      ├class ConsoleMap2D             //二维地图
      └function Rand                  //随机函数
