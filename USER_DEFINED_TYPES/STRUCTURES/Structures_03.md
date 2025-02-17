## Dinamik Bellek Yönetimi ile Yapı Nesnesi Kullanım Örneği

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Student {

    int no;
    char name[20];
    char surname[20];
    int grades[5];
    
};

struct Student* make_random_student(void)
{
    struct Student* p = (struct Student*)malloc(sizeof(*p));
    p->no = rand() % 1001;
    strcpy(p->name, "Hayati");
    strcpy(p->surname, "Kilic");
    for (int i = 0; i < 5; ++i) {
        p->grades[i] = rand() % 101;
    }
    
    return p;
}


int main() {
    
    srand(time(NULL));
    struct Student* ptr = make_random_student();
    
    
    
    printf("ptr->no        : %d\n", ptr->no);
    printf("ptr->name      : %s\n", ptr->name);
    printf("ptr->surname   : %s\n", ptr->surname);
    printf("ptr->grades[0] : %d\n", ptr->grades[0]);
    printf("ptr->grades[4] : %d\n", ptr->grades[4]);
    
    free(ptr);
   
}

/*
Çıktı :
*******
ptr->no        : 972
ptr->name      : Hayati
ptr->surname   : Kilic
ptr->grades[0] : 98
ptr->grades[4] : 30
*/

```


