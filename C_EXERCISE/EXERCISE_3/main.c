#include <stdio.h>
#include <stdarg.h>

typedef enum {
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
} DeviceType;

typedef enum {
    ON,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    UNLOCK,
    LOCK,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    CHANGE_TRACK
} CommandType;

void processControl(DeviceType type, ...){
    va_list arg;
    va_start (arg, type);
    switch (type)
    {
    case LIGHT:
        CommandType cmd= va_arg(arg,CommandType);
        if(cmd == ON){
            printf("Light turned ON\n");
        }else if (cmd == OFF)
        {
            printf("Light turned OFF\n");
        }
        else{
            printf("You can must ON or Off device \n");
        }
        /* code */
        break;
    case AIR_CONDITIONER:
        CommandType conTrol= va_arg(arg,CommandType);
        CommandType temperature= va_arg(arg,CommandType);
        CommandType value= va_arg(arg,int);
        if (conTrol == ON)
        {
            printf("AIR_CONDITIONER turned ON\n"); 
            if (temperature == SET_TEMPERATURE)
            {
                printf("Change TEMPERATURE set to %d degrees \n", value);
            }
        }
        else if (conTrol == OFF)
        {
            printf("AIR_CONDITIONER turned OFF\n");
        }
        else{
             printf("You can ON or Off device \n"); 
             break;
        }
        break;
    case FINGERPRINT_LOCK:
        CommandType a= va_arg(arg,CommandType);
        if (a == UNLOCK)
        {
            printf("FINGERPRINT is UNLOCK \n");
        }
        else if (a == LOCK)
        {
             printf("FINGERPRINT is LOCK \n");
        }
        else{
             printf("FINGERPRINT must UNLOCK or LOCK device \n"); 
             break;
        }
        
        break;
    case MUSIC_PLAYER:
        CommandType ctr= va_arg(arg,CommandType);
        CommandType volume= va_arg(arg,CommandType);
        CommandType change= va_arg(arg,CommandType);
        if (ctr == ON)
        {
            printf("MUSIC_PLAYER turned ON\n"); 
            if (volume == INCREASE_VOLUME)
            {
                printf("INCREASE_VOLUME\n");
            }
            if (volume == DECREASE_VOLUME)
            {
                printf("DECREASE_VOLUME\n");
            }
            if (change == CHANGE_TRACK)
            {
                printf("NEXT SONG\n");
            }
            
        }
        else if (ctr == OFF)
        {
            printf("AIR_CONDITIONER turned OFF");
        }
        else{
             printf("You must ON or Off device "); 
             break;
        }
        break;
    default:
        break;
    }
    va_end(arg);
}

int main(){

    processControl(LIGHT,ON);
    processControl(LIGHT,OFF);
    processControl(AIR_CONDITIONER, ON,SET_TEMPERATURE,25);
    processControl(FINGERPRINT_LOCK, LOCK);
    processControl(MUSIC_PLAYER,ON,DECREASE_VOLUME);
    return 0;

}