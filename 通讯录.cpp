#include<stdio.h>
#include<stdlib.h>
#include<string.h>]
struct line
{
	char major[10];//专业
	int number;//学号
	int phone_number;//电话
	char name[10];//姓名
	char address[60];//住址
	struct line* next;
};
struct line* AppendNode(struct line* head)
{
	system("cls");
	lable_add:
	struct line* p = NULL;
	struct line* p_head = head;
	char ch;
	p = (struct line*)malloc(sizeof(struct line));
	if (p == NULL)
	{
		printf("\t\t\t\t\t\t分配空间失败\n");
		exit(0);
	}
	printf("\t\t\t\t\t\t链表/节点建立成功，请输入数据\n");
	printf("\t\t\t\t\t\t请输入专业，姓名，住址\n");
	scanf("%10s", p->major);
	scanf("%10s", p->name);
	scanf("%6s", p->address);
	while ((ch = getchar()) != '\n');
	printf("\t\t\t\t\t\t请输入学号，电话\n");
	scanf("%d%d", &p->number, &p->phone_number);
	if (head == NULL)
	{
		head = p;
		p->next = NULL;
	}
	else
	{
		while (p_head->next != NULL)
		{
			p_head = p_head->next;
		}
		p_head->next = p;
		p->next = NULL;
		printf("\t\t\t\t\t\t信息录入成功\n");
	}
	printf("\t\t\t\t\t\t输入N\n继续录入，任意键返回菜单\n");
	ch = '\0';
	setbuf(stdin, NULL);
	ch = getchar();
	if (ch == 'n' || ch=='N') 
	{
		goto lable_add;
	}
	system("cls");
	return head;
}
struct line* DisplayLink(struct line* head)
{
	system("cls");
	struct line* p_head = head;
	if (head == NULL)
	{
		return head;
	}
	printf("\t\t\t\t\t\t当前系统内数据：\n");
	int i = 1;
	while (p_head != NULL)
	{
		printf("\t\t\t\t\t\t数据%d\n\t\t\t\t\t\t专业:%s\n\t\t\t\t\t\t学号:%d\n\t\t\t\t\t\t姓名:%s\n\t\t\t\t\t\t电话:%d\n\t\t\t\t\t\t住址:%s\n\n", i, p_head->major, p_head->number, p_head->name, p_head->phone_number, p_head->address);
		p_head = p_head->next;
		i++;
	}
	system("pause");
	system("cls");
	return head;
}
struct line* deleteNode(struct line* head, int number)
{
	system("cls");
	struct line* p = head;
	struct line* p_temp = NULL;
	if (head == NULL)
	{
		return head;
	}
	while (p != NULL && p->number != number)
	{
		p_temp = p;
		p = p->next;
	}
	if (p == NULL)
	{
		p = p_temp;
	}
	if (p->number == number)
	{
		if (p == head)
		{
			head = p->next;
		}
		else
		{
			p_temp->next = p->next;
		}
		free(p);
	}
	else
	{
		printf("\t\t\t\t\t\t系统中没有该信息\n");
	}
	return head;
}
struct line* SaveNode(struct line* head) 
{
	system("cls");
	struct line* p_temp = head;
	FILE* fh;
	fh = fopen("data.bin", "wb+");
	do
	{
		fwrite(p_temp, sizeof(struct line),1,fh);
		p_temp = p_temp->next;
	} while (p_temp !=NULL);
	printf("\t\t\t\t\t\t保存成功\n");
	system("pause");
	system("cls");
	return head;
}
struct line* ModiferNode(struct line* head, int number) 
{
	system("cls");
	struct line* p = head;
	struct line* p_temp = NULL;
	if (head == NULL)
	{
		return head;
	}
	while (p != NULL && p->number != number)
	{
		p_temp = p;
		p = p->next;
	}
	printf("请选择要修改的数据");
	while (1)
	{
		printf(当前信息);
	}
	system("pause");
	system("cls");
	return head;
}
int verify() 
{
	FILE* fh;
	int password,password_temp,i=0;
	fh = fopen("password.bin", "r+");
	if (fh==NULL)
	{
		fh= fopen("password.bin", "w+");
		lable1:
		printf("\t\t\t\t\t\t请设定纯数字的密码\n");
		scanf("%d", &password);
		printf("\t\t\t\t\t\t当前输入密码为：%d\n",password);
		printf("\t\t\t\t\t\t输入N\n重新设定密码，任意键确认");
		char ch = '\0';
		if ((ch = getchar()) == 'N' || (ch = getchar()) == 'n') 
		{
			password = 0;
			goto lable1;
		}
		fprintf(fh,"%d",password);
		system("cls");
		return 1;
	}
	else
	{
		printf("请输入密码：");
		fscanf(fh, "%d", &password);
		do
		{
			scanf("%d",&password_temp);
			i++;
			if (password != password_temp)
			{
				printf("\t\t\t\t\t\t密码错误%d次，错误五次后退出程序\n", i);
				printf("请输入密码:\n");
				if (i==5)
				{
					return 0;
				}
			}
		} while (password != password_temp);
		system("cls");
		return 1;
	}
}
int show_menu() 
{
	printf("\t\t\t\t\t\t请选择系统功能项:\n\t\t\t\t\t\ta.通讯录信息录入\n\t\t\t\t\t\tb.通讯录信息显示\n\t\t\t\t\t\tc.通讯录信息保存\n\t\t\t\t\t\td.通讯录信息删除\n\t\t\t\t\t\te.通讯录信息修改（要求先输入密码）\n\t\t\t\t\t\tf.通讯录信息查询\n\t\t\t\t\t\t(1)按学号查询\n\t\t\t\t\t\t(2)按姓名查询\n\t\t\t\t\t\t(3)按专业查询\n\t\t\t\t\t\t(4)按联系电话查询\n\t\t\t\t\t\tg.退出系统\n");
	return 0;
}
int main() 
{
	struct line* head = NULL;
	int number,a=0;
	a = verify();
	if (a != 1) 
	{
		exit(0);
	}
	char ch = '\0';
	while (1)
	{
		show_menu();
		setbuf(stdin, NULL);
		ch = getchar();
		switch (ch)
		{
		case 'a'://录入
			head = AppendNode(head);
			break;
		case 'b'://显示
			if (head == NULL)
			{
				printf("\t\t\t\t\t\t当前无信息\n");
				system("pause");
				system("cls");
				break;
			}
			DisplayLink(head);
			break;
		case 'c'://保存
			if (head == NULL)
			{
				printf("\t\t\t\t\t\t当前无信息\n");
				system("pause");
				system("cls");
				break;
			}
			SaveNode(head);
			break;
		case 'd'://删除
			printf("\t\t\t\t\t\t请输入需要删除的信息的学号\n");
			scanf("%d", &number);
			if (head == NULL)
			{
				printf("\t\t\t\t\t\t当前无信息\n");
				system("pause");
				system("cls");
				break;
			}
			head = deleteNode(head, number);
			break;
		case 'e'://修改
			a = 0;
			a = verify();
			if (a != 1) 
			{
				break;
			}
			printf("\t\t\t\t\t\t请输入待修改信息的学号\n");
			scanf("%d", &number);
			ModiferNode(head, number);
			break;
		case 'f'://查询

			break;
		case 'g':
			goto lable1;
			break;
		}
	}
	lable1:
	return 0;
}
