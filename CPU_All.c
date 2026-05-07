#include <iostream>
using namespace std;

int main() {
    int n, choice;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[20], bt[20], ct[20], tat[20], wt[20], priority[20];

    for (int i = 0; i < n; i++) {
        cout << "\nProcess " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority: ";
        cin >> priority[i];
    }

    do {
        cout << "\n\n===== MENU =====";
        cout << "\n1. FCFS";
        cout << "\n2. SJF (Non-preemptive)";
        cout << "\n3. Priority (Non-preemptive)";
        cout << "\n4. Round Robin";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            // FCFS
            int time = 0;

            for (int i = 0; i < n; i++) {
                if (time < at[i])
                    time = at[i];

                time += bt[i];
                ct[i] = time;
            }

            cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
            for (int i = 0; i < n; i++) {
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];

                cout << i + 1 << "\t" << at[i] << "\t" << bt[i]
                     << "\t" << ct[i] << "\t" << tat[i]
                     << "\t" << wt[i] << endl;
            }
        }

        else if (choice == 2) {
            // SJF (Non-preemptive)
            int done[20] = {0};
            int time = 0, completed = 0;

            while (completed < n) {
                int min = 9999, index = -1;

                for (int i = 0; i < n; i++) {
                    if (!done[i] && at[i] <= time && bt[i] < min) {
                        min = bt[i];
                        index = i;
                    }
                }

                if (index == -1) {
                    time++;
                    continue;
                }

                time += bt[index];
                ct[index] = time;
                done[index] = 1;
                completed++;
            }

            cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
            for (int i = 0; i < n; i++) {
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];

                cout << i + 1 << "\t" << at[i] << "\t" << bt[i]
                     << "\t" << ct[i] << "\t" << tat[i]
                     << "\t" << wt[i] << endl;
            }
        }

        else if (choice == 3) {
            // Priority (Non-preemptive)
            int done[20] = {0};
            int time = 0, completed = 0;

            while (completed < n) {
                int high = 9999, index = -1;

                for (int i = 0; i < n; i++) {
                    if (!done[i] && at[i] <= time && priority[i] < high) {
                        high = priority[i];
                        index = i;
                    }
                }

                if (index == -1) {
                    time++;
                    continue;
                }

                time += bt[index];
                ct[index] = time;
                done[index] = 1;
                completed++;
            }

            cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
            for (int i = 0; i < n; i++) {
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];

                cout << i + 1 << "\t" << at[i] << "\t" << bt[i]
                     << "\t" << priority[i] << "\t" << ct[i]
                     << "\t" << tat[i] << "\t" << wt[i] << endl;
            }
        }

        else if (choice == 4) {
            // Round Robin
            int quantum;
            cout << "Enter Time Quantum: ";
            cin >> quantum;

            int rem_bt[20];
            for (int i = 0; i < n; i++)
                rem_bt[i] = bt[i];

            int time = 0, completed = 0;

            while (completed < n) {
                int doneFlag = 1;

                for (int i = 0; i < n; i++) {
                    if (rem_bt[i] > 0 && at[i] <= time) {
                        doneFlag = 0;

                        if (rem_bt[i] > quantum) {
                            time += quantum;
                            rem_bt[i] -= quantum;
                        } else {
                            time += rem_bt[i];
                            ct[i] = time;
                            rem_bt[i] = 0;
                            completed++;
                        }
                    }
                }

                if (doneFlag)
                    time++;
            }

            cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
            for (int i = 0; i < n; i++) {
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];

                cout << i + 1 << "\t" << at[i] << "\t" << bt[i]
                     << "\t" << ct[i] << "\t" << tat[i]
                     << "\t" << wt[i] << endl;
            }
        }

    } while (choice != 5);

    return 0;
}
