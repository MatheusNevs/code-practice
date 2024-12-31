#include <iostream>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;

    // Ler os erros da primeira compilação
    std::unordered_set<int> comp1;
    for (int i = 0; i < N; ++i) {
        int error;
        std::cin >> error;
        comp1.insert(error);
    }

    // Ler os erros da segunda compilação
    std::unordered_set<int> comp2;
    for (int i = 0; i < N - 1; ++i) {
        int error;
        std::cin >> error;
        comp2.insert(error);
    }

    // Ler os erros da terceira compilação
    std::unordered_set<int> comp3;
    for (int i = 0; i < N - 2; ++i) {
        int error;
        std::cin >> error;
        comp3.insert(error);
    }

    // Encontrar os erros removidos nas duas correções
    int removed1, removed2;

    for (int error : comp1) {
        if (comp2.count(error) == 0) {
            removed1 = error;
            break;
        }
    }

    for (int error : comp2) {
        if (comp3.count(error) == 0) {
            removed2 = error;
            break;
        }
    }

    // Imprimir os resultados em ordem crescente
    if (removed1 > removed2) {
        std::swap(removed1, removed2);
    }

    std::cout << removed1 << " " << removed2 << std::endl;

    return 0;
}
