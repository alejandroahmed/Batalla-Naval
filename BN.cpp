#include <iostream>
using namespace std;

void mat_en_cero(int mat[][10]);
void mat_en_x(int mat[][10]);
void parte1(int mat[][10]);
void parte2(int mat[][10]);
void parte3(int mat[][10]);
void parte4(int mat[][10]);
void batalla(int tir,int &j,int h[],int a[], int mat[][10]);
void tablero(int j);
int mat1[10][10];
int mat2[10][10];

int main(int argc, char *argv[])
{
    int cant=2;
        
    char jug[10][10];
    for(int i=0;i<cant;i++)
	{
        cout<<"Nombre jugador "<<i+1<<": ";
        cin>>jug[i];
        cout<<endl;
    }
    cout<<"RECUERDEN ELEGIR CORRECTAMENTE LA POSICIÓN DE SUS BARCOS - Si los superponen, perderan alguna parte.";
    int tir=10;
    int h[10],a[10];
    int i=1,gan=0,seg=0;
    cout<<"\n\n"<<jug[0]<<" arma el tablero\n";
    for(int f=0;f<cant;f++)
	{
		if (f==1)
		{
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout<<"\n\n"<<jug[1]<<" arma el tablero\n";
		}
		tablero(f);
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n"<<jug[0]<<" hace uso de sus 30 intentos\n";
    for(int f=0;f<cant;f++)
	{		
		if (f==0)
		{
			batalla(tir,i,h,a, mat2);
		}
		else
		{
			cout<<"\n"<<jug[1]<<" hace uso de sus 30 intentos\n";
			batalla(tir,i,h,a, mat1);
		}
        i++;
	}
	if (h[0]<h[1])
	{	
		gan = 1;
	}
    cout<<"\n\nGANADOR: "<<jug[gan]<<endl;
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
	void batalla(int tir,int &j,int h[],int a[], int mat1[][10])
	{
        h[j]=0;
        a[j]=0;
    /*
	    for(int i=0;i<10;i++)
		{
            for(int j=0;j<10;j++)
			{
            	cout<<mat1[i][j]<<"\t";
			}
            cout<<endl;
		}
    */     
        int k=5;
        int fal[10][10],col,c1=0,fil;
        mat_en_x(fal);
        while(c1<tir)
		{
            cout<<"Tiro"<<endl<<endl;
            cout<<"Fila: "<<endl;
            cin>>fil;
            cout<<"Columna: "<<endl;
            cin>>col;
            if(mat1[fil-1][col-1]==0)
			{
                cout<<endl<<"AGUA"<<endl<<endl;
            }
			else
			{
                if(mat1[fil-1][col-1]==1)
				{
                    cout<<"Has HUNDIDO el barco de 1 parte, ¡Felicitaciones!"<<endl;fal[fil-1][col-1]=1;
					h[j]++;
				}
                if(mat1[fil-1][col-1]==2)
				{
                    cout<<"Has DAÑADO el barco de 2 partes"<<endl;
					fal[fil-1][col-1]=2;
                    mat1[fil-1][col-1]=0;
                    for(int i=0;i<10;i++)
                	    for(int j=0;j<10;j++)
                		    if(mat1[i][j]==2)
							{
                        		//cout<<"¡Muy Bien!"<<endl;
                        		a[j]++;
								k=0;
								h[j]++;
							}
                        	if(k==5)
							{
								cout<<"Has HUNDIDO el barco de 2 partes, ¡Felicidades!"<<endl;
								h[j] = h[j] + 2;
							}
        		}
                if(mat1[fil-1][col-1]==3)
				{
                    cout<<"Has DAÑADO el barco de 3 partes"<<endl;
					fal[fil-1][col-1]=3;
                    mat1[fil-1][col-1]=0;
                    for(int i=0;i<10;i++)
                    	for(int j=0;j<10;j++)
                    		if(mat1[i][j]==3)
							{
                        		//cout<<"¡Muy Bien!"<<endl;
								a[j]++;
								k=0;
								h[j]++;
							}
                    		if(k==5)
							{
								cout<<"Has HUNDIDO el barco de 3 partes, ¡Buen trabajo!"<<endl;
								h[j] = h[j] + 2;
							}
            	}
                if(mat1[fil-1][col-1]==4)
				{
                    cout<<"Has DAÑADO el barco de 4 partes"<<endl;
					fal[fil-1][col-1]=4;
                    mat1[fil-1][col-1]=0;
                    for(int i=0;i<10;i++)
                    	for(int j=0;j<10;j++)
                    		if(mat1[i][j]==4)
							{
                        		//cout<<"¡Muy Bien!"<<endl;
								a[j]++;
								k=0;
								h[j]++;
							}
                    		if(k==5)
							{
								cout<<"Has HUNDIDO el barco de 4 partes, ¡Magistral!"<<endl;
								h[j]=h[j]+2;								
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
        }
    }
