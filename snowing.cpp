//
//  main.cpp
//  rand_snowing
//
//  Created by CHOI JISU on 15/01/2020.
//  Copyright © 2020 CHOI JISU. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int main(int argc, char* argv[])
{
    int x, y;
    int k;

    srand((unsigned int)time(NULL));

    for(y=0; y<48; y++)
    {
    char buf[100+1];
    int i;
    char ch[8 + 1] = {"..*+.*.^"};
        
    for(i=0; i<100; i++)
    buf[i] = 32; // ' ';
    buf[100] = 0;  // '\0';

    for(i=0; i<20; i++)
    {
    x = rand() % 100;
    k = rand() % 8;
    buf[x] = ch[k];
    }

    printf("%s\n", buf);
    }

  return 0;
}

