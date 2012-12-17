// Assign #1 - hexdmp.c
// Jeremy Villegas - CS331 - T.Springer
// 09/26/2008 
//
//

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

struct nibble{
  struct nibble *next;
  char nbyte[3];
};

int main(int argc, char *argv[]){
        int x=0,y=0,sec=0,tot_nibbles=0;
	struct nibble *n=NULL,*f=NULL;
	char *hex;
	const int NIBBLE_SIZE = 4;

        /* Check parameters */
        if(argc != 2) {
                printf("Usage: %s <binary number>\n",argv[0]);
                exit(1);
        }

        /* validate input */
        while(y<(int)strlen(argv[1])){
                char c=argv[1][y];
                if((c=='0'||c=='1')&&((int)strlen(argv[1])%4==0))
                        ++y;
                else {
                        printf("Invalid binary number\n");
                        exit(1);
                }
        }
	/* deal with first nibble */ 
	n=malloc(sizeof(struct nibble));
	f=n; /* save head pointer */
	n->next=NULL;
	for(y=0;y<NIBBLE_SIZE;y++)n->nbyte[y]=argv[1][y];
	
	/* Do we have more than 1 nibble to convert? */
	if(strlen(argv[1])>4) {
		/* total remaining nibbles */
		tot_nibbles=strlen(argv[1])%4==0?(strlen(argv[1])/4-1):(strlen(argv[1])/NIBBLE_SIZE);
		/* iterate through each remaining nibble */
		for(x=0;x<tot_nibbles;x++) {
			n->next=malloc(sizeof(struct nibble));
			n=n->next;
			n->next=NULL;
			/* load up current nibble */
			for(y=0;y<NIBBLE_SIZE;y++)n->nbyte[y]=argv[1][(x*NIBBLE_SIZE)+NIBBLE_SIZE+y];
		}
	}

	hex=malloc(sizeof(char)+(sizeof(char)*tot_nibbles));
	n=f;
	x=0;
	/* iterate through each nibble and convert to hex */
	do {
		if(!strcmp(n->nbyte,"0000"))hex[x]='0';
		if(!strcmp(n->nbyte,"0001"))hex[x]='1';
		if(!strcmp(n->nbyte,"0010"))hex[x]='2';
		if(!strcmp(n->nbyte,"0011"))hex[x]='3';
		if(!strcmp(n->nbyte,"0100"))hex[x]='4';
		if(!strcmp(n->nbyte,"0101"))hex[x]='5';
		if(!strcmp(n->nbyte,"0110"))hex[x]='6';
		if(!strcmp(n->nbyte,"0111"))hex[x]='7';
		if(!strcmp(n->nbyte,"1000"))hex[x]='8';
		if(!strcmp(n->nbyte,"1001"))hex[x]='9';
		if(!strcmp(n->nbyte,"1010"))hex[x]='A';
		if(!strcmp(n->nbyte,"1011"))hex[x]='B';
		if(!strcmp(n->nbyte,"1100"))hex[x]='C';
		if(!strcmp(n->nbyte,"1101"))hex[x]='D';
		if(!strcmp(n->nbyte,"1110"))hex[x]='E';
		if(!strcmp(n->nbyte,"1111"))hex[x]='F';
		x++;
	}while(n=n->next);

	/* display output in binary */
	printf("You entered: ");
	for(x=0;x<strlen(argv[1]);x++) {
		printf("%c",argv[1][x]);
		if((x+1)%4==0)printf(" ");
        }
	printf("\nHex Value  : 0x%s\n",hex);
        return(0);
}


