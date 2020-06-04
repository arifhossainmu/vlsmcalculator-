#include <stdio.h>
#include <math.h>

/*=========================================================================
    |=================VLSM Calculator By Arif =================|
    ========================================================================*/


//******************************************************************************//
//  PLEASE ENTER IP ADDRESS AND CIDR ON THE SAME PROMPT SEPARATED BY SPACE OR   //
//  HIT ENTER AFTER ENTRING IP                                                  //
//                                                                              //
//  THE IP SHOULD BE ENTERED LIKE THIS:                                         //
//                                                                              //
//      192.168.1.1 24                                                          //
//      OR                                                                      //
//      192.168.1.1 => IP                                                       //
//      24 => CIDR                                        there seems to be a bug with the blocksize will check later.                      //
//******************************************************************************//


int main(int argc, char *argv[]) {

    printf("\t=======================================================================\n");
    printf("\t================ VLSM Calculator By Arif ================\n");
    printf("\t=======================================================================\n\n");
    int IP1, IP2, IP3, IP4, CIDR, bitborrowed, bitremained, subnet, host, mask, blocksize;
    char class;

    //Request User input
    printf("-----------------------------------------------------\n");
    printf("| Please enter IP address in the form of \"0.0.0.0\": |\n");
    printf("-----------------------------------------------------\n");
    scanf("%i.%i.%i.%i", &IP1, &IP2, &IP3, &IP4);

    //Check if IP is valid
    do
    {
        if((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 == 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0))
        {
            printf("------------------------------------------------------------\n");
            printf("| Warning!! IP address invalid, please enter a valid IP address: |\n");
            printf("------------------------------------------------------------\n");
            scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
        }
    }while((IP1 >255 || IP2 >255 || IP3 >255 || IP4 >255) || (IP1 == 127 || IP1 == 191 || IP1 == 255) || (IP1 == 0 && IP2 == 0 && IP3 == 0 && IP4 == 0));

        //If IP valid ask for CIDR
            printf("---------------------------------------------\n");
            printf("| Enter CIDR in the format of decimal CIDR: |\n");
            printf("---------------------------------------------\n");
            scanf("%d", &CIDR);
        do{
            //CHeck if CIDR is valid
            if(CIDR > 32 || CIDR == 0)
            {
                printf("--------------------------------------------\n");
                printf("| Invalid CIDR, please enter a valid CIDR: |\n");
                printf("--------------------------------------------\n\n");
                scanf("%d", &CIDR);
            }
        }while(CIDR > 32);

    //Let's determine IP class
    if(IP1 <=170) {
        class = 'A';
    }else if(IP1 <=190) {
        class = 'B';
    }else {
        class = 'C';
    }

    //    Let find the number of bits borrowed
    switch (class) {
        case 'A':
            if(CIDR >= 8) {
                bitborrowed = CIDR - 8;
            }else {
                bitborrowed = 8 - CIDR;
            }
            break;
        case 'B':
            if(CIDR >= 16) {
                bitborrowed = CIDR - 16;
            }else {
                bitborrowed = 16 - CIDR;
            }
            break;
        case 'C':
            if(CIDR >= 24) {
                bitborrowed = CIDR - 24;
            }else {
                bitborrowed = 24 -CIDR;
            }
    }

    //Let Find the number of bits that remained
    switch (class) {
        case 'A':
            bitremained = 32 - CIDR;
            break;
        case 'B':
            bitremained = 32 -CIDR;
            break;
        case 'C':
            bitremained = 32 -CIDR;
            break;
    }

    //Now Let Calculate the number of Subnets
    subnet = pow(2,bitborrowed);

    //And then we calculate the number of usable hosts
    host = pow(2, bitremained)-2;

    //Here we determine the block size
    switch(bitborrowed) {
        case 1:
            blocksize = 128;
            break;
        case 2:
            blocksize = 64;
            break;
        case 3:
            blocksize = 32;
            break;
        case 4:
            blocksize = 16;
            break;
        case 5:
            blocksize = 8;
            break;
        case 6:
            blocksize = 4;
            break;
        case 7:
            blocksize = 2;
            break;
        case 8:
            blocksize = 1;
            break;
    }
    printf("=====================================================\n");
    printf("=============== Here is your Result: ================\n");
    printf("=====================================================\n\n");
    printf("---------------------------------------\n");
    printf("your IP %i.%i.%i.%i/%i is of class %c\n", IP1,IP2,IP3,IP4,CIDR,class);
    printf("---------------------------------------\n");
    printf("Number of bit borrowed is:\t%d \n", bitborrowed);
    printf("---------------------------------------\n");
    printf("Number of bits remained is:\t%d \n", bitremained);
    printf("---------------------------------------\n");
    printf("Subnet:\t%d \n", subnet);
    printf("---------------------------------------\n");
    printf("host:\t%d \n", host);
    printf("---------------------------------------\n");
    printf("blocksize:\t%d \n", blocksize);
    printf("---------------------------------------\n");
    return (0);
}
