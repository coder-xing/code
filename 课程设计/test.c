#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"kongjian.h"
    GtkWidget *win;
    GtkWidget* entry1;
    GtkWidget* entry2;
int main(int argc,char* argv[])
{   
    linklist l;
    stu=initlinklist(&l);
    GtkWidget* box;
    GtkWidget* box1;
    GtkWidget* box2;
    GtkWidget* box3;
    GtkWidget* label1;
    GtkWidget* label2;
    GtkWidget* button;
    GtkWidget* sep;
    //初始化
    gtk_init(&argc,&argv);
    //设置窗口
    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_window_set_title(GTK_WINDOW(win),"登录窗口");
    gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(win),20);

    box = gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(win),box);
    box1 = gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX(box),box1,FALSE,FALSE,5);
    box2 = gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX(box),box2,FALSE,FALSE,5);
    sep = gtk_hseparator_new();//分割线
    gtk_box_pack_start(GTK_BOX(box),sep,FALSE,FALSE,5);
    box3 = gtk_hbox_new(FALSE,0);
    gtk_box_pack_start(GTK_BOX(box),box3,TRUE,TRUE,5);

    gtk_window_set_icon(GTK_WINDOW(win), create_pixbuf("qq.jpg"));
    label1 = gtk_label_new("用户名：");
    entry1 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box1),label1,FALSE,FALSE,5);
    gtk_box_pack_start(GTK_BOX(box1),entry1,FALSE,FALSE,5);

    label2 = gtk_label_new("密    码：");
    entry2 = gtk_entry_new();
    /*设置输入文本不可见*/
    gtk_entry_set_visibility(GTK_ENTRY(entry2),FALSE);
    gtk_box_pack_start(GTK_BOX(box2),label2,FALSE,FALSE,5);
    gtk_box_pack_start(GTK_BOX(box2),entry2,FALSE,FALSE,5);

    button = gtk_check_button_new_with_label("Editable");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(button_clicked),(gpointer)3);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button),TRUE);
    gtk_box_pack_start(GTK_BOX(box3),button,TRUE,TRUE,10);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("清空");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(button_clicked),(gpointer)1);
    gtk_box_pack_start(GTK_BOX(box3),button,TRUE,TRUE,10);
    gtk_widget_show(box2);
    gtk_widget_show(box1);

    button = gtk_button_new_with_label("确认");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(button_clicked),(gpointer)2);
    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),win);
    gtk_box_pack_start(GTK_BOX(box3),button,TRUE,TRUE,5);
    gtk_widget_show(button);
    gtk_widget_show_all(win);
    gtk_main();
    return FALSE;
}

