#include <stdio.h>
#include <stdlib.h>

// Structure to hold the information for each process
struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int complete;
};

// Function to implement the Round Robin scheduling algorithm
void round_robin(struct Process *processes, int num_processes, int quantum, int *total_waiting_time, int *total_turnaround_time)
{
    int current_time = 0;
    int sum, count = 0, i, y = num_processes, temp[num_processes];

    for (int a = 0; a < num_processes; a++)
    {
        temp[a] = processes[a].burst_time;
    }

    for (sum = processes[0].arrival_time, i = 0; y != 0;)
    {
        if (temp[i] <= quantum && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quantum;
            sum = sum + quantum;
        }

        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", processes[i].id, processes[i].burst_time, sum - processes[i].arrival_time, sum - processes[i].arrival_time - processes[i].burst_time);
            *total_waiting_time += sum - processes[i].arrival_time - processes[i].burst_time;
            *total_turnaround_time += sum - processes[i].arrival_time;
            count = 0;
        }
        if (i == num_processes - 1)
        {
            i = 0;
        }
        else if (processes[i + 1].arrival_time <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
}

int main()
{
    // Prompt the user to enter the number of processes
    printf("Enter the number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);

    // Create an array of the process structure
    struct Process processes[num_processes];
    float total_burst_time;

    // Use for loop to enter the details of the process like Arrival time and the Burst Time
    for (int i = 0; i < num_processes; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf("\tArrival time is: "); // Accept arrival time
        scanf("%d", &processes[i].arrival_time);
        printf(" \tBurst time is: "); // Accept the Burst time
        scanf("%d", &processes[i].burst_time);
        total_burst_time += processes[i].burst_time;
        processes[i].id = i + 1;
    }

    // sort process array
    struct Process tempProcess;
    for (int i = 0; i < num_processes; i++)
    {
        for (int x = 0; x < (num_processes - 1); x++)
        {
            if (processes[x].arrival_time > processes[x + 1].arrival_time)
            {
                tempProcess = processes[x];
                processes[x] = processes[x + 1];
                processes[x + 1] = tempProcess;
            }
        }
    }

    // Prompt the user to enter the time quantum for the Round Robin scheduler
    printf("Enter the time quantum: ");
    int quantum;
    scanf("%d", &quantum);

    // Run the Round Robin scheduling algorithm
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("\n Process ID \t\t Burst Time \t\t Turnaround Time \t Waiting Time ");
    round_robin(processes, num_processes, quantum, &total_waiting_time, &total_turnaround_time);

    // Calculate the average waiting time
    float average_waiting_time = (float)total_waiting_time / num_processes;
    float average_turnaround_time = (float)total_turnaround_time / num_processes;
    printf("\nAverage waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);

    // Calculate throughput
    float throughput = (float)num_processes / total_burst_time;
    printf("Throughput: %.2f\n", throughput);

    return 0;
}
