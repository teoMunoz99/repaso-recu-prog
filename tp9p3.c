#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Declaracion de estructuras

// cliente
struct
{
    char razon_social[50];
    char tel[50];
} typedef tcliente;

// pedidos
struct {
    tcliente cliente;
    char vende[50];
    int cantidad;
} typedef tpedidos;

// especie
struct {
    char ncientifico[30];
    char categoria;  // c,p,o,f
    char nvulgar[30];
} typedef tespecie;
// arbol
struct {
    tespecie especie;
    int cantidad;
    float precio;
    tpedidos *pedidos;
    int cantPedidos;
} typedef arbol;

// funciones
void cargarArboles(arbol *arre, int cant);
void mostrarArboles(arbol *arre, int cant);
// void mostrarSegunStock(arbol *arre, int cant);
void mostrarPedidos(arbol *arre, int cant);
void agregarPedidos(arbol *arre, int cant);
// void actualizarStock(arbol *arre, int cant);
// void actualizarPrecio(arbol *arre, int cant);
void liberarMemoria(arbol *arre, int cant);

int main() {
    arbol *parbol;
    int cantidad, op;
    // printf("Ingrese la cantidad de arboles a cargar: ");
    // scanf("%d", &cantidad);
    // parbol = (arbol *)malloc(cantidad * sizeof(arbol));
    // cargarArboles(parbol, cantidad);

    tpedidos *p3, *p7, *p10;
    tpedidos pedido3[] = {
        {{"SRL1", "4395942"}, "vendedor1", 5},
        {{"SRL2", "4395943"}, "vendedor2", 3},
        {{"SRL3", "4395944"}, "vendedor3", 5}};
    tpedidos pedido7[] = {
        {{"SRL4", "4395942"}, "vendedor4", 4},
        {{"SRL5", "4395943"}, "vendedor5", 3}};
    tpedidos pedido10[] = {
        {{"SRL6", "4395942"}, "vendedor6", 2},
        {{"SRL7", "4395943"}, "vendedor7", 2},
        {{"SRL8", "4395942"}, "vendedor8", 3},
        {{"SRL9", "4395943"}, "vendedor9", 4},
    };
    p3 = pedido3;
    p7 = pedido7;
    p10 = pedido10;
    arbol arboles[] = {
        {{"Cientifico1", 'c', "arce rojo"}, 7, 5200.0, NULL, 0},
        {{"Cientifico2", 'c', "naranjo"}, 20, 3200.0, NULL, 0},
        {{"Cientifico3", 'c', "aromo"}, 20, 5000.0, p3, 3},
        {{"Cientifico4", 'c', "mango"}, 9, 7200.0, NULL, 0},
        {{"Cientifico5", 'c', "abeto"}, 30, 6200.0, NULL, 0},
        {{"Cientifico6", 'c', "acacia"}, 26, 8700.0, NULL, 0},
        {{"Cientifico7", 'c', "pino"}, 18, 6200.0, p7, 2},
        {{"Cientifico8", 'c', "encina"}, 25, 7200.0, NULL, 0},
        {{"Cientifico9", 'c', "araucaria"}, 8, 4800.0, NULL, 0},
        {{"Cientifico10", 'c', "araucaria"}, 20, 2000.0, p10, 4},
        {{"Cientifico11", 'c', "araucaria"}, 30, 5700.0, NULL, 0},
        {{"Cientifico12", 'p', "olivo"}, 30, 7200.0, NULL, 0},
    };
    parbol = arboles;
    cantidad = 12;
    do {
        printf("\n\n=============MENU============\n");
        printf("1- Mostrar todos los arboles \n");
        printf("2- Mostrar arboles segun stock \n");
        printf("3- Mostrar todos los pedidos \n");
        printf("4- Agregar pedidos a una especie \n");
        printf("5- Actualizar stock de una especie \n");
        printf("6- Actualizar el precio de una especie \n");
        printf("7- Salir \n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                mostrarArboles(parbol, cantidad);
                break;
            case 2:
                // mostrarSegunStock(parbol, cantidad);
                break;
            case 3:
                mostrarPedidos(parbol, cantidad);
                break;
            case 4:
                agregarPedidos(parbol, cantidad);
                break;
            case 5:
                // actualizarStock(parbol, cantidad);
                break;
            case 6:
                // actualizarPrecio(parbol, cantidad);
                break;
            case 7:
                return 0;
                break;
            default:
                break;
        }
    } while (op != 7);
    liberarMemoria(parbol, cantidad);
    return 0;
}

void cargarArboles(arbol *arre, int cant) {
    printf("\n==========CARGA DE ARBOLES=========\n");

    for (int i = 0; i < cant; i++) {
        printf("\n\n===ARBOL %d===\n", i + 1);
        fflush(stdin);
        printf("Ingrese nombre cientifico: ");
        gets(arre->especie.ncientifico);
        fflush(stdin);
        do {
            printf("Ingrese la categoria(c: caduca, p:perenne, o: conifera, f:frutal): ");
            scanf("%c", &arre->especie.categoria);
            fflush(stdin);
        } while (arre->especie.categoria != 'c' && arre->especie.categoria != 'p' && arre->especie.categoria != 'o' && arre->especie.categoria != 'f');

        printf("\nIngrese el nombre vulgar: ");
        gets(arre->especie.nvulgar);

        printf("\nIngrese el stock: ");
        scanf("%d", &arre->cantidad);

        printf("\nIngrese el precio: ");
        scanf("%f", &arre->precio);

        arre->cantPedidos = 0;
        arre->pedidos = NULL;
        arre++;
    }
}

void mostrarArboles(arbol *arre, int cant) {
    printf("\n\n=============MOSTRAR ARBOLES=============\n");
    for (int i = 0; i < cant; i++) {
        printf("\n");
        printf("---Arbol: %d---\n", i + 1);
        printf("Especie: %s\n", arre->especie.ncientifico);
        switch (arre->especie.categoria) {
            case 'c':
                printf("Categoria: Caduca\n");
                break;
            case 'p':
                printf("Categoria: Perenne\n");
                break;
            case 'o':
                printf("Categoria: Conifera\n");
                break;
            case 'f':
                printf("Categoria: Frutal\n");
                break;
            default:
                break;
        }
        printf("Nombre vulgar: %s\n", arre->especie.nvulgar);
        printf("Stock: %d\n", arre->cantidad);
        printf("Precio: $%2.f\n", arre->precio);
        if (arre->pedidos != NULL) {
            for (int j = 0; j < arre->cantPedidos; j++) {
                printf("Cliente: %s - Tel: %s - Cantidad: %d\n", arre->pedidos[j].cliente.razon_social, arre->pedidos[j].cliente.tel, arre->pedidos[j].cantidad);
                printf("Vendedor: %s \n", arre->pedidos[j].vende);
            }
        } else {
            printf("No hay pedidos de: %s \n", arre->especie.nvulgar);
        }
        arre++;
    }
}

/*void mostrarSegunStock(arbol *arre, int cant) {
    int cStock;
    printf("Ingrese el num de stock: \n");
    scanf("%d", &cStock);
    for (int i = 0; i < cant; i++) {
        if (arre->stock < cStock) {
            printf("Especie: %s\n", arre->especie.nespecie);
            printf("Nombre: %s\n", arre->especie.nombreVulgar);
        }
        arre++;
    }
}*/

void mostrarPedidos(arbol *arre, int cant) {
    float total;
    printf("\n\n============MOSTRAR PEDIDOS============\n");
    for (int i = 0; i < cant; i++) {
        if (arre->pedidos != NULL) {
            printf("==> Especie: %s \n", arre->especie.ncientifico);
            for (int j = 0; j < arre->cantPedidos; j++) {
                total = arre->pedidos[j].cantidad * arre->precio;
                printf("Razon Social: %s \n", arre->pedidos[j].cliente.razon_social);
                printf("Cant: %d \n", arre->pedidos[j].cantidad);
                printf("Total: $%2.f \n", total);
            }
        }
        arre++;
    }
}

void agregarPedidos(arbol *arre, int cant) {
    int especie, num, suma_adentro = 0, pretende, carga = 1;
    printf("\n==========AGREGAR PEDIDOS==========\n\n");
    printf("Elija la especie para cargar pedidos: ");
    int e;
    for (int i = 0; i < cant; i++) {
        printf("\n%d- %s ", i, arre[i].especie.ncientifico);
    }
    scanf("%d", &e);
    if (arre[e].pedidos == NULL) {
        printf("Ingrese la cantidad de pedidos a cargar en: %s\n", arre[e].especie.ncientifico);
        int cp;
        scanf("%d", &cp);
        arre[e].cantPedidos += cp;
        arre[e].pedidos = (tpedidos *)malloc(cp * sizeof(tpedidos));
        for (int i = 0; i < cp; i++) {
            if (arre[e].cantidad > 0) {
                printf("Pedido: %d\n", i + 1);
                printf("\n\nIngrese la razon social: ");
                fflush(stdin);
                gets(arre[e].pedidos[i].cliente.razon_social);
                printf("Ingrese el tel del cliente: ");
                fflush(stdin);
                gets(arre[e].pedidos[i].cliente.tel);
                printf("Ingrese el nombre del vendedor: ");
                fflush(stdin);
                gets(arre[e].pedidos[i].vende);
                do {
                    printf("Ingrese la cantidad a pedir:\n");
                    scanf("%d", &pretende);
                    if (arre[e].cantidad - (pretende + suma_adentro) > 0) {
                        arre[e].pedidos[i].cantidad = pretende;
                        suma_adentro += pretende;
                    } else {
                        printf("Supera el stock disponible de: %d unidades\n", arre[e].cantidad - suma_adentro);
                        carga = 0;
                    }
                } while (carga == 0);
            }
        }
    } else {
        printf("Ya hay pedidos pendientes**\n");
    }
}

// void actualizarStock(arbol *arre, int cant) {}
// void actualizarPrecio(arbol *arre, int cant) {}
void liberarMemoria(arbol *arre, int cant) {
    for (int i = 0; i < cant; i++) {
        if (arre->pedidos != NULL) {
            free(arre->pedidos);
        }
        arre++;
    }
    free(arre);
}