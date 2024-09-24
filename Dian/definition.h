#ifndef DEFINITION_H
#define DEFINITION_H

//货柜的数量为5
#define CounterNumber 5
//名字的输入最长为100
#define NameNumber 100
#define MAX_NAME_LENGTH 100

//声明货物的信息
struct MerchandiseInformation {
	char name[NameNumber];
	int counter;
	int price;
	int Amount;
};

//声明购买货物时需要使用的变量
int counter_choose;
int Amount_choose;
//声明普通变量
int number;//购买物品的数量
int summary;//购买物品的总价
int sumary_history;//记录上次购买
int judge;//判断
int judge_end;
int judge_back;
int count;//计数
int k;//粗存输入的钱的变量
int money;//付款
int check;//找零
char* expectedInput;//判断是否购买

//函数的声明
void InputMerchandise(); 
void MerchandiseChoose();
void Paymoney();
#endif 