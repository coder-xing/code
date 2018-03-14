#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char name[20];
    char sex[5];
    char class[20];
    long school;
    long tel;
    char num[20];
    char building[10];
    char dor[6];
    struct Node*next;
}node;

typedef struct Linklist{
    node *head;
    node *tail;
    int length;
}linklist;

linklist* initlinklist(linklist *stu){
    stu->head=NULL;
    stu->tail=NULL;
    stu->length=0;
    return stu;
}

int addtail(linklist *stu,node *new){
    if(stu->head==NULL){
	stu->head=new;
	stu->tail=new;
	stu->length++;
    }
    else
    {
	stu->tail->next=new;
	stu->tail=new;
	stu->length++;
    }
    return 0;
}

int input_info(linklist *stu){
    system("clear");
    node *new;
    new=(node *)malloc(sizeof(node));
    new->next=NULL;
    printf("清输入你的信息\n");
    printf("请输入姓名");
    scanf("%s",new->name);
    printf("请输入性别");
    scanf("%s",new->sex);
    printf("请输入班级");
    scanf("%s",new->class);
    printf("请输入学号");
    scanf("%ld",&new->school);
    printf("请输入电话号码");
    scanf("%ld",&new->tel);
    printf("请输入身份证");
    scanf("%s",new->num);
    printf("请输入宿舍楼");
    scanf("%s",new->building);
    printf("请输入寝室");
    scanf("%s",new->dor); 
    addtail(stu,new);
}

int show_info(linklist *stu){
	node *p;
	p=stu->head;
	while(p!=NULL){
	    printf("姓名        性别    班级      学号           电话号码            身份证                   宿舍楼      寝室    \n");
	    printf("%-12s%-8s%-10s%-15d%-20ld%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->building,p->dor);
	    p=p->next;
	}
	getchar();
	getchar();
}

void search_info(linklist *stu){
    long i;
    printf("请输入你要查找的学号");
    scanf("%ld",&i);
    node *p;
    p=stu->head;
    while(p!=NULL){
	if(i==p->school){
	    printf("姓名        性别    班级      学号           电话号码            身份证                   宿舍楼      寝室    \n");
	    printf("%-12s%-8s%-10s%-15d%-20ld%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->building,p->dor);
	    break;	
	} 
	p=p->next;
    }
    getchar();
    getchar();
}

void change_info(linklist *stu){
    node *p;
    long a,b;
    int i=0;
    p=stu->head;
    printf("请输入你想要修改学生的学号");
    scanf("%ld",&a);
    while(p!=NULL&&a!=p->school){
	p=p->next;
    i++;}
    printf("请输入你要修改的学号");
    scanf("%ld",&b);
    p->school=b;
    printf("姓名        性别    班级      学号           电话号码            身份证                   宿舍楼      寝室    \n");
    printf("%-12s%-8s%-10s%-15d%-20ld%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->building,p->dor);
    getchar();
    getchar();
}

void delete_info(linklist *stu){

}

int main(){
    linklist l;
    linklist *stu=initlinklist(&l);
   int i;
   while(1){
       system("clear");
   printf("欢迎来到学生档案管理系统\n");
    printf("1:添加学生信息\n");
    printf("2:查询学生信息\n");
    printf("3:修改学生信息\n");
    printf("4:删除学生信息\n");
    printf("5:排序学生信息\n");
    printf("6:显示所有学生信息\n");
    printf("0:退出系统\n");
    scanf("%d",&i);
    switch(i){
	case 1:input_info(stu); break;
	case 2:search_info(stu);break;
	case 3:change_info(stu);break;
	case 6:show_info(stu);break;
	case 0:exit(0);
    }
}
} 
