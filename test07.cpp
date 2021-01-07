#include<iostream>
#include <assert.h>
#include "SimpleList.h"



int main(){
    SimpleList *lst=SimpleList_new();
    SimpleList_push_front(lst,5);
    SimpleList_push_front(lst,6);
    SimpleList_push_front(lst,7); 
    SimpleList_pop_back(lst);
    SimpleList_pop_back(lst);
    SimpleList_pop_back(lst);
    
 try { 
        int i = SimpleList_pop_back(lst);
    
    }
    catch(std::string err)
    { 
        std:: cout << "Errore gestito correttamente" << std::endl;
        
    }    
    SimpleList_print_plus_lenght (lst);
    
    SimpleList_delete(lst);
    
}
