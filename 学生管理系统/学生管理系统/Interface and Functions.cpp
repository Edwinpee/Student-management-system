#pragma once
#include"student_sys.h"
extern fstream Out_File;  //д������
vector<Science_Students> A;
Science_Students* p = new Science_Students[Max_Size];
vector<Liberal_Art_Students> B;
Liberal_Art_Students* q = new Liberal_Art_Students[Max_Size];
void ShowInterface()     //����������
{
	cout << "          *******************************************************" << endl
		<< "          *                                                     *" << endl
		<< "          *                    ѧ������ϵͳ                     *" << endl
		<< "          *                                                     *" << endl
		<< "          *******************************************************" << endl
		<< "          *                                                     *" << endl
		<< "          *                   ��0�������Ļ                     *" << endl
		<< "          *                   ��1�����ѧ����Ϣ                 *" << endl
		<< "          *                   ��2����ѯѧ����Ϣ                 *" << endl
		<< "          *                   ��3����ʾѧ����Ϣ                 *" << endl
		<< "          *                   ��4���޸�ѧ����Ϣ                 *" << endl
		<< "          *                   ��5��ɾ��ѧ����Ϣ                 *" << endl
		<< "          *                   ��6������ѧ����Ϣ                 *" << endl
		<< "          *                   ��7���˳�ϵͳ                     *" << endl
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
	cout << "��������Ҫ�������ѧ����";
	cin >> e;
	cout << "��ֱ������ѧ������,ѧ��,���ģ���ѧ��Ӣ������۳ɼ�(�ÿո��������)" << endl;
	for (int i = 0; i < e; i++)
	{
		q[r].InputMessage();           //����InputMessage����
		for (int j = 0; j < r; j++)
		{
			if (q[j].Num == q[r].Num)  //�ҵ�ѧ���ظ���infBΪ��
			{
				infB = 1;
			}
		}
		if (infB)                      //ѧ���ظ�����������  
		{ 
			cerr << "�����ظ�������ʧ��" << endl;
			break;
		}
		else
		{
			B.push_back(q[r]);        //����Ϣ¼��vector����
		}
		r++;
	}
	infB = 0;                         //����֮��ļ������
}
void Liberal_Art_Students::Search()                                                     //��ѧ�Ų���
{
	bool inf2B = 0;
	string serch2;
	cout << "���������ѧ��ѧ�ţ�";
	cin >> serch2;
	for (vector<Liberal_Art_Students>::iterator it = B.begin(); it != B.end(); it++)    //����ͨ��������������vector������Ҳ����for(int i = 0 ; i < B.size() ; i++) ��ʵ��
	{
		if (it->Num == serch2)                                                          //���ҵ������ѧ��
		{
			cout << "���ҳɹ�" << endl;
			inf2B = 1;
		}
		if (inf2B == 1)                                                                //���ҳɹ��������������
		{
			cout << setw(14) <<  left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����" 
				<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
			cout << setw(14) <<  left << it->Name << setw(14) <<  left << it->Num << setw(14) <<  left << it->Chinese 
				<< setw(14) <<  left << it->Math << setw(14) <<  left << it->English << setw(14) <<  left << it->W_Score << endl;
			break;
		}
	}
	if (inf2B == 0)                                                                    //û�ҵ�������
	{
		cerr << "���޴���" << endl;
	}
	inf2B = 0;
}
void Liberal_Art_Students::Show()
{
	cout << setw(14) << left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����" 
		<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
	for (int i = 0; i < B.size(); i++)      //����vector�����������
	{
		cout << setw(14) <<  left << B[i].Name << setw(14) <<  left << B[i].Num << setw(14) <<  left << B[i].Chinese
			<< setw(14) <<  left << B[i].Math << setw(14) <<  left << B[i].English << setw(14) <<  left << B[i].W_Score << endl;
	}
}
void Liberal_Art_Students::Change()
{
	bool inf4B = 0;
	string serch2;
	cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	cin >> serch2;
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i].Num == serch2)                 //����ѧ�Ų��ҳɹ�
		{
			cout << "���ҳɹ�" << endl;
			inf4B = 1;
		}
		if (inf4B == 1)                        //���ҳɹ������ѧ��������Ϣ
		{
			cout << setw(14) << left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����"
				<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
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
				cout << "��������Ҫ�޸ĵ���Ϣ��(0)�˳��޸� / (1)���� / (2)ѧ�� / (3)���� / (4)��ѧ / (5)Ӣ�� / (6)����" << endl;
				cin >> key4;
				switch (key4)
				{
				case 1:
					cout << "�����������֣�";
					cin >> N_Name2;
					B[i].Name = N_Name2;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 2:
					cout << "��������ѧ�ţ�";
					cin >> N_Num2;
					for (int j = 0; j < B.size(); j++)
					{
						if (N_Num2 == B[j].Num)                   //�޸ĵ�ѧ��������ѧ����ѧ���ظ�
						{
							inf4 = 1;
						}
					}
					if (inf4 != 1)
					{
						B[i].Num = N_Num2;
						cout << "�޸ĳɹ���" << endl;
					}
					else                                         //ѧ���ظ�������ִ���޸�
					{
						cout << "ѧ���ظ�����ִ���޸ģ�" << endl;
					}
					inf4 = 0;
					break;
				case 3:
					cout << "�����������ĳɼ���";
					cin >> N_Chinese2;
					B[i].Chinese = N_Chinese2;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 4:
					cout << "����������ѧ�ɼ���";
					cin >> N_Math2;
					B[i].Math = N_Math2;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 5:
					cout << "��������Ӣ��ɼ���";
					cin >> N_English2;
					B[i].English = N_English2;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 6:
					cout << "�����������۳ɼ���";
					cin >> N_W_score;
					B[i].W_Score = N_W_score;
					cout << "�޸ĳɹ���" << endl;
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
		cout << "���޴���" << endl;
	}
	inf4B = 0;
}
void Liberal_Art_Students::Delete()
{
	bool inf5B = 0;
	string serch5;
	cout << "������Ҫɾ����ѧ��ѧ�ţ�";
	cin >> serch5;
	for (int i = 0; i < B.size(); i++)
	{
		if (B[i].Num == serch5)                              //����ѧ�Ų��ҳɹ�
		{
			cout << "���ҳɹ�" << endl;
			inf5B = 1;
		}
		if (inf5B == 1)                                     //���ҳɹ���ʾ��ѧ��������Ϣ
		{ 
			cout << setw(14) <<  left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����" << setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
			cout << setw(14) <<  left << B[i].Name << setw(14) <<  left << B[i].Num << setw(14) <<  left << B[i].Chinese << setw(14) <<  left << B[i].Math << setw(14) <<  left << B[i].English << setw(14) <<  left << B[i].W_Score << endl;
			cout << "�Ƿ�ȷ��ɾ���� (1)�� / (2)��" << endl;
			int key5;
			cin >> key5;
			if (key5 == 1)
			{
				for (int j = i; j < B.size() - 1; j++)
				{
					B[j] = B[j + 1];
				}
				B.pop_back();
				cout << "ɾ���ɹ�" << endl;
			}
			else if (key5 == 2)
			{
				break;
			}
		}
	}
	if (inf5B == 0)                                       //û�ҵ�
	{
		cerr << "���޴���" << endl;
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
	cout << "��������Ҫ�������ѧ����";
	cin >> e;
	cout << "��ֱ������ѧ������,ѧ��,���ģ���ѧ��Ӣ������۳ɼ�(�ÿո��������)" << endl;
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
			cerr << "�����ظ�������ʧ��" << endl;
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
	cout << "���������ѧ��ѧ�ţ�";
	cin >> serch1;
	for (vector<Science_Students>::iterator it = A.begin(); it != A.end(); it++)
	{
		if (it->Num == serch1)
		{
			cout << "���ҳɹ�" << endl;
			inf2A = 1;
		}
		if (inf2A == 1)
		{
			cout << setw(14) <<  left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����" 
				<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
			cout << setw(14) <<  left << it->Name << setw(14) <<  left << it->Num << setw(14) <<  left << it->Chinese 
				<< setw(14) <<  left << it->Math << setw(14) <<  left << it->English << setw(14) <<  left << it->L_Score << endl;
			break;
		}
	}
	if (inf2A == 0)
	{
		cout << "���޴���" << endl;
	}
	inf2A = 0;
}
void Science_Students::Show()
{
	cout << setw(14) <<  left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����" 
		<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
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
	cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	cin >> serch1;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].Num == serch1)
		{
			cout << "���ҳɹ�" << endl;
			inf4A = 1;
		}
		if (inf4A == 1)
		{
			cout << setw(14) <<  left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����"
				<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
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
				cout << "��������Ҫ�޸ĵ���Ϣ��(0)�˳��޸� / (1)���� / (2)ѧ�� / (3)���� / (4)��ѧ / (5)Ӣ�� / (6)����" << endl;
				cin >> key3;
				switch (key3)
				{
				case 1:
					cout << "�����������֣�";
					cin >> N_Name;
					A[i].Name = N_Name;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 2:
					cout << "��������ѧ�ţ�";
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
						cout << "�޸ĳɹ���" << endl;
					}
					else
					{
						cout << "ѧ���ظ�����ִ���޸ģ�" << endl;
					}
					inf4 = 0;
					break;
				case 3:
					cout << "�����������ĳɼ���";
					cin >> N_Chinese;
					A[i].Chinese = N_Chinese;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 4:
					cout << "����������ѧ�ɼ���";
					cin >> N_Math;
					A[i].Math = N_Math;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 5:
					cout << "��������Ӣ��ɼ���";
					cin >> N_English;
					A[i].English = N_English;
					cout << "�޸ĳɹ���" << endl;
					break;
				case 6:
					cout << "�����������۳ɼ���";
					cin >> N_L_score;
					A[i].L_Score = N_L_score;
					cout << "�޸ĳɹ���" << endl;
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
		cout << "���޴���" << endl;
	}
	inf4A = 0;
}
void Science_Students::Delete()
{
	bool inf5A = 0;
	string serch3;
	cout << "������Ҫɾ����ѧ��ѧ�ţ�";
	cin >> serch3;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].Num == serch3)
		{
			cout << "���ҳɹ�" << endl;
			inf5A = 1;
		}
		if (inf5A == 1)
		{
			cout << setw(14) <<  left << "����" << setw(14) <<  left << "ѧ��" << setw(14) <<  left << "����"
				<< setw(14) <<  left << "��ѧ" << setw(14) <<  left << "Ӣ��" << setw(14) <<  left << "����" << endl;
			cout << setw(14) <<  left << A[i].Name << setw(14) <<  left << A[i].Num << setw(14) <<  left << A[i].Chinese 
				<< setw(14) <<  left << A[i].Math << setw(14) <<  left << A[i].English << setw(14) <<  left << A[i].L_Score << endl;
			cout << "�Ƿ�ȷ��ɾ���� (1)�� / (2)��" << endl;
			int key4;
			cin >> key4;
			if (key4 == 1)
			{
				for (int j = i; j < A.size() - 1; j++)
				{
					A[j] = A[j + 1];
				}
				A.pop_back();
				cout << "ɾ���ɹ�" << endl;
			}
			else if (key4 == 2)
			{
				break;
			}
		}
	}
	if (inf5A == 0)
	{
		cout << "���޴���" << endl;
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
