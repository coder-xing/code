#include<gtk/gtk.h>

void deal_pressed(GtkButton *button,gpointer user_data){
    GtkWidget *window1;
    window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window1);  
}
int main(int argc,char *argv[])  
{  
        //1.gtk环境初始化  
        gtk_init(&argc, &argv);  
  
        //2.创建一个窗口  
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);   
        //3.创建一个表格容器5行4列  
        GtkWidget *table = gtk_table_new(6,1,TRUE);  
        //将table加入到window中  
        gtk_container_add(GTK_CONTAINER(window), table);  
  
        //4.创建一个行编辑  
        //设置行编辑的内容  
        //设置行编辑不允许编辑，只能显示用  
	//设置行间距
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2); 
        //5.创建多个按钮  
        GtkWidget *entry = gtk_button_new_with_label("欢迎来到学生信息管理系统");//数值键0  
        GtkWidget *button0 = gtk_button_new_with_label("1:添加学生信息");//数值键0  
        GtkWidget *button1 = gtk_button_new_with_label("2:修改学生信息");//数值键1  
        GtkWidget *button2 = gtk_button_new_with_label("3:打印学生信息");//数值键2  
        GtkWidget *button3 = gtk_button_new_with_label("4:排序学生信息");//数值键3  
        GtkWidget *button4 = gtk_button_new_with_label("5:退出系统");//数值键4  
  
  
        //6.布局将上面的按钮均放入table容器中  
        gtk_table_attach_defaults(GTK_TABLE(table), entry, 0, 5, 0, 2);  
        gtk_table_attach_defaults(GTK_TABLE(table), button0, 2, 3, 2, 3);  
        gtk_table_attach_defaults(GTK_TABLE(table), button1, 2, 3, 3, 4);  
        gtk_table_attach_defaults(GTK_TABLE(table), button2, 2, 3, 4, 5);  
        gtk_table_attach_defaults(GTK_TABLE(table), button3, 2, 3, 5, 6);  
        gtk_table_attach_defaults(GTK_TABLE(table), button4, 2, 3, 6, 7);  
	g_signal_connect(button0, "pressed", G_CALLBACK(deal_pressed), entry);
	g_signal_connect(GTK_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
        //7.显示所有控件  
        gtk_widget_show_all(window);  
  
        //8.主事件循环  
        gtk_main();  
  
        return 0;  
}  
