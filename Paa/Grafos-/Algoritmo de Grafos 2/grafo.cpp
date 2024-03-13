#include <iostream>
#include <vector>


using namespace std;

// Função para inserir vértices na lista de adjacências
void insert(vector<int> adj[], int u, int v){
//Insere um vértice v no vértice u
	adj[u].push_back(v);
	return;
}

// Função para exibir a lista de adjacências
void printList(vector<int> adj[], int V){
	for (int i = 0; i < V; i++) {
		cout << i;
		for (auto j : adj[i])
			cout << " --> " << j;
		cout << endl;
	}
	cout << endl;
}

// Função para converter adjacência lista para matriz de adjacência
vector<vector<int> > convert(vector<int> adj[], int V){
// Inicializa uma matriz de numeros 1
	vector<vector<int> > matrix(V, vector<int>(V, 0));

	for (int i = 0; i < V; i++) {
		for (auto j : adj[i])
			matrix[i][j] = 1;
	}
	return matrix;
}


// Função para exibir a matriz de adjacência
void printMatrix(vector<vector<int> > adj, int V){
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
//------------------------------------------------------------------------------

struct graph{
    // vertices
    int v;
    // Arestas
    int e;

    // Direção do vertice de origem ao vertice de destino
    int **dir;
};

// Retorna o Grau do vértice desejado
/*
        Para o vértice dado, verifique se existe um caminho deste vértice para
        outro então incrementar o grau
*/

int encontraGrau(struct graph *G, int ver){

    // todas as células conectadas (com valor 1)
    int degree = 0;
    for (int i=0; i<G->v; i++)

        //A contage dos graus acontece quando é encontrado o valor 1 nos
        //vertices conectados.
        if (G-> dir[ver][i] == 1)
            degree++;

        // a linha abaixo é para levar em conta o auto loop no gráfico
     // verifica a soma dos graus no teorema do grafo
    if(G-> dir[ver][ver] == 1)
          degree++;
    return degree;
}

struct graph *createGraph(vector<vector<int> > adj, int v, int e){

    //Definindo G como ponteiro do grafo
    struct graph *G = new graph;

    G->v = v;
    G->e = e;

    // Reservando memoria
    G->dir = new int*[v];

    for (int i = 0;i < v;i++)
        G->dir[i] = new int[v];



	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			G->dir[i][j]= adj[i][j];
		}
	}

    return G;

}

//------------------------------------------------------------------------------

int main(){
//------------------------------------------------------------------------------
    //Declaração de variáveis
    int V, a, numeroAresta;
    numeroAresta = 0;
    cout << "Informe a quantidade de vertices:" << endl;
    cin >> V; // v siguinifica vértices
    cout << endl << "Digite 1 se sim, ou 0 se nao possui aresta:" << endl;
	vector<int> adjList[V];

    for(int l=0;l<V;l++){
        for(int c=0;c<V;c++){
            cout << "Possui aresta na posicao: " << l << " , " << c << endl;
            cin >> a;
                if(a==1){
            insert(adjList, l, c);
            insert(adjList, c, l);
            numeroAresta++;
                }
        }
    }

    system("cls || clear");
// Chamada de função que retorna a matriz de adjacência após a conversão
	vector<vector<int> > adjMatrix = convert(adjList, V);



//------------------------------------------------------------------------------

    int vertices = V;
    int edges = numeroAresta;
    struct graph *G = createGraph(adjMatrix, vertices, edges);

    // loc is find the degree of
    // particular vertex


    int opcao;

    do{
        cout<<"--------------GRAFOS-MENU----------------"<< endl;
        cout<<"1. Matriz de Adjacencia:"<< endl;
        cout<<"2. Lista de Adjacencia:" << endl;
        cout<<"3. Grau do vertice:"<< endl;
        cout<<"4. Grau Maximo e Minimo"<< endl;
        cout<<"0. Sair"<< endl;
        cout<<" Escolha uma opcao que deseja executar."<< endl;

    cin >> opcao;
    system("cls || clear"); // Para limpar a tela
    switch(opcao){
        case 1:
        {
	    cout << "Matriz de adjacencia: " << endl;
	    printMatrix(adjMatrix, V);;
        break; // Para nao executar mais nada neste ciclo
        }
        case 2:
        {
    	cout << "Matriz de adjacencia "  << endl;
	    printList(adjList, V);
        break;
        }
        case 3:
        {
        cout << "Informe qual vertice deseja saber o Grau:" << endl;
        int grau;
        cin >> grau;
        int ver = grau;
        int degree = encontraGrau(G, ver);
        cout << "O Grau do Vertice: " << ver << " = " << degree << endl;
        cout << "Entao o Vertice: " << ver << " tem " << degree <<
        " Arestas!" << endl;

        break;
        }
        case 4:
        {
        int vet[V], i, maior, qualVert = 0, menor, qualVertice = 0;
        for(i=0;i<V;i++){
            vet[i] = encontraGrau(G, i);
        }
        maior = vet[0];
        for(i=1;i<V;i++){
            if(vet[i] > maior){
                maior = vet[i];
                qualVert = i;
            }
        }

        menor = vet[0];
        for(i=1;i<V;i++){
            if(vet[i] < menor){
                menor = vet[i];
                qualVertice = i;
            }
        }

            cout << " O vertice: " << qualVert << ", tem o maior Grau! Com: "
            << maior << " arestas" << endl;
            cout << " O vertice: " << qualVertice << ", tem o menor Grau! Com: "
            << menor << " arestas" << endl;


        break;
        }
        case 0:
        {
        break;
        }
        default:
        cout<<"O valor inserido nao e valido."<<endl;
        break;
        } // Fecho do switch
        }while(opcao!=0); // fecho do ciclo "do" com condição while.


//------------------------------------------------------------------------------
	return 0;
}
