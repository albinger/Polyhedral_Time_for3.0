#include "num2words-en.h"
#include "string.h"
#include "pebble.h"


int time_to_2words(int hours, int minutes, char *line1, char *line2, size_t length)
{

	//ShowDie = time_to_words(hours, minutes, value, length);
	char hrs[10];
  char mns[10];
  
  int hrand;
  int mrand;
  
  static int const DICE[] = {
    4,
    6,
    8,
    10,  
    12,
    20,
    12,
    10,
    8,
    6,
    4
  };
  
  hrand = DICE[rand()%5];
  mrand = DICE[rand()%11];
  
  if(hours/hrand==0){
    snprintf(hrs,9,"1d%i-%i",hrand,hrand-hours);
  }else{
    if(hours%hrand != 0){
      snprintf(hrs,9,"%id%i+%i",(hours/hrand),hrand,(hours%hrand));
    }else{  
      snprintf(hrs,9,"%id%i",(hours/hrand),hrand);
    }
  }
  if(minutes == 0){
    snprintf(mns,9," ");
  }else{
    if(minutes/mrand==0){
      snprintf(mns,9,"1d%i-%i",mrand,mrand-minutes);
    }else{ 
      if(minutes%mrand != 0){
        snprintf(mns,9,"%id%i+%i",(minutes/mrand),mrand,(minutes%mrand));
      }else{
        snprintf(mns,9,"%id%i", (minutes/mrand),mrand);
      }
    }
  }
  memset(line1, '\0', length);
  memset(line2, '\0', length);
  //snprintf(line1,strlen(hrs),"%s ",hrs);  
  memcpy(line1,hrs,strlen(hrs));
  //snprintf(line2,strlen(mns),"%s ",mns); 
  memcpy(line2,mns,strlen(mns));
  //APP_LOG(APP_LOG_LEVEL_INFO, "hrs:%s:", hrs);
  //APP_LOG(APP_LOG_LEVEL_INFO, "mns:%s:", mns);
  


  if(mrand == 20){return(0);}else{return(1);}
}
