#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string>

void tituloPrincipal()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"                    Simulacion de una COLA y Dos ventanillas                 "<<endl;
   cout<<"===============================================================================\n"<<endl;
    
   int segundos=5;
    cout << "\t\t\tEn instantes comienza la simulacion ...\n";
    for(int i=0; i<=79; i++)
        cout << "_";
    for(int i=0; i<=79; i++)
    {
        cout<<char(219);
        Sleep(50);
    }

   i = 0;
   putchar('\n');
   for (; i < 80; i++) {
      putchar('_');
   }
   cout<<endl;
}


struct Cola
{
	char Persona;
	Cola *siguiente;
};

typedef struct Cola *TCola;

void Push(TCola &Tope,TCola &Frente,char Dato)
{
	TCola q;
	q = new (struct Cola);
	q -> Persona = Dato;
	q -> siguiente = NULL;
	if(Frente == NULL)
	{			
		Frente = q;
	}
	else
	{		
		Tope -> siguiente = q;	
	}	

	Tope = q;
}

void Pop(TCola &Tope,TCola &Frente)
{	
	TCola aux;
	aux = Frente;
	if(Frente == Tope)
	{
		Frente = NULL;
		Tope = NULL;		
	}
	else
	{
		Frente = Frente -> siguiente;
	}	
}

void Mostrar(TCola &Frente)
{
	if(Frente == NULL)
	{
		cout<<"\n\tLa cola esta vacia"<<endl;
	}
	else
	{
		TCola q;
		
		q = Frente;
		
		while(q != NULL)
		{
			cout<<"\n\t\t["<<q->Persona<<"]" <<endl;
			q = q -> siguiente;			
		}
	}
}

void main()
{
	system("COLOR 0A");
	
	TCola Tope = NULL;
	TCola Frente = NULL;
	TCola Tope_1 = NULL;
	TCola Frente_1 = NULL;
	int variable;
	int Opcion = 1;
	int personas_a_entrar;
	int tiempo = 0;
	int i;
	int tiempo_total_1=0;
	int tiempo_total_2=0;
	char Personitas[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int cantidad = strlen(Personitas);
	char cliente;
	int demora;
	int tiempo_promedio_1 ;
	int tiempo_promedio_2 ;
	int veces_1=0;
	int veces_2=0;
	int Ventanilla_1 = 0;
	int Ventanilla_2 = 0;
	string cliente_1=" " ;
	string cliente_2=" " ;
	tituloPrincipal();
	clrscr();
	while(Opcion == 1)
	{
		personas_a_entrar = 0 + rand() % (1 +1 - 0) ;
		i=0;
		while(i<=personas_a_entrar)
		{
			demora = 0 + rand() % (30 +1 - 0);
			tiempo = tiempo + demora;
			variable = 0 + rand() % (cantidad-1+1 - 0) ;
			cliente = Personitas[variable];
			cout<<"\nLlega el Cliente ["<<cliente<<"] despues de "<<demora<<" Segundos"<<endl<<endl;				

			Push(Tope,Frente,cliente);
			cout<<"Ventanilla 1\t\t Ventanilla 2\n\n";
			cout<<"\t["<<cliente_1<<"]\t\t\t["<<cliente_2<<"]"<<endl<<endl<<endl;
			cout<<" \t\tCOLA "<<endl;
			Mostrar(Frente);
			cout<<"\n\nPulse enter";
			getch();
			clrscr();			
					
					
			if(Ventanilla_1 != 1 )
			{
				cliente_1 = cliente ;
				Pop(Tope,Frente);
				cout<<"Usuario ["<<cliente_1<<"] esta siendo atendido por la Ventanilla 1 \n"<<endl<<endl;
				Ventanilla_1++;
			}	
				else
				{
					if(Ventanilla_2 != 1 )
					{
						cliente_2 = cliente;
						Pop(Tope,Frente);
						cout<<"Usuario ["<<cliente<<"] esta siendo atendido por la Ventanilla 2 \n"<<endl<<endl;
						Ventanilla_2++;
					}
				}
			

			cout<<"Ventanilla 1\t\t Ventanilla 2\n\n";
			cout<<"\t["<<cliente_1<<"]\t\t\t["<<cliente_2<<"]"<<endl<<endl<<endl;
			cout<<" \t\tCOLA "<<endl;
			Mostrar(Frente);			
			
			cout<<"\n\nPulse enter";
			getch();
			clrscr();
			i++;
		}

		variable = 0 + rand() % (1 +1 - 0) ;

		if(variable == 0 && Ventanilla_1 > 0)
		{			
			variable = 0 + rand() % (30 +1 - 0) ;
			tiempo = tiempo + variable;
			tiempo_total_1 = tiempo_total_1 + variable;
			veces_1++;
			tiempo_promedio_1 = tiempo_total_1 / veces_1;
			cout<<"\nDETALLES:Cliente atendido en la Ventanilla 1 en "<<variable<<" segundos"<<endl<<endl;
			cliente_1 = " ";
			Ventanilla_1--;
		}

		if(variable == 1 && Ventanilla_2 > 0)
		{			
			variable = 0 + rand() % (30 +1 - 0) ;
			tiempo = tiempo + variable;
			tiempo_total_2 = tiempo_total_2 + variable;
			veces_2++;
			tiempo_promedio_2 = tiempo_total_2 / veces_2;
			cliente_2 = " ";
			cout<<"\nDETALLES:Cliente atendido en la Ventanilla 2 en "<<variable<<" segundos"<<endl<<endl;
			Ventanilla_2--;			
		}	

		cout<<"Ventanilla 1\t\t Ventanilla 2\n\n";
		cout<<"\t["<<cliente_1<<"]\t\t\t["<<cliente_2<<"]"<<endl<<endl<<endl;
		cout<<" \t\tCOLA "<<endl;
		Mostrar(Frente);
		cout<<"\nPulse enter";
		getch();		

		if(veces_1>0 && veces_2 >0)
		{						
			cout<<"\n\nTiempo Promedio de Espera de la cola 1:"<<tiempo_promedio_1<<endl;
			cout<<"\nTiempo Promedio de Espera de la cola 2:"<<tiempo_promedio_2<<endl;
		}	

		cout<<"\n\n\nDigite 0 para salir de la simulacion"<<endl;
		cout<<"Digite otro numero para seguir con la simulacion"<<endl;
		cout<<"\nOpcion:";
		cin>>Opcion;
		cout<<"\nPulse enter";
		getch();
		clrscr();			
	}	
	cout<<"\nTiempo total de Simulacion :"<<tiempo<<" segundos"<<endl;
	cout<<"\nFIN DE LA SIMULACION"<<endl;
	system("Pause");
}
