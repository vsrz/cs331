// Assign #1 - fperf.c
// Jeremy Villegas - CS331 - T.Springer
// 09/26/2008 
//
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[]) {
	struct timespec tp;
	double te,factor,f;
	int x,y;	

	if(argc!=2) {
		printf("Usage: %s [factor]\n",argv[0]);
		exit(1);
	} 

	/* replay factor */
	factor=atoi(argv[1]);	

	/* start clock, start dividing */
	clock_gettime(CLOCK_REALTIME,&tp);
	te=tp.tv_sec+(tp.tv_nsec*1e-09);
	for(x=y=0;x<factor;x++)y/=x+1;
	clock_gettime(CLOCK_REALTIME,&tp);
	printf("Integer Division Time Elapsed : %lf\n",(tp.tv_sec+(tp.tv_nsec*1e-09))-te);

	/* start clock, start dividing */
	clock_gettime(CLOCK_REALTIME,&tp);
	te=tp.tv_sec+(tp.tv_nsec*1e-09);
	for(x=f=0;x<factor;x++)f/=x;
	clock_gettime(CLOCK_REALTIME,&tp);
	printf("Floating Division Time Elapsed: %lf\n",(tp.tv_sec+(tp.tv_nsec*1e-09))-te);

	return(0);
}


