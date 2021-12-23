#include <iostream>
#include <string>

class racun{
    private:
        std::string ime;
        std::string prezime;
        double stanje;
    public:
        racun() = default;
        
        racun(std::string a, std::string b, double c)
        : ime{a}, prezime{b}, stanje{c}
        {}

        void uplati(const double&& a){stanje+=a;}
        void isplati(const double&& a){
            if(stanje < a)
                throw std::string{"Na racunu nema dovoljno sredstava za isplatu!"};
            stanje -= a;
        }
        double stanje_racuna(){return stanje;}
};

int main(int argc, const char** argv) 
{
    racun r("james", "smith", 10000.0);
    r.uplati(100.5);
    r.isplati(200.5);
    std::cout << r.stanje_racuna() << std::endl;

    return 0;
}