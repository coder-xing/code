#include <gtk/gtk.h>  
  
int main(int argc,char *argv[])  
{  
    //1.gtk环境初始化  
    gtk_init(&argc, &argv);  
  
    //2.创建一个窗口  
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
  
    //3.设置窗口标题  
    gtk_window_set_title(GTK_WINDOW(window), "window");  
  
    //4.窗口在显示器中居中显示  
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
  
    //5.设置窗口最小大小  
    gtk_widget_set_size_request(window, 400,300);  
  
    //6.固定窗口大小  
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);  
  
    //7."destroy"与gtk_main_quit链接  
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
  
    //8.显示所有窗口  
    gtk_widget_show_all(window);  
  
    //9.主事件循环  
    gtk_main();  
  
  
    return 0;  
}  

