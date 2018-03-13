#include <gtk/gtk.h>  
  
int main(int argc,char *argv[])  
{  
        //1.gtk环境初始化  
        gtk_init(&argc, &argv);  
  
        //2.创建一个窗口  
        //GtkWidget *window = gtk_window_new(GTK_WINDOW_POPUP);  
  
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
  
        //设置窗口标题  
        gtk_window_set_title(GTK_WINDOW(window), "hbox");  
  
        //3.1创建一个水平容器  
        GtkWidget *hbox = gtk_hbox_new(TRUE, 10);  
        //3.2将水平容器加入到窗口中  
        gtk_container_add(GTK_CONTAINER(window), hbox);  
  
        //4.1.1创建按钮button1  
        GtkWidget *button1 = gtk_button_new_with_label("button1");  
        //4.1.2将button1加入到hbox中  
        gtk_container_add(GTK_CONTAINER(hbox), button1);  
  
        //4.2.1创建按钮button2  
        GtkWidget *button2 = gtk_button_new_with_label("button2");  
        //4.2.2将button2加入到hbox  
        gtk_container_add(GTK_CONTAINER(hbox), button2);  
  
        //4.3.1创建按钮button3  
        GtkWidget *button3 = gtk_button_new_with_label("button3");  
        //4.3.2将button2加入到hbox  
        gtk_container_add(GTK_CONTAINER(hbox), button3);  
  
        //5.显示所有文件  
        gtk_widget_show_all(window);  
  
        //6.主事件循环  
        gtk_main();  
  
        return 0;  
}  
