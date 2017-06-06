/*
 * prueba_hash.c
 * Pruebas para el tipo de dato abstracto Tabla de Hash
 * Copyright: (2011) Margarita Manterola, Maximiliano Curia
 * Licencia: CC-BY-SA 2.5 (ar) ó CC-BY-SA 3.0
 */

#include "heap.h"
#include "testing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For ssize_t in Linux.


/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

int cmp(const void* a,const void* b){
	if(*(int*)a>*(int*)b) return 1;
	if(*(int*)a<*(int*)b) return -1;
	return 0;
}

static void prueba_crear_heap_vacio()
{
	int a = 1;
	
    heap_t* heap = heap_crear(cmp);

    print_test("Prueba heap crear heap vacio", heap);
    print_test("Prueba heap la cantidad de elementos es 0", heap_cantidad(heap) == 0);
	print_test("Prueba heap esta vacio", heap_esta_vacio(heap));
	print_test("Prueba heap_ver_max es NULL", !heap_ver_max(heap));
	print_test("Prueba heap desencolar es NULL", !heap_desencolar(heap));
	print_test("Prueba heap encolar un elemento", heap_encolar(heap, &a));
	print_test("Prueba heap_ver_max es 1", (heap_ver_max(heap) == &a));
	print_test("Prueba heap esta vacio es false", !heap_esta_vacio(heap));
	print_test("Prueba heap desencolar es 1", (heap_desencolar(heap) == &a));


    heap_destruir(heap, NULL);
}

static void prueba_heap_pocos_elementos(){
	int a = 1;
	int b = 2;
	int c = 3;
	//int d = 4;
	//int e = 5;

	heap_t* heap = heap_crear(cmp);
	print_test("Prueba heap encolar un elemento", heap_encolar(heap, &a));
	print_test("Prueba heap encolar un elemento", heap_encolar(heap, &c));
	print_test("Prueba heap_ver_max es 3", (heap_ver_max(heap) == &c));
	print_test("Prueba heap encolar un elemento", heap_encolar(heap, &b));
	print_test("Prueba heap_ver_max es 3", (heap_ver_max(heap) == &c));
	print_test("Prueba heap desencolar es 3", (heap_desencolar(heap) == &c));
	print_test("Prueba heap_ver_max es 2", (heap_ver_max(heap) == &b));
	print_test("Prueba heap la cantidad de elementos es 2", heap_cantidad(heap) == 2);
	print_test("Prueba heap esta vacio es false", !heap_esta_vacio(heap));


	heap_destruir(heap, NULL);
}



void pruebas_heap_alumno()
{
    /* Ejecuta todas las pruebas unitarias. */
    prueba_crear_heap_vacio();
    prueba_heap_pocos_elementos();
}