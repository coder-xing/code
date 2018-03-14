#include <gtk/gtk.h>  
#include<string.h>
void deal(void) {
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *button;
    GtkWidget *entry;
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *entry3;
    GtkWidget *entry4;
    GtkWidget *entry5;
    GtkWidget *label;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *label3;
    GtkWidget *label4;
    GtkWidget *label5;
    GtkWidget *label6;
    char name[20];
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "添加学生信息");  

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);  
    
    gtk_widget_set_size_request(window, 800,600);  
    
    //gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  
    //gtk_table_set_col_spacings(GTK_TABLE(table), 2);

    table=gtk_table_new(20,10,TRUE);
   //设置按钮 
    button=gtk_button_new_with_label("添加");
    //button1=gtk_button_new_with_label("hello");
   //创建文本框
    entry=gtk_entry_new();
    entry1=gtk_entry_new();
    entry2=gtk_entry_new();
    entry3=gtk_entry_new();
    entry4=gtk_entry_new();
    entry5=gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), " "); 
    gtk_entry_set_text(GTK_ENTRY(entry1), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry2), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry3), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry4), " ");  
    gtk_entry_set_text(GTK_ENTRY(entry5), " ");
    strcpy(name,gtk_entry_get_text(GTK_ENTRY(entry)));
    g_print("%s",name);
    //创建标签
    label=gtk_label_new("  ");
    label1=gtk_label_new("姓名");
    label2=gtk_label_new("性别");
    label3=gtk_label_new("班级");
    label4=gtk_label_new("学号");
    label5=gtk_label_new("电话号码");
    label6=gtk_label_new("身份证号");
    //标签添加进容器
    gtk_table_attach_defaults(GTK_TABLE(table),label,0,40,0,5);
    gtk_table_attach_defaults(GTK_TABLE(table),label1,0,4,5,10);
    gtk_table_attach_defaults(GTK_TABLE(table),label2,0,4,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),label3,0,4,15,20);
    gtk_table_attach_defaults(GTK_TABLE(table),label4,0,4,20,25);
    gtk_table_attach_defaults(GTK_TABLE(table),label5,0,4,25,30);
    gtk_table_attach_defaults(GTK_TABLE(table),label6,0,4,30,35);
    //文本框添加进容器
    gtk_table_attach_defaults(GTK_TABLE(table),entry,5,10,5,10);
    gtk_table_attach_defaults(GTK_TABLE(table),entry1,5,10,10,15);
    gtk_table_attach_defaults(GTK_TABLE(table),entry2,5,10,15,20);
    gtk_table_attach_defaults(GTK_TABLE(table),entry3,5,10,20,25);
    gtk_table_attach_defaults(GTK_TABLE(table),entry4,5,10,25,30);
    gtk_table_attach_defaults(GTK_TABLE(table),entry5,5,10,30,35);

    gtk_table_attach_defaults(GTK_TABLE(table),button,40,50,50,55);
    g_signal_connect(button, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
   //按钮添加进容器  
    //gtk_table_attach_defaults(GTK_TABLE(table),button,0,20,18,27);
    gtk_container_add(GTK_CONTAINER(window),table);
    gtk_widget_show_all(window);
}


//void show_list(void)
//{
 //   GtkWidget* window;
  //  GtkWidget* frame;
   // GtkWidget* view;
   // GtkListStore* model;
//
 //   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 //   g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),window);
 //   gtk_window_set_title(GTK_WINDOW(window),"TREEVIEW --使用 LISTSTORE");
 //   gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
 //   gtk_container_set_border_width(GTK_CONTAINER(window),10);
 //   frame = gtk_frame_new("可编辑的列表");
 //   gtk_frame_set_label_align(GTK_FRAME(frame),1.0,0);
 //   gtk_container_add(GTK_CONTAINER(window),frame);
 //   /*创建单元格列表*/
//
 //   gtk_widget_show_all(window);
//}////

  
int main(int argc,char *argv[])  
{  
    //1.gtk环境初始化  
    gtk_init(&argc, &argv);  
  
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
    gtk_table_set_row_spacings(GTK_TABLE(table), 16);
    gtk_table_set_col_spacings(GTK_TABLE(table), 16);
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
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,20,0,12);
    gtk_table_attach_defaults(GTK_TABLE(table),button1,5,15,12,16);
    gtk_table_attach_defaults(GTK_TABLE(table),button2,5,15,16,20);
    gtk_table_attach_defaults(GTK_TABLE(table),button3,5,15,20,24);
    gtk_table_attach_defaults(GTK_TABLE(table),button4,5,15,24,28);
    gtk_table_attach_defaults(GTK_TABLE(table),button5,5,15,28,32);
    gtk_table_attach_defaults(GTK_TABLE(table),button6,5,15,32,36);
    gtk_table_attach_defaults(GTK_TABLE(table),button7,5,15,36,40);
  
    //7."destroy"与gtk_main_quit链接  
    g_signal_connect(button1, "pressed", G_CALLBACK(deal), NULL);  
    g_signal_connect(button2, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button3, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button4, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button5, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button6, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(button7, "pressed", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(table, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
  
    //8.显示所有窗口  
    gtk_widget_show_all(window);  
  
    //9.主事件循环  
    gtk_main();  

    return 0;  
}  

