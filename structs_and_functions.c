#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structs_and_functions.h"

List_c cria_lista_cliente(void) {
    List_c aux;
    aux = (List_c) malloc(sizeof (List_node_cliente));
    if (aux != NULL) {
        aux->cliente.n_cliente = 0;
        aux->previous = NULL;
        aux->next = NULL;
    }
    return aux;
}

List_v cria_lista_voo(void) {
    List_v aux;
    aux = (List_v) malloc(sizeof ( List_node_voo));
    if (aux != NULL) {
        aux->voo.n_voo = 0;
        aux->previous = NULL;
        aux->next = NULL;
    }
    return aux;
}

List_r cria_lista_reserva(void) {
    List_r aux;
    aux = (List_r) malloc(sizeof ( List_node_reserva));
    if (aux != NULL) {
        aux->reserva.n_cliente = 0;
        aux->previous = NULL;
        aux->next = NULL;
    }
    return aux;
}

List_c destroi_lista_c(List_c lista) {
    List_c temp_ptr;
    while (lista_vazia_c(lista) == 0) {
        temp_ptr = lista;
        lista = lista->next;
        free(temp_ptr);
    }
    free(lista);
    return NULL;
}

List_v destroi_lista_v(List_v lista) {
    List_v temp_ptr;
    while (lista_vazia_v(lista) == 0) {
        temp_ptr = lista;
        lista = lista->next;
        free(temp_ptr);
    }
    free(lista);
    return NULL;
}

List_r destroi_lista_r(List_r lista) {
    List_r temp_ptr;
    while (lista_vazia_r(lista) == 0) {
        temp_ptr = lista;
        lista = lista->next;
        free(temp_ptr);
    }
    free(lista);
    return NULL;
}

int lista_vazia_c(List_c lista) {
    return ( lista->next == NULL ? 1 : 0);
}

int lista_vazia_v(List_v lista) {
    return ( lista->next == NULL ? 1 : 0);
}

int lista_vazia_r(List_r lista) {
    return ( lista->next == NULL ? 1 : 0);
}

void procura_cliente_numero_cliente(List_c lista, int chave, List_c *ant, List_c *actual) {
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)->cliente.n_cliente < chave) {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->cliente.n_cliente != chave)
        *actual = NULL;
}

void procura_voo_numero_voo(List_v lista, int chave, List_v *ant, List_v *actual) {
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)->voo.n_voo < chave) {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->voo.n_voo != chave)
        *actual = NULL;
}

void procura_reserva_numero_reserva(List_r lista, int chave, List_r *ant, List_r *actual) {
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)->reserva.n_reserva < chave) {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->reserva.n_reserva != chave)
        *actual = NULL;
}

void procura_reserva_numero_cliente(List_r lista, int chave, List_r *ant, List_r *actual) {
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)->reserva.n_cliente != chave) {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->reserva.n_cliente != chave)
        *actual = NULL;
}

void procura_reserva_numero_voo(List_r lista, int chave, List_r *ant, List_r *actual) {
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)->reserva.n_voo != chave) {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->reserva.n_voo != chave)
        *actual = NULL;
}

int elimina_cliente_numero_cliente(List_c lista, int chave) {
    List_c ant;
    List_c actual;
    procura_cliente_numero_cliente(lista, chave, &ant, &actual);
    if (actual != NULL) {
        if (actual->next != NULL) actual->next->previous = ant;
        ant->next = actual->next;
        free(actual);
        printf("\n   Eliminacao do cliente numero %d  efectuada.\n   ", chave);
        //system("pause");
        return 1;
    } else {
        printf("\n   Eliminacao nao efectuada. Cliente numero %d nao existente.\n   ", chave);
        //system("pause");
        return 0;
    }
}

int elimina_voo_numero_voo(List_v lista, int chave) {
    List_v ant;
    List_v actual;
    procura_voo_numero_voo(lista, chave, &ant, &actual);
    if (actual != NULL) {
        if (actual->next != NULL) actual->next->previous = ant;
        ant->next = actual->next;
        free(actual);
        printf("\n   Eliminacao do voo numero %d  efectuada.\n   ", chave);
        //system("pause");
        return 1;
    } else {
        printf("\n   Eliminacao nao efectuada. Voo numero %d nao existente.\n   ", chave);
        //system("pause");
        return 0;
    }
}

int elimina_reserva_numero_reserva(List_r lista, int chave) {
    List_r ant;
    List_r actual;
    procura_reserva_numero_reserva(lista, chave, &ant, &actual);
    if (actual != NULL) {
        if (actual->next != NULL) actual->next->previous = ant;
        ant->next = actual->next;
        free(actual);
        printf("\n   Eliminacao da reserva numero %d  efectuada.\n   ", chave);
        //system("pause");
        return 1;
    } else {
        printf("\n   Eliminacao nao efectuada. Reserva numero %d nao existente.\n   ", chave);
        //system("pause");
        return 0;
    }
}

void elimina_reserva_numero_cliente(List_r lista, int chave) {
    List_r ant;
    List_r actual;
    procura_reserva_numero_cliente(lista, chave, &ant, &actual);
    if (actual != NULL) {
        if (actual->next != NULL) actual->next->previous = ant;
        ant->next = actual->next;
        free(actual);
    }
}

void elimina_reserva_numero_voo(List_r lista, int chave) {
    List_r ant;
    List_r actual;
    procura_reserva_numero_voo(lista, chave, &ant, &actual);
    if (actual != NULL) {
        if (actual->next != NULL) actual->next->previous = ant;
        ant->next = actual->next;
        free(actual);
    }
}

void insere_lista_cliente(List_c lista, int chave, char nome[], char morada[], char e_mail[], unsigned long long telefone) {
    List_c no;
    List_c ant, inutil;
    no = (List_c) malloc(sizeof (List_node_cliente));
    if (no != NULL) {
        no->cliente.n_cliente = chave;
        strcpy(no->cliente.nome, nome);
        strcpy(no->cliente.morada, morada);
        strcpy(no->cliente.e_mail, e_mail);
        no->cliente.telefone = telefone;
        no->cliente.n_voos_efectuados = 0;
        procura_cliente_numero_cliente(lista, chave, &ant, &inutil);
        no->next = ant->next;
        no->previous = ant;
        if (ant->next != NULL)ant->next->previous = no;
        ant->next = no;
        printf("\n   Criacao de cliente efectuada. Atribuicao do numero %d ao cliente.\n   ", chave);
        //system("pause");
    }
}

void insere_lista_voo(List_v lista, int chave, int dia_voo, int mes_voo, int ano_voo, int hora_voo, int minutos_voo, char origem[], char destino[]) {
    List_v no;
    List_v ant, inutil;
    no = (List_v) malloc(sizeof (List_node_voo));
    if (no != NULL) {
        no->voo.n_voo = chave;
        no->voo.dia_voo = dia_voo;
        no->voo.mes_voo = mes_voo;
        no->voo.ano_voo = ano_voo;
        no->voo.hora_voo = hora_voo;
        no->voo.minutos_voo = minutos_voo;
        strcpy(no->voo.origem, origem);
        strcpy(no->voo.destino, destino);
        int i;
        for (i = 0; i < 50; i++) {
            no->voo.lugares_vagos[i] = 1;
        }
        no->voo.n_lugares_vagos = 50;
        procura_voo_numero_voo(lista, chave, &ant, &inutil);
        no->next = ant->next;
        no->previous = ant;
        if (ant->next != NULL)ant->next->previous = no;
        ant->next = no;
        printf("\n   Criacao de voo efectuada. Atribuicao do numero %d ao voo.\n   ", chave);
        //system("pause");
    }
}

void insere_lista_reserva(List_r lista, int chave, int n_cliente, int n_voo, int dia_reserva, int mes_reserva, int ano_reserva, int hora_reserva, int minutos_reserva, int lugar_voo) {
    List_r no;
    List_r ant, inutil;
    no = (List_r) malloc(sizeof (List_node_reserva));
    if (no != NULL) {
        no->reserva.n_reserva = chave;
        no->reserva.n_cliente = n_cliente;
        no->reserva.n_voo = n_voo;
        no->reserva.dia_reserva = dia_reserva;
        no->reserva.mes_reserva = mes_reserva;
        no->reserva.ano_reserva = ano_reserva;
        no->reserva.hora_reserva = hora_reserva;
        no->reserva.minutos_reserva = minutos_reserva;
        no->reserva.n_lugar = lugar_voo;
        procura_reserva_numero_reserva(lista, chave, &ant, &inutil);
        no->next = ant->next;
        no->previous = ant;
        if (ant->next != NULL)ant->next->previous = no;
        ant->next = no;
        printf("\n   Criacao de reserva efectuada. Atribuicao do numero %d a reserva.\n   ", chave);
        //system("pause");
    }
}

List_c pesquisa_cliente_numero_cliente(List_c lista, int chave) {
    List_c ant;
    List_c actual;
    procura_cliente_numero_cliente(lista, chave, &ant, &actual);
    return (actual);
}

List_v pesquisa_voo_numero_voo(List_v lista, int chave) {
    List_v ant;
    List_v actual;
    procura_voo_numero_voo(lista, chave, &ant, &actual);
    return (actual);
}

List_r pesquisa_reserva_numero_reserva(List_r lista, int chave) {
    List_r ant;
    List_r actual;
    procura_reserva_numero_reserva(lista, chave, &ant, &actual);
    return (actual);
}

List_r pesquisa_reserva_numero_cliente(List_r lista, int chave) {
    List_r ant;
    List_r actual;
    procura_reserva_numero_cliente(lista, chave, &ant, &actual);
    return (actual);
}

List_r pesquisa_reserva_numero_voo(List_r lista, int chave) {
    List_r ant;
    List_r actual;
    procura_reserva_numero_voo(lista, chave, &ant, &actual);
    return (actual);
}

void verifica_reserva_cliente(List_r lista, int n_cliente, int n_voo) {
    List_r l = lista->next;
    while (l) {
        if (l->reserva.n_cliente == n_cliente && l->reserva.n_voo == n_voo) {
            printf("\n\n   Cliente referido possui reserva no voo indicado.\n\n   ");
            //system("pause");
            break;
        }
        l = l->next;
    }
    if (!l) {
        printf("\n\n   Cliente referido nao possui reserva no voo indicado.\n\n   ");
        //system("pause");
    }
}

int verifica_reserva_repetida(List_r lista, int n_cliente, int n_voo) {
    List_r l = lista->next;
    int test = 0;
    while (l) {
        if (l->reserva.n_cliente == n_cliente && l->reserva.n_voo == n_voo) {
            test = 1;
            break;
        }
        l = l->next;
    }
    return test;
}

void imprime_lista_clientes(List_c lista) {
    List_c l = lista->next;
    int test = 1;
    if (!l) {
        printf("\n   Clientes nao existentes.\n   ");
        test = 0;
    }
    while (l) {
        printf("   --------------------------------------------------\n\n");
        printf("   Nome do cliente: %s\n", l->cliente.nome);
        printf("   Numero de cliente: %d\n", l->cliente.n_cliente);
        printf("   Numero de voos efectuados: %d\n", l->cliente.n_voos_efectuados);
        printf("   Numero de telefone: %llu\n", l->cliente.telefone);
        printf("   Morada do cliente: %s\n", l->cliente.morada);
        printf("   E-mail do cliente: %s\n", l->cliente.e_mail);
        l = l->next;
    }
    if (test == 1) {
        printf("   --------------------------------------------------\n\n");
        printf("   Numero de clientes existentes: %d\n", lista->cliente.n_cliente);
        printf("   --------------------------------------------------\n\n");
    }
}

void imprime_lista_voos(List_v lista) {
    List_v l = lista->next;
    int test = 1;
    if (!l) {
        printf("\n   Voos nao existentes.\n   ");
        test = 0;
    }
    while (l) {
        printf("   --------------------------------------------------\n\n");
        printf("   Numero de voo: %d\n", l->voo.n_voo);
        printf("   Dia de voo: %d\n", l->voo.dia_voo);
        printf("   Mes de voo: %d\n", l->voo.mes_voo);
        printf("   Ano de voo: %d\n", l->voo.ano_voo);
        printf("   Hora de voo: %d\n", l->voo.hora_voo);
        printf("   Minutos de voo: %d\n", l->voo.minutos_voo);
        printf("   Lugares vagos no voo: %d\n", l->voo.n_lugares_vagos);
        printf("   Origem do voo: %s\n", l->voo.origem);
        printf("   Destino do voo: %s\n", l->voo.destino);
        l = l->next;
    }
    if (test == 1) {
        printf("   --------------------------------------------------\n\n");
        printf("   Numero de voos existentes: %d\n", lista->voo.n_voo);
        printf("   --------------------------------------------------\n\n");
    }
}

void imprime_lista_reservas(List_r lista) {
    List_r l = lista->next;
    int test = 1;
    if (!l) {
        printf("\n   Reservas nao existentes.\n   ");
        test = 0;
    }
    while (l) {
        printf("   --------------------------------------------------\n\n");
        printf("   Numero de reserva: %d\n", l->reserva.n_reserva);
        printf("   Numero de voo: %d\n", l->reserva.n_voo);
        printf("   Numero de cliente: %d\n", l->reserva.n_cliente);
        printf("   Dia de reserva: %d\n", l->reserva.dia_reserva);
        printf("   Mes de reserva: %d\n", l->reserva.mes_reserva);
        printf("   Ano de reserva: %d\n", l->reserva.ano_reserva);
        printf("   Hora de reserva: %d\n", l->reserva.hora_reserva);
        printf("   Minutos de reserva: %d\n", l->reserva.minutos_reserva);
        printf("   Numero de lugar no voo: %d\n", l->reserva.n_lugar);
        l = l->next;
    }
    if (test == 1) {
        printf("   --------------------------------------------------\n\n");
        printf("   Numero de reservas existentes: %d\n", lista->reserva.n_cliente);
        printf("   --------------------------------------------------\n\n");
    }
}

void imprime_n_voos_efectuados(List_c lista) {
    int i = 0;
    int n_clientes = lista->cliente.n_cliente;
    Cliente * lista_clientes_n_voo[ n_clientes];
    List_c l = lista->next;
    if (!l)printf("\n   Listagem nao efectuada. Passageiros nao existentes.\n   ");
    while (l) {
        lista_clientes_n_voo[ i] = &(l->cliente);
        l = l->next;
        i++;
    }
    quick_sort(lista_clientes_n_voo, 0, n_clientes - 1);
    i = n_clientes - 1;
    for (i; i >= 0; i--) {
        printf("   ---------------------------------------------");
        printf("\n\n   Nome do cliente: %s\n", (*lista_clientes_n_voo[ i]).nome);
        printf("   Numero de cliente: %d\n", (*lista_clientes_n_voo[ i]).n_cliente);
        printf("   Numero de voos efectuados: %d\n", (*lista_clientes_n_voo[ i]).n_voos_efectuados);
    }
}

void insertion_sort(Cliente *vect[], int n) {
    int j, k;
    Cliente *y;
    for (k = 1; k < n; k++) {
        y = vect[k];
        for (j = k - 1; j >= 0 && strcmp((*y).nome, (*vect[j]).nome) < 0; j--)
            vect[j + 1] = vect[j];
        vect[j + 1] = y;
    }
}

void imprime_nome_voo(List_r lista_de_reservas, List_c lista_de_clientes, List_v voo_actual) {
    int i = 0;
    int n_clientes = 50 - voo_actual->voo.n_lugares_vagos;
    int lista_clientes_reserva[ n_clientes];
    List_r l = lista_de_reservas->next;
    if (!l) {
        printf("\n   Listagem nao efectuada. Reservas nao existentes.\n   ");
        return;
    }
    while (l) {
        if (l->reserva.n_voo == voo_actual->voo.n_voo) {
            lista_clientes_reserva[ i] = l->reserva.n_cliente;
            i++;
        }
        l = l->next;
    }
    i = 0;
    Cliente * lista_clientes[ n_clientes];
    for (i; i < n_clientes; i++) {
        lista_clientes[ i] = &(pesquisa_cliente_numero_cliente(lista_de_clientes, lista_clientes_reserva[i])->cliente);
    }

    insertion_sort(lista_clientes, n_clientes);
    i = 0;
    if (n_clientes > 0) printf("\n\n   Passageiros do voo numero %d:\n", voo_actual->voo.n_voo);
    if (n_clientes == 0) printf("\n\n   Listagem nao efectuada. Passageiros nao existentes.\n");
    for (i; i < n_clientes; i++) {
        printf("   ---------------------------------------------");
        printf("\n\n   Nome do cliente: %s\n", (*lista_clientes[ i]).nome);
        printf("   Numero do cliente: %d\n", (*lista_clientes[ i]).n_cliente);

    }
}

void imprime_nome(List_c lista_de_clientes) {
    int i = 0;
    int n_clientes = lista_de_clientes->cliente.n_cliente;
    if (n_clientes == 0) {
        printf("\n   Listagem nao efectuada. Clientes nao existentes.\n   ");
        return;
    }
    List_c l;
    l = lista_de_clientes->next;
    Cliente * lista_clientes[ n_clientes];
    while (l) {
        lista_clientes[ i] = &(l->cliente);
        l = l->next;
        i++;
    }

    insertion_sort(lista_clientes, n_clientes);
    i = 0;
    for (i; i < n_clientes; i++) {
        printf("   ---------------------------------------------");
        printf("\n\n   Nome do cliente: %s\n", (*lista_clientes[ i]).nome);
        printf("   Numero do cliente: %d\n", (*lista_clientes[ i]).n_cliente);
    }
}

int quick_sort(Cliente* x[], int li, int ls) {
    Cliente *a, *temp;
    int down, up;
    a = x[li];
    down = li;
    up = ls;
    while (down < up) {
        while ((*x[down]).n_voos_efectuados <= (*a).n_voos_efectuados && down < ls)
            down++;
        while ((*x[up]).n_voos_efectuados > (*a).n_voos_efectuados)
            up--;
        if (down < up) {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[li] = x[up];
    x[up] = a;
    return up;
}

int escreve_clientes(const char *name, List_c *a, int num) {
    FILE *fp = fopen(name, "wb");
    int cnt = -1;

    if (fp != NULL) {
        List_c L = (*a);
        cnt = 0;
        int i = 0;
        for (i; i < num; i++) {
            L = L->next;
            cnt += fwrite(L, sizeof (List_node_cliente), 1, fp);
        }
        fclose(fp);
    }

    return cnt;
}

int escreve_voos(const char *name, List_v *a, int num) {
    FILE *fp = fopen(name, "wb");
    int cnt = -1;

    if (fp != NULL) {
        List_v L = (*a);
        cnt = 0;
        int i = 0;
        for (i; i < num; i++) {
            L = L->next;
            cnt += fwrite(L, sizeof (List_node_voo), 1, fp);
        }
        fclose(fp);
    }

    return cnt;
}

int escreve_reservas(const char *name, List_r *a, int num) {
    FILE *fp = fopen(name, "wb");
    int cnt = -1;

    if (fp != NULL) {
        List_r L = (*a);
        cnt = 0;
        int i = 0;
        for (i; i < num; i++) {
            L = L->next;
            cnt += fwrite(L, sizeof (List_node_reserva), 1, fp);
        }
        fclose(fp);
    }

    return cnt;
}

int escreve_contadores(int n_clientes, int n_voos, int n_reservas) {
    FILE *f;
    f = fopen("contadores.txt", "w");
    int cnt = -1;
    if (f != NULL) {
        cnt = 1;
        fprintf(f, "%d\n", n_clientes);
        fprintf(f, "%d\n", n_voos);
        fprintf(f, "%d\n", n_reservas);

        fclose(f);
    }

    return cnt;
}

int le_contadores(int *n_clientes, int *n_voos, int *n_reservas) {
    FILE *f = fopen("contadores.txt", "r");
    int lidos = -1;
    if (f != NULL) {
        lidos = 1;
        fscanf(f, "%d", n_clientes);
        fscanf(f, "%d", n_voos);
        fscanf(f, "%d", n_reservas);

        fclose(f);
    }

    return lidos;
}

int le_clientes(const char *name, List_c a) {
    long size;
    FILE *fp = fopen(name, "rb");
    int cnt = -1;

    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) / sizeof (List_node_cliente);
        rewind(fp);

        a->cliente.n_cliente = size;

        int i = 0;
        cnt = 0;
        int chave;
        for (i; i < size; i++) {
            List_c no;
            List_c ant, inutil;
            no = (List_c) malloc(sizeof (List_node_cliente));

            if (no != NULL) {
                cnt += fread(no, sizeof (List_node_cliente), 1, fp);

                chave = no->cliente.n_cliente;
                procura_cliente_numero_cliente(a, chave, &ant, &inutil);
                no->next = ant->next;
                no->previous = ant;
                if (ant->next != NULL)ant->next->previous = no;
                ant->next = no;
            }
        }
        fclose(fp);
    }

    return cnt;
}

int le_voos(const char *name, List_v a) {
    long size;
    FILE *fp = fopen(name, "rb");
    int cnt = -1;

    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) / sizeof (List_node_voo);
        rewind(fp);

        a->voo.n_voo = size;

        int i = 0;
        cnt = 0;
        int chave;
        for (i; i < size; i++) {
            List_v no;
            List_v ant, inutil;
            no = (List_v) malloc(sizeof (List_node_voo));

            if (no != NULL) {
                cnt += fread(no, sizeof (List_node_voo), 1, fp);

                chave = no->voo.n_voo;
                procura_voo_numero_voo(a, chave, &ant, &inutil);
                no->next = ant->next;
                no->previous = ant;
                if (ant->next != NULL)ant->next->previous = no;
                ant->next = no;
            }
        }
        fclose(fp);
    }

    return cnt;
}

int le_reservas(const char *name, List_r a) {
    long size;
    FILE *fp = fopen(name, "rb");
    int cnt = -1;

    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) / sizeof (List_node_reserva);
        rewind(fp);

        a->reserva.n_cliente = size;

        int i = 0;
        cnt = 0;
        int chave;
        for (i; i < size; i++) {
            List_r no;
            List_r ant, inutil;
            no = (List_r) malloc(sizeof (List_node_reserva));

            if (no != NULL) {
                cnt += fread(no, sizeof (List_node_reserva), 1, fp);

                chave = no->reserva.n_reserva;
                procura_reserva_numero_reserva(a, chave, &ant, &inutil);
                no->next = ant->next;
                no->previous = ant;
                if (ant->next != NULL)ant->next->previous = no;
                ant->next = no;
            }
        }
        fclose(fp);
    }

    return cnt;
}

int data_test(List_v *actual, int dia, int mes, int ano) {
    if ((*actual)-> voo.ano_voo < ano)return 1;
    if ((*actual)-> voo.ano_voo == ano && (*actual)-> voo.mes_voo < mes)return 1;
    if ((*actual)-> voo.ano_voo == ano && (*actual)-> voo.mes_voo == mes && (*actual)-> voo.dia_voo < dia)return 1;
    return 0;
}

// READ INT FROM KEYBOARD

int le_int_teclado(int* num, int tamanho) {
    char* p;
    char linha[tamanho];

    if (fgets(linha, tamanho, stdin) != NULL) {
        if ((p = strchr(linha, '\n')) != NULL)
            *p = '\0';
        sscanf(linha, "%d", num);
        return EXIT_SUCCESS;
    } else
        return EXIT_FAILURE;
}

// READ STRING FROM KEYBOARD

int le_string_teclado(char* str, int tamanho) {
    char* p;
    char linha[tamanho];

    if (fgets(linha, tamanho, stdin) != NULL) {
        if ((p = strchr(linha, '\n')) != NULL)
            *p = '\0';
        strcpy(str, linha);
        return EXIT_SUCCESS;
    } else
        return EXIT_FAILURE;
}