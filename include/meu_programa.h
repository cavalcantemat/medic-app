#ifndef MEU_PROGRAMA_H
#define MEU_PROGRAMA_H

#include <gtk/gtk.h>

/* Função para inicializar a janela principal */
GtkWidget *criar_janela_principal();

/* Função para inicializar os botões */
GtkWidget *criar_botao_ok();
GtkWidget *criar_botao_cancelar();

/* Função para exibir uma mensagem de erro */
void exibir_mensagem_de_erro(const char *mensagem);

#endif /* MEU_PROGRAMA_H */
