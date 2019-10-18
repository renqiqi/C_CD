#include<stdio.h>
#include <stdlib.h>
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
/*定义随机函数*/

{ 
	int t;
    t=rand()%n;
    return t;
}

void ctm_i(struct struc *t)
/*定义指向结构体类型变量的指针变量*/
             
{ 
	t->a=sj(1000);
    t->c=sj(4);
    if(t->c==0) 
	{ 
		t->b=sj(1000-(t->a));
        t->add=(t->a)+(t->b);
	}
    if(t->c==1)
	{ 
		t->b=sj((t->a)+1);
        t->add=(t->a)-(t->b);
	}
	if(t->c==2)
	{
        t->b=sj((t->a)+1);
        t->add=(t->a)*(t->b);
	}
    if(t->c==3)
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
    printf("===================================\n");
    printf("现在进行第%d题\n",n+1); 
    printf("本题你总共有三次机会，结果请保留整数\n");
    if(t->c==0) 
		printf("%d+%d=",t->a,t->b);
    if(t->c==1) 
		printf("%d-%d=",t->a,t->b);
    if(t->c==2) 
		printf("%d*%d=",t->a,t->b);
    if(t->c==3) 
		printf("%d/%d=",t->a,t->b);
    /*用来进行加减乘除运算*/
    scanf("%d",&ad);
    if(ad==t->add)
    {
        t->grade=10;
	    printf("完全正确，你非常聪明!加10分\n");
    }
    else
	{ 
        printf("你答错了，继续努力!\n");
        if(t->c==0) 
			printf("%d+%d=",t->a,t->b);
        if(t->c==1) 
			printf("%d-%d=",t->a,t->b);
        if(t->c==2) 
			printf("%d*%d=",t->a,t->b);
        if(t->c==3)
			printf("%d/%d=",t->a,t->b);
        scanf("%d",&ad);
        if(ad==t->add)
        {
            t->grade=8;
            printf("答对了，你很棒!加8分\n");
        }
        else 
		{ 
            printf("你答错了，继续努力!\n");
            if(t->c==0) 
				printf("%d+%d=",t->a,t->b);
            if(t->c==1) 
				printf("%d-%d=",t->a,t->b);
            if(t->c==2) 
				printf("%d*%d=",t->a,t->b);
            if(t->c==3) 
				printf("%d/%d=",t->a,t->b);
            scanf("%d",&ad);
            if(ad==t->add)
            {
                 t->grade=6;
                 printf("答对了，祝贺你!加6分\n");
            }
            else 
			{
                 t->grade=0;
                 printf("非常遗憾你又答错了，请继续做下一题.\n");
                 printf("正确答案为%d\n",t->add);
			}
		 }
	}
}
}

void main()

{
    int i,j,score=0;
    int Time,end,start;
    start=clock(); 
    printf("%d",start); 
    struct struc test[10];
    srand((unsigned)time(NULL));
    /*C语言随机函数,产生题目*/	
    printf("_______________________________________________________________________________\n");
    printf("_______________________________小学生数学CAI系统_______________________________\n");
    printf("_______________________________________________________________________________\n");
    for(i=0;i<10;i++)
	{ 
        ctm_i(&test[i]);
        for(j=0;j<i;j++)
        if(test[i].a==test[j].a&&test[i].b==test[j].b&&test[i].c==test[j].c)
        ctm_i(&test[i]);
	}	 
    for(i=0;i<10;i++)
        tcm_i(&test[i],i);
        printf("小学生四则运算测试结束!\n");
    for(i=0;i<10;i++)
        score=score+test[i].grade;
    if(score>=90 )
	{
        printf("优秀!\n"); 
	}
    else if (score>=75 )
	{
	    printf("良好!\n ");
	}
    else if (score>=60) 
	{
	    printf("合格!\n");
	}
    else  
	{
	    printf("不合格!\n");
	}
    printf("score=%d\n",score);
    /*小学生回答问题的分数和等级*/ 
    if(score>=60)
	{
        printf("祝贺你!\n");
	}
    else
	{
        printf("继续努力,请重做!\n");
        for(i=0;i<10;i++)
		{ 
            ctm_i(&test[i]);
            for(j=0;j<i;j++)
            if(test[i].a==test[j].a&&test[i].b==test[j].b&&test[i].c==test[j].c)
            ctm_i(&test[i]);
		}	 
        for(i=0;i<10;i++)
            tcm_i(&test[i],i);
	}
    end = clock(); 
    printf("%d\n",end); 
    Time = (end-start)/CLK_TCK; 
    printf("%d=(%d-%d)/%d\n",Time,end,start,CLK_TCK); 
    printf("%d\n",end-start); 
    printf("用时:%d秒\n",Time); 
    /*小学生回答问题的时间*/
}

