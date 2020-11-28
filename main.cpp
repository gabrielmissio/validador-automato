#include<iostream>
#include<string>

using namespace std;

string input;
int controle = 0;
char proximoCharValido1 = 'a';
char proximoCharValido2 = ' ';



void s0();
void s1();
void s2();
void s3();

int main(){

    string linguagem = "{W | W ∈ {ab^m ba(ab)^n | m, n ≥0} }";
    bool valido = false;
    cout<<linguagem<<endl;
    cout<<"Entre com uma palavra para verificar se ela eh valida com a linguagem a cima: ";
    cin>>input;
    s0();

}

void s0(){

    if(controle < input.size()){
        if(input[controle] == proximoCharValido1){//a
            proximoCharValido1 = 'a';
            controle++;
            s1();
        }else{
            controle++;
            s0();
        }
    }else{
        cout<<"PALAVRA INVALIDA"<<endl;
    }

}
void s1(){

    if(controle < input.size()){
        if(input[controle] == proximoCharValido1){//b
            proximoCharValido1 = 'a';
            controle++;
            s2();
        }else{
            controle++;
            s1();
        }
    }else{
        cout<<"PALAVRA INVALIDA"<<endl;
    }

}
void s2(){//s3 do desenho errado

    if(controle < input.size()){
        if(input[controle] == proximoCharValido1){//a
            proximoCharValido1 = 'b';
            controle++;
            s3();
        }else{
            controle++;
            s2();
        }
    }else{
        cout<<"PALAVRA VALIDA"<<endl;
    }
}

void s3(){

    if(controle < input.size()){
        if(input[controle] == proximoCharValido1){//b
            proximoCharValido1 = 'a';
            controle++;
            s2();
        }else{
            controle++;
            s3();
        }
    }else{
        cout<<"PALAVRA INVALIDA"<<endl;
    }

}
