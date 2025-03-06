#ifndef CALCULOS_HPP
#define CALCULOS_HPP

#include "paciente.hpp"

float calcularTMB(const DadosPaciente& paciente);
float calcularIMC(float peso, float altura);
std::string classificarIMC(float imc);
float calcularNecessidadeHidrica(float peso);
void calcularMacronutrientes(float calorias, int objetivo);

#endif
