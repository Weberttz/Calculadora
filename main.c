#include <stdio.h>
#include <stdlib.h>

void clear() {
    system("cls");
}

void operacao(char n){
    double num1, num2, resultado;
    printf("Digite o primeiro numero: ");
    scanf("%lf", &num1);
    printf("Digite o segundo numero: ");
    scanf("%lf", &num2);

    switch (n)
    {
    case '1':
        resultado = num1 + num2;
        printf("Resultado: %.2lf + %.2lf = %.2lf", num1, num2, resultado);
        break;
    case '2':
        resultado = num1 - num2;
        printf("Resultado: %.2lf - %.2lf = %.2lf", num1, num2, resultado);
        break;
    case '3': 
        resultado = num1 * num2;
        printf("Resultado: %.2lf * %.2lf = %.2lf", num1, num2, resultado);
        break;
    case '4':
        if(num2 != 0){
            resultado = num1/num2;
            printf("Resultado: %.2lf / %.2lf = %.2lf", num1, num2, resultado);
        }else 
        printf("Erro: Divisao por zero nao e permitida.\n");
        break;
    default:
        break;
    }
}

int novaOperacao(){
    char letra, valido = 0;
    
    while(valido == 0)
    {
        printf("\nDeseja realizar outra operacao? (s/n):");
        scanf("%s%*c", &letra);
        if(letra != 's' && letra != 'S' && letra != 'n' && letra != 'N'){
            printf("Resposta invalida. Por favor, digite 's' para sim ou 'n' para nao.");
            continue;
        }
        else valido = 1;
    }

    if(letra == 's' || letra == 'S') return 1;
    else return 0;
}


void escolhaUsuario(){
    char opcao;
    int exe_programa = 1, invalido;
    
    while(exe_programa == 1){
        invalido = 0;
        printf("===============================\nCalculadora Simples\n===============================");
        printf("\nSelecione uma operacao:\n1. Adicao\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n5. Sair\nOpcao:");
        scanf("%c%*c", &opcao);
        switch (opcao)
        {
        case '1':
            operacao(opcao);
            exe_programa = novaOperacao();
            break;
        case '2':
            operacao(opcao);
            exe_programa = novaOperacao();
            break;
        case '3':
            operacao(opcao);
            exe_programa = novaOperacao();
            break;
        case '4':
            operacao(opcao);
            exe_programa = novaOperacao();       
            break;
        case '5':
            exe_programa = 0;
            break;
        default:
            printf("Opcao invalida, digite novamente\n");
            invalido = 1;
            break;
        }
        if(exe_programa == 0 && invalido == 0) printf("Obrigado por usar a calculadora! Ate a proxima.");
        if (exe_programa == 1 && invalido == 0) clear();
        if(invalido == 1) printf("\n");
    }

    exit(0);
}

int main(){
    escolhaUsuario();
    return 0;
}