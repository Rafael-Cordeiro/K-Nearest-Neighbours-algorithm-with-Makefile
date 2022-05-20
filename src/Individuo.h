#include <bits/stdc++.h>

using namespace std;

class Individuo {
    private:
        string classe;
        double attr1, attr2, attr3, attr4;
    public:
        Individuo(double attr1, double attr2, double attr3, double attr4, string classe) {
            this->attr1 = attr1;
            this->attr2 = attr2;
            this->attr3 = attr3;
            this->attr4 = attr4;
            this->classe = classe;
        }

        string getClasse() {
            return this->classe;
        }

        double getAttr1() {
            return this->attr1;
        }

        double getAttr2() {
            return this->attr2;
        }

        double getAttr3() {
            return this->attr3;
        }
        
        double getAttr4() {
            return this->attr4;
        }
};