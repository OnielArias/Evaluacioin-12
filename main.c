#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    long int mble_no;
    char sex[8];
    char mail[100];
    char citision_no[20];

    };
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    system("color 3f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
    printf("Registros\n");
printf("\t\t*****BIENVENIDOS AL DIRECTORIO TELEFONICO****");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Agregar  nuevo   \t2.Lista   \t3.Salir  \n\t4.Modificar \t5.Buscar \t6.Borrar");

switch(getch())
{
    case '1':
	addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': exit(0);
    break;
    case '4': modifyrecord();
    break;
    case '5': searchrecord();
    break;
    case '6': deleterecord();
    break;
    default:
                system("cls");
                printf("\nIngrese numero dek 1 al 6 solamente");
                printf("\n Ingrese cualquier letra");
                getch();

menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\nIngrese nombre: ");
        got(p.name);
        printf("\nIngrese direccion: ");
        got(p.address);
        printf("\nIngrese nombre de papa: ");
        got(p.father_name);
        printf("\nIngrese nombre de papa: ");
        got(p.mother_name);
        printf("\nIngrese numero de telefono: ");
        scanf("%ld",&p.mble_no);
        printf("Ingrese genero: ");
        got(p.sex);
        printf("\nIngrese E-Mail: ");
         got(p.mail);
        printf("\nIngrese Cedula: ");
        got(p.citision_no);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRegistro guardado !!");

fclose(f);

    printf("\n\ningrese cualquier letra");

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nError de apertura de archivo en el listado :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n TU REGISTRO ES:\n\n ");
        printf("\nNombre: %s\nDireccion: %s\nNombre de papa: %s\nNombre de mama: %s\nNumero celular: %ld\nGenero: %s\nE-Mail: %s\nCedula: %s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\nIngrese cualquier letra");
 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\nError en abrir\a\a\a\a");
    exit(1);

}
printf("\nIngrese el nombre de la persona a buscar\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tInformacion detallada sobre %s",name);
        printf("\nNombre: %s\nDireccion: %s\nNombre de papa: %s\nNombre de mama: %s\nNumero celular: %ld\nGenero: %s\nE-Mail: %s\nCedula: %s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);
    }
        else
        printf("404 ! No encontrado !!");

}
 fclose(f);
  printf("\nIngrese cualquier letra");

	 getch();
    system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("\nDATOS DE CONTACTO NO AGREGADOS.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("Error al abrir");
		else

        {


		printf("\nIngrese Nombre de contacto: ");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("\nNO HAY REGISTRO DE CONTACTO PARA BORRAR.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("\nREGISTRO BORRADO SATISFACTORIAMENTE.");

		}
	}
}
 printf("\nIngrese cualquier letra");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("\nDatos de contacto aun no agregados.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nIngrese el nombre del contacto a modificar:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



        printf("\nIngrese nombre: ");
        got(p.name);
        printf("\nIngrese direccion: ");
        got(p.address);
        printf("\nIngrese nombre de papa: ");
        got(p.father_name);
        printf("\nIngrese nombre de papa: ");
        got(p.mother_name);
        printf("\nIngrese numero de telefono: ");
        scanf("%ld",&p.mble_no);
        printf("Ingrese genero: ");
        got(p.sex);
        printf("\nIngrese E-Mail: ");
         got(p.mail);
        printf("\nIngrese Cedula: ");
        got(p.citision_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\nTu informacion a sido modificada");

            }
            else
            {
                    printf(" \nDatos no encontrados");

            }
            fclose(f);
	}
	 printf("\nIngrese cualquier letra");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
