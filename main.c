#include <stdio.h>
#include <time.h>


//In case you haven't seen this before, these are preprocessor commands. What they do is that they
#define NUM_QUESTIONS 10
#define TIME_LIMIT    15

/*
Ofei-Badu William - 4104724 - CodeBase Admin
*/

/*
 * Simple Quiz Game in C
 * Compile:  gcc -o quiz quiz_game.c
 * Run:      ./quiz
 */


int main(void) {
    int score = 0;
    char answer[10];

    char questions[NUM_QUESTIONS][200] = {
      { "What was the name of Ghana before it gained independence?" },
      { "On what date did Ghana gain independence?" },
      { "Who was the first President of Ghana?" },
      { "Which European country colonized Ghana?" },
      { "The Ashanti Kingdom was known for trading which valuable resource?" },
      { "Who led the coup that overthrew Kwame Nkrumah in 1966?" },
      { "What is the name of Ghana's national parliament building located in Accra?" },
      { "Which Ghanaian leader founded the Convention People's Party (CPP)?" },
      { "The Volta River Project, which created Lake Volta, was initiated under whose presidency?" },
      { "Jerry John Rawlings first came to power in Ghana through a coup in which year?" }
    };

    char options[NUM_QUESTIONS][4][100] = {
      { "A. Gold Coast", "B. Silver Coast", "C. Ivory Coast", "D. Slave Coast" },
      { "A. January 1, 1956", "B. March 6, 1957", "C. April 12, 1960", "D. July 4, 1958" },
      { "A. Kofi Busia", "B. John Agyekum Kufuor", "C. Kwame Nkrumah", "D. Hilla Limann" },
      { "A. France", "B. Portugal", "C. Belgium", "D. Britain" },
      { "A. Diamonds", "B. Gold", "C. Ivory", "D. Salt" },
      { "A. Jerry Rawlings", "B. Ignatius Acheampong", "C. Emmanuel Kotoka and Joseph Ankrah", "D. Akwasi Afrifa" },
      { "A. The State House", "B. Independence Hall", "C. The Parliament House", "D. The Capitol Building" },
      { "A. J.B. Danquah", "B. Kwame Nkrumah", "C. Kofi Busia", "D. Edward Akufo-Addo" },
      { "A. Kofi Busia", "B. Hilla Limann", "C. Kwame Nkrumah", "D. Jerry Rawlings" },
      { "A. 1972", "B. 1975", "C. 1979", "D. 1981" }
    };

    int correct[NUM_QUESTIONS] = {0, 1, 2, 3, 1, 2, 2, 1, 2, 2 };

    printf("=== QUIZ GAME ===\n");
    printf("You have %d seconds per question.\n\n", TIME_LIMIT);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Q%d: %s\n", i + 1, questions[i]);
        for (int j = 0; j < 4; j++)
            printf("  %s\n", options[i][j]);

        printf("Your answer (A/B/C/D): ");
        fflush(stdout);//It clears the standard output buffer

        clock_t start = clock();
        fgets(answer, sizeof(answer), stdin);
        double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;// This part is the code of the timer. It divides the ticks difference by  the ticks per second of the CPU to give the time in seconds

        if (elapsed > TIME_LIMIT) {
            printf("  TIME'S UP! Answer was\n %c.\n\n", 'A' + correct[i]);// This is an offset that works to display the answer by adding the index of the correct anser to A. Since A is first, its index is 0 and so it is not affected if that is the answer. The rest are just offsets from A, being B, C and D
            continue;
        }


        //Validating the answer
        //Accepting the first letter of the input
        char ch = answer[0];
        //Ensuring the ASCII letters match
        if (ch >= 'a' && ch <= 'd')
            {ch -= 32;}
        int chosen = ch - 'A';

        if (chosen < 0 || chosen > 3) {
            printf("  Invalid input.\n\n");
            continue;
        }

        if (chosen == correct[i]) {
            printf("  Correct!\n\n");
            score++;
        } else {
            printf("  Wrong! Answer was %c.\n\n", 'A' + correct[i]);
        }
    }

    printf("=== RESULTS ===\n");
    printf("Score: %d / %d\n", score, NUM_QUESTIONS);

    if      (score == NUM_QUESTIONS) {printf("Perfect score!\n");}
    else if (score >= 3)             {printf("Good job!\n");}
    else                             {printf("Keep practicing!\n");}

    return 0;
}
