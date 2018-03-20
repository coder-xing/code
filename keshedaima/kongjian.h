#ifndef kongjian_h
#define kongjain_h
#include<gtk/gtk.h>

//int N=0,i=0;
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
 GtkWidget* entry1;
 GtkWidget* entry2;
    GtkWidget* window;
//查找函数标签指针
    GtkWidget *la,*lb,*lc;
lab biao,biao1,biao2,biao3,biao4,biao5;
//修改文本框
    GtkWidget *en1,*en2,*en3,*en4,*en5,*en6,*en7,*en8;
GtkWidget *la,*lb,*lc;
    GtkWidget *txt,*txt1,*txt2,*txt3,*txt4;
//wenben radio_button1,radio_button2;
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

void chazhao1(GtkWidget*);
void chazhao2(GtkWidget*);
void chazhao3(GtkWidget*);
linklist* initlinklist(linklist *);
int addtail(linklist *,node *);
int save_info(GtkWidget *);
linklist * load_info();
void show_dia(GtkWidget *, gpointer);
void delete_dia(GtkWidget *, gpointer);
void men();
void women();
int show_info();
void on_clicked(GtkWidget *,gpointer );
gpointer create_entry(gint max, gboolean editable, gboolean visible);
void clear(GtkWidget *button);
void deal(void);
void search_info(void);
int get_num(GtkWidget *);
int get_school(GtkWidget *);
int get_tel(GtkWidget *);
void  chazhao1( GtkWidget *);
void  chazhao2( GtkWidget *);
void  chazhao3( GtkWidget *);
void xianshi(GtkWidget *);
void  shi( GtkWidget *);
void input_name(GtkWidget *);
void input_class(GtkWidget *);
void input_school(GtkWidget *);
void input_tel(GtkWidget *);
void input_num(GtkWidget *);
void input_zhuanye(GtkWidget *);
void input_dor(GtkWidget *);
void change_name(GtkWidget *);
void change_class(GtkWidget *);
void change_school(GtkWidget *);
void change_tel(GtkWidget *);
void change_num(GtkWidget *);
void change_zhuanye(GtkWidget *);
void change_dor(GtkWidget *);
void change_info(GtkWidget *);
void  delete_info( GtkWidget *);
void delete_informat();
void menu(void);
void button_clicked(GtkWidget*,int);
#endif
