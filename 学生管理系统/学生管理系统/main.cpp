/****************************************************************************************************************
*        开发日志
* 1.找到整齐输入输出到文件里的方法，无顺序插入，显示功能块可用读取文件的方法显示。
* 2.修改和删除可利用查找完成
* 3.怎样从外部读取已完成的数据文件并保存到容器中
* 4.运用多文件编程为什么会出现 1>源1.obj :error LNK2005 : "int n" (?n@@3HA)已经在 main.obj 中定义
* 5.可采用链表编写（还可以用链表与线性表结合完成）
*
****************************************************************************************************************/
#include"student_sys.h"
fstream Out_File;       //用于写入数据到文本
int main()
{
	ShowInterface();    //调出交互界面
	int n = 0;          //选择功能
	int infer = 0;      //控制整个系统的结束
	Student* a = new Science_Students;      //通过虚基类的指针来访问子类对象
	Student* b = new Liberal_Art_Students;  //通过虚基类的指针来访问子类对象
	while (infer == 0)
	{
		cout << "请选择功能：";
		cin >> n;
		switch (n)
		{
		case 0:  //清屏
			system("cls");
			ShowInterface();
			break;
		case 1:   //添加学生
			int x, k;
			do                           //通过循环来实现继续添加，用 x 变量控制结束
			{
				cout << "请输入要插入的学生类型。  理科生(1) / 文科生(2)" << endl;
				cin >> k;
				if (k == 1)   
				{
					a->Add();            //通过子类指针来调用添加函数
				}
				else if (k == 2)
				{
					b->Add();
				}
				cout << "是否继续添加？  是(1) / 否(0)" << endl;
				cin >> x;
				if (x == 0)
				{
					system("cls");
					ShowInterface();
				}
			} while (x != 0);
			break;
		case 2:  //查找
			cout << "请输入查找学生类型。 理科生(1) / 文科生(2)" << endl;
			int key;
			cin >> key;
			if (key == 1)        
			{
				a->Search();             //通过子类指针来调用查找函数
			}
			else if (key == 2)   
			{
				b->Search();
			}
			break;
		case 3:  //显示学生
			a->Show();                  //通过子类指针来调用显示函数
			cout << "----------------------------------------------------------------------------------------------------------" << endl;
			b->Show();
			break;
		case 4:  //修改
			cout << "请输入要修改的学生类型。 理科生(1) / 文科生(2)" << endl;
			int key2;
			cin >> key2;
			if (key2 == 1)       
			{
				a->Change();            //通过子类指针来调用修改函数
			}
			else if (key2 == 2)   
			{
				b->Change();
			}
			break;
		case 5:  //删除
			cout << "请输入要删除的学生类型。 理科生(1) / 文科生(2)" << endl;
			int key3;
			cin >> key3;
			if (key3 == 1)       
			{
				a->Delete();           //通过子类指针来调用删除函数
			}
			else if (key3 == 2)  
			{
				b->Delete();
			}
			break;
		case 6:  //保存
			Out_File.open("StudentSystem.txt", ios::out);
			a->Preserve();            //通过子类指针来调用保存函数
			b->Preserve();
			cout << "保存成功！" << endl;
			Out_File.close();
			break;
		case 7:   //退出功能    
			cout << "确认退出吗?  Yes(1)/No(0)" << endl;
			cin >> infer;
			if (infer == 1)
			{
				exit(1);
			}
			else
			{
				system("cls");
				ShowInterface();
			}
		}
	}
}