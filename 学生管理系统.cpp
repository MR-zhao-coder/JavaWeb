#include<stdio.h>
#include<stdlib.h>  
#include<malloc.h>                                      //为了后面使用清屏函数
#include<math.h>                                          //为了后面使用cos函数                                               //定义全局变量方便后面的do……while语句结束条件能够成立
struct student                                            //定义结构体为了后面定义结构体数组方便处理学生的信息
{
    int num;
	char name[20];
	float MT;
	float EN;
	float PH;
};
void judge(struct student a[],int n)                      //防止在修改学生信息时成绩输入负数
{
	do
	{
	if(a[n].MT < 0 || a[n].EN < 0 || a[n].PH < 0)
	{
		printf("输入出错请重新输入(数学 英语 物理)成绩：");
		scanf("%f %f %f",&a[n].MT,&a[n].EN,&a[n].PH);
	}
	}while(a[n].MT < 0 || a[n].EN < 0 || a[n].PH < 0);
	do
	{
		if(a[n].num < 0)
		{
		printf("输入出错请重新输入学号:");
        scanf("%d",&a[n].num);
		}
	}while(a[n].num < 0);
	return;
}
void map()                                                      //定义制作管理系统主界面函数
{
	system("color Ee");
	printf("********************************************************************************\n");
	printf("**                                                                            **\n");
	printf("**                              欢迎进入学生管理系统：                        **\n");
	printf("**                                                                            **\n");
	printf("**                                 1.输入学生信息。                           **\n");
	printf("**                                 2.修改学生信息。                           **\n");
	printf("**                                 3.查找学生信息。                           **\n");
	printf("**                                 4.学生成绩排名。                           **\n");
	printf("**                                 5.学生成绩方差情况。                       **\n");
	printf("**                                 6.查看学生信息。                           **\n");
	printf("**                                 7.退出程序。                               **\n");
	printf("**                                                                            **\n");
	printf("**                                                                            **\n");
	printf("**                                 请输入编号（1-7）                          **\n");
	printf("**                                                                            **\n");
	printf("**                                                                            **\n");
	printf("**                                                                            **\n");
	printf("**                                                                            **\n");
	printf("**                                                                            **\n");
	printf("**                          小提示：当提示按“0”的时候请不要按(1-6)的数字哟！**\n");
	printf("**                          小提示：学号的输入一定要具有唯一性哟 ^ - ^ Thanks!**\n");
	printf("********************************************************************************\n");
			return;
}
void input(struct student a[],int n)                              //定义录入函数
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		printf("输入第%d个学生的学号:",i + 1);
		do                                                      //避免输入负数的情况
		{
		scanf ("%d",&a[i].num);
		if(a[i].num < 0)
            printf("输入出错请重新输入学号：");
		}while(a[i].num < 0);
		printf("输入第%d个学生的姓名:",i + 1);
		scanf ("%s",a[i].name);
		printf("依次输入第%d个学生的数学英语物理成绩:",i + 1);
		do                                                      //避免输入负数的情况
		{
		scanf ("%f %f %f",&a[i].MT,&a[i].EN,&a[i].PH);
		if(a[i].MT < 0 || a[i].EN < 0 || a[i].PH < 0)
            printf("输入出错请重新输入学生的数学英语物理成绩：");
        }while(a[i].MT < 0 || a[i].EN < 0 || a[i].PH < 0);
		printf("\n");
		
	}
	printf("录入成功！请按任意数字键返回主界面：");
    scanf("%d",&j);
    return;
}
void view(struct student a[],int n)                        //定义查看学生信息的函数
{
	int i;
	printf("学生的信息表如下：\n");
	printf("学号\t姓名\t数学\t英语\t物理\t\n");
    for(i = 0;i < n;i++)
		printf("%d\t%s\t%2.2f\t%2.2f\t%2.2f\t\n",a[i].num,a[i].name,a[i].MT,a[i].EN,a[i].PH);
	printf("按“0”返回主界面：");
	return;
}
void modify(struct student a[],int n)
{

	int i,j,k,m;
	printf("请输入您要修改信息学生的学号：");
	do
	{
    scanf("%d",&i);
	for(m = 0;m < n;m++)                                   //查找出与输入数字相同的学号并将该学号所处个数发送给变量i
	{
		if(i == a[m].num)
		{
			i = m;
		    break;
		}
	}
	if(m == n)
		printf("未找到该学生请重新输入学号：");
	}while(m == n);
	printf("已找到该学生信息如下：\n");
	printf("学号\t姓名\t数学\t英语\t物理\t\n");
	printf("%d\t%s\t%2.2f\t%2.2f\t%2.2f\t\n",a[i].num,a[i].name,a[i].MT,a[i].EN,a[i].PH);
	printf("请选择是否进行修改？“1(是)” or “2(否)”");
	scanf("%d",&j);
	if(j == 1)
	{
		int c;
		do                                                          //提高程序的可操作性，方便用户的使用
		{
		printf("请选择需修改的项目：\n");
		printf("1.修改该学生的学号\n");
		printf("2.修改该学生的姓名\n");
		printf("3.修改该学生的三科(数学 英语 物理)成绩\n");
        printf("请输入参数1-3:");
		do
		{
		scanf("%d",&k);
		if(k < 1 || k > 3)
	        printf("输入错误请重新输入：");
		}while(k < 1 || k > 3);
		switch(k)
		{
		case 1:printf("请输入修改后的学号：");scanf("%d",&a[i].num);judge(a,i);break;
		case 2:printf("请输入修改后的姓名：");scanf("%s",a[i].name);break;
		case 3:printf("请输入修改后的三科(数学 英语 物理)成绩：");scanf("%f %f %f",&a[i].MT,&a[i].EN,&a[i].PH);judge(a,i);break;
		}
		printf("请选择是否继续修改？“1(是)”or“2(否)”");
		scanf("%d",&c);
		}while(c == 1);
	}
	printf("请输入“0”返回主界面：");
	return;
}
void find(struct student a[],int n)
{
	int i,m;
	printf("请输入您要查找信息的学生的学号：");
	do
	{
    scanf("%d",&i);
	for(m = 0;m < n;m++)                                   //查找出与输入数字相同的学号并将该学号所处个数发送给变量i
	{
		if(i == a[m].num)
		{
			i = m;
		    break;
		}
	}
	if(m == n)
		printf("未找到该学生请重新输入学号：");
	}while(m == n);
	printf("已找到该学生信息如下：\n");
	printf("学号\t姓名\t数学\t英语\t物理\t总分\t平均分\t\n");
	printf("%d\t%s\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t\n",
		a[i].num,a[i].name,a[i].MT,a[i].EN,a[i].PH,a[i].MT + a[i].EN + a[i].PH,(a[i].MT + a[i].EN + a[i].PH)/3);
	printf("请按“0”返回主界面：");
	return;
}
void rank(struct student a[],int n)
{
	int i,j,k;
	struct student t;
	for(i = 0;i < n-1;i++)
		for(j = 0;j < n - i -1;j++)
		{
			if((a[j].MT + a[j].EN + a[j].PH)<(a[j + 1].MT + a[j + 1].EN + a[j + 1].PH))
			(t = a[j],a[j]= a[j + 1],a[j + 1]= t);
		}
    printf("学号\t姓名\t数学\t英语\t物理\t总分\t平均分\t\n");
	for(k = 0;k < n;k++)
	{
	    printf("%d\t%s\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t\n",
		a[k].num,a[k].name,a[k].MT,a[k].EN,a[k].PH,a[k].MT + a[k].EN + a[k].PH,(a[k].MT + a[k].EN + a[k].PH)/3);
	}
	printf("请按“0”返回主界面：");
	return;
}
void variance(struct student a[],int n)
{
	double sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0;
	double sum5 = 0,sum6 = 0,sum7 = 0,sum8 = 0;
	double ave1,ave2,ave3,aver;
	int i,k;
	for(i = 0;i < n;i++)
	{
		sum1 = sum1 + a[i].MT;
		sum2 = sum2 + a[i].EN;
		sum3 = sum3 + a[i].PH;
		sum4 = sum4 + a[i].MT + a[i].EN + a[i].PH;
	}
    ave1 = sum1 / n;
	ave2 = sum2 / n;
	ave3 = sum3 / n;
	aver = sum4 / (3 * n);
    for(k = 0;k < n;k++)
	{
		sum5 = sum5 + pow((a[k].MT - ave1),2);
		sum6 = sum6 + pow((a[k].EN - ave2),2);
		sum7 = sum7 + pow((a[k].PH - ave3),2);
		sum8 = sum8 + pow((a[k].MT - aver),2) + pow((a[k].EN - aver),2) + pow((a[k].PH - aver),2);	
	}
	printf("该班成绩方差情况如下：\n");
	printf("数学成绩方差\t英语成绩方差\t物理成绩方差\t总成绩方差\t\n");
	printf("%2.2lf\t\t%2.2lf\t\t%2.2lf\t\t%2.2lf\t\t\n",sum5 / n,sum6 / n,sum7 / n,sum8 / (3 * n));
	printf("请按“0”返回主界面：");
	return;
}
int main()      
{
	int len;
	printf("请输入学生个数：");
	scanf("%d",&len);
	system("cls");
	struct student * a = (struct student *)malloc(sizeof(struct student) * len);
	float x = cos(0.0);                       //用来解决scanf存储float数据时会出现的警告
	int q = 0,p;                                    //全局变量初始化
	do
	{
		if(q == 0 || q % 2 != 0)              //为了可以重复处理录入的学生信息
		{
			map();
		}
		q++;                                                                                    //计算循环次数进行相应的操作
		if(q == 1)                                                                              //提示第一步必须先录入学生信息
			printf("请先按“1”录入学生的信息(运行一次程序只允许录入一次学生信息（@·.·@）)：");
		else if(q % 2 == 0)
			printf("请按所需功能相应的键：");
	    do
		{
		scanf("%d",&p);
		if(p < 0 || p > 7)
	        printf("输入错误请重新输入：");
		}while(p < 0 || p > 7);
		system("cls");                                                                          //进行适时地清屏方便程序的重复操作
		switch(p)                            
		{
		case 0:;break;
		case 1:input(a,len),system("cls");break;
		case 2:modify(a,len);break;
		case 3:find(a,len);break;
		case 4:rank(a,len);break;
		case 5:variance(a,len);break;
		case 6:view(a,len);break;
		}
	}while(p < 7);//使循环结束即结束该程序的条件
	free(a);
	return 0;
}
/*
本程序使用规则：先输入1存储学生信息，此时程序界面立刻跳转到主界面，
在输入相应的需要的功能所对应的数字后得到相应的结果，之后通过按0返回主
界面重新选择所需要的功能按其对应的数字即可.
*/