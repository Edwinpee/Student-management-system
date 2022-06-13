#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
#define ���� L_Score
#define ���� W_Score
#define Max_Size 1000
class Student    //��ѧ���ࣨ���ࣩ,�ɷ�Ϊ�����ࣨ��������Ŀ�����
{
public:
	string Name;
	string Num;
	int Chinese = 0;
	int Math = 0;
	int English = 0;
	virtual void InputMessage() = 0;
	virtual void Add() = 0;
	virtual void Search() = 0;
	virtual void Show() = 0;
	virtual void Change() = 0;
	virtual void Delete() = 0;
	virtual void Preserve() = 0;
};
class Liberal_Art_Students :public Student          //�Ŀ���
{
public:
	int W_Score = 0;    //���۳ɼ�
	void InputMessage();
	void Add();
	void Search();
	void Show();
	void Change();
	void Delete();
	void Preserve();
};
class Science_Students :public Student             //�����
{
public:
	int L_Score = 0;    //���۳ɼ�
	void InputMessage();
	void Add();
	void Search();
	void Show();
	void Change();
	void Delete();
	void Preserve();
};
void ShowInterface();//����������

