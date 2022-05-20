#include "knn.h"

int main(int argc, char const *argv[]) {
    vector<Individuo> individuos;
    int K = 6;
    int tamTreinamento = 105;

    for (int i = 0; i < tamTreinamento; i++) {
        string classe;
        double a, b, c, d;
        cin >> a >> b >> c >> d >> classe;
        individuos.push_back(Individuo(a, b, c, d, classe));
    }
    
    int acertos = 0;
    int tamTestes = 150 - tamTreinamento;

    for (int i = 0; i < tamTestes; i++) {
        string classe;
        double a, b, c, d;
        cin >> a >> b >> c >> d >> classe;
        Individuo ind(a, b, c, d, classe);
        string classeObtida = classificarAmostra(individuos, ind, K);
        cout << "Classe esperada: " << classe << "\n";
        cout << "Classe obtida: " << classeObtida << "\n\n";

        if (classe == classeObtida)
            acertos++;
    }

    cout << acertos << " acertos de um total de " << tamTestes << " testes.\n";
    
    return 0;
}
