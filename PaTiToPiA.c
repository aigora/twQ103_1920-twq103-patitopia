#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h> // esta libreria sirve para hacer las pausas ( sleep() ) a lo largo del programa
#define rojo "\x1b[31m"
#define reset "\x1b[33m"
#define verde "\x1b[32m"

struct cuentas{
	char username[100];
	char password[100];
};
struct patitos{
	char tipos[100];
};
struct ubicacion{
	char pais[100];
};

// LLAMADA A LAS FUNCIONES: 
void banner();
float saldof(); 
void hastaluego();
int menu(char i, struct cuentas cuenta[], int contadorC);
void tiempof();

int main(){
	FILE * cuentas;
	FILE * patitos;
	struct cuentas cuenta[100];
	struct patitos patos[100];
	char opMenu,opcion2,opcion3;
	int j, contadorC=0, existeU=3, existeP= 3, contadorP=0, opcion=13, k = 0,cestapatos[100],auxcesta;
	int nn=164;
	float preciopatos[100]={31.41,100,25.99,19.99,19.95,2.99,39.99,4.99,10,15,35,20.99},coste,saldo;
	
	//esto sirve para cambiar el color de las letras
	system("color 06");
	
	cuentas = fopen("cuentas.txt", "r");
	
	if(cuentas == NULL){
		printf("No se encuentra el fichero\n");
		return 0;
	}
	
	while (fscanf(cuentas, "%s %s", &cuenta[contadorC].username, &cuenta[contadorC].password) != EOF){
		//printf("%s\n", cuenta[contadorC].username); Para asegurarnos que se ha pasado bien al vector de estructuras.
		//printf("%s\n", cuenta[contadorC].password); Para asegurarnos que se ha pasado bien al vector de estructuras.
		contadorC++;
	}
	//printf("%d", contadorC); Aquí comprobamos que se han contado bien el nº de cuentas existentes.
	
	fclose(cuentas);
	
	// BANNER:
	banner();
	
	// MENU DE INICIO:
	do{
		printf("Bienvenido al menu principal de PaTiToPiA.\nElige entre las siguientes opciones:\n");
		printf("A-Ayuda\nI-Iniciar Sesion\nR-Registrarse\nS- Salir\n");
		fflush(stdin);
		scanf("%c",&opMenu);
		
		menu(opMenu, cuenta, contadorC);
		
	}while ((opMenu!= 'I')&&(opMenu!= 'R')&&(opMenu!= 'S'));

	
	
	// TIENDA:
	//tienda();
	
	// Recorremos el fichero patitos.txt para guardarlo en nuestro vector de estructuras:
	patitos = fopen("patitos.txt", "r");
	
	if(patitos == NULL){
		printf("No se encuentra el fichero\n");
		return 0;
	}
	while (contadorP < 12){
		fgets(patos[contadorP].tipos,40,patitos);
		contadorP++;
	}
	
	fclose(patitos);
	
	printf("A continuacion se le solicitaran los datos de su tarjeta:\n");
	
	saldo = saldof();
	// Una vez el usuario se haya registrado o iniciado sesión, comienza la compra de patitos:
	sleep(1);
	banner();
	
	printf("Bienvenido a la tienda: \n");
	
	// Con el siguiente do-while el usuario puede seleccionar uno de los patitos para observar sus cualidades.
	do{
		do{
			
		printf("Escoja de que pato quiere ver mas informacion introduciendo su numero:\nPulse 0 para abandonar la tienda\n");
		// Ahora imprimimos en pantalla todos los tipos de patitos que tenemos a la venta para que el usuario los vea.
		k=0;
		while(k < contadorP){
			printf("%d. %s",k+1,patos[k].tipos);
			k++;
		}
		scanf("%d", &opcion);
		printf("\n\n");
    	switch(opcion){
        	case 1:
        		printf("Pato seleccionado: Patito Pirata\n");
        		printf("Equipado con una espada, un parche en el ojo, un gran sombrero, y una pata de palo, \neste patito de goma te ayudara a conquistar la ba%cera.\nPero ten cuidado no se rebele y decida sustituirte como capitan del ba%co.\n", nn, nn);
        		printf("Precio: 31.41$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        			
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[0] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 2:
        		printf("Pato seleccionado: Patito Cientifico\n");
        		printf("Mas vale que te pongas las gafas protectoras y unos guantes, \nporque con este loco patito cualquier experimento puede irse de las alas.\nPor que creias que tiene las plumas negras? Tantos experimentos que alguno tenia que salir mal y ... EXPLOTAR.\n");
        		printf("Precio: 100$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[1] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
       					break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 3:
        		printf("Pato seleccionado: Patito Vaquero\n");
        		printf("Bienvenidos al oeste de la ba%cera, donde te encontraras saqueadores, jinetes, y ... \nEs eso un patito vaquero? \nCon su lazo y su increible punteria conseguira atrapar a esas burbujas escurridizas de la ba%cera.\n", nn, nn);
        		printf("Precio: 25.99$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[2] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
    					break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 4:
        		printf("Pato seleccionado: Pato Potter\n");
        		printf("Recien salido de Quackwarts aqui esta el elegido, el que, \narmado solo con su varita magica conseguira derrotar al se%cor oscuro.\nAyudale a conseguir su mision, o la hora del ba%co no volvera a ser lo mismo. \nEl destino del mundo magico esta en vuestras alas.\n", nn, nn);
        		printf("Precio: 19.99$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[3] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
       					break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
       			break;
        	case 5:
        		printf("Pato seleccionado: Astropato\n");
        		printf("Desde los confines del espacio aterriza en nuestro catologo Astropato:\ntras ser el primer pato astronauta en llegar a la Luna en 1996 y \nser nombrado por la NASA en 2002 Astronauta Honorable este a%co cumplira su sue%co: llegar a tu ba%cera.\n", nn, nn, nn);
        		printf("Precio: 19.95$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[4] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 6:
       			printf("Pato seleccionado: Patito policia\n");
       			printf("Justo. Valiente. Honrado. Tres palabras que describen a la perfeccion a este increible justiciero.\nNo todos los heroes tienen capa, algunos como este tienen pico.\n");
       			printf("Precio: 2.99$\n");
       			printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[5] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 7:
        		printf("Pato seleccionado: Afropato\n");
        		printf("Afropato llega desde los 80 para a%cadir algo de ritmo a tu ba%co. \nCon su pelazo y su moviento de alas sabra como conquistar la pista de baile y tu corazon.\nSi te gusta el boogie y el plumaje de lentejuelas este es tu pato.\n", nn, nn);
        		printf("Precio: 80$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[6] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 8:
        		printf("Pato seleccionado: Patito Deportista\n");
        		printf("Este pato tiene claro una cosa: le gusta ganar. Tras llevar a Quacka%ca a las Finales del Mundo de Petanca y \nllevarse dos veces la medalla de oro en natacion sincronizada \nha venido para ayudarte a vencer el aburrimiento en la ba%cera.\n", nn, nn);
        		printf("Precio: 4.99$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[7] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 9:
        		printf("Pato seleccionado: Pate Inclusive\n");
        		printf("Aqui teneis un pato colorido para que nadie se sienta excluido!\nSu maravilloso arcoiris y sus plumas en el pelo haran de tu ba%cera un mundo nuevo\n", nn);
        		printf("Precio: 10$\n");
        		printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[8] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 10:
        		printf("Pato seleccionado: No Pato\n");
        		printf("Como bien dice su nombre, este patito no es un pato, o eso se piensa el.\nSu cara tapada con una bolsita de papel y su camiseta con estampado de rinoceronte \nhara que pase completamente desapercibido por tu ba%cera.\n", nn);
        		printf("Precio: 15$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[9] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 11:
        		printf("Pato seleccionado: Patito-Ciborg\n");
        		printf("Este patito-ciborg esta envuelto en metal y posee en su frente un super rayo laser el cual \nhara retroceder a cualquier enemigo en tu ducha.\nTen cuidado si se enfada!\n");
        		printf("Precio: 35$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n", nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n", nn);
        			scanf("%d",&auxcesta);
        			cestapatos[10] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	case 12:
        		printf("Pato seleccionado: Spiderpato\n");
        		printf("Si necesitas que la ciudad de NuevaQuack sea salvada, no dudes en llamar a Spiderpato!\nSus telara%cas se posaran por toda tu ba%cera para rescatarte del malefico Doctor Pactopus \ny asi salvar tu relajante ducha.\n", nn, nn, nn);
        		printf("Precio: 20.99$\n");
				printf("\nDesea a%cadir este patito a la cesta?\nS-Si\nN-No\n",nn);
        		fflush(stdin);
        		scanf("%c",&opcion2);
        		if(opcion2 == 'N'){
        			printf("\nRedirigiendole a la tienda...\n");
        			sleep(1);
        			banner();
        			break;
        		}
        		if(opcion2 == 'S'){
        			printf("Cuantos desea a%cadir?\n",nn);
        			scanf("%d",&auxcesta);
        			cestapatos[11] += auxcesta;
        			printf("\nDesea seguir comprando o pasar a confimar la cesta?\nS-Seguir comprando\nC-Cesta\n");
        			fflush(stdin);
        			scanf("%c",&opcion3);
        			if(opcion3== 'S'){
        				printf("\nRedirigiendole a la tienda...\n");
        				sleep(1);
        				banner();
        				break;
					}
					if(opcion3='C'){
						printf("\nYendo a la cesta...\n");
						sleep(1);
        				banner();
						break;
					}
				}
        		break;
        	default:
        		if(opcion == 0){
        			break;
				}
            	printf("No hay pato asociado a ese numero, introduce otro numero\n");
            	sleep(1);
            	banner();
    	}
    }while((opcion<1 || opcion >12 || opcion2 == 'N' || opcion3== 'S')&& opcion != 0);
    
    printf("Has a%cadido a la cesta:\n",nn);
	k=0;
	while(k != contadorP){
		if(cestapatos[k] > 0){
			printf("- %d unidad(es) de %s",cestapatos[k],patos[k].tipos);
		}
		k++;
		}
	k=0;
	coste=0;
	while(k<contadorP){
		coste = coste + (float)cestapatos[k]*preciopatos[k];
		k++;
	}
	printf("El precio total seria de %.2f$\n",coste);
	printf("Desea confirmar la compra o vaciar la cesta y volver a la tienda?\nC-Confirmar compra y pagar\nV-Vaciar cesta y volver\n");
	fflush(stdin);
	scanf("%c",&opcion2);
	if(opcion2== 'V' || opcion2 == 'v'){
		printf("Vaciando cesta...\n");
		sleep(2);
       	banner();
		k=0;
		while(k<contadorP){
			cestapatos[k] = 0;
			k++;
		}
	}else{
		printf("Pasando a confirmar la compra...\n");
		if(coste>saldo){
			printf(rojo "El precio supera el saldo de su tarjeta, no puede permitirse comprar todos estos patitos\n" reset);
			printf(rojo "Procedemos a borrarle la cesta...\n" reset);
			sleep(4);
			banner();
			k=0;
			while(k<contadorP){
			cestapatos[k] = 0;
			k++;
			}
		}else{
			printf(verde "Se ha completado la compra con exito, su saldo restante es %.2f$\n\n" reset ,saldo-coste);
			tiempof();
			printf("Esperamos que halla disfrutado de su compra, muchas gracias\n");
			printf("A continuacion, se cerrara el programa.\n\n");
			sleep(4);
			hastaluego();
			return 0;
		}
	}
	}while(coste>saldo || opcion2 == 'V');
}

// FUNCIONES DEFINIDAS:

int menu(char i, struct cuentas cuenta[], int contadorC){
	
	FILE * cuentas;
	//struct cuentas cuenta[100];
	char username[100], password[100];
	int j, existeU=3, existeP= 3;
	int option;
	int nn=164;
	do{
		switch(i){
			case 'A':
				printf("Para acceder a la tienda deberas iniciar sesion, en caso de no disponer de cuenta debe registrarse\n\n");
				break;
			case 'I':	
				printf("Para iniciar sesion introduzca su nombre de usuario y contrase%ca\n", nn);
				printf("Usuario: \n");
				fflush(stdin);
				scanf("%s", username);
				
				// Creamos un buble que recorra todos los nombres guardados en el vector y los compare con el usuario introducido para ver si realmente 
				// esá registrado o no. A raíz de las diferentes posibilidades escribimos diferentes soluciones/salidas del programa:
				
				for(j=0;j < contadorC; j++){
					
				    existeU = strcmp(username, cuenta[j].username); 
					
				    if(existeU == 0){
				    	printf(verde "La cuenta existe\n"reset );
						do{	
							printf("Introduce su contrase%ca: \n", nn); 
							fflush(stdin);
							scanf("%s", password);
							existeP = strcmp(password, cuenta[j].password);
				
							if(existeP == 0){
								printf(verde "Has iniciado tu cuenta correctamente\n\n" reset);
								option= 1;
								break;
							}  
							if (existeP != 0){
								printf(rojo "La contrase%ca no es correcta\n" reset, nn);	
	
							}
						}while(existeP != 0);
					}else if (j == contadorC -1 && existeU != 0 && existeP !=0){
						printf(rojo "No existe el usuario introducido.\n\n" reset);
						option= 0;
						sleep(2);
						banner();
						}
					}
				break;
				
			case 'R':
				printf("Para registrarse necesitara un nombre de usuario y una contrase%ca\n", nn);
				
				// Para que un usuario que quiera registrarse no tenga el mismo nombre que otro ya registrado creamos un bucle do-while que avise al usuario
				// de que ese nombre ya existe en el fichero cuentas.
				do{
					printf("Introduzca el nombre deseado:\n");
					fflush(stdin);
				    scanf("%s", username);
				    
					for(j=0; j<contadorC; j++){
						
						existeU = strcmp(username, cuenta[j].username); 
						
					    if(existeU == 0){
						 printf(rojo "Este usuario ya existe, introduzca uno valido.\n" reset);
						 break;
						}
						else if(contadorC-1 == j && existeU != 0){
							printf(verde"Nombre disponible.\n"reset);
							break;
						}
					}
				}while(existeU == 0);
						
				printf("Introduzca la contrase%ca:\n", nn);
				fflush(stdin);
				gets(password);
				cuentas = fopen("cuentas.txt", "w");
				j=0;
				while(j<contadorC){
					fprintf(cuentas,"%s\n",cuenta[j].username);
					fprintf(cuentas,"%s\n",cuenta[j].password);
						j++;
				}
				fprintf(cuentas,"%s\n",username);
				fprintf(cuentas,"%s\n",password);
				printf(verde "Se ha registrado correctamente.\n\n"reset);
				break;
			case 'S':
				printf("Saliendo...");
				return 0;
		}
	}while(option == 0);
}

void hastaluego(){
	system("cls");
	printf("\n\n\t\t\t\t\tQuackdo vuelva le estaremos esperando.");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t    _      _                          _      _\n");
	printf("\t\t\t\t  _(.)<  >(.)_                      _(.)<  >(.)_\n");
	printf("\t\t\t\t (___)    (___)                    (___)    (___) \n");
}

void banner(){
	system("cls");
	printf("\n\n");
	printf("\t\t\t ********************************************************************\n");
	printf("\t\t\t         ____      _______     _______       ____      ____      \n");
	printf("\t\t\t    _   |    | ___    |           |    ___  |    |    |    |   _    \n");
	printf("\t\t\t  _(.)< |____| ___|   |     |     |   |   | |____| |  |____| >(.)_ \n");
	printf("\t\t\t (___)  |     |   |   |     |     |   |   | |      |  |    |  (___)   \n");
	printf("\t\t\t        |     |___|   |     |     |   |___| |      |  |    |         \n");
	printf("\n");
	printf("\t\t\t ********************************************************************\n");
	printf("\n\n");
	return;
}

float saldof(){
	char letra, nombretarjeta[200], letraT, numerotarjeta[100], codtarjeta[100],fb;
	int num=1, i,i2, checknum=0,checkcod,checkfecha,checknom,contesp,fm,fa;
	int nn= 164; 
	float saldo;
	do{
		sleep(3);
		banner();
		do{
			printf("\nIntroduzca el nombre y los apellidos del titular en mayusculas\n");
			fflush(stdin);
			gets(nombretarjeta);
			i=0;
			while(i<strlen(nombretarjeta)){
				i2=0;
				contesp=0;
					while(i2<strlen(nombretarjeta)){
						if(nombretarjeta[i2] == ' '){
							contesp++;
						}
						i2++;
					}
				if((nombretarjeta[i] < 'A' || nombretarjeta[i] > 'Z') && (nombretarjeta[i] != ' ')){
					printf(rojo "Nombre invalido, recuerde que debe estar completamente en mayusculas\n" reset);
					checknom = 0;
					break;
				}else if(contesp!=2){
					printf(rojo "Nombre invalido, recuerde que solo debe escribir un nombre y dos apellidos\n" reset);
					checknom=0;
					break;
				}
				else{
					checknom =1;
				}
				i++;
			}
		}while(checknom==0);
		
		
		do{
			printf("\nIntroduzca el numero de la tarjeta con espacios\n");
			gets(numerotarjeta);
			i=0;
			while(i < strlen(numerotarjeta)){
				if((numerotarjeta[i] < '0' || numerotarjeta[i] > '9') && (numerotarjeta[i] != ' ')  ){
					printf(rojo "Numero invalido, recuerda que solo se aceptan numeros y espacios\n" reset);
					checknum= 0;
					break;
				}else if (strlen(numerotarjeta) != 19){
					printf(rojo "Numero invalido, recuerda que debe ser de la forma 'NNNN NNNN NNNN NNNN'\n" reset);
					checknum=0;
					break;
				}else {
					checknum=1;
				}
				i++;
			}			
		}while(checknum==0);

		do{
			printf("\nIntroduzca el codigo de la tarjeta\n");
			gets(codtarjeta);
			i=0;
			while(i < strlen(codtarjeta)){
				if(codtarjeta[i] < '0' || codtarjeta[i] > '9' ){
					printf( rojo "Codigo invalido, recuerde que solo se aceptan numeros y espacios\n"reset);
					checkcod= 0;
					break;
				}else if (strlen(codtarjeta) != 3){
					printf(rojo "Codigo invalido, recuerde que son 3 digitos\n"reset );
					checkcod=0;
					break;
				}else {
					checkcod=1;
				}
				i++;
			}
		}while(checkcod==0);
		
		do{
			printf("\nIntroduzca la fecha de caducidad de la tarjeta de la forma 'MM/AA'\n");
			fflush(stdin);
			scanf("%d",&fm);
			scanf("%c",&fb);
			scanf("%d",&fa);
			checkfecha= 0;
			if(fm<1 || fm>12){
				printf(rojo "Fecha invalida, mes inexistente\n" reset);
				checkfecha=0;
			}else if(fa>99){
				printf(rojo "Fecha invalida, a%co inexistente\n" reset,nn);
				checkfecha=0;
			}else if((fa==20 && fm<5) || (fa<20 )){
				printf(rojo"Fecha invalida, la tarjeta ya ha caducado\n"reset);
				checkfecha=0;
			}else if(fb != '/'){
				printf(rojo"Fecha invalida, recuerda que debes incluir '/' entre el mes y el a%co\n"reset,nn);
			}else{
				checkfecha=1;
			}
		}while(checkfecha==0);
		srand(time(NULL)*100000);
		saldo= 1 + rand() % (5000-1);
		printf("\nSu saldo parece ser de %.0f$\n",saldo);
		printf("\nEsta conforme o desea introducir otra tarjeta?\nS-Introducir otra tarjeta\nC-Continuar\n");
		fflush(stdin);
		scanf("%c",&letra);
	}while(letra == 'S' || letra == 's');
	
	printf(verde "Su tarjeta ha sido introducida con exito\n" reset);
	return saldo;
}

void tiempof(){
	int k,codpost[100],check=0,numeroP=0,numcasa,planta,tiempo;
	char pais[100],calle[100],ccaa[100],municipio[100],portal,opt;
	struct ubicacion ubi[10];
	FILE * paises;
	
	
	paises = fopen("paises.txt", "r");
	while ((fscanf(paises,"%s",&ubi[numeroP].pais) != EOF)){
		numeroP++;
	}
	do{
		sleep(3);
		banner();
		printf("Por favor, indique la direccion de entrega del paquete:\n\n");
		do{
			printf("Pais de residencia en mayusculas:\n");
			fflush(stdin);
			gets(pais);
			k=0;
			while(k != strlen(pais)){
				if(pais[k] != ' ' && (pais[k] < 'A' || pais[k] > 'Z')){
					printf(rojo "Pais invalido, recuerde que debe estar completamente en mayusculas\nUse 'N' en lugar de '%c' \n" reset,165);
					check=0;
					break;
				}else {
					check =1;
				}
				k++;
			}
			k=0;
			while(k<numeroP){
				if(strcmp(ubi[k].pais,pais) == 0){	
					printf(verde "Podemos realizar la entrega en el pais indicado\n" reset);
					check=1;
					break;
				}else if(k==numeroP-1 && strcmp(ubi[k].pais,pais) != 0 && check==1){
					printf(rojo "Nuestros medios no nos permiten llegar hasta tal pais\n" reset );
					check=0;
					break;
				}
				k++;
			}
		}while(check == 0);
		
		do{
			printf("Comunidad Autonoma,Estado o Region:\n");
			gets(ccaa);
			k=0;
			while(k<strlen(ccaa)){
				if((ccaa[k] < 'A' || ccaa[k] > 'Z') && (ccaa[k] < 'a' || ccaa[k] > 'z')){
					printf(rojo "Invalido, recuerde que solo se permiten letras\n" reset);
					check=0;
					break;
				}else{
					check=1;
				}
				k++;
			}
		}while(check==0);
		
		do{
			printf("Municipio:\n");
			gets(municipio);
			k=0;
			while(k<strlen(municipio)){
				if((municipio[k] < 'a' || municipio[k] > 'z') && (municipio[k] <'A' || municipio[k] > 'Z')){
					printf(rojo "Invalido, recuerde que solo se permiten letras\n" reset);
					check=0;
					break;
				}else{
					check=1;
				}
				k++;
			}
		}while(check==0);
		
		do{
		printf("Calle o Avenida:\n");
		gets(calle);
			k=0;
			while(k<strlen(calle)){
				if((calle[k] < 'a' || calle[k] > 'z') && (calle[k] <'A' || calle[k] > 'Z') && calle[k] != ' '){
					printf(rojo "Invalido, recuerde que solo se permiten letras y espacios\n" reset);
					check=0;
					break;
				}else{
					check=1;
				}
				k++;
			}
		}while(check==0);
	
		do{	
			printf("Numero de la residencia\n");
			fflush(stdin);
			scanf("%d",&numcasa);
			if(numcasa < 1 || numcasa > 200){
				printf(rojo "Numero invalido\n" reset);
				check=0;
			}else {
				check=1;
			}
		}while(check==0);
		
		do{
			printf("Indique si se trata de un piso o de un chalet\nP-Piso\nC-Chalet\n");
			fflush(stdin);
			scanf("%c",&opt);
			
			if(opt == 'C'){
				printf(verde "En ese caso no son necesario mas datos, gracias\n" reset);
				check=1;	
			}else if(opt == 'P'){
				do{
				printf("Planta:\n");
				fflush(stdin);
				scanf("%d",&planta);
				if(planta < 1 || planta > 99){
					printf(rojo "Planta invalida\n" reset);
					check=0;
				}else {
					check=1;
				}
				}while(check==0);
				
				do{
					printf("Portal:\n");
					fflush(stdin);
					scanf("%c",&portal);
					if(portal < 'A' || portal > 'Z'){
						printf(rojo "Portal invalido, recuerde que debe estar en mayusculas\n" reset);
						check=0;
					}else{
						check=1;
					}
				}while(check==0);
			}else{
				check=0;
			}
		}while(check==0);
		if(opt == 'P'){
			printf("La ubicacion es: C/%s  n%c %d, %d%c%c en %s, %s (%s)\n",calle,167,numcasa,planta,167,portal,municipio,ccaa,pais);
		}else{
			printf("La ubicacion es: C/%s  n%c%d en %s, %s (%s)\n",calle,167,numcasa,municipio,ccaa,pais);
		}
			
		srand(time(NULL)*100000);
		tiempo= 15 + rand() % (310-15);
		if(tiempo < 49){
			printf("Parece ser que disponemos de almacenes cerca suya, podriamos hacer la entrega en unas %d horas\n",tiempo);
		}else if(tiempo >192){
			printf("Al no disponer de almacenes cerca suya el pedido tardara algo mas de una semana en llegar,\naproximadamente %d dias\n",tiempo/24);
		}else{
			printf("Su pedido llegara a su ubicacion en %d dias\n",tiempo/24);
		}
			printf("Desea confirmar la ubicacion o modificarla?\nC-Confirmar\nM-Modificar datos\n");
			fflush(stdin);
			scanf("%c",&opt);
		}while(opt == 'M' || opt == 'm');
		printf(verde "La ubicacion ha sido confirmada con exito\n" reset);
}
