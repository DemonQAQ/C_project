#include<stdio.h>
#include<stdlib.h>
#include<string.h>]
struct line
{
	char major[10];//רҵ
	int number;//ѧ��
	int phone_number;//�绰
	char name[10];//����
	char address[60];//סַ
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
		printf("\t\t\t\t\t\t����ռ�ʧ��\n");
		exit(0);
	}
	printf("\t\t\t\t\t\t����/�ڵ㽨���ɹ�������������\n");
	printf("\t\t\t\t\t\t������רҵ��������סַ\n");
	scanf("%10s", p->major);
	scanf("%10s", p->name);
	scanf("%6s", p->address);
	while ((ch = getchar()) != '\n');
	printf("\t\t\t\t\t\t������ѧ�ţ��绰\n");
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
		printf("\t\t\t\t\t\t��Ϣ¼��ɹ�\n");
	}
	printf("\t\t\t\t\t\t����N\n����¼�룬��������ز˵�\n");
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
	printf("\t\t\t\t\t\t��ǰϵͳ�����ݣ�\n");
	int i = 1;
	while (p_head != NULL)
	{
		printf("\t\t\t\t\t\t����%d\n\t\t\t\t\t\tרҵ:%s\n\t\t\t\t\t\tѧ��:%d\n\t\t\t\t\t\t����:%s\n\t\t\t\t\t\t�绰:%d\n\t\t\t\t\t\tסַ:%s\n\n", i, p_head->major, p_head->number, p_head->name, p_head->phone_number, p_head->address);
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
		printf("\t\t\t\t\t\tϵͳ��û�и���Ϣ\n");
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
	printf("\t\t\t\t\t\t����ɹ�\n");
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
	printf("��ѡ��Ҫ�޸ĵ�����");
	while (1)
	{
		printf(��ǰ��Ϣ);
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
		printf("\t\t\t\t\t\t���趨�����ֵ�����\n");
		scanf("%d", &password);
		printf("\t\t\t\t\t\t��ǰ��������Ϊ��%d\n",password);
		printf("\t\t\t\t\t\t����N\n�����趨���룬�����ȷ��");
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
		printf("���������룺");
		fscanf(fh, "%d", &password);
		do
		{
			scanf("%d",&password_temp);
			i++;
			if (password != password_temp)
			{
				printf("\t\t\t\t\t\t�������%d�Σ�������κ��˳�����\n", i);
				printf("����������:\n");
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
	printf("\t\t\t\t\t\t��ѡ��ϵͳ������:\n\t\t\t\t\t\ta.ͨѶ¼��Ϣ¼��\n\t\t\t\t\t\tb.ͨѶ¼��Ϣ��ʾ\n\t\t\t\t\t\tc.ͨѶ¼��Ϣ����\n\t\t\t\t\t\td.ͨѶ¼��Ϣɾ��\n\t\t\t\t\t\te.ͨѶ¼��Ϣ�޸ģ�Ҫ�����������룩\n\t\t\t\t\t\tf.ͨѶ¼��Ϣ��ѯ\n\t\t\t\t\t\t(1)��ѧ�Ų�ѯ\n\t\t\t\t\t\t(2)��������ѯ\n\t\t\t\t\t\t(3)��רҵ��ѯ\n\t\t\t\t\t\t(4)����ϵ�绰��ѯ\n\t\t\t\t\t\tg.�˳�ϵͳ\n");
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
		case 'a'://¼��
			head = AppendNode(head);
			break;
		case 'b'://��ʾ
			if (head == NULL)
			{
				printf("\t\t\t\t\t\t��ǰ����Ϣ\n");
				system("pause");
				system("cls");
				break;
			}
			DisplayLink(head);
			break;
		case 'c'://����
			if (head == NULL)
			{
				printf("\t\t\t\t\t\t��ǰ����Ϣ\n");
				system("pause");
				system("cls");
				break;
			}
			SaveNode(head);
			break;
		case 'd'://ɾ��
			printf("\t\t\t\t\t\t��������Ҫɾ������Ϣ��ѧ��\n");
			scanf("%d", &number);
			if (head == NULL)
			{
				printf("\t\t\t\t\t\t��ǰ����Ϣ\n");
				system("pause");
				system("cls");
				break;
			}
			head = deleteNode(head, number);
			break;
		case 'e'://�޸�
			a = 0;
			a = verify();
			if (a != 1) 
			{
				break;
			}
			printf("\t\t\t\t\t\t��������޸���Ϣ��ѧ��\n");
			scanf("%d", &number);
			ModiferNode(head, number);
			break;
		case 'f'://��ѯ

			break;
		case 'g':
			goto lable1;
			break;
		}
	}
	lable1:
	return 0;
}
