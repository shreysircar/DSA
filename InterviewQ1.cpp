🧩 Problem Statement (Reframed)

You are given a lab consisting of N workstations arranged in a row. Each workstation is represented by a character in a string lab:

'S' → occupied by a student
'.' → empty workstation

You can install a computer system only on an empty workstation ('.').

⚙️ Rules:
Each student ('S') needs access to at least one adjacent system.
A system placed at index i can serve:
the student at i - 1 (left), or
the student at i + 1 (right)
A system can serve multiple students if they are adjacent.
A student is considered served if at least one adjacent workstation has a system.
🎯 Goal:

Return the minimum number of systems required so that all students are served.

If it is impossible to serve all students, return -1.

//solution (greedy)
#include <iostream>
using namespace std;

int solution(int N, string lab) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (lab[i] == 'S') {

            // 👉 If already served, skip
            if ((i - 1 >= 0 && lab[i - 1] == 'X') ||
                (i + 1 < N && lab[i + 1] == 'X')) {
                continue;
            }

            // 👉 Prefer right
            if (i + 1 < N && lab[i + 1] == '.') {
                lab[i + 1] = 'X';
                count++;
            }
            // 👉 Otherwise left
            else if (i - 1 >= 0 && lab[i - 1] == '.') {
                lab[i - 1] = 'X';
                count++;
            }
            // 👉 Impossible
            else {
                return -1;
            }
        }
    }

    return count;
}

//No real overlapping subproblems->no DP 