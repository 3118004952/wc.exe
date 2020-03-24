
#include <iostream>
#include "wc.h"

int main()
{
	int num;
	char getcommand[256];//保存命令
	while (1)
	{
		std::cout << "wc.exe ";
		std::cin.getline(getcommand, 256);
		num = 0;
		while (num < 256 && getcommand[num] != '\0')
		{
			if (getcommand[num] == '-')//取得命令的开头
			{
				if (getcommand[num + 1] == 'r') //退出程序
					return 0;
				if (getcommand[num + 1] == 'c' || getcommand[num + 1] == 'w' || getcommand[num + 1] == 'l') {}//判断指令是否正确
				else
				{
					std::cout << "指令不存在！\n";
					break;
				}
				int i = num + 2;
				int j = 0;
				char save[256];
				std::ifstream fr;
				while (getcommand[i] == ' ')//判断指令格式是否正确
				{
					i++;
				}
				if (i == num + 2)//说明指令后面没有跟空格
				{
					std::cout << "输入错误！\n";
					break;
				}
				while (getcommand[i] != '\0')//取文件路径或名字
				{
					save[j++] = getcommand[i++];
				}
				save[j] = '\0';
				fr.open(save, std::ifstream::in);//打开文件
				if (!fr.is_open())
				{
					std::cout << "文件不存在！\n";
					break;
				}
				switch (getcommand[++num])
				{
				case 'c':
					std::cout << "字符数："<< characters(&fr)<<"\n";
					break;
				case 'w':
					std::cout << "词数：" << words(&fr) << "\n";
					break;
				case 'l':
					std::cout << "行数：" << lines(&fr) << "\n";
					break;
				default:
					break;
				}
			}
			else
			{
				if (getcommand[num] != ' ')//判断命令格式是否正确
					break;
			}
			num++;
		}
	}
}
