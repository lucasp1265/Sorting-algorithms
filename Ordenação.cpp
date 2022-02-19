#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define quantidade 10


/* Função para trocar dois ponteiros 
*/
void troca(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
void bubbleSort(int n, int *v){
    
    /* Condição de parada para a recursão
    */
    if(n<1){
        return;
    }
        /*For para percorrer o vertor enquanto verifica cada par e troca de lugar se for necessário
        */
        for(int i=0;i<n;i++){
         if(v[i]>v[i+1]){
            troca(&v[i],&v[i+1]);
        }
    }
    /* Chamada da recursão n vezes(de n até 1)
    */
    bubbleSort(n-1,v);

}

void insertionSort(int *v, int n){
    int key,j;
    /*O for seleciona cada elemento do vetor
    */
    for (int i = 1; i < n; i++) {
        key = v[i];
        j = i - 1;
        /* O while encontra a posição e troca com o elemento seguinte se ele for maior
        */
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void selectionSort(int *v, int n){
    int min;
/*Passa pelo vetor procurando o menor valor e colocando seu indice em min. 
    Se o min não for o mesmo do primeiro for ele troca de lugar o min com posição comparada
*/
    for (int i = 0; i < (n-1); i++){
     min = i;
     for (int j = (i+1); j < n; j++) {
       if(v[j] < v[min]) 
         min = j;
     }
     if (i != min) {
       troca(&v[i],&v[min]);
     }
  }

}

void mergeIntercala(int *v,int aux[],int ini, int meio,int fin){

    int atual,fimEsq,n;
    atual = ini;
    fimEsq = meio-1;
    n = fin + 1;
    /*Enquanto a primeira metade do vetor não chega no meio e a segunda metade não chega no final
        é verificado qual valor é menor e colocado no vetor auxiliar
    */
    while((ini<=fimEsq)&&(meio<=fin)){
        if(v[ini]<= v[meio])
            aux[atual++] = v[ini++];
        else
            aux[atual++] = v[meio++];
    }

    /* Se caso existirem valores não ordenados pela função acima em alguma das metades(Caso de vetores impares)
        O while continua ordenando
    */
    while(ini<=fimEsq)
        aux[atual++] = v[ini++];

    while(meio<=fin)
        aux[atual++] = v[meio++];

    /*for para ordenar o vetor inicial usando o auxiliar
    */
    for(int i = 0;i < n;i++){
        v[fin] = aux[fin];
        fin--;
    }
}

/*Divide o vetor de dois em dois chamando a função merge intercala para cada valor
*/
void mergeDivide(int *v, int aux[], int ini, int fin){
    int meio;
    if(fin>ini){
        meio = (fin+ini)/2;

        mergeDivide(v,aux,ini,meio);
        mergeDivide(v,aux,meio+1,fin);

        mergeIntercala(v,aux,ini,meio+1,fin);

    }

}

void mergeSort(int *v, int n){
    int aux[n];
    mergeDivide(v,aux,0,n-1);

}

void quickSort(int *v, int ini, int fin)
{
	int i, j, pivo, aux;
	i = ini;
	j = fin-1;
    /* Pivo sendo atribuido na metade do vetor
    */
	pivo = v[(ini + fin) / 2];

    /* while acha o primeiro valor maior ou igual ao pivo da pela esquerda e o primeiro valor menor ou igual ao pivo pela direita
        E se o i não passou pelo j ele troca os valores da posição
    */
	while(i <= j)
	{
		while(v[i] < pivo && i < fin)
		{
			i++;
		}
		while(v[j] > pivo && j > ini)
		{
			j--;
		}
		if(i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
    /*Se o J não chegou ao começou ou o i não chegou ao final, é chamada uma recursividade 
    */
	if(j > ini)
		quickSort(v, ini, j+1);
	if(i < fin)
		quickSort(v, i, fin);
}

int main(){
    int op;
    int *vetor;
    vetor = new int[quantidade];

    srand((unsigned)time(0));

    for(int i=0;i<quantidade;i++){
        vetor[i] = rand()%(quantidade);
        cout << vetor[i] << endl;
    }
    cout << "Escolha qual Algoritmo de ordenacao (1:Bubble 2:Insert 3:Selection 4:Merge 5:Quick)" << endl;
    cin >> op;

    switch(op){
        case 1:
            bubbleSort(quantidade,vetor);
            break;

        case 2:

            insertionSort(vetor,quantidade);
            break;
        case 3:

            selectionSort(vetor,quantidade);
            break;

        case 4:
            mergeSort(vetor,quantidade);
            break;

        case 5:
            quickSort(vetor,0,quantidade);
            break;
        
        default:
            cout << "Opcao invalida!" << endl;
            break;



    }

    for(int i=0;i<quantidade;i++){
        cout << vetor[i];
    }

    
    delete[] vetor;

    return 0;
}