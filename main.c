/*
 * Marek Padlewski
 * 2x2 Solver
 * 29.01.2018
*/

#include "Moves.h"
#include "SolutionsFinder.h"
#include "UserInputParsing.h"
#include <stdio.h>
#include "CubeStatesReaderWriter.h"
#include "stdbool.h"

int main()
{
    printf("\033c" );

    FILE *fp = fopen("MapOfStates.txt", "r");

    if (fp == NULL)
    {
        //file doesnt exist
        //needs to generate map
        FILE *fp2 = fopen("MapOfStates.txt", "w");

        printf("\nGenerating the map... it may take about 20 seconds.\n");
        computeClosestPaths();
        writeStates(fp2);
        printf("Done!\n");
    }

    else
    {
        readStates(fp);
    }

    bool clause = true;
    int c;
    char sign='N';

    while (clause)
    {
        //while user want to type next scramble

        CubeState state = scramble(solved());

        printf("Solutions: \n");

        findSolutions(state, 0);

        printf("\nDo you want to scramble again? (Y/N): ");

        while ((c = getchar()) != '\n' && c != EOF)
        {
            sign = c;
        }

        if (sign == 'Y' || sign == 'y')
            clause = true;
        else
            clause = false;
    }

    return 0;
}