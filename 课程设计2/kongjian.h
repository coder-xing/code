#ifndef kongjian_h
#define kongjain_h
#include<gtk/gtk.h>

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
static int callback(void *,int,char**,char**);
GdkPixbuf *create_pixbuf (const gchar *);
void chazhao1(GtkWidget*);//身份证号码查找
void chazhao2(GtkWidget*);//学号查找
void chazhao3(GtkWidget*);//电话查找
void show_dia(GtkWidget *, gpointer);
void delete_dia(GtkWidget *, gpointer);
void save_dia(GtkWidget *, gpointer);
void load_dia(GtkWidget *, gpointer);
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
void get_name(GtkWidget *,GtkWidget*);
void get_class(GtkWidget *,GtkWidget*);
void get_zhuanye(GtkWidget *,GtkWidget*);
void get_dor(GtkWidget *,GtkWidget*);
void get_name_clear(GtkWidget *,GtkWidget*);
void  chazhao1_clear( GtkWidget *);
void  chazhao2_clear( GtkWidget *);
void  chazhao3_clear( GtkWidget *);
void  chazhao1( GtkWidget *);
void  chazhao2( GtkWidget *);
void  chazhao3( GtkWidget *);
void  chazhao4( GtkWidget *);
void  chazhao5( GtkWidget *);
void  chazhao6( GtkWidget *);
void  chazhao7( GtkWidget *);
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
