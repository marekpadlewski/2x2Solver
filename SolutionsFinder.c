#include <stdio.h>
#include "SolutionsFinder.h"
#include "Moves.h"
#include "StatesComputor.h"

char solutions[11];

void findSolutions(CubeState state, int level)
{
    //using Depth-First Search algorithm

    if (isSame(state, solved()))
    {
        if (level == 0)
            printf("Cube is solved!\n");

        else
        {
            printf("%d | ", level);

            for (int i=0 ; i<level ; i++)
            {
                if (solutions[i] == '1')
                    printf("R2 ");
                else if (solutions[i] == 'r')
                    printf("R' ");
                else if (solutions[i] == '2')
                    printf("F2 ");
                else if (solutions[i] == 'f')
                    printf("F' ");
                else if (solutions[i] == '3')
                    printf("U2 ");
                else if (solutions[i] == 'u')
                    printf("U' ");
                else
                    printf("%c ", solutions[i]);
            }
            printf("\n");
        }
    }

    if (level >= 11)
        return;

    for (int i = 0 ; i < 9 ; i++)
    {
        CubeState newState = moves[i](state);
        if (movesToSolved(&newState) < movesToSolved(&state)) //if this move is optimal
        {
            solutions[level] = move_symbols[i];
            findSolutions(newState, level + 1);
        }
    }
}