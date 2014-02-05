/* 
 * File:   main.c
 * Author: mariodiogosilva
 *
 * Created on February 4, 2014, 3:13 PM
 */

#include <stdio.h>
#include <string.h>

#include "lista_ligada_dupla.h"

#define BUFSIZE 32

int main(int argc, char** argv) {
    List_c lista_de_clientes = cria_lista_cliente();
    List_v lista_de_voos = cria_lista_voo();
    List_r lista_de_reservas = cria_lista_reserva();

    int n_cliente = 1;
    int n_voo = 1;
    int n_reserva = 1;

    printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Iniciacao do programa\n\n");

    int lidos;
    lidos = le_contadores(&n_cliente, &n_voo, &n_reserva);
    if (lidos == -1) printf("\n   Ficheiro de contadores nao lido.\n   Provavel primeira utilizacao do programa ou erro na leitura.\n");
    else if (lidos == 1) printf("\n   Ficheiro de contadores lido com sucesso.\n");

    lidos = le_clientes("clientes", lista_de_clientes);
    if (lidos == -1) printf("\n   Ficheiro de clientes nao lido.\n   Provavel primeira utilizacao do programa ou erro na leitura.\n");
    else if (lidos == 0)printf("\n   Ficheiro de clientes lido com erro na leitura dos valores\n   ou clientes nao existentes.\n");
    else printf("\n   Ficheiro de clientes lido com sucesso.\n");

    lidos = le_voos("voos", lista_de_voos);
    if (lidos == -1) printf("\n   Ficheiro de voos nao lido.\n   Provavel primeira utilizacao do programa ou erro na leitura.\n");
    else if (lidos == 0)printf("\n   Ficheiro de voos lido com erro na leitura dos valores\n   ou voos nao existentes.\n");
    else printf("\n   Ficheiro de voos lido com sucesso.\n");

    lidos = le_reservas("reservas", lista_de_reservas);
    if (lidos == -1) printf("\n   Ficheiro de reservas nao lido.\n   Provavel primeira utilizacao do programa ou erro na leitura.\n\n   ");
    else if (lidos == 0)printf("\n   Ficheiro de reservas lido com erro na leitura dos valores\n   ou reservas nao existentes.\n\n   ");
    else printf("\n   Ficheiro de reservas lido com sucesso.\n\n   ");

    printf("\n\n   Programa considerado iniciado com sucesso.\n\n\n   ");

    //system("pause");

    char string_test[BUFSIZE];
    char nome[33];
    char morada[33];
    char e_mail[33];
    char origem[25];
    char destino[25];
    char cidadeC[25] = "Cernache";
    char cidadeL[25] = "Lisboa";
    unsigned long long telefone;
    int number_cliente;
    int number_voo;
    int number_reserva;
    int dia_voo, mes_voo, ano_voo, hora_voo, minutos_voo;
    int dia_reserva, mes_reserva, ano_reserva, hora_reserva, minutos_reserva, lugar_voo;
    int test = 0;
    int viagem;
    int voo_efectuado = 0;
    int escritos;
    char* p;

    int opcao;
    do {
        if (lista_de_clientes->cliente.n_cliente == 0) n_cliente = 1;
        if (lista_de_voos->voo.n_voo == 0) n_voo = 1;
        if (lista_de_reservas->reserva.n_cliente == 0) n_reserva = 1;

        do {
            opcao = 8;
            //fflush(stdin);
            //system("cls");
            printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Menu Inicial\n\n");
            printf("   1 - Criar/eliminar/visualizar clientes;\n   2 - Criar/eliminar/visualizar voos;\n   3 - Criar/eliminar/visualizar reservas;\n\
   4 - Visionar lista ordenada de passageiros por nome;\n   5 - Visionar lista ordenada de passageiros por n. de voos efectuados;\n\
   6 - Verificar se um passageiro tem reserva num voo;\n   7 - Sair;\n\n   Opcao: ");
            fgets(string_test, sizeof (string_test), stdin);
            //scanf("%d", &opcao);
            sscanf(string_test, "%d", &opcao);
        } while (opcao < 1 || opcao > 7);

        if (opcao == 1) {
            do {
                opcao = 8;
                //fflush(stdin);
                //system("cls");
                printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Criar/eliminar/verificar clientes\n\n");
                printf("   1 - Criar Cliente;\n   2 - Eliminar Cliente;\n   3 - Visualizar clientes;\n   4 - Voltar ao menu anterior;\n   7 - Sair;\n\n   Opcao: ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &opcao);
            } while (opcao < 1 || opcao > 7 || opcao == 5 || opcao == 6);

            if (opcao == 1) {
                //fflush(stdin);
                printf("\n   Nome do cliente ( max. %lu caracteres): ", sizeof (string_test));
                if (fgets(string_test, sizeof (string_test), stdin) != NULL) {
                    if ((p = strchr(string_test, '\n')) != NULL)
                        *p = '\0';
                    strcpy(nome, string_test);
                }
                printf("\n   Morada do cliente ( max. %lu caracteres): ", sizeof (string_test));
                if (fgets(string_test, sizeof (string_test), stdin) != NULL) {
                    if ((p = strchr(string_test, '\n')) != NULL)
                        *p = '\0';
                    strcpy(morada, string_test);
                }
                printf("\n   E_mail do cliente ( max. %lu caracteres): ", sizeof (string_test));
                if (fgets(string_test, sizeof (string_test), stdin) != NULL) {
                    if ((p = strchr(string_test, '\n')) != NULL)
                        *p = '\0';
                    strcpy(e_mail, string_test);
                }
                printf("\n   Telefone do cliente: ");
                //fflush(stdin);
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%llu", &telefone);
                //scanf("%llu", &telefone);
                insere_lista_cliente(lista_de_clientes, n_cliente, nome, morada, e_mail, telefone);
                lista_de_clientes->cliente.n_cliente++;
                n_cliente++;

                escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
                if (escritos == -1) {
                    printf("\n   Ficheiro de contadores nao escrito.\n");
                    return -1;
                } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

                escritos = escreve_clientes("clientes", &lista_de_clientes, lista_de_clientes->cliente.n_cliente);
                if (escritos == -1) {
                    printf("\n   Ficheiro de clientes nao escrito.\n");
                    return -1;
                } else if (escritos == 0)printf("\n   Ficheiro de clientes escrito com erro nos valores\n   ou clientes nao existentes.\n");
                else printf("\n   Ficheiro de clientes escrito com sucesso.\n");


            } else if (opcao == 2) {
                //fflush(stdin);
                printf("\n   Numero do cliente( Para voltar ao menu anterior inserir -1): ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &number_cliente);
                //scanf("%d", &number_cliente);
                List_r reserva_actual = pesquisa_reserva_numero_cliente(lista_de_reservas, number_cliente);
                while (reserva_actual != NULL) {
                    List_v voo_actual = pesquisa_voo_numero_voo(lista_de_voos, reserva_actual->reserva.n_voo);
                    voo_actual->voo.n_lugares_vagos++;
                    voo_actual->voo.lugares_vagos[ reserva_actual->reserva.n_lugar - 1] = 1;
                    elimina_reserva_numero_cliente(lista_de_reservas, number_cliente);
                    lista_de_reservas->reserva.n_cliente--;
                    reserva_actual = pesquisa_reserva_numero_cliente(lista_de_reservas, number_cliente);
                }
                test = elimina_cliente_numero_cliente(lista_de_clientes, number_cliente);
                if (test) {
                    lista_de_clientes->cliente.n_cliente--;

                    // SAVE DATA
                    escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de contadores nao escrito.\n");
                        return -1;
                    } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

                    escritos = escreve_clientes("clientes", &lista_de_clientes, lista_de_clientes->cliente.n_cliente);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de clientes nao escrito.\n");
                        return -1;
                    } else if (escritos == 0)printf("\n   Ficheiro de clientes escrito com erro nos valores\n   ou clientes nao existentes.\n");
                    else printf("\n   Ficheiro de clientes escrito com sucesso.\n");

                    escritos = escreve_voos("voos", &lista_de_voos, lista_de_voos->voo.n_voo);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de voos nao escrito.\n");
                        return -1;
                    } else if (escritos == 0)printf("\n   Ficheiro de voos escrito com erro nos valores\n   ou voos nao existentes.\n");
                    else printf("\n   Ficheiro de voos escrito com sucesso.\n");

                    escritos = escreve_reservas("reservas", &lista_de_reservas, lista_de_reservas->reserva.n_cliente);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de reservas nao escrito.\n");
                        return -1;
                    } else if (escritos == 0)printf("\n   Ficheiro de reservas escrito com erro nos valores\n   ou reservas nao existentes.\n");
                    else printf("\n   Ficheiro de reservas escrito com sucesso.\n");
                }
                test = 0;

            } else if (opcao == 3) {
                imprime_lista_clientes(lista_de_clientes);
                printf("\n   ");
                //system("pause");
            }
        } else if (opcao == 2) {
            do {
                opcao = 8;
                //fflush(stdin);
                //system("cls");
                printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Criar/eliminar/verificar voos\n\n");
                printf("   1 - Criar Voo;\n   2 - Eliminar Voo;\n   3 - Visualizar voos;\n   4 - Voltar ao menu anterior;\n   7 - Sair;\n\n   Opcao: ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &opcao);
            } while (opcao < 1 || opcao > 7 || opcao == 5 || opcao == 6);

            if (opcao == 1) {
                do {
                    //fflush(stdin);
                    printf("\n   Dia do voo: ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &dia_voo);
                    //scanf("%d", &dia_voo);
                } while (dia_voo < 1 || dia_voo > 31);
                do {
                    //fflush(stdin);
                    printf("\n   Mes do voo: ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &mes_voo);
                    //scanf("%d", &mes_voo);
                } while (mes_voo < 1 || mes_voo > 12);
                do {
                    //fflush(stdin);
                    printf("\n   Ano do voo( 2000-2100): ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &ano_voo);
                    //scanf("%d", &ano_voo);
                } while (ano_voo < 2000 || ano_voo > 2100);
                printf("\n   Tempo de partida do voo\n");
                do {
                    //fflush(stdin);
                    printf("\n      Hora( 0-23): ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &hora_voo);
                    //scanf("%d", &hora_voo);
                } while (hora_voo < 0 || hora_voo > 23);
                do {
                    //fflush(stdin);
                    printf("\n      Minutos( 0-59): ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &minutos_voo);
                    //scanf("%d", &minutos_voo);
                } while (minutos_voo < 0 || minutos_voo > 59);

                do {
                    //fflush(stdin);
                    printf("\n\n   Origem e destino do voo\n\n      1 - Origem: Lisboa - Destino: Cernache\n      2 - Origem: Cernache - Destino: Lisboa\n\n   Opcao: ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &viagem);
                    //scanf("%d", &viagem);
                } while (viagem < 1 || viagem > 2);
                if (viagem == 1) {
                    strcpy(origem, cidadeL);
                    strcpy(destino, cidadeC);
                } else {
                    strcpy(origem, cidadeC);
                    strcpy(destino, cidadeL);
                }
                insere_lista_voo(lista_de_voos, n_voo, dia_voo, mes_voo, ano_voo, hora_voo, minutos_voo, origem, destino);
                lista_de_voos->voo.n_voo++;
                n_voo++;

                escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
                if (escritos == -1) {
                    printf("\n   Ficheiro de contadores nao escrito.\n");
                    return -1;
                } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

                escritos = escreve_voos("voos", &lista_de_voos, lista_de_voos->voo.n_voo);
                if (escritos == -1) {
                    printf("\n   Ficheiro de voos nao escrito.\n");
                    return -1;
                } else if (escritos == 0)printf("\n   Ficheiro de voos escrito com erro nos valores\n   ou voos nao existentes.\n");
                else printf("\n   Ficheiro de voos escrito com sucesso.\n");

            } else if (opcao == 2) {
                //fflush(stdin);
                printf("\n   Numero do voo( Para voltar ao menu anterior inserir -1): ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &number_voo);
                //scanf("%d", &number_voo);
                do {
                    printf("\n   O voo foi efectuado?(  1 - Sim; 2 - Nao ): ");
                    fgets(string_test, sizeof (string_test), stdin);
                    //scanf("%d", &opcao);
                    sscanf(string_test, "%d", &voo_efectuado);
                    //scanf("%d", &voo_efectuado);
                } while (voo_efectuado < 1 || voo_efectuado > 2);
                List_r reserva_actual = pesquisa_reserva_numero_voo(lista_de_reservas, number_voo);
                List_c cliente_actual;
                if (reserva_actual)cliente_actual = pesquisa_cliente_numero_cliente(lista_de_clientes, reserva_actual->reserva.n_cliente);
                while (reserva_actual) {
                    elimina_reserva_numero_voo(lista_de_reservas, number_voo);
                    if (voo_efectuado == 2)cliente_actual->cliente.n_voos_efectuados--;
                    lista_de_reservas->reserva.n_cliente--;
                    reserva_actual = pesquisa_reserva_numero_voo(lista_de_reservas, number_voo);
                    if (reserva_actual)cliente_actual = pesquisa_cliente_numero_cliente(lista_de_clientes, reserva_actual->reserva.n_cliente);
                }
                test = elimina_voo_numero_voo(lista_de_voos, number_voo);
                if (test) {
                    lista_de_voos->voo.n_voo--;

                    // SAVE DATA
                    escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de contadores nao escrito.\n");
                        return -1;
                    } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

                    escritos = escreve_clientes("clientes", &lista_de_clientes, lista_de_clientes->cliente.n_cliente);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de clientes nao escrito.\n");
                        return -1;
                    } else if (escritos == 0)printf("\n   Ficheiro de clientes escrito com erro nos valores\n   ou clientes nao existentes.\n");
                    else printf("\n   Ficheiro de clientes escrito com sucesso.\n");

                    escritos = escreve_voos("voos", &lista_de_voos, lista_de_voos->voo.n_voo);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de voos nao escrito.\n");
                        return -1;
                    } else if (escritos == 0)printf("\n   Ficheiro de voos escrito com erro nos valores\n   ou voos nao existentes.\n");
                    else printf("\n   Ficheiro de voos escrito com sucesso.\n");

                    escritos = escreve_reservas("reservas", &lista_de_reservas, lista_de_reservas->reserva.n_cliente);
                    if (escritos == -1) {
                        printf("\n   Ficheiro de reservas nao escrito.\n");
                        return -1;
                    } else if (escritos == 0)printf("\n   Ficheiro de reservas escrito com erro nos valores\n   ou reservas nao existentes.\n");
                    else printf("\n   Ficheiro de reservas escrito com sucesso.\n");
                }
                test = 0;

            } else if (opcao == 3) {
                imprime_lista_voos(lista_de_voos);
                printf("\n   ");
                //system("pause");
            }
        } else if (opcao == 3) {
            do {
                opcao = 8;
                //fflush(stdin);
                //system("cls");
                printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Criar/eliminar/verificar reservas\n\n");
                printf("   1 - Criar Reserva;\n   2 - Eliminar Reserva;\n   3 - Visualizar reservas;\n   4 - Voltar ao menu anterior;\n   7 - Sair;\n\n   Opcao: ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &opcao);
                //scanf("%d", &opcao);
            } while (opcao < 1 || opcao > 7 || opcao == 5 || opcao == 6);

            if (opcao == 1) {
                //fflush(stdin);
                printf("\n   Numero de voo( Para voltar ao menu anterior inserir -1): ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &number_voo);
                //scanf("%d", &number_voo);
                List_v voo_actual = pesquisa_voo_numero_voo(lista_de_voos, number_voo);
                if (voo_actual != NULL) {
                    if (voo_actual->voo.n_lugares_vagos != 0) {
                        //fflush(stdin);
                        printf("\n   Numero de cliente( Para voltar ao menu anterior inserir -1): ");
                        fgets(string_test, sizeof (string_test), stdin);
                        //scanf("%d", &opcao);
                        sscanf(string_test, "%d", &number_cliente);
                        //scanf("%d", &number_cliente);
                        if (pesquisa_cliente_numero_cliente(lista_de_clientes, number_cliente)) {
                            if (verifica_reserva_repetida(lista_de_reservas, number_cliente, number_voo) == 0) {
                                do {
                                    //fflush(stdin);
                                    printf("\n   Dia da reserva: ");
                                    fgets(string_test, sizeof (string_test), stdin);
                                    //scanf("%d", &opcao);
                                    sscanf(string_test, "%d", &dia_reserva);
                                    //scanf("%d", &dia_reserva);
                                } while (dia_reserva < 1 || dia_reserva > 31);
                                do {
                                    //fflush(stdin);
                                    printf("\n   Mes da reserva: ");
                                    fgets(string_test, sizeof (string_test), stdin);
                                    //scanf("%d", &opcao);
                                    sscanf(string_test, "%d", &mes_reserva);
                                    //scanf("%d", &mes_reserva);
                                } while (mes_reserva < 1 || mes_reserva > 12);
                                do {
                                    //fflush(stdin);
                                    printf("\n   Ano da reserva( 2000-2100): ");
                                    fgets(string_test, sizeof (string_test), stdin);
                                    //scanf("%d", &opcao);
                                    sscanf(string_test, "%d", &ano_reserva);
                                    //scanf("%d", &ano_reserva);
                                } while (ano_reserva < 2000 || ano_reserva > 2100);
                                printf("\n   Tempo de marcacao da reserva\n");
                                do {
                                    //fflush(stdin);
                                    printf("\n      Hora( 0-23): ");
                                    fgets(string_test, sizeof (string_test), stdin);
                                    //scanf("%d", &opcao);
                                    sscanf(string_test, "%d", &hora_reserva);
                                    //scanf("%d", &hora_reserva);
                                } while (hora_reserva < 0 || hora_reserva > 23);
                                do {
                                    //fflush(stdin);
                                    printf("\n      Minutos( 0-59): ");
                                    fgets(string_test, sizeof (string_test), stdin);
                                    //scanf("%d", &opcao);
                                    sscanf(string_test, "%d", &minutos_reserva);
                                    //scanf("%d", &minutos_reserva);
                                } while (minutos_reserva < 0 || minutos_reserva > 59);
                                if (data_test(&voo_actual, dia_reserva, mes_reserva, ano_reserva) == 0) {
                                    int i;
                                    for (i = 0; i < 50; i++) {
                                        if (voo_actual->voo.lugares_vagos[i] == 1) {
                                            voo_actual->voo.n_lugares_vagos--;
                                            voo_actual->voo.lugares_vagos[i] = 0;
                                            lugar_voo = i + 1;
                                            break;
                                        }
                                    }
                                    insere_lista_reserva(lista_de_reservas, n_reserva, number_cliente, number_voo, dia_reserva, mes_reserva, ano_reserva, hora_reserva, minutos_reserva, lugar_voo);
                                    lista_de_reservas->reserva.n_cliente++;
                                    n_reserva++;
                                    List_c cliente_actual = pesquisa_cliente_numero_cliente(lista_de_clientes, number_cliente);
                                    cliente_actual->cliente.n_voos_efectuados++;

                                    // SAVE DATA
                                    escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
                                    if (escritos == -1) {
                                        printf("\n   Ficheiro de contadores nao escrito.\n");
                                        return -1;
                                    } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

                                    escritos = escreve_clientes("clientes", &lista_de_clientes, lista_de_clientes->cliente.n_cliente);
                                    if (escritos == -1) {
                                        printf("\n   Ficheiro de clientes nao escrito.\n");
                                        return -1;
                                    } else if (escritos == 0)printf("\n   Ficheiro de clientes escrito com erro nos valores\n   ou clientes nao existentes.\n");
                                    else printf("\n   Ficheiro de clientes escrito com sucesso.\n");

                                    escritos = escreve_voos("voos", &lista_de_voos, lista_de_voos->voo.n_voo);
                                    if (escritos == -1) {
                                        printf("\n   Ficheiro de voos nao escrito.\n");
                                        return -1;
                                    } else if (escritos == 0)printf("\n   Ficheiro de voos escrito com erro nos valores\n   ou voos nao existentes.\n");
                                    else printf("\n   Ficheiro de voos escrito com sucesso.\n");

                                    escritos = escreve_reservas("reservas", &lista_de_reservas, lista_de_reservas->reserva.n_cliente);
                                    if (escritos == -1) {
                                        printf("\n   Ficheiro de reservas nao escrito.\n");
                                        return -1;
                                    } else if (escritos == 0)printf("\n   Ficheiro de reservas escrito com erro nos valores\n   ou reservas nao existentes.\n");
                                    else printf("\n   Ficheiro de reservas escrito com sucesso.\n");
                                    //

                                } else {
                                    printf("\n\n   Reserva nao efectuada. Data introduzida ultrapassa a data de partida do voo.\n\n   "); //system("pause");
                                }
                            } else {
                                printf("\n\n   Cliente referido ja possui reserva no voo indicado.\n\n   "); //system("pause");
                            }
                        } else {
                            printf("\n   Reserva nao efectuada. Cliente indicado inexistente.\n   "); //system("pause");
                        }
                    } else {
                        printf("\n   Reserva nao efectuada. Voo indicado sem lugares vagos.\n   "); //system("pause");
                    }
                } else {
                    printf("\n   Reserva nao efectuada. Voo indicado inexistente.\n   "); //system("pause");
                }

            } else if (opcao == 2) {
                //fflush(stdin);
                printf("\n   Numero de reserva( Para voltar ao menu anterior inserir -1): ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &number_reserva);
                //scanf("%d", &number_reserva);
                List_r reserva_actual = pesquisa_reserva_numero_reserva(lista_de_reservas, number_reserva);
                List_c cliente_actual;
                if (reserva_actual)cliente_actual = pesquisa_cliente_numero_cliente(lista_de_clientes, reserva_actual->reserva.n_cliente);
                if (reserva_actual) {
                    cliente_actual->cliente.n_voos_efectuados--;
                    List_v voo_actual = pesquisa_voo_numero_voo(lista_de_voos, reserva_actual->reserva.n_voo);
                    voo_actual->voo.n_lugares_vagos++;
                    voo_actual->voo.lugares_vagos[ reserva_actual->reserva.n_lugar - 1] = 1;
                }
                test = elimina_reserva_numero_reserva(lista_de_reservas, number_reserva);
                if (test)lista_de_reservas->reserva.n_cliente--;
                test = 0;

                // SAVE DATA
                escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
                if (escritos == -1) {
                    printf("\n   Ficheiro de contadores nao escrito.\n");
                    return -1;
                } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

                escritos = escreve_clientes("clientes", &lista_de_clientes, lista_de_clientes->cliente.n_cliente);
                if (escritos == -1) {
                    printf("\n   Ficheiro de clientes nao escrito.\n");
                    return -1;
                } else if (escritos == 0)printf("\n   Ficheiro de clientes escrito com erro nos valores\n   ou clientes nao existentes.\n");
                else printf("\n   Ficheiro de clientes escrito com sucesso.\n");

                escritos = escreve_voos("voos", &lista_de_voos, lista_de_voos->voo.n_voo);
                if (escritos == -1) {
                    printf("\n   Ficheiro de voos nao escrito.\n");
                    return -1;
                } else if (escritos == 0)printf("\n   Ficheiro de voos escrito com erro nos valores\n   ou voos nao existentes.\n");
                else printf("\n   Ficheiro de voos escrito com sucesso.\n");

                escritos = escreve_reservas("reservas", &lista_de_reservas, lista_de_reservas->reserva.n_cliente);
                if (escritos == -1) {
                    printf("\n   Ficheiro de reservas nao escrito.\n");
                    return -1;
                } else if (escritos == 0)printf("\n   Ficheiro de reservas escrito com erro nos valores\n   ou reservas nao existentes.\n");
                else printf("\n   Ficheiro de reservas escrito com sucesso.\n");
                //

            } else if (opcao == 3) {
                imprime_lista_reservas(lista_de_reservas);
                printf("\n   ");
                //system("pause");
            }

        } else if (opcao == 4) {
            do {
                opcao = 8;
                //fflush(stdin);
                //system("cls");
                printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Lista ordenada dos passageiros por nome\n\n");
                printf("   1 - Visualizar lista ordenada de todos os passageiros;\n   2 - Visualizar lista ordenada de passageiros por voo;\n\
   3 - Voltar ao menu anterior;\n   7 - Sair;\n\n   Opcao: ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &opcao);
            } while (opcao < 1 || opcao > 7 || opcao == 4 || opcao == 5 || opcao == 6);

            if (opcao == 1) {
                //system("cls");
                printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Lista ordenada de todos os passageiros por nome\n\n");
                imprime_nome(lista_de_clientes);
                printf("\n\n   ");
                //system("pause");
            } else if (opcao == 2) {
                //system("cls");
                printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Lista ordenada dos passageiros por nome num voo\n\n");
                //fflush(stdin);
                printf("\n   Numero do voo( Para voltar ao menu anterior inserir -1): ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &number_voo);
                //scanf("%d", &number_voo);
                List_v voo_actual = pesquisa_voo_numero_voo(lista_de_voos, number_voo);
                if (voo_actual) {
                    imprime_nome_voo(lista_de_reservas, lista_de_clientes, voo_actual);
                } else
                    printf("\n   Listagem nao efectuada. Voo indicado inexistente.\n   ");
                printf("\n\n   ");
                //system("pause");
            }
        } else if (opcao == 5) {
            opcao = 8;
            //fflush(stdin);
            //system("cls");
            printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas\n\n   Lista ordenada dos passageiros por n. de voos efectuados\n");
            imprime_n_voos_efectuados(lista_de_clientes);
            printf("\n   ");
            //system("pause");
        } else if (opcao == 6) {
            opcao = 8;
            //fflush(stdin);
            //system("cls");
            printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Verificar se um passageiro tem reserva num voo\n\n");
            //fflush(stdin);
            printf("\n   Numero de cliente( Para voltar ao menu anterior inserir -1): ");
            fgets(string_test, sizeof (string_test), stdin);
            //scanf("%d", &opcao);
            sscanf(string_test, "%d", &number_cliente);
            //scanf("%d", &number_cliente);
            if (pesquisa_cliente_numero_cliente(lista_de_clientes, number_cliente)) {
                printf("\n   Numero de voo( Para voltar ao menu anterior inserir -1): ");
                fgets(string_test, sizeof (string_test), stdin);
                //scanf("%d", &opcao);
                sscanf(string_test, "%d", &number_voo);
                //scanf("%d", &number_voo);
                if (pesquisa_voo_numero_voo(lista_de_voos, number_voo)) {
                    verifica_reserva_cliente(lista_de_reservas, number_cliente, number_voo);
                } else {
                    printf("\n   Verificacao nao efectuada. Voo indicado inexistente.\n   "); //system("pause");
                }
            } else {
                printf("\n   Verificacao nao efectuada. Cliente indicado inexistente.\n   "); //system("pause");
            }
        }
    } while (opcao != 7);

    //system("cls");
    printf("\n   ******** GCC-Airlines ********\n\n   Gestao de Reservas - Encerramento do programa\n\n");

    escritos = escreve_contadores(n_cliente, n_voo, n_reserva);
    if (escritos == -1) {
        printf("\n   Ficheiro de contadores nao escrito.\n");
        return -1;
    } else if (escritos == 1)printf("\n   Ficheiro de contadores escrito com sucesso.\n");

    escritos = escreve_clientes("clientes", &lista_de_clientes, lista_de_clientes->cliente.n_cliente);
    if (escritos == -1) {
        printf("\n   Ficheiro de clientes nao escrito.\n");
        return -1;
    } else if (escritos == 0)printf("\n   Ficheiro de clientes escrito com erro nos valores\n   ou clientes nao existentes.\n");
    else printf("\n   Ficheiro de clientes escrito com sucesso.\n");

    escritos = escreve_voos("voos", &lista_de_voos, lista_de_voos->voo.n_voo);
    if (escritos == -1) {
        printf("\n   Ficheiro de voos nao escrito.\n");
        return -1;
    } else if (escritos == 0)printf("\n   Ficheiro de voos escrito com erro nos valores\n   ou voos nao existentes.\n");
    else printf("\n   Ficheiro de voos escrito com sucesso.\n");

    escritos = escreve_reservas("reservas", &lista_de_reservas, lista_de_reservas->reserva.n_cliente);
    if (escritos == -1) {
        printf("\n   Ficheiro de reservas nao escrito.\n");
        return -1;
    } else if (escritos == 0)printf("\n   Ficheiro de reservas escrito com erro nos valores\n   ou reservas nao existentes.\n");
    else printf("\n   Ficheiro de reservas escrito com sucesso.\n");

    destroi_lista_c(lista_de_clientes);
    destroi_lista_v(lista_de_voos);
    destroi_lista_r(lista_de_reservas);

    printf("\n\n   Programa considerado encerrado com sucesso.\n\n");

    return 0;
}


