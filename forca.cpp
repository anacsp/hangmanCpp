#include <iostream>
#include <string>

using namespace std;

string defPalavra();
char inLetra();
int compara(string, char, string *);
string boneco(int);

int main(){
    //Intro jogo
    cout << "Bem vindo ao Jogo da Forca" << endl;
    string dsnho = boneco(0);
    cout << dsnho << endl;

    //Gerar palavra
    string aDescobrir = defPalavra();

    //Cria - com quantidade de caracteres da palavra
    string underlines(aDescobrir.length(), '-');

    //Conta vidas
    int vidas = 6;
    int acertosTotal = 0; 

    system("clear"); // Para apagar a palavra digitada
    cout << "Bem vindo ao Jogo da Forca" << endl;

    while(1){
        
        //Imprimir boneco
         string desenho =  boneco(vidas);
         cout << desenho << endl;

        //Imprimir - do tamanho da palavra
        cout << "Palavra: " << underlines << endl << endl;

        //Ler input
        char tentativa = inLetra();
        system("clear"); 
        cout << "Jogo da Forca" << endl;

        //Comparar com a palavra
        int acertos = compara(aDescobrir, tentativa, &underlines);

        //Mostrar se esta certo e vidas
        if(acertos == 0){
            vidas = vidas - 1;
        }
        acertosTotal = acertosTotal + acertos;
        if(acertosTotal == aDescobrir.length()){
            cout << desenho << endl;
            cout << "Uhul! Você descobriu a palavra!"<< endl;
            cout << "A palavra é:" << aDescobrir << endl;
            break;
        }
        cout << "Você possui " << vidas << " vidas." << endl;
       
        //vidas = 0? acaba o jogo
        if(vidas  == 0){
            cout << boneco(vidas) << endl;
            cout << "Você perdeu o jogo." << endl;
            cout << "A palavra era: " << aDescobrir << endl;
            break;
        }
     }
//fim de jogo
return 0;
}

//Função input palavra 
string defPalavra(){
    string palavra;

    cout << "Jogador 1, digite uma palavra: ";
    cin >> palavra;
    return palavra;
}
//Função input letra
char inLetra(){
    char letra;

    cout << "Jogador 2, digite uma letra: ";
    cin >> letra;
    return letra;
}
//Função comparação letra com cada caractere da palavra
int compara(string palavraDig, char letraDig, string *lugarLetra){

    int tam = palavraDig.length();
    int Acertos = 0;
    for(int i = 0; i < tam; i++){
        if(palavraDig[i] == letraDig){
            Acertos++;            
            (*lugarLetra)[i] = letraDig;
        }
    }
    cout << "Você acertou " << Acertos <<" letras!" << endl;
    return Acertos;
}
//Função que desenha o boneco
string boneco(int vida){
    string desenho = "";
    switch(vida){
        case 0:
            desenho = 
 "...___________    \n \
    | /   _|_       \n \
    |/   {ºnº}      \n \
    |     /|\\      \n \
    |      |        \n \
    |    ./ \\.     \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
break;
        case 1:
            desenho = 
 "...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /|\\      \n \
    |      |        \n \
    |    ./         \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
break;
        case 2:
            desenho = 
 "...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /|\\      \n \
    |      |        \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~" ;
break;
        case 3:
            desenho = 
 "...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /|        \n \
    |      |        \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
break;
        case 4:
            desenho = 
 "...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |     /         \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
break; 
        case 5:
            desenho = 
 "...___________    \n \
    | /   _|_       \n \
    |/   {º_º}      \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
break;
        case 6:
            desenho = 
 "...___________    \n \
    | /             \n \
    |/              \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
    |               \n \
~~~~~~~~~~~~~~~~~~~~~~";
break;
    }
return desenho;
}