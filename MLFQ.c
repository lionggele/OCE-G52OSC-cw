#include<stdio.h>   
    // initlialize the variable name  
    int i, y, sum=0, count=0, temp[10];
    int x = -1;
    int NOP; 
    int quantum; 
    int waiting_time=0, turnaround_time=0;
    int arrival_time[10], burst_time[10], remaining_burst_time[10], process_id[10], remaining_process[10];
    float avg_waiting_time, avg_turnaround_time;  



int RR(){  
    waiting_time = 0;
    char stringNum[10];
    printf("\n Process No \t\t Burst Time \t\t Turnaround Time \t\t Remaining Burst Time \t\t Waiting Time");  
    i = 0;
    
    while (burst_time[i] != 0 ){
        sum+=quantum;
        
        remaining_burst_time[i] = burst_time[i] - quantum;
        if (remaining_burst_time[i] > 0){
            x++;
            temp[x] = remaining_burst_time[i];
            remaining_process[x] = process_id[i];
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t\t %d \t\t\t %d", i+1, burst_time[i], quantum, remaining_burst_time[i], sum-arrival_time[i]-burst_time[i]);  
        }
        else if (remaining_burst_time[i] < 0){
            remaining_burst_time[i] = 0;
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t\t %d", i+1, burst_time[i], burst_time[i], remaining_burst_time[i]); 
        }
        else{
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t\t %d", i+1, burst_time[i], quantum, remaining_burst_time[i]);  
        }
         
        i++;
    }
    }   

int FCFS(){
    i = 0;
    sum = 0;
    waiting_time = 0;
    printf("\n Process No \t\t Remaining Burst Time \t\t Turnaround Time \t\t Waiting Time");  
    while (temp[i] != 0){
        
        printf("\n Process %d \t\t %d\t\t\t\t %d\t\t\t\t %d", remaining_process[i], temp[i], temp[i]+waiting_time, waiting_time); 
        waiting_time+=(temp[i]+waiting_time);

        i++;

    }
}


int main(){
    // Accept number of processes
    printf(" Total number of process in the system: ");  
    scanf("%d", &NOP);  
    y = NOP; // Assign the number of process to variable y  
  
    // Use for loop to enter the details of the process like Arrival time and the Burst Time  
    for(i=0; i<NOP; i++){  
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
        printf("\tArrival time is: ");  // Accept arrival time  
        scanf("%d", &arrival_time[i]);  
        printf(" \tBurst time is: "); // Accept the Burst time  
        scanf("%d", &burst_time[i]);  

        process_id[i] = i+1;
    }  
    printf("\n Enter the Time Quantum for the process: ");  
    scanf("%d", &quantum);  
    printf("\nFirst Queue");
    RR();
    printf("\n\nSecond Queue");
    FCFS();
    printf("\n\nSummary\n");
    printf("\n Process No \t\t Burst Time \t\t Turnaround Time \t\t Waiting Time"); 
    for(i=0; i<NOP; i++){
        if(remaining_burst_time[i] == 0)
        printf("\n Process %d \t\t %d\t\t\t %d\t\t\t\t %d", i+1, burst_time[i], burst_time[i], 0);  
    }
    i = 0;
    waiting_time = 0;
    while(temp[i] != 0){
        printf("\n Process %d \t\t %d\t\t\t %d\t\t\t\t %d", remaining_process[i], temp[i]+quantum, temp[i]+waiting_time+quantum, waiting_time);  
        waiting_time+=(temp[i]+waiting_time);
        i++;
    }

}