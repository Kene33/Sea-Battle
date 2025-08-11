#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void showMap(int rows, int cols, bool array[rows][cols]);
bool AllElementsEqual(int rows, int cols, bool array[rows][cols]);

int main(void)
{
    int hits = 0;
    int misses = 0;
    int ships_left  = 0;

    int rows, cols; // rows = X, cols = Y
    printf("Enter number of lines: "); scanf("%i", &rows);
    printf("Enter number of columns: "); scanf("%i", &cols);

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
            answer[i] = (char)(c + ('a' - 'A'));  // +32 ascii difference
        }
    }

    if ((strcmp(answer, "yes") == 0 || strcmp(answer, "y") == 0)) {
        showMap(rows, cols, array);
    }

    while (!AllElementsEqual(rows, cols, array)) {
        int guessX, guessY;

        ships_left = 0;
        for (int i=0; i <= rows; i++) {
            for (int j=0; j <= cols; j++) {
                if (array[i][j]) {
                    ships_left++;
                }
            }
        }

        printf("\033[37;42mYou have %i hits and %i misses.\033[0m\n", hits, misses);
        printf("\033[37;42mYou have %i ships left.\033[0m\n", ships_left);

        printf("\n\033[37;41mEnter X coordinate:\033[0m"); scanf("%i", &guessX);
        printf("\033[37;41mEnter Y coordinate:\033[0m"); scanf("%i", &guessY);


        if (guessX < 0 || guessX >= rows || guessY < 0 || guessY >= cols) {
            printf("Some problem! Maybe you write uncorrect coordinate.\n");
            return 0;
        }
        
        bool ship = array[guessX][guessY];

        if (ship == true) {
            printf("\033[37;102mThe ship was shot down! | X%d Y%d\033[0m\n", guessX, guessY);
            array[guessX][guessY] = false;
            hits++;
        }
        else {
            printf("Sorry, nothing there. | X%d Y%d\n", guessX, guessY);
            misses++;
        }

    }
    printf("\033[37;102mYou WIN!\033[0m\n");
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
    printf("\n\n");
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
