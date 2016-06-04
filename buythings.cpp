#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct product {
	int id;
	char name[10];
	int num;
	int sale;
	int cost;
};


int cal(struct product *produce, int i)
{
	int id, num;
	int money = 0;
	char keep = 'y';

	do
	{
		printf("�п�J�n�i��X�إ��<1�� 2�R>\n");
		scanf("%d", &i);

		if (i == 1)
		{
			printf("�п�J�n���ذӫ~id:\n");
			scanf("%d", &id);
			printf("�п�J�n��h�ֶq:\n");
			scanf("%d", &num);
			switch (id){
			case 1:
				if (num > produce[0].num)
				{
					printf("\n");
					printf("�ƶq����\n");
					printf("\n");
				}
				else
				{
					produce[0].num = produce[0].num - num;
					money += num*produce[0].sale;
				}
				break;
			case 2:
				if (num > produce[1].num)
				{
					printf("\n");
					printf("�ƶq����\n");
					printf("\n");
				}
				else
				{
					produce[1].num = produce[1].num - num;
					money += num*produce[1].sale;
				}
				break;
			case 3:
				if (num > produce[2].num)
				{
					printf("\n");
					printf("�ƶq����\n");
					printf("\n");
				}
				else
				{
					produce[2].num = produce[2].num - num;
					money += num*produce[2].sale;
				}
				break;
			}

		}
		else
		{
			printf("�п�J�n�R��ذӫ~id:\n");
			scanf("%d", &id);
			printf("�п�J�n�R�h�ֶq:\n");
			scanf("%d", &num);

			if (money < num*produce[id - 1].cost)
			{
				printf("\n");
				printf("====������====\n");
				printf("\n");
			}
			else
			{
				switch (id){
				case 1:
					produce[0].num = produce[0].num + num;
					money -= num*produce[0].cost;

					break;
				case 2:
					produce[1].num = produce[1].num + num;
					money -= num*produce[1].cost;
					break;
				case 3:
					produce[2].num = produce[2].num + num;
					money -= num*produce[2].cost;
					break;
				}
			}
			
		}
		printf("====�ثe�ӫ~�ƶq====\n%d.%s:%d\n%d.%s:%d\n%d.%s:%d\n", produce[0].id, produce[0].name, produce[0].num, produce[1].id, produce[1].name, produce[1].num, produce[2].id, produce[2].name, produce[2].num);
		printf("====�ثe�ӫ~���/����====\n%d.%s:%d/%d\n%d.%s:%d/%d\n%d.%s:%d/%d\n", produce[0].id, produce[0].name, produce[0].sale, produce[0].cost, produce[1].id, produce[1].name, produce[1].sale, produce[1].cost, produce[2].id, produce[2].name, produce[2].sale, produce[2].cost);
		printf("�ثe���J:%d\n", money);

		printf("�O�_�n�~����(y/n):\n");
		keep = getch();
		printf("%c\n", keep);
	} while (keep == 'y');
	
	
	return 0;
}

int main(void) {
	
	product *produce;
	produce = (product*)malloc(sizeof(product)* 3);
	produce[0].num = 50;
	produce[1].num = 60;
	produce[2].num = 30;
	strcpy(produce[0].name, "milk");
	strcpy(produce[1].name, "bread");
	strcpy(produce[2].name, "egg");
	produce[0].id = 1;
	produce[1].id = 2;
	produce[2].id = 3;
	printf("====�ثe�ӫ~�ƶq====\n%d.%s:%d\n%d.%s:%d\n%d.%s:%d\n", produce[0].id, produce[0].name, produce[0].num, produce[1].id, produce[1].name, produce[1].num, produce[2].id, produce[2].name, produce[2].num);
	produce[0].sale = 30;
	produce[1].sale = 70;
	produce[2].sale = 20;
	produce[0].cost = 20;
	produce[1].cost = 40;
	produce[2].cost = 10;
	printf("====�ثe�ӫ~���/����====\n%d.%s:%d/%d\n%d.%s:%d/%d\n%d.%s:%d/%d\n", produce[0].id, produce[0].name, produce[0].sale, produce[0].cost, produce[1].id, produce[1].name, produce[1].sale, produce[1].cost, produce[2].id, produce[2].name, produce[2].sale, produce[2].cost);

	int i = 0;
	cal(produce, i);
	system("pause");
	return 0;
}