#include<iostream>
#include <assert.h>
#include "SimpleList.h"

int main(){
    SimpleList *lst=SimpleList_new();
    SimpleList_push_front(lst,5);
    SimpleList_push_front(lst,6);
    SimpleList_push_front(lst,7); 
    int primo = SimpleList_pop_front(lst); 
    int secondo =  SimpleList_pop_front(lst);
    int terzo = SimpleList_pop_front(lst);
    std::cout<< primo <<std::endl;
    std::cout<< secondo <<std::endl;
    std::cout<< terzo <<std::endl;
    
    
    SimpleList_print_plus_lenght (lst);
    
    std::cout << "Tre push e tre pop gestiti correttamente " << std::endl;
    
    
     try { 
        int i = SimpleList_pop_front(lst);
    
    }
    catch(std::string err)
    { 
        std:: cout << "Errore gestito correttamente" << std::endl;
        
    }  
    
    SimpleList_delete(lst);
    
    
}
