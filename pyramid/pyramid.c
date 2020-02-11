//
//  main.cpp
//  sas4
//
//  Created by CHOI JISU on 06/02/2020.
//  Copyright © 2020 CHOI JISU. All rights reserved.
//

#include <iostream>




int quanline(int tier, int line)
{
    int Endline =0;
    int Addline =0;
    int x;

    for(x=(tier-1); x>=0; x--)
    {
        Addline += line*x;
    }
    Endline = (3 * tier) + Addline;
    printf("The whole quantity of the lines : %d\n", Endline);
    return Endline;
}

int calclast(int tier, int star, int Endline)
{
    int Endstar =0;
    int Addstar =0;
    int i;
    int s =1;
    
    //regular * value in last line
    s = 1+2*(Endline-1);        //s=49(cased in '5/1/2')    s=29(cased in '3/2/3')

    for(i=2; i<=tier; i++)
    {
        Addstar += star + (i-2);
    }

    Endstar = s + (2*Addstar);
    
    printf("The quantity of * in inner pyramid : %d\n", s);
    printf("Additional * value depending on argv[3] : %d\n", Addstar);
    printf("The quantity of stars in the last line : %d\n\n", Endstar);
return Endstar;
}

void putline(int last, int s, int t, int l, int ln, int tier, int star, int Addstar)    //t = current tier num
{
    int i;
    int linestar;
    int space;
    
    linestar = s + (2*Addstar);
    space = (last - linestar)/2;

    for(i=0; i<space; i++)
    {
        printf(" ");
    }
    printf("/");

    for(i=0; i<linestar; i++)
    {
        if(t == tier)
        {
            int m = 0;
            int com;
            
            if(tier > 1)
            {
                m = tier * 0.8;
            }
            
            com = ((space + i) >= (last / 2 - m) && (space + i) <= (last / 2 + m));

            if(ln > (l/3) && com)
            {
                if(ln >= (l*0.6) && ln <= (l*0.8) && (space + i) == (last / 2 + m - 1))
                    printf("$");
                else
                    printf("|");
            }
            else
            {
                printf("*");
            }
        }
        else
        {
            printf("*");
        }
    }
    printf("\\\n");
//    printf("%d - Add : %d\nlinestar = %d\n", 2*a, Addstar, linestar);
}

int main(int argc, const char * argv[]) {

    int tier =0, line, star;
    int Addstar =0;
    int i, t, l;
    int s =1;
    int ln =0;

    if(argc == 4)
    {
        tier = atoi(argv[1]); //info[0] = tier, info[1] = regular line increse per tier, info[2] = first *increse value
        line = atoi(argv[2]);
        star = atoi(argv[3]);
    }
    else
    {
//        printf("sastantua.out num(tier) num(increase of *) num(increasing lines of tier)");
        tier = 3;
        line = 4;
        star = 8;
    }
    
//    printf("Tier : %d\n", tier);
    
    int Endline = quanline(tier, line);
    int last = calclast(tier, star, Endline);
    //            blank = (int)((last+2)/2);
    for(t=1; t<=tier; t++)
    {
//        printf("tier : %d\n", t);
        l = 3+(line*(t-1));          //line num per each tier
        if(t>1)
        {
                Addstar += star + (t-2);
        }
        
        for(i=1; i<=l; i++)
        {
            ln++;
            s = 1+(2*(ln-1));
//            printf("%3.d - * : %d\n", ln, s);
            putline(last, s, t, l, i, tier, star, Addstar);
        }
    

    }

        
    return 0;
}

