#include <stdio.h>
#include <stdlib.h>

#include "dgv.h"
#include "csv_reader.h"

#define FILE_PATH "../../data/USA-roads.csv"

int main()
{
    printf("Verify that file %s exists\n", FILE_PATH);

    if (checkFileExists(FILE_PATH))
    {
        printf("File exists\n");
    }
    else
    {
        printf("File does not exist\n");
        return 1;
    }

    GraphType graph = readFormatCSV(FILE_PATH);
    return 0;
}
