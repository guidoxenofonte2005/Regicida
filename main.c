#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Bibliotecas de Guido pq ele � besta
#include <locale.h>
#include <windows.h>
#include <mmsystem.h>

struct Casa{
    int cor;
    int trancada;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    Sleep(500);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Sleep(500);
    printf("\t\t    REGICIDA\n");
    Sleep(500);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    //PlaySound(" coloca o nome do arquivo aqui ", NULL, SND_FILENAME | SND_ASYNC);

    // VARIABLE AREA
    int array_testes[6][6] = {{1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6}
    };

    char posicao1[2], posicao2[2], posicaostr[3];
    int opcao_modo;
    int dificuldade;
    int colorarr[37];
    int **bigarr;
    int x, y, w=6, W=6, h=6, H=6;

    struct Casa **casas6x6;

    int coordinates;
    int r=0,g=0,ye=0,b=0,p=0,c=0;
    int casasarr[7];
    bool invalid;
    bool valid_gamemode;
    // END OF VARIABLE AREA

    bigarr = (int **)malloc(sizeof(int*)*13);
    for (int i = 0 ; i <13 ; i++)
    {
        bigarr[i] = (int *)malloc(sizeof(int)*13);
    }
    casas6x6 = (struct Casa **) malloc(6*sizeof(struct Casa *));
    for (int i=0; i<6; i++) {
        casas6x6[i] = (struct Casa*) malloc(6*sizeof(struct Casa));
    }

    // GAMEMODE SELECTION AREA

    Sleep(500);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 1 - Unidos somos Fortes (WIP);\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 2 - Dividir para Conquistar (WIP);\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 3 - Concentra��o Central;\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 4 - Controle da Fronteira (WIP);\n");



    printf("\t Digite o modo de jogo: ");
    while (!valid_gamemode) {
        fflush(stdin);
        scanf("%d", &opcao_modo);
        switch (opcao_modo) {
            case 1:
                paint(1);
                printf("\tDIGITE UMA OP��O V�LIDA! ");
                reset();
                continue;
            case 2:
                paint(1);
                printf("\tDIGITE UMA OP��O V�LIDA! ");
                reset();
                continue;
            case 3:
                valid_gamemode = true;
                break;
            case 4:
                paint(1);
                printf("\tDIGITE UMA OP��O V�LIDA! ");
            default:
                reset();
                continue;
                paint(1);
                printf("\tDIGITE UMA OP��O V�LIDA! ");
                reset();
                continue;
        }
    }

    // END OF GAMEMODE SELECTION AREA


    printf("\n");


    // THIRD MODE AREA
    if (opcao_modo==3) {

        paint(1);
        printf("     Modo Selecionado: Concentra��o Central\n");
        reset();

        // THIRD MODE DIFFICULTY SELECTION AREA

        Sleep(500);
        PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 1 - F�cil;\n");
        Sleep(200);
        PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 2 - M�dio;\n");
        Sleep(200);
        PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 3 - Dif�cil;\n");
        Sleep(200);

        printf("\tSelecione a dificuldade: ");
        while (true) {
            fflush(stdin);
            scanf("%d", &dificuldade);
            if (dificuldade>=1 && dificuldade<=3) {
                break;
            } else {
                paint(1);
                printf("\tDIGITE UMA OP��O V�LIDA! ");
                reset();
            }
        }

        paint(1);
        if (dificuldade==1) {
            printf("\n\tDificuldade Selecionada: F�cil\n");
        } else if (dificuldade==2) {
            printf("\n\tDificuldade Selecionada: M�dio\n");
        } else {
            printf("\n\tDificuldade Selecionada: Dif�cil\n");
        }
        reset();

        // END OF DIFFICULTY SELECTION AREA

        Sleep(340);

        // RANDOM STACKING COLORS GENERATION AREA
        for (int i=0; i<36; i++)
        {
            colorarr[i]=randcolornum(&r,&g,&ye,&b,&p,&c,6);
            if (i==35)
            {
                colorarr[i+1]=0;
            }
        }

        for (int i=0;i<13;i++)
        {
            for (int j=0;j<13;j++)
            {
                bigarr[i][j]=(i!=6||j!=6)? 0:colorarr[0];
            }
        }
        // RANDOM STACKING COLORS GENERATION AREA

        r=0,g=0,ye=0,b=0,p=0,c=0;

        for (int i=0; i<7; i++)
        {
            if (i!=5)
            {
                casasarr[i]=randcolornum(&r,&g,&ye,&b,&p,&c,1);
            }
        }

        bool *casasrev = (bool*)malloc(7*sizeof(bool));
        for (int i=0; i<7; i++) {
            casasrev[i] = false;
        }

        for (int i=0;i<=3-dificuldade;i++)
        {
            int n;
            bool rep;
            do
            {
                rep=false;

                printf("\n\t\t  ");
                for (int i=0; i<7; i++)
                {
                    if (i!=5)
                    {
                        if (casasrev[i])
                        {
                            paint(casasarr[i]);
                            printf("# ");
                            reset();
                        }
                        else
                        {
                            printf("# ");
                        }

                    }
                }
                printf("\n\t\t  ");
                for (int k=0; k<7; k++)
                {
                    if (k!=5)
                    {
                        printf("%d ", k);
                    }
                }
                printf("\n\tDigite o n�mero correspondente �\n\tcasa a ser revelada: ");
                scanf("%d", &n);

                if (n<0||n>6||n==5)
                {
                    paint(1);
                    printf("\t    Digite uma casa v�lida!\n");
                    reset();
                }

                for (int j=0;j<7;j++)
                {
                    if (j!=5)
                    {
                        if (casasrev[j] && n==j)
                        {
                            paint(1);
                            printf("\t    Digite uma casa nova!\n");
                            reset();
                            rep = true;
                        }
                    }
                }
                if (!rep)
                {
                    casasrev[n] = true;
                }
            }
            while (n<0||n>6||n==5||rep);


            Sleep(50);

        }
        printf("\n\t\t  ");
        for (int i=0; i<7; i++)
        {
            if (i!=5)
            {
                if (casasrev[i])
                {
                    paint(casasarr[i]);
                    printf("# ");
                    reset();
                }
                else
                {
                    printf("# ");
                }

            }
        }
        printf("\n\t\t  ");
        for (int k=0; k<7; k++)
        {
            if (k!=5)
            {
                printf("%d ", k);
            }
        }

        Sleep(200);

        printf("\n\n");

        // LEVEL GENERATION TEXT
        printf("\t\tGerando n�vel.");
        Sleep(500);
        printf(".");
        Sleep(550);
        printf(".\n\n");
        Sleep(490);
        // END OF THIS

        exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 1);

        printf("\n\tPr�xima pe�a: ");
        paint(colorarr[1]);
        printf("#\n");
        reset();

/*/
        // CODE FOR INPUTS
        for (int n=1;n<36;n++)
        {
            // COORDINATE INPUT AREA
            do
            {
                printf("\tDigite a coordenada: ");
                fflush(stdin);
                fgets(posicaostr, 3, stdin);

                posicao1[0] = posicaostr[0];
                posicao2[0] = posicaostr[1];
                y = (int)strtol(posicao1, NULL, 16);
                x = (int)strtol(posicao2, NULL, 16);

                //importante
                invalid = (bigarr[y][x]!=0 || (bigarr[y-1][x]==0 && bigarr[y+1][x]==0 && bigarr[y][x-1]==0 && bigarr[y][x+1]==0) || (W-w==5 && (x>W || x<w)) || (H-h==5 && (y>H || y<h)))? true : false;
                //fim do importante
                if ((y>11||y<1)||(x<1||x>11)) {
                    paint(1);
                    printf("\tERRO! DIGITE UMA COORDENADA V�LIDA!\n\n");
                    reset();
                }

                if (invalid) {
                paint(1);
                printf("\tERRO! COORDENADAS INV�LIDAS!\n\n");
                reset();
                }

            } while ((y>11||y<1)||(x<1||x>11)||invalid);
            // END OF COORDINATE INPUT AREA

            // MAX AND MIN HEIGHT/WIDTH CHECKING AREA
            if (H-h!=5)
            {
                if (y>H) {
                    H = y;
                }
                if (y<h) {
                    h = y;
                }
            }
            if (W-w!=5)
            {
                if (x>W) {
                    W = x;
                }
                if (x<w) {
                    w = x;
                }
            }
            // END OF THAT SHIT
            //printf(" W: %d\n w: %d\n H: %d\n h: %d\n",W,w,H,h);

            bigarr[y][x]=colorarr[n];

            printf("\n");

            printf("\n\t\t  ");
            for (int i=0; i<7; i++)
            {
                if (i!=5)
                {
                    if (casasrev[i])
                    {
                        paint(casasarr[i]);
                        printf("# ");
                        reset();
                    }
                    else
                    {
                        printf("# ");
                    }

                }
            }
            printf("\n\t\t  ");
            for (int k=0; k<7; k++)
            {
                if (k!=5)
                {
                    printf("%d ", k);
                }
            }
            printf("\n");

            exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 1);

            printf("\n\tPr�xima pe�a: ");
            paint(colorarr[n+1]);
            printf("#\n");
            reset();
        }
//*/
        // END OF INPUT

        printf("\n\t\t");
        for (int i=0; i<7; i++)
        {
            if (i!=5)
            {
                paint(casasarr[i]);
                printf("# ");
                reset();
            }
        }
        printf("\n\t\t");
        for (int k=0; k<7; k++)
        {
            if (k!=5)
            {
                printf("%d ", k);
            }
        }
        printf("\n");

        // FASE DE INTRIGA
        int k=0, l=0;
        for (int i=0/*H-5*/; i<6/*h+6*/; i++){
            for (int j=0/*W-5*/; j<6/*w+6*/; j++){
                casas6x6[k][l].cor = array_testes[i][j]/*bigarr[i][j]*/;
                l++;
            }
            k++;
            l=0;
        }
        // Valida��o da matriz pequena

        // Fim da valida��o

        for (int i=0; i<6; i++) {
            paint(1);
            printf("\t\t   FASE DE INTRIGA\n\t\t%d INTRIGAS RESTANTES\n\n", 6-i);
            reset();

            exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 2);

            char posicao_pequeno[3];
            char posicao1_peq[2], posicao2_peq[2];
            int valido;

            do {
                printf("\tCasa 1 >- ");
                fflush(stdin);
                fgets(posicao_pequeno, 3, stdin);

                posicao1_peq[0] = posicao_pequeno[0];
                posicao2_peq[0] = posicao_pequeno[1];
                int x1_peq = (int)strtol(posicao1_peq, NULL, 16);
                int y1_peq = (int)strtol(posicao2_peq, NULL, 16)-9;

                printf("\tCasa 2 >- ");
                fflush(stdin);
                fgets(posicao_pequeno, 3, stdin);

                posicao1_peq[0] = posicao_pequeno[0];
                posicao2_peq[0] = posicao_pequeno[1];
                int x2_peq = (int)strtol(posicao1_peq, NULL, 16);
                int y2_peq = ((int)strtol(posicao2_peq, NULL, 16))-9;

                valido = validaIntriga(x1_peq, x2_peq, y1_peq, y2_peq);
                if (!valido) {
                    paint(1);
                    printf("\tDIGITE CASAS ADJACENTES!\n");
                    reset();
                }
            } while (!valido);
        }


    }
    // END OF THIRD MODE AREA
}


// COLOR FUNCTIONS AREA:

void red() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
}

void green() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
}

void yellow() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
}

void blue() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
}

void purple() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);
}

void cyan() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
}

void reset() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
}

// END OF COLOR FUNCTIONS


// RANDOM COLOR GENERATOR:

int randcolornum(int *r, int *g, int *ye, int *b, int *p, int *c, int Max)
{
    int upper = 6, lower = 1;
    int n;
    do
    {

        n = (rand() % (upper - lower + 1)) + lower;
    }
    while((*r==Max&&n==1)||(*g==Max&&n==2)||(*ye==Max&&n==3)||(*b==Max&&n==4)||(*p==Max&&n==5)||(*c==Max&&n==6));

    switch (n)
    {
        case 1:
            (*r)++;
            break;
        case 2:
            (*g)++;
            break;
        case 3:
            (*ye)++;
            break;
        case 4:
            (*b)++;
            break;
        case 5:
            (*p)++;
            break;
        case 6:
            (*c)++;
            break;
    }
    //printf("%d %d %d %d %d %d\n",*r,*g,*ye,*b,*p,*c);
    return n;
}


// PAINTING FUNCTION

void paint(int n)
{
    switch (n)
    {
        case 1:
            red();
            break;
        case 2:
            green();
            break;
        case 3:
            yellow();
            break;
        case 4:
            blue();
            break;
        case 5:
            purple();
            break;
        case 6:
            cyan();
            break;
    }
}


// FUN��ES OBRIGAT�RIAS:

int exibeTabuleiro(int **tabuleiro, struct Casa **tabuleiroMini, int H, int h, int W, int w, int modo)
{
    switch (modo) {
    case 1:
        for (int i=H-5; i<h+6; i++)
        {
            printf("\t");
            for (int j=W-5; j<w+6; j++)
            {
                if (tabuleiro[i][j]==0)
                {
                    Sleep(5);
                    printf("%x%x ", i,j);
                }
                else
                {
                    Sleep(5);
                    paint(tabuleiro[i][j]);
                    printf(" # ");
                    reset();
                }
            }
            printf("\n");
        }
        break;
    case 2:
        printf("\t\t   1  2  3  4  5  6\n");
        for (int i=0; i<6; i++)
        {
            int j = 0;
            printf("\t\t");
            printf("%x ", i+10);
            for (j=0; j<6; j++)
            {
                Sleep(5);
                paint(tabuleiroMini[i][j].cor);
                printf(" # ");
                reset();
            }
            printf("\n");
        }
        break;
    default:
        printf("ERRO");
        break;
    }

    return 0;
}

int validaIntriga(int x1_peq, int x2_peq, int y1_peq, int y2_peq) {

    int valid = (((y2_peq==y1_peq && (x2_peq-x1_peq==1 || x2_peq-x1_peq==-1))||(x2_peq==x1_peq && (y2_peq-y1_peq==1 || y2_peq-y1_peq==-1)))
                          &&(x1_peq<7&&x1_peq>0)&&(x2_peq<7&&x2_peq>0)&&(y1_peq<7&&y1_peq>0)&&(y2_peq<7&&y2_peq>0)) ? 1 : 0;

    return valid;
}

int fazIntriga(){

}

// gildo mexendo no git
