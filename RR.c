// C program for implementation of FCFS
// scheduling
#include <stdio.h>
// Function to find the waiting time for all
// processes
void waitingTime(int n,
                 int bt[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time
void turnAroundTime(int n,
                    int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void avgTime(int n, int al[], int bt[], int t)
{
    int i, wt[n], tat[n], total = 0, counter = 0, total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    waitingTime(n, bt, wt);

    // Function to find turn around time for all processes
    turnAroundTime(n, bt, wt, tat);

    // Display processes along with all details
    printf("Processes Arrival time Burst time Waiting time Turn around time\n");

    for (total = 0, i = 0; n != 0)
    {
        if (bt[i] <= t && bt[i] > 0)
        {
            total = total + bt[i];
            bt[i] = 0;
            counter = 1;
        }
        else if (bt[i] > 0)
        {
            bt[i] = bt[i] - t;
            total = total + t;
        }
        // Calculate total waiting time and total turn
        // around time
        if (bt[i] == 0 && counter == 1)
        {
            n--;
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            printf(" %d ", (i + 1));
            printf("	       %d ", al[i]);
            printf("	    %d ", bt[i]);
            printf("	         %d", wt[i]);
            printf("	     %d\n", tat[i]);
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (al[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    int s = (float)total_wt / (float)n;
    int t = (float)total_tat / (float)n;
    printf("Average waiting time = %d", s);
    printf("\n");
    printf("Average turn around time = %d ", t);
    printf("\n");
    printf("Total number of task processes per unit of time: %d", n);
}

// Driver code
int main()
{
    // process id's
    // int processes[];
    // int n = sizeof processes / sizeof processes[0];
    int processes[20];
    int n;

    // arrival_time for all processes
    int arrival_time[20];

    // Burst time of all processes
    int burst_time[20];

    // time queantum
    int time_quantum;
    //  Enter number of process
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        // Enter process id's
        printf("Enter process id of all the processes: ");
        scanf("%d", &processes[i]);

        // Eneter Arrival Time
        printf("Enter the arrival time for %d process: ", processes[i]);
        scanf("%d", &arrival_time[i]);

        // Enter burst time
        printf("Enter the burst time for %d process: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter Time Quantum:\n");
    scanf("%d", &time_quantum);

    avgTime(n, arrival_time, burst_time, time_quantum);
    return 0;
}
