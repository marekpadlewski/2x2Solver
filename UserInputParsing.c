#include "UserInputParsing.h"
#include "Moves.h"
#include <stdio.h>

char line[100];

CubeState scramble(CubeState state)
{
    int counter=0;
    bool clause = false;
    CubeState oldState;

    while (!clause)
    {
        if (counter == 0)
            oldState = state;

        if (!clause)
            state = oldState; //if scramble was wrong, come back to original state

        clause = true;
        printf("Please type your scramble: ");

        int j=0, sign;
        while ((sign = getchar()) != '\n' && sign != EOF)
        {
            //getting user scramble
            line[j] = sign;
            j++;
        }

        line[j] = '\n';


        for (int i = 0  ; i < 100 ; i++)
        {
            //parsing user input for specific cube moves

            if (line[i] == '\n')
                break;

            if (line[i] == 'R' && (line[i+1] == ' ' || line[i+1] == '\n'))
                state = move_R(state);
            else if (line[i] == 'R' && line[i+1] == '\'' && (line[i+2] == ' ' || line[i+2] == '\n'))
                state = move_Rp(state);
            else if (line[i] == 'R' && line[i+1] == '2' && (line[i+2] == ' ' || line[i+2] == '\n'))
                state = move_R2(state);
            else if (line[i] == 'F' && (line[i+1] == ' ' || line[i+1] == '\n'))
                state = move_F(state);
            else if (line[i] == 'F' && line[i+1] == '\'' && (line[i+2] == ' ' || line[i+2] == '\n'))
                state = move_Fp(state);
            else if (line[i] == 'F' && line[i+1] == '2' && (line[i+2] == ' ' || line[i+2] == '\n'))
                state = move_F2(state);
            else if (line[i] == 'U' && (line[i+1] == ' ' || line[i+1] == '\n'))
                state = move_U(state);
            else if (line[i] == 'U' && line[i+1] == '\'' && (line[i+2] == ' ' || line[i+2] == '\n'))
                state = move_Up(state);
            else if (line[i] == 'U' && line[i+1] == '2' && (line[i+2] == ' ' || line[i+2] == '\n'))
                state = move_U2(state);
            else if (((line[i] == 'R' || line[i] == 'U' || line[i] == 'F') && (line[i+1] != '\'' && line[i+1] != '2' && line[i+1] != ' '))
                     || (line[i] != 'R' && line[i] != 'U' && line[i] != 'F' &&  line[i] != '\'' && line[i] != '2' && line[i] != ' ')
                     || (line[i] != 'R' && line[i] != 'U' && line[i] != 'F' &&  (line[i+1] == '2' || line[i+1] == '\''))
                     || (i == 0 && (line[i] == '2' || line[i] == '\'' || line[i] == ' ')))
            {
                printf("Invalid input, you must have typed wrong scramble!\n\n");
                clause = false;
                break;
            }
        }

        if (clause) //if scramble was correct
            break;

        counter++;
    }

    return state;

}