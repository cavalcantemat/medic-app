#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;

    // Inicializa a biblioteca GTK
    gtk_init(&argc, &argv);

    // Cria um GtkBuilder e carrega a interface do usuário a partir do arquivo .glade
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "ui/interface.glade", NULL);

    // Cria a janela principal a partir da interface do usuário
    window = GTK_WIDGET(gtk_builder_get_object(builder, "janela_principal"));

    // Conecta o sinal "destroy" da janela ao evento gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Mostra a janela
    gtk_widget_show(window);

    // Executa o loop principal da biblioteca GTK
    gtk_main();

    return 0;
}
