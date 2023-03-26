#include<stdio.h>
#include<string.h>

struct process_struct {
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
};

void faculty_Queue(int cnt) {

        int count, arrival_Time, burst_Time, quantum_time;
        struct process_struct faculty_Process[cnt];

        for(int count = 0; count < cnt; count++) {
                printf("Enter the details of Process[%d]", count+1);
                puts("");
                printf("Process Name : ");
                scanf("%s", faculty_Process[count].process_name);
        
                printf("Arrival Time : ");
                scanf("%d", &faculty_Process[count].arrival_time);
        
                printf("Burst Time : ");
                scanf("%d", &faculty_Process[count].burst_time);
                puts("");
        }
        printf("quantum time for FACULTY queue : ");
        scanf("%d", &quantum_time);

        

}

void student_Queue(int cnt) {
        int count, arrival_Time, burst_Time, quantum_time;
        struct process_struct student_Process[cnt];

        for(int count = 0; count < cnt; count++) {
                printf("Enter the details of Process[%d]", count+1);
                puts("");
                printf("Process Name : ");
                scanf("%s", student_Process[count].process_name);
        
                printf("Arrival Time : ");
                scanf("%d", &student_Process[count].arrival_time);
        
                printf("Burst Time : ");
                scanf("%d", &student_Process[count].burst_time);
                puts("");
        }
        printf("quantum time for FACULTY queue : ");
        scanf("%d", &quantum_time);    



}

int main() {
    int selected,cnt;
    printf("Please choose a queue to post your query : ");
    printf("1. FACULTY queue.");
    printf("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &selected);
 
    switch(selected) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &cnt);
                
                faculty_Queue(cnt);
                
                break;
 
        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &cnt);
 
                student_Queue(cnt);
                
                break;
 
        default : 
                printf("Please selet the correct option by running the program again.");
    }
 
    return 0;
}