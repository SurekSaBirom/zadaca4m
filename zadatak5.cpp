#include <iostream>
#include <cmath>

struct tacka{
    int x;
    int y;

    tacka() = default;
    tacka(int a, int b)
    : x{a}, y{b} {};
};

double duzina_stranice(tacka a, tacka b){
    double d = sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
    return d;
}

struct trokut{
    tacka a;
    tacka b;
    tacka c;

    trokut() = default;
    trokut(tacka a1, tacka b1, tacka c1)
    : a{a1}, b{b1}, c{c1} {};

    trokut& transliraj(int tx, int ty){
        a.x += tx; a.y += ty;
        b.x += tx; b.y += ty;
        c.x += tx; c.y += ty;
        auto temp = this;
        return *temp;
    }

    trokut& skaliraj(int tx=1, int ty=1){
        a.x *= tx; a.y *= ty;
        b.x *= tx; b.y *= ty;
        c.x *= tx; c.y *= ty;
        auto temp = this;
        return *temp;
    }

    double obim(){
        double zbir = duzina_stranice(a,b) + duzina_stranice(b,c) + duzina_stranice(c,b);
        return zbir;
    }

    std::string vrhovi(){
        std::string vrhcina = "A(" + std::to_string(a.x) + ',' + std::to_string(a.y) + ") " + "B(" + std::to_string(b.x) + ',' + std::to_string(b.y) + ") " + "C(" + std::to_string(c.x) + ',' + std::to_string(c.y) + ") ";
        return vrhcina;
    }
};

int main(int argc, const char** argv) 
{

    tacka A{1,2};
    tacka B{1,9};
    tacka C;
    C.x = C.y = 4;
    trokut t{A, B, C};
    t.transliraj(3,-3).skaliraj(2).skaliraj(-1,-1);

    std::cout << t.obim() << std::endl;
    std::cout << t.vrhovi() << std::endl;

    return 0;
}
