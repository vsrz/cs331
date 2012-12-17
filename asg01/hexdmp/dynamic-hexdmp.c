// cs331_asg01_01.cpp : Defines the entry point for the console application.
//

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct nibble{
  struct nibble *next;
  char nbyte[3];
};

int main(int argc, char *argv[]){
        int y=0,sec=0;
	struct nibble *n=NULL,*f=NULL;
	const int NIBBLE_SIZE = 4;

        /* Check parameters */
        if(argc != 2) {
                printf("Usage: %s <binary number>\n",argv[0]);
                exit(1);
        }

        /* validate input */
        while(y<(int)strlen(argv[1])){
                char c=argv[1][y];
                if(c=='0'||c=='1')
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
	for(y=0;y<=(int)strlen(argv[1])&&y<NIBBLE_SIZE;y++){
		printf("Loading: y is %d -- %d gets %c\n",y,y%4,argv[1][(int)strlen((argv[1])-y-1)]);
		n->nbyte[y%4]=argv[1][(int)strlen((argv[1])-y-1)];
	}

        return(0);
	/* deal with rest of input */
	if(strlen(argv[1])>NIBBLE_SIZE) {
		/* split work into nibbles */
		int nib_rem=strlen(argv[1])%4==0?(strlen(argv[1])/4-1):(strlen(argv[1])/NIBBLE_SIZE);
		for(sec=0;sec<=nib_rem;sec++) {
			n->next=malloc(sizeof(struct nibble));
			n=n->next;
			n->next=NULL;
			for(y=0;y<=y%4;y++) {
				

				if(argv[1][strlen(argv[1])-(4*sec)-y]=='0' ||
				   argv[1][strlen(argv[1])-(4*sec)-y]=='1') {
					n->nbyte[y%4]=argv
		}
	}

        return(0);
}


