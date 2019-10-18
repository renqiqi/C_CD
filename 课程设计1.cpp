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
/*定义指向结构体类型变量的指针变量*/
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
		printf("现在进行第%d题\n",n+1);
		printf("本题你有3次机会\n");
		if(t->c==1)
			printf("%d+%d=",t->a,t->b);
		if(t->c==2)
			printf("%d-%d=",t->a,t->b);
		if(t->c==1)
			printf("%d*%d=",t->a,t->b);
		if(t->c==1)
			printf("%d/%d=",t->a,t->b);
		/*用来进行加减乘除运算*/
		scanf("%d",&ad);
		if(ad==t->add)
		{
			t->grade=10;
			printf("正确，加10分！\n");
		}
		else
		{
            printf("你答错了，还有2次机会，加油！\n");
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
				printf("正确，加8分！\n");
			}
			else
			{
                printf("你答错了，还有1次机会，加油！\n");
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
					printf("正确，加6分！\n");
				}
				else
				{
					t->grade=0;
					printf("正确答案是%d\n",t->add);
					printf("非常遗憾你答错了，请做下一题\n");
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
	/*随机函数，产生题目*/
	printf("_____________________________________________________________\n");
	printf("_______________________小学生数学CAI系统_____________________\n");
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
	printf("数学测试结束！\n");
	for(i=0;i<10;i++)
		score=score+test[i].grade;
	if(score>=90)
	{
		printf("优秀\n");
	}
	else if(score>=75)
	{
		printf("良好\n");
	}
	else if(score>=60)
	{
		printf("合格\n");
	}
	else
	{
		printf("不合格\n");
	}
	printf("score=%d\n",score);
	/*同学回答问题的分数和等级*/
    if(score>=60)
	{
		printf("恭喜你通过测试！\n");
	}
	else
	{
		printf("很遗憾你未能通过测试，请重做！\n");
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
	printf("用时：%d秒\n",Time);
	/*同学回答问题所用时间*/
}


		

