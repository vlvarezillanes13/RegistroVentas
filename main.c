
#include <stdio.h>
#include <stdlib.h>

struct cafeta {
    char nombre[10];
    int codigo;
    int p_costo;
    int p_venta;
    int cantidad;
    struct cafeta *enlace;
};

int main() {

    struct cafeta *inicio, *venta, *ptr;

    int opcion, total_costo = 0, total_venta = 0, ganacias = 0;

    inicio = NULL;

    do {
        printf("\n\n               REGISTRO DE VENTAS CAFETA ICI            \n");
        printf("-------------------------------------------------------------\n");
        printf("Opción = 1 ---> Registrar Venta\n");
        printf("Opción = 0 ---> No registrar venta \n");
        printf("Ingrese opción: ");
        scanf("%d", &opcion);
        if (opcion == 1) {
            venta = (struct cafeta *) malloc(sizeof (struct cafeta));
            venta->enlace = NULL;

            printf("Ingrese código del producto: ");
            scanf("%d", &venta->codigo);
            while (venta->codigo < 1000 || venta->codigo > 9999) { //codigo 4 digitos
                printf("Código incorrecto, ingrese nuevamente código del producto: ");
                scanf("%d", &venta->codigo);
            }

            printf("Ingrese cantidad de productos vendidos: ");
            scanf("%d", &venta->cantidad);
            while (venta->cantidad < 1) {
                printf("Cantidad de productos vendidos incorrecta, ingrese nuevamente: ");
                scanf("%d", &venta->cantidad);
            }

            printf("Ingrese precio de costo del producto: ");
            scanf("%d", &venta->p_costo);
            while (venta->p_costo < 10000 || venta->p_costo > 99999) {
                printf("Precio incorrecto, ingrese nuevamente código del producto: ");
                scanf("%d", &venta->p_costo);
            }

            printf("Ingrese precio de venta del producto: ");
            scanf("%d", &venta->p_venta);
            while (venta->p_venta < 20000 || venta->p_venta > 99999) {
                printf("Precio Venta incorrecto, ingrese nuevamente código del producto: ");
                scanf("%d", &venta->p_venta);
            }

            if (inicio == NULL) {
                inicio = venta;
            } else {
                //encontrar el ultimo registro
                ptr = inicio;
                while (ptr->enlace != NULL) {
                    ptr = ptr->enlace;
                }
                ptr->enlace = venta;
            }
        }
        system("cls");
    } while (opcion != 0);
    
    
    if(inicio != NULL){
        //recorrer todos los registros
        ptr = inicio;
        while(ptr!=NULL){
            total_costo += (ptr->p_costo * ptr->cantidad);
            total_venta += (ptr->p_venta * ptr->cantidad);
            ptr = ptr->enlace;
        }
        
        ganacias = total_venta - total_costo;
        printf("La ganancia de la cafeta en este mes es de: $%d",ganacias);
    }
    return (EXIT_SUCCESS);
}

