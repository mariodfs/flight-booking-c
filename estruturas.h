/* 
 * File:   Estruturas.h
 * Author: mariodiogosilva
 *
 * Created on February 4, 2014, 3:34 PM
 */

#ifndef ESTRUTURAS_H
#define	ESTRUTURAS_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct cliente Cliente;
    typedef struct reserva Reserva;
    typedef struct voo Voo;
    typedef struct lnode_c *List_c;
    typedef struct lnode_v *List_v;
    typedef struct lnode_r *List_r;
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


#ifdef	__cplusplus
}
#endif

#endif	/* ESTRUTURAS_H */

