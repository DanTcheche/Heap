#define TAM_INI = 30;

typedef struct heap{
	void* elementos[];
	size_t cant;
	cmp_func_t cmp;
}heap_t;

heap_t *heap_crear(cmp_func_t cmp){
	heap_t heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;
	heap->elementos = malloc(sizeof(void*)*TAM_INI);
	if(!heap->elementos) return NULL;
	heap->cmp = cmp;
	heap->cant = 0;
}

void swap(void* x, void* y){
	void* aux = *x;
	*x = *y;
	*y = aux;
}

void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
	for(int i = (cant-1); i>1, i--){
		swap(elementos[0], elementos[i]);
		downheap(elementos[0])
	}
}

