#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Declaracion de estructuras

// cliente
struct
{
    char razon_social[50];
    char telefono[50];
} typedef tcliente;

// pedidos
struct {
    tcliente cliente;
    char vendedor[50];
    int cantidad;
} typedef tpedidos;

// especie
struct {
    char ncientifico[50];
    char categoria;
    char nvulgar[50];
} typedef tespecie;
// arbol
struct {
    tespecie especie;
    int stock;
    float precio;
    int canPedidos;
    tpedidos *pedidos;
} typedef arbol;

// funciones
void cargarArboles(arbol *arre, int cant);
void mostrarArboles(arbol *arre, int cant);
void mostrarSegunStock(arbol *arre, int cant);
void mostrarPedidos(arbol *arre, int cant);
void agregarPedidos(arbol *arre, int cant);
void actualizarStock(arbol *arre, int cant);
void actualizarPrecio(arbol *arre, int cant);
void liberarMemoria(arbol *arre, int cant);

int main() {
    int op, cantidad;
    arbol *parbol;
    printf("\nIngrese la cantidad de arboles a cargar: ");
    scanf("%d", &cantidad);
    parbol = (arbol*)malloc(cantidad * sizeof(arbol));
    cargarArboles(parbol, cantidad);

    //___________Datos prueba_________________

    //tpedidos *p1, *p2, *p3;
    //tpedidos pedido1[] = {
    //    {{"Cliente1 SRL", "4360371"}, "Vendedor1", 3},
    //    {{"Cliente2 SRL", "4360372"}, "Vendedor1", 2},
    //    {{"Cliente3 SRL", "4360373"}, "Vendedor1", 4},
    //};
    //tpedidos pedido2[] = {
    //    {{"Cliente4 SRL", "4360371"}, "Vendedor2", 5},
    //    {{"Cliente5 SRL", "4360372"}, "Vendedor2", 1},
    //    {{"Cliente6 SRL", "4360373"}, "Vendedor2", 6},
    //    {{"Cliente7 SRL", "4360373"}, "Vendedor2", 9},
    //};
    //tpedidos pedido3[] = {
    //    {{"Cliente8 SRL", "4360371"}, "Vendedor3", 1},
    //    {{"Cliente9 SRL", "4360372"}, "Vendedor3", 2},
    //};
    //p1 = pedido1;
    //p2 = pedido2;
    //p3 = pedido3;
    //arbol arboles[] = {
    //    {{"Quercus", 'c', "Roble"}, 35, 6500, 0, NULL},
    //    {{"Pinus", 'o', "Pino"}, 50, 7200, 0, NULL},
    //    {{"Cedrus", 'p', "Cedro"}, 45, 8000, 3, p3},
    //    {{"Salix", 'f', "Sauce"}, 38, 6800, 0, NULL},
    //    {{"Populus", 'c', "Alamo"}, 42, 7400, 0, NULL},
    //    {{"Olea", 'o', "Olivo"}, 48, 7700, 4, p2},
    //    {{"Abies", 'p', "Abeto"}, 55, 8500, 0, NULL},
    //    {{"Acacia", 'f', "Acacia"}, 37, 6700, 0, NULL},
    //    {{"Carpinus", 'c', "Haya"}, 41, 7300, 0, NULL},
    //    {{"Cupressus", 'o', "Cipres"}, 47, 7900, 2, p3},
    //    {{"Castanea", 'p', "Castanio"}, 53, 8200, 0, NULL},
    //    {{"Fraxinus", 'f', "Fresno"}, 39, 7000, 0, NULL},
    //    {{"Populus", 'c', "Chopo"}, 43, 7600, 0, NULL},
    //    {{"Arecaceae", 'o', "Palma"}, 49, 7800, 0, NULL},
    //    {{"Eucalyptus", 'p', "Eucalipto"}, 52, 8100, 0, NULL},
    //    {{"Juglans", 'f', "Nogal"}, 36, 6600, 0, NULL}};
    //parbol = arboles;
    //cantidad = 16;

    //________________________________________

    do {
        printf("\n\n=============MENU============\n\n");
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
                mostrarSegunStock(parbol, cantidad);
                break;
            case 3:
                mostrarPedidos(parbol, cantidad);
                break;
            case 4:
                agregarPedidos(parbol, cantidad);
                break;
            case 5:
                actualizarStock(parbol, cantidad);
                break;
            case 6:
                actualizarPrecio(parbol, cantidad);
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
    printf("\n\n----------CARGAR ARBOLES----------\n");
    for (int i = 0; i < cant; i++) {
        printf("\n------Arbol n: %d-------\n", i + 1);
        printf("\nNombre cientifico: ");
        fflush(stdin);
        gets(arre->especie.ncientifico);
        printf("\nCategoria(c-o-p-f): ");
        scanf("%c", &arre->especie.categoria);
        printf("\nNombre vulgar: ");
        fflush(stdin);
        gets(arre->especie.nvulgar);
        printf("\nIngrese el stock: ");
        scanf("%d", &arre->stock);
        printf("\nIngrese el precio: ");
        scanf("%f", &arre->precio);
        arre->canPedidos = 0;
        arre->pedidos = NULL;
    }
    printf("\n\n---------- ----------\n");
}

void mostrarArboles(arbol *arre, int cant) {
    printf("\n\n----------MOSTRAR ARBOLES----------\n\n");

    for (int i = 0; i < cant; i++) {
        printf("\n---Arbol: %d---\n", i + 1);
        printf("Nombre cientifico: %s\n", arre->especie.ncientifico);
        printf("Categoria: %c\n", arre->especie.categoria);
        printf("Nombre vulgar: %s\n", arre->especie.nvulgar);
        printf("Stock: %d\n", arre->stock);
        printf("Precio: $%2.f\n", arre->precio);
        if (arre->pedidos != NULL) {
            printf("------PEDIDOS------\n");
            for (int j = 0; j < arre->canPedidos; j++) {
                printf("Razon social: %s - Tel: %s\n", arre->pedidos[j].cliente.razon_social, arre->pedidos[j].cliente.telefono);
                printf("Vendedor: %s\n", arre->pedidos[j].vendedor);
                printf("Cant de pedidos: %d\n", arre->pedidos[j].cantidad);
                printf("--------------\n");
            }
        }
        printf("----------------\n");
        arre++;
    }
    printf("\n---------------------\n");
}

void mostrarSegunStock(arbol *arre, int cant) {
    int cantidad;
    printf("\n\n----------MOSTRAR SEGUN STOCK----------\n\n");
    printf("Ingrese el stock para ver: ");
    scanf("%d", &cantidad);
    for (int i = 0; i < cant; i++) {
        if (arre->stock <= cantidad) {
            printf("\n---Arbol: %d---\n", i + 1);
            printf("Nombre cientifico: %s\n", arre->especie.ncientifico);
            printf("Categoria: %c\n", arre->especie.categoria);
            printf("Nombre vulgar: %s\n", arre->especie.nvulgar);
            printf("Stock: %d\n", arre->stock);
            printf("Precio: $%2.f\n", arre->precio);
            printf("----------------\n");
        }
        arre++;
    }
    printf("\n---------------------\n");
}

void mostrarPedidos(arbol *arre, int cant) {
    printf("\n\n----------MOSTRAR PEDIDOS----------\n\n");
    for (int i = 0; i < cant; i++) {
        if (arre->canPedidos > 0) {
            printf("------PEDIDOS DE: %s-----\n\n", arre->especie.nvulgar);
            if (arre->pedidos != NULL) {
                for (int j = 0; j < arre->canPedidos; j++) {
                    printf("Razon social: %s - Tel: %s\n", arre->pedidos[j].cliente.razon_social, arre->pedidos[j].cliente.telefono);
                    printf("Vendedor: %s\n", arre->pedidos[j].vendedor);
                    printf("Cant de pedidos: %d\n", arre->pedidos[j].cantidad);
                    printf("--------------\n");
                }
            }
            printf("----------------\n");
        }
        arre++;
    }
    printf("\n---------------------\n");
}

// agregar pedidos solo a los que no tengan pedidos
void agregarPedidos(arbol *arre, int cant) {
    int op, canP, pretende, bandera = 1, acumulado = 0;
    printf("\n\n----------AGREGAR PEDIDOS----------\n\n");
    printf("--Elija una especie para agregar pedidos\n");
    for (int i = 0; i < cant; i++) {
        if (arre->pedidos == NULL) {
            printf("\n%d - %s", i, arre[i].especie.nvulgar);
        }
    }
    printf("\n");
    scanf("%d", &op);
    printf("--Ingrese la cantidad de pedidos a cargar en: %s\n", arre[op].especie.nvulgar);
    scanf("%d", &canP);
    arre[op].pedidos = (tpedidos *)malloc(canP * sizeof(tpedidos));
    for (int i = 0; i < canP; i++) {
        printf("-------Pedido n: %d------\n", i + 1);
        printf("\n-->Razon social: ");
        fflush(stdin);
        gets(arre[op].pedidos[i].cliente.razon_social);
        printf("\n-->Telefono: ");
        fflush(stdin);
        gets(arre[op].pedidos[i].cliente.telefono);
        printf("\n-->Vendedor: ");
        fflush(stdin);
        gets(arre[op].pedidos[i].vendedor);
        // Validar que las cant no superen el stock
        //_____________________
        //printf("\n-->Cantidad a pedir: ");
        //scanf("%d", &pretende);
        //arre[op].canPedidos = canP;
        //arre[op].pedidos[i].cantidad = pretende;
        //_____________________
        do {
            printf("\n-->Cantidad a pedir: ");
            scanf("%d", &pretende);
            if (arre[op].stock - (pretende + acumulado) >= 0) {
                acumulado = acumulado + pretende;
                arre[op].canPedidos = acumulado;
                arre[op].pedidos[i].cantidad = pretende;
                bandera = 1;
            } else {
                printf("La cantidad que se pretende supera el stock actual\n");
                bandera = 0;
            }
        } while (bandera == 0);
    }
    printf("\n---------------------\n");
}

void actualizarStock(arbol *arre, int cant) {
    int op, canS;
    printf("\n\n----------ACTUALIZAR STOCK----------\n");
    printf("--Elija una especie para actualizar stock\n");
    for (int i = 0; i < cant; i++) {
        if (arre->pedidos == NULL) {
            printf("\n%d - %s", i, arre[i].especie.nvulgar);
        }
    }
    printf("\n");
    scanf("%d", &op);
    printf("--Stock actual: %d --- Nuevo stock: ", arre[op].stock);
    scanf("%d", &canS);
    // validar antes de guardar
    arre[op].stock = canS;
    printf("Stock actualizado!\n");
    printf("\n---------------------\n");
}

void actualizarPrecio(arbol *arre, int cant) {
    int op;
    float precioN;
    printf("\n\n----------ACTUALIZAR PRECIO----------\n");
    printf("--Elija una especie para actualizar su precio\n");
    for (int i = 0; i < cant; i++) {
        printf("\n%d - %s", i, arre[i].especie.nvulgar);
    }
    printf("\n");
    scanf("%d", &op);
    printf("--Precio actual: $%2.f --- Nuevo precio: $", arre[op].precio);
    scanf("%f", &precioN);
    // validar antes de guardar
    arre[op].precio = precioN;
    printf("Precio actualizado!\n");
    printf("\n---------------------\n");
}

void liberarMemoria(arbol *arre, int cant) {
    printf("\n\n----------LIBERAR MEMORIA----------\n");
    for (int i = 0; i < cant; i++) {
        if (arre->pedidos != NULL) {
            free(arre->pedidos);
        }
        arre++;
    }
    free(arre);
    printf("\n----------------------n");
}