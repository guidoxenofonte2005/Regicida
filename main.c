#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Bibliotecas de Guido pq ele é besta
#include <locale.h>
#include <windows.h>
#include <mmsystem.h>

struct Casa{
    int cor;
    int trancada;
};

HANDLE wHnd;
HANDLE rHnd;

int main()
{
    config();
    mciSendString("open Sounds\\OST\\Requiem_for_a_Dream.wav alias REQUIEM", NULL, 0, NULL);
    mciSendString("play REQUIEM", NULL, 0, NULL);
    start();

    // VARIABLE AREA
    int array_testes[6][6] = {{1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6},
                              {1, 2, 3, 4, 5, 6}
    };

    char posicao1[2], posicao2[2], posicaostr[3];
    int escolha;
    int voltar;
    int opcao_modo;
    int modo;
    int valor_pulado;
    int dificuldade;
    int colorarr[37];
    int **bigarr;
    int x, y, w=6, W=6, h=6, H=6;

    struct Casa **casas6x6;

    int coordinates;
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

    // INITIAL CHOICE AREA
    do{
        Sleep(500);
        PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 1 - Jogar;\n");
        Sleep(200);
        PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 2 - Regras;\n");
        Sleep(200);
        PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
        printf("\t 3 - Créditos;\n");
        Sleep(200);
        printf("\t Escolha uma das opções: ");
        scanf("%d", &escolha);

        if (escolha == 1){
            paint(1);
            printf("\n\tOpção Selecionada: Jogar\n\n");
            reset();
        }
        else if (escolha == 2){
            rules();

            do{
            paint(1);
            printf("\tDigite 0 para sair das regras e voltar para as opções: ");
            reset();
            fflush(stdin);
            scanf("%d", &voltar);
            }while (voltar != 0);
            printf("\n");
        }
        else if (escolha == 3){
            credits();

            do{
            paint(1);
            printf("\tDigite 0 para sair dos créditos e voltar para as opções: ");
            reset();
            fflush(stdin);
            scanf("%d", &voltar);
            }while (voltar != 0);
            printf("\n");
        }
        else{
            paint(1);
            printf("\tDIGITE UMA OPÇÃO VÁLIDA!\n\n");
            reset();
        }
        }while (escolha != 1);

    // END OF INITIAL CHOICE AREA

    // GAMEMODE SELECTION AREA

    Sleep(500);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 1 - Unidos somos Fortes (WIP);\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 2 - Dividir para Conquistar (WIP);\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 3 - Concentração Central;\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 4 - Controle da Fronteira;\n");

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
                modo = 1;
                valor_pulado = 5;
                break;
            case 4:
                valid_gamemode = true;
                modo = 2;
                valor_pulado = 1;
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
    if (opcao_modo==3)
    {
        paint(1);
        printf("\tModo Selecionado: Concentração Central\n\n");
        reset();
    }else if (opcao_modo==4)
    {
        paint(1);
        printf("\tModo Selecionado: Controle da Fronteira\n\n");
        reset();
    }

    // THIRD MODE DIFFICULTY SELECTION AREA

    Sleep(500);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 1 - Fácil;\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 2 - Médio;\n");
    Sleep(200);
    PlaySound("Sounds\\SFX\\blipSelect.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t 3 - Difícil;\n");
    Sleep(200);

    printf("\t Selecione a dificuldade: ");
    while (true) {
        fflush(stdin);
        scanf("%d", &dificuldade);
        if (dificuldade>=1 && dificuldade<=3) {
            break;
        } else {
            paint(1);
            printf("\t DIGITE UMA OPÇÃO VÁLIDA! ");
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


    embaralhar(bigarr, colorarr, casasarr, valor_pulado);


    bool *casasrev = (bool*)malloc(7*sizeof(bool));
    for (int i=0; i<7; i++) {
        casasrev[i] = false;
    }

    bool *cortranc = (bool*)malloc(7*sizeof(bool));
    for (int i=1; i<7; i++) {
        cortranc[i] = false;
    }


    for (int i=0;i<=3-dificuldade;i++)
    {
        int n;
        bool rep;
        do
        {
            rep=false;

            imprime_N_das_cores(casasarr, casasrev, cortranc, valor_pulado);

            printf("\t Digite o número correspondente à\n\tcasa a ser revelada: ");
            scanf("%d", &n);

            if (n<0||n>6||n==valor_pulado)
            {
                paint(1);
                printf("\t    Digite uma casa válida!\n");
                reset();
            }

            for (int j=0;j<7;j++)
            {
                if (j!=valor_pulado)
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
        while (n<0||n>6||n==valor_pulado||rep);


        Sleep(50);

    }

    imprime_N_das_cores(casasarr, casasrev, cortranc, valor_pulado);

    Sleep(200);

    mciSendString("stop REQUIEM", NULL, 0, NULL);

    // LEVEL GENERATION TEXT
    printf("\t\tGerando nível.");
    Sleep(800);
    printf(".");
    Sleep(500);
    printf(".\n\n");
    Sleep(200);
    // END OF THIS
    paint(1);

    PlaySound("Sounds\\SFX\\changeRound.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\t\t\t   FASE DE EXPANSÃO\n\n\n");
    reset();
    Sleep(1000);

    //mciSendString("open Sounds\\OST\\The_Puppeteers_Tale.wav alias REQUIEM", NULL, 0, NULL);
    //mciSendString("play REQUIEM", NULL, 0, NULL);
    PlaySound("Sounds\\OST\\The_Puppeteers_Tale.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 1);
    printf("\n\tPróxima peça: ");
    paint(colorarr[1]);
    printf("#\n");
    reset();
//*/
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
                printf("\tERRO! DIGITE UMA COORDENADA VÁLIDA!\n\n");
                reset();
            } else if (invalid) {
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
        // END OF THAT
        //printf(" W: %d\n w: %d\n H: %d\n h: %d\n",W,w,H,h);
        bigarr[y][x]=colorarr[n];

        imprime_N_das_cores(casasarr, casasrev, cortranc, valor_pulado);

        exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 1);

        if (n!=35) {
            printf("\n\tPróxima peça: ");
            paint(colorarr[n+1]);
            printf("#\n");
            reset();
        }
    }

//*/
    // END OF INPUT
    paint(1);
    printf("\n\n\t\t\tPONTUAÇÕES DAS CASAS:\n");
    reset();

    for (int i=0;i<7;i++)
    {
        if (i!=valor_pulado)
        {
            casasrev[i]=true;
        }
    }
    imprime_N_das_cores(casasarr, casasrev, cortranc, valor_pulado);

    // FASE DE INTRIGA
    int k=0, l=0;
    for (int i=H-5; i<h+6; i++){
        for (int j=W-5; j<w+6; j++){
            casas6x6[k][l].cor = bigarr[i][j];
            l++;
        }
        k++;
        l=0;
    }
    // Validação da matriz pequena

    // Fim da validação
    PlaySound(NULL, NULL, NULL);
    paint(1);
    PlaySound("Sounds\\SFX\\changeRound.wav", NULL, SND_FILENAME | SND_ASYNC);
    printf("\n\t\t\t   FASE DE INTRIGA\n");
    reset();
    Sleep(1000);
    PlaySound(NULL, NULL, NULL);
    PlaySound("Sounds\\OST\\The_Puppeteers_Tale.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    for (int i=0; i<6; i++)
    {
        Sleep(500);
        paint(1);
        printf("\t\t\t%d INTRIGAS RESTANTES\n", 6-i);
        reset();

        if (pontosCorretos(casas6x6, casasarr, modo, valor_pulado))
        {
            exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 2);

            victory();
            break;
        }

        exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 2);

        char posicao_pequeno[3];
        char posicao1_peq[2], posicao2_peq[2];
        int valido;

        int x1_peq;
        int y1_peq;
        int x2_peq;
        int y2_peq;

        do
        {
            do
            {
                printf("\t\t    Digite 00 se quer desistir: \n");
                printf("\t\t    Casa 1 >- ");
                fflush(stdin);
                fgets(posicao_pequeno, 3, stdin);

                posicao1_peq[0] = posicao_pequeno[0];
                posicao2_peq[0] = posicao_pequeno[1];
                x1_peq = (int)strtol(posicao1_peq, NULL, 16)-1;
                y1_peq = (int)strtol(posicao2_peq, NULL, 16)-1;

                if (x1_peq==-1 && y1_peq==-1)
                {
                    defeat();
                    return 0;
                }else if (x1_peq>5||x1_peq<0||y1_peq>5||y1_peq<0)
                {
                    paint(1);
                    printf("\t\t    DIGITE UMA COORDENADA VÁLIDA!\n");
                    reset();
                }

            } while(x1_peq>5||x1_peq<0||y1_peq>5||y1_peq<0);

            do
            {
                printf("\t\t    Casa 2 >- ");
                fflush(stdin);
                fgets(posicao_pequeno, 3, stdin);

                posicao1_peq[0] = posicao_pequeno[0];
                posicao2_peq[0] = posicao_pequeno[1];
                x2_peq = (int)strtol(posicao1_peq, NULL, 16)-1;
                y2_peq = (int)strtol(posicao2_peq, NULL, 16)-1;

                 if (x2_peq==-1 && y2_peq==-1)
                {
                    defeat();
                    return 0;
                }else if (x2_peq>5||x2_peq<0||y2_peq>5||y2_peq<0)
                {
                    paint(1);
                    printf("\t\t    DIGITE UMA COORDENADA VÁLIDA!\n");
                    reset();
                }

            } while(x2_peq>5||x2_peq<0||y2_peq>5||y2_peq<0);


            valido = validaIntriga(casas6x6, cortranc, x1_peq, x2_peq, y1_peq, y2_peq);

        } while (!valido);

        fazIntriga(casas6x6, cortranc, casasarr, x1_peq, x2_peq, y1_peq, y2_peq);

        imprime_N_das_cores(casasarr, casasrev, cortranc, valor_pulado);


    }
    if (!pontosCorretos(casas6x6, casasarr, modo, valor_pulado))
        {
            exibeTabuleiro(bigarr, casas6x6, H, h, W, w, 2);

            //PlaySound(NULL, NULL, NULL);
            defeat();
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

// START FUNCTION:

void start(){
    Sleep(500);
    paint(1);
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    Sleep(500);
    printf("\t\t   ___ ___ ___ ___ ___ ___ ___   _\n");
    printf("\t\t  | _ \\ __/ __|_ _/ __|_ _|   \\ /_\\\n");
    printf("\t\t  |   / _| (_ || | (__ | || |) / _ \\\n");
    printf("\t\t  |_|_\\___\\___|___\\___|___|___/_/ \\_\\\n\n");
    reset();

    paint(3);
    Sleep(500);
    printf("\t\t\t          ___\n");
    printf("\t\t\t __  __   \\o/   __  __\n");
    printf("\t\t\t \\*) \\*)  |O|  (*/ (*/\n");
    printf("\t\t\t  \\*\\_\\*\\_|*|_/*/_/*/\n");
    printf("\t\t\t   \\_______________/ \n");
    reset();

    printf("\t\t\t        .-=-=-.\n");
    printf("\t\t\t       /       \\\n");
    printf("\t\t\t      |         |\n");
    printf("\t\t\t      | )     ( |\n");
    printf("\t\t\t\      \\/");
    paint(1);
    printf(" 0");
    reset();
    printf("\\ /");
    paint(1);
    printf("0 ");
    reset();
    printf("\\/\n");
    printf("\t\t\t      (    ^    )\n");
    printf("\t\t\t       |.     .|\n");
    printf("\t\t\t       ||xxxxx||\n");
    printf("\t\t\t       '-._._.-'\n\n");

    Sleep(500);
    paint(1);
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    reset();
}

// CONFIGURATION FUNCTION:

void config(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    // CONSOLE AREA
    HWND consoleWindow = GetConsoleWindow();

    SetWindowPos( consoleWindow, 0, 550, 160, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle("REGICIDA");
    SMALL_RECT windowSize = {0, 0, 70, 30};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
}

// FUNCION TO SHOW THE RULES:

void rules(){
    paint(1);
    printf("\n\tOpção Selecionada: Regras\n\n");
    reset();
    paint(2);
    Sleep(500);
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    Sleep(1000);
    printf("\t\t     ____ ____ ____ ____ ____ ____ \n");
    printf("\t\t     |__/ |___ | __ |__/ |__| [__  \n");
    printf("\t\t     |  \\ |___ |__] |  \\ |  | ___]\n\n");
    Sleep(1000);
    printf("\tAs Casas estão disputando ferozmente pelo Trono. Resta você, \ndono de todos os segredos, manipular vassalos e nobres para chegar num \n");
    printf("resultado que, apesar de não agradar a todos, trará paz. Entretanto, o \ntempo é escasso e algumas das suas preciosas informações tardam a che-\n");
    printf("gar. Você precisará trabalhar com incertezas por um momento. E quando\nas informações chegarem, talvez seja tarde demais para reverter a situ-\n");
    printf("ação. A guerra pode estar mais perto do que nunca e a única pessoa ca-\npaz de evitá-la é você.\n\n");
    Sleep(1000);
    printf("     I) Visão Geral\n");
    printf("\tVocê representa o Titereiro, figura enigmática e muito influen-\nte. Após quatro Fases (Preparação, Expansão, Corvo e Intriga) você ven-\n");
    printf("cerá a partida se conseguir colocar cada Casa na pontuação definida no\ncomeço da partida. Evitando, assim, a guerra.\n\n");
    Sleep(1000);
    printf("     II) Preparação\n");
    printf("\tEscolha o modo de jogo e a dificuldade, que é quem define a\nquantidade de peças que poderão ter sua pontuação revelada.\n\n");
    Sleep(1000);
    printf("     III) Fase de Expansão\n");
    printf("\tNessa fase, você irá preencher o tabuleiro 11x11, por meio das\ncoordenadas, com as peças que forem entregues pelo sistema, de modo que\n");
    printf("o tabuleiro fique preenchido no formato 6x6 ao final. Você deve inserir\nas peças em casas adjacentes às que já possuem alguma peça inserida.\n\n");
    Sleep(1000);
    printf("     IV) Fase do Corvo e da Intriga\n");
    printf("\tApós o preenchimento do tabuleiro, as pontuações de todas as\npeças serão reveladas. Você terá a oportunidade de realizar seis intri-\n");
    printf("gas, que significa manipular a posição das peças, para que o tabuleiro\nfique com a pontuação correta de cada peça, de acordo com os seguintes\n");
    printf("modos:\n");
    printf("\t   [#][#][#][#][#][#]\t\t[ ][ ][ ][ ][ ][ ]\n");
    printf("\t   [#][ ][ ][ ][ ][#]\t\t[ ][#][#][#][#][ ]\n");
    printf("\t   [#][ ][ ][ ][ ][#]\t\t[ ][#][#][#][#][ ]\n");
    printf("\t   [#][ ][ ][ ][ ][#]\t\t[ ][#][#][#][#][ ]\n");
    printf("\t   [#][ ][ ][ ][ ][#]\t\t[ ][#][#][#][#][ ]\n");
    printf("\t   [#][#][#][#][#][#]\t\t[ ][ ][ ][ ][ ][ ]\n");
    printf("\t Controle das Fronteiras       Concentração Central\n\n");
    printf("\tVocê deve escolher duas fichas adjacentes para trocá-las de lu-\ngar. Em seguida deve trancar uma das duas peças selecionadas, e por úl-\ntimo trancar uma das cores que as duas peças possuem. Após trancar a\npeça no tabuleiro, esta não poderá mais ser mexida de forma alguma.\n");
    printf("Após trancar a cor, você somente não poderá mais mexer em peças daquela\ncor se tentar mexer com outra peça na qual sua cor também está tranca-\nda.");
    printf("\n\tO trancamento de uma peça é representado com os ':' nas late-\nrais da peça.\n\n");
    Sleep(1000);
    printf("     V) Fim da Partida\n");
    printf("\tApós realizar as seis intrigas (ou menos, caso consiga chegar à\nquantidade correta antes), você vence a partida se todas as peças esti-\n");
    printf("verem com a pontuação correta dentro do tabuleiro 4x4, e assim consegue\nevitar a guerra e a paz irá reinar por mais algum tempo. Caso contrá-\n");
    printf("rio, você falhou e muitas vidas serão perdidas.\n\n");
    Sleep(500);
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    reset();
}

// FUNCION TO SHOW THE CREDITS:

void credits(){
    paint(1);
    printf("\n\tOpção Selecionada: Créditos\n\n");
    reset();
    paint(2);
    Sleep(500);
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    Sleep(1000);
    printf("\t\t\t\t/\n");
    printf("\t\t   ____ ____ ____ ___  . ___ ____ ____\n");
    printf("\t\t   |    |__/ |___ |  \\ |  |  |  | [__  \n");
    printf("\t\t   |___ |  \\ |___ |__/ |  |  |__| ___]\n\n");

    Sleep(500);
    printf("\t\t\t     Desenvolvedores:\n");
    printf("\t     Antonio Nunes, Arthur Lôbo e Guido Xenofonte\n\n");
    printf("\t\t\t  Sir. Caçador de bugs:\n");
    printf("\t\t\t\tArthur Lôbo\n\n");
    Sleep(500);
    printf("\t\t    Barão da música e efeitos sonoros:\n");
    printf("\t\t\t      Guido Xenofonte\n\n");
    Sleep(500);
    printf("\t\t\t Mestre-artesão do jogo:\n");
    printf("\t\t\t      Antonio Nunes\n\n");
    Sleep(500);
    printf("\t\t\t   Idealizador do jogo:\n");
    printf("\t\t\t     Roberto Pinheiro\n\n");
    Sleep(500);
    printf("    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    reset();
}

// FUNCION TO SHOW THE WORD VITÓRIA:

void victory(){
    paint(2);
    Sleep(500);
    printf("\n");
    printf("\t\t\t\t   __\n");
    printf("\t\t\t\t  /_/\n");
    printf("\t __   __  ___   _____    ___    ___   ___     _     _ \n");
    printf("\t \\ \\ / / |_ _| |_   _|  / _ \\  | _ \\ |_ _|   /_\\   | |\n");
    printf("\t  \\ V /   | |    | |   | (_) | |   /  | |   / _ \\  |_|\n");
    printf("\t   \\_/   |___|   |_|    \\___/  |_|_\\ |___| /_/ \\_\\ (_)\n");
   reset();
}

//  FUNCION TO SHOW THE WORD DERROTA:

void defeat(){
    paint(1);
    Sleep(500);
    printf("\n");
    printf("\t  ___    ___   ___   ___    ___    _____     _     _ \n");
    printf("\t |   \\  | __| | _ \\ | _ \\  / _ \\  |_   _|   /_\\   | |\n");
    printf("\t | |) | | _|  |   / |   / | (_) |   | |    / _ \\  |_|\n");
    printf("\t |___/  |___| |_|_\\ |_|_\\  \\___/    |_|   /_/ \\_\\ (_)\n");
    reset();
}

// FUNÇÕES OBRIGATÓRIAS:

void embaralhar(int **bigarr, int *colorarr, int *casasarr, int valor_pulado)
{
    int r=0,g=0,ye=0,b=0,p=0,c=0;

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

    r=0,g=0,ye=0,b=0,p=0,c=0;

    for (int i=0; i<7; i++)
    {
        if (i!=valor_pulado)
        {
            casasarr[i]=randcolornum(&r,&g,&ye,&b,&p,&c,1);
        }
    }
}



int exibeTabuleiro(int **tabuleiro, struct Casa **tabuleiroMini, int H, int h, int W, int w, int modo)
{
    int numEspacos=W-w;
    switch (modo) {
    case 1:
        switch (numEspacos) {
        case 0:
            printf("\t");
            break;
        case 1:
            printf("\t   ");
            break;
        case 2:
            printf("\t     ");
            break;
        case 3:
            printf("\t\t");
            break;
        case 4:
            printf("\t\t  ");
            break;
        case 5:
            printf("\t\t    ");
            break;
        }
        for (int k=W-5; k<w+6; k++)
        {
            printf("+----");
        }
        printf("+\n");
        for (int i=H-5; i<h+6; i++)
        {
            switch (numEspacos) {
            case 0:
                printf("\t");
                break;
            case 1:
                printf("\t   ");
                break;
            case 2:
                printf("\t     ");
                break;
            case 3:
                printf("\t\t");
                break;
            case 4:
                printf("\t\t  ");
                break;
            case 5:
                printf("\t\t    ");
                break;
            }
            for (int j=W-5; j<w+6; j++)
            {
                if (tabuleiro[i][j]==0)
                {
                    printf("|");
                    Sleep(5);
                    printf(" %x%x ", i,j);
                }
                else
                {
                    printf("|");
                    Sleep(5);
                    paint(tabuleiro[i][j]);
                    printf(" #  ");
                    reset();
                }
            }
            printf("|\n");
            switch (numEspacos) {
            case 0:
                printf("\t");
                break;
            case 1:
                printf("\t   ");
                break;
            case 2:
                printf("\t     ");
                break;
            case 3:
                printf("\t\t");
                break;
            case 4:
                printf("\t\t  ");
                break;
            case 5:
                printf("\t\t    ");
                break;
            }
                for (int k=W-5; k<w+6; k++)
                {
                    printf("+----");
                }
        printf("+\n");
        }
        break;
    case 2:
        printf("\t\t        1   2   3   4   5   6\n");
        printf("\t\t      +---");
        for (int k=0; k<5; k++)
        {
            printf("+---");
        }
        printf("+\n");
        for (int i=0; i<6; i++)
        {
            int j = 0;
            printf("\t\t    %d ", i+1);
                for (j=0; j<6; j++)
                {
                    printf("|");
                    Sleep(5);
                    paint(tabuleiroMini[i][j].cor);
                    switch (tabuleiroMini[i][j].trancada)
                    {
                        case true:
                            printf(":#:");
                            break;
                        case false:
                            printf(" # ");
                            break;
                    }
                    reset();
                }
                printf("|\n\t\t      +---");
        for (int k=0; k<5; k++)
            {
                printf("+---");
            }
        printf("+\n");
        }
        break;
    default:
        printf("ERRO");
        break;
    }

    return 0;
}

int validaIntriga(struct Casa **matriz_pequena, bool *cortranc, int x1_peq, int x2_peq, int y1_peq, int y2_peq) {

    int valid = (((x1_peq == x2_peq && (y1_peq-y2_peq == 1 || y1_peq-y2_peq == -1)) || (y1_peq == y2_peq && (x1_peq-x2_peq == 1 || x1_peq-x2_peq == -1)))

                && (matriz_pequena[x1_peq][y1_peq].trancada == 0 && matriz_pequena[x2_peq][y2_peq].trancada ==0)

                && ((cortranc[matriz_pequena[x1_peq][y1_peq].cor] == 0) || (cortranc[matriz_pequena[x2_peq][y2_peq].cor] == 0))) ? 1 : 0;

    if (!((x1_peq == x2_peq && (y1_peq-y2_peq == 1 || y1_peq-y2_peq == -1)) || (y1_peq == y2_peq && (x1_peq-x2_peq == 1 || x1_peq-x2_peq == -1))))
    {
        paint(1);
        printf("\tDIGITE CASAS ADJACENTES!\n");
        reset();
    }
    else if (!((matriz_pequena[x1_peq][y1_peq].trancada == 0 && matriz_pequena[x2_peq][y2_peq].trancada ==0)))
    {
        paint(1);
        printf("\tAS DUAS CASAS PRECISAM ESTAR \n\tDESTRANCADAS PARA FAZER INTRIGA!\n");
        reset();
    }
    else if (!(((cortranc[matriz_pequena[x1_peq][y1_peq].cor] == 0) || (cortranc[matriz_pequena[x2_peq][y2_peq].cor] == 0))))
    {
        paint(1);
        printf("\tPELO MENOS UMA COR PRECISA ESTAR \n\tDESTRANCADA PARA FAZER INTRIGA!\n");
        reset();
    }

    return valid;
}

int fazIntriga(struct Casa **casas6x6, bool *cortranc, int *casasarr, int x1_peq, int x2_peq, int y1_peq, int y2_peq){

    int n1,n2;
    do
    {
        paint(1);
        printf("\n\tDIGITE UMA PEÇA DO TABULEIRO PARA TRANCAR. (1 OU 2): ");
        reset();

        scanf(" %d", &n1);

    } while (n1!=1&&n1!=2 );

    switch(n1)
    {
        case 1:
            casas6x6[x1_peq][y1_peq].trancada = true;
            break;
        case 2:
            casas6x6[x2_peq][y2_peq].trancada = true;
            break;
    }

    printf("\n");
    do
    {
        paint(1);
        printf("\tDIGITE UMA COR PARA TRANCAR (0 a 6): ");
        reset();

        scanf(" %d", &n2);
        if (cortranc[casasarr[n2]])
        {
            paint(1);
            printf("\tTRANQUE UMA COR NOVA!\n");
            reset();
        }
        else if (casasarr[n2] != casas6x6[x1_peq][y1_peq].cor  &&  casasarr[n2] != casas6x6[x2_peq][y2_peq].cor)
        {
            paint(1);
            printf("\tSOMENTE AS CORES DAS CASAS ENVOLVIDAS\n\tNA INTRIGA PODEM SER TRANCADAS!\n");
            reset();
        }

        //printf(" %d %d",casasarr[n2],casas6x6[x1_peq][y1_peq].cor);
    } while((casasarr[n2] != casas6x6[x1_peq][y1_peq].cor  &&  casasarr[n2] != casas6x6[x2_peq][y2_peq].cor)  ||  cortranc[casasarr[n2]]);

    cortranc[casasarr[n2]] = true;


    struct Casa temp;
    temp = casas6x6[x1_peq][y1_peq];
    casas6x6[x1_peq][y1_peq] = casas6x6[x2_peq][y2_peq];
    casas6x6[x2_peq][y2_peq] = temp;

}

int pontosCorretos(struct Casa **casas6x6, int *casasarr, int modo, int valor_pulado){

    int r=0,g=0,ye=0,b=0,p=0,c=0;

    switch (modo)
    {
        case 1:
            for (int i=1;i<5;i++)
            {
                for (int j=1;j<5;j++)
                {
                    switch (casas6x6[i][j].cor)
                    {
                        case 1:
                            r++;
                            break;
                        case 2:
                            g++;
                            break;
                        case 3:
                            ye++;
                            break;
                        case 4:
                            b++;
                            break;
                        case 5:
                            p++;
                            break;
                        case 6:
                            c++;
                            break;
                    }
                }
            }
            break;
        case 2:
            for (int i=0;i<6;i++)
            {
                for (int j=0;j<6;j++)
                {
                    if ((i==0||i==5)||(j==0||j==5))
                    {
                        switch (casas6x6[i][j].cor)
                        {
                            case 1:
                                r++;
                                break;
                            case 2:
                                g++;
                                break;
                            case 3:
                                ye++;
                                break;
                            case 4:
                                b++;
                                break;
                            case 5:
                                p++;
                                break;
                            case 6:
                                c++;
                                break;
                        }
                    }
                }
            }
            break;
    }

    int venceu = 1;

    paint(1);
    printf("\n\tCasas corretas: \n\t");
    paint(2);

    for (int i=0;i<7;i++)
    {
        if (i==valor_pulado) continue;

        switch (casasarr[i])
        {
            case 1:
                if (r!=i)
                {
                    venceu = 0;
                    continue;
                }
                printf("Vermelho | ");
                continue;
            case 2:
                if (g!=i)
                {
                    venceu = 0;
                    continue;
                }
                printf("Verde | ");
                continue;
            case 3:
                if (ye!=i)
                {
                    venceu = 0;
                    continue;
                }
                printf("Amarelo | ");
                continue;
            case 4:
                if (b!=i)
                {
                    venceu = 0;
                    continue;
                }
                printf("Azul | ");
                continue;
            case 5:
                if (p!=i)
                {
                    venceu = 0;
                    continue;
                }
                printf("Roxo | ");
                continue;
            case 6:
                if (c!=i)
                {
                    venceu = 0;
                    continue;
                }
                printf("Ciano | ");
                continue;
        }
        //printf("\t\t %d  %d  %d  %d  %d  %d\n\n\n", r,g,ye,b,p,c);

    }

    printf("\n\n");
    reset();

    return venceu;
}

void imprime_N_das_cores(int *casasarr, bool *casasrev, bool *cortranc, int valor_pulado) {

    printf("\n\t\t    ");
    for (int i=0; i<7; i++)
    {
        if (i!=valor_pulado)
        {
             if (casasrev[i])
            {
                paint(casasarr[i]);
            }
            else
            {
               reset();
            }

            switch (cortranc[casasarr[i]])
            {
                case true:
                    Sleep(10);
                    printf(" :#: ");
                    break;
                case false:
                    Sleep(10);
                    printf("  #  ");
                    break;
            }
            reset();
        }
    }
    printf("\n\t\t    ");
    for (int k=0; k<7; k++)
    {
        if (k!=valor_pulado)
        {
            Sleep(20);
            printf("  %d  ", k);
        }
    }
    printf("\n\n");
}
