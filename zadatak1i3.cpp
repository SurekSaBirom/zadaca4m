#include <iostream>
#include <list>
#include <string>

template <typename t, typename u>
t find_br(std::list<t> lista, u lamb){
    if(lista.empty()) throw std::string{"Kolekcija je prazna!"};
    t max = *(lista.begin());
    auto it = lista.begin();
    while( it != lista.end() ){
        if( lamb(*it, max) ) max = *it;
        ++it;
    } 
    return max;
}

int main() 
{
    std::list<int> a{1,2,5,20,-2,5};
    std::list<char> b{'a', 'b', 'c'};

    auto min = [](auto a, auto b){return a < b;};
    auto max = [](auto a, auto b){return a > b;};

    int k2 = find_br(a, max);
    int k1 = find_br(a, min);

    char a1 = find_br(b, max);
    char a2 = find_br(b, min);

    std::cout << k1 << ',' << k2 << std::endl;
    std::cout << a1 << ',' << a2 << std::endl;

    return 0;
}