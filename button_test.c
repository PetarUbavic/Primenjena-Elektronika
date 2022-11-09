#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv)
{
	FILE *fp;
	FILE *fl;
	FILE *fb;
	char *str;
	char tval1,tval2,tval3,tval4, sval1, sval2, sval3, sval4, kval1, kval2, kval3, kval4, prom = 0;
	size_t num_of_bytes = 6;

	while(1)
	{

		//Citanje vrednosti tastera
		fp = fopen ("/dev/button", "r");
		if(fp==NULL)
		{
			puts("Problem pri otvaranju /dev/button");
			return -1;
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp); 

		if(fclose(fp))
		{
			puts("Problem pri zatvaranju /dev/button");
			return -1;
		}

		tval4 = str[5] - 48;
		free(str);

		if(tval4 == 1)
		{///////////////////
	
			// Upali diode
			fl = fopen("/dev/led", "w");
			if(fl == NULL)
			{
				printf("Problem pri otvaranju /dev/led\n");
				return -1;
			}
			//fputs("0x0F\n", fl);
			if(fclose(fl))
			{
				printf("Problem pri zatvaranju /dev/led\n");
				return -1;
			}

			// Ugasi diode
			fl = fopen("/dev/led", "w");
			if(fl == NULL)
			{
				printf("Problem pri otvaranju /dev/led\n");
				return -1;
			}
			//fputs("0x00\n", fl);
			if(fclose(fl))
			{
				printf("Problem pri zatvaranju /dev/led\n");
				return -1;
			}
			
			
					//Citanje vrednosti switcha
		fb = fopen ("/dev/switch", "r");
		if(fb==NULL)
		{
			puts("Problem pri otvaranju /dev/switch");
			return -1;
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fb); 

		if(fclose(fb))
		{
			puts("Problem pri zatvaranju /dev/switch");
			return -1;
		}


		sval1 = str[2] - 48;
		sval2 = str[3] - 48;
		sval3 = str[4] - 48;
		sval4 = str[5] - 48;
		free(str);
		
		if(sval4 == 0)
			if(sval3 == 0)
				operacija = 1; //plus
			else
				operacija = 2; //minus
			
		else
			if(sval3 == 0)
				opearcija = 3; //puta
			else
				operacija = 4; //podeljeno
			
		if(sval1 == 0)
			if(sval2 == 0)
				operand = 0;
			else
				operand = 1;
		else
			if(sval2 == 0)
				operand = 2;
			else
				operand = 3;
		
		kval1 = fl[2]-48;
		kval2 = fl[3]-48;
		kval3 = fl[4]-48;
		kval4 = fl[5]-48;
		
		
		if(operacija == 1)
		{
			if(kval4 == 1)
				prom = prom+1;
			if(kval3 == 1)
				prom = prom+2;
			if(kval2 == 1)
				prom = prom+4;
			if(kval1 == 1)
				prom = prom+8;
			
			prom=prom+operand;
			fl = fopen("/dev/led", "w");
			fprintf(fl, prom);
		}
		else if(opearcija == 2)
		{
			if(kval4 == 1)
				prom = prom+1;
			if(kval3 == 1)
				prom = prom+2;
			if(kval2 == 1)
				prom = prom+4;
			if(kval1 == 1)
				prom = prom+8;
			
			prom=prom+operand;
			fl = fopen("/dev/led", "w");
			fprintf(fl, prom);
		}
		else if(operacija == 3)
		{
			if(kval4 == 1)
				prom = prom+1;
			if(kval3 == 1)
				prom = prom+2;
			if(kval2 == 1)
				prom = prom+4;
			if(kval1 == 1)
				prom = prom+8;
			
			prom=prom+operand;
			fl = fopen("/dev/led", "w");
			fprintf(fl, prom);
		}
		else if(operacija == 4)
		{
			if(kval4 == 1)
				prom = prom+1;
			if(kval3 == 1)
				prom = prom+2;
			if(kval2 == 1)
				prom = prom+4;
			if(kval1 == 1)
				prom = prom+8;
			
			prom=prom+operand;
			fl = fopen("/dev/led", "w");
			fprintf(fl, prom);
		}
		
		sleep(1);	
		}////////////////
		sleep(1);
	}
}
