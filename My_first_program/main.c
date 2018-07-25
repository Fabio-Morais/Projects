#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <locale.h> // biblioteca para conseguir pôr acentos
#define MAX1 10
#define MAX2 20
#define MAX3 30
#define MAX4 100

typedef struct deputados{//variavel deputados
char codigo[MAX1];
char nome[MAX3];
char genero;
char circulo[MAX2];
}tdeputados ;
typedef struct partidos{//variael partidos
char sigla [MAX1];
char nome[MAX3];
int quantdeputados;
int fe;
int ma;
tdeputados deputados[MAX4];
}tpartido;
typedef struct parlamento {//variavel parlamento tparlamento
char pais[MAX1];
int quantpartidos;
tpartido partidos[MAX4];
}tparlamento;
int main(){
setlocale(LC_ALL, "Portuguese");        // habilita a acentuação para o português
tparlamento parlamento[3]={"portugal",3,{"BE","bloco de esquerda",4,1,3,{{"xbe16","Carlos Matias",'M',"porto"},{"abe16","Antonio joão",'M',"porto"},{"cbe16","Catarina Martins",'F',"braga"},{"zbe16","João antónio",'M',"lisboa"}},{"PS","partido socialista",5,2,3,{{"gjr4","Antonia Rocha",'F',"Lisboa"},{"ytr4","Ana drago",'F',"Aveiro"},{"ntr4","Mario Costa",'M',"Lisboa"},{"rt45","Martins moreira",'M',"Porto"},{"gtr4","Marcos Silva",'M',"Aveiro"}}},{"PSD","partido social democrata",8,0,8,{{"psd116","Marcelo Sousa",'M',"Lisboa"},{"psd216","Pedro Lopes",'M',"Lisboa"},{"psd316","Mario Soares",'M',"Lisboa"},{"psd416","Joaquim Amaral",'M',"Lisboa"},{"psd516","Anibal Silva",'M',"Lisboa"},{"psd616","Paulo Rangel",'M',"Setubal"},{"psd716","Francisco Carneiro",'M',"Porto"},{"psd816","José da Silva",'M',"Aveiro"}}}}};
char resp;      //variavel para ler a resposta à pergunta "deseja realizar outras operaçoes?"
int n=1,pos,pot,pog;//n é otamanho do vetor parlamento
do{
system("cls");      //limpar tela
while(n<=0) // verifica se há parlamentos suficientes (>= 1)   n= numero de parlamentos
{
    printf("Não possui parlamentos insira pelo menos um");
    inserirparlamento(parlamento,&n);

}
pot=detetarparlamentomenos3(parlamento,&n,&pos); // a função irá returnar um valor 0, caso houver menos de 3 partidos ou 1 se houver mais de 3 partidos
while(pot==0){ // verifica se há partidos suficentes >=3    pos=posição do partido
    printf("O parlamento %s necessita de mais um partido",parlamento[pos].pais);
    inserirpartidocasoerro(parlamento,&n,pos);      // pos vai ter o numero do parlamento com menos de 3 partidos
    pot=detetarparlamentomenos3(parlamento,&n,&pos);
    }
pog=detetardepumenos4(parlamento,&n,&pos,&pot);
while(pog==0){// verifica se há deputados suficentes (>=3)
    printf("O partido %s precisa de mais deputados",parlamento[pos].partidos[pot].nome);
    depucasoerro(parlamento,&n,pos,pot);        // pot vai ter o numero do partido com menos de 4 deputados
    pog=detetardepumenos4(parlamento,&n,&pos,&pot);
    }
rebot(parlamento,&n); // função com os diversos menus e opções, capaz de voltar ao menu principal
fflush(stdin);      //limpa o buffer para evitar erros
printf("\n\n\t\tDeseja realizar outras operações?(S/N) ");
scanf(" %c",&resp);
resp=toupper(resp);     //transforma a resposta em maisculas
fflush(stdin);



}while(resp=='S'); // Se a resposta do utilizador for 'N' ou 'n' o programa termina


return 0;
}
