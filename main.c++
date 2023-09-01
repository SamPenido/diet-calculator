#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DadosPaciente {
public:
  string nome;
  float altura = 0;
  float peso = 0;
  int idade = 0;
  char usuario;
  int calculadora = 0;
  float resultado = 0;
};

vector<DadosPaciente> dadosPacientes;
void adicionarDados();
void mostrarDados();
float calcularHarrisBenedit(char usuario, float peso, float altura, int idade);
float calcularOMS(char usuario, float peso, int idade);
float calcularFormulaDeBolso(int opcao, float peso);
float calcularDRISaudaveis(char usuario, float peso, float altura, int idade,
                           int opcao);
float calcularDRISobrepeso(char usuario, float peso, float altura, int idade,
                           int opcao);
void calcularMacronutrientes(float resultado, int opcao);

int main() {
  int menuOpcao;
  bool continuar = true;

  // Menu inicial//

  while (continuar) {
    cout << "\n" << endl;
    cout << "Menu Inicial" << endl;
    cout << "1. Acessar Dados" << endl;
    cout << "2. Realizar Consulta" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opcao: ";
    cout << "\n" << endl;
    cin >> menuOpcao;

    switch (menuOpcao) {
    case 1:
      mostrarDados();
      break;

    case 2:
      adicionarDados();
      break;

    case 3:
      continuar = false;
      break;

    default:
      cout << "Opção invalida" << endl;
      break;
    }
  }

  return 0;
}

// Adicionar Dados //

void adicionarDados() {
  DadosPaciente paciente;
  cout << "Digite o Nome do Paciente: ";
  cin >> paciente.nome;

  cout << "Digite o Sexo do Paciente (m/f): ";
  cin >> paciente.usuario;

  cout << "Digite o Peso do Paciente: ";
  cin >> paciente.peso;

  cout << "Digite a Altura do paciente em CENTIMETROS: ";
  cin >> paciente.altura;

  cout << "Digite a Idade do Paciente: ";
  cin >> paciente.idade;
  cout << "\n" << endl;
  cout << "Opcao de calculadora" << endl;
  cout << "(1) Harris Benedit" << endl;
  cout << "(2) OMS" << endl;
  cout << "(3) Formula de bolso" << endl;
  cout << "(4) DRI Saudaveis" << endl;
  cout << "(5) DRI Sobrepeso" << endl;
  cout << ": ";
  cout << "\n" << endl;
  cin >> paciente.calculadora;

  switch (paciente.calculadora) {
  case 1:
    paciente.resultado = calcularHarrisBenedit(paciente.usuario, paciente.peso,
                                               paciente.altura, paciente.idade);
    break;

  case 2:
    paciente.resultado =
        calcularOMS(paciente.usuario, paciente.peso, paciente.idade);
    break;

  case 3:
    int opcao;
    cout << "Selecione a opcao:\n";
    cout << "(1) Perda de Peso\n";
    cout << "(2) Manutencao\n";
    cout << "(3) Ganho de Peso\n";
    cin >> opcao;
    paciente.resultado = calcularFormulaDeBolso(opcao, paciente.peso);
    break;

  case 4:
    cout << "Calculadora disponivel apenas para idade acima de 18 anos.\n";
    cout << "Calculadora (DRI Saudaveis) selecionada.\n";
    cout << "Fator atividade:\n";
    cout << "(1) Sedentario\n";
    cout << "(2) Ativo\n";
    cout << "(3) Muito Ativo\n";
    cin >> opcao;
    paciente.resultado =
        calcularDRISaudaveis(paciente.usuario, paciente.peso, paciente.altura,
                             paciente.idade, opcao);
    break;

  case 5:
    cout << "Calculadora disponivel apenas para idade acima de 18 anos.\n";
    cout << "Calculadora (DRI Sobrepeso) selecionada.\n";
    cout << "Fator atividade:\n";
    cout << "(1) Sedentario\n";
    cout << "(2) Ativo\n";
    cout << "(3) Muito Ativo\n";
    cin >> opcao;
    paciente.resultado =
        calcularDRISobrepeso(paciente.usuario, paciente.peso, paciente.altura,
                             paciente.idade, opcao);
    break;

  default:
    cout << "Numero digitado invalido" << endl;
    break;
  }

  calcularMacronutrientes(paciente.resultado, paciente.calculadora);

  dadosPacientes.push_back(paciente);
  cout << "\n" << endl;
  cout << "Dados salvos com sucesso!" << endl;
  cout << "\n" << endl;
}

// Mostrar os dados //

void mostrarDados() {
  if (dadosPacientes.empty()) {
    cout << "\n" << endl;
    cout << "Banco de dados vazio. Realize uma consulta para salvar dados."
         << endl;
  } else {
    for (const auto &paciente : dadosPacientes) {
      cout << "\n" << endl;
      cout << "Nome do paciente: " << paciente.nome << endl;
      cout << "Altura: " << paciente.altura << " cm" << endl;
      cout << "Peso: " << paciente.peso << " kg" << endl;
      cout << "Idade: " << paciente.idade << " anos" << endl;
      cout << "Sexo: " << ((paciente.usuario == 'm') ? "Masculino" : "Feminino")
           << endl;
      cout << "Calculadora: " << paciente.calculadora << endl;
      cout << "Resultado: " << paciente.resultado << " KCAL" << endl;
      cout << "\n" << endl;
      cout << endl;
    }
  }

  cout << "Pressione Enter para voltar ao menu inicial...";
  cin.ignore();
  cin.get();

  system("clear");
}

float calcularHarrisBenedit(char usuario, float peso, float altura, int idade) {
  float FA = 0;
  int opcao;
  cout << "\n" << endl;
  cout << "Fator atividade: " << endl;
  cout << "(1) Acomodado" << endl;
  cout << "(2) Acomodado e Movel" << endl;
  cout << "(3) Ambulante" << endl;
  cout << "\n" << endl;
  cin >> opcao;

  if (opcao == 1) {
    FA = 1.2;
  } else if (opcao == 2) {
    FA = 1.25;
  } else if (opcao == 3) {
    FA = 1.3;
  }

  if (usuario == 'm') {
    return (66.5 + (13.75 * peso) + (5 * altura) - (6.76 * idade)) * FA;
  } else if (usuario == 'f') {
    return (655 + (9.56 * peso) + (1.85 * altura) - (4.68 * idade)) * FA;
  }

  return 0;
}

float calcularOMS(char usuario, float peso, int idade) {
  if (idade >= 18 && idade < 30) {
    return (usuario == 'm') ? (15.057 * peso + 692.2) : (14.818 * peso + 486.6);
  } else if (idade >= 30 && idade < 60) {
    return (usuario == 'm') ? (11.472 * peso + 873.1) : (8.126 * peso + 845.6);
  } else if (idade >= 60) {
    return (usuario == 'm') ? (11.711 * peso + 587.7) : (11.711 * peso + 587.7);
  }

  return 0;
}

float calcularFormulaDeBolso(int opcao, float peso) {
  if (opcao == 1) {
    return 22.5 * peso;
  } else if (opcao == 2) {
    return 27.5 * peso;
  } else if (opcao == 3) {
    return 32.5 * peso;
  }

  return 0;
}

float calcularDRISaudaveis(char usuario, float peso, float altura, int idade,
                           int opcao) {
  altura /= 100;
  float PA = 0;

  if (opcao == 1) {
    PA = 1.0;
  } else if (opcao == 2) {
    PA = 1.11;
  } else if (opcao == 3) {
    PA = 1.25;
  }

  if (usuario == 'm') {
    return 662 - (9.53 * idade) + PA * ((15.91 * peso) + (539.6 * altura));
  } else if (usuario == 'f') {
    return 354 - (6.91 * idade) + PA * ((9.36 * peso + 726 * altura));
  }

  return 0;
}

float calcularDRISobrepeso(char usuario, float peso, float altura, int idade,
                           int opcao) {
  altura /= 100;
  float PA = 0;

  if (opcao == 1) {
    PA = 1.0;
  } else if (opcao == 2) {
    PA = 1.11;
  } else if (opcao == 3) {
    PA = 1.25;
  }

  if (usuario == 'm') {
    return 1086 - (10.1 * idade) + PA * ((13.7 * peso) + (416 * altura));
  }

  return 0;
}

void calcularMacronutrientes(float resultado, int opcao) {
  float carbo;
  float proteina;
  float fat;

  switch (opcao) {
  case 1:
    carbo = (resultado / 2) / 4;
    proteina = (resultado * 0.3) / 4;
    fat = (resultado * 0.2) / 9;
    cout << "\n" << endl;
    cout << "Carboidratos: " << carbo << "g" << endl;
    cout << "Proteinas: " << proteina << "g" << endl;
    cout << "Gorduras: " << fat << "g" << endl;
    cout << "\n" << endl;
    break;

  case 2:
    carbo = (resultado * 0.55) / 4;
    proteina = (resultado * 0.15) / 4;
    fat = (resultado * 0.3) / 9;
    cout << "\n" << endl;
    cout << "Carboidratos: " << carbo << "g" << endl;
    cout << "Proteinas: " << proteina << "g" << endl;
    cout << "Gorduras: " << fat << "g" << endl;
    cout << "\n" << endl;
    break;

  case 3:
    carbo = (resultado * 0.4) / 4;
    proteina = (resultado * 0.3) / 4;
    fat = (resultado * 0.3) / 9;
    cout << "\n" << endl;
    cout << "Carboidratos: " << carbo << "g" << endl;
    cout << "Proteinas: " << proteina << "g" << endl;
    cout << "Gorduras: " << fat << "g" << endl;
    cout << "\n" << endl;
    break;

  default:
    cout << "Opção invalida" << endl;
    break;
  }
}
