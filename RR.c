#include<stdio.h>   

struct Process {
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
};
  
int main(){  
    // initlialize the variable name  
    int i, y, sum=0, count=0, temp[10];
    int NOP, quantum, waiting_time=0, turnaround_time=0;  
    float avg_waiting_time, avg_turnaround_time;  
    

    // Accept number of processes
    printf(" Total number of process in the system: ");  
    scanf("%d", &NOP);  
    y = NOP; // Assign the number of process to variable y  
    struct Process processes[NOP];
    struct Process temporary[NOP];
  
    // Use for loop to enter the details of the process like Arrival time and the Burst Time  
    for(i=0; i<NOP; i++){  
        // processes[i].arrival_time = 0;
        // processes[i].burst_time = 0;
        // processes[i].turnaround_time = 0;
        // processes[i].waiting_time = 0;
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
        printf("\tArrival time is: ");  // Accept arrival time  
        scanf("%d", &processes[i].arrival_time);  
        printf(" \tBurst time is: "); // Accept the Burst time  
        scanf("%d", &processes[i].burst_time);  
        temporary[i].burst_time = processes[i].burst_time; // store the burst time in temp array  
    }  

    // Accept the Time quantum  
    printf("\n Enter the Time Quantum for the process: ");  
    scanf("%d", &quantum);  

    // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\n Process No \t\t Burst Time \t\t Turnaround Time \t Waiting Time ");  
    for(sum=processes[0].arrival_time, i = 0; y!=0; ) {  
        if(temporary[i].burst_time <= quantum && temporary[i].burst_time > 0){ // if burst time is lesser than quantum
            sum = sum + temporary[i].burst_time;  
            temporary[i].burst_time = 0;  
            count=1;  
        }     
        else if(temporary[i].burst_time > 0){   // if burst time is more than quantum
            temporary[i].burst_time = temporary[i].burst_time - quantum;  
            sum = sum + quantum;    
        }  
        if(temp[i]==0 && count==1){  
            y--; //decrement the process no.  
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", i+1, processes[i].burst_time, sum - processes[i].arrival_time, sum - processes[i].arrival_time - processes[i].burst_time);  
            waiting_time = waiting_time+sum-processes[i].arrival_time-processes[i].burst_time;  
            turnaround_time = turnaround_time+sum-processes[i].arrival_time;  
            count =0;     
        }  
        if(i==NOP-1){  // checks if it is the last procedure and resetting i to 0
            i=0;  
        }  
        else if(processes[i+1].arrival_time<=sum){  // checks if the next arrival time is lesser than the sum.
            i++;  
        }  
        else{  
            i=0;  
        }  
    }   

    // represents the average waiting time and Turn Around time  
    avg_waiting_time = waiting_time * 1.0/NOP;  
    avg_turnaround_time = turnaround_time * 1.0/NOP;  
    printf("\n\nAverage Turn Around Time: %.2f", avg_waiting_time);  
    printf("\nAverage Waiting Time: %.2f", avg_turnaround_time);  
    getchar();  

    return 0;
}  