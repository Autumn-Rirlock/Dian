#include <stdio.h>
#include "Definition.h"
#include <string.h>

char judgement_end[100];//判断
char str_end[4] = "end";
char str_back2[5] = "back";

//货物输入函数
void InputMerchandise(struct MerchandiseInformation * Merchandise,int * judge,int * count, struct MerchandiseInformation * Merchandise_input_history , int * judge_back) {
	*judge_back = 0;
	/*清空缓冲区*/
	while (getchar() != '\n') {
		continue;
	}
	printf("按Enter继续,输入back撤回上一步操作，输入end结束摆放:");
	fgets(judgement_end, MAX_NAME_LENGTH, stdin);
	judgement_end[strcspn(judgement_end, "\n")] = '\0';
	/*结束购买*/
	if (strcmp(judgement_end, str_end) == 0) {
		*judge = 1;
	}
	/*撤销上一步操作*/
	else if (strcmp(judgement_end, str_back2) == 0 && *count == 0) {
		printf("您还未放置任何东西哦~\n");
		*judge_back = 1;
	}
	else if (strcmp(judgement_end, str_back2) == 0 && *count != 0) {
		printf("您已经成功撤回上次摆放操作\n");
		*judge_back = 1;
	}
	else {
		printf("请输入商品信息\n");
		printf("名称 通道 价格 数量\n");
		printf("请用大写字母作为商品名称\n\n");
		scanf("%s %d %d %d", Merchandise->name, &(Merchandise->counter), &(Merchandise->price), &(Merchandise->Amount));

		/*确保输入的商品名称是大写字母*/
		if (strlen(Merchandise->name) == 1) {
			if (Merchandise->name[0] >= 'A' && Merchandise->name[0] <= 'Z') {
				printf("货物的名词是:%s\n处在的通道是:%d\n它的价格是:%d\n它的数量是:%d\n\n",
					Merchandise->name, Merchandise->counter, Merchandise->price, Merchandise->Amount);
				Merchandise_input_history = Merchandise;
				(*count)++;
			}
			else {
				printf("请输入大写字母作为商品名称！\n");
				InputMerchandise(&Merchandise,judge,count, Merchandise_input_history, judge_back);
			}
		}
		else {
			printf("请输入大写字母作为商品名称！\n");
			InputMerchandise(&Merchandise,judge, count, Merchandise_input_history, judge_back);
		}
	}
}

void Paymoney(int sum) {
	printf("请付钱哦，目前只支持支付1元，2元和5元~\n");
	for (;;) {
		printf("您支付：");
		scanf("%d", &k);
		if (k == 1 || k == 2 || k == 5) {
			money += k;
		}
		else {
			printf("您的输入有无，请重新输入：");
		}
		if (money == sum) {
			printf("购买成功\n");
			return 0;
		}
		else if (money > sum) {
			check = money - sum;
			printf("找您 %d 元",check);
			return 0;
		}
	}
}

void CleanStruct(struct MerchandiseInformation* info) {
	/*清空字符串*/
	memset(info->name, 0, sizeof(info->name));
	/*其他成员*/
	info->counter = 0;
	info->price = 0;
	info->Amount = 0;
}
