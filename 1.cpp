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
/*�����������*/

{ 
	int t;
    t=rand()%n;
    return t;
}

void ctm_i(struct struc *t)
/*����ָ��ṹ�����ͱ�����ָ�����*/
             
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
    printf("���ڽ��е�%d��\n",n+1); 
    printf("�������ܹ������λ��ᣬ����뱣������\n");
    if(t->c==0) 
		printf("%d+%d=",t->a,t->b);
    if(t->c==1) 
		printf("%d-%d=",t->a,t->b);
    if(t->c==2) 
		printf("%d*%d=",t->a,t->b);
    if(t->c==3) 
		printf("%d/%d=",t->a,t->b);
    /*�������мӼ��˳�����*/
    scanf("%d",&ad);
    if(ad==t->add)
    {
        t->grade=10;
	    printf("��ȫ��ȷ����ǳ�����!��10��\n");
    }
    else
	{ 
        printf("�����ˣ�����Ŭ��!\n");
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
            printf("����ˣ���ܰ�!��8��\n");
        }
        else 
		{ 
            printf("�����ˣ�����Ŭ��!\n");
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
                 printf("����ˣ�ף����!��6��\n");
            }
            else 
			{
                 t->grade=0;
                 printf("�ǳ��ź����ִ���ˣ����������һ��.\n");
                 printf("��ȷ��Ϊ%d\n",t->add);
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
    /*C�����������,������Ŀ*/	
    printf("_______________________________________________________________________________\n");
    printf("_______________________________Сѧ����ѧCAIϵͳ_______________________________\n");
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
        printf("Сѧ������������Խ���!\n");
    for(i=0;i<10;i++)
        score=score+test[i].grade;
    if(score>=90 )
	{
        printf("����!\n"); 
	}
    else if (score>=75 )
	{
	    printf("����!\n ");
	}
    else if (score>=60) 
	{
	    printf("�ϸ�!\n");
	}
    else  
	{
	    printf("���ϸ�!\n");
	}
    printf("score=%d\n",score);
    /*Сѧ���ش�����ķ����͵ȼ�*/ 
    if(score>=60)
	{
        printf("ף����!\n");
	}
    else
	{
        printf("����Ŭ��,������!\n");
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
    printf("��ʱ:%d��\n",Time); 
    /*Сѧ���ش������ʱ��*/
}

