#include <playAPC/playapc.h>
#include <math.h>
//tetse para github
int main()
{

    int sol, terra, Lua;
    double R, r, Ang;
    Ponto P1, P2, P3, Ps;

    AbreJanela(700, 700, "SistemaSolar");
    MostraPlanoCartesiano(10);
    PintarFundo(10, 10, 10);

    P1.x     =   0;
    P1.y     =   0;
    R        =   0;
    Ps.x     =   40;
    Ps.y     =   0;



    Lua     = CriaGrupo();      CriaCirculo(1,P1);      Pintar(200,200,200);

    terra   = CriaGrupo();      CriaCirculo(2,P1);      Pintar (0,0,255);

    sol     = CriaGrupo();      CriaCirculo(5,Ps);      Pintar (255,255,0);

    for (Ang = 0;  ; Ang +=10)
    {
        R = 1500/(sqrt(2500*pow(sin(Ang),2) + 900*pow(cos(Ang),2)));
        P2.x = R*cos(Ang);
        P2.y = R*sin(Ang);
        Move(P2,terra);//translada Terra para sua órbita

        r = 15/(sqrt(25*pow(sin(Ang*13),2) + 9*pow(cos(Ang*13),2)));
        P3.x = r*cos(Ang*13)+P2.x;
        P3.y = r*sin(Ang*13)+P2.y;
        Move(P3,Lua);//translada Lua para sua órbita

        Desenha1Frame();
    }
        Desenha();

        return 0;
    }
