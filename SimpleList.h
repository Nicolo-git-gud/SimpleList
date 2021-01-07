struct Cell {
    int value;
    Cell *next;
};

struct SimpleList {
    Cell *head;
    int lenght;
};


// function declarations

// test01
SimpleList *SimpleList_new();
int SimpleList_length(SimpleList *l);
void SimpleList_delete(SimpleList *l);

// test02
void SimpleList_push_back(SimpleList *l, int value);
void SimpleList_print(SimpleList *l);
SimpleList *SimpleList_copy( SimpleList *l);
SimpleList *SimpleListMerge(SimpleList *A, SimpleList *B);
SimpleList *SimpleListMerge2(SimpleList *A, SimpleList *B);
void SimpleList_reverse_print(SimpleList *l);
void reverse_print_cell(Cell *c);
void SimpleList_recoursive_print(SimpleList *l);
void SimpleList_recoursive_print(SimpleList *l);
int SimpleList_length_new(SimpleList *l);
void SimpleList_print_plus_lenght(SimpleList *l);
SimpleList * SimpleList_from_array(int a[], int l);
int * array_from_list(SimpleList *l);
void SimpleList_push_front(SimpleList *l,int v);
int SimpleList_pop_back(SimpleList *l);
int SimpleList_pop_front(SimpleList *l);bv 
