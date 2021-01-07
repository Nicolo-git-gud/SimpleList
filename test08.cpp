#include<iostream>
#include <assert.h>
#include "SimpleList.h"

int main(){
    SimpleList *lst=SimpleList_new();
    SimpleList_push_front(lst,5);
    SimpleList_push_front(lst,6);
    SimpleList_push_front(lst,7); 
    int primo = SimpleList_pop_back(lst); //Eseguo la pop dopo tre push front quindi mi restituisce lo stesso ordine che avrei avuto con tre pushback;
    int secondo =  SimpleList_pop_back(lst);
    int terzo = SimpleList_pop_back(lst);
    std::cout<< primo <<std::endl;
    std::cout<< secondo <<std::endl;
    std::cout<< terzo <<std::endl;
    
    
    SimpleList_print_plus_lenght (lst);
    
    SimpleList_delete(lst);
    
}
