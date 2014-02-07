/* 
 * File:   structs_and_functions.h
 * Author: mariodiogosilva
 *
 * Created in 2009, modified in 2014
 */

#ifndef LISTA_LIGADA_DUPLA_H
#define	LISTA_LIGADA_DUPLA_H

typedef struct cliente Cliente;
typedef struct reserva Reserva;
typedef struct voo Voo;
typedef struct lnode_c* List_c;
typedef struct lnode_v* List_v;
typedef struct lnode_r* List_r;
typedef struct lnode_c List_node_cliente;
typedef struct lnode_v List_node_voo;
typedef struct lnode_r List_node_reserva;

struct cliente {
    int n_cliente;
    int n_voos_efectuados;
    unsigned long long telefone;
    char nome[33];
    char morada[33];
    char e_mail[33];
};

struct reserva {
    int n_reserva;
    int n_cliente;
    int n_voo;
    int dia_reserva;
    int mes_reserva;
    int ano_reserva;
    int hora_reserva;
    int minutos_reserva;
    int n_lugar;
};

struct voo {
    int n_voo;
    int dia_voo;
    int mes_voo;
    int ano_voo;
    int hora_voo;
    int minutos_voo;
    int lugares_vagos[50];
    int n_lugares_vagos;
    char origem[25];
    char destino[25];
};

struct lnode_c {
    Cliente cliente;
    List_c previous;
    List_c next;
};

struct lnode_v {
    Voo voo;
    List_v previous;
    List_v next;
};

struct lnode_r {
    Reserva reserva;
    List_r previous;
    List_r next;
};

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
int le_int_teclado(int* num, int tamanho);
int le_string_teclado(char* str, int tamanho);

#endif	/* LISTA_LIGADA_DUPLA_H */

