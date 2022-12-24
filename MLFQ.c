#include<stdio.h>   
#include <stdlib.h>


struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int waiting_time;
  int complete;
  int remaining_burst;
  int turnaround_time;
};

int q2Length = -1;
int sum=0;
int FCFSsum = 0;

// round robin function
void round_robin(struct Process* q1, int num_processes, int quantum, int* total_waiting_time, int* total_turnaround_time, struct Process* q2) {
    int current_time = 0;
    int count=0,i, y = num_processes;

    

    for(int i = 0; i< num_processes; i++){
        
        q1[i].complete = 0;
        if (q1[i].burst_time < quantum){
            q1[i].waiting_time = sum - q1[i].arrival_time;
            sum+=q1[i].burst_time;
            q1[i].remaining_burst = 0;
            q1[i].turnaround_time = q1[i].burst_time+q1[i].waiting_time;
            q1[i].complete = 1;
            
        }
        else if (q1[i].burst_time == quantum){
            q1[i].waiting_time = sum - q1[i].arrival_time;
            sum+=quantum;
            q1[i].remaining_burst = 0;
            q1[i].turnaround_time = quantum + q1[i].waiting_time;
            q1[i].complete = 1;

        } 
        else{
            q1[i].waiting_time = sum - q1[i].arrival_time;
            sum+=quantum;
            q2Length++;
            q1[i].remaining_burst = q1[i].burst_time - quantum;
            q1[i].turnaround_time = quantum + q1[i].waiting_time;
            q2[q2Length] = q1[i];

        }

        
    }
    printf("\n Process ID \t\t Burst Time \t\t Turnaround Time \t Waiting Time ");  
    for (int i = 0; i < num_processes; i++){
        printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", q1[i].id, q1[i].burst_time, q1[i].turnaround_time, q1[i].waiting_time);
    }


}

//FCFS function
void FCFS(int quantum, int* total_waiting_time, int* total_turnaround_time, struct Process* q2){
    if (q2Length <0){
        printf("\nThere is no need for the second queue as everything was completed in the first\n");
    }
    else{
        printf("\n Process ID \t\t Remaining Burst Time \t\t Turnaround Time \t Waiting Time "); 
        for(int i = 0; i<q2Length+1;i++){
            printf("\n Process %d \t\t %d\t\t\t\t %d\t\t\t %d", q2[i].id, q2[i].remaining_burst, FCFSsum+q2[i].remaining_burst, FCFSsum);
            q2[i].waiting_time += (FCFSsum+sum-q2[i].turnaround_time);
            q2[i].turnaround_time += (q2[i].waiting_time + q2[i].remaining_burst);

            FCFSsum+=q2[i].remaining_burst;

        }
    }
}


int main() {
    // Prompt the user to enter the number of q1
    printf("Enter the number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);

    // Create an array of the process structure
    struct Process q1[num_processes];
    struct Process q2[num_processes];

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Prompt the user to enter the information for each process
    for (int i = 0; i < num_processes; i++) {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i+1);  
        printf("\tArrival time is: ");  // Accept arrival time  
        scanf("%d", &q1[i].arrival_time);  
        printf("\tBurst time is: "); // Accept the Burst time  
        scanf("%d", &q1[i].burst_time);  
        q1[i].id = i+1;
        q1[i].complete = 0;
    }

    // sort process array
    struct Process tempProcess;
    for (int i = 0; i <num_processes; i++){
        for (int x = 0; x<(num_processes-1);x++){
            if (q1[x].arrival_time>q1[x+1].arrival_time){
                tempProcess = q1[x];
                q1[x] = q1[x+1];
                q1[x+1] = tempProcess;
                
            }
        }
    }

    // Setting the sum to the first arrival time value in case it is not 0 to avoid negative values.
    sum = q1[0].arrival_time;

    // Prompt the user to enter the time quantum for the Round Robin scheduler
    printf("\nEnter the time quantum: ");
    int quantum;
    scanf("%d", &quantum);

    // run for both queues
    printf("\nQueue 1");  
    round_robin(q1, num_processes, quantum, &total_waiting_time, &total_turnaround_time, q2);
    printf("\n\nQueue 2"); 
    FCFS(quantum,&total_waiting_time, &total_turnaround_time, q2);

    // summarize both queues
    printf("\n\nSummary");
    printf("\n Process ID \t\t Burst Time \t\t Turnaround Time \t Waiting Time ");  
    for (int i = 0; i < num_processes; i++){
        if (q1[i].complete == 1){
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", q1[i].id, q1[i].burst_time, q1[i].burst_time+q1[i].waiting_time, q1[i].waiting_time);
            total_waiting_time+=( q1[i].waiting_time);
            total_turnaround_time+=(q1[i].burst_time+q1[i].waiting_time);
        }
    }
    for (int i = 0; i < q2Length+1; i++){
        printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", q2[i].id, q2[i].burst_time, q2[i].burst_time+q2[i].waiting_time, q2[i].waiting_time);
        total_waiting_time+=(q2[i].waiting_time);
        total_turnaround_time+=(q2[i].burst_time+q2[i].waiting_time);
    }

    // Calculate the average waiting and turnaround times
    float average_waiting_time = (float)total_waiting_time / num_processes;
    float average_turnaround_time = (float)total_turnaround_time / num_processes;
    printf("\n\nAverage waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);

    return 0;
}