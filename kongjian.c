#include <gtk/gtk.h>  
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void chazhao1(GtkWidget*);
void chazhao2(GtkWidget*);
void chazhao3(GtkWidget*);
typedef struct Node{
    char name[20];
    char sex[8];
    char class[20];
    char school[10];
    char tel[10];
    char num[20];
    char zhuanye[20];
    char dor[6];
    struct Node *next;
}node;

typedef struct Lab{
    GtkWidget *la1;
    GtkWidget *la2;
    GtkWidget *la3;
    GtkWidget *la4;
    GtkWidget *la5;
    GtkWidget *la6;
    GtkWidget *la7;
    GtkWidget *la8;
}lab;

//查找函数标签指针
    GtkWidget *la,*lb,*lc;
lab biao,biao1,biao2,biao3;
//修改文本框
    GtkWidget *en1,*en2,*en3,*en4,*en5,*en6,*en7,*en8;

typedef GtkWidget* wenben;

wenben txt,txt1,txt2,txt3;
wenben radio_button1,radio_button2;
typedef struct Linklist{
    node *head;
    node *tail;
    int length;
}linklist;
linklist *stu;

typedef struct aa{
    GtkWidget *entry;
//    GtkWidget *entry1;
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
char sexx[4]="\0";
void show_dia(GtkWidget *button, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(window,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"添加完成", "通知");
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

int show_info(){
	node *p=NULL;
	p=stu->head;
	while(p!=NULL){
	    printf("姓名        性别    班级      学号           电话号码            身份证                   专业      寝室    \n");
	    printf("%-12s%-8s%-10s%-15s%-20s%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->zhuanye,p->dor);
	    p=p->next;
	}
	free(p);
}
void on_clicked(GtkWidget *button,gpointer data){
	node *p=NULL;
	p=(node *)malloc(sizeof(node));
	p->next=NULL;
	 strcpy(p->name,gtk_entry_get_text(GTK_ENTRY(add.entry)));
//	 strcpy(p->sex,gtk_entry_get_text(GTK_ENTRY(add.entry1)));
	 strcpy(p->sex,sexx);
	 strcpy(p->class,gtk_entry_get_text(GTK_ENTRY(add.entry2)));
	 strcpy(p->school,gtk_entry_get_text(GTK_ENTRY(add.entry3)));
	 strcpy(p->tel,gtk_entry_get_text(GTK_ENTRY(add.entry4)));
	 strcpy(p->num,gtk_entry_get_text(GTK_ENTRY(add.entry5)));
	 strcpy(p->zhuanye,gtk_entry_get_text(GTK_ENTRY(add.entry6)));
	 strcpy(p->dor,gtk_entry_get_text(GTK_ENTRY(add.entry7)));
	 g_print("我的名字是%s\n",p->name);
	 g_print("我的名字是%s\n",p->sex);
	 g_print("我的名字是%s\n",p->class);
	 g_print("我的名字是%s\n",p->school);
	 g_print("我的名字是%s\n",p->tel);
	 g_print("我的名字是%s\n",p->num);
	 g_print("我的名字是%s\n",p->zhuanye);
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


void clear(GtkWidget *button){
    gtk_entry_set_text(GTK_ENTRY(add.entry), " "); 
//    gtk_entry_set_text(GTK_ENTRY(add.entry1), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry2), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry3), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry4), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry5), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry6), " "); 
    gtk_entry_set_text(GTK_ENTRY(add.entry7), " "); 
}

//void (GtkWidget *radio_button1)
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
//    GtkWidget *radio_button1;
 //   GtkWidget *radio_button2; 

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
    gtk_entry_set_text(GTK_ENTRY(add.entry), " "); 
    //gtk_entry_set_text(GTK_ENTRY(add.entry1), " ");  
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
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_button1))==1)
	men();
    else
//    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio_button2))==1)
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
    button1=gtk_button_new_with_label("身份证号查找");
    button2=gtk_button_new_with_label("学号查找");
    button3=gtk_button_new_with_label("电话号码查找");
    button4=gtk_button_new_with_label("姓名查找");
    button5=gtk_button_new_with_label("班级查找");
    button6=gtk_button_new_with_label("宿舍楼查找");
    button7=gtk_button_new_with_label("寝室查找");
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
 /*   g_signal_connect(button1, "clicked", G_CALLBACK(chazhao), (gpointer)4);  
    g_signal_connect(button1, "clicked", G_CALLBACK(chazhao), (gpointer)5);  
    g_signal_connect(button1, "clicked", G_CALLBACK(chazhao), (gpointer)6);  
    g_signal_connect(button1, "clicked", G_CALLBACK(chazhao), (gpointer)7); */ 
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  
    
    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);  
}
//按身份证号查找子函数
int get_num(GtkWidget *butt){
    gchar bb[40];
    node *p=NULL;
    p=(node*)malloc(sizeof(node)); 
    p=stu->head;
    p->next=NULL;
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt)));
   //如果无数据则直接退出此函数 
    if(p==NULL){
	g_print("p为空");
	return 1;}
   while(p==NULL){
	if(0==strcmp(p->name,bb)){
		break;
	    } 
	else{
	    p=p->next;} 
   } 
    gtk_label_set_text(GTK_LABEL(biao.la1),p->name);
    gtk_label_set_text(GTK_LABEL(biao.la2),p->sex);
    gtk_label_set_text(GTK_LABEL(biao.la3),p->class);
    gtk_label_set_text(GTK_LABEL(biao.la4),p->school);
    gtk_label_set_text(GTK_LABEL(biao.la5),p->tel);
    gtk_label_set_text(GTK_LABEL(biao.la6),p->num);
    gtk_label_set_text(GTK_LABEL(biao.la7),p->zhuanye);
    gtk_label_set_text(GTK_LABEL(biao.la8),p->dor);
}
//按学号查找
int get_school(GtkWidget *butt){
    gchar bb[40];
    node *p=NULL;
    p=(node*)malloc(sizeof(node)); 
    p=stu->head;
    p->next=NULL;
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt1)));
   //如果无数据则直接退出此函数 
    if(p==NULL){
	g_print("p为空");
	return 1;}
   while(p==NULL){
	if(0==strcmp(p->school,bb)){
		break;
	    } 
	else{
	    p=p->next;} 
   } 
    gtk_label_set_text(GTK_LABEL(biao1.la1),p->name);
    gtk_label_set_text(GTK_LABEL(biao1.la2),p->sex);
    gtk_label_set_text(GTK_LABEL(biao1.la3),p->class);
    gtk_label_set_text(GTK_LABEL(biao1.la4),p->school);
    gtk_label_set_text(GTK_LABEL(biao1.la5),p->tel);
    gtk_label_set_text(GTK_LABEL(biao1.la6),p->num);
    gtk_label_set_text(GTK_LABEL(biao1.la7),p->zhuanye);
    gtk_label_set_text(GTK_LABEL(biao1.la8),p->dor);
}
//按学号查找并修改
int get_school1(GtkWidget *butt){
    gchar bb[40];
    node *p=NULL;
    p=(node*)malloc(sizeof(node)); 
    p=stu->head;
    p->next=NULL;
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt3)));
   //如果无数据则直接退出此函数 
    if(p==NULL){
	g_print("p为空");
	return 1;}
   while(p==NULL){
	if(0==strcmp(p->school,bb)){
		break;
	    } 
	else{
	    p=p->next;} 
   } 
    gtk_label_set_text(GTK_LABEL(biao3.la1),p->name);
    gtk_label_set_text(GTK_LABEL(biao3.la2),p->sex);
    gtk_label_set_text(GTK_LABEL(biao3.la3),p->class);
    gtk_label_set_text(GTK_LABEL(biao3.la4),p->school);
    gtk_label_set_text(GTK_LABEL(biao3.la5),p->tel);
    gtk_label_set_text(GTK_LABEL(biao3.la6),p->num);
    gtk_label_set_text(GTK_LABEL(biao3.la7),p->zhuanye);
    gtk_label_set_text(GTK_LABEL(biao3.la8),p->dor);
}

int get_tel(GtkWidget *butt){
    gchar bb[40];
    node *p=NULL;
    p=(node*)malloc(sizeof(node)); 
    p=stu->head;
    p->next=NULL;
    strcpy(bb,gtk_entry_get_text(GTK_ENTRY(txt2)));
   //如果无数据则直接退出此函数 
    if(p==NULL){
	g_print("p为空");
	return 1;}
   while(p==NULL){
	if(0==strcmp(p->tel,bb)){
		break;
	    } 
	else{
	    p=p->next;} 
   } 
    gtk_label_set_text(GTK_LABEL(biao2.la1),p->name);
    gtk_label_set_text(GTK_LABEL(biao2.la2),p->sex);
    gtk_label_set_text(GTK_LABEL(biao2.la3),p->class);
    gtk_label_set_text(GTK_LABEL(biao2.la4),p->school);
    gtk_label_set_text(GTK_LABEL(biao2.la5),p->tel);
    gtk_label_set_text(GTK_LABEL(biao2.la6),p->num);
    gtk_label_set_text(GTK_LABEL(biao2.la7),p->zhuanye);
    gtk_label_set_text(GTK_LABEL(biao2.la8),p->dor);
}
//个人信息查找窗口
void  chazhao1( GtkWidget *button1)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案查询系统");  
    gtk_widget_set_size_request(window, 820,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt), " "); 
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
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
    //gtk_label_set_text(GTK_LABEL(biao.la),"请输入查找的身份证");
   
     
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
    gtk_fixed_put(GTK_FIXED(fixed),biao.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_num),NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}


void  chazhao2( GtkWidget *button2)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案查询系统");  
    gtk_widget_set_size_request(window, 820,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt1=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt1), " "); 
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
    biao1.la1=gtk_label_new("");
    biao1.la2=gtk_label_new("");
    biao1.la3=gtk_label_new("");
    biao1.la4=gtk_label_new("");
    biao1.la5=gtk_label_new("");
    biao1.la6=gtk_label_new("");
    biao1.la7=gtk_label_new("");
    biao1.la8=gtk_label_new("");
    lb=gtk_label_new("请输入你要查询的学号");
   //设置标签内容 
    //gtk_label_set_text(GTK_LABEL(biao.la),"请输入查找的身份证");
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
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao1.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_school),NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}

void  chazhao3( GtkWidget *button3)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案查询系统");  
    gtk_widget_set_size_request(window, 820,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt2=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt2), " "); 
    GtkWidget *butt;
    GtkWidget *butt1;
    GtkWidget *butt2;
    GtkWidget *butt3;
    GtkWidget *butt4;
    GtkWidget *butt5;
    GtkWidget *butt6;
    GtkWidget *butt7;
    GtkWidget *butt8;
    
    butt=gtk_button_new_with_label("查找");
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");
    biao2.la1=gtk_label_new("");
    biao2.la2=gtk_label_new("");
    biao2.la3=gtk_label_new("");
    biao2.la4=gtk_label_new("");
    biao2.la5=gtk_label_new("");
    biao2.la6=gtk_label_new("");
    biao2.la7=gtk_label_new("");
    biao2.la8=gtk_label_new("");
    lc=gtk_label_new("请输入你要查询的电话");
   
   //设置标签内容 
    //gtk_label_set_text(GTK_LABEL(biao.la),"请输入查找的身份证");
     
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
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la1,10,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la2,110,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la3,210,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la4,310,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la5,410,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la6,510,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la7,610,150);
    gtk_fixed_put(GTK_FIXED(fixed),biao2.la8,710,150);
    g_signal_connect(butt, "clicked", G_CALLBACK(get_tel),NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  

    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}

     
void xianshi(GtkWidget *button6){
    GtkWidget *window;
    GtkWidget *textview;
    GtkTextBuffer *buffer;
    GtkWidget *fixed;
    GtkWidget *notebook;
    gchar buf[600]="\0";
    node *p;
    p=stu->head;
    if(p==NULL)
	return ;
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
    sprintf(buf,"%-12s%-8s%-10s%-15s%-20s%-25s%-12s%-8s\n",p->name,p->sex,p->class,p->school,p->tel,p->num,p->zhuanye,p->dor);
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
    node *p=(node*)malloc(sizeof(node));
    p=stu->head;
    p->next=NULL;
    char nul[40];
    strcpy(nul,p->name);
    GtkWidget *window;
    GtkWidget *clist;
    gchar *text2[8]={nul,"","helel","ss","ss","ss","ss","ss"}; //定义列表项数据

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
gtk_clist_set_column_title(GTK_CLIST(clist),6,"专业");
gtk_clist_set_column_title(GTK_CLIST(clist),7,"寝室");

gtk_clist_prepend(GTK_CLIST(clist),text2);

gtk_clist_column_titles_show(GTK_CLIST(clist));

gtk_container_add(GTK_CONTAINER(window),clist);

gtk_widget_show(clist);

gtk_widget_show(window);

}
void change_name(GtkWidget *butt11){
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window1), "修改姓名");  
    gtk_widget_set_size_request(window1, 200,100);  
    GtkWidget *label;
    label=gtk_label_new("姓名");

    gtk_widget_show(window1) ;
}

void change_info(GtkWidget *button4)
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window), "档案系统");  
    gtk_widget_set_size_request(window, 820,600);  
    GtkWidget *fixed;
    fixed =gtk_fixed_new();
    txt3=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(txt3), " "); 
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
    butt1=gtk_button_new_with_label("姓名");
    butt2=gtk_button_new_with_label("性别");
    butt3=gtk_button_new_with_label("班级");
    butt4=gtk_button_new_with_label("学号");
    butt5=gtk_button_new_with_label("电话");
    butt6=gtk_button_new_with_label("身份证");
    butt7=gtk_button_new_with_label("专业");
    butt8=gtk_button_new_with_label("寝室");

    butt11=gtk_button_new_with_label("姓名");
    butt22=gtk_button_new_with_label("性别");
    butt33=gtk_button_new_with_label("班级");
    butt44=gtk_button_new_with_label("学号");
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
    g_signal_connect(butt, "clicked", G_CALLBACK(get_school1),NULL);  
    g_signal_connect(butt11, "clicked", G_CALLBACK(change_name), NULL);  
    g_signal_connect(fixed, "delete_event", G_CALLBACK(gtk_main_quit), NULL);  
    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window); 

}

int main(int argc,char *argv[])  
{  
    //1.gtk环境初始化  
    gtk_init(&argc, &argv);  
    linklist l;
    stu=initlinklist(&l);
    //2.创建一个窗口  
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
    GtkWidget *fixed;
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *button5;
    GtkWidget *button6;
    GtkWidget *button7;

    fixed=gtk_fixed_new();
    //table =gtk_table_new(8,1,FALSE);
    gtk_container_add(GTK_CONTAINER(window),fixed);
//    gtk_table_set_row_spacings(GTK_TABLE(table), 8);
 //   gtk_table_set_col_spacings(GTK_TABLE(table), 8);
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
    button4=gtk_button_new_with_label("删除学生信息");
    button5=gtk_button_new_with_label("排序学生信息");
    button6=gtk_button_new_with_label("显示所有学生信息");
    button7=gtk_button_new_with_label("退出系统");
    //设置按钮大小 
    gtk_widget_set_size_request(button,300,50);
    gtk_widget_set_size_request(button1,200,50);
    gtk_widget_set_size_request(button2,200,50);
    gtk_widget_set_size_request(button3,200,50);
    gtk_widget_set_size_request(button4,200,50);
    gtk_widget_set_size_request(button5,200,50);
    gtk_widget_set_size_request(button6,200,50);
    gtk_widget_set_size_request(button7,200,50);
   //将容器放进组合盒 
    gtk_fixed_put(GTK_FIXED(fixed),button,250,40);
    gtk_fixed_put(GTK_FIXED(fixed),button1,300,105);
    gtk_fixed_put(GTK_FIXED(fixed),button2,300,170);
    gtk_fixed_put(GTK_FIXED(fixed),button3,300,235);
    gtk_fixed_put(GTK_FIXED(fixed),button4,300,300);
    gtk_fixed_put(GTK_FIXED(fixed),button5,300,365);
    gtk_fixed_put(GTK_FIXED(fixed),button6,300,430);
    gtk_fixed_put(GTK_FIXED(fixed),button7,300,495);
    //添加按钮
  
    //7."destroy"与gtk_main_quit链接  
    g_signal_connect(button1, "pressed", G_CALLBACK(deal), NULL);  
    g_signal_connect(button2, "pressed", G_CALLBACK(search_info), NULL);  
    g_signal_connect(button3, "pressed", G_CALLBACK(change_info), NULL);  
    g_signal_connect(button4, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button5, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button6, "pressed", G_CALLBACK(xianshi), NULL);  
    g_signal_connect(button7, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
  
    //gtk_container_add(GTK_CONTAINER(window),fixed);
    //8.显示所有窗口  
    gtk_widget_show_all(window);  
  
    //9.主事件循环  
    gtk_main();  

    return 0;  
}  

