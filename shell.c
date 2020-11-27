#include "holberton.h"

#define MAX_ARGS 13  /*Numero maximo de argumentos (-1) cuando se trate de un comando externo*/
#define MAX_I 105 /*Numero de caracteres maximo para comando las variables de ambiente*/

/*Declarando variables*/
char comando[MAX_I]; /*Esta var lee el comando que ingrese el usuario*/
char *args[MAX_ARGS]; /*en este arreglo se almacenan los argumentos del comando ingresado*/
/*Declarando variables de ambiente*/
char SHELL[MAX_I];
char PATH[MAX_I];
char HOME[MAX_I];
char PWD[MAX_I];

void separaArgs(void){
  int i;
  for(i=0;i<(MAX_ARGS-1);i++) args[i]=NULL; /*Borrar argumento previo que pudiera existir*/
  strtok(comando," "), i=0; /*separar palabras individuales usando tokens (espacio vacio)*/
  args[i]=comando; /*El 1er argumento sera comando por un requerimiento de execvp*/
  while((args[++i]=strtok(NULL," "))!=NULL && i<(MAX_ARGS-2));
}

void listaDir(void){
  char ruta[MAX_I]; /*Var auxiliar para formar la ruta solicitada por el usuario*/
  int archs; /*Numero de archivos encontrados en el dir indicado*/
  int cnt=-1;
  struct dirent **lista; /*var que guarda la lista de archivos/dirs encontrados*/
  strcpy(ruta,PWD); /*Suponemos que el dir solicitado es de la ruta actual*/
  if(args[1]) strcat(ruta,"/"), strcat(ruta,args[1]); 
    /*pero si se trata de una(s) subcarpeta(s) las concatenamos*/
  archs=scandir(ruta,&lista,0,alphasort); /*Revisar el dir solicitado*/
  if(archs<0) /*En caso de falla enviar mensaje*/
    printf("Error no existe o no se pudo leer [%s]\n",ruta);
  else if(archs==2){ /*Si solo se encontro los directorios . (actual) y .. (padre) se
    considera que el dir esta vacio a efectos practicos*/
    printf(" El directorio [%s] esta vacio",ruta);
  }
  else{ /*Si se encontra al menos un archivo/directorio mostrarlo*/
    printf(" Archivos y carpetas encontrados en: [%s]\n",ruta);
    while(++cnt<archs)
      if(strcmp(lista[cnt]->d_name,".")!=0 && strcmp(lista[cnt]->d_name,"..")!=0)
        printf(" %s\n",lista[cnt]->d_name);
  }
}

void eco(void){
  int i;
  int j;
  int k=0;
  char aux[6];
  while(args[++k]){ /*Aqui hay que recorrer argumento por  argumentos mientra este tenga valor*/
    for(i=0;i<strlen(args[k]);i++){ /*Para imprimir lo hare de caracter en caracter para 
      interceptar el $ en caso de que este presente en cuanquier posicion*/
      if(args[k][i]!='$') printf("%c",args[k][i]);
      else{ /*Si se encuentra el $ ver si le sigue el nombre de alguna variable de ambiente 
        en caso afirmativo imprimir el valor correspondiente, sino imprimir el simbolo*/
        j=-1;
        while(++j<5 && (i+j+1)<strlen(args[k]) && args[k][i+j+1]!='\0')
          aux[j]=args[k][i+j+1]; /*En aux copiar la sub cadena que sigue al simbolo $*/
        aux[j]='\0';
        if(strcmp(aux,"SHELL")==0) /*Ver si hay que imprimir el valor de SHELL*/
          printf("%s",SHELL), i+=5;
        else if(strncmp(aux,"PATH",4)==0) /*Idem PATH*/
          printf("%s",PATH), i+=4;
        else if(strncmp(aux,"PWD",3)==0) /*Idem PWD*/
          printf("%s",PWD), i+=3;
        else if(strncmp(aux,"HOME",4)==0) /*Idem HOME*/
          printf("%s",HOME), i+=4;
        else printf("$"); /*Ninguno de los anteriores el $ es solo un caracter mas*/
      }
    }
    printf(" "); /*Imprimir el espacio entre los distintos argumentos*/
  }
  printf("\n"); /*Imprimir un salto de linea al final del ultimo argumento*/
}

void comExterno(){ /*Ejecutar entradas consideradas comando externos*/
  int pid=0;
  int status;
  pid=fork(); /*Crear un proceso hijo*/
  if(pid<0) printf("Error! no se pudo crear un proceso hijo");
  if (pid==0){
    status=execvp(comando,args); /*Trata de ejecutar el comando y los argumentos que tenga*/
    if(status){
      printf("¡Error! %s no se reconoce o no se pudo ejecutar\n",comando);
      exit(1); /*Como no se pudo ejecutar el comando cerramos el proceso hijo*/
    }
  }
  else
    wait(NULL); /*esperar a que termine el proceso hijo*/
}
