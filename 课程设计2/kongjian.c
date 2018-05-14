/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 作者代号: *** :liujiaxing
  * 版权声明: *** :
  * 联络信箱: *** :937985509@qq.com
  * 文档用途: *** :C程序设计
  * 文档信息: *** :gtk sqlite3
  * 修订时间: *** :2018年第15周 04月14日 星期六 下午11:02 (104天)
  * 代码说明: *** :自行添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include <gtk/gtk.h>  
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sqlite3.h>
#include"kongjian.h"
    char name[20];
    char sex[8];
    char class[10];
    char school[15];
    char tel[15];
    char num[20];
    char zhuanye[20];
    char dor[6];

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

GtkWidget* entry1;
GtkWidget* entry2;
GtkWidget* window;
//查找函数标签指针
GtkWidget *la,*lb,*lc;
lab biao,biao1,biao2,biao3,biao4,biao5,biao6;
//修改文本框
GtkWidget *en1,*en2,*en3,*en4,*en5,*en6,*en7,*en8;
GtkWidget *la,*lb,*lc;
    GtkWidget *txt,*txt1,*txt2,*txt3,*txt4,*txt5,*txt6,*txt7,*txt8;

int i=0,N=0,row=0;
int de=0;
char sexx[4]="\0";

GdkPixbuf *create_pixbuf (const gchar *filename)
{
       GdkPixbuf *pixbuf;
       GError *error = NULL;
       pixbuf = gdk_pixbuf_new_from_file(filename, &error);
       if(!pixbuf)
       {
               fprintf(stderr, "%s\n", error->message);
               g_error_free(error);
       }
       else;
}


void delete_informat() 
{
    sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char *c;
    rc=sqlite3_open("stu.db",&db);
    if(rc==1){
           g_print("open failed");
       exit(0);
   }
   else
       printf("open successful");
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt4)));
    sql=sqlite3_mprintf("delete from dangan where school='%s'",bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&c);
    sqlite3_close(db);
	
 }                        
void show_dia(GtkWidget *button, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"添加完成", "通知");
    gtk_window_set_title(GTK_WINDOW(dialog), "通知");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
void save_dia(GtkWidget *button6, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"保存完成", "通知");
    gtk_window_set_title(GTK_WINDOW(dialog), "通知");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
void load_dia(GtkWidget *button5, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"读入完成", "通知");
    gtk_window_set_title(GTK_WINDOW(dialog), "通知");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
void delete_dia(GtkWidget *butt9, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"删除成功", "通知");
    gtk_window_set_title(GTK_WINDOW(dialog), "通知");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
void men(){
    strcpy(sexx,"男");
}
    
void women(){
    strcpy(sexx,"女");
}

void on_clicked(GtkWidget *button,gpointer data){
       sqlite3 *db;
       int rc;
       char *sql;
       sql=(char*)malloc(sizeof(char)*1000);
       char *c;
       rc=sqlite3_open("stu.db",&db);
       if(rc==1){
	   g_print("open failed\n");
	   exit(0);
       }
       else
	   g_print("open successful\n");
       sql="CREATE TABLE DANGAN("
	   "SCHOOL  TEXT PRIMARY KEY NOT NULL,"
	   "NAME    TEXT        NOT NULL,"
	   "SEX     TEXT        NOT NULL,"
	   "CLASS   TEXT        NOT NULL,"
	   "TEL     TEXT        NOT NULL,"
	   "NUM     TEXT         NOT NULL,"
	   "ZHUANYE TEXT        NOT NULL,"
	   "DOR     TEXT        NOT NULL);";
        rc=sqlite3_exec(db,sql,NULL,NULL,&c);
	g_print("nishishei\n");
	 strcpy(name,gtk_entry_get_text(GTK_ENTRY(add.entry)));
	 strcpy(sex,sexx);
	 strcpy(class,gtk_entry_get_text(GTK_ENTRY(add.entry2)));
	 strcpy(school,gtk_entry_get_text(GTK_ENTRY(add.entry3)));
	 strcpy(tel,gtk_entry_get_text(GTK_ENTRY(add.entry4)));
	 strcpy(num,gtk_entry_get_text(GTK_ENTRY(add.entry5)));
	 strcpy(zhuanye,gtk_entry_get_text(GTK_ENTRY(add.entry6)));
	 strcpy(dor,gtk_entry_get_text(GTK_ENTRY(add.entry7)));
	sql=sqlite3_mprintf("insert into dangan(school,name,sex,class,tel,num,zhuanye,dor) values('%s','%s','%s','%s','%s','%s','%s','%s')",school,name,sex,class,tel,num,zhuanye,dor);
       rc=sqlite3_exec(db,sql,NULL,NULL,&c);
       if(rc==1){
	    printf("insert failed");
	    exit(0);
       }
       else
	   printf("insert success");
       sql="select *from dangan";
       rc=sqlite3_exec(db,sql,callback,0,&c);
       sqlite3_close(db);
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


void clear(GtkWidget *button){
    gtk_entry_set_text(GTK_ENTRY(add.entry), ""); 
//    gtk_entry_set_text(GTK_ENTRY(add.entry1), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry2), ""); 
    gtk_entry_set_text(GTK_ENTRY(add.entry3), ""); 
    gtk_entry_set_text(GTK_ENTRY(add.entry4), ""); 
    gtk_entry_set_text(GTK_ENTRY(add.entry5), ""); 
    gtk_entry_set_text(GTK_ENTRY(add.entry6), ""); 
    gtk_entry_set_text(GTK_ENTRY(add.entry7), ""); 
}

//添加信息函数
void deal(void) {
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *button;
//    GtkWidget *entry;
    GtkWidget *label;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *label3;
    GtkWidget *label4;
    GtkWidget *label5;
    GtkWidget *label6;
    GtkWidget *label7;
    GtkWidget *label8;
   GSList *radio_group; 
  //  GtkWidget *but2;
    GtkWidget *radio_button2; 
    GtkWidget *radio_button1; 

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "添加学生信息");  

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
    
    gtk_widget_set_size_request(window, 800,600);  
    table=gtk_table_new(20,10,TRUE);
   //设置按钮 
    button=gtk_button_new_with_label("添加");
   //创建文本框
    add.entry= create_entry(30,TRUE,TRUE);    
 //   add.entry1 = create_entry(30,TRUE,TRUE);    
    add.entry2 = create_entry(30,TRUE,TRUE);    
    radio_button1 = gtk_radio_button_new_with_label(NULL,"男");  
    radio_group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button1));  
    radio_button2 = gtk_radio_button_new_with_label(radio_group,"女");  

    add.entry3 = create_entry(30,TRUE,TRUE);    
    add.entry4 = create_entry(30,TRUE,TRUE);    
    add.entry5 = create_entry(30,TRUE,TRUE);    
    add.entry6 = create_entry(30,TRUE,TRUE);    
    add.entry7 = create_entry(30,TRUE,TRUE);    
    gtk_entry_set_text(GTK_ENTRY(add.entry), ""); 
    //gtk_entry_set_text(GTK_ENTRY(add.entry1), " ");  
    gtk_entry_set_text(GTK_ENTRY(add.entry2), "");  
    gtk_entry_set_text(GTK_ENTRY(add.entry3), "");  
    gtk_entry_set_text(GTK_ENTRY(add.entry4), "");  
    gtk_entry_set_text(GTK_ENTRY(add.entry5), "");
    gtk_entry_set_text(GTK_ENTRY(add.entry6), "");
    gtk_entry_set_text(GTK_ENTRY(add.entry7), "");
    // 创建标签
    label=gtk_label_new("");
    label1=gtk_label_new("姓名");
    label2=gtk_label_new("性别");
    label3=gtk_label_new("班级");
    label4=gtk_label_new("学号");
    label5=gtk_label_new("电话号码");
    label6=gtk_label_new("身份证号");
    label7=gtk_label_new("专业");
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
    //gtk_table_attach_defaults(GTK_TABLE(table),add.entry1,5,15,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry2,5,15,15,20);
    gtk_table_attach_defaults(GTK_TABLE(table),radio_button1,5,10,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),radio_button2,10,15,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry3,5,15,20,25);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry4,5,15,25,30);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry5,5,15,30,35);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry6,5,15,35,40);
    gtk_table_attach_defaults(GTK_TABLE(table),add.entry7,5,15,40,45);

    gtk_table_attach_defaults(GTK_TABLE(table),button,40,50,50,55);
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_button1)))
	men();
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_button2)))
	women();
    g_signal_connect(button, "clicked", G_CALLBACK(on_clicked),(gpointer) 1);
    //g_signal_connect(radio_group,"toggle",G_CALLBACK(women),NULL);
    //g_signal_connect(radio_button2,"toggle",G_CALLBACK(women),NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(show_dia),window);  
    g_signal_connect(button, "clicked", G_CALLBACK(clear),NULL);  
   //按钮添加进容器  
    gtk_container_add(GTK_CONTAINER(window),table);
    gtk_widget_show_all(window);
}
//查找信息总函数
void search_info(void){

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 800,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    GtkWidget *image;
    image=gtk_image_new_from_file("zhi.jpg");
    gtk_widget_set_size_request(image, 800,600);  
    gtk_container_add(GTK_CONTAINER(fixed),image);
    
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
    button1=gtk_button_new_with_label("身份证号查找");
    button2=gtk_button_new_with_label("学号查找");
    button3=gtk_button_new_with_label("电话号码查找");
    button4=gtk_button_new_with_label("姓名查找");
    button5=gtk_button_new_with_label("班级查找");
    button6=gtk_button_new_with_label("专业查找");
    button7=gtk_button_new_with_label("寝室查找");
    //gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button1), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button2), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button3), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button4), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button5), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button6), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button7), GTK_RELIEF_NONE);
    //gtk_button_set_relief(GTK_BUTTON(button8), GTK_RELIEF_NONE);
/*设置标签*/
    label=gtk_label_new("精确查找");
    label1=gtk_label_new("模糊查找");
/*设置按钮尺寸*/
    gtk_widget_set_size_request(button1,100,50);
    gtk_widget_set_size_request(button2,100,50);
    gtk_widget_set_size_request(button3,100,50);
    gtk_widget_set_size_request(button4,100,50);
    gtk_widget_set_size_request(button5,100,50);
    gtk_widget_set_size_request(button6,100,50);
    gtk_widget_set_size_request(button7,100,50);
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
    g_signal_connect(button1, "clicked", G_CALLBACK(chazhao1),NULL);  
    g_signal_connect(button2, "clicked", G_CALLBACK(chazhao2),NULL);  
    g_signal_connect(button3, "clicked", G_CALLBACK(chazhao3),NULL);  
    g_signal_connect(button4, "clicked", G_CALLBACK(chazhao4), NULL);  
    g_signal_connect(button5, "clicked", G_CALLBACK(chazhao5), NULL);  
    g_signal_connect(button6, "clicked", G_CALLBACK(chazhao6), NULL);  
    g_signal_connect(button7, "clicked", G_CALLBACK(chazhao7), NULL); 
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  
    
    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);  
}
//按身份证号查找子函数
int get_num(GtkWidget *butt){
    sqlite3 *db;
    char *sql;
    int rc;
    char **resultp;
    char *errmsg;
    int nrow,ncolumn,index;
    rc=sqlite3_open("stu.db",&db);
    if(rc==1){
	g_print("open failed");
	exit(0);
    }
    else
	g_print("open successful");
    gchar bb[15];
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt)));
   //如果无数据则直接退出此函数 
    g_print("bb=%s",bb);
   //sql="select *from dangan"; 
    sql=sqlite3_mprintf("select * from dangan where num = '%s';",bb); 
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
	{
		perror("sqlite3_get_table");
		exit(-1);}
    for(int a=0;a<nrow;a++)
	for(int b=1;b<ncolumn;b++){
	    g_print("%s\n",resultp[a*ncolumn+b]);
    gtk_label_set_text(GTK_LABEL(biao.la1),resultp[ncolumn+0]);
    gtk_label_set_text(GTK_LABEL(biao.la2),resultp[ncolumn+1]);
    gtk_label_set_text(GTK_LABEL(biao.la3),resultp[ncolumn+2]);
    gtk_label_set_text(GTK_LABEL(biao.la4),resultp[ncolumn+3]);
    gtk_label_set_text(GTK_LABEL(biao.la5),resultp[ncolumn+4]);
    gtk_label_set_text(GTK_LABEL(biao.la6),resultp[ncolumn+5]);
    gtk_label_set_text(GTK_LABEL(biao.la7),resultp[ncolumn+6]);
    gtk_label_set_text(GTK_LABEL(biao.la8),resultp[ncolumn+7]);} 
    sqlite3_close(db);
}

int get_school(GtkWidget *butt){
    sqlite3 *db;
    char *sql;
    int rc;
    char **resultp;
    char *errmsg;
    int nrow,ncolumn,index;
    rc=sqlite3_open("stu.db",&db);
    if(rc==1){
	g_print("open failed");
	exit(0);}
    else
	g_print("open successful");
    gchar bb[15];
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt1)));
   //如果无数据则直接退出此函数 
    g_print("bb=%s",bb);
    sql=sqlite3_mprintf("select * from dangan where school = '%s';",bb); 
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
	{
		perror("sqlite3_get_table");
		exit(-1);
	}
    for(int a=0;a<nrow;a++)
	for(int b=1;b<ncolumn;b++){
	    g_print("%s\n",resultp[a*ncolumn+b]);
    gtk_label_set_text(GTK_LABEL(biao1.la1),resultp[ncolumn+0]);
    gtk_label_set_text(GTK_LABEL(biao1.la2),resultp[ncolumn+1]);
    gtk_label_set_text(GTK_LABEL(biao1.la3),resultp[ncolumn+2]);
    gtk_label_set_text(GTK_LABEL(biao1.la4),resultp[ncolumn+3]);
    gtk_label_set_text(GTK_LABEL(biao1.la5),resultp[ncolumn+4]);
    gtk_label_set_text(GTK_LABEL(biao1.la6),resultp[ncolumn+5]);
    gtk_label_set_text(GTK_LABEL(biao1.la7),resultp[ncolumn+6]);
    gtk_label_set_text(GTK_LABEL(biao1.la8),resultp[ncolumn+7]);} 
    sqlite3_close(db);
}
int get_school1(GtkWidget *butt){
    sqlite3 *db;
    char *sql;
    int rc;
    char **resultp;
    char *errmsg;
    int nrow,ncolumn,index;
    rc=sqlite3_open("stu.db",&db);
    if(rc==1){
	g_print("open failed");
	exit(0);}
    else
	g_print("open successful");
    gchar bb[15];
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
   //如果无数据则直接退出此函数 
    g_print("bb=%s",bb);
   //sql="select *from dangan"; 
    sql=sqlite3_mprintf("select * from dangan where school = '%s';",bb); 
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
	{
		perror("sqlite3_get_table");
		exit(-1);}
    for(int a=0;a<nrow;a++)
	for(int b=1;b<ncolumn;b++){
	    g_print("%s\n",resultp[a*ncolumn+b]);
    gtk_label_set_text(GTK_LABEL(biao3.la1),resultp[ncolumn+0]);
    gtk_label_set_text(GTK_LABEL(biao3.la2),resultp[ncolumn+1]);
    gtk_label_set_text(GTK_LABEL(biao3.la3),resultp[ncolumn+2]);
    gtk_label_set_text(GTK_LABEL(biao3.la4),resultp[ncolumn+3]);
    gtk_label_set_text(GTK_LABEL(biao3.la5),resultp[ncolumn+4]);
    gtk_label_set_text(GTK_LABEL(biao3.la6),resultp[ncolumn+5]);
    gtk_label_set_text(GTK_LABEL(biao3.la7),resultp[ncolumn+6]);
    gtk_label_set_text(GTK_LABEL(biao3.la8),resultp[ncolumn+7]);} 
    sqlite3_close(db);
}
//按学号查找
int get_tel(GtkWidget *butt){
    sqlite3 *db;
    char *sql;
    int rc;
    char **resultp;
    char *errmsg;
    int nrow,ncolumn,index;
    rc=sqlite3_open("stu.db",&db);
    if(rc==1){
	g_print("open failed");
	exit(0);
    }
    else
	g_print("open successful");
    gchar bb[15];
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt2)));
   //如果无数据则直接退出此函数 
    g_print("bb=%s",bb);
   //sql="select *from dangan"; 
    sql=sqlite3_mprintf("select * from dangan where school = '%s';",bb); 
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
	{
		perror("sqlite3_get_table");
		exit(-1);
	}
    for(int a=0;a<nrow;a++)
	for(int b=1;b<ncolumn;b++){
	    g_print("%s\n",resultp[a*ncolumn+b]);
    gtk_label_set_text(GTK_LABEL(biao2.la1),resultp[ncolumn+0]);
    gtk_label_set_text(GTK_LABEL(biao2.la2),resultp[ncolumn+1]);
    gtk_label_set_text(GTK_LABEL(biao2.la3),resultp[ncolumn+2]);
    gtk_label_set_text(GTK_LABEL(biao2.la4),resultp[ncolumn+3]);
    gtk_label_set_text(GTK_LABEL(biao2.la5),resultp[ncolumn+4]);
    gtk_label_set_text(GTK_LABEL(biao2.la6),resultp[ncolumn+5]);
    gtk_label_set_text(GTK_LABEL(biao2.la7),resultp[ncolumn+6]);
    gtk_label_set_text(GTK_LABEL(biao2.la8),resultp[ncolumn+7]);} 
    sqlite3_close(db);
}

//删除查找界面
int delete_search(GtkWidget *butt){
    sqlite3 *db;
    char *sql;
    int rc;
    char **resultp;
    char *errmsg;
    int nrow,ncolumn,index;
    rc=sqlite3_open("stu.db",&db);
    if(rc==1){
	g_print("open failed");
	exit(0);}
    else
	g_print("open successful");
    gchar bb[15];
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt4)));
   //如果无数据则直接退出此函数 
    g_print("bb=%s",bb);
    sql=sqlite3_mprintf("select * from dangan where school = '%s';",bb); 
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncolumn,&errmsg) != SQLITE_OK)
	{
		perror("sqlite3_get_table");
		exit(-1);}
    for(int a=0;a<nrow;a++)
	for(int b=1;b<ncolumn;b++){
    gtk_label_set_text(GTK_LABEL(biao5.la1),resultp[ncolumn+0]);
    gtk_label_set_text(GTK_LABEL(biao5.la2),resultp[ncolumn+1]);
    gtk_label_set_text(GTK_LABEL(biao5.la3),resultp[ncolumn+2]);
    gtk_label_set_text(GTK_LABEL(biao5.la4),resultp[ncolumn+3]);
    gtk_label_set_text(GTK_LABEL(biao5.la5),resultp[ncolumn+4]);
    gtk_label_set_text(GTK_LABEL(biao5.la6),resultp[ncolumn+5]);
    gtk_label_set_text(GTK_LABEL(biao5.la7),resultp[ncolumn+6]);
    gtk_label_set_text(GTK_LABEL(biao5.la8),resultp[ncolumn+7]);} 
    sqlite3_close(db);
}
/*清理标签栏和输入构件*/
void chazhao1_clear(GtkWidget *button9){
    gtk_entry_set_text(GTK_ENTRY(txt), ""); 
    gtk_label_set_text(GTK_LABEL(biao.la1),"");
    gtk_label_set_text(GTK_LABEL(biao.la2),"");
    gtk_label_set_text(GTK_LABEL(biao.la3),"");
    gtk_label_set_text(GTK_LABEL(biao.la4),"");
    gtk_label_set_text(GTK_LABEL(biao.la5),"");
    gtk_label_set_text(GTK_LABEL(biao.la6),"");
    gtk_label_set_text(GTK_LABEL(biao.la7),"");
    gtk_label_set_text(GTK_LABEL(biao.la8),"");} 
//身份证号查询窗口
void  chazhao1( GtkWidget *button1)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案查询系统");  
    gtk_widget_set_size_request(window, 820,300);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt), ""); 
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    GtkWidget *butt9;
    
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
    butt9=gtk_button_new_with_label("清除");
    biao.la1=gtk_label_new("");
    biao.la2=gtk_label_new("");
    biao.la3=gtk_label_new("");
    biao.la4=gtk_label_new("");
    biao.la5=gtk_label_new("");
    biao.la6=gtk_label_new("");
    biao.la7=gtk_label_new("");
    biao.la8=gtk_label_new("");
    la=gtk_label_new("请输入你要查询的身份证");
   
   //设置标签内容 
   //设置构件大小 
    gtk_widget_set_size_request(la,180,50);
    gtk_widget_set_size_request(biao.la1,100,50);
    gtk_widget_set_size_request(biao.la2,100,50);
    gtk_widget_set_size_request(biao.la3,100,50);
    gtk_widget_set_size_request(biao.la4,100,50);
    gtk_widget_set_size_request(biao.la5,100,50);
    gtk_widget_set_size_request(biao.la6,100,50);
    gtk_widget_set_size_request(biao.la7,100,50);
    gtk_widget_set_size_request(biao.la8,100,50);
   //设置回调函数 
    gtk_widget_set_size_request(butt,100,30);
    gtk_widget_set_size_request(butt1,100,30);
    gtk_widget_set_size_request(butt2,100,30);
    gtk_widget_set_size_request(butt3,100,30);
    gtk_widget_set_size_request(butt4,100,30);
    gtk_widget_set_size_request(butt5,100,30);
    gtk_widget_set_size_request(butt6,100,30);
    gtk_widget_set_size_request(butt7,100,30);
    gtk_widget_set_size_request(butt8,100,30);
    gtk_widget_set_size_request(butt9,100,30);
    gtk_widget_set_size_request(txt,200,30);
   //放入构建 
    gtk_fixed_put(GTK_FIXED(fixed),la,40,40);
    gtk_fixed_put(GTK_FIXED(fixed),txt,240,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt,500,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt1,10,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt2,110,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt3,210,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt4,310,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt5,410,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt6,510,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt7,610,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt8,710,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt9,710,250);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_num),NULL);  
    g_signal_connect(butt9, "clicked", G_CALLBACK(chazhao1_clear),NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}
//学号清理函数
void chazhao2_clear(GtkWidget *button9){
    gtk_entry_set_text(GTK_ENTRY(txt1), ""); 
    gtk_label_set_text(GTK_LABEL(biao1.la1),"");
    gtk_label_set_text(GTK_LABEL(biao1.la2),"");
    gtk_label_set_text(GTK_LABEL(biao1.la3),"");
    gtk_label_set_text(GTK_LABEL(biao1.la4),"");
    gtk_label_set_text(GTK_LABEL(biao1.la5),"");
    gtk_label_set_text(GTK_LABEL(biao1.la6),"");
    gtk_label_set_text(GTK_LABEL(biao1.la7),"");
    gtk_label_set_text(GTK_LABEL(biao1.la8),"");} 
//学号查询窗口
void  chazhao2( GtkWidget *button2)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案查询系统");  
    gtk_widget_set_size_request(window, 820,300);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt1=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt1), ""); 
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    GtkWidget *butt9;
    
   //设置标签内容 
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
    butt9=gtk_button_new_with_label("清除");
    biao1.la1=gtk_label_new("");
    biao1.la2=gtk_label_new("");
    biao1.la3=gtk_label_new("");
    biao1.la4=gtk_label_new("");
    biao1.la5=gtk_label_new("");
    biao1.la6=gtk_label_new("");
    biao1.la7=gtk_label_new("");
    biao1.la8=gtk_label_new("");
    lb=gtk_label_new("请输入你要查询的学号");
   //设置构件大小 
    gtk_widget_set_size_request(lb,180,50);
    gtk_widget_set_size_request(biao1.la1,100,50);
    gtk_widget_set_size_request(biao1.la2,100,50);
    gtk_widget_set_size_request(biao1.la3,100,50);
    gtk_widget_set_size_request(biao1.la4,100,50);
    gtk_widget_set_size_request(biao1.la5,100,50);
    gtk_widget_set_size_request(biao1.la6,100,50);
    gtk_widget_set_size_request(biao1.la7,100,50);
    gtk_widget_set_size_request(biao1.la8,100,50);
   
   //设置回调函数 

    gtk_widget_set_size_request(butt,100,30);
    gtk_widget_set_size_request(butt1,100,30);
    gtk_widget_set_size_request(butt2,100,30);
    gtk_widget_set_size_request(butt3,100,30);
    gtk_widget_set_size_request(butt4,100,30);
    gtk_widget_set_size_request(butt5,100,30);
    gtk_widget_set_size_request(butt6,100,30);
    gtk_widget_set_size_request(butt7,100,30);
    gtk_widget_set_size_request(butt8,100,30);
    gtk_widget_set_size_request(butt9,100,30);
    gtk_widget_set_size_request(txt1,200,30);
   //放入构建 
    gtk_fixed_put(GTK_FIXED(fixed),lb,40,40);
    gtk_fixed_put(GTK_FIXED(fixed),txt1,240,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt,500,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt1,10,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt2,110,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt3,210,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt4,310,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt5,410,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt6,510,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt7,610,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt8,710,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt9,710,250);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_school),NULL);  
    g_signal_connect(butt9, "clicked", G_CALLBACK(chazhao2_clear),NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}
void chazhao3_clear(GtkWidget *button9){
    gtk_entry_set_text(GTK_ENTRY(txt2), ""); 
    gtk_label_set_text(GTK_LABEL(biao2.la1),"");
    gtk_label_set_text(GTK_LABEL(biao2.la2),"");
    gtk_label_set_text(GTK_LABEL(biao2.la3),"");
    gtk_label_set_text(GTK_LABEL(biao2.la4),"");
    gtk_label_set_text(GTK_LABEL(biao2.la5),"");
    gtk_label_set_text(GTK_LABEL(biao2.la6),"");
    gtk_label_set_text(GTK_LABEL(biao2.la7),"");
    gtk_label_set_text(GTK_LABEL(biao2.la8),"");} 
//电话查询窗口
void  chazhao3( GtkWidget *button3)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案查询系统");  
    gtk_widget_set_size_request(window, 820,300);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt2=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt2), ""); 
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    GtkWidget *butt9;
    
   //设置标签内容 
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
    butt9=gtk_button_new_with_label("清理");
    biao2.la1=gtk_label_new("");
    biao2.la2=gtk_label_new("");
    biao2.la3=gtk_label_new("");
    biao2.la4=gtk_label_new("");
    biao2.la5=gtk_label_new("");
    biao2.la6=gtk_label_new("");
    biao2.la7=gtk_label_new("");
    biao2.la8=gtk_label_new("");
    lc=gtk_label_new("请输入你要查询的电话");
     
   //设置构件大小 
    gtk_widget_set_size_request(lc,180,50);
    gtk_widget_set_size_request(biao2.la1,100,50);
    gtk_widget_set_size_request(biao2.la2,100,50);
    gtk_widget_set_size_request(biao2.la3,100,50);
    gtk_widget_set_size_request(biao2.la4,100,50);
    gtk_widget_set_size_request(biao2.la5,100,50);
    gtk_widget_set_size_request(biao2.la6,100,50);
    gtk_widget_set_size_request(biao2.la7,100,50);
    gtk_widget_set_size_request(biao2.la8,100,50);

    gtk_widget_set_size_request(butt,100,30);
    gtk_widget_set_size_request(butt1,100,30);
    gtk_widget_set_size_request(butt2,100,30);
    gtk_widget_set_size_request(butt3,100,30);
    gtk_widget_set_size_request(butt4,100,30);
    gtk_widget_set_size_request(butt5,100,30);
    gtk_widget_set_size_request(butt6,100,30);
    gtk_widget_set_size_request(butt7,100,30);
    gtk_widget_set_size_request(butt8,100,30);
    gtk_widget_set_size_request(butt9,100,30);
    gtk_widget_set_size_request(txt2,200,30);
   //放入构建 
    gtk_fixed_put(GTK_FIXED(fixed),lc,40,40);
    gtk_fixed_put(GTK_FIXED(fixed),txt2,240,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt,500,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt1,10,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt2,110,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt3,210,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt4,310,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt5,410,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt6,510,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt7,610,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt8,710,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt9,710,250);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_tel),NULL);  
    g_signal_connect(butt9, "clicked", G_CALLBACK(chazhao3_clear),NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}

void chazhao4(GtkWidget *button4){
    //char *bb[8];
    GtkWidget *window;//窗口和按键的对应指针
    GtkWidget *clist;
    GtkWidget *fixed;
    GtkWidget *label;
    GtkWidget *bu;
    GtkWidget *bu1;
    bu=gtk_button_new_with_label("查找");
    bu1=gtk_button_new_with_label("清除");
    label=gtk_label_new("请输入信息:");
    char title[] = "学生信息";
    fixed=gtk_fixed_new();
    txt5=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt5), ""); 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//创建窗口
    gtk_window_set_title(GTK_WINDOW(window),title);//设置窗口标题
    gtk_widget_set_size_request(window, 800,600);  
    gtk_widget_set_size_request(txt5, 300,30);  
    gtk_widget_set_size_request(label, 100,30);  
    gtk_widget_set_size_request(bu, 80,30);  
    gtk_widget_set_size_request(bu1, 80,30);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//窗口居中
    gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
    clist = gtk_clist_new(8);//创建表格
    gtk_widget_set_size_request(clist, 800,500);  
    gtk_fixed_put(GTK_FIXED(fixed),clist,0,100);
    gtk_fixed_put(GTK_FIXED(fixed),txt5,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu,500,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu1,600,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,50,30);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"       姓名       ");//添加列标题
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"        性别       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"        班级       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"        学号           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"        电话           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"        身份证           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"           专业            ");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"          宿舍         ");
    
    gtk_clist_column_titles_show(GTK_CLIST(clist));//显示列标题
    gtk_container_add(GTK_CONTAINER(window),fixed);//将标签盒加入窗口
    g_signal_connect(bu, "clicked", G_CALLBACK(get_name), clist);
    g_signal_connect(bu1, "clicked", G_CALLBACK(get_name_clear), clist);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);//显示窗口
    gtk_main();
    } 
//按照名字查找
void get_name(GtkWidget *bu,GtkWidget *clist){
    sqlite3 *db;
    int rc,i,j,ok;
    char *sql;
    char *errmsg;
    char **result;
    char cc[20];
    char *bb[8];
    sqlite3_open("stu.db",&db);
    strcpy(cc,gtk_entry_get_text(GTK_ENTRY(txt5)));
	sql=sqlite3_mprintf("select * from dangan where name ='%s';",cc);
    sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    ok=j;
    g_print("j=%d",j);
    g_print("i=%d",i);
	for(int b=0;b<i;b++)
    {
	bb[0]=result[ok++];
	bb[1]=result[ok++];
	bb[2]=result[ok++];
	bb[3]=result[ok++];
	bb[4]=result[ok++];
	bb[5]=result[ok++];
	bb[6]=result[ok++];
	bb[7]=result[ok++];
        gtk_clist_append(GTK_CLIST(clist),(gchar**)(bb));  //对cilst列表 构建 进行从无到有到数据填充
}}  

//清除查找的姓名
void get_name_clear(GtkWidget *bu1,GtkWidget *clist){
    for(int a=0;a<=row+1;a++)
    gtk_clist_remove(GTK_CLIST(clist),a);
}
//查找班级函数
void chazhao5(GtkWidget *button5){
    GtkWidget *window;//窗口和按键的对应指针
    GtkWidget *clist;
    GtkWidget *fixed;
    GtkWidget *label;
    GtkWidget *bu;
    GtkWidget *bu1;
    bu=gtk_button_new_with_label("查找");
    bu1=gtk_button_new_with_label("清除");
    label=gtk_label_new("请输入信息:");
    char title[] = "学生信息";
    fixed=gtk_fixed_new();
    txt6=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt6), ""); 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//创建窗口
    gtk_window_set_title(GTK_WINDOW(window),title);//设置窗口标题
    gtk_widget_set_size_request(window, 800,600);  
    gtk_widget_set_size_request(txt6, 300,30);  
    gtk_widget_set_size_request(label, 100,30);  
    gtk_widget_set_size_request(bu, 80,30);  
    gtk_widget_set_size_request(bu1, 80,30);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//窗口居中
    gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
  
    clist = gtk_clist_new(8);//创建表格
    gtk_widget_set_size_request(clist, 800,500);  
    gtk_fixed_put(GTK_FIXED(fixed),clist,0,100);
    gtk_fixed_put(GTK_FIXED(fixed),txt6,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu,500,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu1,600,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,50,30);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"       姓名       ");//添加列标题
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"        性别       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"        班级       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"        学号           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"        电话           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"        身份证           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"           专业            ");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"          宿舍         ");
    
    gtk_clist_column_titles_show(GTK_CLIST(clist));//显示列标题
    gtk_container_add(GTK_CONTAINER(window),fixed);//将标签盒加入窗口
    g_signal_connect(bu, "clicked", G_CALLBACK(get_class), clist);
    g_signal_connect(bu1, "clicked", G_CALLBACK(get_name_clear), clist);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);//显示窗口
    gtk_main();
}  
void get_class(GtkWidget *bu,GtkWidget *clist){
    sqlite3 *db;
    int rc,i,j,ok;
    char *sql;
    char *errmsg;
    char **result;
    char cc[20];
    char *bb[8];
    sqlite3_open("stu.db",&db);
    strcpy(cc,gtk_entry_get_text(GTK_ENTRY(txt6)));
	sql=sqlite3_mprintf("select * from dangan where class ='%s';",cc);
    sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    ok=j;
    g_print("j=%d",j);
    g_print("i=%d",i);
	for(int b=0;b<i;b++)
    {
	bb[0]=result[ok++];
	bb[1]=result[ok++];
	bb[2]=result[ok++];
	bb[3]=result[ok++];
	bb[4]=result[ok++];
	bb[5]=result[ok++];
	bb[6]=result[ok++];
	bb[7]=result[ok++];
        gtk_clist_append(GTK_CLIST(clist),(gchar**)(bb));  //对cilst列表 构建 进行从无到有到数据填充
}}  
//清除查找的姓名

void chazhao6(GtkWidget *button6){
    GtkWidget *window;//窗口和按键的对应指针
    GtkWidget *clist;
    GtkWidget *fixed;
    GtkWidget *label;
    GtkWidget *bu;
    GtkWidget *bu1;
    bu=gtk_button_new_with_label("查找");
    bu1=gtk_button_new_with_label("清除");
    label=gtk_label_new("请输入信息:");
    char title[] = "学生信息";
    fixed=gtk_fixed_new();
    txt7=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt7),""); 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//创建窗口
    gtk_window_set_title(GTK_WINDOW(window),title);//设置窗口标题
    gtk_widget_set_size_request(window, 800,600);  
    gtk_widget_set_size_request(txt7, 150,30);  
    gtk_widget_set_size_request(label, 100,30);  
    gtk_widget_set_size_request(bu, 80,30);  
    gtk_widget_set_size_request(bu1, 80,30);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//窗口居中
    gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
  
    clist = gtk_clist_new(8);//创建表格
    gtk_widget_set_size_request(clist, 800,500);  
    gtk_fixed_put(GTK_FIXED(fixed),clist,0,100);
    gtk_fixed_put(GTK_FIXED(fixed),txt7,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu,500,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu1,600,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,50,30);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"       姓名       ");//添加列标题
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"        性别       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"        班级       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"        学号           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"        电话           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"        身份证           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"           专业            ");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"          宿舍         ");
    
    gtk_clist_column_titles_show(GTK_CLIST(clist));//显示列标题
    gtk_container_add(GTK_CONTAINER(window),fixed);//将标签盒加入窗口
    g_signal_connect(bu, "clicked", G_CALLBACK(get_zhuanye), clist);
    g_signal_connect(bu1, "clicked", G_CALLBACK(get_name_clear), clist);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);//显示窗口
    gtk_main();
     } 

void get_zhuanye(GtkWidget *bu,GtkWidget *clist){
    sqlite3 *db;
    int rc,i,j,ok;
    char *sql;
    char *errmsg;
    char **result;
    char cc[20];
    char *bb[8];
    sqlite3_open("stu.db",&db);
    strcpy(cc,gtk_entry_get_text(GTK_ENTRY(txt7)));
	sql=sqlite3_mprintf("select * from dangan where zhuanye ='%s';",cc);
    sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    ok=j;
    g_print("j=%d",j);
    g_print("i=%d",i);
	for(int b=0;b<i;b++)
    {
	bb[0]=result[ok++];
	bb[1]=result[ok++];
	bb[2]=result[ok++];
	bb[3]=result[ok++];
	bb[4]=result[ok++];
	bb[5]=result[ok++];
	bb[6]=result[ok++];
	bb[7]=result[ok++];
        gtk_clist_append(GTK_CLIST(clist),(gchar**)(bb));  //对cilst列表 构建 进行从无到有到数据填充
}}  

void chazhao7(GtkWidget *button7){
    GtkWidget *window;//窗口和按键的对应指针
    GtkWidget *clist;
    GtkWidget *fixed;
    GtkWidget *label;
    GtkWidget *bu;
    GtkWidget *bu1;
    bu=gtk_button_new_with_label("查找");
    bu1=gtk_button_new_with_label("清除");
    label=gtk_label_new("请输入信息:");
    char title[] = "学生信息";
    fixed=gtk_fixed_new();
    txt8=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt8),""); 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//创建窗口
    gtk_window_set_title(GTK_WINDOW(window),title);//设置窗口标题
    gtk_widget_set_size_request(window, 800,600);  
    gtk_widget_set_size_request(txt8, 150,30);  
    gtk_widget_set_size_request(label, 100,30);  
    gtk_widget_set_size_request(bu, 80,30);  
    gtk_widget_set_size_request(bu1, 80,30);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//窗口居中
    gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
  
    clist = gtk_clist_new(8);//创建表格
    gtk_widget_set_size_request(clist, 800,500);  
    gtk_fixed_put(GTK_FIXED(fixed),clist,0,100);
    gtk_fixed_put(GTK_FIXED(fixed),txt8,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu,500,30);
    gtk_fixed_put(GTK_FIXED(fixed),bu1,600,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,50,30);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"       姓名       ");//添加列标题
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"        性别       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"        班级       ");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"        学号           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"        电话           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"        身份证           ");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"           专业            ");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"          宿舍         ");
    
    gtk_clist_column_titles_show(GTK_CLIST(clist));//显示列标题
    gtk_container_add(GTK_CONTAINER(window),fixed);//将标签盒加入窗口
    g_signal_connect(bu, "clicked", G_CALLBACK(get_dor), clist);
    g_signal_connect(bu1, "clicked", G_CALLBACK(get_name_clear), clist);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);//显示窗口
    gtk_main();
     } 

void get_dor(GtkWidget *bu,GtkWidget *clist){
    sqlite3 *db;
    int rc,i,j,ok;
    char *sql;
    char *errmsg;
    char **result;
    char cc[20];
    char *bb[8];
    sqlite3_open("stu.db",&db);
    strcpy(cc,gtk_entry_get_text(GTK_ENTRY(txt8)));
	sql=sqlite3_mprintf("select * from dangan where dor ='%s';",cc);
    sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    ok=j;
    g_print("j=%d",j);
    g_print("i=%d",i);
	for(int b=0;b<i;b++)
    {
	bb[0]=result[ok++];
	bb[1]=result[ok++];
	bb[2]=result[ok++];
	bb[3]=result[ok++];
	bb[4]=result[ok++];
	bb[5]=result[ok++];
	bb[6]=result[ok++];
	bb[7]=result[ok++];
        gtk_clist_append(GTK_CLIST(clist),(gchar**)(bb));  //对cilst列表 构建 进行从无到有到数据填充
}}  

void xianshi(GtkWidget *button6){
    char *cc[8];
    sqlite3 *db;
    int rc;
    char *sql;
    char **result;
    char *errmsg;
    int i,j;
    int ok;
    sqlite3_open("stu.db",&db);
    sql="select *from dangan";
    int n=0;
    GtkWidget *window;//窗口和按键的对应指针
    GtkWidget *alist;
    
    char title[] = "学生信息";
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//创建窗口
    gtk_window_set_title(GTK_WINDOW(window),title);//设置窗口标题
    gtk_widget_set_size_request(window, 800,600);  
     
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//窗口居中
    gtk_signal_connect(GTK_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
    //gtk_container_add(GTK_CONTAINER(window),scrolled);
  
    alist = gtk_clist_new(8);//创建表格
    gtk_clist_set_column_title(GTK_CLIST(alist),0,"       学号            ");//添加列标题
    gtk_clist_set_column_title(GTK_CLIST(alist),1,"        姓名         ");
    gtk_clist_set_column_title(GTK_CLIST(alist),2,"        性别       ");
    gtk_clist_set_column_title(GTK_CLIST(alist),3,"        班级           ");
    gtk_clist_set_column_title(GTK_CLIST(alist),4,"        电话              ");
    gtk_clist_set_column_title(GTK_CLIST(alist),5,"        身份证                      ");
    gtk_clist_set_column_title(GTK_CLIST(alist),6,"         专业            ");
    gtk_clist_set_column_title(GTK_CLIST(alist),7,"          宿舍         ");
    sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    ok=j;
    g_print("ok=%d",ok);
    g_print("i=%d",i);
    for(int a=0;a<=i;a++)
	for(int b=0;b<=j;b++)
    {if(ok<=(i*j)){
	cc[0]=result[ok++];
	cc[1]=result[ok++];
	cc[2]=result[ok++];
	cc[3]=result[ok++];
	cc[4]=result[ok++];
	cc[5]=result[ok++];
	cc[6]=result[ok++];
	cc[7]=result[ok++];
        gtk_clist_append(GTK_CLIST(alist),(gchar**)(cc) ); //对cilst列表 构建 进行从无到有到数据填充
		      }} 
    gtk_clist_column_titles_show(GTK_CLIST(alist));//显示列标题
    gtk_container_add(GTK_CONTAINER(window),alist);//将标签盒加入窗口
    gtk_widget_show(alist);//显示表格
    gtk_widget_show(window);//显示窗口
    sqlite3_close(db);
    gtk_main();
}

//修改姓名函数
void input_name(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set name='%s' where school='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);} 
    sqlite3_free_table(result);
    sqlite3_close(db);
}
//学生班级修改函数
void input_class(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set class='%s' where school='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);}
    sqlite3_free_table(result);
    sqlite3_close(db);
}

//修改学号函数
void input_school(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set school='%s' where school ='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);} 
    sqlite3_free_table(result);
    sqlite3_close(db);
}
//修改电话函数
void input_tel(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set tel='%s' where school='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);} 
    sqlite3_free_table(result);
    sqlite3_close(db);
}
//修改身份证函数
void input_num(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set num='%s' where school='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);} 
    sqlite3_free_table(result);
    sqlite3_close(db);
}
//修改专业函数
void input_zhuanye(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set zhuanye='%s' where school='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);} 
    sqlite3_free_table(result);
    sqlite3_close(db);
}
//修改寝室信息函数
void input_dor(GtkWidget *button)
{   sqlite3 *db;
    char *sql;
    int rc;
    char bb[20];
    char **result;
    char *errmsg;
    int i,j;
    sqlite3_open("stu.db",&db);
    char b[15]="\0";
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(en1)));
    g_print("b=%s",b);
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
    sql=sqlite3_mprintf("update dangan set dor='%s' where school='%s';",b,bb);
    rc=sqlite3_exec(db,sql,NULL,NULL,&errmsg);
    sql=sqlite3_mprintf("select * from dangan where school='%s';",bb);
    rc=sqlite3_get_table(db,sql,&result,&i,&j,&errmsg);
    g_print("j=%d",j);
    g_print("i=%d",i);
    for(int a=0;a<i;a++)
	for(int b=1;b<j;b++){
    gtk_label_set_text(GTK_LABEL(biao4.la1),result[j+0]);
    gtk_label_set_text(GTK_LABEL(biao4.la2),result[j+1]);
    gtk_label_set_text(GTK_LABEL(biao4.la3),result[j+2]);
    gtk_label_set_text(GTK_LABEL(biao4.la4),result[j+3]);
    gtk_label_set_text(GTK_LABEL(biao4.la5),result[j+4]);
    gtk_label_set_text(GTK_LABEL(biao4.la6),result[j+5]);
    gtk_label_set_text(GTK_LABEL(biao4.la7),result[j+6]);
    gtk_label_set_text(GTK_LABEL(biao4.la8),result[j+7]);} 
    sqlite3_free_table(result);
    sqlite3_close(db);
}
//修改姓名小窗口
void change_name(GtkWidget *butt11)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改姓名");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("姓名");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_name), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);  
    gtk_widget_show_all(window1) ;
}
//修改班级小窗口
void change_class(GtkWidget *butt44)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改班级");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("班级");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_class), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);  
    gtk_widget_show_all(window1) ;

}
//修改学号小窗口
void change_school(GtkWidget *butt44)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改学号");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("学号");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_school), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window1) ;
}
//修改电话小窗口
void change_tel(GtkWidget *butt55)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改电话");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("电话");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_tel), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window1) ;
}
//修改身份证小窗口
void change_num(GtkWidget *butt66)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改身份证");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("身份证");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_num), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window1) ;
}
//修改专业小窗口
void change_zhuanye(GtkWidget *butt77)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改专业");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("专业");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_zhuanye), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);  
    gtk_widget_show_all(window1) ;
}
//修改住宿信息
void change_dor(GtkWidget *butt88)
{
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改宿舍");  
    gtk_widget_set_size_request(window1, 300,160);  
    GtkWidget *label;
    GtkWidget *fixed;
    GtkWidget *button;
    button=gtk_button_new_with_label("确认");
    fixed=gtk_fixed_new();
    label=gtk_label_new("宿舍");
    en1=gtk_entry_new();
    gtk_widget_set_size_request(label,40,40);
    gtk_widget_set_size_request(button,80,40);
    gtk_widget_set_size_request(en1,150,30);
    gtk_fixed_put(GTK_FIXED(fixed),label,25,25);
    gtk_fixed_put(GTK_FIXED(fixed),button,170,90);
    gtk_fixed_put(GTK_FIXED(fixed),en1,100,30);
    gtk_container_add(GTK_CONTAINER(window1),fixed);
    g_signal_connect(button, "clicked", G_CALLBACK(input_dor), NULL);
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);  
    gtk_widget_show_all(window1) ;
}
// 修改信息主界面
void change_info(GtkWidget *butto4)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案系统");  
    gtk_widget_set_size_request(window, 820,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt3=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt3), ""); 
    GtkWidget *image;
    image=gtk_image_new_from_file("zhi.jpg");
    gtk_widget_set_size_request(image, 820,600);  
    gtk_container_add(GTK_CONTAINER(fixed),image);
   //设置标签 
    GtkWidget *label;
    //设置按钮
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    
    GtkWidget *butt11;
    GtkWidget *butt22;
    GtkWidget *butt33;
    GtkWidget *butt44;
    GtkWidget *butt55;
    GtkWidget *butt66;
    GtkWidget *butt77;
    GtkWidget *butt88;
    
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("学号");
    butt2=gtk_button_new_with_label("姓名");
    butt3=gtk_button_new_with_label("性别");
    butt4=gtk_button_new_with_label("班级");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");

    butt11=gtk_button_new_with_label("学号");
    butt22=gtk_button_new_with_label("姓名");
    butt33=gtk_button_new_with_label("性别");
    butt44=gtk_button_new_with_label("班级");
    butt55=gtk_button_new_with_label("电话");
    butt66=gtk_button_new_with_label("身份证");
    butt77=gtk_button_new_with_label("专业");
    butt88=gtk_button_new_with_label("寝室");
    biao3.la1=gtk_label_new("");
    biao3.la2=gtk_label_new("");
    biao3.la3=gtk_label_new("");
    biao3.la4=gtk_label_new("");
    biao3.la5=gtk_label_new("");
    biao3.la6=gtk_label_new("");
    biao3.la7=gtk_label_new("");
    biao3.la8=gtk_label_new("");
    
    biao4.la1=gtk_label_new("");
    biao4.la2=gtk_label_new("");
    biao4.la3=gtk_label_new("");
    biao4.la4=gtk_label_new("");
    biao4.la5=gtk_label_new("");
    biao4.la6=gtk_label_new("");
    biao4.la7=gtk_label_new("");
    biao4.la8=gtk_label_new("");
    
    lc=gtk_label_new("请查找你要修改的学生");
   //设置标签内容 
    label=gtk_label_new("");
    gtk_label_set_text(GTK_LABEL(label),"请选择修改的信息");
     
   //设置构件大小 
    gtk_widget_set_size_request(label,180,50);
    gtk_widget_set_size_request(lc,180,50);
    gtk_widget_set_size_request(biao3.la1,100,50);
    gtk_widget_set_size_request(biao3.la2,100,50);
    gtk_widget_set_size_request(biao3.la3,100,50);
    gtk_widget_set_size_request(biao3.la4,100,50);
    gtk_widget_set_size_request(biao3.la5,100,50);
    gtk_widget_set_size_request(biao3.la6,100,50);
    gtk_widget_set_size_request(biao3.la7,100,50);
    gtk_widget_set_size_request(biao3.la8,100,50);
   
    gtk_widget_set_size_request(biao4.la1,100,50);
    gtk_widget_set_size_request(biao4.la2,100,50);
    gtk_widget_set_size_request(biao4.la3,100,50);
    gtk_widget_set_size_request(biao4.la4,100,50);
    gtk_widget_set_size_request(biao4.la5,100,50);
    gtk_widget_set_size_request(biao4.la6,100,50);
    gtk_widget_set_size_request(biao4.la7,100,50);
    gtk_widget_set_size_request(biao4.la8,100,50);
   //设置回调函数 

    gtk_widget_set_size_request(butt,100,30);
    gtk_widget_set_size_request(butt1,100,30);
    gtk_widget_set_size_request(butt2,100,30);
    gtk_widget_set_size_request(butt3,100,30);
    gtk_widget_set_size_request(butt4,100,30);
    gtk_widget_set_size_request(butt5,100,30);
    gtk_widget_set_size_request(butt6,100,30);
    gtk_widget_set_size_request(butt7,100,30);
    gtk_widget_set_size_request(butt8,100,30);
   //修改选项按钮 
    gtk_widget_set_size_request(butt11,100,30);
    gtk_widget_set_size_request(butt22,100,30);
    gtk_widget_set_size_request(butt33,100,30);
    gtk_widget_set_size_request(butt44,100,30);
    gtk_widget_set_size_request(butt55,100,30);
    gtk_widget_set_size_request(butt66,100,30);
    gtk_widget_set_size_request(butt77,100,30);
    gtk_widget_set_size_request(butt88,100,30);
    gtk_widget_set_size_request(txt3,200,30);
   //放入构建 
    gtk_fixed_put(GTK_FIXED(fixed),lc,40,40);
    gtk_fixed_put(GTK_FIXED(fixed),txt3,240,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt,500,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt1,10,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt2,110,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt3,210,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt4,310,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt5,410,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt6,510,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt7,610,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt8,710,100);

    gtk_fixed_put(GTK_FIXED(fixed),label,40,250);
    
    gtk_fixed_put(GTK_FIXED(fixed),butt11,10,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt22,110,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt33,210,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt44,310,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt55,410,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt66,510,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt77,610,300);
    gtk_fixed_put(GTK_FIXED(fixed),butt88,710,300);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao3.la8,710,150);
   //下排修改标签 
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la1,10,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la2,110,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la3,210,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la4,310,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la5,410,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la6,510,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la7,610,350);
    gtk_fixed_put(GTK_FIXED(fixed),biao4.la8,710,350);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_school1),NULL);  
    g_signal_connect(butt11, "clicked", G_CALLBACK(change_school), NULL);  
    g_signal_connect(butt22, "clicked", G_CALLBACK(change_name), NULL);  
    g_signal_connect(butt44, "clicked", G_CALLBACK(change_class), NULL);  
    g_signal_connect(butt55, "clicked", G_CALLBACK(change_tel), NULL);  
    g_signal_connect(butt66, "clicked", G_CALLBACK(change_num), NULL);  
    g_signal_connect(butt77, "clicked", G_CALLBACK(change_zhuanye), NULL);  
    g_signal_connect(butt88, "clicked", G_CALLBACK(change_dor), NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  
    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window); 

}


void  delete_info( GtkWidget *button4)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "学生信息删除系统");  
    gtk_widget_set_size_request(window, 820,300);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt4=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt4), ""); 

    GtkWidget *image;
    image=gtk_image_new_from_file("zhi.jpg");
    gtk_widget_set_size_request(image, 820,300);  
    gtk_container_add(GTK_CONTAINER(fixed),image);

    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    GtkWidget *butt9;
    
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
    butt9=gtk_button_new_with_label("确认删除");
    biao5.la1=gtk_label_new("");
    biao5.la2=gtk_label_new("");
    biao5.la3=gtk_label_new("");
    biao5.la4=gtk_label_new("");
    biao5.la5=gtk_label_new("");
    biao5.la6=gtk_label_new("");
    biao5.la7=gtk_label_new("");
    biao5.la8=gtk_label_new("");
    lc=gtk_label_new("请输入你要删除的学号");
   
   //设置标签内容 
    //gtk_label_set_text(GTK_LABEL(biao.la),"请输入查找的身份证");
     
   //设置构件大小 
    gtk_widget_set_size_request(lc,180,50);
    gtk_widget_set_size_request(biao5.la1,100,50);
    gtk_widget_set_size_request(biao5.la2,100,50);
    gtk_widget_set_size_request(biao5.la3,100,50);
    gtk_widget_set_size_request(biao5.la4,100,50);
    gtk_widget_set_size_request(biao5.la5,100,50);
    gtk_widget_set_size_request(biao5.la6,100,50);
    gtk_widget_set_size_request(biao5.la7,100,50);
    gtk_widget_set_size_request(biao5.la8,100,50);
   

    gtk_widget_set_size_request(butt,100,30);
    gtk_widget_set_size_request(butt1,100,30);
    gtk_widget_set_size_request(butt2,100,30);
    gtk_widget_set_size_request(butt3,100,30);
    gtk_widget_set_size_request(butt4,100,30);
    gtk_widget_set_size_request(butt5,100,30);
    gtk_widget_set_size_request(butt6,100,30);
    gtk_widget_set_size_request(butt7,100,30);
    gtk_widget_set_size_request(butt8,100,30);
    gtk_widget_set_size_request(butt9,100,30);
    //gtk_widget_set_size_request(txt2,200,30);
   //放入构建 
    gtk_fixed_put(GTK_FIXED(fixed),lc,40,40);
    gtk_fixed_put(GTK_FIXED(fixed),txt4,240,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt,500,50);
    gtk_fixed_put(GTK_FIXED(fixed),butt1,10,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt2,110,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt3,210,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt4,310,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt5,410,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt6,510,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt7,610,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt8,710,100);
    gtk_fixed_put(GTK_FIXED(fixed),butt9,390,250);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao5.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(delete_search),NULL);  
    g_signal_connect(butt9, "clicked", G_CALLBACK(delete_informat),NULL);  
    g_signal_connect(butt9, "clicked", G_CALLBACK(delete_dia),window);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}

     

void menu(void)  
{  
    //2.创建一个窗口 


    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    GtkWidget *fixed;
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *butto4;
    GtkWidget *button5;
    GtkWidget *button6;
    GtkWidget *button7;
    GtkWidget *button8;
    fixed=gtk_fixed_new();
    GtkWidget *image;
    image=gtk_image_new_from_file("3.jpg");
    gtk_widget_set_size_request(image, 800,600);  
    gtk_container_add(GTK_CONTAINER(fixed),image);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);       // 设置无边框   
    gtk_widget_set_app_paintable(window, TRUE); 

        //5.通过GdkPixbuf来写该图片大小
        //5.1创建pixbuf，需要占用资源，使用完需要释放
       /* GdkPixbuf *src = gdk_pixbuf_new_from_file("./img/2.png", NULL);
        //5.2修改图片大小
        GdkPixbuf *dst = gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
        GtkWidget *image_two = gtk_image_new_from_pixbuf(dst);
        //5.3pixbuf使用完需要释放其中资源
        g_object_unref(src);
        g_object_unref(dst);*/
    gtk_container_add(GTK_CONTAINER(window),fixed);
    //3.设置窗口标题  
    gtk_window_set_title(GTK_WINDOW(window), "档案管理系统");  
    //4.窗口在显示器中居中显示  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
    //5.设置窗口最小大小  
    gtk_widget_set_size_request(window, 800,600);  
    //6.固定窗口大小  
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE); 
    //创建按钮
    button=gtk_button_new_with_label("欢迎来到学生档案管理系统");
    button1=gtk_button_new_with_label("添加学生信息");
    button2=gtk_button_new_with_label("查询学生信息");
    button3=gtk_button_new_with_label("修改学生信息");
    butto4=gtk_button_new_with_label("删除学生信息");
    button5=gtk_button_new_with_label("读入学生信息");
    button6=gtk_button_new_with_label("保存学生信息");
    button7=gtk_button_new_with_label("显示学生信息");
    button8=gtk_button_new_with_label("退出系统");


    gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button1), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button2), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button3), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(butto4), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button5), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button6), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button7), GTK_RELIEF_NONE);
    gtk_button_set_relief(GTK_BUTTON(button8), GTK_RELIEF_NONE);
    //设置按钮大小 
    gtk_widget_set_size_request(button,300,50);
    gtk_widget_set_size_request(button1,200,50);
    gtk_widget_set_size_request(button2,200,50);
    gtk_widget_set_size_request(button3,200,50);
    gtk_widget_set_size_request(butto4,200,50);
    gtk_widget_set_size_request(button5,200,50);
    gtk_widget_set_size_request(button6,200,50);
    gtk_widget_set_size_request(button7,200,50);
    gtk_widget_set_size_request(button8,200,50);
   //将容器放进组合盒 
    gtk_fixed_put(GTK_FIXED(fixed),button,250,20);
    gtk_fixed_put(GTK_FIXED(fixed),button1,300,85);
    gtk_fixed_put(GTK_FIXED(fixed),button2,300,150);
    gtk_fixed_put(GTK_FIXED(fixed),button3,300,215);
    gtk_fixed_put(GTK_FIXED(fixed),butto4,300,280);
    gtk_fixed_put(GTK_FIXED(fixed),button5,300,345);
    gtk_fixed_put(GTK_FIXED(fixed),button6,300,410);
    gtk_fixed_put(GTK_FIXED(fixed),button7,300,475);
    gtk_fixed_put(GTK_FIXED(fixed),button8,300,540);
    //gtk_fixed_put(GTK_FIXED(fixed),image_one,0,0);
    //添加按钮
  
    //7."destroy"与gtk_main_quit链接  
    g_signal_connect(button1, "pressed", G_CALLBACK(deal), NULL);  
    g_signal_connect(button2, "pressed", G_CALLBACK(search_info), NULL);  
    g_signal_connect(button3, "pressed", G_CALLBACK(change_info), NULL);  
    g_signal_connect(butto4, "clicked", G_CALLBACK(delete_info), NULL);  
    g_signal_connect(button5, "pressed", G_CALLBACK(load_dia), NULL);  
    g_signal_connect(button7, "pressed", G_CALLBACK(xianshi), NULL);  
    g_signal_connect(button6, "pressed", G_CALLBACK(save_dia), window);  
    g_signal_connect(button8, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
    
    //8.显示所有窗口  
    gtk_widget_show_all(window);  
  
    //9.主事件循环  
    gtk_main();  

    return ;  
}  
  
void button_clicked(GtkWidget* button,int data)  
{  
    /*void gtk_entry_set_text(Gtk_Entry *entry,const gchr  *text) 
     *     将新的内容取代文本输入构件当前的内容。 
     *const gchar *gtk_entry_get_text(GtkEntry *entry) 
     *     获得当前文本输入构件的内容 
     */  
    if((int)data == 1){  
        gtk_entry_set_text(GTK_ENTRY(entry1),"");  
        gtk_entry_set_text(GTK_ENTRY(entry2),"");  
    } else if ((int)data == 2){  
        const gchar* username = gtk_entry_get_text(GTK_ENTRY(entry1));  
        const gchar* password = gtk_entry_get_text(GTK_ENTRY(entry2));  
        g_print("用户名是：%s",username);  
        g_print("\n");  
        g_print("密码是：%s\n",password); 
	if(strcmp(username,"liu")==0&&strcmp(password,"123")==0)
	menu();
    } else if((int)data == 3){  
        /*改变文本空的可编辑状态*/  
        gtk_editable_set_editable(GTK_EDITABLE(entry1),GTK_TOGGLE_BUTTON(button)->active);  
        gtk_editable_set_editable(GTK_EDITABLE(entry2),GTK_TOGGLE_BUTTON(button)->active);  
    }

}  
  


