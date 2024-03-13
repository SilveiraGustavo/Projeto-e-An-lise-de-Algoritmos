
// Trabalho 01 - Implementação de Algoritmos de Ordenação
//   ###########   INTEGRANTES DO GRUPO    #############
// - André Igor Costa Linhares - Engenharia de Computação, Turma 2021.1.
// - Gustavo Silveira Dias - Engenharia de Computação, Turma 2021.1.
// - Mirelle Silva Vieira - Engenharia de Computação, Turma 2021.1.

#include <iostream>
#include <locale>

using namespace std;

void Merge(double vet[], int inicio, int meio, int fim, int MaxTam); // Procedimento Merge responsável pela junção da primeira e
                                                                     // segunda parte do vetor. Ele receberá o vetor vet, e as
                                                                     // variáveis inicio, meio, fim e MaxTam.

void MergeSort(double vet[], int inicio, int fim, int MaxTam); // Procedimento MergeSort, que receberá o vetor vet e as
                                                               // variáveis inicio, fim e MaxTam

double DividirVetor(double vetor[], int comeco, int fim, int k); // Função responsável por dividir o vetor (sendo esquerda menor que o pivô e direita maior que pivô), retornar posição do pivô e
                                                                // recebe por parâmetro o vetor, começo do vetor, final do vetor.
void QuickSort(double vetor[], int esq, int dir, int k);// Procedimento para o método QuickSort.

void ChamadaPraQuick(double vetor[], int esq, int dir, int k); // Procedimento responsável por mostrar o vetor original do QuickSort e chamar o procedimento "QuickSort".

void InsertionSort(double vetor[], int maxTam); // Procedimento InsertionSort que recebe o vetor vet e a variável maxTam

void BubbleSort(double vetor[], int maxTam);// Procedimento de ordenação referente ao BubbleSort, recebendo o vetor e seu tamanho como parâmetro.

void SelectionSort(double vetor[], int maxTam);// Procedimento de ordenação referente ao SelectionSort, recebendo o vetor e seu tamanho como parâmetro.

void VetorVariavel(double VetDin[], int maxTam, int num); // Procedimento responsável por preencher o vetor(por entrada) e chamar a função referente a opção selecionada no menu.

void Menu(double VetDin[], int maxTam); // Procedimento que cria o menu para a seleção do método de ordenação desejado.

int main() // Função principal, onde será inicializado o programa.
{
    setlocale(LC_ALL, "Portuguese");
    // Declaração de variáveis para serem usadas em todo o programa.
    int maxTam;
    double VetDin[maxTam];

    Menu(VetDin, maxTam); // Chamada de procedimento Menu.

    return 0;
}

void Merge(double vet[], int inicio, int meio, int fim, int MaxTam)
{
    // Variáveis i, j e k declaradas para não ocorer alteração nas variáveis inicio, meio e fim,
    // que possibilitam a divisão
    int i = inicio; // Variável utilizada para perccorrer a primeira parte do vetor
    int j = meio + 1; // Variável utilizada para perccorrer a segunda parte do vetor
    int k = inicio; // Variável utilizada para o vetor auxiliar, declarado logo após
    int b = j; // Variável utilizada para auxiliar a mostrar a primeira parte do vetor na parte das comparações

    double aux[MaxTam]; // Declaração de um vetor auxiliar, onde serão copiados os elementos ordenados do vetor vet

    cout << "Comparando o primeiro elemento da primeira parte com o primeiro elemento da segunda parte: " << endl;

    // Laço de repetição que ocorre apenas se houver elementos na primeira e segunda parte
    while (i <= meio && j <= fim) {
        cout << "Primeira parte: ";
        // Laço de repetição que mostra a primeira parte do vetor
        for(int m = i; m < b; m++){
            cout << vet[m] << " ";
        }
        cout << endl;

        cout << "Segunda parte: ";
        // Laço de repetição que mostra a segunda parte do vetor
        for(int n = j; n <= fim; n++){
            cout << vet[n] << " ";
        }
        cout << endl << endl;
        cout << vet[i] << " < " << vet[j] << "?" << endl;
        if (vet[i] <= vet[j]) {
            cout << "SIM!" << endl << endl;
            aux[k] = vet[i]; // Vetor aux recebe o primeiro elemento da primeira parte, que é menor do que o primeiro elemento da seguda parte
            i++; // A posição i do vetor já foi comparada, o laço agora trabalhará com i + 1
        }
        else {
            cout << "NAO!" << endl << endl;
            aux[k] = vet[j]; // Vetor aux  recebe o primeiro elemento da segunda parte, que é menor do que o primeiro elemento da primeira parte
            j++; // A posição i do vetor já foi comparada, o laço agora trabalhará com i + 1
        }
        k++; // A posição k do vetor aux já foi preenchida, o laço agora trabalhará com k + 1
    }

    //Caso haja elementos restantes da primeira parte, ele serão copiados para o vetor auxiliar
    while (i <= meio) {
        aux[k] = vet[i];
        i++;
        k++;
    }

    //Caso haja elementos restantes da segunda parte, ele serão copiados para o vetor auxiliar
    while (j <= fim) {
        aux[k] = vet[j];
        j++;
        k++;
    }

    //Os elementos do vetor auxiliar são são copiados para o vetor original
    for (int p = inicio; p <= fim; p++) {
        vet[p] = aux[p];
        cout << vet[p] << " ";
    }

    cout << endl << endl;
}

/* inicio refere-se a posição da esquerda
e fim, a posição da direita das sublistas do
vetor a ser ordenado
*/

void MergeSort(double vet[], int inicio, int fim, int MaxTam)//MergeSort
{
    // Para que a divisão aconteça, o vetor precisa no mínimo de 2 elementos
    if (inicio < fim) {
        // calculando o meio
        int meio = (inicio + fim) / 2;

        cout << "Dividindo... " << endl;

        cout << "Primeira parte do vetor: " << endl;
        // Laço de repetição que mostra a primeira parte após a divisão
        for(int i = inicio; i <= meio; i++) {
            cout << vet[i] << "  ";
        }

        cout << endl;
        cout << "Segunda parte do vetor: " << endl;
        // Laço de repetição que mostra a segunda parte após a divisão
        for(int i = meio + 1; i <= fim; i++) {
            cout << vet[i] << "  ";
        }

        cout << endl << endl;

        MergeSort(vet, inicio, meio, MaxTam); // Chamada recursiva da função MergeSort para a primeira parte
        MergeSort(vet, meio + 1, fim, MaxTam); // Chamada recursiva da função MergeSort para a segunda parte

        Merge(vet, inicio, meio, fim, MaxTam); // Junção dos elementos da primeira e segunda parte

        cout << "Vetor com todos os elementos: ";
        // Laço de repetição que mostra o vetor com todos os elementos
        for (int i = 0; i < MaxTam; i++) {
            cout << vet[i] << " ";
        }
        cout << endl << endl;
    }
}

double DividirVetor(double vetor[], int comeco, int fim, int k)
{
    double pivo = vetor[fim];// Declarada variável pivô recebendo o item da ultima posição do vetor.
    double aux;             // Variável responsável por permitir a troca de valores dentro do vetor.
    int Indice = comeco;
     cout << "Para o pivo: " << pivo << endl;



       for(int i=0; i < k; i++)// Laço que imprime o vetor antes da alteração.
 {
     cout << vetor[i] << " ";
 }
 cout << endl;

  for( int i= comeco; i < fim; i++)// Laço de repetição que varre todo o vetor.
  {

      if(vetor[i] < pivo)// Caso o valor da posição do laço seja menor que o valor do pivô, entra na condição.
      {
          if(vetor[i] != vetor[Indice]){


          cout << "Pega o " << vetor[i] << " e troca pelo " << vetor[Indice] << endl;
          }
          aux = vetor[i];       // Troca dos valores utilizando a variável aux como intermediadora.
          vetor[i] = vetor[Indice];
          vetor[Indice] = aux;
          Indice++;
      }




  }

        aux = vetor[fim];  // Realocando o pivô para sua devida posição.
        vetor[fim] = vetor[Indice];
        vetor[Indice] = aux;
        if(vetor[fim] != vetor[Indice])
        {


        cout << "Realocando o pivo [" << vetor[Indice] << "] para seu lugar. " << endl;
        }

        else
        {
            cout << "Pivo já está na sua respectiva posição!" << endl;
        }
                         for(int i=0; i<k; i++)// Laço que imprime o vetor depois da alteração.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

        return Indice;// retorna posição do pivô.
}

void QuickSort(double vetor[], int esq, int dir, int k)//QuickSort
{
    double pivo;// Declaração da variável que será usada para armazenar a posição do vetor
                // que estiver o valor do pivô.
    if(esq < dir)// Condição para a execução apenas se o valor do início for menor que o
    {           // do final do vetor, sendo ele particionado ou não.
       pivo = DividirVetor(vetor, esq, dir, k);// A função armazena na variável pivô o valor da posição do pivô retornado por ela.

       QuickSort(vetor, esq, pivo-1, k);// Chamada recursiva, porém alterando os valores dos parâmetros e considerando apenas os valores do começo até uma posição a menos do pivô.
       QuickSort(vetor, pivo+1, dir, k);// Chamada recursiva com valores de parâmetros alterados considerando apenas valores
    }                                   // de uma posição a mais do pivô até o final do vetor.

}

void ChamadaPraQuick(double vetor[], int esq, int dir, int k)
{
    cout << "############### QuickSort ###############" << endl;
    cout << "=========== VETOR ORIGINAL ===========" << endl;

    for(int i=0; i < k; i++)// Laço de repetição que imprime o vetor em seu estado original, ou seja,
    {                       //   antes das alterações.
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "=========== Operações ===========" << endl;
    QuickSort(vetor, 0, (dir - 1), k);//   antes das alterações.
}

void InsertionSort(double vetor[], int maxTam)//InsertionSort
{
    int aux; //Declaração da variável aux de "auxiliar", ela armazenará temporariamente valores
             //durante a execução da ordenação por Insertion Sort.

    cout << "############### InsertionSort ###############" << endl;

    cout << "=========== VETOR ORIGINAL ===========" << endl;
    for(int i=0; i < maxTam; i++) //Laço de repetição que mostra os elementos do vetor na sua forma original.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "=========== Operações ===========" << endl;
    for(int i=0; i < maxTam -1; i++) //Laço de repetição exterior que refere-se a parte ordenada do vetor, que
                                     //começa com o primeiro elemento.
    {
        for(int j= i+1; j>0; j--) //Laço de repetição interior que refere-se a parte desordenada do vetor, que
                                  //começa com o segundo elemento.
        {
            if(vetor[j]< vetor[j-1]) //A troca só será realizada se o vetor da parte desordenada for menor que
                                     //o da parte ordenada.
            {
                aux = vetor[j]; //Variável aux recebe temporariamente o elemento da posição j.
                vetor[j] = vetor[j-1];//O maior elemento vai para a posição onde estava o elemento da posição j.
                vetor[j-1] = aux;//O vetor na posição anterior a de j recebe o que está dentro da variável aux.

                cout << "Troca do [" << vetor[j] << "] pelo [" << vetor[j-1] << "]: " << endl; // Imprime os valores que foram trocados na iteração.

                for(int i=0; i < maxTam; i++)//Laço de repetição que mostra todos os passos do InsertionSort.
                {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                cout << endl;
            }
        }
    }

    cout << "=========== VETOR APÓS OPERAÇÕES ===========" << endl;

    for(int i=0; i < maxTam; i++)//Laço de repetição que mostra o vetor ordenado pelo InsertionSort
    {
        cout << vetor[i] << " ";
    }

    cout << endl;
}

void BubbleSort(double vetor[], int maxTam)//BubbleSort
{
   double aux; // variável responsável por possibilitar a troca de dois valores do vetor.

    cout << "############### BubbleSort ###############" << endl;
    cout << "=========== VETOR ORIGINAL ===========" << endl;

    for(int i=0; i < maxTam; i++) // Laço responsável por imprimir na tela o vetor original,
    {                              //sendo por atribuição ou por entrada de dados.
        cout << vetor[i] << " ";
    }

    cout << endl;

    cout << "=========== Operações ===========" << endl;

    for(int i= 0; i< maxTam; i++)   // Laço externo responsável por percorrer todo o vetor.
    {
        for(int j=0; j< maxTam -1; j++) // Laço interno responsável pelas comparações.
        {
            if(vetor[j] > vetor[j+1])// Comparação do elemento presente na posição "J" para verificar se ele é maior que
                                    // o elemento "J + 1".
                {
                    aux = vetor[j]; // A varialvel aux armazena  temporariamente o elemento presente na posição "J".
                    vetor[j] = vetor[j+1]; // Vetor[j] recebe o elemento presente na posição "J +1".
                    vetor[j+1] = aux; // Vetor[ j + 1] recebe o elemento que estava presente na posição " J " e faz a troca de elementos.

                    cout << "Troca do [" << vetor[j] << "] pelo [" << vetor[j+1] << "]: " << endl; // Informando os elementos que estão sendo trocados na interação.

                    for(int i=0; i < maxTam; i++) // Laço de repetição para mostrar todos os passos de troca do algoritmo de ordenação.
                    {
                        cout << vetor[i] << " ";
                    }

                    cout << endl;
                    cout << endl;
                }
        }
    }

    cout << "=========== VETOR APÓS OPERAÇÕES ===========" << endl;

    for(int i=0; i < maxTam; i++) // Laço de repetição para mostrar os elementos completamente ordenados  pelo BubbleSort.
    {
        cout << vetor[i] << " ";
    }

    cout << endl;
}

void SelectionSort(double vetor[], int maxTam)
{
   double menor;  // Variável responsavel para armazenar o menor elemento do vetor.
    int posicao;  // Variável responsavel para armazenar a posição do menor elemento do vetor.
    bool troca;  // Variável de troca (verdadeira ou falsa).
    double aux; // variável responsável por possibilitar a troca de dois valores do vetor.

    cout << "############### SelectionSort ###############" << endl;
    cout << "=========== VETOR ORIGINAL ===========" << endl;

    for(int i=0; i < maxTam; i++) // Laço responsável por imprimir na tela o vetor original,
                                 //sendo por atribuição ou por entrada de dados.
    {
        cout << vetor[i] << " ";
    }
    cout << endl; // Quebra de linha.

    cout << "=========== Operações ===========" << endl;
    for(int i=0; i< maxTam -1; i++)
    {
        menor = vetor[i];  // Variável "menor" esta recebendo o menor elemento do vetor.
        posicao = i;      // Variável "Posição" esta recebendo o menor elemento do vetor.
        troca = false;   //  Troca está recebendo falso.

        for(int j= i+1; j< maxTam; j++)
        {
            if(vetor[j] < menor)  // Se o elemento da posição "j" for menor que o elemento guardado no  "menor"  então faz a troca.
            {
                menor = vetor[j]; // Caso o elemento "j" seja menor, irá atualizar o indice e passar "j" como menor elemento.
                posicao = j;     // Elemento da posição "J" foi armazenado na variável posição.
                troca = true;   // Troca foi realizada.
            }
        }

        for (int i=0; i< maxTam; i++) // Laço de repetição responsavél por percorrer o vetor.
        {
            cout << vetor[i] << " ";

        }

        cout <<  endl; // Quebra de linha.

        if (vetor[i] != vetor[posicao]) // Comparação dos elementos na posição "i" para ver se é diferente que o vetor "posição".
{

    cout << "Troca do [" << vetor[i] << "] pelo [" << vetor[posicao] << "]: " << endl; // Informando os elementos que estão sendo trocados na interação.
}
else
{
    cout << "[" << vetor[i] << "] e [" << vetor[posicao] << "] são iguais, mantém!! " << endl; // Informando os elementos que são iguais na interação.
}

        if (troca)
        {
            aux = vetor[i]; // Variável aux recebeu temporariamente o elemento da posição "I".
            vetor[i] = menor; // Vetor[i] recebe o menor elemento.
            vetor[posicao] = aux; // vetor[posicao] troca de valor com  a variável aux.
        }
    }

    cout << "=========== VETOR APÓS OPERAÇÕES ===========" << endl;

    for(int i=0; i< maxTam; i++) // Laço de repetição para mostrar os elementos completamente ordenados pelo algoritmo SelectionSort.
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void VetorVariavel(double VetDin[], int maxTam, int num) // Procedimento para preencher o vetor de tamanho variável de acordo com a entrada do tamanho máximo.
{
    for(int i=0; i< maxTam; i++) // Laço para preencher o vetor por entrada.
    {
        cout << "Digite o " << i+1 << "º número: ";
        cin >> VetDin[i];
    }
    cout << endl;

    if(num == 1)// Condicional necessária para ordenação de acordo com o solicitado no menu, passado por parâmetro pela variável "num".
    {
      InsertionSort(VetDin, maxTam);
    }
        else if(num == 2)
        {
            SelectionSort(VetDin, maxTam);
        }
        else if(num == 3)
        {
            BubbleSort(VetDin, maxTam);
        }
        else if(num == 4)
        {
            ChamadaPraQuick(VetDin, 0, maxTam, maxTam);
        }
        else if(num == 5)
        {
            cout << "############### MergeSort ###############" << endl;

            cout << "=========== VETOR ORIGINAL ===========" << endl;
            for(int i=0; i < maxTam; i++)
            {
                cout << VetDin[i] << " ";
            }
            cout << endl << endl;
            cout << "=========== Operações ===========" << endl;
            MergeSort(VetDin, 0, maxTam -1, maxTam);
        }
}

void Menu(double VetDin[], int maxTam)
{
    char entrar;

    cout << "|-------------------- Seja bem-vindo(a) ao algoritmo de ordenação --------------------|" << endl;

    cout << "Deseja entrar no menu de opções? (s/n): ";// Entrada de valor responsável pela iniciação ou não no laço while.
    cin >> entrar;

    while (entrar == 's' || entrar == 'S')
    {
        double numeros[10]= {3.2, 2, 5, 1, 10, 9, 7, 3, 4, 11};// Declaração do vetor por atribuição com seus valores já pré definidos.
        int botao2;// Declaração de variáveis para a entrada no menu.
        char botao1;// Declaração de variáveis para a entrada no menu.

        cout << "========== Bem-Vindo(a) ao menu ==========" << endl;//Cardápio de opções para que o usuário possa escolher.
        cout << "[A] - Vetor por atribuição." << endl;
        cout << "[B] - Vetor por entrada." << endl;
        cout << "Selecione uma letra: ";
        cin >> botao1; // Entrada do valor para seleção entre (A ou B).
        cout << "[1] - InsertionSort." << endl;
        cout << "[2] - SelectionSort." << endl;
        cout << "[3] - BubbleSort."  << endl;
        cout << "[4] - QuickSort."  << endl;
        cout << "[5] - MergeSort." << endl;
        cout << "Selecione uma opção: ";
        cin >> botao2;// Entrada do valor para seleção entre (1, 2, 3, 4 ou 5).

        if(botao2 == 1 && (botao1 == 'a'|| botao1 == 'A') )// Condições para executar o tipo de Algoritmo de ordenação
        {                                                   // de acordo com o valor da entrada mostrada no cardápio de opções.
            InsertionSort(numeros, 10);// Chama o procedimento InsertionSort para o vetor preenchido por atribuição.
        }
        else if(botao2 == 1 && (botao1 == 'b'|| botao1 == 'B') )
        {
            cout << "Digite o tamanho do vetor: ";
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 1);// Chamada da função que preenche o vetor por entrada.
        }
        else if(botao2 == 2 && (botao1 == 'a'|| botao1 == 'A') )
        {
            SelectionSort(numeros, 10);// Chama o procedimento SelectionSort para o vetor preenchido por atribuição.
        }
        else if(botao2 == 2 && (botao1 == 'b'|| botao1 == 'B') )
        {
            cout << "Digite o tamanho do vetor: ";
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 2);// Chamada da função que preenche o vetor por entrada.
        }
        else if(botao2 == 3 && (botao1 == 'a'|| botao1 == 'A') )
        {
            BubbleSort(numeros, 10);// Chama o procedimento BubbleSort para o vetor preenchido por atribuição.
        }
        else if(botao2 == 3 && (botao1 == 'b'|| botao1 == 'B') )
        {
            cout << "Digite o tamanho do vetor: ";
            cin >> maxTam;
            VetorVariavel(VetDin,maxTam, 3);// Chamada da função que preenche o vetor por entrada.
        }


        else if(botao2 == 4 && (botao1 == 'a'|| botao1 == 'A') )
    {
        ChamadaPraQuick(numeros, 0, 10, 10);// Chama o procedimento ChamadaPraQuick para o vetor preenchido por atribuição.
    cout << "=========== VETOR ORDENADO ===========" << endl;
        for(int i=0; i<10; i++)// Imprime o vetor já ordenado.
    {
        cout << numeros[i] << " ";
    }
    cout << endl;

    }

    else if(botao2 == 4 && (botao1 == 'b'|| botao1 == 'B'))
    {
        cout << "Digite o tamanho do vetor: ";// Entrada do valor referente ao tamanho do vetor.
        cin >> maxTam;
        VetorVariavel(VetDin,maxTam, 4);// Chamada da função que preenche o vetor por entrada.

        cout << "=========== VETOR ORDENADO ===========" << endl;

        for (int i=0; i<maxTam; i++)// Imprime o vetor já ordenado.
        {
            cout << VetDin[i] << " ";

        }

        cout << endl;
    }
        else if(botao2 == 5 && (botao1 == 'a' || botao1 == 'A'))
        {
            cout << "############### MergeSort ###############" << endl;

            cout << "=========== VETOR ORIGINAL ===========" << endl;
            for(int i=0; i < 10; i++)//Imprime o vetor Original.
            {
                cout << numeros[i] << " ";
            }
            cout << endl;
            cout << "=========== Operações ===========" << endl;

            MergeSort(numeros, 0, 9, 10);// Chama o procedimento MergeSort.

            cout << "=========== VETOR ORDENADO ===========" << endl; // Imprime o vetor já ordenado.
            for(int i=0; i< 10; i++)
            {
                cout << numeros[i] << " ";
            }
            cout << endl;

        }
        else if(botao2 == 5 && (botao1 == 'b' || botao1 == 'B'))
        {
            cout << "Digite o tamanho do vetor: "; // Entrada do valor referente ao tamanho do vetor.
            cin >> maxTam;

            VetorVariavel(VetDin,maxTam, 5); // Chamada da função que preenche o vetor por entrada.

            cout << "=========== VETOR ORDENADO ===========" << endl;
            for(int i=0; i< maxTam; i++)// Laço para mostrar o vetor após ser ordenado pelo MergeSort.
            {
                cout << VetDin[i] << " ";
            }
            cout << endl;

        }

    cout << "Deseja retornar ao menu? (s/n): ";// Entrada do valor que irá satisfazer ou não a condição do
    cin >> entrar;                              // while que ela está inclusa.
    }
}
