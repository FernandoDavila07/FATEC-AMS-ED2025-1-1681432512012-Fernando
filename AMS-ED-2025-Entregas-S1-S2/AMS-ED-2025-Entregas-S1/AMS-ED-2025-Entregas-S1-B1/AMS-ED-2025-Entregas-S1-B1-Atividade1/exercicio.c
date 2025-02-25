#include <stdio.h>

void desconto_calc(float *precoptr, float *descptr, float *prec_fnptr, float *vlr_descptr){
    *vlr_descptr = *precoptr * (*descptr/100);
    *prec_fnptr = *precoptr - *vlr_descptr;
}

int main()
{
    float preco, desc, prec_fn, vlr_desc;
    
    
    printf("Insira o valor do produto: ");
    scanf("%f", &preco);
    
    printf("Insira a porcentagem de desconto que voce recebeu: ");
    scanf("%f", &desc);
    
    desconto_calc(&preco, &desc, &prec_fn, &vlr_desc);
    
    printf("O valor inicial do produto é de: %.2fR$\n", preco);
    printf("A porcentagem de desconto aplicada foi de: %.0f%%\n", desc);
    printf("O desconto foi de: %.2fR$\n", vlr_desc);
    printf("O valor final da compra é de %.2fR$\n", prec_fn);
}