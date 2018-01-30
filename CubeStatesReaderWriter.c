#include "CubeStatesReaderWriter.h"

static FILE *fp3;

void printStates(CubeState key, int value)
{
    unsigned long long state_value = serialize(key);

    fprintf(fp3, "%llu %d\n", state_value, value);
};

void writeStates(FILE *fp2)
{
    if (!fp2)
        printf("Error opening file!");

    fp3 = fp2;
    forEachElement(printStates);

    fp3 = NULL;
    fclose(fp2);
}

void readStates(FILE *fp)
{
    clearMap();

    printf("\nReading the map... it may take a few seconds.\n");

    int var=1;

    while(var != EOF)
    {
        unsigned long long key;
        int value;
        var = fscanf(fp, "%llu %d", &key, &value);
        insertState(deserialize(key), value);
    }

    fclose(fp);
}