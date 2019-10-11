#include <stdio.h>

int Bin_Dec(int num, int d, int dec)
{
	if(num != 0)
		return Bin_Dec(num/10, d*2, dec+(num%10)*d);
	else	
		return dec;
}

void Bin_Oct(int num, int d, int oct)
{
	if(num != 0){
		oct = oct+(num%10)*d;
		num/=10; d*=2;

		oct = oct+((num%10)*d);
		num/=10; d*=2;

		oct = oct+(num%10)*d;
		
		Bin_Oct(num/10, 1, 0);
			printf("%d", oct);	
	}
}

void Bin_Hex(int num, int d, int dec)
{
	if(num != 0){
		dec = dec+(num%10)*d;
		num/=10; d*=2;

		dec = dec+((num%10)*d);
		num/=10; d*=2;

		dec = dec+(num%10)*d;
		num/=10; d*=2;

		dec = dec+(num%10)*d;
		
		Bin_Hex(num/10, 1, 0);
		switch (dec){
			case 10: putchar('A'); break;
			case 11: putchar('B'); break;
			case 12: putchar('C'); break;
			case 13: putchar('D'); break;
			case 14: putchar('E'); break;
			case 15: putchar('F'); break;
			default: printf("%d", dec);	
		}
	}
}

//===================Octal para Binario (INICIO)============================================
void Converte_Oct_Bin(int n, int x){

	if(n == 0)
		printf("00");
	
	else{
		if(x == n && x < 4 && x != 1)
		printf("0");
	
		else if(x == n && x == 1)
		printf("00");	
	}
    if (n/2 != 0){
        Converte_Oct_Bin(n/2, x);
    }
    printf("%d", n%2);
}

void Oct_Bin(int n, int x){
	
	if (n != 0){
	Oct_Bin(n/10, x/10);
	Converte_Oct_Bin(n%10, x%10);
	}
}
//===================Octal para Binario (FIM)============================================

void Dec_Bin(int valor)
{
int quociente, resto;
	if(valor != 0){
		quociente=valor / 2;
		resto=valor-quociente * 2;
		Dec_Bin(quociente);
		printf("%d", resto);
	}
}

int Dec_Oct(int valor)
{
int quociente, resto;
	if(valor != 0){
		quociente=valor / 8;
		resto=valor-quociente * 8;
		Dec_Oct(quociente);
		printf("%d", resto);
	}
}

int Dec_Hex(int valor)
{
int quociente, resto;
	if(valor != 0){
		quociente=valor / 16;
		resto=valor-quociente * 16;
		Dec_Hex(quociente);
		switch (resto){
			case 10: putchar('A'); break;
			case 11: putchar('B'); break;
			case 12: putchar('C'); break;
			case 13: putchar('D'); break;
			case 14: putchar('E'); break;
			case 15: putchar('F'); break;
			default: printf("%d", resto);
		}
	}
}

//===================Hexadecimal para Binario (INICIO)============================================
void Converte_Hex_Bin(int n, int x){

	if(n > 3 && n < 8)
		printf("0");
	else{
		if(n == 0)
			printf("000");

		else{
			if(x == n && x < 4 && x != 1)
			printf("00");
	
		else if(x == n && x == 1)
			printf("000");	
		}
	}
	
    if (n/2 != 0){
        Converte_Hex_Bin(n/2, x);
    }
    printf("%d", n%2);
}

void Hex_Bin(int n, int x){
	
	if (n != 0){
	Hex_Bin(n/10, x/10);
	Converte_Hex_Bin(n%10, x%10);
	}
}

int main(){
	int num, base;
	
	printf("Insira numero e sua respectiva Base:\n");
	scanf("%d %d",&num, &base);
	
	switch(base){
		case 2:
			printf("\nDecimal: %d", Bin_Dec(num,1, 0)); 
				printf("\nHexadecimal: ");
				Bin_Hex(num, 1, 0);
					printf("\nOctal: ");
					Bin_Oct(num,1, 0);
			break;
			
		case 8:
			printf("\nBinario: ");
			Oct_Bin(num, num);
				printf("\nDecimal: ");
				//Oct_Dec()
					printf("\nHexadecimal: ");
			break;
			
		case 10:
			printf("\nBinario: ");
			Dec_Bin(num);
				printf("\nOctal: ");
				Dec_Oct(num);
					printf("\nHexadecimal: ");
					Dec_Hex(num);
			break;
			
		case 16:
			printf("\nBinario: ");
			Hex_Bin(num, num);
				printf("\nDecimal: ");
				//Hex_Dec(num);
					printf("\nOctal: ");
					//Hex_Oct(num);
			break;
		default: printf("\n\nBase incorreta\n.");
	}
	return 0;
}
