/****************************************************************************************************************
*        ������־
* 1.�ҵ���������������ļ���ķ�������˳����룬��ʾ���ܿ���ö�ȡ�ļ��ķ�����ʾ��
* 2.�޸ĺ�ɾ�������ò������
* 3.�������ⲿ��ȡ����ɵ������ļ������浽������
* 4.���ö��ļ����Ϊʲô����� 1>Դ1.obj :error LNK2005 : "int n" (?n@@3HA)�Ѿ��� main.obj �ж���
* 5.�ɲ��������д�������������������Ա�����ɣ�
*
****************************************************************************************************************/
#include"student_sys.h"
fstream Out_File;       //����д�����ݵ��ı�
int main()
{
	ShowInterface();    //������������
	int n = 0;          //ѡ����
	int infer = 0;      //��������ϵͳ�Ľ���
	Student* a = new Science_Students;      //ͨ��������ָ���������������
	Student* b = new Liberal_Art_Students;  //ͨ��������ָ���������������
	while (infer == 0)
	{
		cout << "��ѡ���ܣ�";
		cin >> n;
		switch (n)
		{
		case 0:  //����
			system("cls");
			ShowInterface();
			break;
		case 1:   //���ѧ��
			int x, k;
			do                           //ͨ��ѭ����ʵ�ּ�����ӣ��� x �������ƽ���
			{
				cout << "������Ҫ�����ѧ�����͡�  �����(1) / �Ŀ���(2)" << endl;
				cin >> k;
				if (k == 1)   
				{
					a->Add();            //ͨ������ָ����������Ӻ���
				}
				else if (k == 2)
				{
					b->Add();
				}
				cout << "�Ƿ������ӣ�  ��(1) / ��(0)" << endl;
				cin >> x;
				if (x == 0)
				{
					system("cls");
					ShowInterface();
				}
			} while (x != 0);
			break;
		case 2:  //����
			cout << "���������ѧ�����͡� �����(1) / �Ŀ���(2)" << endl;
			int key;
			cin >> key;
			if (key == 1)        
			{
				a->Search();             //ͨ������ָ�������ò��Һ���
			}
			else if (key == 2)   
			{
				b->Search();
			}
			break;
		case 3:  //��ʾѧ��
			a->Show();                  //ͨ������ָ����������ʾ����
			cout << "----------------------------------------------------------------------------------------------------------" << endl;
			b->Show();
			break;
		case 4:  //�޸�
			cout << "������Ҫ�޸ĵ�ѧ�����͡� �����(1) / �Ŀ���(2)" << endl;
			int key2;
			cin >> key2;
			if (key2 == 1)       
			{
				a->Change();            //ͨ������ָ���������޸ĺ���
			}
			else if (key2 == 2)   
			{
				b->Change();
			}
			break;
		case 5:  //ɾ��
			cout << "������Ҫɾ����ѧ�����͡� �����(1) / �Ŀ���(2)" << endl;
			int key3;
			cin >> key3;
			if (key3 == 1)       
			{
				a->Delete();           //ͨ������ָ��������ɾ������
			}
			else if (key3 == 2)  
			{
				b->Delete();
			}
			break;
		case 6:  //����
			Out_File.open("StudentSystem.txt", ios::out);
			a->Preserve();            //ͨ������ָ�������ñ��溯��
			b->Preserve();
			cout << "����ɹ���" << endl;
			Out_File.close();
			break;
		case 7:   //�˳�����    
			cout << "ȷ���˳���?  Yes(1)/No(0)" << endl;
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