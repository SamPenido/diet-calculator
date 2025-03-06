#include <iostream>
#include "paciente.hpp"
#include "calculos.hpp"

int main() {
    DadosPaciente paciente;

    std::cout << "Nome: ";
    std::cin >> paciente.nome;

    std::cout << "Sexo (m/f): ";
    std::cin >> paciente.sexo;

    std::cout << "Peso (kg): ";
    std::cin >> paciente.peso;

    std::cout << "Altura (cm): ";
    float alturaCm;
    std::cin >> alturaCm;
    paciente.alturaMetros = alturaCm / 100;

    std::cout << "Idade: ";
    std::cin >> paciente.idade;

    paciente.tmb = calcularTMB(paciente);

    std::cout << "\nTMB Calculada: " << paciente.tmb << " kcal\n";

    float imc = calcularIMC(paciente.peso, paciente.alturaMetros);
    std::cout << "IMC: " << imc << " (" << classificarIMC(imc) << ")\n";

    float agua = calcularNecessidadeHidrica(paciente.peso);
    std::cout << "Necessidade hídrica: " << agua << " ml/dia\n";

    std::cout << "Objetivo (1-Perder Peso, 2-Manter, 3-Ganhar Peso): ";
    int objetivo;
    std::cin >> objetivo;

    calcularMacronutrientes(paciente.tmb, objetivo);

    return 0;
}
