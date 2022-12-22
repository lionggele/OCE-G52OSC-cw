#include<stdio.h>   
  
int main(){  
    // initlialize the variable name  
    int i, y, sum=0, count=0, temp[10];
    int NOP, quantum, waiting_time=0, turnaround_time=0, arrival_time[10], burst_time[10];  
    float avg_waiting_time, avg_turnaround_time;  

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
        temp[i] = burst_time[i]; // store the burst time in temp array  
    }  

    // Accept the Time quantum  
    printf("\n Enter the Time Quantum for the process: ");  
    scanf("%d", &quantum);  

    // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\n Process No \t\t Burst Time \t\t Turnaround Time \t Waiting Time ");  
    for(sum=0, i = 0; y!=0; ) {  
        if(temp[i] <= quantum && temp[i] > 0){ // define the conditions 
            sum = sum + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0){  
            temp[i] = temp[i] - quantum;  
            sum = sum + quantum;    
        }  
        if(temp[i]==0 && count==1){  
            y--; //decrement the process no.  
            printf("\n Process %d \t\t %d\t\t\t %d\t\t\t %d", i+1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);  
            waiting_time = waiting_time+sum-arrival_time[i]-burst_time[i];  
            turnaround_time = turnaround_time+sum-arrival_time[i];  
            count =0;     
        }  
        if(i==NOP-1){  
            i=0;  
        }  
        else if(arrival_time[i+1]<=sum){  
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