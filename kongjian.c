#include <gtk/gtk.h>  
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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
linklist *stu;

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

q add;
//初始化链表
linklist* initlinklist(linklist *l){
    l->head=NULL;
    l->tail=NULL;
    l->tail=NULL;
    l->length=0;
    return l;
}
//尾插入法
int addtail(linklist *stu,node *new){
    //new->next==NULL;
    if(stu->head==NULL){
        stu->head=new;
        stu->length++;
    }
    else
    {
        stu->tail->next=new;
        stu->length++;
    }
        stu->tail=new;
    return 0;
}
int i=0;
//保存链表数据
int save_info()
{
    FILE *fp;
    int count;
    int j=0;
    node *pcur=(node*)malloc(sizeof(node));
    pcur->next=NULL;
    pcur= stu->head;

if((fp=fopen("student2.txt","wb+"))==NULL)
{
    printf("open file error and save error !\n");
    printf("open file error and save error !\n");
    exit(0);
}
    //printf("open file error and save error !\n");
while(pcur != NULL)
{
    if(fwrite(pcur,sizeof(node),1,fp)!=1)
{
    printf("write error\n");
    exit(-1);
}
    j++;
    pcur = pcur->next;
}
    free(pcur);
    printf("save success!\n");
    printf("save num =%d \n",j);
    fclose(fp);
}
/*node* creat(){
    node *p=(node*)malloc(sizeof(node));
    return p;
}*/

int read_info(){
    FILE *fp;
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    if((fp=fopen("student2.txt","r"))==NULL){
	printf("read failed");
	return 1;
    }
    while(fread(p,sizeof(stu),1,fp)==1){
	addtail(stu,p);
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
	return 1;
//	p=creat();
    }
    free(p);
    fclose(fp);
}

int show_info(){
	node *p=NULL;
	p=stu->head;
	while(p!=NULL){
	    printf("姓名        性别    班级      学号           电话号码            身份证                   宿舍楼      寝室    \n");
	    printf("%-12s%-8s%-10s%-15s%-20s%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->building,p->dor);
	    p=p->next;
	}
	free(p);
}
void on_clicked(GtkWidget *button,gpointer data){
	node *p=NULL;
	p=(node *)malloc(sizeof(node));
	p->next=NULL;
	 strcpy(p->name,gtk_entry_get_text(GTK_ENTRY(add.entry)));
	 strcpy(p->sex,gtk_entry_get_text(GTK_ENTRY(add.entry1)));
	 strcpy(p->class,gtk_entry_get_text(GTK_ENTRY(add.entry2)));
	 strcpy(p->school,gtk_entry_get_text(GTK_ENTRY(add.entry3)));
	 strcpy(p->tel,gtk_entry_get_text(GTK_ENTRY(add.entry4)));
	 strcpy(p->num,gtk_entry_get_text(GTK_ENTRY(add.entry5)));
	 strcpy(p->building,gtk_entry_get_text(GTK_ENTRY(add.entry6)));
	 strcpy(p->dor,gtk_entry_get_text(GTK_ENTRY(add.entry7)));
	 g_print("我的名字是%s\n",p->name);
	 g_print("我的名字是%s\n",p->sex);
	 g_print("我的名字是%s\n",p->class);
	 g_print("我的名字是%s\n",p->school);
	 g_print("我的名字是%s\n",p->tel);
	 g_print("我的名字是%s\n",p->num);
	 g_print("我的名字是%s\n",p->building);
	 g_print("我的名字是%s\n",p->dor);
	 addtail(stu,p);
//	 save_info();
	 show_info();
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



void clear(GtkWidget *button,gpointer entry){
gtk_entry_set_text(entry, "" );
}
void deal(void) {
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *button;
    GtkWidget *entry;

    GtkWidget *label;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *label3;
    GtkWidget *label4;
    GtkWidget *label5;
    GtkWidget *label6;
    GtkWidget *label7;
    GtkWidget *label8;

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "添加学生信息");  

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
    
    gtk_widget_set_size_request(window, 800,600);  

    table=gtk_table_new(20,10,TRUE);
   //设置按钮 
    button=gtk_button_new_with_label("添加");
   //创建文本框
    add.entry= create_entry(30,TRUE,TRUE);    
    add.entry1 = create_entry(30,TRUE,TRUE);    
    add.entry2 = create_entry(30,TRUE,TRUE);    
    add.entry3 = create_entry(30,TRUE,TRUE);    
    add.entry4 = create_entry(30,TRUE,TRUE);    
    add.entry5 = create_entry(30,TRUE,TRUE);    
    add.entry6 = create_entry(30,TRUE,TRUE);    
    add.entry7 = create_entry(30,TRUE,TRUE);    
    gtk_entry_set_text(GTK_ENTRY(add.entry), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry1), " ");  
    gtk_entry_set_text(GTK_ENTRY(add.entry2), " ");  
    gtk_entry_set_text(GTK_ENTRY(add.entry3), " ");  
    gtk_entry_set_text(GTK_ENTRY(add.entry4), " ");  
    gtk_entry_set_text(GTK_ENTRY(add.entry5), " ");
    gtk_entry_set_text(GTK_ENTRY(add.entry6), " ");
    gtk_entry_set_text(GTK_ENTRY(add.entry7), " ");
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
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry,5,15,5,10);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry1,5,15,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry2,5,15,15,20);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry3,5,15,20,25);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry4,5,15,25,30);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry5,5,15,30,35);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry6,5,15,35,40);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry7,5,15,40,45);

    gtk_table_attach_defaults(GTK_TABLE(table),button,40,50,50,55);
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked),(gpointer) 1);  
 /*   g_signal_connect(button, "clicked", G_CALLBACK(on_clicked2),entry1);  
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
    g_signal_connect(button, "clicked", G_CALLBACK(clear),entry7);*/  
    //g_signal_connect(button, "clicked", G_CALLBACK(show_info),window);  
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
    //g_signal_connect(button, "clicked", G_CALLBACK(click),entry);  
    g_signal_connect(fixed, "destroy", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
    gtk_main();
}


void xianshi(GtkWidget *button6){
    g_print("hello");
    GtkWidget *window;
    GtkWidget *textview;
    GtkTextBuffer *buffer;
    GtkWidget *fixed;
    GtkWidget *notebook;
    gchar buf[300]="\0";
    node *p;
    p=stu->head;
    show_info();
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //3.设置窗口标题  
    gtk_window_set_title(GTK_WINDOW(window), "学生信息显示");  
    //4.窗口在显示器中居中显示  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
    //5.设置窗口最小大小  
    gtk_widget_set_size_request(window,600,400);  
    fixed=gtk_fixed_new();
    GtkWidget *label;
    notebook =gtk_notebook_new();
    sprintf(buf,"%-12s%-8s%-10s%-15s%-20s%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->building,p->dor);
    label=gtk_label_new("显示所有信息"); 
    textview = gtk_text_view_new();
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    gtk_widget_show(textview);
    gtk_text_buffer_set_text(buffer, buf, -1);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), textview, label);
    //gtk_widget_set_size_request(label,100,100);
    gtk_widget_set_size_request(notebook,300,300);
   // gtk_fixed_put(GTK_FIXED(fixed),label,50,20);
    gtk_fixed_put(GTK_FIXED(fixed),notebook,20,40);
    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}

void shi(GtkWidget *button6)
{

GtkWidget *window;
GtkWidget *clist;
gchar *text2[8]={"刘备","男","23","ss","ss","ss","ss","ss"}; //定义列表项数据

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

gtk_signal_connect(GTK_OBJECT(window),"delete_event",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);

gtk_widget_set_size_request(window,800,600);

gtk_container_set_border_width(GTK_CONTAINER(window),8);

    //gtk_widget_set_size_request(clist,300,300);
clist=gtk_clist_new(8);

gtk_clist_set_column_justification( (GtkCList *)clist, 0 ,GTK_JUSTIFY_CENTER );
gtk_clist_set_column_width( (GtkCList *)clist,0,60 );
gtk_clist_set_row_height( (GtkCList *)clist,20 );
gtk_clist_set_column_title(GTK_CLIST(clist),0,"姓名");
gtk_clist_set_column_title(GTK_CLIST(clist),1,"性别");
gtk_clist_set_column_title(GTK_CLIST(clist),2,"班级");
gtk_clist_set_column_title(GTK_CLIST(clist),3,"学号");
gtk_clist_set_column_title(GTK_CLIST(clist),4,"电话");
gtk_clist_set_column_title(GTK_CLIST(clist),5,"身份证");
gtk_clist_set_column_title(GTK_CLIST(clist),6,"宿舍楼");
gtk_clist_set_column_title(GTK_CLIST(clist),7,"寝室");

gtk_clist_prepend(GTK_CLIST(clist),text2);

gtk_clist_column_titles_show(GTK_CLIST(clist));

gtk_container_add(GTK_CONTAINER(window),clist);


gtk_widget_show(clist);

gtk_widget_show(window);

}

int main(int argc,char *argv[])  
{  
    //1.gtk环境初始化  
    gtk_init(&argc, &argv);  
    linklist l;
    stu=initlinklist(&l);
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
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
  
    //8.显示所有窗口  
    gtk_widget_show_all(window);  
  
    //9.主事件循环  
    gtk_main();  

    return 0;  
}  

