#ifndef _NODO_H_
#define _NODO_H_
#include <string.h>
struct nodo {
	/* Valor del Nodo */
	char val;
	/* Puntero que "apunta" al siguiente nodo */
	struct	nodo * sig;
};

#endif
