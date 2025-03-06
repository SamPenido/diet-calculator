#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>

struct DadosPaciente {
    std::string nome;
    float alturaMetros = 0;
    float peso = 0;
    int idade = 0;
    char sexo;
    int calculadora = 0;
    float tmb = 0;  // Taxa Metabólica Basal
};

#endif
