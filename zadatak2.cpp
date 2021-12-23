#include <iostream>
#include <vector>

class student{
    private:
        std::string ime;
        std::string prezime;
        std::vector<int> ocjene;
    public:
        student () = default;
        student(std::string a, std::string b, std::vector<int> c)
        : ime{a}, prezime{b}, ocjene{c} {};

        void dodaj_ocjenu(int a){ ocjene.push_back(a); }
        double prosjek_ocjena(){
            auto it = ocjene.begin();
            double pro = 0;
            while(it!=ocjene.end()){
                pro += *it;
                ++it;
            }
            pro /= ocjene.size();
            return pro;
        }
};

int main() 
{
    std::vector<int> ocjene{8,9,10};
    student s("mary", "jhonson", ocjene);
    s.dodaj_ocjenu(10);
    std::cout << s.prosjek_ocjena() << std::endl;

    return 0;
 }