#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void showMap(int rows, int cols, bool array[rows][cols]);
bool AllElementsEqual(int rows, int cols, bool array[rows][cols]);

int main(void)
{

    int rows, cols; // rows = X, cols = Y
    printf("Enter number of lines: "); scanf_s("%i", &rows);
    printf("Enter number of columns: "); scanf_s("%i", &cols);

    bool array[rows][cols];
    // bool array[5][5] = { false }; test AllElementsEqual
    // showMap(rows, cols, array); 

    char answer[4];
    printf("Show map? (yes/no): ");
    scanf("%3s", answer);
    

    // computer science woooow
    for (size_t i = 0; answer[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)answer[i];
        if (c >= 'A' && c <= 'Z') {
            answer[i] = (char)(c + ('a' - 'A'));  // +32 т.к по ASCII разница = 32
        }
    }

    if ((strcmp(answer, "yes") == 0 || strcmp(answer, "y") == 0)) {
        showMap(rows, cols, array);
    }

    bool win = AllElementsEqual(rows, cols, array);

    while (!win) {
        int guessX, guessY;

        printf("Enter X coordinate: "); scanf_s("%i", &guessX);
        printf("Enter Y coordinate: "); scanf_s("%i", &guessY);

        bool ship = array[guessX][guessY];

        if (guessX < 0 || guessX >= rows || guessY < 0 || guessY >= cols) {
            printf("Some problem! Maybe you write uncorrect coordinate.\n");
            return 0;
        }
        else if (ship == true) {
            printf("The ship was shot down! | X%d Y%d\n", guessX, guessY);
            array[guessX][guessY] = false;
        }
        else {
            printf("Sorry, nothing there. | X%d Y%d\n", guessX, guessY);
        }

    }
    printf("You WIN!");
    return 0;
}


void showMap(int rows, int cols, bool array[rows][cols])
{
    printf("You see the map with ship.\n");

    printf("X Y- - - - - - - - - - - - - - - - - - -\n");
    for (int i = 0; i <= rows; i++) {
        printf("%i|", i);

        for (int j = 0; j <= cols; j++) {

            printf("%s\t", array[i][j] ? "X" : ".");
        }
        printf("\n");

    }
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    for (int i = 0; i <= cols; i++)
    {
        printf("%i \t", i);
    }
    printf("\n");
}


bool AllElementsEqual(int rows, int cols, bool array[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j])
            {
                return false;
            }
        }
    }

    return true;
}