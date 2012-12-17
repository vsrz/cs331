#include <stdio.h>
#include <stdlib.h>

extern float f2c(float);

int main(int argc, char *argv[])
{

    float   val;

    if (argc != 2) {
        printf("Usage:: %s <fahrtemp> \n", argv[0]);
        exit(-1);
    }

    val = atof(argv[1]);

    printf("Fahrenheit: %4.1f Celsius: %4.1f \n", val, f2c(val));

    exit(0);

}


