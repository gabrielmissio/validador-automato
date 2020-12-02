#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string input;
string result;
int controle;
char proximoCharValido;
ofstream results;

void s0(bool first);
void s1();
void s2();
void s3();
void writeLine(bool finalLine, bool isReject);


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
        result = "";

        cout<<"Palavra Lida: "<<input<<endl;
        results<<"Palavra Lida: "<<input<<"\n";
        s0(true);
    }
    strings.close();
    results.close();
}

void writeLine(bool finalLine=false, bool isReject=false){
    string reject = "STRING REJEITADA";

    if (results.is_open()) {
        results<<result<<"\n";
        if (isReject){
            cout<<reject<<endl;
            results<<"\n"<<reject<<"\n";
        }
        if (finalLine) {
            cout<<"-----------------------------------"<<"\n"<<endl;
            results<<"-----------------------------------"<<"\n"<<"\n";
        }
    } else {
        throw invalid_argument("Result file is not accessible.");
    }
}

void s0(bool first = false){

    if(controle < input.size()){
        if (!first) {
            result = result + "q0";
            writeLine();
        }

        result = "ft(q0,";
        result += input[controle];
        result = result + ") = ";

        if(input[controle] == proximoCharValido){//a
            proximoCharValido = 'a';
            controle++;
            s1();
        }else{
            controle++;
            s0();
        }
    }else{
        if (first) {
            result = "Error on read string!";
        } else {
            result += "error";
        }
        writeLine(true, true);
    }

}

void s1(){

    if(controle < input.size()){
        result = result + "q1";
        writeLine();

        result = "ft(q1,";
        result += input[controle];
        result = result + ") = ";

        if(input[controle] == proximoCharValido){//b
            proximoCharValido = 'a';
            controle++;
            s2();
        } else {
            controle++;
            s1();
        }
    }else{
        result += "error";
        writeLine(true, true);
    }

}

void s2(){//s3 do desenho errado

    if(controle < input.size()){
        result = result + "q2";
        writeLine();

        result = "ft(q2,";
        result += input[controle];
        result = result + ") = ";

        if(input[controle] == proximoCharValido){//a
            proximoCharValido = 'b';
            controle++;
            s3();
        }else{
            controle++;
            s2();
        }
    }else{
        result += "q2";
        writeLine();
        result = "\nSTRING ACEITA";
        cout<<result<<endl;
        writeLine(true);
    }
}

void s3(){

    if(controle < input.size()){
        result = result + "q3";
        writeLine();

        result = "ft(q3,";
        result += input[controle];
        result = result + ") = ";

        if(input[controle] == proximoCharValido){//b
            proximoCharValido = 'a';
            controle++;
            s2();
        }else{
            controle++;
            s3();
        }
    }else{
        result += "error";
        writeLine(true, true);
    }

}
