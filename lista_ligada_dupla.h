/* 
 * File:   lista_ligada_dupla.h
 * Author: mariodiogosilva
 *
 * Created on February 4, 2014, 5:03 PM
 */

#ifndef LISTA_LIGADA_DUPLA_H
#define	LISTA_LIGADA_DUPLA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "estruturas.h"

    List_c cria_lista_cliente(void);
    List_v cria_lista_voo(void);
    List_r cria_lista_reserva(void);

    List_c destroi_lista_c(List_c lista);
    List_v destroi_lista_v(List_v lista);
    List_r destroi_lista_r(List_r lista);

    int lista_vazia_c(List_c lista);
    int lista_vazia_v(List_v lista);
    int lista_vazia_r(List_r lista);

    void procura_voo_numero_voo(List_v lista, int chave, List_v *ant, List_v *actual);
    void procura_reserva_numero_reserva(List_r lista, int chave, List_r *ant, List_r *actual);
    void procura_reserva_numero_cliente(List_r lista, int chave, List_r *ant, List_r *actual);
    void procura_reserva_numero_voo(List_r lista, int chave, List_r *ant, List_r *actual);

    int elimina_cliente_numero_cliente(List_c lista, int chave);
    int elimina_voo_numero_voo(List_v lista, int chave);
    int elimina_reserva_numero_reserva(List_r lista, int chave);
    void elimina_reserva_numero_cliente(List_r lista, int chave);
    void elimina_reserva_numero_voo(List_r lista, int chave);

    void insere_lista_cliente(List_c lista, int chave, char nome[], char morada[], char e_mail[], unsigned long long telefone);
    void insere_lista_voo(List_v lista, int chave, int dia_voo, int mes_voo, int ano_voo, int hora_voo, int minutos_voo, char origem[], char destino[]);
    void insere_lista_reserva(List_r lista, int chave, int n_cliente, int n_voo, int dia_reserva, int mes_reserva, int ano_reserva, int hora_reserva, int minutos_reserva, int lugar_voo);

    List_c pesquisa_cliente_numero_cliente(List_c lista, int chave);
    List_v pesquisa_voo_numero_voo(List_v lista, int chave);
    List_r pesquisa_reserva_numero_reserva(List_r lista, int chave);
    List_r pesquisa_reserva_numero_cliente(List_r lista, int chave);
    List_r pesquisa_reserva_numero_voo(List_r lista, int chave);

    void verifica_reserva_cliente(List_r lista, int n_cliente, int n_voo);
    int verifica_reserva_repetida(List_r lista, int n_cliente, int n_voo);

    void imprime_lista_clientes(List_c lista);
    void imprime_lista_voos(List_v lista);
    void imprime_lista_reservas(List_r lista);
    void imprime_n_voos_efectuados(List_c lista);

    void imprime_nome_voo(List_r lista_de_reservas, List_c lista_de_clientes, List_v voo_actual);
    void imprime_nome(List_c lista_de_clientes);

    int escreve_clientes(const char *name, List_c *a, int num);
    int escreve_voos(const char *name, List_v *a, int num);
    int escreve_reservas(const char *name, List_r *a, int num);
    int escreve_contadores(int n_clientes, int n_voos, int n_reservas);

    int le_contadores(int *n_clientes, int *n_voos, int *n_reservas);
    int le_clientes(const char *name, List_c a);
    int le_voos(const char *name, List_v a);
    int le_reservas(const char *name, List_r a);

    void insertion_sort(Cliente *vect[], int n);
    int quick_sort(Cliente* x[], int li, int ls);

    int data_test(List_v *actual, int dia, int mes, int ano);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTA_LIGADA_DUPLA_H */
