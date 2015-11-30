#ifndef _PILA_H_
#define _PILA_H_

#include "nodo.h"

void push(struct nodo *cabecera, char valor_nuevo);

struct nodo * inicializar();

void pop(struct nodo *cabecera);

char tope(struct nodo *cabecera);

#endif
