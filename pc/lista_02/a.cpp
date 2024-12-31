#include <iostream>
#include <string>

int main() {
    std::string entrada;
    std::cin >> entrada;
    
    int formigas_ingeridas = 0, formigas_ingeridas_totais= 0, rans_vivas, serpentes;
 
    for (char c : entrada) {
        if (c == 'r') {
            if (rans_vivas > 0){
                formigas_ingeridas_totais += formigas_ingeridas;
                formigas_ingeridas = 0;
            }
            else
                rans_vivas = 1;
        } else if (c == 's' && rans_vivas > 0) {
            rans_vivas--;
            formigas_ingeridas = 0;
        } else if (c == '.' && rans_vivas > 0) {
            formigas_ingeridas++;
        }
    }
    formigas_ingeridas_totais += formigas_ingeridas;
    std::cout << formigas_ingeridas_totais << std::endl;
    
    return 0;
}
