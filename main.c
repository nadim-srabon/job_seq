#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the jobs array
    struct Job {
        char jobId;    // Job ID
        int profit;    // Profit of the job
        int deadline;  // Deadline of the job
    };

    struct Job jobs[] = {
        {'a', 20, 4},
        {'b', 10, 1},
        {'c', 40, 1},
        {'d', 30, 1}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]); // Number of jobs

    // Sort jobs based on profit in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    // Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Array to store the job sequence and mark slots
    int slot[maxDeadline];
    char jobSequence[maxDeadline];

    // Initialize all slots to -1 (unoccupied)
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Perform job sequencing
    for (int i = 0; i < n; i++) {
        // Check for a free slot from the last possible slot
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {  // If the slot is free
                slot[j] = i;      // Assign this job to the slot
                jobSequence[j] = jobs[i].jobId;
                break;
            }
        }
    }

    // Print the job sequence
    printf("Job sequence for maximum profit: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%c ", jobSequence[i]);
        }
    }
    printf("\n");

    return 0;
}
