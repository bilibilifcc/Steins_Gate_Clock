#include "tools.h"

//生成随机数
//区间(min,max]
int randBetween(int min,int max){
    int rand1 = qrand() % (max - min);
    return (rand1 + min);
}
