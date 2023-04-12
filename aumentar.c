#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int largura, altura;
    int i, j;
    char formato[4];
    char aux[100];
    int valor_maximo;

    FILE *arq1;
    arq1 = fopen("C:/Aula-5-PDI/lena256.pgm", "r");
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

    // Expandir a imagem para o dobro do tamanho
    int nova_largura = largura * 2;
    int nova_altura = altura * 2;
    int **nova_imagem = malloc(nova_altura * sizeof(int *));
    for (i = 0; i < nova_altura; i++)
    {
        nova_imagem[i] = malloc(nova_largura * sizeof(int));
    }

    for (i = 0; i < nova_altura; i++)
    {
        for (j = 0; j < nova_largura; j++)
        {
            nova_imagem[i][j] = imagem[i/2][j/2];
        }
    }

    // Salvar a imagem resultante em um novo arquivo
    FILE *arq2;
    arq2 = fopen("C:/Aula-5-PDI/lena256-expandido.pgm", "w");
    fprintf(arq2, "%s\n", formato);
    fprintf(arq2, "%d %d\n", nova_largura, nova_altura);
    fprintf(arq2, "%d\n", valor_maximo);
    for (i = 0; i < nova_altura; i++)
    {
        for (j = 0; j < nova_largura; j++)
        {
            fprintf(arq2, "%d\n", nova_imagem[i][j]);
        }
    }
    fclose(arq2);

    // Liberar a memória alocada
    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

    for (i = 0; i < nova_altura; i++)
    {
        free(nova_imagem[i]);
    }
    free(nova_imagem);

    fclose(arq1);
    return 0;
}
