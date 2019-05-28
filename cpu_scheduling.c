#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _process{
	int pnum, arr_time, burst_time, priority, wait_time, turna_time, remain_time;
}process;

void sortp(process * pro, int index){
	process temp;
	int i,j;
	for(i = index - 1; i > 0;i--){
		for(j = 0;j < i;j++){
			if(pro[j].arr_time > pro[j+1].arr_time){
				temp = pro[j+1];
				pro[j+1] = pro[j];
				pro[j] = temp;
			
			}
			else if(pro[j].arr_time == pro[j+1].arr_time && pro[j].priority > pro[j+1].priority){
				temp = pro[j+1];
				pro[j+1] = pro[j];
				pro[j] = temp;
			}
		}
	}
}

void FCFS(process * pro, int index){
	int i,time,count,pnum = 0;
   
	for(i = 0; i < index; i++){
    	pro[i].remain_time = pro[i].burst_time;
    }
   
	time = pro[0].arr_time;
	count = index;

    while(count>0){
		if(pro[pnum].arr_time > time){
			time++;
			continue;
		}
		time += pro[pnum].remain_time;
		pro[pnum].turna_time = time - pro[pnum].arr_time;
		pro[pnum].remain_time = 0;
		printf("P%d : remain = %d, time = %d, count = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time, count);
		pnum++;
		count--;
    }

    for(i = 0; i < index; i++){
    	pro[i].wait_time = pro[i].turna_time - pro[i].burst_time;
    }
}

void SJF(process * pro, int index){
	int i,time,count,pnum = 0;
   
	for(i = 0; i < index; i++){
    	pro[i].remain_time = pro[i].burst_time;
    }
   
	time = pro[0].arr_time;
	count = index;

    while(count>0){
		if(pro[pnum].remain_time == 0){
			if(pnum < index - 1){
				pnum++;
			}
			else{
				pnum = 0;
			}
//			printf("P%d : remain = %d, time = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time);
			continue;
		}
		if(pro[pnum].arr_time > time){
			time++;
			continue;
		}
    	for(i = 0; i < index;i++){
			if(pro[pnum].remain_time > pro[i].remain_time && pro[i].arr_time <= time && pro[i].remain_time != 0){
//				printf("P%d : remain = %d, time = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time);
				pnum = i;
//				printf("P%d : remain = %d, time = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time);
			}
			else if(pro[pnum].remain_time == pro[i].remain_time && pro[i].arr_time <= time && pro[i].remain_time != 0){
				if(pro[pnum].arr_time > pro[i].arr_time){
					pnum = i;
				}
			}
		}
		time += pro[pnum].remain_time;
		pro[pnum].turna_time = time - pro[pnum].arr_time;
		pro[pnum].remain_time = 0;
		printf("P%d : remain = %d, time = %d, count = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time, count);
		pnum++;
		count--;
    }

    for(i = 0; i < index; i++){
    	pro[i].wait_time = pro[i].turna_time - pro[i].burst_time;
    }
}

void SRTF(process * pro, int index){
	int i,time,count,pnum = 0, act = 0;
   
	for(i = 0; i < index; i++){
    	pro[i].remain_time = pro[i].burst_time;
    }

	time = pro[0].arr_time;
	count = index;

	while(count>0){
		if(pro[pnum].remain_time == 0){
			if(pnum < index - 1){
				pnum++;
			}
			else{
				pnum = 0;
			}
//			printf("P%d : remain = %d, time = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time);
			continue;
		}
		if(pro[pnum].arr_time > time){
			if(act != 0){
				if(pnum < index - 1){
					pnum++;
				}
				else{
					pnum = 0;
				}
			}
			else{
				time++;
			}
			continue;
		}
		for(i = 0; i < index; i++){
			if(pro[pnum].remain_time > pro[i].remain_time && pro[i].arr_time <= time && pro[i].remain_time != 0){
				pnum = i;
			}
			else if(pro[pnum].remain_time == pro[i].remain_time && pro[i].arr_time <= time && pro[i].remain_time != 0){
				if(pro[pnum].arr_time > pro[i].arr_time){
					pnum = i;
				}
			}
		}
		pro[pnum].remain_time--;
		time++;
		if(pro[pnum].remain_time == pro[pnum].burst_time - 1){
			act++;
		}
		printf("P%d : remain = %d, time = %d, count = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time, count);
		if(pro[pnum].remain_time == 0){
			pro[pnum].turna_time = time - pro[pnum].arr_time;
			count--;
			act--;
		}
	}

	for(i = 0; i < index; i++){
		pro[i].wait_time = pro[i].turna_time - pro[i].burst_time;
    }
}

void Priority(process * pro, int index){
	int i, time, count, pnum = 0, act = 0;
   
    for(i = 0; i < index; i++){
    	pro[i].remain_time = pro[i].burst_time;
    }

    time = pro[0].arr_time;
    count = index;

    while(count>0){
		if(pro[pnum].remain_time == 0){
			if(pnum < index - 1){
				pnum++;
			}
			else{
				pnum = 0;
			}
//			printf("P%d : remain = %d, time = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time);
			continue;
		}
		if(pro[pnum].arr_time > time){
			if(act != 0){
				if(pnum < index - 1){
					pnum++;
				}
				else{
					pnum = 0;
				}
			}
			else{
				time++;
			}
			continue;
		}
		for(i = 0; i < index; i++){
			if(pro[pnum].priority > pro[i].priority && pro[i].arr_time <= time && pro[i].remain_time != 0){
//				printf("P%d : remain = %d, time = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time);
				pnum = i;
			}
			else if(pro[pnum].priority == pro[i].priority && pro[i].arr_time <= time && pro[i].remain_time != 0){
				if(pro[pnum].arr_time > pro[i].arr_time){
					pnum = i;
				}
			}
		}
		pro[pnum].remain_time--;
		time++;
		if(pro[pnum].remain_time == pro[pnum].burst_time - 1){
			act++;
		}
		printf("P%d : remain = %d, time = %d, count = %d\n", pro[pnum].pnum, pro[pnum].remain_time, time, count);
		if(pro[pnum].remain_time == 0){
			pro[pnum].turna_time = time - pro[pnum].arr_time;
			count--;
			act--;
		}
	}

    for(i = 0; i < index; i++){
    	pro[i].wait_time = pro[i].turna_time - pro[i].burst_time;
    }
}

void RR(process * pro, int index, int Q){
	int i, j, pnum = 0, count = 0, wait, temp, ta = 0, ptime = 0, act = 0;

	for(i = 0; i < index; i++){
		pro[i].remain_time = pro[i].burst_time;
 	}

	while(count != index){
		if(pro[pnum].remain_time == 0){
			if(pnum < index - 1){
				pnum++;
			}
			else{
				pnum = 0;
			}
			continue;
		}
		if(pro[pnum].arr_time > ta){
			if(act != 0){
				if(pnum < index - 1){
					pnum++;
				}
				else{
					pnum = 0;
				}
			}
			else{
				ta++;
			}
			continue;
		}
		temp = Q;
		for(i = 1; i <= Q; i++){
			if(pro[pnum].remain_time == 0){
				temp = i;
				count++;
				act--;
				break;
			}
			else{
				pro[pnum].remain_time--;
				if(pro[pnum].remain_time == 0){
					temp = i;
					count++;
					act--;
					break;
				}
			}
		}

		ta = ta + temp;
		pro[pnum].turna_time = ta;
		if(pro[pnum].turna_time != 0){
			act++;
		}
		printf("P%d : %d \ncount : %d\nindex : %d\nta : %d\n\n", pro[pnum].pnum, pro[pnum].remain_time, count, index, ta);
		if(pnum < index - 1){
			pnum++;
		}
		else{
			pnum = 0;
		}
	}
	for(i = 0; i < index; i++){
		pro[i].turna_time = pro[i].turna_time - pro[i].arr_time;
		pro[i].wait_time = pro[i].turna_time - pro[i].burst_time;
 	}
}

int main(){
	int selectmenu = 0;
	int index = 0;
	int i, j, Q;
	float av_ta = 0, av_wt = 0;
	process * pro = (process *)malloc(sizeof(process));
	
	FILE * list;
	list = fopen("proc.txt", "r");
	if(list == NULL){
		printf("file read error!!");
		exit(1);
	}
	else{
		while(!feof(list)) { 
			fscanf(list, "%d %d %d %d", &pro[index].pnum, &pro[index].burst_time, &pro[index].arr_time, &pro[index].priority);
			pro[index].wait_time = 0;
			pro[index].turna_time = 0;
			index++;
    	    if(feof(list)!=0) break;
    	}
		fclose(list);
	}
	sortp(pro, index);

	while(1){
		printf("---------------Select Menu---------------\n");
		printf("1. FCFS mode\n");
		printf("2. SJF mode\n");
		printf("3. SRTF mode\n");
		printf("4. Priority mode\n");
		printf("5. RR mode\n");
		printf("6. exit\n\n");
		printf("please insert number and enter\n");
		scanf("%d", &selectmenu);
		if(selectmenu == 6){
			printf("exit program\n");
			break;
		}
		switch(selectmenu){
			case 1:
				FCFS(pro, index);
				printf("num	wait	turn\n");
				printf("--------------------\n");
				av_ta = 0;
				av_wt = 0;
				for(j = 0; j < index; j++){
					printf("P%d :	%d	%d\n", pro[j].pnum, pro[j].wait_time, pro[j].turna_time);
					av_ta = av_ta + pro[j].turna_time;
					av_wt = av_wt + pro[j].wait_time;
				}
				printf("AV_TA = %f\n", av_ta / index);
				printf("AV_WT = %f\n", av_wt / index);
				break;
			case 2:
				SJF(pro, index);
				printf("num	wait	turn\n");
				printf("--------------------\n");
				av_ta = 0;
				av_wt = 0;
				for(j = 0; j < index; j++){
					printf("P%d :	%d	%d\n", pro[j].pnum, pro[j].wait_time, pro[j].turna_time);
					av_ta = av_ta + pro[j].turna_time;
					av_wt = av_wt + pro[j].wait_time;
				}
				printf("AV_TA = %f\n", av_ta / index);
				printf("AV_WT = %f\n", av_wt / index);
				break;
			case 3:
				SRTF(pro, index);
				printf("num	wait	turn\n");
				printf("--------------------\n");
				av_ta = 0;
				av_wt = 0;
				for(j = 0; j < index; j++){
					printf("P%d :	%d	%d\n", pro[j].pnum, pro[j].wait_time, pro[j].turna_time);
					av_ta = av_ta + pro[j].turna_time;
					av_wt = av_wt + pro[j].wait_time;
				}
				printf("AV_TA = %f\n", av_ta / index);
				printf("AV_WT = %f\n", av_wt / index);
				break;
			case 4:
				Priority(pro, index);
				printf("num	wait	turn\n");
				printf("--------------------\n");
				av_ta = 0;
				av_wt = 0;
				for(j = 0; j < index; j++){
					printf("P%d :	%d	%d\n", pro[j].pnum, pro[j].wait_time, pro[j].turna_time);
					av_ta = av_ta + pro[j].turna_time;
					av_wt = av_wt + pro[j].wait_time;
				}
				printf("AV_TA = %f\n", av_ta / index);
				printf("AV_WT = %f\n", av_wt / index);
				break;
			case 5:
				printf("enter Q var\n");
				scanf("%d", &Q);
				RR(pro, index, Q);
				printf("num	wait	turn\n");
				printf("--------------------\n");
				av_ta = 0;
				av_wt = 0;
				for(j = 0; j < index; j++){
					printf("P%d :	%d	%d\n", pro[j].pnum, pro[j].wait_time, pro[j].turna_time);
					av_ta = av_ta + pro[j].turna_time;
					av_wt = av_wt + pro[j].wait_time;
				}
				printf("AV_TA = %f\n", av_ta / index);
				printf("AV_WT = %f\n", av_wt / index);
				break;
			default:
				printf("유효한 값이 아닙니다. 다시 입력해주세요.\n");
				break;
		}
	}
	return 0;
}
