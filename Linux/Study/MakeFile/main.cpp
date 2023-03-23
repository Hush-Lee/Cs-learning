#include"head.h"
#include <iostream>
#include <ostream>
int main(){
    int a=7;
    int b=6;
    std::cout<<a<<"+"<<b<<"="<<add(a,b)<<std::endl;
    std::cout<<a<<"-"<<b<<"="<<sub(a,b)<<std::endl;
    std::cout<<a<<"x"<<b<<"="<<multiply(a, b)<<std::endl;
    std::cout<<a<<"/"<<b<<"="<<divid(a,b)<<std::endl;
}
