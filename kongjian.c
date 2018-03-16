#include <gtk/gtk.h>  
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
gint N=0;
typedef struct Node{
    char name[20];
    char sex[5];
    char class[20];
    char school[10];
    char tel[10];
    char num[20];
    char building[20];
    char dor[6];
    struct Node *next;
}node;

typedef struct Linklist{
    node *head;
    node *tail;
    int length;
}linklist;

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

typedef struct aa{
    GtkWidget *entry;
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *entry3;
    GtkWidget *entry4;
    GtkWidget *entry5;
    GtkWidget *entry6;
    GtkWidget *entry7;
}q;

char *name[20];     
char *sex[5];       
char *class[20];    
char *school[10];   
char *tel[10];      
char *num[20];      
char *building[20]; 
char *dor[6];   

char *cha;

int i=0; 
/*
void click(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    cha=(char*)malloc(sizeof(char)*50);  
    strcpy(cha,word);
     g_print("用户名是：%s\n",cha);
     for(int a=0;a<=N;a++){
	 if(strcmp(name[a],cha)==0)
	     i=a;
	 printf("i=%d",i);
     }
}

void on_clicked1(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    name[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(name[N],word);
     g_print("用户名是：%s\n",name[N]);
     g_print("N=：%d\n",N);
}

void on_clicked2(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    sex[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(sex[N],word);
     g_print("用户名是：%s\n",sex[N]);
} 
void on_clicked3(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    class[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(class[N],word);
     g_print("用户名是：%s\n",class[N]);
}
void on_clicked4(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    school[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(school[N],word);
     g_print("用户名是：%s\n",school[N]);
}
void on_clicked5(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    tel[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(tel[N],word);
     g_print("用户名是：%s\n",tel[N]);
}
void on_clicked6(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    num[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(num[N],word);
     g_print("用户名是：%s\n",num[N]);
}
void on_clicked7(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    building[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(building[N],word);
     g_print("用户名是：%s\n",building[N]);
}
void on_clicked8(GtkWidget *button,GtkWidget *entry1){
    const char *word = gtk_entry_get_text(GTK_ENTRY(entry1));  
    dor[N]=(char*)malloc(sizeof(char)*50);  
    strcpy(dor[N],word);
     g_print("用户名是：%s\n",dor[N]);
     N++;
}*/ 

void show_info(GtkWidget *widget, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,
    GTK_DIALOG_DESTROY_WITH_PARENT,
    GTK_MESSAGE_INFO,
    GTK_BUTTONS_OK,"添加完成", "title");
    gtk_window_set_title(GTK_WINDOW(dialog), "信息");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void clear(GtkWidget *button,gpointer entry){
gtk_entry_set_text(entry, "" );
}
void deal(void) {
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *button;
    GtkWidget *entry;
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *entry3;
    GtkWidget *entry4;
    GtkWidget *entry5;
    GtkWidget *entry6;
    GtkWidget *entry7;
    GtkWidget *label;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *label3;
    GtkWidget *label4;
    GtkWidget *label5;
    GtkWidget *label6;
    GtkWidget *label7;
    GtkWidget *label8;

    /*stu *p;
    p=(stu *)malloc(sizeof(stu));
    p->name=entry;
    p->sex=entry1;
    p->class=entry2;
    p->school=entry3;
    p->tel=entry4;
    p->num=entry5;
    p->building=entry6;
    p->dor=entry7;*/
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "添加学生信息");  

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
    
    gtk_widget_set_size_request(window, 800,600);  

    table=gtk_table_new(20,10,TRUE);
   //设置按钮 
    button=gtk_button_new_with_label("添加");
   //创建文本框
    entry=gtk_entry_new();
    entry1=gtk_entry_new();
    entry2=gtk_entry_new();
    entry3=gtk_entry_new();
    entry4=gtk_entry_new();
    entry5=gtk_entry_new();
    entry6=gtk_entry_new();
    entry7=gtk_entry_new();
    
    gtk_entry_set_text(GTK_ENTRY(entry), " "); 
    gtk_entry_set_text(GTK_ENTRY(entry1), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry2), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry3), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry4), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry5), " ");
    gtk_entry_set_text(GTK_ENTRY(entry6), " ");
    gtk_entry_set_text(GTK_ENTRY(entry7), " ");
    //创建标签
    label=gtk_label_new("  ");
    label1=gtk_label_new("姓名");
    label2=gtk_label_new("性别");
    label3=gtk_label_new("班级");
    label4=gtk_label_new("学号");
    label5=gtk_label_new("电话号码");
    label6=gtk_label_new("身份证号");
    label7=gtk_label_new("宿舍楼");
    label8=gtk_label_new("寝室号");
    //标签添加进容器
    gtk_table_attach_defaults(GTK_TABLE(table),label,0,40,0,5);
    gtk_table_attach_defaults(GTK_TABLE(table),label1,0,4,5,10);
    gtk_table_attach_defaults(GTK_TABLE(table),label2,0,4,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),label3,0,4,15,20);
    gtk_table_attach_defaults(GTK_TABLE(table),label4,0,4,20,25);
    gtk_table_attach_defaults(GTK_TABLE(table),label5,0,4,25,30);
    gtk_table_attach_defaults(GTK_TABLE(table),label6,0,4,30,35);
    gtk_table_attach_defaults(GTK_TABLE(table),label7,0,4,35,40);
    gtk_table_attach_defaults(GTK_TABLE(table),label8,0,4,40,45);
    //文本框添加进容器
    gtk_table_attach_defaults(GTK_TABLE(table),entry,5,15,5,10);
    gtk_table_attach_defaults(GTK_TABLE(table),entry1,5,15,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),entry2,5,15,15,20);
    gtk_table_attach_defaults(GTK_TABLE(table),entry3,5,15,20,25);
    gtk_table_attach_defaults(GTK_TABLE(table),entry4,5,15,25,30);
    gtk_table_attach_defaults(GTK_TABLE(table),entry5,5,15,30,35);
    gtk_table_attach_defaults(GTK_TABLE(table),entry6,5,15,35,40);
    gtk_table_attach_defaults(GTK_TABLE(table),entry7,5,15,40,45);

    gtk_table_attach_defaults(GTK_TABLE(table),button,40,50,50,55);
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked1),entry);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked2),entry1);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked3),entry2);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked4),entry3);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked5),entry4);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked6),entry5);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked7),entry6);  
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked8),entry7);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry1);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry2);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry3);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry4);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry5);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry6);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry7);  
    g_signal_connect(button, "clicked", G_CALLBACK(show_info),window);  
   //按钮添加进容器  
    //gtk_table_attach_defaults(GTK_TABLE(table),button,0,20,18,27);
    gtk_container_add(GTK_CONTAINER(window),table);
    gtk_widget_show_all(window);
}
void search_info(void){

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 800,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    
    GtkWidget *label;
    GtkWidget *label1;
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *button5;
    GtkWidget *button6;
    GtkWidget *button7;
    GtkWidget *button8;
//设置按钮标签
    button=gtk_button_new_with_label("学号查找");
    button1=gtk_button_new_with_label("身份证号查找");
    button2=gtk_button_new_with_label("学号查找");
    button3=gtk_button_new_with_label("电话号码查找");
    button4=gtk_button_new_with_label("身份证号查找");
    button5=gtk_button_new_with_label("姓名查找");
    button6=gtk_button_new_with_label("班级查找");
    button7=gtk_button_new_with_label("宿舍楼查找");
    button8=gtk_button_new_with_label("寝室查找");
/*设置标签*/
    label=gtk_label_new("精确查找");
    label1=gtk_label_new("模糊查找");
    button3=gtk_button_new_with_label("电话号码查找");
    button4=gtk_button_new_with_label("身份证号查找");
/*设置按钮尺寸*/
    gtk_widget_set_size_request(button,100,50);
    gtk_widget_set_size_request(button1,100,50);
    gtk_widget_set_size_request(button2,100,50);
    gtk_widget_set_size_request(button3,100,50);
    gtk_widget_set_size_request(button4,100,50);
    gtk_widget_set_size_request(button5,100,50);
    gtk_widget_set_size_request(button6,100,50);
    gtk_widget_set_size_request(button7,100,50);
    gtk_widget_set_size_request(button8,100,50);
    /*设置标签尺寸*/
    gtk_widget_set_size_request(label,100,50);
    gtk_widget_set_size_request(label1,100,50);
    /*添加所有控件到组合盒*/
    gtk_fixed_put(GTK_FIXED(fixed),label,20,20);
    gtk_fixed_put(GTK_FIXED(fixed),button1,120,70);
    gtk_fixed_put(GTK_FIXED(fixed),button2,220,120);
    gtk_fixed_put(GTK_FIXED(fixed),button3,320,170);
    gtk_fixed_put(GTK_FIXED(fixed),label1,20,170);
    gtk_fixed_put(GTK_FIXED(fixed),button4,120,220);
    gtk_fixed_put(GTK_FIXED(fixed),button5,220,270);
    gtk_fixed_put(GTK_FIXED(fixed),button6,320,320);
    gtk_fixed_put(GTK_FIXED(fixed),button7,420,370);
    gtk_fixed_put(GTK_FIXED(fixed),button8,520,420);

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);  
}

void  chazhao( GtkWidget *button6,gpointer data)
{ 
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 800,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    
    GtkWidget *entry;
    entry=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), " "); 
    
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *button5;
    GtkWidget *button9;
    GtkWidget *button7;
    GtkWidget *button8;
    GtkWidget *label;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *label3;
    GtkWidget *label4;
    GtkWidget *label5;
    GtkWidget *label6;
    GtkWidget *label7;
    GtkWidget *label8;

    button=gtk_button_new_with_label("查找");
    button1=gtk_button_new_with_label("姓名");
    button2=gtk_button_new_with_label("性别");
    button3=gtk_button_new_with_label("班级");
    button4=gtk_button_new_with_label("学号");
    button4=gtk_button_new_with_label("电话");
    button5=gtk_button_new_with_label("身份证");
    button7=gtk_button_new_with_label("宿舍楼");
    button8=gtk_button_new_with_label("寝室");
    label=gtk_label_new("");
    label1=gtk_label_new("");
    label2=gtk_label_new("");
    label3=gtk_label_new("");
    label4=gtk_label_new("");
    label5=gtk_label_new("");
    label6=gtk_label_new("");
    label7=gtk_label_new("");
    label8=gtk_label_new("");
   
   //设置标签内容 
    gtk_label_set_text(GTK_LABEL(label),"请输入查找的学号");
   
    gtk_label_set_text(GTK_LABEL(label1),name[i]);
    gtk_label_set_text(GTK_LABEL(label2),sex[i]);
    gtk_label_set_text(GTK_LABEL(label3),class[i]);
    gtk_label_set_text(GTK_LABEL(label4),school[i]);
    gtk_label_set_text(GTK_LABEL(label5),tel[i]);
    gtk_label_set_text(GTK_LABEL(label6),num[i]);
    gtk_label_set_text(GTK_LABEL(label7),building[i]);
    gtk_label_set_text(GTK_LABEL(label8),dor[i]);
     
   //设置构件大小 
    gtk_widget_set_size_request(label,120,50);
    gtk_widget_set_size_request(label1,100,50);
    gtk_widget_set_size_request(label2,100,50);
    gtk_widget_set_size_request(label3,100,50);
    gtk_widget_set_size_request(label4,100,50);
    gtk_widget_set_size_request(label5,100,50);
    gtk_widget_set_size_request(label6,100,50);
    gtk_widget_set_size_request(label7,100,50);
    gtk_widget_set_size_request(label8,100,50);
   
   //设置回调函数 

    gtk_widget_set_size_request(button,100,30);
    gtk_widget_set_size_request(button1,100,30);
    gtk_widget_set_size_request(button2,100,30);
    gtk_widget_set_size_request(button3,100,30);
    gtk_widget_set_size_request(button4,100,30);
    gtk_widget_set_size_request(button5,100,30);
    gtk_widget_set_size_request(button7,100,30);
    gtk_widget_set_size_request(button8,100,30);
    gtk_widget_set_size_request(entry,200,30);
   //放入构建 
    gtk_fixed_put(GTK_FIXED(fixed),label,40,40);
    gtk_fixed_put(GTK_FIXED(fixed),entry,160,50);
    gtk_fixed_put(GTK_FIXED(fixed),button,400,50);
    gtk_fixed_put(GTK_FIXED(fixed),button1,50,100);
    gtk_fixed_put(GTK_FIXED(fixed),button2,150,100);
    gtk_fixed_put(GTK_FIXED(fixed),button3,250,100);
    gtk_fixed_put(GTK_FIXED(fixed),button4,350,100);
    gtk_fixed_put(GTK_FIXED(fixed),button5,450,100);
    gtk_fixed_put(GTK_FIXED(fixed),button7,550,100);
    gtk_fixed_put(GTK_FIXED(fixed),button8,650,100);
    gtk_fixed_put(GTK_FIXED(fixed),label1,50,150);
    gtk_fixed_put(GTK_FIXED(fixed),label2,150,150);
    gtk_fixed_put(GTK_FIXED(fixed),label3,250,150);
    gtk_fixed_put(GTK_FIXED(fixed),label4,350,150);
    gtk_fixed_put(GTK_FIXED(fixed),label5,450,150);
    gtk_fixed_put(GTK_FIXED(fixed),label6,550,150);
    gtk_fixed_put(GTK_FIXED(fixed),label7,650,150);
    gtk_fixed_put(GTK_FIXED(fixed),label8,750,150);
    g_signal_connect(button, "clicked", G_CALLBACK(click),entry);  
    g_signal_connect(fixed, "destroy", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
    gtk_main();
}


void xianshi(GtkWidget *button6)
{

GtkWidget *window;

GtkWidget *clist;
g_print("N=%d",N);
gchar *text1[8]={name[1],sex[1],class[1],school[1],tel[1],num[1],building[1],dor[1]}; /*定义列表项数据*/
gchar *text2[8]={"刘备","男","23","ss","ss","ss","ss","ss"}; /*定义列表项数据*/

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

gtk_signal_connect(GTK_OBJECT(window),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);

gtk_widget_set_size_request(window,800,600);

gtk_container_set_border_width(GTK_CONTAINER(window),10);

clist=gtk_clist_new(8);

gtk_clist_set_column_title(GTK_CLIST(clist),0,"姓名");
gtk_clist_set_column_title(GTK_CLIST(clist),1,"性别");
gtk_clist_set_column_title(GTK_CLIST(clist),2,"班级");
gtk_clist_set_column_title(GTK_CLIST(clist),3,"学号");
gtk_clist_set_column_title(GTK_CLIST(clist),4,"电话");
gtk_clist_set_column_title(GTK_CLIST(clist),5,"身份证");
gtk_clist_set_column_title(GTK_CLIST(clist),6,"宿舍楼");
gtk_clist_set_column_title(GTK_CLIST(clist),7,"寝室");


gtk_clist_prepend(GTK_CLIST(clist),text1);/*将列表项数据添加到列表*/

gtk_clist_prepend(GTK_CLIST(clist),text2);

gtk_clist_column_titles_show(GTK_CLIST(clist));

gtk_container_add(GTK_CONTAINER(window),clist);


gtk_widget_show(clist);

gtk_widget_show(window);

gtk_main();}


int main(int argc,char *argv[])  
{  
    //1.gtk环境初始化  
    //linklist l;
    gtk_init(&argc, &argv);  
    //2.创建一个窗口  
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    GtkWidget *table;
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *button5;
    GtkWidget *button6;
    GtkWidget *button7;
    table =gtk_table_new(8,1,FALSE);
    gtk_container_add(GTK_CONTAINER(window),table);
    gtk_table_set_row_spacings(GTK_TABLE(table), 8);
    gtk_table_set_col_spacings(GTK_TABLE(table), 8);
    //3.设置窗口标题  
    gtk_window_set_title(GTK_WINDOW(window), "档案管理系统");  
  
    //4.窗口在显示器中居中显示  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
  
    //5.设置窗口最小大小  
    gtk_widget_set_size_request(window, 1000,800);  
  
    //6.固定窗口大小  
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE); 
    //创建按钮
    button=gtk_button_new_with_label("欢迎来到学生档案管理系统");
    button1=gtk_button_new_with_label("添加学生信息");
    button2=gtk_button_new_with_label("查询学生信息");
    button3=gtk_button_new_with_label("修改学生信息");
    button4=gtk_button_new_with_label("删除学生信息");
    button5=gtk_button_new_with_label("排序学生信息");
    button6=gtk_button_new_with_label("显示所有学生信息");
    button7=gtk_button_new_with_label("退出系统");
    //添加按钮
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,20,0,6);
    gtk_table_attach_defaults(GTK_TABLE(table),button1,5,15,12,16);
    gtk_table_attach_defaults(GTK_TABLE(table),button2,5,15,16,20);
    gtk_table_attach_defaults(GTK_TABLE(table),button3,5,15,20,24);
    gtk_table_attach_defaults(GTK_TABLE(table),button4,5,15,24,28);
    gtk_table_attach_defaults(GTK_TABLE(table),button5,5,15,28,32);
    gtk_table_attach_defaults(GTK_TABLE(table),button6,5,15,32,36);
    gtk_table_attach_defaults(GTK_TABLE(table),button7,5,15,36,40);
  
    //7."destroy"与gtk_main_quit链接  
    g_signal_connect(button1, "pressed", G_CALLBACK(deal), NULL);  
    g_signal_connect(button2, "pressed", G_CALLBACK(search_info), NULL);  
    g_signal_connect(button3, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button4, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button5, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button6, "pressed", G_CALLBACK(xianshi), NULL);  
    g_signal_connect(button7, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(table, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
  
    //8.显示所有窗口  
    gtk_widget_show_all(window);  
  
    //9.主事件循环  
    gtk_main();  

    return 0;  
}  

