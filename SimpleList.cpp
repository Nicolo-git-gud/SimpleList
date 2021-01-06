#include "SimpleList.h"
#include <iostream>
#include <string>

SimpleList *SimpleList_new() {
    SimpleList *l = new SimpleList;
    l->head = nullptr;
    l->lenght = 0;
    return l;
}

int SimpleList_length(SimpleList *l){
    int contatore=0;
    Cell *aux = l->head;
    while (aux!=nullptr){
        aux=aux->next;
        contatore ++;
    }
    return contatore;
}
int SimpleList_length_new(SimpleList *l){

    return l -> lenght;
}


void SimpleList_delete(SimpleList *l){
    while(l->head!=nullptr){
        Cell *temp=l->head;
        l->head=l->head->next;
        delete temp;
    }
    delete l;
}
void SimpleList_print( SimpleList *l){
    Cell *current =l->head;
    while(current!=nullptr ){
        std::cout<<current->value<<std::endl;
        current=current->next;
    }
}
void SimpleList_print_plus_lenght( SimpleList *l){
    int lu = SimpleList_length_new(l);
    std::cout <<  "La lista è composta da :" << " " << lu << " Elementi " << std::endl;
    Cell *current =l->head;
    while(current!=nullptr ){
        std::cout<<current->value<<std::endl;
        current=current->next;
    }
}
void reverse_print_cell(Cell *c){
  if (c -> next == nullptr)
      return;

    c = c -> next;
      reverse_print_cell(c);
std::cout << c-> value << std::endl;

}  

void rec_print_cell(Cell *c){
  if (c -> next == nullptr)
      return;

    c = c -> next;
    std::cout << c-> value << std::endl;
  rec_print_cell(c);


}  
void SimpleList_reverse_print(SimpleList *l){
Cell *c = l-> head;
    if(l -> head == nullptr)
    return;

reverse_print_cell(c);
std::cout << c -> value << std::endl;
}
void SimpleList_recoursive_print(SimpleList *l){
Cell *c = l-> head;
    if(l -> head == nullptr)
    return;
std::cout << c -> value << std::endl;
rec_print_cell(c);

}
void SimpleList_push_back(SimpleList *l, int value){
    
    Cell *aux=new Cell;
    aux->value=value;
    if(l->head==nullptr){
        aux->next=l->head;
        l->head=aux;
        l -> lenght = 1;
        return;
    }
    Cell *cur=l->head;
    Cell *prev=nullptr;
    while(cur!=nullptr){
        prev=cur;
        cur=cur->next;
    }
    l->lenght++;
    aux->next=cur;
    prev->next=aux;
    
}
SimpleList *SimpleList_copy (SimpleList *l){
    if (l->head==nullptr){
        SimpleList *b=SimpleList_new();
        return b;
    }
    SimpleList *b=SimpleList_new();
    Cell *copia=l->head;
    Cell *current=new Cell;
    current->value=l->head->value;
    current->next=nullptr;
    b->head=current;
    copia = copia->next;
    while(copia!=nullptr){
        
        Cell *Aux = new Cell;
        Aux->value=copia->value;
        Aux->next=nullptr;
        current->next=Aux;
        current=Aux;
        copia = copia->next;
    }
    b->lenght = l->lenght;
    return b;
}

SimpleList *SimpleListMerge(SimpleList *A, SimpleList *B){
    if(A->head == nullptr && B->head == nullptr){
        return SimpleList_new();
    }
    SimpleList *Mergiato= SimpleList_copy(A);
    SimpleList *copiB = SimpleList_copy(B);
    Cell*current = Mergiato->head;
    while(current->next!=nullptr)
        current = current->next;
    current->next = copiB->head;
    delete copiB;
    Mergiato -> lenght =(A -> lenght + B -> lenght);
    return Mergiato;
}


SimpleList *SimpleListMerge2(SimpleList *A, SimpleList *B){
    SimpleList *Mergiato= SimpleList_new();
    if(A->head==nullptr && B->head==nullptr)
        return Mergiato;
    if(A->head==nullptr)
    {
        Cell *merge=B->head;
        Cell *current=new Cell;
        current->value=merge->value;
        current->next=nullptr;
        merge=merge->next;
        Mergiato->head=current;
        while(merge!=nullptr){
            Cell *aux=new Cell;
            aux->value=merge->value;
            aux->next=nullptr;
            merge=merge->next;
            current->next=aux;
            current=aux;
        }
        Mergiato -> lenght = B -> lenght;
        return Mergiato;
        
    }
    else{
        Cell *merge=A->head;
        Cell *current=new Cell;
        current->value=merge->value;
        current->next=nullptr;
        merge=merge->next;
        Mergiato->head=current;
        while(merge!=nullptr){
            Cell *aux=new Cell;
            aux->value=merge->value;
            aux->next=nullptr;
            merge=merge->next;
            current->next=aux;
            current=aux;
        }
        if(B->head==nullptr)
            Mergiato -> lenght = A -> lenght; 
        return Mergiato;
        merge=B->head;
        while(current->next!=nullptr)
            current=current->next;
        current->next=B->head;
        while(merge!=nullptr){
            Cell *aux=new Cell;
            aux->value=merge->value;
            aux->next=nullptr;
            merge=merge->next;
            current->next=aux;
            current=aux;
        }
    } 
    Mergiato -> lenght = A -> lenght + B -> lenght;
    return Mergiato;
}


SimpleList * SimpleList_from_array(int a[], int c){
    SimpleList *l= SimpleList_new();
    if (c==0)
        return l;
    Cell *Cur = new Cell;
    Cur -> value = a[0];
    Cur -> next=nullptr;
    l -> head = Cur;
    for (int i=1; i < c; i++){
        Cell *aux  =  new Cell;
        aux -> value = a[i];
        aux -> next = nullptr;
        Cur -> next = aux;
        Cur = aux;
    }
    l -> lenght = c;
    return l;
}
int * array_from_list(SimpleList *l){
   if(l->head==nullptr){
       int *b=new int[0];
       return b;
   }
    int n = l-> lenght;
    int *b = new int[n];
    Cell *cur = l-> head;
    for(int i=0;i<n;i++){
        b[i] = cur-> value;
        cur = cur->next;
    }
    return b;
}

void SimpleList_push_front(SimpleList *l,int v){
    Cell *aux = new Cell;
    aux->value = v;
    aux->next = l->head;
    l->head = aux;
    l->lenght ++;
}
int SimpleList_pop_back(SimpleList *l){
    if(l->head==nullptr){
        std::string err = "lista vuota";
        throw err;
    }
    Cell *prev = l->head;
    Cell *cur = l->head;
    while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
    }
    int value = cur -> value;
    prev -> next = nullptr;
    delete cur;
    return value;
}
