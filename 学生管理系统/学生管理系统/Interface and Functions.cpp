#pragma once
#include"student_sys.h"
extern fstream Out_File;  //写入数据
vector<Science_Students> A;
Science_Students* p = new Science_Students[Max_Size];
vector<Liberal_Art_Students> B;
Liberal_Art_Students* q = new Liberal_Art_Students[Max_Size];
void ShowInterface()     //主交互界面
{
	cout << "          *******************************************************" << endl
		<< "          *                                                     *" << endl
		<< "          *                    学生管理系统                     *" << endl
		<< "          *                                                     *" << endl
		<< "          *******************************************************" << endl
		<< "          *                                                     *" << endl
		<< "          *                   【0】清空屏幕                     *" << endl
		<< "          *                   【1】添加学生信息                 *" << endl
		<< "          *                   【2】查询学生信息                 *" << endl
		<< "          *                   【3】显示学生信息                 *" << endl
		<< "          *                   【4】修改学生信息                 *" << endl
		<< "          *                   【5】删除学生信息                 *" << endl
		<< "          *                   【6】保存学生信息                 *" << endl
		<< "          *                   【7】退出系统                     *" << endl
		<< "          *                                                     *" << endl
		<< "          *******************************************************" << endl;
}

void Liberal_Art_Students::InputMessage()
{
	cin >> Name >> Num >> Chinese >> Math >> English >> W_Score;
}
void Liberal_Art_Students::Add()
{
	bool infB = 0;
	int e, r = 0;
	cout << "请输入需要插入多少学生：";
	cin >> e;
	cout << "请分别输入该学生姓名,学号,语文，数学，英语和文综成绩(用空格号作划分)" << endl;
	for (int i = 0; i < e; i++)
	{
		q[r].InputMessage();           //调用InputMessage函数
		for (int j = 0; j < r; j++)
		{
			if (q[j].Num == q[r].Num)  //找到学号重复则infB为真
			{
				infB = 1;
			}
		}
		if (infB)                      //学号重复报错，不插入  
		{ 
			cerr << "出现重复，插入失败" << endl;
			break;
		}
		else
		{
			B.push_back(q[r]);        //将信息录入vector容器
		}
		r++;
	}
	infB = 0;                         //用于之后的继续添加
}
void Liberal_Art_Students::Search()                                                     //按学号查找
{
	bool inf2B = 0;
	string serch2;
	cout << "请输入查找学生学号：";
	cin >> serch2;
	for (vector<Liberal_Art_Students>::iterator it = B.begin(); it != B.end(); it++)    //这是通过迭代器来访问vector容器，也可用for(int i = 0 ; i < B.size() ; i++) 来实现
	{
		if (it->Num == serch2)                                                          //查找到输入的学号
		{
			cout << "查找成功" << endl;
			inf2B = 1;
		}
		if (inf2B == 1)                                                                //查找成功，将其所有输出
		{
			cout << setw(14) <<  left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文" 
				<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "文综" << endl;
			cout << setw(14) <<  left << it->Name << setw(14) <<  left << it->Num << setw(14) <<  left << it->Chinese 
				<< setw(14) <<  left << it->Math << setw(14) <<  left << it->English << setw(14) <<  left << it->W_Score << endl;
			break;
		}
	}
	if (inf2B == 0)                                                                    //没找到，报错
	{
		cerr << "查无此人" << endl;
	}
	inf2B = 0;
}
void Liberal_Art_Students::Show()
{
	cout << setw(14) << left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文" 
		<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "文综" << endl;
	for (int i = 0; i < B.size(); i++)      //遍历vector容器输出数据
	{
		cout << setw(14) <<  left << B[i].Name << setw(14) <<  left << B[i].Num << setw(14) <<  left << B[i].Chinese
			<< setw(14) <<  left << B[i].Math << setw(14) <<  left << B[i].English << setw(14) <<  left << B[i].W_Score << endl;
	}
}
void Liberal_Art_Students::Change()
{
	bool inf4B = 0;
	string serch2;
	cout << "请输入要修改的学生学号：";
	cin >> serch2;
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i].Num == serch2)                 //输入学号查找成功
		{
			cout << "查找成功" << endl;
			inf4B = 1;
		}
		if (inf4B == 1)                        //查找成功输出该学生所有信息
		{
			cout << setw(14) << left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文"
				<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "文综" << endl;
			cout << setw(14) <<  left << B[i].Name << setw(14) <<  left << B[i].Num << setw(14) <<  left << B[i].Chinese 
				<< setw(14) <<  left << B[i].Math << setw(14) <<  left << B[i].English << setw(14) <<  left << B[i].W_Score << endl;
			bool inf3 = 1;
			bool inf4 = 0;
			while (inf3)
			{
				int key4;
				string N_Name2;
				string N_Num2;
				int N_Chinese2 = 0;
				int N_Math2 = 0;
				int N_English2 = 0;
				int N_W_score = 0;
				cout << "请输入需要修改的信息：(0)退出修改 / (1)姓名 / (2)学号 / (3)语文 / (4)数学 / (5)英语 / (6)理综" << endl;
				cin >> key4;
				switch (key4)
				{
				case 1:
					cout << "请输入新名字：";
					cin >> N_Name2;
					B[i].Name = N_Name2;
					cout << "修改成功！" << endl;
					break;
				case 2:
					cout << "请输入新学号：";
					cin >> N_Num2;
					for (int j = 0; j < B.size(); j++)
					{
						if (N_Num2 == B[j].Num)                   //修改的学号与其他学生的学号重复
						{
							inf4 = 1;
						}
					}
					if (inf4 != 1)
					{
						B[i].Num = N_Num2;
						cout << "修改成功！" << endl;
					}
					else                                         //学号重复报错，不执行修改
					{
						cout << "学号重复！不执行修改！" << endl;
					}
					inf4 = 0;
					break;
				case 3:
					cout << "请输入新语文成绩：";
					cin >> N_Chinese2;
					B[i].Chinese = N_Chinese2;
					cout << "修改成功！" << endl;
					break;
				case 4:
					cout << "请输入新数学成绩：";
					cin >> N_Math2;
					B[i].Math = N_Math2;
					cout << "修改成功！" << endl;
					break;
				case 5:
					cout << "请输入新英语成绩：";
					cin >> N_English2;
					B[i].English = N_English2;
					cout << "修改成功！" << endl;
					break;
				case 6:
					cout << "请输入新文综成绩：";
					cin >> N_W_score;
					B[i].W_Score = N_W_score;
					cout << "修改成功！" << endl;
					break;
				default:
					inf3 = 0;
					break;
				}
			}
			break;
		}
	}
	if (inf4B == 0)
	{
		cout << "查无此人" << endl;
	}
	inf4B = 0;
}
void Liberal_Art_Students::Delete()
{
	bool inf5B = 0;
	string serch5;
	cout << "请输入要删除的学生学号：";
	cin >> serch5;
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i].Num == serch5)                              //输入学号查找成功
		{
			cout << "查找成功" << endl;
			inf5B = 1;
		}
		if (inf5B == 1)                                     //查找成功显示该学生所有信息
		{ 
			cout << setw(14) <<  left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文" << setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "文综" << endl;
			cout << setw(14) <<  left << B[i].Name << setw(14) <<  left << B[i].Num << setw(14) <<  left << B[i].Chinese << setw(14) <<  left << B[i].Math << setw(14) <<  left << B[i].English << setw(14) <<  left << B[i].W_Score << endl;
			cout << "是否确定删除？ (1)是 / (2)否" << endl;
			int key5;
			cin >> key5;
			if (key5 == 1)
			{
				for (int j = i; j < B.size() - 1; j++)
				{
					B[j] = B[j + 1];
				}
				B.pop_back();
				cout << "删除成功" << endl;
			}
			else if (key5 == 2)
			{
				break;
			}
		}
	}
	if (inf5B == 0)                                       //没找到
	{
		cerr << "查无此人" << endl;
	}
	inf5B = 0;
}
void Liberal_Art_Students::Preserve()
{
	for (int i = 0; i < B.size(); i++)
	{
		Out_File << setw(14) <<  left << B[i].Name << setw(14) <<  left << B[i].Num << setw(14) <<  left << B[i].Chinese 
			<< setw(14) <<  left << B[i].Math << setw(14) <<  left << B[i].English << setw(14) <<  left << B[i].W_Score << endl;
	}
}


void Science_Students::InputMessage()
{
	cin >> Name >> Num >> Chinese >> Math >> English >> L_Score;
}
void Science_Students::Add()
{
	bool infA = 0;
	int e = 0, l = 0;
	cout << "请输入需要插入多少学生：";
	cin >> e;
	cout << "请分别输入该学生姓名,学号,语文，数学，英语和理综成绩(用空格号作划分)" << endl;
	for (int i = 0; i < e; i++)
	{
		p[l].InputMessage();
		for (int j = 0; j < l; j++)
		{
			if (p[j].Num == p[l].Num)
			{
				infA = 1;
			}
		}
		if (infA)
		{
			cerr << "出现重复，插入失败" << endl;
			break;
		}
		else
		{
			A.push_back(p[l]);
		}
		l++;
	}
	infA = 0;
}
void Science_Students::Search()
{
	bool  inf2A = 0;
	string serch1;
	cout << "请输入查找学生学号：";
	cin >> serch1;
	for (vector<Science_Students>::iterator it = A.begin(); it != A.end(); it++)
	{
		if (it->Num == serch1)
		{
			cout << "查找成功" << endl;
			inf2A = 1;
		}
		if (inf2A == 1)
		{
			cout << setw(14) <<  left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文" 
				<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "理综" << endl;
			cout << setw(14) <<  left << it->Name << setw(14) <<  left << it->Num << setw(14) <<  left << it->Chinese 
				<< setw(14) <<  left << it->Math << setw(14) <<  left << it->English << setw(14) <<  left << it->L_Score << endl;
			break;
		}
	}
	if (inf2A == 0)
	{
		cout << "查无此人" << endl;
	}
	inf2A = 0;
}
void Science_Students::Show()
{
	cout << setw(14) <<  left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文" 
		<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "理综" << endl;
	for (int i = 0; i < A.size(); i++)
	{
		cout << setw(14) <<  left << A[i].Name << setw(14) <<  left << A[i].Num << setw(14) <<  left << A[i].Chinese
			<< setw(14) <<  left << A[i].Math << setw(14) <<  left << A[i].English << setw(14) <<  left << A[i].L_Score << endl;
	}
}
void Science_Students::Change()
{
	bool inf4A = 0;
	string serch1;
	cout << "请输入要修改的学生学号：";
	cin >> serch1;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].Num == serch1)
		{
			cout << "查找成功" << endl;
			inf4A = 1;
		}
		if (inf4A == 1)
		{
			cout << setw(14) <<  left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文"
				<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "理综" << endl;
			cout << setw(14) <<  left << A[i].Name << setw(14) <<  left << A[i].Num << setw(14) <<  left << A[i].Chinese
				<< setw(14) <<  left << A[i].Math << setw(14) <<  left << A[i].English << setw(14) <<  left << A[i].L_Score << endl;
			bool inf3 = 1;
			bool inf4 = 0;
			while (inf3)
			{
				int key3;
				string N_Name;
				string N_Num;
				int N_Chinese = 0;
				int N_Math = 0;
				int N_English = 0;
				int N_L_score = 0;
				cout << "请输入需要修改的信息：(0)退出修改 / (1)姓名 / (2)学号 / (3)语文 / (4)数学 / (5)英语 / (6)理综" << endl;
				cin >> key3;
				switch (key3)
				{
				case 1:
					cout << "请输入新名字：";
					cin >> N_Name;
					A[i].Name = N_Name;
					cout << "修改成功！" << endl;
					break;
				case 2:
					cout << "请输入新学号：";
					cin >> N_Num;
					for (int j = 0; j < A.size(); j++)
					{
						if (N_Num == A[j].Num)
						{
							inf4 = 1;
						}
					}
					if (inf4 != 1)
					{
						A[i].Num = N_Num;
						cout << "修改成功！" << endl;
					}
					else
					{
						cout << "学号重复！不执行修改！" << endl;
					}
					inf4 = 0;
					break;
				case 3:
					cout << "请输入新语文成绩：";
					cin >> N_Chinese;
					A[i].Chinese = N_Chinese;
					cout << "修改成功！" << endl;
					break;
				case 4:
					cout << "请输入新数学成绩：";
					cin >> N_Math;
					A[i].Math = N_Math;
					cout << "修改成功！" << endl;
					break;
				case 5:
					cout << "请输入新英语成绩：";
					cin >> N_English;
					A[i].English = N_English;
					cout << "修改成功！" << endl;
					break;
				case 6:
					cout << "请输入新理综成绩：";
					cin >> N_L_score;
					A[i].L_Score = N_L_score;
					cout << "修改成功！" << endl;
					break;
				default:
					inf3 = 0;
					break;
				}
			}
			break;
		}
	}
	if (inf4A == 0)
	{
		cout << "查无此人" << endl;
	}
	inf4A = 0;
}
void Science_Students::Delete()
{
	bool inf5A = 0;
	string serch3;
	cout << "请输入要删除的学生学号：";
	cin >> serch3;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].Num == serch3)
		{
			cout << "查找成功" << endl;
			inf5A = 1;
		}
		if (inf5A == 1)
		{
			cout << setw(14) <<  left << "姓名" << setw(14) <<  left << "学号" << setw(14) <<  left << "语文"
				<< setw(14) <<  left << "数学" << setw(14) <<  left << "英语" << setw(14) <<  left << "理综" << endl;
			cout << setw(14) <<  left << A[i].Name << setw(14) <<  left << A[i].Num << setw(14) <<  left << A[i].Chinese 
				<< setw(14) <<  left << A[i].Math << setw(14) <<  left << A[i].English << setw(14) <<  left << A[i].L_Score << endl;
			cout << "是否确定删除？ (1)是 / (2)否" << endl;
			int key4;
			cin >> key4;
			if (key4 == 1)
			{
				for (int j = i; j < A.size() - 1; j++)
				{
					A[j] = A[j + 1];
				}
				A.pop_back();
				cout << "删除成功" << endl;
			}
			else if (key4 == 2)
			{
				break;
			}
		}
	}
	if (inf5A == 0)
	{
		cout << "查无此人" << endl;
	}
}
void Science_Students::Preserve()
{
	for (int i = 0; i < A.size(); i++)
	{
		Out_File << setw(14) <<  left << A[i].Name << setw(14) <<  left << A[i].Num << setw(14) <<  left << A[i].Chinese
			<< setw(14) <<  left << A[i].Math << setw(14) <<  left << A[i].English << setw(14) <<  left << A[i].L_Score << endl;
	}
}
