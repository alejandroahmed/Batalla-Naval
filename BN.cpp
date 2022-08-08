#include <iostream>
using namespace std;

void mat_en_cero(int mat[][10]);
void mat_en_x(int mat[][10]);
void parte1(int mat[][10]);
void parte2(int mat[][10]);
void parte3(int mat[][10]);
void parte4(int mat[][10]);
void batalla(int tir,int ju,int h[], int mat[][10]);
void tablero(int j);
int mat1[10][10];
int mat2[10][10];

int main(int argc, char *argv[])
{
    int cant=2; //cant=cantidad de jugadores

    char jug[10][10]; //tablero
    for(int i=0;i<cant;i++) //pide y lee los nombres de los jugadores
{
        cout<<"Nombre jugador "<<i+1<<": ";
        cin>>jug[i];
        cout<<endl;
    }
    cout<<"RECUERDEN ELEGIR CORRECTAMENTE LA POSICION DE SUS BARCOS - Si los superponen, perderan alguna parte.";
    int tir=30; //cantidad de intentos
    int h[1];
    h[0] = 0;
    h[1] = 0;
    int i=1,gan=0,seg=0;
    cout<<"\n\n"<<jug[0]<<" arma el tablero\n"; //llama al primer jugador a armar su tablero
    for(int f=0;f<cant;f++)
{
if (f==1)
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"\n\n"<<jug[1]<<" arma el tablero\n"; //llama al segundo jugador a armar su tablero
}
tablero(f); //arman los tableros
}
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"\n"<<jug[0]<<" hace uso de sus 30 intentos\n";
    for(int f=0;f<cant;f++)
{
if (f==0)
{
batalla(tir,0,h, mat2);
}
else
{
cout<<"\n"<<jug[1]<<" hace uso de sus 30 intentos\n";
batalla(tir,1,h, mat1);
}
        i++;
}

if (h[0]<h[1])
{
gan = 1;
}
else if (h[0]>h[1])
{
gan = 0;
}
    cout<<"\n\nGANADOR: "<<jug[gan]<<", "<<h[0]<<" a "<<h[1]<<endl;
    return 0;
}

void mat_en_x(int fal [][10])
{
    for(int i=0;i<10;i++)
    {
    for(int j=0;j<10;j++)
    {
    fal[i][j]=0;
}
}  
}
void mat_en_cero(int mat [][10])
{
        for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        mat[i][j]=0;
    }
void parte1(int mat[][10])
{
int fil,col;
cout<<"\nBarco de 1 parte"<<endl<<"Fila"<<endl;
cin>>fil;
cout<<"Columna"<<endl;
cin>>col;
mat[fil-1][col-1]=1;
}
void parte2(int mat[][10])
{
        int fil,col;
        cout<<"\nBarco de 2 partes"<<endl;
        for(int i=0;i<2;i++)
{
        cout<<"Fila"<<endl;
        cin>>fil;
        cout<<"Columna"<<endl;
        cin>>col;
        mat[fil-1][col-1]=2;
    }
    }
void parte3(int mat[][10])
{
        int fil,col;
        cout<<"\nBarco de 3 partes"<<endl;
        for(int i=0;i<3;i++)
{
            cout<<"Fila"<<endl;
            cin>>fil;
            cout<<"Columna"<<endl;
            cin>>col;
            mat[fil-1][col-1]=3;
        }
}
void parte4(int mat[][10])
{
        int fil,col;
        cout<<"\nBarco de 4 partes"<<endl;
        for(int i=0;i<4;i++)
{
            cout<<"Fila"<<endl;
            cin>>fil;
            cout<<"Columna"<<endl;
            cin>>col;
            mat[fil-1][col-1]=4;
        }
}
void tablero(int j)
{
if (j==0)
{
  mat_en_cero(mat1);
    parte1(mat1);
    parte2(mat1);
    parte3(mat1);
    parte4(mat1);
    cout<<"Su tablero: "<<endl;
    for(int i=0;i<10;i++)
{
           for(int k=0;k<10;k++)
{
            cout<<mat1[i][k]<<"\t";
}
           cout<<endl;
}
}
else
{
mat_en_cero(mat2);
   parte1(mat2);
    parte2(mat2);
    parte3(mat2);
    parte4(mat2);
   
cout<<"Su tablero: "<<endl;
    for(int i=0;i<10;i++)
{
           for(int k=0;k<10;k++)
{
            cout<<mat2[i][k]<<"\t";
}
           cout<<endl;
}
}
}
void batalla(int tir,int ju,int h[], int mat1[][10])
{
        h[ju]=0;
        int k=5;
        int fal[10][10],col,c1=0,fil;
        mat_en_x(fal);
        while(c1<tir)
{
            cout<<"Tiro "<<c1+1<<endl<<endl;
            cout<<"Fila: "<<endl;
            cin>>fil;
            cout<<"Columna: "<<endl;
            cin>>col;
            if(mat1[fil-1][col-1]==0)
{
                cout<<endl<<"AGUA (-1)"<<endl<<endl;
                fal[fil-1][col-1]=-1;
            }
else
{
                if(mat1[fil-1][col-1]==1)
{
                    cout<<"Has HUNDIDO el barco de 1 parte, felicitaciones!"<<endl;
fal[fil-1][col-1]=1;
h[ju]++;
}
                if(mat1[fil-1][col-1]==2)
{
                    cout<<"Has DANIADO el barco de 2 partes"<<endl;
fal[fil-1][col-1]=2;
                    mat1[fil-1][col-1]=0;
                    for(int i=0;i<10;i++)
                   for(int j=0;j<10;j++)
                   if(mat1[i][j]==2)
{
                        //cout<<"¡Muy Bien!"<<endl;
k=0;
h[ju]++;
}
                        if(k==5)
{
cout<<"Has HUNDIDO el barco de 2 partes, felicidades!"<<endl;
h[ju] = h[ju] + 2;
}
        }
                if(mat1[fil-1][col-1]==3)
{
                    cout<<"Has DANIADO el barco de 3 partes"<<endl;
fal[fil-1][col-1]=3;
                    mat1[fil-1][col-1]=0;
                    for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                    if(mat1[i][j]==3)
{
                        //cout<<"¡Muy Bien!"<<endl;
k=0;
h[ju]++;
}
                    if(k==5)
{
cout<<"Has HUNDIDO el barco de 3 partes, buen trabajo!"<<endl;
h[ju] = h[ju] + 2;
}
            }
                if(mat1[fil-1][col-1]==4)
{
                    cout<<"Has DANIADO el barco de 4 partes"<<endl;
fal[fil-1][col-1]=4;
                    mat1[fil-1][col-1]=0;
                    for(int i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                    if(mat1[i][j]==4)
{
                        //cout<<"¡Muy Bien!"<<endl;
k=0;
h[ju]++;
}
                    if(k==5)
{
cout<<"Has HUNDIDO el barco de 4 partes, magistral!"<<endl;
h[ju]=h[ju]+2;
}
                }
                                             
            }
            for(int i=0;i<10;i++)
{
                for(int j=0;j<10;j++)
{                    
                    cout<<fal[i][j]<<"\t";
}
                cout<<endl;
            }
            /*cout<<endl<<endl<<endl<<endl;*/
            c1++;
            k=5;
            cout<<"Puntaje: "<<h[ju]<<endl;  
            if (h[ju]==17)
            {
            c1 = tir;
}
        }
    }
