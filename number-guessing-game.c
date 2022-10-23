//CS2600 Quiz 3 question 3
//Tomes, Christopher

//modified version for saving user info.

//create a loop GAME_LOOP

// prompt user for input

// if 1, begin guessing game.
    //look up a file and grab the MAXVAL from text file maxval.txt 
    //loop
    //prompt user for input
    //notify player if exact; "win game" , lower or higher.
    //on q. or win scenario go back to GAME_LOOP.
//if 2 modify MAX.
    // prompt player for new max.
    //begin game part 1 with new Max.
    //save the MAXVAL to file maxval.txt

//if 3 quit program.

////CODE BELOW IS UNCHANGED FROM MAIN AT THE MOMENT//////

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#define TRUE 1
#define MY_INT_MAX 1000000

int main(){

    srand(time(NULL));//create random val for game
    
    while(TRUE)
    {
        unsigned char quit_val = 0; //used to determine exit condition
        unsigned int user_input; //read from scanf
        long max_num = 10;//random val will be between this and 1
        unsigned int guess = 0; //users guess
        unsigned int rand_num = rand()%max_num; //force constraints
        printf("Press 1 to play a game\nPress 2 to change max number\nPress 3 to quit\n-------------------------\n");
        scanf("%d",&user_input);
        switch (user_input)
        {
        case 2:
            do{ //change the max then fall through to case 1.
                printf("Changing Max:\n");
                printf("Max is currently %ld. What would you like the max number to be?\n-------------------------------------\n", max_num);
                if(scanf("%lu",&max_num)){

                }else{
                    printf("Invalid Input try again.\n");
                    fflush(stdin);
                    continue;
                }

                if(max_num < 1){//retstrict neg inputs
                    printf("Negative values are not permitted.\n");
                    max_num = 10;
                    continue;
                }else if(max_num > MY_INT_MAX)//i set an arbitrary max don't go above.
                {
                    printf("Value is too large.\n");
                    max_num = 10;
                    continue;
                }else{
                    printf("Setting max to %lu\n", max_num);
                    break;
                }
            }while(TRUE);
            
            rand_num = rand()%max_num+1;
        
            
        case 1:
            printf("Starting Game\n");
            printf("Pick a number between 1 and %lu.\n-------------------\n", max_num);
        
            do
            {
                if(scanf("%d",&guess)){//read guess
                    
                }else{//check for quick val or garbage input.
                    scanf("%c",&quit_val);
                    if('q' == quit_val){
                        printf("TRIGGERED QUIT\n");
                        break;
                    }else{
                        printf("Invalid input, try again.\n");
                        continue;
                    }
                }
                if(guess > max_num || guess < 0)
                {
                    printf("User's guess is out of bounds.\n");
                    printf("Please choose a value in between 1 - %lu\n", max_num);

                }else if(guess > rand_num){
                    printf("%d is Too High!\n", guess);
                }else if(guess < rand_num){
                    printf("%d is Too Low!\n", guess);
                }else{
                    printf("WINNER!\n-------\n");
                    break;
                }
            }while(guess != rand_num);//if guess is correct break loop.
            /* code */
            break;
        case 3:
            printf("Goodbye Thank you for playing\n");
            return EXIT_SUCCESS;
            break;
        default:
            break;
        }
    }
    return EXIT_SUCCESS;
}

