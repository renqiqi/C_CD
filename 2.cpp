#include<stdio.h>
#include <stdlib.h>
#include <time.h> 
/*Դ�ļ�*/ 
   
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
	/*ϵͳ����������������*/

    return t;
	/*�����ϼ���t*/

}

void ctm_i(struct struc *t)
/*����ָ��ṹ�����ͱ�����ָ�����*/
             
{ 
	t->a=sj(1000);
	/*����������������1000���ڵ���*/

    t->c=sj(4);
    if(t->c==0) 
	{ 
		t->b=sj(1000-(t->a));
        t->add=(t->a)+(t->b);
	}
	/*�ӷ�����*/

    if(t->c==1)
	{ 
		t->b=sj((t->a)+1);
        t->add=(t->a)-(t->b);
	}
	/*��������*/

	if(t->c==2)
	{
        t->b=sj((t->a)+1);
        t->add=(t->a)*(t->b);
	}
    /*�˷�����*/

    if(t->c==3)
	{
        t->b=sj(1000-(t->a));
	    t->add=(t->a)/(t->b);
	}
	/*��������*/

    t->grade=10;
}

void tcm_i(struct struc *t,int n)

{ 
    int ad;
{
    printf("===================================\n");
	/*�ֿ�ÿ���������*/

    printf("���ڽ��е�%d��\n",n+1);
	/*��ʾͬѧ���ڽ��еڼ���*/

    printf("�������ܹ������λ���,�뱣������\n");
	/*������Сѧ����ѧ���㣬���������������*/

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
    /*�жϽ���Ƿ���ȷ*/

    {
        t->grade=10;
	    printf("��ȫ��ȷ����ǳ�����!��10��\n");
	    /*��һ�λش���ȷ���ּܷ�10��*/
	}
	
    /*��һ�λش����󣬽��еڶ��λش�*/
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
	    /*�жϽ���Ƿ���ȷ*/

        {
            t->grade=8;
            printf("����ˣ���ܰ�!��8��\n");
			/*�ڶ��λش���ȷ���ּܷ�8��*/
		}

		/*�ڶ��λش����󣬽��е����λش�*/
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
			/*�жϽ���Ƿ���ȷ*/

            {
                 t->grade=6;
                 printf("����ˣ�ף����!��6��\n");
				 /*�����λش���ȷ���ּܷ�6��*/
            }

			/*�������λش�����þ����÷�Ϊ�㣬������һ��*/
            else 
			{
                 t->grade=0;
                 printf("�ǳ��ź����ִ���ˣ����������һ��.\n");
                 printf("�������ȷ��Ϊ%d\n",t->add);
				 /*�����ȷ�𰸣���ʾ������һ��*/
			}
		 }
	}
}
}

void main()

{
    int i,j,score=0;
    int Time,start,end;
	/*����ʱ�䡢��ʼ����������*/

    start=clock(); 
    printf("%d",start); 
    printf("_______________________________________________________________________________\n");
    printf("_______________________��ӭ����Сѧ����������������Գ���______________________\n");
    printf("_______________________________________________________________________________\n");
	/*������Գ���Ļ�ӭ����*/
	
	/*ѡ��������Ѷ�*/
	int q,n;
	printf("��ѡ�������Ѷȣ�����1���򵥣���2���еȣ���3�����ѣ���  \n");
	scanf("%d",&q);
	if(q==1)
		n=10;
	if(q==2)
		n=100;
	if(q==3)
		n=1000;
	struct struc test[10];
    srand((unsigned)time(NULL));

	/*C�����������,������Ŀ*/	
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
		/*һ��10�����������*/

    for(i=0;i<10;i++)
        score=score+test[i].grade;
	    /*ÿ����÷���ӵõ��ܷ�*/
    
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
    /*���Сѧ���ش�����ķ����͵ȼ�*/ 
    
	if(score>=60)
	{
        printf("ף����!\n");
	}
    /*�������ڵ���60�֣�����ͨ��*/

	/*����С��60�֣�����δͨ���������²���*/
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
    /*��¼Сѧ���ش������ʱ��*/
}

