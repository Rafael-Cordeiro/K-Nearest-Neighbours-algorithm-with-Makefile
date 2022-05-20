#include "Individuo.h"
#include <vector>
#include <math.h>
#include <set>
#include <map>

double obterDistanciaEuclidiana(Individuo ind1, Individuo ind2) {
    double soma = pow((ind1.getAttr1() - ind2.getAttr1()), 2) +
        pow((ind1.getAttr2() - ind2.getAttr2()), 2) +
        pow((ind1.getAttr3() - ind2.getAttr3()), 2) +
        pow((ind1.getAttr4() - ind2.getAttr4()), 2);
    
    return sqrt(soma);
}

string classificarAmostra(vector<Individuo>& individuos, Individuo aNewIndividuo, int K) {
    if (K % 2 == 0) {
        K--;
        if (K <= 0) {
            K = 1;
        }
    }

    int individuosSize = individuos.size();
    set<pair<double, int>> distIndividuos;
    
    for (int i = 0; i < individuosSize; i++) {
        double dist = obterDistanciaEuclidiana(individuos[i], aNewIndividuo);
        distIndividuos.insert(make_pair(dist, i));
    }

    set<pair<double, int>>::iterator it;
    vector<int> contClasses(3);
    int contK = 0;

    for (it = distIndividuos.begin(); it != distIndividuos.end(); it++) {
        string classe = individuos[it->second].getClasse();

        cout << individuos[it->second].getClasse() << " ";
        cout << it->second << ": " << it->first << "\n";

        if (classe == "Iris-setosa")
            contClasses[0]++;
        if (classe == "Iris-versicolor")
            contClasses[1]++;
        if (classe == "Iris-virginica")
            contClasses[2]++;

        if (contK > K) break;
        contK++;
    }

    string classeClassificacao;

    if (contClasses[0] >= contClasses[1] && contClasses[0] >= contClasses[2])
        classeClassificacao = "Iris-setosa";
    if (contClasses[1] >= contClasses[0] && contClasses[1] >= contClasses[2])
        classeClassificacao = "Iris-versicolor";
    if (contClasses[2] >= contClasses[0] && contClasses[2] >= contClasses[1])
        classeClassificacao = "Iris-virginica";

    return classeClassificacao;
}