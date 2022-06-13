#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
#define 理综 L_Score
#define 文综 W_Score
#define Max_Size 1000
class Student    //总学生类（基类）,可分为两子类（理科生，文科生）
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
class Liberal_Art_Students :public Student          //文科生
{
public:
	int W_Score = 0;    //文综成绩
	void InputMessage();
	void Add();
	void Search();
	void Show();
	void Change();
	void Delete();
	void Preserve();
};
class Science_Students :public Student             //理科生
{
public:
	int L_Score = 0;    //理综成绩
	void InputMessage();
	void Add();
	void Search();
	void Show();
	void Change();
	void Delete();
	void Preserve();
};
void ShowInterface();//主交互界面

