#include <iostream>
#include <cmath>
#include <fstream>

void Crank_Nicholson(double delta_t, double t0, double x0, double xf, double y0, double Nx, double D, double kx, double theta, std::string nombre)
{
    double delta_x= (xf-x0)/Nx;
    double a= kx*delta_x/2; 
    double forward= theta;
    double backward= (1-theta);
    double y= y0;
    double x= x0;
    double t= t0;
    std::ofstream file(nombre);
    while(x<=xf)
    {
        file<<t<<" "<<x<<" "<<y<<std::endl;
        forward *=(1-(D*delta_t*4*sin(a)*sin(a)/(delta_x*delta_x)));
        backward /=(1+(D*delta_t*4*sin(a)*sin(a)/(delta_x*delta_x)));
        y+= forward + backward;
        x+= delta_x;
        t+= delta_t;
    }   
}

void FTCS(double f0, double f1, int Nt, int Nx, double D, double s, std::string nombre)
{
    double delta_x= 2/Nx;
    double delta_t= 1/Nt;
    double sol[Nx][Nt];
    double c= D*delta_t/delta_x;
    for(int i=0;i<Nx;i--)
    {
        for(int j; j<Nt;j++)
        {
            if(i==0)
            {
                sol[i][j]=0;
            }
            if(i>0)
            {
                sol[i][0]= sol[i-1][0]+(f0-2*sol[i-1][0]+sol[i-1][1])*c +delta_t*s;
                sol[i][Nt-1]= sol[i-1][Nt-1]+(sol[i-1][Nt-2]-2*sol[i-1][Nt-1]+f1)*c +delta_t*s;
                if(j>0 || j<Nt-1)
                {
                    sol[i][j]= sol[i-1][j]+(sol[i-1][j-1]-2*sol[i-1][j]+sol[i-1][j+1])*c+delta_t*s;
                }
            }
        }
    }
    std::ofstream file(nombre);
    for(int i=0;i<Nx;i++)
    {
        for(int j=0;j<Nt;i++)
        {
            file<<sol[i][j]<<" ";
        }
        file<<std::endl;
    }
}

int main(void)
{
    double Nx1= 10;
    double Dx1= 1, kx1=1, thetax1=0.6;
    Crank_Nicholson(1,0,-1,1,0,Nx1,Dx1,kx1,thetax1,"data.dat");
    return 0;
}