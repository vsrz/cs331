// Assign #1 - iperf2.c 
// Jeremy Villegas - CS331 - T.Springer
// 09/26/2008 
//
//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char *argv[]) {
	struct timespec tp;
	short s;
	int i;
	double d,te,factor,x,y;
		
	if(argc!=2) {
		printf("Usage: %s [factor]\n",argv[0]);
		exit(1);
	} 

	/* replay factor */
	factor=atoi(argv[1]);

	/* start clock, 16-bit integer  */
	clock_gettime(CLOCK_REALTIME,&tp);
	te=tp.tv_sec+(tp.tv_nsec*1e-09);
	for(x=s=0;x<factor;x++) s+=s+1;	
	clock_gettime(CLOCK_REALTIME,&tp);
	printf("16-bit Time Elapsed: %lf\n",(tp.tv_sec+(tp.tv_nsec*1e-09))-te);

	/* start clock, start dividing */
	clock_gettime(CLOCK_REALTIME,&tp);
	te=tp.tv_sec+(tp.tv_nsec*1e-09);
	for(x=i=0;x<factor;x++)i/=i+1;
	clock_gettime(CLOCK_REALTIME,&tp);
	printf("32-bit Time Elapsed: %lf\n",(tp.tv_sec+(tp.tv_nsec*1e-09))-te);

	/* start clock, start adding */
	clock_gettime(CLOCK_REALTIME,&tp);
	te=tp.tv_sec+(tp.tv_nsec*1e-09);
	for(x=d=0;x<factor;x++) d+=1+d;	
	clock_gettime(CLOCK_REALTIME,&tp);
	printf("64-bit Time Elapsed: %lf\n",(tp.tv_sec+(tp.tv_nsec*1e-09))-te);


	return(0);
}

