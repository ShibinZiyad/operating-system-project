#include <stdio.h>
#include<stdbool.h>


void queueUpdate(int queue[],int timer,int arrival[],int n, int maxProccessIndex){
	int zeroIndex, i;
	for( i = 0; i < n; i++){
		if(queue[i] == 0){
			zeroIndex = i;
			break;
		}
	}
	queue[zeroIndex] = maxProccessIndex + 1;
}

void queueMaintain(int queue[], int n){
	int i;
	for( i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
		int temp = queue[i];
		queue[i] = queue[i+1];
		queue[i+1] = temp;
	}
}

void checkNewArrival(int timer, int arrival[], int n, int maxProccessIndex,int queue[]){
	if(timer <= arrival[n-1]){
	bool newArrival = false;
	int j;
	for( j = (maxProccessIndex+1); j < n; j++){
			if(arrival[j] <= timer){
			if(maxProccessIndex < j){
				maxProccessIndex = j;
				newArrival = true;
			}
		}
	}

	if(newArrival)
		queueUpdate(queue,timer,arrival,n, maxProccessIndex);
	}
}

int main(){
    printf("There is two options. Press 1 for Student Queue. Press 2 for Faculty Queue.\n");
    int X;
    scanf("%d",&X);
	int n,tq, timer = 0, maxProccessIndex = 0,i;
	float avgWait = 0, avgTT = 0;
	printf( "\n Time quantum : ");
	scanf("%d",&tq);
	printf( "\nNumber of processes : ");
	scanf("%d",&n);
	int arrival[n], burst[n], wait[n], turn[n], queue[n], temp_burst[n],turnAround[n],completionTime[n];  //#
	bool complete[n];

	for(i=0;i<n;i++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
        scanf("%d",&arrival[i]);
        scanf("%d",&burst[i]);
		temp_burst[i] = burst[i];
	}

	for( i = 0; i < n; i++){
		complete[i] = false;
		queue[i] = 0;
	}
	while(timer < arrival[0])
		timer++;
	queue[0] = 1;

	while(true){
		bool flag = true;
		for( i = 0; i < n; i++){
			if(temp_burst[i] != 0){
				flag = false;
				break;
			}
		}
		if(flag)
			break;

		for( i = 0; (i < n) && (queue[i] != 0); i++){
			int ctr = 0;
			while((ctr < tq) && (temp_burst[queue[0]-1] > 0)){
				temp_burst[queue[0]-1] -= 1;
				timer += 1;
				ctr++;


				checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
			}

			if((temp_burst[queue[0]-1] == 0) && (complete[queue[0]-1] == false)){

				turn[queue[0]-1] = timer;
				complete[queue[0]-1] = true;
			}


			bool idle = true;
			if(queue[n-1] == 0){
				for(int i = 0; i < n && queue[i] != 0; i++){
					if(complete[queue[i]-1] == false){
						idle = false;
					}
				}
			}
			else
				idle = false;

			if(idle){
				timer++;
				checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
			}



			queueMaintain(queue,n);
		}
	}

	for(i = 0; i < n; i++){
		turn[i] = turn[i] - arrival[i];
		wait[i] = turn[i] - burst[i];
        turnAround[i] = wait[i] + burst[i]; //#
        completionTime[i] = turnAround[i] + arrival[i];
    }

    printf("\nNo\t|AT\t|BT\t|WT\t|TT\t| CT|\n");


	for( i = 0; i < n; i++){
		printf("%d\t| %d\t| %d\t| %d\t|%d\t|%d\t|\n",i+1, arrival[i],burst[i],wait[i],turnAround[i],completionTime[i]);


	}

	for( i =0; i< n; i++){
		avgWait += wait[i];
		avgTT += turnAround[i];
	}

	printf("\nAverage wait time : %f\nAverage Turn Around Time : %f ",(avgWait/n),(avgTT/n));

	return 0;

}

