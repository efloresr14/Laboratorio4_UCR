#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palabras_iguales(const char *a, const char *b){return strcmp(a,b)==0;}

int main(int argc,char *argv[]){
    if(argc!=4){printf("Uso: %s entrada palabra_buscar palabra_reemplazo\n",argv[0]);return 1;}
    FILE *fin=fopen(argv[1],"r"); if(!fin){perror("input");return 1;}
    char out[128]; sprintf(out,"mod_%s",argv[1]);
    FILE *fout=fopen(out,"w"); if(!fout){perror("output");return 1;}
    char buf[256];int i=0,c;
    while((c=fgetc(fin))!=EOF){
        if(isalpha(c)||isdigit(c)) buf[i++]=c;
        else{
            if(i){buf[i]='\0'; if(palabras_iguales(buf,argv[2])) fputs(argv[3],fout);
                  else fputs(buf,fout); i=0;}
            fputc(c,fout);
        }
    }
    if(i){buf[i]='\0'; if(palabras_iguales(buf,argv[2])) fputs(argv[3],fout);
          else fputs(buf,fout);}
    fclose(fin); fclose(fout);
    printf("Archivo '%s' modificado -> '%s'\n",argv[1],out);
}
