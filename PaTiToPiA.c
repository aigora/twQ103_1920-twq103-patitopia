#include <stdio.h>
#include <math.h>
#include <string.h>

struct cuentas{
	char username[100];
	char password[100];
};
struct patitos{
	char tipos;
};

int main(){
	FILE * cuentas;
	FILE * patitos;
	struct cuentas cuenta[100];
	struct patitos patos[100];
	char username[100], password[100];
	char i;
	int j, contadorC=0, existeU=3, existeP= 3, contadorP=0, opcion=13, k = 0;;
	
	// Abrimos el fichero y guardamos los datos en un vector de estrucutras. Luego cerramos fichero.
	
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
	//printf("%d", contadorC); AquÌ comprobamos que se han contado bien el n∫ de cuentas existentes.
	
	fclose(cuentas);
	
	// Menu de inicio del programa:
	
	do{
		printf("Bienvenido al menu principal de PaTiToPiA.\nElige entre las siguientes opciones:\n");
		printf("A-Ayuda\nI-Iniciar Sesion\nR-Registrarse\nS- Salir\n");
		fflush(stdin);
		scanf("%c",&i);
		
		switch(i){
			case 'A':
				printf("Para acceder a la tienda deberas iniciar sesion, en caso de no disponer de cuenta debe registrarse\n\n");
				break;
			case 'I':	
				printf("Para iniciar sesion introduzca su nombre de usuario y password\n");
				printf("Usuario: \n");
				fflush(stdin);
				scanf("%s", username);
				
				// Creamos un buble que recorra todos los nombres guardados en el vector y los compare con el usuario introducido para ver si realmente 
				// esta registrado o no. A raiz de las diferentes posibilidades escribimos diferentes soluciones/salidas del programa:
				
				for(j=0;j < contadorC; j++){
					
				    existeU = strcmp(username, cuenta[j].username); 
					
				    if(existeU == 0){
						do{	
							printf("Password: \n"); 
							fflush(stdin);
							scanf("%s", password);
							existeP = strcmp(password, cuenta[j].password);
				
							if(existeP == 0){
								printf("Has iniciado tu cuenta correctamente\n\n");
								break;
							}  
							if (existeP != 0){
								printf("La contrasenia no es correcta\n");	
							}
						}while(existeP != 0);
					}
					if (j == contadorC-1 && existeU == 1){
						printf("No existe el usuario introducido. Volviendo al menu inicial: \n\n");
						i= 'Z';
						break;
						}
					}
				break;
				
			case 'R':
				printf("Para registrarse necesitara un nombre de usuario y una password\n");
				
				// Para que un usuario que quiera registrarse no tenga el mismo nombre que otro ya registrado creamos un bucle do-while 
				// que avise al usuario de que ese nombre ya existe en el fichero cuentas.txt.
				do{
					printf("Introduzca el nombre deseado:\n");
					fflush(stdin);
				        scanf("%s", username);
				    
					for(j=0; j<contadorC; j++){
						
					    existeU = strcmp(username, cuenta[j].username); 
						
					    if(existeU == 0){
						 printf("Este usuario ya existe, introduzca uno valido.\n");
						 break;
					     }
					    else{
						printf("Nombre disponible.\n");
						break;
					    }
					}	
				}while(existeU == 0);
				
				printf("Introduzca la contrasenia:\n");
				fflush(stdin);
				scanf("%s", password);
				printf("Se ha registrado correctamente, le redirigimos a la tienda.\n\n");
			break;
			case 'S':
				printf("Saliendo...");
				return 0;	
		}
	}while ((i!= 'I')&&(i!= 'R')&&(i!= 'S'));
	
	// Recorremos el fichero patitos.txt para guardarlo en nuestro vector de estructuras:
	patitos = fopen("patitos.txt", "r");
	
	if(patitos == NULL){
		printf("No se encuentra el fichero\n");
		return 0;
	}
	
	while (fscanf(patitos, "%c", &patos[contadorP].tipos) != EOF){
	//	printf("%c", patos[contadorP].tipos); Para asegurarnos que se ha pasado bien al vector de estructuras.
		contadorP++;
	}
	
	fclose(patitos);
	
	// Una vez el usuario se haya registrado o iniciado sesion, comienza la compra de patitos:
	
	printf("Bienvenido a la tienda: \n");
	printf("Escoja de que pato quiere ver mas informacion introduciendo su numero:\n");
	
	// Ahora imprimimos en pantalla todos los tipos de patitos que tenemos a la venta para que el usuario los vea.
	while(k != contadorP){
		printf("%c", patos[k].tipos);
		k++;
	}
	
	// Con el siguiente do-while el usuario puede seleccionar uno de los patitos para observar sus cualidades.
	do{
		scanf("%d", &opcion);
    	switch(opcion){
        	case 1:
        		printf("Pato seleccionado: Pato pirata\n");
        		printf("Equipado con una espada, un parche en el ojo, un gran sombrero, y una pata de palo, este patito de goma te ayudara a conquistar la baniera.\nPero ten cuidado no se rebele y decida sustituirte como capitan del banio.");
        		break;
        	case 2:
        		printf("Pato seleccionado: Pato cientifico\n");
        		printf("Mas vale que te pongas las gafas protectoras y unos guantes, porque con este loco patito cualquier experimento puede irse de las alas.\nøPor que creias que tiene las plumas negras? Tantos experimentos que alguno tenia que salir mal yÖ EXPLOTAR.");
        		break;
        	case 3:
        		printf("Pato seleccionado: Pato vaquero\n");
        		printf("Bienvenidos al oeste de la baniera, donde te encontraras saqueadores, jinetes, yÖ \nøEs eso un patito vaquero? Con su lazo y su increible punteria conseguira atrapar a esas burbujas escurridizas de la baniera.");
        		break;
        	case 4:
        		printf("Pato seleccionado: Pato Potter\n");
        		printf("Recien salido de Quackwarts aqui esta el elegido, el que, armado solo con su varita magica conseguira derrotar al senior oscuro.\nAyudale a conseguir su mision, o la hora del banio no volvera a ser lo mismo. El destino del mundo magico esta en vuestras alas.");
       			break;
        	case 5:
        		printf("Pato seleccionado: Astropato\n");
        		printf("Desde los confines del espacio aterriza en nuestro catologo Astropato:\ntras ser el primer pato astronauta en llegar a la Luna en 1996 y ser nombrado por la NASA en 2002 Astronauta Honorable este anio cumplira su suenio: llegar a tu baniera.");
        		break;
        	case 6:
       			printf("Pato seleccionado: Pato policia\n");
       			printf("Justo. Valiente. Honrado.Tres palabras que describen a la perfeccion a este increible justiciero.\nNo todos los heroes tienen capa, algunos como este tienen pico.");
        		break;
        	case 7:
        		printf("Pato seleccionado: Afropato\n");
        		printf("Afropato llega desde los 80 para aniadir algo de ritmo a tu banio. Con su pelazo y su moviento de alas sabra como conquistar la pista de baile y tu corazon.\nSi te gusta el boogie y el plumaje de lentejuelas este es tu pato.");
        		break;
        	case 8:
        		printf("Pato seleccionado: Pato deportista\n");
        		printf("Este pato tiene claro una cosa: le gusta ganar. Tras llevar a Quackania a las Finales del Mundo de Petanca y \nllevarse dos veces la medalla de oro en natacion sincronizada ha venido para ayudarte a vencer el aburrimiento en la baniera.");
        		break;
        	case 9:
        		printf("Pato seleccionado: Pate inclusive");
        		printf("°Aqui teneis un pato colorido para que nadie se sienta excluido!\nSu maravilloso arcoiris y sus plumas en el pelo haran de tu baniera un mundo nuevo");
        		break;
        	case 10:
        		printf("Pato seleccionado: No pato\n");
        		printf("Como bien dice su nombre, este patito no es un pato, o eso se piensa el.\nSu cara tapada con una bolsita de papel y su camiseta con estampado de rinoceronte hara que pase completamente desapercibido por tu baniera.");
        		break;
        	case 11:
        		printf("Pato seleccionado: Pato-ciborg\n");
        		printf("Este patito-ciborg esta envuelto en metal y posee en su frente un super rayo laser el cual hara retroceder a cualquier enemigo en tu ducha.\n°Ten cuidado si se enfada!");
        		break;
        	case 12:
        		printf("Pato seleccionado: Spiderpato\n");
        		printf("Si necesitas que la ciudad de NuevaQuack sea salvada, °no dudes en llamar a Spiderpato!\nSus telaranias se posar·n por toda tu baniera para rescatarte del malÈfico Doctor Pactopus y asi salvar tu relajante ducha.");
        		break;
        	default:
            	printf("No hay pato asociado a ese numero, introduce otro numero\n");
            	scanf("%d", &opcion);
            	break;
    	}
	}while(opcion<1 || opcion >12);
	
}

