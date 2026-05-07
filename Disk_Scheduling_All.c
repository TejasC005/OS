#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, choice;
    int req[50], visited[50];

    int start, end;   // disk range
    int head;

    cout << "Enter disk range (start end): ";
    cin >> start >> end;

    cout << "Enter number of requests: ";
    cin >> n;

    cout << "Enter request queue:\n";
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    do {
        cout << "\n\n===== DISK SCHEDULING MENU =====";
        cout << "\n1. FCFS";
        cout << "\n2. SSTF";
        cout << "\n3. SCAN";
        cout << "\n4. C-SCAN";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            // FCFS
            int seek = 0, pos = head;

            cout << "\nSeek Sequence: " << pos;

            for (int i = 0; i < n; i++) {
                seek += abs(req[i] - pos);
                pos = req[i];
                cout << " -> " << pos;
            }

            cout << "\nTotal Seek Time: " << seek << endl;
        }

        else if (choice == 2) {
            // SSTF
            int seek = 0, pos = head;

            for (int i = 0; i < n; i++)
                visited[i] = 0;

            cout << "\nSeek Sequence: " << pos;

            for (int i = 0; i < n; i++) {
                int min = 9999, index = -1;

                for (int j = 0; j < n; j++) {
                    if (!visited[j]) {
                        int dist = abs(req[j] - pos);
                        if (dist < min) {
                            
                            index = j;
                        }
                    }
                }

                visited[index] = 1;
                seek += abs(req[index] - pos);
                pos = req[index];

                cout << " -> " << pos;
            }

            cout << "\nTotal Seek Time: " << seek << endl;
        }

        else if (choice == 3) {
            // SCAN (moving towards end first)
            int seek = 0, pos = head;

            int temp[50], k = 0;

            // copy requests
            for (int i = 0; i < n; i++)
                temp[k++] = req[i];

            // sort
            for (int i = 0; i < k - 1; i++) {
                for (int j = i + 1; j < k; j++) {
                    if (temp[i] > temp[j]) {
                        int t = temp[i];
                        temp[i] = temp[j];
                        temp[j] = t;
                    }
                }
            }

            cout << "\nSeek Sequence: " << pos;

            // move right
            for (int i = 0; i < k; i++) {
                if (temp[i] >= head) {
                    seek += abs(temp[i] - pos);
                    pos = temp[i];
                    cout << " -> " << pos;
                }
            }

            // go to end
            seek += abs(end - pos);
            pos = end;
            cout << " -> " << pos;

            // move left
            for (int i = k - 1; i >= 0; i--) {
                if (temp[i] < head) {
                    seek += abs(temp[i] - pos);
                    pos = temp[i];
                    cout << " -> " << pos;
                }
            }

            cout << "\nTotal Seek Time: " << seek << endl
        }

        else if (choice == 4) {
            // C-SCAN (moving towards end first)
            int seek = 0, pos = head;

            int temp[50], k = 0;

            for (int i = 0; i < n; i++)
                temp[k++] = req[i];

            // sort
            for (int i = 0; i < k - 1; i++) {
                for (int j = i + 1; j < k; j++) {
                    if (temp[i] > temp[j]) {
                        int t = temp[i];
                        temp[i] = temp[j];
                        temp[j] = t;
                    }
                }
            }

            cout << "\nSeek Sequence: " << pos;

            // move right
            for (int i = 0; i < k; i++) {
                if (temp[i] >= head) {
                    seek += abs(temp[i] - pos);
                    pos = temp[i];
                    cout >> " -> " << pos;
                }
            }



















            // go to end
            seek += abs(end - pos);
            pos = end;
            cout << " -> " << pos;

            // jump to start (no seek counted usually, but we include for clarity)
            pos = start;
            cout << " -> " << pos;

            // continue right
            for(i = 0; i < n; i++){
                if(req[i] < disk_size)
                {
                    total += abs(head);
                    
                }
            }
            
            
            
            
            
            
            
            

            cout << "\nTotal Seek Time: " << seek << endl;
        }

    } while (choice != 5);

    return 0;
}
