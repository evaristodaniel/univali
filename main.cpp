/*
 Algortimo Calculadora
 Esse algortimo converte número decimais para binário e binários para decimais.
 
 Autores: Daniel e Lucas.
 */

#include <iostream>
#include <cmath>
#include <curses.h>

using namespace std;

// Procedimento para converter Binário para decimal

void converteBinarioDecimal () {
    int binario,resto, decimal = 0, i = 0;
    cout << "Entre com o valor em Binário: ";
    cin >> binario;
    while (binario != 0) {
        resto = binario % 10;
        binario = binario / 10;
        decimal += resto * pow(2,i);
        ++i;
    }
    cout << "Valor BINÁRIO, convertido para DECIMAL: " << decimal << endl << endl;
}

// Procedimento para converter Decimal para Binário.
// Utilizamos um vetor de 8 posições responsável por armazenar o resto da divisão.
// O armazenamento do resto ocorre de trás para frente, com a intenção de guardar na forma inversa.

void converteDecimalBinario () {
    int vet[8], cont=7, decimal;
    
    cout << "Entre com o valor em Decimal: ";
    cin >> decimal;
    
    for(int i=0; i < 8; i++)
        vet[i] = 0;
                                           
    while(decimal >= 1){
        vet[cont] = decimal % 2;
        decimal = decimal / 2;
        cont = cont - 1;
    }
    
    cout << "Valor DECIMAL, convertido para BINÁRIO: ";
    
    for(int i=cont+1; i < 8 ;i++)
        cout << vet[i];
}

// Procedimento para desenha a calculadora.

void menu () {
    cout <<"         _____________________"     <<endl;
    cout <<"        |    CALCULADORA      |"    <<endl;
    cout <<"        |  _________________  |"    <<endl;
    cout <<"        | |Pressione...     | |"    <<endl;
    cout <<"        | |1.Decimal-Binário| |"    <<endl;
    cout <<"        | |2.Binário-Decimal| |"    <<endl;
    cout <<"        | |_________________| |"    <<endl;
    cout <<"        |  ___ ___ ___   ___  |"    <<endl;
    cout <<"        | | 7 | 8 | 9 | | + | |"    <<endl;
    cout <<"        | |___|___|___| |___| |"    <<endl;
    cout <<"        | | 4 | 5 | 6 | | - | |"    <<endl;
    cout <<"        | |___|___|___| |___| |"    <<endl;
    cout <<"        | | 1 | 2 | 3 | | x | |"    <<endl;
    cout <<"        | |___|___|___| |___| |"    <<endl;
    cout <<"        | | . | 0 | = | | / | |"    <<endl;
    cout <<"        | |___|___|___| |___| |"    <<endl;
    cout <<"        |_____________________|"    <<endl;

}

// Inicio do programa

int main() {
    int op;
    
    menu();                                         // Chama procedimento para desenhar calculadora
    cout << "$: ";
    cin  >> op;                                     // Leitura da opção desejada pelo usuário.
    
    switch (op) {                                   // Caso digite 1 converte Binario para Decimal e 2 Decimal para Bin.
        case 1:converteBinarioDecimal(); break;
        case 2:converteDecimalBinario(); break;
        default: cout<<"Opção inválida";            // Caso digite algo diferente de 1 e 2 apresenta mensagem de oção inválida.
    }
    
    return 0;
}
