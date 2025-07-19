/*
 * test.cpp
 *
 *  Created on: May 18, 2025
 *      Author: AhmedMontasser
 */


#include <iostream>

/* Module Description:-
 * ---------------------
 * 	1.
 *
 */


void Print(int && r){
    std::cout << "rvalue\n" ;
}
void Print(int & r){
    std::cout << "lvalue\n" ;
}
template<typename T>
void F(T&& r){
    Print(std::forward<T>(r)) ;
//    Print(r) ; //r will always be an lvalue unless forwarding is used
}

void test(){
    int i{} ;
    F(i) ;
    F(3) ;
}
