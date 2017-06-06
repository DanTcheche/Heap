#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"
#define CARGA_MAX 0.7
#define	CARGA_MIN 0.25
#define FACT_REDIM 2
#define TAM_INI 30


typedef struct heap{
	void* elementos[];
	size_t cantidad;
	cmp_func_t cmp;
}heap_t;

void swap(void* x, void* y){
	void* aux = *x;
	*x = *y;
	*y = aux;
}

float factor_de_carga(heap_t* heap){
	return (float)(heap->cantidad)/(float)(heap->tam);
}

bool heap_redimensionar(heap, tam_nuevo){
	void* elementos_nuevo[] = realloc(heap->elementos, sizeof(void*)*tam_nuevo);
	if(!elementos_nuevo) return false;
	heap->elementos = elementos_nuevo;
	heap->tam = tam_nuevo;
	return true;
}

heap_t* heap_crear(cmp_func_t cmp){
	heap_t heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;
	heap->elementos = malloc(sizeof(void*)*TAM_INI);
	if(!heap->elementos) return NULL;
	heap->cmp = cmp;
	heap->cantidad = 0;
	heap->tam = TAM_INI;
}

void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
	for(int i = (cant-1); i>1, i--){
		swap(elementos[0], elementos[i]);
		downheap(elementos[0], cmp);
	}
}

heap_t* heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
	heapify(arreglo, n, cmp);
	heap_crear(cmp);
	heap->elementos = arreglo;
	heap->cantidad = n;
	heap->cmp = cmp;
	heap->tam = n;
	return heap;
}

void heap_destruir(heap_t *heap, void destruir_elemento(void *e)){

}

size_t heap_cantidad(const heap_t *heap){
	return heap->cantidad;
}

bool heap_esta_vacio(const heap_t *heap){
	return (heap->cantidad == 0);
}

bool heap_encolar(heap_t *heap, void* elem){
	if(*elem == NULL) return false;
	heap->elementos[cantidad] = elem;
	if (factor_de_carga(heap)>CARGA_MAX){
		if(!heap_redimensionar(heap, tam*FACT_REDIM)) return false;
	} 
	return true;