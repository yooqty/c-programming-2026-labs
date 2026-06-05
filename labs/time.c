#include <time.h>
int main() { 
    clock_t t_start,t_end;
    t_start = clock(); // начать подсчет времепни с этой точки
    for (int i=0; i<10000000; i++)    
    duration = (clock() - t_start) / (double) CLOCKS_PER_SEC;	//Расчитать время работы программы от старта до текущего момента
    printf("Need_time duration  = %f",duration);
    return 0;
}




#include <time.h>
int main() { 
    time_t  t1,t0;
    long unsigned int i;
    t0 = time (NULL);// начать подсчет времепни
    for(i=0; i<1500000000L; i++); // Расчтеn «алгоритма»
    t1 = time (NULL);
    diftime =  difftime( t1,  t0); //Расчитать время работы программы в секундах    
    printf("Need time difftime = %f \n",diftime); return 0;
}




#include <time.h>
/* вывод   локального времени и времени по Гринвичу */
int main(void)
{
    struct tm *local, *gm;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    printf ("Local time and date: %s", asctime(local));
    gm = gmtime(&t);
    printf ("Greenwich mean time and date: %s", asctime(gm));
    return 0;  }




int main(void)
{
struct tm t;
t.tm_year = 90; /* 1990 год */
t.tm_mon = 1; /* месяц - 1 */
t.tm_mday = 7;
mktime(&t);
printf("The day of the week is %d", t.tm_wday);
return 0;
}




#include <time.h>
#include <cstdio>
			
int main(int argc, char** argv) {
time_t tod;
time(&tod);
 		
printf(“Time is %s\n", ctime(&tod));

return 0;
}

#include <stdio.h>
#include <time.h>
int main() {
    time_t t;
    struct tm *p;
    char s[80];
    char* format = "%A %B %Y";
    t = time(NULL);
    p = gmtime(&t);
    strftime(s, 80, format, p); 
    printf("Time: %s\n", s); 
    return 0;}




int add_num(int n, ...)
{
    int res = 0;
    va_list list;
    va_start(list, n); // инициализируем list последним заданным аргументом
    while (n)
    {
        res += va_arg(list, int);
        --n;
    }
    va_end(list); // завершение продвижения по аргументам
    return res;
}
