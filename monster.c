#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper to generate random numbers
int getRandomInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// --- Knight Actions ---
int attack() {
    return getRandomInRange(5, 12);
}

int heal() {
    return getRandomInRange(8, 15);
}

int specialAttack() {
    return getRandomInRange(8, 25);
}

// --- Monster Action ---
int monsterAttack() {
    return getRandomInRange(8, 12);
}

// --- Printing Functions ---
void printStatus(int kLife, int mLife) {
    printf("Knight HP: %d\n", kLife);
    printf("Monster HP: %d\n", mLife);
    printf("------------------------------\n");
}

void printRoundLog(char* message) {
    printf("%s\n", message);
}

int main() {
    srand(time(NULL)); // Seed random number generator [cite: 40]

    int knightLife = 40;
    int monsterLife = 40;
    int turn = 1;
    char choice;

    while (knightLife > 0 && monsterLife > 0) {
        printf("--- Round %d ---\n", turn);
        printf("Choose your action: (A)ttack, (H)eal, (S)pecial Attack\n");
        scanf(" %c", &choice);

        // Knight's turn
        if (choice == 'A' || choice == 'a') {
            int dmg = attack();
            monsterLife -= dmg;
            printf("You attacked the monster and dealt %d damage.\n", dmg);
        } else if (choice == 'H' || choice == 'h') {
            int hp = heal();
            knightLife += hp;
            printf("You healed yourself for %d points.\n", hp);
        } else if (choice == 'S' || choice == 's') {
            if (turn % 3 == 0) { // Special available every 3rd turn
                int dmg = specialAttack();
                monsterLife -= dmg;
                printf("You used SPECIAL ATTACK and dealt %d damage!\n", dmg);
            } else {
                printf("Special Attack not ready! You wasted your turn.\n");
            }
        }

        // Monster's turn (if still alive)
        if (monsterLife > 0) {
            int mDmg = monsterAttack();
            knightLife -= mDmg;
            printf("The monster attacked and dealt %d damage.\n", mDmg);
        }

        // Status update
        printStatus(knightLife, monsterLife);
        turn++;
    }

    if (knightLife > 0) {
        printf("🎉 Victory! You defeated the monster!\n");
    } else {
        printf("💀 You were defeated!\n");
    }

    return 0;
}