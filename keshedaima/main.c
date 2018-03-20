/*************************************************************************
    > File Name: main.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com
    > Created Time: 2015年06月25日 星期四 20时03分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <string.h>

#define OK 2
#define ERROR 1
typedef struct manager{ //管理员
	char id[30];//管理员序号
	char password[30];//管理员密码
}admin;

typedef struct score{   //学生成绩
	char math[10];
	char english[10];
	char C_program[10];
	char computer[10];
	char PE[10];
	/*
	 * 高数 英语 C语言 计算机 体育
	 */
}SCORE;

typedef struct student{  //学生信息
	char id[30];//学号
	char name[30];//姓名
	char age[10];//年龄
	char password[30];//密码
	char classes[30];//班级
	SCORE score;//学生课程成绩
	char rank[5];//总分排名
	struct student *prev;//链表前一结点
	struct student *next;//链表后一结点

}stu;

typedef struct login{    //登录所需
	GtkWidget *window;   //登录窗口
	GtkWidget *id;		 //学号
	GtkWidget *password; // 密码
	GtkWidget *identify_code;//验证码
	GtkWidget *label;    //标签
	GtkWidget *radio;    //选项
}LOGIN;

typedef struct add{      //添加功能所需全局变量，参见上面20行
	GtkWidget *window;
	GtkWidget *id;
	GtkWidget *name;
	GtkWidget *password;
	GtkWidget *classes;
	GtkWidget *score_math;
	GtkWidget *score_english;
	GtkWidget *score_C_program;
	GtkWidget *score_computer;
	GtkWidget *score_PE;
	GtkWidget *age;
}ADD;

typedef struct del{ //删除功能
	GtkWidget *window;//删除窗口
	GtkWidget *entry;//文本框
}DEL;

typedef struct save{      //存储窗口
	GtkWidget *window;
}SAVE;

typedef struct inq{       //查看学生信息
	GtkWidget *window;    
	GtkWidget *radio;		
	GtkWidget *entry;	 //参见上面10行
}INQ;

typedef struct change{ //管理员更改学生信息功能所需全局变量
	GtkWidget *window;
	GtkWidget *entry;
	GtkWidget *id;
	GtkWidget *name;
	GtkWidget *password;
	GtkWidget *classes;
	GtkWidget *score_math;
	GtkWidget *score_english;
	GtkWidget *score_C_program;
	GtkWidget *score_computer;
	GtkWidget *score_PE;
	GtkWidget *age;
	GtkWidget *new_password;//新密码
	GtkWidget *re_password; //再次输入的密码
}REV;

typedef struct sort{		//排序功能
	GtkWidget *window; 
	GtkWidget *radio;
}SORT;

typedef struct pro{
	LOGIN *login;          //对管理员功能的整体定义
	ADD *add;
	DEL *del;
	REV *change;
	INQ *inq;
	SAVE *save;
	SORT *sort;
}ADMIN;

char nameid[30];          //甄别是否是管理员
int chose;                //在选择按照什么方式进行排序或查询时需要
int count;                //登录错误次数
int flag;                 //是否更改了信息

stu *head;
stu *create();            //申请一个空间
int init_head(stu *head); //初始化链表
int length(stu *head);    //链表长度
int insert_end(stu *head, stu *n); //尾插
int del_node(stu *head);  //删除结点函数
int insert_cur(stu *head, char id[30], stu *n);  //在某个位置进行插入
int destory(stu *head);   //销毁链表
stu *find_id_exist(stu *head, char id[30]);  //查询文件中id是否存在，返回位置，不存在返回NULL
stu *find_name_exist(stu *head, char id[30]);//查询文件中名字是否存在，返回位置，不存在返回NULL
stu *find_rank_exist(stu *head, char id[30]);//查询文件中该排名是否存在，返回位置，不存在返回NULL
stu *find_math_exist(stu *head, char id[30]);//查询文件中高数成绩是否存在，返回位置，不存在返回NULL
stu *find_english_exist(stu *head, char id[30]);//查询文件中英语成绩是否存在，返回位置，不存在返回NULL
stu *find_PE_exist(stu *head, char id[30]);//查询文件中体育成绩是否存在，返回位置，不存在返回NULL
stu *find_C_program_exist(stu *head, char id[30]);//查询文件中C语言成绩是否存在，返回位置，不存在返回NULL
stu *find_computer_exist(stu *head, char id[30]);//查询文件中计算机成绩是否存在，返回位置，不存在返回NULL

int admin_save_mod(); //管理员功能中将链表写入文件
int data_init_mod();  //初始化文件并创建链表
int stu_exist_mod(char id[30], char password[30]); //查看学生信息是否在文件中存在
int sort_mod(int (*comp)(const void *, const void *));//对文件进行排序（排序规则如下7行）
int comp_name(const void *x, const void *y);
int comp_math(const void *x, const void *y);
int comp_PE(const void *x, const void *y);
int comp_english(const void *x, const void *y);
int comp_computer(const void *x, const void *y);
int comp_C_program(const void *x, const void *y);
int comp_score(const void *x, const void *y);
/*每一个功能我需要一个控制函数, 返回管理员界面*/
void login_ctrl(GtkWidget *widget, gpointer data);   //登录界面的功能实现函数
void login_toggled(GtkWidget *widget, gpointer data);//对选项的选择函数，区别于学生和管理员
void login_sort_ctrl(GtkWidget *widget, gpointer data);//排序功能进行实现的函数
void login_sort_ret_ctrl(GtkWidget *widget, gpointer data);//从排序窗口返回管理员菜单
void login_sort_message_ctrl(GtkWidget *widget, gpointer data);//对排序结果的不同情况的表达
void login_toggled1(GtkWidget *widget,gpointer data);//对选择排序方式或者查询方式时用（包括下面7行都是一样）
void login_toggled2(GtkWidget *widget,gpointer data);
void login_toggled3(GtkWidget *widget,gpointer data);
void login_toggled4(GtkWidget *widget,gpointer data);
void login_toggled5(GtkWidget *widget,gpointer data);
void login_toggled6(GtkWidget *widget,gpointer data);
void login_toggled7(GtkWidget *widget,gpointer data);
void login_toggled8(GtkWidget *widget,gpointer data);
void login_change_ctrl(GtkWidget *widget, gpointer data);//更改学生信息功能的实现
void login_change_ret_ctrl(GtkWidget *widget, gpointer data);//从更改学生信息窗口返回到管理员菜单
void login_del_ctrl(GtkWidget *widget, gpointer data);//删除学生信息功能实现
void login_del_ret_ctrl(GtkWidget *widget, gpointer data);//从删除学生界面返回到管理员菜单
void login_inq_all_view(GtkWidget *widget, gpointer data);//查询所有学生的界面
void login_inq_ctrl(GtkWidget *widget, gpointer data);//查询功能实现函数
void login_inq_ret_ctrl(GtkWidget *widget, gpointer data);//从查询界面返回到管理员菜单
void login_inq_message_ctrl(GtkWidget *widget, gpointer data);//对查询以后结果的不同情况的表达
void login_add_ctrl(GtkWidget *widget, gpointer data);//添加学生信息的界面
void login_add_ret_ctrl(GtkWidget *widget, gpointer data);//从学生信息添加界面返回到管理员菜单
void login_admin_ret_ctrl(GtkWidget *widget, gpointer data);//从管理员菜单返回到登陆界面
void login_save_message_ctrl(GtkWidget *widget, gpointer data);//对存储结果不同情况的表达
void login_stu_change_ctrl(GtkWidget *widget, gpointer data);//实现学生更改自己的信息的函数
void login_stu_change_ret_ctrl(GtkWidget *widget, gpointer data);//从学生更改信息界面返回到学生菜单
void login_stu_ret_ctrl(GtkWidget *widget, gpointer data);//从学生菜单返回到登陆界面
void login_exit_ctrl(GtkWidget *widget, gpointer data);//退出

gpointer create_window(GtkWindowType type, const gchar *title, gboolean resizable, gint width, gint height);//创建窗口函数
gpointer create_entry(gint max, gboolean editable, gboolean visible);//创建文本框函数
void login_view();//登陆界面
void login_message_view(int count);//登录不同结果的表达
void login_identify_code_message_view(int count);//对验证码输入不同结果的表达
void login_admin_view();//管理员菜单截面
void login_admin_add_view();//添加学生信息界面
void login_admin_add_message_view(GtkWidget *widget, gpointer data);//对不同添加的结果的表达
void login_admin_del_message_view(GtkWidget *widget, gpointer data);//对不同删除的结果的表达
void login_admin_del_view();//删除界面
void login_admin_change_view();//管理员更改学生信息界面
void login_change_message_view(GtkWidget *widget, gpointer data);//对不同更改结果的表达
void login_stu_change_view();//学生更改信息界面
void login_student_view();//学生菜单
void gtk_admin_inq_view();//管理员查询界面
void gtk_admin_sort_view();//管理员排序界面
void login_stu_inq_message_view();//学生查询不同结果的返回
void login_admin_inq_all_view(GtkWidget *widget, gpointer data);//对全部查询的不同结果的返回
void login_exit_message_view(GtkWidget *widget, gpointer data);//对退出不同结果的返回


ADMIN pro;                                //管理员的定义
LOGIN login, login_admin, login_stu;	  //定义不同的登录类型
ADD add;								  //添加功能的定义
INQ inq;								  //查询功能的定义
DEL del;								  //删除功能的定义
REV change;                               //更改功能的定义
SORT sort;                                //排序功能的定义
admin *manager;                           //定义管理员
stu *my;                                  //定义学生信息

char nameid[30] = "学  生";               //默认定义登录是学生
int chose = 1;						      //初始化chose，count和flag
int count = 0;
int flag = 0;

stu *head = NULL;                         //头结点指向NULL
 
stu *create(){
    return (stu*)calloc(1, sizeof(stu));  //申请空间(双向循环链表)
}

int init_head(stu *head){                 //初始化头结点
    if(head == NULL){
        return 1;
    }
    head -> prev = head;
    head -> next = head;
    return 0;
}

int length(stu* head){				      //返回链表长度
    int len = 0;
    stu *p = NULL;
    if(head == NULL)
        return 0;
    p = head -> next;
    while(p != head){
        len ++;
        p = p  -> next;
    }
    return len;
}

int insert_end(stu *head, stu *p){        //尾插
    if(p == NULL || head == NULL){
        return 1;
    }
    p -> prev = head -> prev;
    p -> next = head;
    head -> prev -> next = p;
    head -> prev = p;
    return 0;
}

int destory(stu *head){              //销毁链表
    stu *temp = NULL;
    stu *next = NULL;
    if(head == NULL)
        return 1;
    temp = head -> next;
    while(temp != head){
        next = temp -> next;
        free(temp);
        temp = next;
    }
    head -> prev = head;
    head -> next = head;
    return 0;
}

stu *find_id_exist(stu *head, char id[30]){  //查询id信息是否在文件中存在
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> id) == 0){
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

stu *find_name_exist(stu *head, char id[30]){     //查询链表中该排名是否存在，返回位置，不存在返回NULL（下几个find函数同）
    stu *p = NULL;
    if(head == NULL)
        return NULL;
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> name) == 0)
            return p;
		p = p -> next;
    }
    return NULL;
}

stu *find_math_exist(stu *head, char id[30]){
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> score.math) == 0)
            return p;
        p = p -> next;
    }
    return NULL;
}

stu *find_english_exist(stu *head, char id[30]){
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> score.english) == 0)
        return p;
        p = p -> next;
    }
    return NULL;
}

stu *find_C_program_exist(stu *head, char id[30]){
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> score.C_program) == 0)
        return p;
        p = p -> next;
    }
    return NULL;
}

stu *find_computer_exist(stu *head, char id[30]){
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> score.computer) == 0)
        return p;
        p = p -> next;
    }
    return NULL;
}

stu *find_PE_exist(stu *head, char id[30]){
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> score.PE) == 0)
        return p;
        p = p -> next;
    }
    return NULL;
}

stu *find_rank_exist(stu *head, char id[30]){
    stu *p = NULL;
    if(head == NULL){
        return NULL;
    }
    p = head -> next;
    while(p != head){
        if(strcmp(id, p -> rank) == 0)
        return p;
        p = p -> next;
    }
    return NULL;
}

int del_id(stu *head, char id[30]){                    //删除结点
    stu *temp = NULL;
    temp = find_id_exist(head, id);
    if(head == NULL || temp == NULL)
        return 1;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
    return 0;
}

int insert_cur(stu *head, char id[30],stu *n){        //插入到指定位置
    stu *temp = NULL;
    if(n == NULL || head == NULL)
		return 1;
    temp = find_id_exist(head, id);
    n -> next = temp -> next;
    temp -> next ->prev = n;
    temp -> next = n;
    n -> prev = temp;

    return 0;
}


int stu_exist_mod(char id[30], char password[30]){        //判断学生是否存在
    stu *temp = NULL;
	temp = head -> next;
    while(temp != head){
        if(!strcmp(id, temp->id) && !strcmp(password, temp->password)){
            *my = *temp;
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

int admin_save_mod(){
    FILE *fp = NULL;                                     //管理员存储时写入文件
    stu *p = NULL;
    if(head == NULL)
        return ERROR;
    fp = fopen("data", "w");
    if(fp == NULL){
        return ERROR;
    }
    p = head -> next;
    while(p != head){
        fwrite(p, sizeof(stu), 1, fp);
        p = p -> next;
    }
    fclose(fp);

    return 0;
}

int data_init_mod(){                                 //初始化文件和链表
    FILE *fp = NULL;
    stu *p = NULL;
    fp = fopen("data", "r");
    if(fp == NULL){
        fp =fopen("data", "w");
        if(fp == NULL)
            return 1;
    }
    else{
        p = create();
        if(p == NULL)
            return 2;
        while(fread(p, sizeof(stu), 1, fp) != 0){
            insert_end(head, p);
            p = create();
            if(p == NULL)
                return 2;
        }
        free(p);
    }
    fclose(fp);
    return 0;
}

int sort_mod(int (*comp)(const void *, const void *)){           //排序函数 
    stu *temp = NULL;
    int len = 0;
    stu *node = NULL;
    int i =  0;


    if(head == NULL)
        return ERROR;
    len = length(head);
    temp = (stu*)calloc(len, sizeof(stu));
    if(temp == NULL)
        return OK;
    node = head -> next;
    for(i = 0; i < len; i ++){
        temp[i] = *node;
        node = node -> next;
    }
    destory(head);
    qsort(temp,len,sizeof(stu),comp);
    for(i = 0; i < len; i ++){
        node = create();
        if(node == NULL)
            return OK;
        *node = temp[i];
        if(comp == comp_score){
            gcvt((double)i +1, 2, node->rank);
        }
        insert_end(head, node);
    }
    free(temp);
    return 0;
}

int comp_name(const void *x, const void *y){          //不同的比较规则（下同）姓名
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = strcmp(px -> name, py -> name);
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

int comp_math(const void *x, const void *y){
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = atof(px->score.math) - atof(py -> score.math);
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

int comp_english(const void *x, const void *y){
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = atof(px->score.english) - atof(py -> score.english);
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

int comp_computer(const void *x, const void *y){
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = atof(px->score.computer) - atof(py -> score.computer);
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

int comp_C_program(const void *x, const void *y){
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = atof(px->score.C_program) - atof(py -> score.C_program);
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

int comp_PE(const void *x, const void *y){
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = atof(px->score.PE) - atof(py -> score.PE);
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

int comp_score(const void *x, const void *y){
    const stu *px = x;
    const stu *py = y;
    int result = 0;
    result = (atof(px -> score.computer) + atof(px ->score.C_program) + atof(px ->score.english) +atof(px -> score.math) + atof(px -> score.PE)) - (atof(py -> score.computer) + atof(py ->score.C_program) + atof(py ->score.english) +atof(py -> score.math) + atof(py -> score.PE));
    if(result == 0)
        return 0;
    else if(result < 0)
        return 1;
    else return -1;
}

void login_identify_code_message_view(int count){         //对验证码不同结果的表达
    GtkWidget *message;   //信息框
    GtkWidget *button;    //按钮
    
    message = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE,NULL);//特定信息框显示一个?
    button = gtk_button_new_from_stock(GTK_STOCK_OK);//OK形式的特殊按钮    
    gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message)->action_area)),button);         //将构件插入到格子当中
    gtk_widget_show(button);																		//显示按钮
    
    if(count < 3){
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"验证码不正确\n请仔细观察后重新输入"); //对信息进行赋值
		g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),message);        //回调关闭窗口函数
		gtk_widget_show(message);																 //显示信息框
		return;
    }
    else {
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"登录失败次数超过3次\n为保护您的帐号安全你将被退出系统,886~");
		g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_main_quit),message);															//(同上)
		gtk_widget_show(message);
    }
}


void login_message_view(int count)	                                                      //此函数形式与上相同，功能是对于用户名密码不匹配的表达
{
	GtkWidget *message;
	GtkWidget *button;

	message = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE,NULL);
	button = gtk_button_new_from_stock(GTK_STOCK_OK);

	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message)->action_area)),button);
	gtk_widget_show(button);
	if(count<3){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"用户名或密码不正确\n请检查后重新输入");
		g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),message);
		gtk_widget_show(message);
		return;
	}
	else{
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"登录失败次数超过3次\n为保护您的帐号安全你将被退出系统,886~");
		g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_main_quit),message);
		gtk_widget_show(message);
	}

}
void login_ctrl(GtkWidget *widget,gpointer data)	
{
	char id[30]="\0";									//定义id用来判断
	char password[30]="\0";								//定义password用于判断
	
	gtk_widget_hide(login.window);                      //隐藏登录窗口
	if(0==strcmp("管理员",nameid)){			            //判断登录身份是否时管理员
		strcpy(id,gtk_entry_get_text(GTK_ENTRY(login.id)));   //将文本框中的值赋给变量
		strcpy(password,gtk_entry_get_text(GTK_ENTRY(login.password)));
		if(0==strcmp(id,manager->id)&&0==strcmp(password,manager->password)){
			if(0==strcmp(gtk_label_get_text(GTK_LABEL(login.label)),gtk_entry_get_text(GTK_ENTRY(login.identify_code)))){ //对验证码的匹配处理
				count=0;
				login_admin_view();		//进入管理员菜单
			}
			else{				
				count++;				                       //未匹配成功记录未成功次数
				login_identify_code_message_view(count);       //转到验证码未匹配的函数
				gtk_widget_show(login.window);                 //显示登陆界面
			}
		}
		else{	
			count++;				
			login_message_view(count);                         //用户密码不匹配转到显示不匹配的结果的函数 
			gtk_widget_show(login.window);

		}

	} 
	else{					                          //学生的情况，同上
		strcpy(id,gtk_entry_get_text(GTK_ENTRY(login.id)));
		strcpy(password,gtk_entry_get_text(GTK_ENTRY(login.password)));
		if(0!=stu_exist_mod(id,password)){
				if(0==strcmp(gtk_label_get_text(GTK_LABEL(login.label)),gtk_entry_get_text(GTK_ENTRY(login.identify_code)))){
					count=0;
					login_student_view();			
				}
				else{				
					login_identify_code_message_view(count);
					gtk_widget_show(login.window);
				}
		}			
		else{	
			count++;				
			login_message_view(count);
			gtk_widget_show(login.window);

		}
	}

}







void login_toggled1(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){       //检测对应的按钮如果是按下的更改全局变量chose（下同）
		chose = 1;
	}
	return;
}

void login_toggled2(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 2;
	}
	return;
}

void login_toggled3(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 3;
	}
	return;
}


void login_toggled4(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 4;
	}
	return;
}

void login_toggled5(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 5;
	}
	return;
}

void login_toggled6(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 6;
	}
	return;
}

void login_toggled7(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 7;
	}
	return;
}

void login_toggled8(GtkWidget *widget,gpointer data)
{


	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))){
		chose = 8;
	}
	return;
}

void login_admin_add_ret_ctrl(GtkWidget *widget, gpointer data){     //从管理员添加窗口返回到管理员菜单
	gtk_widget_hide(add.window);
	gtk_widget_show(login_admin.window);
}

void login_admin_ret_ctrl(GtkWidget *widget, gpointer data){        //从管理员菜单返回到登陆界面
	gtk_widget_hide(login_admin.window);

	gtk_widget_show(login.window);
} 
 
void login_add_ctrl(GtkWidget *widget, gpointer data){             //从管理员菜单进入添加学生信息的界面
	gtk_widget_hide(login_admin.window);
	login_admin_add_view();
	gtk_widget_show(add.window);
}

void login_toggled(GtkWidget *widget, gpointer data){              //判断选择是管理员还是学生，并对全局变量nameid进行赋值
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
		strcpy(nameid, gtk_button_get_label(GTK_BUTTON(widget)));
	}
	return ;
}



void login_add_ret_ctrl(GtkWidget *widget, gpointer data){        //从添加窗口返回到管理员菜单
	gtk_widget_hide(add.window);
	gtk_widget_show(login_admin.window);

}

void login_del_ctrl(GtkWidget *widget, gpointer data){            //从管理员菜单进入到删除窗口
    gtk_widget_hide(login_admin.window);
    login_admin_del_view();
}

void login_del_ret_ctrl(GtkWidget *widget, gpointer data){        //从删除窗口返回管理员菜单
    gtk_widget_hide(del.window);
    gtk_widget_show(login_admin.window);
}

void login_change_ctrl(GtkWidget *widget, gpointer data){        //从管理员菜单进入更改学生信息窗口
    gtk_widget_hide(change.window);
    login_admin_change_view();
}

void login_change_ret_ctrl(GtkWidget *widget, gpointer data){      //从更改学会是跟信息窗口返回管理员窗口
    gtk_widget_hide(change.window);
    gtk_widget_show(login_admin.window);
}

void login_inq_ret_ctrl(GtkWidget *widget, gpointer data){          //从查询窗口返回到管理员菜单
    gtk_widget_hide(inq.window);
    gtk_widget_show(login_admin.window);
}

void login_exit_ctrl(GtkWidget *widget , gpointer data){            //退出管理员菜单的实现
	GtkWidget *message;
	GtkWidget *button;
    if(strcmp("管理员", nameid) == 0){                              //判断是否是管理员，显示不同的界面
        login_admin_view();
    }
    else{
        login_student_view();
    }
    if(flag == 0){
	message = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE,NULL);
	gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"您确定退出教学管理系统？");
	button = gtk_button_new_from_stock(GTK_STOCK_OK);
	if(0==strcmp("管理员",nameid)){							//实现函数通用性
		g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),message);
		gtk_widget_hide(login_admin.window);
		gtk_widget_show(login.window);
	}
	else{
		g_signal_connect(button,"clicked",G_CALLBACK(login_stu_ret_ctrl),NULL);
	}
	g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),NULL);
	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message)->action_area)),button);
	gtk_widget_show(button);

	button = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
	g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),message);
	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message)->action_area)),button);
	gtk_widget_show(button);
	gtk_widget_show(message);
	return;
}
    else{
        message = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,GTK_MESSAGE_INFO, GTK_BUTTONS_NONE,NULL);   //如果flag不为0说明改动数据，要求重新写入文件
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "数据有改变\n请先保存数据！");           
        button = gtk_button_new_from_stock(GTK_STOCK_OK);                                                   //特定的OK按钮
        g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), NULL);
        gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
        gtk_widget_show(button);
        gtk_widget_show(message);
    }
}

void login_save_message_ctrl(GtkWidget *widget, gpointer data){      //对与不同的保存结果的表达
    GtkWidget *message;
    GtkWidget *button;

    message = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_NONE, NULL);//这里注释好几次了。。不注释了，意思就是做message，做button
    button = gtk_button_new_from_stock(GTK_STOCK_OK);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), message);
    gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
    gtk_widget_show(button);

    if(admin_save_mod() != 0){
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "保存失败！");      //如果返回不为0说明失败
        gtk_widget_show(message);
        return;
    }
    else{
         gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "保存成功～");
         flag = 0;
    }
    gtk_widget_show(message);
}



void login_inq_ctrl(GtkWidget *widget, gpointer data){           //退出管理员界面，进入查询菜单
	gtk_widget_hide(login_admin.window);
	gtk_admin_inq_view();
}

void login_inq_message_ctrl(GtkWidget *widget, gpointer data){   //实现查看功能的函数
    GtkWidget *message;
    GtkWidget *button;
    GtkWidget *notebook;          //笔记本
    GtkWidget *textview;          
    GtkTextBuffer *buffer;		  //文本构件，更改它相当于更改文本
    GtkWidget *label;
    gchar play[200] = "\0";
    char text[30] = "\0";
    stu *temp = NULL;

    strcpy(text, gtk_entry_get_text(GTK_ENTRY(inq.entry)));              //将文本内容读入字符串
    message = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE,NULL);
    button = gtk_button_new_from_stock(GTK_STOCK_OK);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy),message);
    gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
    gtk_widget_show(button);

    switch(chose){      //根据不同的规则在链表中找结点
        case 1: //用户名
            temp = find_name_exist(head, text);
            break;
        case 2: //高数成绩
            temp = find_math_exist(head,text);
            break;
		case 3: //英语:
            temp = find_english_exist(head,text);
            break;
        case 4: //c语言
            temp = find_C_program_exist(head, text);
            break;
        case 5://计算机
            temp = find_computer_exist(head, text);
            break;
        case 6://体育
            temp = find_PE_exist(head, text);
            break;
        case 7://总分排名
            temp = find_rank_exist(head, text);
            break;
        case 8://id
            temp = find_id_exist(head, text);
            break;
        default :
            break;
    }
    if(temp ==  NULL){                 //如果未找到返回到NULL
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "查找不存在\n请重新输入！");   
		gtk_widget_show(message);
        return ;
    }
    else{
        notebook = gtk_notebook_new();// 创建新的笔记本
        gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> vbox)),notebook);  //笔记本的位置
        gtk_widget_show(notebook);

        sprintf(play, "学号：%s\n用户名:%s\n密码:%s\n班级:%s\n年龄:%s\n高数成绩:%s\n英语成绩:%s\nC语言成绩:%s\n计算机成绩:%s\n体育成绩:%s\n总分排名:%s\n",temp ->id, temp ->name, temp ->password, temp->classes, temp ->age, temp ->score.math, temp->score.english, temp->score.C_program, temp->score.computer, temp ->score.PE, temp->rank);
		// 将链表中的数据放到字符串中方便打印
        textview = gtk_text_view_new();
        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));    
        gtk_text_buffer_set_text(buffer, play, -1);                      //对buffer进行赋值也就是改变文本显示的内容
        label = gtk_label_new(text);									 //显示的内容读入标签
        gtk_notebook_append_page(GTK_NOTEBOOK(notebook), textview, label);  //在笔记本构建中插入页面
        gtk_widget_show(textview);
		gtk_widget_show(message);
	}
}
        

void login_stu_change_message_ctrl(GtkWidget *widget , gpointer data){
	GtkWidget *message;
	GtkWidget *button;
	stu *temp = NULL;
	char password[30] ="\0";
	char new_password[30] = "\0";
	char re_password[30] = "\0";
	strcpy(password, gtk_entry_get_text(GTK_ENTRY(change.password)));                                      //对当前函数用于比较的password进行赋值（下同）
	strcpy(new_password, gtk_entry_get_text(GTK_ENTRY(change.new_password)));
	strcpy(re_password, gtk_entry_get_text(GTK_ENTRY(change.re_password)));
	message = gtk_message_dialog_new(NULL ,GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_NONE, NULL);
	button = gtk_button_new_from_stock(GTK_STOCK_OK);														//特殊的OK按钮你懂的。。
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), message);
	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
	gtk_widget_show(button);


	if(strcmp(password, my->password)){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "原密码输入错误\n请重新输入！");       //下面这些都是判断以后输出信息框
		gtk_widget_show(message);
		return ;
	}
	else if(strlen(new_password) < 3){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "输入的密码位数过短！\n请重新如数！");
		gtk_widget_show(message);
		return ;
	}
	else if(strcmp(new_password, re_password) != 0){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "两次输入的密码不同！\n请重新输入！");
		gtk_widget_show(message);
	}
	else{
		strcpy(my -> password, new_password);
		*find_id_exist(head, my -> id) = *my;
		if(admin_save_mod() != 0){
			gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "数据出错，修改失败\n请重新尝试！");
			gtk_widget_show(message);
			return ;
		}
		else{
			gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "修改成功！");
			gtk_widget_show(message);
		}


	}
}




void login_stu_change_view(){         //学生修改个人的信息（这段程序毫无难点。。。）
	GtkWidget *button;
	GtkWidget *table;
	GtkWidget *label;
	
		//模式是：对标签label进行赋值，然后定义标签位置，创建输入的框，然后定义框的位置，打印出来两个构件

	change.window = create_window(GTK_WINDOW_TOPLEVEL, "个人修改密码", FALSE, 300, 400);
	g_signal_connect_swapped(GTK_WINDOW(change.window), "destroy", G_CALLBACK(login_stu_change_ret_ctrl), change.window);
	table = gtk_table_new(4, 4, TRUE);
	gtk_container_add(GTK_CONTAINER(change.window), table);
	gtk_widget_show(table);

	label = gtk_label_new("原密码：");
	gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 0, 1);
	gtk_widget_show(label);
	change.password = create_entry(30, TRUE, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table), change.password, 1, 3, 0, 1);

	label = gtk_label_new("新密码：");
	gtk_table_attach_defaults(GTK_TABLE(table),label, 0, 1, 1, 2);
	gtk_widget_show(label);
	change.new_password = create_entry(30, TRUE, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table), change.new_password, 1, 3, 1, 2);

	label = gtk_label_new("重新输入：");
	gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 2, 3);
	gtk_widget_show(label);
	change.re_password = create_entry(30, TRUE, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table), change.re_password, 1, 3, 2, 3);
	
	button = gtk_button_new_with_label("确	定");
	g_signal_connect(button, "clicked", G_CALLBACK(login_stu_change_message_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 2, 3, 4);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("取	消");
	g_signal_connect(button, "clicked", G_CALLBACK(login_stu_change_ret_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 2, 4, 3, 4);
	gtk_widget_show(button);


}

void login_sort_ret_ctrl(GtkWidget *widget, gpointer data){//从排序函数返回到管理员菜单
	gtk_widget_hide(sort.window);
    gtk_widget_show(login_admin.window);
}

void login_sort_ctrl(GtkWidget *widget , gpointer data){ //从管理员菜单进入排序界面
    gtk_widget_hide(login_admin.window);
    gtk_admin_sort_view();
}

void login_sort_message_ctrl(GtkWidget *widget, gpointer data){ //对不同的选择进行排序实现的函数
    GtkWidget *message;
    GtkWidget *button;

    int (*comp)(const void *, const void *) = NULL;
    message = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_NONE, NULL);
    button = gtk_button_new_from_stock(GTK_STOCK_OK);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), message);
    gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
    gtk_widget_show(button);
    comp = comp_name;
    switch(chose){
        case 1: //用户名
            comp = comp_name;
            break;
        case 2: //高数成绩
            comp = comp_math;
            break;
        case 3: //英语
            comp = comp_english;
            break;
        case 4: //c语言
            comp = comp_C_program;
            break;
        case 5://计算机
            comp = comp_computer;
            break;
        case 6://体育
            comp = comp_PE;
            break;
        case 7://总分排名
            comp = comp_score;
            break;
        default :
            break;
    }
    
    if(sort_mod(comp) != 0){
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "排序失败！");
        gtk_widget_show(message);
        return ;
    }
    else{
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "排序成功 ！");
        flag = 1;
        gtk_widget_show(message);
    }
}

void login_admin_add_message_view(GtkWidget *widget, gpointer data){  //对不同的添加信息进行表达的函数
	GtkWidget *message;
	GtkWidget *button;
	char id[30];
	stu *node = NULL;

	strcpy(id, gtk_entry_get_text(GTK_ENTRY(add.id)));                //对id进行赋
	
	message = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_NONE,NULL);
	button = gtk_button_new_from_stock(GTK_STOCK_OK);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy),message);
	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message)->action_area)), button); //将按钮插件放入
	gtk_widget_show(button);

	if(find_id_exist(head,id)){																	//下面到结束的代码就是判断是否存在学号，如果不存在申请一个结点的空间然后存入链表
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"学号已存在"); 
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(id, "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"学号不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.name)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"姓名不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.password)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"密码不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.classes)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"班级不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.score_math)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"高数成绩不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.score_english)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"英语成绩不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.score_computer)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"计算机成绩不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.score_C_program)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"C语言成绩不能为空！");
		gtk_widget_show(message);
		return;
	}
	else if(!strcmp(gtk_entry_get_text(GTK_ENTRY(add.score_PE)), "")){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"体育成绩不能为空！");
		gtk_widget_show(message);
		return;
	}

	node = create();
	if(node == NULL){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"添加失败");
		gtk_widget_show(message);
		return;
	}
	else{
		strcpy(node->id,id);
		strcpy(node->name,gtk_entry_get_text(GTK_ENTRY(add.name)));
		strcpy(node->password,gtk_entry_get_text(GTK_ENTRY(add.password)));
		strcpy(node->classes,gtk_entry_get_text(GTK_ENTRY(add.classes)));
		strcpy(node->score.math,gtk_entry_get_text(GTK_ENTRY(add.score_math)));
		strcpy(node->score.english,gtk_entry_get_text(GTK_ENTRY(add.score_english)));
		strcpy(node->score.computer,gtk_entry_get_text(GTK_ENTRY(add.score_computer)));
		strcpy(node->score.C_program,gtk_entry_get_text(GTK_ENTRY(add.score_C_program)));
		strcpy(node->score.PE,gtk_entry_get_text(GTK_ENTRY(add.score_PE)));
		strcpy(node->age,gtk_entry_get_text(GTK_ENTRY(add.age)));

		insert_end(head,node);
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"成功添加！");
		flag = 1;
		gtk_widget_show(message);
	}

}

void login_admin_add_view(){       //添加学生信息的界面，这个我简直不想写注释。。。都能看懂
	GtkWidget *button;
    GtkWidget *table;
    GtkWidget *label;
    GtkWidget *table2;

    add.window = create_window(GTK_WINDOW_TOPLEVEL,"管理员添加学生信息",FALSE, 400, 400);
    g_signal_connect_swapped(GTK_WINDOW(add.window), "destroy", G_CALLBACK(login_add_ret_ctrl),add.window);
    table = gtk_table_new(9,3,TRUE);
    gtk_container_add(GTK_CONTAINER(add.window),table);
    gtk_widget_show(table);

    label = gtk_label_new("请输入相应信息： ");
   gtk_table_attach_defaults(GTK_TABLE(table),label,0,3,0,1);
	gtk_widget_show(label);
	label = gtk_label_new("学  号：");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,1,2);
	gtk_widget_show(label);
	add.id = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table),add.id,1,3,1,2);
	label = gtk_label_new("姓  名：");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,2,3);
	gtk_widget_show(label);
	add.name = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table),add.name,1,3,2,3);
	label = gtk_label_new("密  码：");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,3,4);
	gtk_widget_show(label);
	add.password = create_entry(30,TRUE,FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table),add.password,1,3,3,4);
	label = gtk_label_new("班  级：");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,4,5);
	gtk_widget_show(label);
	add.classes = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table),add.classes,1,3,4,5);


	table2 = gtk_table_new(5,2,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table),table2,0,3,5,9);
	gtk_widget_show(table2);
	label = gtk_label_new("高数成绩：");
	gtk_table_attach_defaults(GTK_TABLE(table2),label,0,1,0,1);
	gtk_widget_show(label);
	add.score_math = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table2),add.score_math,1,2,0,1);
	label = gtk_label_new("英语成绩：");
	gtk_table_attach_defaults(GTK_TABLE(table2),label,0,1,1,2);
	gtk_widget_show(label);
	add.score_english = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table2),add.score_english,1,2,1,2);
	label = gtk_label_new("C语言成绩：");
	gtk_table_attach_defaults(GTK_TABLE(table2),label,0,1,2,3);
	gtk_widget_show(label);
	add.score_C_program = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table2),add.score_C_program,1,2,2,3);
    label = gtk_label_new("计算机成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0,1,3,4);
    gtk_widget_show(label);
    add.score_computer = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2),add.score_computer,1,2,3,4);
    label = gtk_label_new("体育成绩: ");
    gtk_table_attach_defaults(GTK_TABLE(table2),label, 0,1,4,5);
    gtk_widget_show(label);
    add.score_PE = create_entry(30,TRUE,TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2),add.score_PE,1,2,4,5);

	label = gtk_label_new("年  龄：");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,9,10);
	gtk_widget_show(label);
	add.age = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table),add.age,1,3,9,10);

    button = gtk_button_new_with_label("确  定");
	g_signal_connect(button,"clicked",G_CALLBACK(login_admin_add_message_view),NULL);  //确定后回调对于添加结果的不同情况的表达的函数
	gtk_table_attach_defaults(GTK_TABLE(table),button,0,1,10,11);
	gtk_widget_show(button);
	button = gtk_button_new_with_label("取  消");
	g_signal_connect(button,"clicked",G_CALLBACK(login_add_ret_ctrl),NULL);     //返回到管理员菜单
	gtk_table_attach_defaults(GTK_TABLE(table),button,2,3,10,11);
	gtk_widget_show(button);
}

void gtk_admin_inq_view(){                //选择以什么方式查询的界面
    GtkWidget *button;
    GtkWidget *table;
    GtkWidget *label;
    GSList *group;
    /*
	 *这个函数采用的方式就是group来实现的不同的选择，且是单选
	 *具体方式就是第一个选项参数为NULL，之后的所有的选项参数都是group，然后需要对group精心赋值。
	 *所有的选项对应的都是inq.radio
	 */
    inq.window = create_window(GTK_WINDOW_TOPLEVEL, "查询学生信息窗口", FALSE, 300, 500);
    g_signal_connect_swapped(GTK_WINDOW(inq.window), "destroy", G_CALLBACK(login_inq_ret_ctrl), inq.window);
    table = gtk_table_new(11,2,TRUE);
    gtk_container_add(GTK_CONTAINER(inq.window), table);
    gtk_widget_show(table);
    button = gtk_button_new_with_label("查看所有学生信息");
    g_signal_connect(button, "clicked", G_CALLBACK(login_inq_all_view), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 2, 0, 1);
    gtk_widget_show(button);
    
    inq.radio = gtk_radio_button_new_with_label(NULL, "按照姓名查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled1),NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio , 0, 2, 1, 2);
	gtk_widget_show(inq.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照高数成绩查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled2), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 2, 3);
    gtk_widget_show(inq.radio);
    
     group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照英语成绩查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled3), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 3 , 4);
    gtk_widget_show(inq.radio);
    
     group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照C语言成绩查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled4), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 4, 5);
    gtk_widget_show(inq.radio);
    
     group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照计算机成绩查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled5), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 5, 6);
    gtk_widget_show(inq.radio);

     group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照体育成绩查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled6), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 6, 7);
    gtk_widget_show(inq.radio);
    
     group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照排名查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled7), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 7, 8);
    gtk_widget_show(inq.radio);
    
     group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(inq.radio));
    inq.radio = gtk_radio_button_new_with_label(group,"按照学号查询：");
    g_signal_connect(inq.radio, "toggled", G_CALLBACK(login_toggled8), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.radio, 0 ,2 , 8, 9);
    gtk_widget_show(inq.radio);
    
    label = gtk_label_new("请输入要查找的内容：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0,  1, 9, 10);
    gtk_widget_show(label);
    inq.entry = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), inq.entry, 1, 2, 9, 10);
    
    button = gtk_button_new_with_label("确   定");
    g_signal_connect(button, "clicked", G_CALLBACK(login_inq_message_ctrl), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 10, 11);
    gtk_widget_show(button);
    
    button = gtk_button_new_with_label("取   消");
    g_signal_connect(button, "clicked", G_CALLBACK(login_inq_ret_ctrl), inq.window);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 10, 11);
    gtk_widget_show(button);

}

void login_inq_all_view(GtkWidget *widget, gpointer data){    //对所有学生资料的显示，也是做了一个标签页，同之前的查看。
    GtkWidget *notebook;
    GtkWidget *textview;
	GtkTextBuffer *buffer;
    GtkWidget *label;
    GtkWidget *button;
    GtkWidget *dialog;
    stu *p = NULL;
    gchar play[300] = "\0";
    
    dialog = gtk_dialog_new_with_buttons("所有学生的资料：", GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, NULL);
    gtk_widget_set_size_request(GTK_WIDGET(dialog), 800, 500);
    gtk_widget_show(dialog);
    
    notebook = gtk_notebook_new(); //创建新的笔记本
    gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(dialog) ->vbox)), notebook);
	gtk_widget_show(notebook);
    p = head -> next;
    while( p != head){
        sprintf(play, "学号：%s\n用户名:%s\n密码:%s\n班级:%s\n年龄:%s\n高数成绩:%s\n英语成绩:%s\nC语言成绩:%s\n计算机成绩:%s\n体育成绩:%s\n总分排名:%s\n",p ->id, p ->name, p ->password, p->classes, p ->age, p ->score.math, p->score.english, p->score.C_program, p->score.computer, p ->score.PE, p->rank);
        textview = gtk_text_view_new();
        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));  //取得当前页码标签
        gtk_text_buffer_set_text(buffer, play, -1);
        label = gtk_label_new(p ->name);// 标签名字
        gtk_notebook_append_page(GTK_NOTEBOOK(notebook), textview, label);
        gtk_widget_show(textview);
        p = p -> next;
    }
    button = gtk_button_new_with_label("确  认");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), dialog);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog) -> action_area), button, TRUE, TRUE, 0);
    gtk_widget_show(button);
}
    
void login_admin_del_view(){    //显示删除界面， 又是毫无难点的程序。。自己看
    GtkWidget *button;
    GtkWidget *table;
    GtkWidget *label;
    
    del.window = create_window(GTK_WINDOW_TOPLEVEL,"删除对应学生", FALSE, 300, 200);
    g_signal_connect_swapped(GTK_WINDOW(del.window), "destroy", G_CALLBACK(login_del_ret_ctrl), del.window);
    table = gtk_table_new(2, 4, TRUE);
    gtk_container_add(GTK_CONTAINER(del.window), table);
    gtk_widget_show(table);
    label = gtk_label_new("请输入你想删除的人的学号：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 4, 0 ,1);
    gtk_widget_show(label);
    del.entry = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), del.entry, 1, 3, 1, 2);
    gtk_widget_show(del.entry);
    
    button = gtk_button_new_with_label("确   定");
    g_signal_connect(button, "clicked", G_CALLBACK(login_admin_del_message_view), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 2, 3, 4);
    gtk_widget_show(button);
    
    button = gtk_button_new_with_label("取   消");
    g_signal_connect(button, "clicked", G_CALLBACK(login_del_ret_ctrl), del.window);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 2, 4, 3, 4);
    gtk_widget_show(button);
}

void login_admin_del_message_view(GtkWidget *widget , gpointer data){   //对于删除结果的不同的表达，问题在于del_id的返回值
    GtkWidget *message;
    GtkWidget *button;
    char id[30];
    
    strcpy(id, gtk_entry_get_text(GTK_ENTRY(del.entry)));
    message = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_NONE, NULL);
    button = gtk_button_new_from_stock(GTK_STOCK_OK);
    
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy),message);
    gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
    gtk_widget_show(button);
    if(del_id(head , id)){																						//这之上的这块函数都是做消息框的界面，下面是判断
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "删除失败！");
        gtk_widget_show(message);
        return ;
    }
    else{
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "删除成功！");
        flag = 1;
        gtk_widget_show(message);
    }
    
}

void login_admin_change_view(){  //修改学生信息的窗口，毫无难点。。
    GtkWidget *button;
    GtkWidget *table;
    GtkWidget *table2;
    GtkWidget *label;
    
    change.window = create_window(GTK_WINDOW_TOPLEVEL, "修改学生信息窗口", FALSE, 300, 400);
    g_signal_connect_swapped(GTK_WINDOW(change.window), "destroy", G_CALLBACK(login_change_ret_ctrl), change.window);
    table = gtk_table_new(11, 3, TRUE);
    gtk_container_add(GTK_CONTAINER(change.window), table);
    gtk_widget_show(table);
    
    label = gtk_label_new("修改学号：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 0, 1);
    gtk_widget_show(label);
    change.entry =  create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), change.entry, 1, 3, 0, 1);
    
    
    label = gtk_label_new("新学号：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 1, 2);
    gtk_widget_show(label);
    change.id = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), change.id, 1, 3, 1, 2);
    
     label = gtk_label_new("新姓名：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 2, 3);
    gtk_widget_show(label);
    change.name = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), change.name, 1, 3, 2, 3);   
    
    label = gtk_label_new("新密码：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 3, 4);
    gtk_widget_show(label);
    change.password = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), change.password, 1, 3, 3, 4);
    
    label = gtk_label_new("新班级：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 4, 5);
    gtk_widget_show(label);
    change.classes = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), change.classes, 1, 3, 4, 5);
    
    table2 = gtk_table_new(5,2,TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), table2, 0, 3, 5, 9);
    gtk_widget_show(table2);
    
    label = gtk_label_new("高数成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0, 1, 0, 1);
    gtk_widget_show(label);
    change.score_math = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2) ,change.score_math, 1, 2, 0, 1);
    
    label = gtk_label_new("高数成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0, 1, 0, 1);
    gtk_widget_show(label);
    change.score_math = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2) ,change.score_math, 1, 2, 0, 1);
    
    label = gtk_label_new("英语成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0, 1, 1, 2);
    gtk_widget_show(label);
    change.score_english = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2) ,change.score_english, 1, 2, 1, 2);
    
    label = gtk_label_new("C语言成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0, 1, 2, 3);
    gtk_widget_show(label);
    change.score_C_program = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2) ,change.score_C_program, 1, 2, 2, 3);
    
    label = gtk_label_new("计算机成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0, 1, 3, 4);
    gtk_widget_show(label);
    change.score_computer = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2) ,change.score_computer, 1, 2, 3, 4);
    
    label = gtk_label_new("体育成绩：");
    gtk_table_attach_defaults(GTK_TABLE(table2), label, 0, 1, 4, 5);
    gtk_widget_show(label);
    change.score_PE = create_entry(30, TRUE, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table2) ,change.score_PE, 1, 2, 4, 5);
    
    label = gtk_label_new("新年龄：");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 9, 10);
    gtk_widget_show(label);
    change.age = create_entry(30, 30, TRUE);
    gtk_table_attach_defaults(GTK_TABLE(table), change.age, 1, 3, 9, 10);
    
    button = gtk_button_new_with_label("确   定");
    g_signal_connect(button, "clicked", G_CALLBACK(login_admin_add_message_view), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 10, 11);
    gtk_widget_show(button);
    
    button = gtk_button_new_with_label("取   消");
    g_signal_connect(button, "clicked", G_CALLBACK(login_change_ret_ctrl), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 2, 3, 10, 11);
    gtk_widget_show(button);
}
void login_change_message_view(GtkWidget *widget, gpointer data){  //对于修改结果的不同情况的返回，也是以消息框配一个系统自带的按钮实现的
   

	GtkWidget *message;
	GtkWidget *button;
	char id[20];
	stu *p=NULL;
	stu *temp=NULL;
	p=create();
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(change.entry)));

	temp = find_id_exist(head,id);
	//puts(cur->id);
		//通过id查找，插入后删除


	message = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE,NULL);
	button = gtk_button_new_from_stock(GTK_STOCK_OK);
	g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),message);
	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message)->action_area)),button);
	gtk_widget_show(button);
	if(NULL == temp){
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"修改失败");
		gtk_widget_show(message);
		free(p);
		return;
	}
	else{
		strcpy(id,gtk_entry_get_text(GTK_ENTRY(change.id)));

		if(NULL!=find_id_exist(head,id)){
			gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"学号已存在");
			gtk_widget_show(message);
			free(p);
			return;
		}
		else{
			strcpy(p->id,gtk_entry_get_text(GTK_ENTRY(change.id)));
			strcpy(p->name,gtk_entry_get_text(GTK_ENTRY(change.name)));
			strcpy(p->password,gtk_entry_get_text(GTK_ENTRY(change.password)));
			strcpy(p->classes,gtk_entry_get_text(GTK_ENTRY(change.classes)));
			strcpy(p->score.math,gtk_entry_get_text(GTK_ENTRY(change.score_math)));
			strcpy(p->score.english,gtk_entry_get_text(GTK_ENTRY(change.score_english)));
			strcpy(p->score.computer,gtk_entry_get_text(GTK_ENTRY(change.score_computer )));
			strcpy(p->age,gtk_entry_get_text(GTK_ENTRY(change.age)));


			strcpy(temp->id,p->id);
			strcpy(temp->name,p->name);
			strcpy(temp->password,p->password);
			strcpy(temp->classes,p->classes);
			strcpy(temp->score.math,p->score.math);
			strcpy(temp->score.english,p->score.english);
			strcpy(temp->score.computer,p->score.computer);
			strcpy(temp->age,p->age);
			gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message),"修改成功");
			flag=1;									// 数据修改标记变量
			gtk_widget_show(message);
			free(p);
			}

	}
}

void gtk_admin_sort_view(){             //排序窗口的创建，和之前那个查询的窗口是一模一样的模式
    GtkWidget *button;
    GtkWidget *table;
    GSList *group;
    GtkWidget *label;
    
    sort.window = create_window(GTK_WINDOW_TOPLEVEL, "排序学生信息", FALSE, 250, 400);
    g_signal_connect_swapped(GTK_WINDOW(sort.window), "destroy", G_CALLBACK(login_sort_ret_ctrl), sort.window);
    table = gtk_table_new(9, 2, TRUE);
    gtk_container_add(GTK_CONTAINER(sort.window), table);
    gtk_widget_show(table);
    
    label = gtk_label_new("请选择排序方式");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 2, 0, 1);
    gtk_widget_show(label);
    
    sort.radio = gtk_radio_button_new_with_label(NULL, "姓       名");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled1), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 1, 2);
    gtk_widget_show(sort.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(sort.radio));
    sort.radio = gtk_radio_button_new_with_label(group, "数学成绩");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled2), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 2, 3);
    gtk_widget_show(sort.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(sort.radio));
    sort.radio = gtk_radio_button_new_with_label(group, "英语成绩");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled3), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 3, 4);
    gtk_widget_show(sort.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(sort.radio));
    sort.radio = gtk_radio_button_new_with_label(group, "C语言成绩");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled4), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 4, 5);
    gtk_widget_show(sort.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(sort.radio));
    sort.radio = gtk_radio_button_new_with_label(group, "计算机成绩");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled5), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 5, 6);
    gtk_widget_show(sort.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(sort.radio));
    sort.radio = gtk_radio_button_new_with_label(group, "体育成绩");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled6), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 6, 7);
    gtk_widget_show(sort.radio);
    
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(sort.radio));
    sort.radio = gtk_radio_button_new_with_label(group, "总  分");
    g_signal_connect(sort.radio, "toggled", G_CALLBACK(login_toggled7), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), sort.radio, 0, 2, 7, 8);
    gtk_widget_show(sort.radio);
    
    button = gtk_button_new_with_label("确   定");
    g_signal_connect(button, "clicked", G_CALLBACK(login_sort_message_ctrl), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 8, 9);
    gtk_widget_show(button);
    
    button = gtk_button_new_with_label("取   消");
    g_signal_connect(button, "clicked", G_CALLBACK(login_sort_ret_ctrl), NULL);
    gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 8, 9);
    gtk_widget_show(button);
    
}

void login_exit_message_view(GtkWidget *widget, gpointer data){           //退出的时候的信息的返回，分修改和没修改信息两种情况
    GtkWidget *message;
    GtkWidget *button;
    
    if(flag == 0){//未修改信息，直接打印信息框，提示是否退出
        message = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_NONE,NULL);
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "您确定退出学生成绩管理系统？");
        button = gtk_button_new_from_stock(GTK_STOCK_OK);
        if(strcmp("管理员", nameid) == 0){
            g_signal_connect(button, "clicked", G_CALLBACK(login_admin_ret_ctrl), NULL);
        }
        else {
            g_signal_connect(button, "clicked", G_CALLBACK(login_stu_ret_ctrl), NULL);
        }
        g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), button);
        gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
        gtk_widget_show(button);
        
        button = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
        g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy),message);
        gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
		gtk_widget_show(button);
		gtk_widget_show(message);
        return ;
    }
        else{//修改了信息，打印提示框提示保存数据且只有一个按钮
            message = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,GTK_MESSAGE_INFO, GTK_BUTTONS_NONE, NULL);
            gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(message), "您修改了数据\n请先保存数据！");
            button = gtk_button_new_from_stock(GTK_STOCK_OK);
            g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), message);
            gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(message) -> action_area)), button);
            gtk_widget_show(button);
            gtk_widget_show(message);
        } 
}

void login_view(){  //登录的界面
    GtkWidget *label;
	GtkWidget *table;
	GtkWidget *button;
	GSList *group;

	gint i = 0;
	gchar buffer[30] = "\0";

	for(i = 0;i < 4;i++){           //随机一个验证码2333333
		srand((unsigned)time(NULL) + i);
		buffer[i] = "123456789abcedfghijklmnopqrstuzwxyz"[rand() % 35];
	}

	login.window = create_window(GTK_WINDOW_TOPLEVEL,"欢迎使用学生管理系统",FALSE,300,300);  
	g_signal_connect(login.window, "destroy",G_CALLBACK(exit), NULL);
	table = gtk_table_new(3,2,TRUE);
	gtk_container_add(GTK_CONTAINER(login.window),table);
	gtk_widget_show(table);
	label = gtk_label_new("用户名 ： ");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,0,1);
	gtk_widget_show(label);
	login.id = create_entry(30,TRUE,TRUE);
	gtk_table_attach_defaults(GTK_TABLE(table), login.id,1,2,0,1);
	label = gtk_label_new("密  码 : ");
	gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,1,2);
	gtk_widget_show(label);
	login.password = create_entry(30,TRUE,FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table),login.password,1,2,1,2);
	login.label = gtk_label_new("验证码 : ");
	gtk_label_set_text(GTK_LABEL(login.label), buffer);
	gtk_table_attach_defaults(GTK_TABLE(table),login.label,0,1,2,3);
	gtk_widget_show(login.label);
	login.identify_code = create_entry(30, TRUE, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table), login.identify_code, 1, 2, 2,3);
	login.radio = gtk_radio_button_new_with_label(NULL, "学  生");                   //对于学生和老师这两种情况还是用一个group来进行单选
	g_signal_connect(login.radio, "toggled", G_CALLBACK(login_toggled), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table),login.radio, 0,1,3,4);
	gtk_widget_show(login.radio);
	group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(login.radio));
	login.radio = gtk_radio_button_new_with_label(group, "管理员");
	g_signal_connect(login.radio, "toggled",G_CALLBACK(login_toggled), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), login.radio,1,2,3,4);
	gtk_widget_show(login.radio);


	button = gtk_button_new_with_label("登   陆");                           
	g_signal_connect(button, "clicked", G_CALLBACK(login_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 0,1,4,5);
	gtk_widget_show(button);
	button = gtk_button_new_with_label("取  消");
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked",G_CALLBACK(gtk_widget_destroy), login.window);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 1,2,4,5);
	gtk_widget_show(button);
}




void login_admin_view(){      //管理员菜单，完全无难点
	GtkWidget *button;
	GtkWidget *table;
	login_admin.window =create_window(GTK_WINDOW_TOPLEVEL,"欢迎老师您进入管理系统", FALSE, 600, 200);
	g_signal_connect(login_admin.window, "destroy", G_CALLBACK(login_exit_ctrl), NULL);
	table = gtk_table_new(1, 7, TRUE);
	gtk_container_add(GTK_CONTAINER(login_admin.window),table);
	gtk_widget_show(table);

	button = gtk_button_new_with_label("添加学生\n 信息");
	g_signal_connect(button,"clicked",G_CALLBACK(login_add_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button,0, 1, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("删除学生\n 信息");
	g_signal_connect(button,"clicked",G_CALLBACK(login_del_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("保   存");
	g_signal_connect(button, "clicked", G_CALLBACK(login_save_message_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 2, 3, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("修   改");
	g_signal_connect(button, "clicked", G_CALLBACK(login_change_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 3, 4, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("查   询");
	g_signal_connect(button, "clicked", G_CALLBACK(login_inq_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 4, 5, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("排   序");
	g_signal_connect(button, "clicked", G_CALLBACK(login_sort_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 5, 6, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("退   出");
	g_signal_connect(button, "clicked", G_CALLBACK(login_exit_message_view), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 6, 7, 0 ,1);
	gtk_widget_show(button);
}


void login_stu_change_ctrl(GtkWidget *widget, gpointer data){ //从学生登录窗口进入学生更改信息窗口
    gtk_widget_hide(login_stu.window);
    login_stu_change_view();
}

void login_student_view(){    //更改信息的窗口也是如此的简单= =
    GtkWidget *button;
	GtkWidget *table;

	login_stu.window = create_window(GTK_WINDOW_TOPLEVEL, "欢迎使用学管理系统", FALSE, 300, 200);
	g_signal_connect(login_stu.window, "destroy", G_CALLBACK(login_exit_ctrl), NULL);
	table = gtk_table_new(1, 3, TRUE);
	gtk_container_add(GTK_CONTAINER(login_stu.window), table);
	gtk_widget_show(table);
	button = gtk_button_new_with_label("查看成绩信息");
	g_signal_connect(button, "clicked", G_CALLBACK(login_stu_inq_message_view), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button , 0, 1, 0, 1);
	gtk_widget_show(button);
	
	button = gtk_button_new_with_label("修改个人信息");
	g_signal_connect(button, "clicked", G_CALLBACK(login_stu_change_ctrl), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 0, 1);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("退出系统");
	g_signal_connect(button, "clicked", G_CALLBACK(login_exit_message_view), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table),button, 2, 3, 0, 1);
	gtk_widget_show(button);
	
}

void login_stu_inq_message_view(GtkWidget *widget,gpointer data){ //这个就是当查询的时候，做一个与之前管理员查询类似的标签界面
	GtkWidget *notebook;
	GtkWidget *textview;
	GtkTextBuffer *buffer;
	GtkWidget *label;
	GtkWidget *button;
	GtkWidget *dialog;
	stu *p = NULL;
	gchar str[300] = "\0";

	dialog = gtk_dialog_new_with_buttons("个人信息", GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(dialog), 800, 400);
	gtk_widget_show(dialog);

	notebook = gtk_notebook_new();
	gtk_container_add(GTK_CONTAINER(GTK_BOX(GTK_DIALOG(dialog) -> vbox)), notebook);
	gtk_widget_show(notebook);

	sprintf(str, "学号：%s\n用户名：%s\n密码：%s\n班级：%s\n年龄：%s\n高数成绩：%s\n英语成绩：%s\nC语言成绩：%s\n计算机成绩：%s\n体育成绩：%s\n总分排名：%s\n", my -> id, my -> name, my -> password, my -> classes, my -> age, my -> score.math, my -> score.english, my -> score.C_program, my -> score.computer, my -> score.PE, my -> rank);
	textview = gtk_text_view_new();
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
	gtk_text_buffer_set_text(buffer, str, -1);

	label = gtk_label_new(my -> name);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook), textview, label);
	gtk_widget_show(textview);

	button=gtk_button_new_with_label("确  定");
	g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_widget_destroy),dialog);	
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->action_area),button,TRUE,TRUE,0);
	gtk_widget_show(button);
}


void login_stu_change_ret_ctrl(GtkWidget *widget, gpointer data){ //从学生信息修改返回到学生菜单
    gtk_widget_hide(change.window);
    gtk_widget_show(login_stu.window);
}

void login_stu_ret_ctrl(GtkWidget *widget , gpointer data){    //从学生菜单返回到登录界面
    gtk_widget_hide(login_stu.window);
    gtk_widget_show(login.window);
}


 

gpointer create_entry(gint max, gboolean editable, gboolean visible){  //这是所有创建的输入文本框的函数
	GtkWidget *entry;
	entry = gtk_entry_new();//创建新的文本输入框
	gtk_entry_set_max_length(GTK_ENTRY(entry),max);//定义最长输入字节数
	gtk_entry_set_editable(GTK_ENTRY(entry),editable);//定义可编辑性
	gtk_entry_set_visibility(GTK_ENTRY(entry),visible);//定义显示性
	gtk_widget_show(entry);//打印出来
	return entry;
}



gpointer create_window(GtkWindowType type, const gchar *title, gboolean resizable, gint width, gint height){
	GtkWidget *window;
	window = gtk_window_new(type); //创建以type参数为格式的窗口
	gtk_window_set_title(GTK_WINDOW(window),title);//窗口名
	gtk_window_set_resizable(GTK_WINDOW(window),resizable);//窗口的可缩放性
	gtk_widget_set_size_request(GTK_WIDGET(window), width, height);//高度宽度
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);//位置
	gtk_widget_show(window);//显示窗口
	return window;
}

int main(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	pro.login = &login;
	pro.inq = &inq;
	pro.del = &del;
	pro.change = &change;
	pro.sort = &sort;
	my = (stu *)calloc(1, sizeof(stu));        //先对my和manager申请一个单位空间
	manager = (admin *)calloc(1,sizeof(admin));
	strcpy(manager -> id, "zhr");   //设置一个管理员23333
	strcpy(manager -> password, "5256");

	head = create();                //创建头结点
	if(init_head(head) != 0)        //初始化头结点
		exit(0);
	data_init_mod();               //初始化文件

	login_view();                   //进入第一个函数。。
	gtk_main();
	destory(head);
	free(my);

	return 0;
}

