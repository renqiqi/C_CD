#include <stdio.h>
#include <math.h>
#include <time.h>
struct struc
{
	int a;
	int b;
	int c;
	int add;
	int grade;
};
int sj(int n)
{
	int t;
	//t=rand()%n;
	return t;
}
void ctm_i(struct struc *t)
/*����ָ��ṹ�����ͱ�����ָ�����*/
{    
    t->a=sj(1000);
    t->c=sj(4);
	if(t->c==1)
	{
         t->b=sj(1000-(t->a));
		 t->add=(t->a)+(t->b);
	}
	if(t->c==2)
	{
		t->b=sj((t->a)+1);
		t->add=(t->a)-(t->b);
	}
	if(t->c==3)
	{
        t->b=sj((t->a)+1);
		t->add=(t->a)*(t->b);
	}
	if(t->c==4)
	{
		t->b=sj(1000-(t->a));
		t->add=(t->a)/(t->b);
	}
t->grade=10;
}
void tcm_i(struct struc *t,int n)
{
	int ad;
	{
		printf("___________________________________________________\n");
		printf("���ڽ��е�%d��\n",n+1);
		printf("��������3�λ���\n");
		if(t->c==1)
			printf("%d+%d=",t->a,t->b);
		if(t->c==2)
			printf("%d-%d=",t->a,t->b);
		if(t->c==1)
			printf("%d*%d=",t->a,t->b);
		if(t->c==1)
			printf("%d/%d=",t->a,t->b);
		/*�������мӼ��˳�����*/
		scanf("%d",&ad);
		if(ad==t->add)
		{
			t->grade=10;
			printf("��ȷ����10�֣�\n");
		}
		else
		{
            printf("�����ˣ�����2�λ��ᣬ���ͣ�\n");
            if(t->c==1)
			printf("%d+%d=",t->a,t->b);
		    if(t->c==2)
			printf("%d-%d=",t->a,t->b);
		    if(t->c==1)
			printf("%d*%d=",t->a,t->b);
		    if(t->c==1)
			printf("%d/%d=",t->a,t->b);
			scanf("%d",&ad);
			if(ad==t->add)
			{
				t->grade=8;
				printf("��ȷ����8�֣�\n");
			}
			else
			{
                printf("�����ˣ�����1�λ��ᣬ���ͣ�\n");
				if(t->c==1)
			    printf("%d+%d=",t->a,t->b);
		        if(t->c==2)
			    printf("%d-%d=",t->a,t->b);
		        if(t->c==1)
			    printf("%d*%d=",t->a,t->b);
		        if(t->c==1)
		      	printf("%d/%d=",t->a,t->b);
				scanf("%d",&ad);
				if(ad==t->add)
				{
					t->grade=6;
					printf("��ȷ����6�֣�\n");
				}
				else
				{
					t->grade=0;
					printf("��ȷ����%d\n",t->add);
					printf("�ǳ��ź������ˣ�������һ��\n");
				}
			}
		}
}
}
void main ()
{
	int i;
	int j;
	int score=0;
	int Time;
	int end;
	int start;
	start=clock();
	printf("%d",start);
	struct struc test[10];
	//srand((unsigned)time(NULL));
	/*���������������Ŀ*/
	printf("_____________________________________________________________\n");
	printf("_______________________Сѧ����ѧCAIϵͳ_____________________\n");
	printf("_____________________________________________________________\n");
	for(i=0;i<10;i++)
	{
		ctm_i(&test[i]);
		for(j=0;j<i;j++)
			if(test[i].a==test[j].a && test[i].b==test[j].b && test[i].c==test[j].c)
				ctm_i(&test[i]);
	}
	for(i=0;i<10;i++)
		tcm_i(&test[i],i);
	printf("��ѧ���Խ�����\n");
	for(i=0;i<10;i++)
		score=score+test[i].grade;
	if(score>=90)
	{
		printf("����\n");
	}
	else if(score>=75)
	{
		printf("����\n");
	}
	else if(score>=60)
	{
		printf("�ϸ�\n");
	}
	else
	{
		printf("���ϸ�\n");
	}
	printf("score=%d\n",score);
	/*ͬѧ�ش�����ķ����͵ȼ�*/
    if(score>=60)
	{
		printf("��ϲ��ͨ�����ԣ�\n");
	}
	else
	{
		printf("���ź���δ��ͨ�����ԣ���������\n");
		for(i=0;i<10;i++)
		{
			ctm_i(&test[i]);
		    for(j=0;j<i;j++)
			    if(test[i].a==test[j].a && test[i].b==test[j].b && test[i].c==test[j].c)
				     ctm_i(&test[i]);
		}
	    for(i=0;i<10;i++)
		    tcm_i(&test[i],i);
		}
	end=clock();
	printf("%d\n",end);
	Time=(end-start)/CLK_TCK;
    printf("%d=(%d-%d)/%d\n",Time,end,start,CLK_TCK);
	printf("%d\n",end-start);
	printf("��ʱ��%d��\n",Time);
	/*ͬѧ�ش���������ʱ��*/
}


		

