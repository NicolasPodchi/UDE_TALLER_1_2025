typedef struct
{
    strDinamico id;
    int minimosParametros;
    int maximoParametros;

} comando;

////

typedef struct nodoL
{
    comando e;
    nodoL * sig;
} nodoListaComando;

typedef nodoListaComando * listaComando;