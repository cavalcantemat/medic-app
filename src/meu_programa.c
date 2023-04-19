#include <gtk/gtk.h>

// Função callback que é chamada quando a janela é destruída
void on_window_destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc, &argv);

    // Cria uma janela
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Conecta o sinal de destruição da janela à função on_window_destroy()
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // Exibe a janela
    gtk_widget_show_all(window);

    // Entra no loop principal do GTK
    gtk_main();

    return 0;
}
