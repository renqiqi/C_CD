#include<stdio.h>
#include <stdlib.h>
#include <time.h> 
/*源文件*/ 
   
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
	/*系统随机函数随机出数字*/

    return t;
	/*返回上级数t*/

}

void ctm_i(struct struc *t)
/*定义指向结构体类型变量的指针变量*/
             
{ 
	t->a=sj(1000);
	/*调用随机函数，输出1000以内的数*/

    t->c=sj(4);
    if(t->c==0) 
	{ 
		t->b=sj(1000-(t->a));
        t->add=(t->a)+(t->b);
	}
	/*加法运算*/

    if(t->c==1)
	{ 
		t->b=sj((t->a)+1);
        t->add=(t->a)-(t->b);
	}
	/*减法运算*/

	if(t->c==2)
	{
        t->b=sj((t->a)+1);
        t->add=(t->a)*(t->b);
	}
    /*乘法运算*/

    if(t->c==3)
	{
        t->b=sj(1000-(t->a));
	    t->add=(t->a)/(t->b);
	}
	/*除法运算*/

    t->grade=10;
}

void tcm_i(struct struc *t,int n)

{ 
    int ad;
{
    printf("===================================\n");
	/*分开每道题的虚线*/

    printf("现在进行第%d题\n",n+1);
	/*提示同学正在进行第几题*/

    printf("本题你总共有三次机会,请保留整数\n");
	/*由于是小学生数学计算，结果保留整数部分*/

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
    /*判断结果是否正确*/

    {
        t->grade=10;
	    printf("完全正确，你非常聪明!加10分\n");
	    /*第一次回答正确，总分加10分*/
	}
	
    /*第一次回答错误后，进行第二次回答*/
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
	    /*判断结果是否正确*/

        {
            t->grade=8;
            printf("答对了，你很棒!加8分\n");
			/*第二次回答正确，总分加8分*/
		}

		/*第二次回答错误后，进行第三次回答*/
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
			/*判断结果是否正确*/

            {
                 t->grade=6;
                 printf("答对了，祝贺你!加6分\n");
				 /*第三次回答正确，总分加6分*/
            }

			/*此题三次回答机会用尽，得分为零，进行下一题*/
            else 
			{
                 t->grade=0;
                 printf("非常遗憾你又答错了，请继续做下一题.\n");
                 printf("本题的正确答案为%d\n",t->add);
				 /*输出正确答案，提示进行下一题*/
			}
		 }
	}
}
}

void main()

{
    int i,j,score=0;
    int Time,start,end;
	/*输入时间、开始、结束变量*/

    start=clock(); 
    printf("%d",start); 
    printf("_______________________________________________________________________________\n");
    printf("_______________________欢迎进入小学生算术四则运算测试程序______________________\n");
    printf("_______________________________________________________________________________\n");
	/*进入测试程序的欢迎界面*/
	
	/*选择计算题难度*/
	int q,n;
	printf("请选择题型难度，输入1（简单）、2（中等）或3（困难）：  \n");
	scanf("%d",&q);
	if(q==1)
		n=10;
	if(q==2)
		n=100;
	if(q==3)
		n=1000;
	struct struc test[10];
    srand((unsigned)time(NULL));

	/*C语言随机函数,产生题目*/	
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
		/*一组10道题运算结束*/

    for(i=0;i<10;i++)
        score=score+test[i].grade;
	    /*每道题得分相加得到总分*/
    
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
    /*输出小学生回答问题的分数和等级*/ 
    
	if(score>=60)
	{
        printf("祝贺你!\n");
	}
    /*分数大于等于60分，测试通过*/

	/*分数小于60分，测试未通过，需重新测试*/
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
    /*记录小学生回答问题的时间*/
}

