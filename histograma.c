#include <stdio.h>
#include <stdlib.h>

int main(){

    int largura, altura;
    int i, j;
    char formato[4];
    char aux[100];
    int valor_maximo;

    FILE *arq1;
    arq1 = fopen("C:/Users/alunos/Downloads/Aula-5-PDI-main/Expandir/lena256.pgm", "r");
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
    printf("Valor maximo: %i\n", valor_maximo);

    // Alocar memória para a imagem original
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
    fclose(arq1);

    // Calcular o histograma
    int histograma[valor_maximo + 1];
    for (i = 0; i <= valor_maximo; i++)
    {
        histograma[i] = 0;
    }
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            int pixel_valor = imagem[i][j];
            histograma[pixel_valor]++;
        }
    }

    // Imprimir o histograma
    printf("\nHistograma:\n");
    for (i = 0; i <= valor_maximo; i++)
    {
        printf("%d: %d\n", i, histograma[i]);
    }

    // Liberar a memória alocada
    for (i = 0; i < altura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}

