#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int largura, altura;
int i, j;
char formato[4];
char aux[100];
int valor_maximo;




int main()
{

    float c = 1;
    float s;


    FILE *arq1;
    arq1 = fopen("C:/Aula-5-PDI/spine.pgm", "r");
    if (arq1 == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    fscanf(arq1, "%[^\n]\n", formato);
    printf("%s\n",formato);
    fscanf(arq1, "%[^\n]\n", aux );
    fscanf(arq1, "%d %d\n", &largura, &altura);
    printf("%d %d\n",largura, altura);
    fscanf(arq1, "%d\n", &valor_maximo);
    printf("Lido");
    

    // Alocar memória para a imagem
    int **imagem = malloc(altura * sizeof(int *));
    for (i = 0; i < altura; i++)
    {
        imagem[i] = malloc(largura * sizeof(int));
    }



        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                int pixel_valor;
                fscanf(arq1, "%d\n", &pixel_valor);
                imagem[i][j] = pixel_valor;
            }
        }


for ( i = 0; i < altura; i++)
    {
        for ( j = 0; j < largura; j++)
        {
            
                s = (c*(pow(((float)(imagem[i][j])/255),0.5)));
                imagem[i][j] = (int)(s*255);

        }
    }



    // Salvar a imagem resultante em um novo arquivo
    FILE *arq2;
    arq2 = fopen("C:/Aula-5-PDI/spine2.pgm", "w");
    fprintf(arq2, "%s\n", formato);
    fprintf(arq2, "%d %d\n", largura, altura);
    fprintf(arq2, "%d\n", valor_maximo);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            fprintf(arq2, "%d\n", imagem[i][j]);
        }
    }
    fclose(arq2);

    // Liberar a memória alocada
    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

    fclose(arq1);
    return 0;
}