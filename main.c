#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Bibliotecas de Guido pq ele é besta
#include <locale.h>
#include <windows.h>
#include <mmsystem.h>

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
    char posicao1[2], posicao2[2], posicaostr[3];
    int opcao_modo;
    int dificuldade;
    int colorarr[37];
    int **bigarr;
    int x, y, w=6, W=6, h=6, H=6;
    int smallarr[6][6];
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

    // GAMEMODE SELECTION AREA

    Sleep(500);
    //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 1 - Unidos somos Fortes (WIP);\n");
    Sleep(200);
    //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 2 - Dividir para Conquistar (WIP);\n");
    Sleep(200);
    //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 3 - Concentração Central;\n");
    Sleep(200);
    //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 4 - Controle da Fronteira (WIP);\n");



    printf("\t Digite o modo de jogo: ");
    while (!valid_gamemode) {
        fflush(stdin);
        scanf("%d", &opcao_modo);
        switch (opcao_modo) {
            case 1:
                paint(1);
                printf("\tDIGITE UMA OPÇÃO VÁLIDA! ");
                reset();
                continue;
            case 2:
                paint(1);
                printf("\tDIGITE UMA OPÇÃO VÁLIDA! ");
                reset();
                continue;
            case 3:
                valid_gamemode = true;
                break;
            case 4:
                paint(1);
                printf("\tDIGITE UMA OPÇÃO VÁLIDA! ");
                reset();
                continue;
            default:
                paint(1);
                printf("\tDIGITE UMA OPÇÃO VÁLIDA! ");
                reset();
                continue;
        }
    }

    // END OF GAMEMODE SELECTION AREA


    printf("\n");


    // THIRD MODE AREA
    if (opcao_modo==3) {

        paint(1);
        printf("     Modo Selecionado: Concentração Central\n");
        reset();

        // THIRD MODE DIFFICULTY SELECTION AREA

        Sleep(500);
        //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 1 - Fácil;\n");
        Sleep(200);
        //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 2 - Médio;\n");
        Sleep(200);
        //PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 3 - Difícil;\n");
        Sleep(200);

        printf("\tSelecione a dificuldade: ");
        while (true) {
            fflush(stdin);
            scanf("%d", &dificuldade);
            if (dificuldade>=1 && dificuldade<=3) {
                break;
            } else {
                paint(1);
                printf("\tDIGITE UMA OPÇÃO VÁLIDA! ");
                reset();
            }
        }

        paint(1);
        if (dificuldade==1) {
            printf("\n\tDificuldade Selecionada: Fácil\n");
        } else if (dificuldade==2) {
            printf("\n\tDificuldade Selecionada: Médio\n");
        } else {
            printf("\n\tDificuldade Selecionada: Difícil\n");
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
                printf("\n\tDigite o número correspondente à\n\tcasa a ser revelada: ");
                scanf("%d", &n);

                if (n<0||n>6||n==5)
                {
                    paint(1);
                    printf("\t    Digite uma casa válida!\n");
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
        printf("\t\tGerando nível.");
        Sleep(500);
        printf(".");
        Sleep(550);
        printf(".\n\n");
        Sleep(490);
        // END OF THIS

        exibeTabuleiro(bigarr, H, h, W, w);

        printf("\n\tPróxima peça: ");
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

                invalid = (bigarr[y][x]!=0 || (bigarr[y-1][x]==0 && bigarr[y+1][x]==0 && bigarr[y][x-1]==0 && bigarr[y][x+1]==0) || (W-w==5 && (x>W || x<w)) || (H-h==5 && (y>H || y<h)))? true : false;

                if ((y>11||y<1)||(x<1||x>11)) {
                    paint(1);
                    printf("\tERRO! DIGITE UMA COORDENADA VÁLIDA!\n\n");
                    reset();
                }

                if (invalid) {
                paint(1);
                printf("\tERRO! COORDENADAS INVÁLIDAS!\n\n");
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

            exibeTabuleiro(bigarr, H, h, W, w);

            printf("\n\tPróxima peça: ");
            paint(colorarr[n+1]);
            printf("#\n");
            reset();
        }
//*/
        printf("\n\t\t ");
        for (int i=0; i<7; i++)
        {
            if (i!=5)
            {
                paint(casasarr[i]);
                printf("# ");
                reset();
            }
        }
        printf("\n\t\t ");
        for (int k=0; k<7; k++)
        {
            if (k!=5)
            {
                printf("%d ", k);
            }
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
    SetConsoleTextAttribute(hConsole, 14);
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


// FUNÇÕES OBRIGATÓRIAS:

int exibeTabuleiro(int **tabuleiro, int W, int w, int H, int h)
{
    for (int i=W-5; i<w+6; i++)
    {
        printf("\t");
        for (int j=H-5; j<h+6; j++)
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
    return 0;
}
