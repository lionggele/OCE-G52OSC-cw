// scheduling
// Online resource : https://www.geeksforgeeks.org/program-for-fcfs-cpu-scheduling-set-1/
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the information for each process
struct Process
{
    int id;
    int burst_time;
};

// Function to implement FCFS scheduler algorithm.
void first_come_first_serve(struct Process *processes, int num_processes, int *total_waiting_time, int *total_turnaround_time)
{

    int waiting_time[num_processes];
    waiting_time[0] = 0;

    // for calculating waiting time of each process
    for (int i = 1; i < num_processes; i++)
    {
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1];
    }

    for (int i = 0; i < num_processes; i++)
    {
        printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", processes[i].id,
               processes[i].burst_time, waiting_time[i], processes[i].burst_time + waiting_time[i]);
        *total_waiting_time += waiting_time[i];
        *total_turnaround_time += waiting_time[i] + processes[i].burst_time;
    }
}

int main()
{
    // Prompt the user to enter the number of processesA
    printf("Enter the number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);

    // Create an array of the process structure
    struct Process processes[num_processes];

    // Use for loop to enter the details of the process like Arrival time and the Burst Time
    for (int i = 0; i < num_processes; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" \tBurst time is: "); // Accept the Burst time
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    // Run the FCFS scheduling algorithm
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("\n Process ID \t\t Burst Time \t\t Turnaround Time \t Waiting Time ");
    first_come_first_serve(processes, num_processes, &total_waiting_time, &total_turnaround_time);

    // Calculate the average waiting time
    float average_waiting_time = (float)total_waiting_time / num_processes;
    float average_turnaround_time = (float)total_turnaround_time / num_processes;
    printf("\nAverage waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);

    return 0;
}