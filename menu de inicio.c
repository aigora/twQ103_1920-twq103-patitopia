#include <stdio.h>
#include <math.h>
int main(){
	int i;
	do{
	printf("Bienvenido al menu principal de PaTiToPiA.\nElige entre las siguientes opciones:\n");
	printf("A-Ayuda\nI-Iniciar Sesion\nR-Registrarse\nT-Tienda\n");
	fflush(stdin);
	scanf("%c",&i);
}while ((i!= 'A')&&(i!= 'I')&&(i!= 'R')&&(i!= 'T'));
switch(i){
	case 'A':
		printf("Para acceder a la tienda deberas iniciar sesion, en caso de no disponer de cuenta debe registrarse");
		break;
	case 'I':
		printf("Para iniciar sesion introduzca su nombre de usuario y password\n");
		printf("Usuario: ");
		printf("\nPassword: ");
		break;
	case 'R':
		printf("Para registrarse necesitara un nombre de usuario y una password\n");
		break;
	case 'T':
		printf("Esta es la tienda de PaTiToPiA, donde encontrara todo nuestro catologo:\n");
		break;
		
}
}

