#include <gtk/gtk.h>  
  
int main(int argc, char *argv[])  
{  
        //1.gtk初始化工作  
        gtk_init(&argc, &argv);  
  
        //2.创建一个顶层窗口  
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
  
        //3.创建一个button，文本信息为Hello gtk  
        GtkWidget *button = gtk_button_new_with_label("Hello gtk");  
  
        //4.将button放入窗口中（窗口也是一种容器）  
        gtk_container_add(GTK_CONTAINER(window), button);  
  
        //5.显示button  
        gtk_widget_show(button);  
        //6.显示window  
        gtk_widget_show(window);  
  
        //7.主事件循环  
        gtk_main();  
          
        return 0;  
  
}  
