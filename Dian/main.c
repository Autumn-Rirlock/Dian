#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Definition.h"
#include<windows.h>

/*定义货物信息*/
struct MerchandiseInformation Merchandise[CounterNumber];
struct MerchandiseInformation Merchandise_choose;
struct MerchandiseInformation Merchandise_history;
struct MerchandiseInformation Merchandise_input_history[CounterNumber];

char str[4] = "end";
char str_back[5] = "back";
char * judgement = NULL;//判断
char judgementend[100];
int lastpoint = -1;//上次购买货物的信息
int N;

int main(void) {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	printf("按下Enter开始购买把~\n");
	judgement = (char*)malloc(100);
	/*传入商品信息*/
	for (int i = 0; i < CounterNumber; i++) {
		InputMerchandise(&(Merchandise[i]), &judge_end, &count,&(Merchandise_input_history[i]),&judge_back);
		if (judge_end == 1) {
			N = i;
			if (count != 0) {
				printf("您已经摆放了%d个物品！", count);
				break;
			}
			else if (count == 0 && judge_back != 1) {
				printf("您还没摆放呢...");
				i--;
			}
		}
		if (judge_back == 1) {
			CleanStruct(&Merchandise[i]);
			i--;
			count--;
		}
	}

	/*购买物品*/
	for (;;) {
		/*清空缓冲区*/
		while (getchar() != '\n') {
			continue;
		}
		/*结束购买*/
		printf("按Enter继续，输入back撤回，输入end结束:");
		fgets(judgement, MAX_NAME_LENGTH,stdin);
		judgement[strcspn(judgement, "\n")] = '\0';
		if (strcmp(judgement, str) == 0) {
			if (summary != 0) {
				printf("物品的总价是：%d\n", summary);
				Paymoney(summary);
				while (getchar() != '\n') {
					continue;
				}
				fgets(judgementend, MAX_NAME_LENGTH, stdin);
				judgementend[strcspn(judgementend, "\n")] = '\0';
				exit(0);
			}
			else {
				printf("您未购买任何产品\n");
			}
		}
		/*撤回购买*/
		else if (strcmp(judgement, str_back) == 0) {
			if (lastpoint != -1) {
				summary = sumary_history;
				Merchandise[lastpoint].Amount += number;
				printf("您已经成功撤回上次购买操作~\n");
				continue;
			}
			else if(lastpoint == -1){
				printf("您还未执行任何操作\n");
			}
		}
		/*选择物品*/
		else {
			printf("请输入你要购买的商品的名称 所在的通道 与购买的数量\n");
			scanf("%s %d %d", Merchandise_choose.name, &Merchandise_choose.counter, &number);
			for (int i = 0; i < N; i++) {
				if (strcmp(Merchandise_choose.name, Merchandise[i].name) == 0 && Merchandise_choose.counter == Merchandise[i].counter) {
					judge = 0;

					sumary_history = summary;//记录上次购买的总金额

					lastpoint = i;//记录上次购买的货物信息

					summary += Merchandise[i].price * number;

					Merchandise_history.Amount = Merchandise[i].Amount;//记录未购买时候的数量

					Merchandise[i].Amount -= number;
					
					/*防止货物不足*/
					if (Merchandise[i].Amount < 0) {
						printf("货物不足哦，请重新选择\n");
						Merchandise[i].Amount += number;
						break;
					}
					else if (Merchandise[i].Amount >= 0) {
						printf("目前花费：%d\n", summary);
						break;
					}
				}
				else {
					judge = 1;
				}
			}
			if (judge == 1) {
				printf("请仔细核对名称与编号哦~\n");
			}
		}
	}

	system("pause");
	return 0;
}