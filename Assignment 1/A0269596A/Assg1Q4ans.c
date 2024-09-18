// CS2100 Computer Organisation
// AY2024/2025 Semester 1
// National University of Singapore.
// Assignment 1 Question 4.
// All rights reserved.
//
// Start by filling in the following variables which main() will print out so as to identify yourself.
// Failure to full in the details correctly will be penalised.
//

const char *student_number = "A0269596A";
const char *student_name = "Ricco Lim";
const char *student_tut_grp = "T07";

int func(int a) {
    int i = 32, count = 0;
    while (i > 0) {
        if (a >= 0) count++;
        i--;
        if (i == 0) break;
        a *= 2;
    }
    return count;
}