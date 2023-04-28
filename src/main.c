#include <gtk/gtk.h>

GtkBuilder *builder;
GtkWidget *window;

void on_login_window_destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void on_register_bt_clicked(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void on_login_bt_clicked(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void on_user_register_btn_clicked(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("ui/interface.glade");

    gtk_builder_add_callback_symbols(
            builder,
            "on_login_window_destroy",      G_CALLBACK(on_login_window_destroy),
            "on_register_bt_clicked",       G_CALLBACK(on_register_bt_clicked),
            "on_login_bt_clicked",          G_CALLBACK(on_login_bt_clicked),
            "on_user_register_btn_clicked", G_CALLBACK(on_user_register_btn_clicked),
            NULL);
    gtk_builder_connect_signals(builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "madic-app"));

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}