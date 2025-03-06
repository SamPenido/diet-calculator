#include "calculos.hpp"
#include <iostream>

float calcularTMB(const DadosPaciente& paciente) {
    if (paciente.sexo == 'm') {
        return 10 * paciente.peso + 6.25 * paciente.alturaMetros * 100 + 5 - 5 * paciente.idade;
    } else {
        return 10 * paciente.peso + 6.25 * paciente.alturaMetros * 100 - 161 - 5 * paciente.idade;
    }
}

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

std::string classificarIMC(float imc) {
    if (imc < 18.5) return "Baixo Peso";
    if (imc < 24.9) return "Peso Normal";
    if (imc < 29.9) return "Sobrepeso";
    return "Obesidade";
}

float calcularNecessidadeHidrica(float peso) {
    return peso * 35;
}

void calcularMacronutrientes(float calorias, int objetivo) {
    float carbo, proteina, gordura;

    switch (objetivo) {
        case 1:  // Perda de Peso
            proteina = 2.0; 
            gordura = calorias * 0.25 / 9;
            carbo = (calorias - (proteina * 4 + gordura * 9)) / 4;
            break;

        case 2:  // Manutenção
            proteina = 1.6; 
            gordura = calorias * 0.3 / 9;
            carbo = (calorias - (proteina * 4 + gordura * 9)) / 4;
            break;

        case 3:  // Ganho de Massa
            proteina = 1.8; 
            gordura = calorias * 0.25 / 9;
            carbo = (calorias - (proteina * 4 + gordura * 9)) / 4;
            break;

        default:
            proteina = 1.6;
            gordura = calorias * 0.3 / 9;
            carbo = (calorias - (proteina * 4 + gordura * 9)) / 4;
            break;
    }

    std::cout << "Macros sugeridos:\n";
    std::cout << "Proteínas: " << proteina * paciente.peso << "g\n";
    std::cout << "Gorduras: " << gordura << "g\n";
    std::cout << "Carboidratos: " << carbo << "g\n";
}
