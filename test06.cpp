#include<iostream>
#include <assert.h>
#include "SimpleList.h"



int main(){
    SimpleList *lst=SimpleList_new();
    // SimpleList_push_front(lst,5);
    //  SimpleList_push_front(lst,6);
    //SimpleList_push_front(lst,7);
    try { 
        int i = SimpleList_pop_back(lst);
        std::cout << "Il valore eliminato è " << i << std::endl;
    }
    catch(std::string err)
    { 
        std:: cout << "Errore, lista vuota" << std::endl;
        
    }
    
    SimpleList_print_plus_lenght (lst);
    
    SimpleList_delete(lst);
    
}
