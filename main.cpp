#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string input;
int controle;
char proximoCharValido;
ofstream results;

void s0();
void s1();
void s2();
void s3();
void writeLine(string result);


int main(){
    bool valido = false;
    ifstream strings;
    string linguagem = "L = {W | W ∈ {ab^m ba(ab)^n | m, n ≥0} }";
    string alfabeto = "Alfabeto = {a,b}";
    string estados = "Estados = {q0, q1, q2, q3}";
    string estadosIniciais = "Estado Inicial = {q0}";
    string estadosFinais = "Estado Final = {q2}";

    results.open("saida.txt");
    results<<linguagem<<"\n";
    results<<alfabeto<<"\n";
    results<<estados<<"\n";
    results<<estadosIniciais<<"\n";
    results<<estadosFinais<<"\n";
    results<<"-----------------------------------"<<"\n";

    cout<<linguagem<<endl;
    cout<<alfabeto<<endl;
    cout<<estados<<endl;
    cout<<estadosIniciais<<endl;
    cout<<estadosFinais<<"\n"<<endl;

    strings.open("entrada.txt");
    while (std::getline(strings, input)) {
        // Start variable values
        controle = 0;
        proximoCharValido = 'a';

        cout<<"Palavra Lida: "<<input<<endl;
        s0();
    }
    strings.close();
    results.close();
}

void writeLine(string result){
    if (results.is_open()) {
        results<<result<<"\n";
    } else {
        throw invalid_argument("Result file is not accessible.");
    }
}

void s0(){
    string value;
    if(controle < input.size()){
        value = "ft(q0,";
        value += input[controle];
        value = value + ") = ";
        if(input[controle] == proximoCharValido){//a
            proximoCharValido = 'a';
            controle++;
            writeLine(value + "q1");
            s1();
        }else{
            controle++;
            writeLine(value + "q0");
            s0();
        }
    }else{
        cout<<"STRING REJEITADA"<<endl;
    }

}

void s1(){

    if(controle < input.size()){
        if(input[controle] == proximoCharValido){//b
            proximoCharValido = 'a';
            controle++;
            s2();
        }else{
            controle++;
            s1();
        }
    }else{
        cout<<"STRING REJEITADA"<<endl;
    }

}

void s2(){//s3 do desenho errado

    if(controle < input.size()){
        if(input[controle] == proximoCharValido){//a
            proximoCharValido = 'b';
            controle++;
            s3();
        }else{
            controle++;
            s2();
        }
    }else{
        cout<<"STRING ACEITA"<<endl;
    }
}

void s3(){

    if(controle < input.size()){
        if(input[controle] == proximoCharValido){//b
            proximoCharValido = 'a';
            controle++;
            s2();
        }else{
            controle++;
            s3();
        }
    }else{
        cout<<"STRING REJEITADA"<<endl;
    }

}
