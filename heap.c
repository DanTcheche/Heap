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
	size_t tam;
	cmp_func_t cmp;
}heap_t;

void swap(void** x, void** y){
	void** aux = x;
	x = y;
	y = aux;
}

void upheap(void* elementos[], size_t posicion, cmp_func_t cmp){
	if(posicion == 0) return;
	padre = (posicion-1)/2;
	if(cmp(elementos[padre], elementos[posicion]) < 0){
		swap(&elementos[padre], &elementos[posicion]);
		upheap(elementos, padre, cmp);
	}
}

void downheap(void* elementos[], size_t tam, size_t posicion, cmp_func_t cmp){
	if(posicion>tam) return;
	size_t max = pos;
	size_t hijo_izq = posicion*2+1;
	size_t hijo_der = posicion*2+2;
	if(hijo_izq < n && cmp(elementos[hijo_izq], elementos[max]) > 0) max = hijo_izq;
	if(hijo_der < n && cmp(elementos[hijo_der], elementos[max]) > 0) max = hijo_der;
	if(max != pos){
		swap(&arreglo[max], &arreglo[pos]);
		downheap(elementos, tam, max, cmp)
	}
}

void heapify(void* elementos[], size_t cant, cmp_func_t cmp){
	for(int i = (cant-1); i >= 0; i--){
		downheap(elementos, cant, elementos[i], cmp);
	}
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
		swap(&elementos[0], &elementos[i]); 
		downheap(elementos, cant, elementos[0], cmp);
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