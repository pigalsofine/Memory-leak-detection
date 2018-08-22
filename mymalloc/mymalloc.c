//
// Created by wangh on 18-4-15.
//

#include <zconf.h>
#include <string.h>
#include <printf.h>
#include <stdlib.h>
#include "mymalloc.h"

#ifdef malloc
#undef malloc
#endif
#ifdef free
#undef free
#endif

struct Mem_record mem_record[MAX_RECORD];
size_t my_index;

void my_init(){
    atexit( report );
}

void *w_malloc(size_t size,char FILE[MAX_FILE_NAME],char FUNC[MAX_FUNC_NAME],size_t lineno){
    struct memory *mem;
    mem = (struct memory *)malloc(size+sizeof(size_t));
    mem_record[my_index].address = mem->address;
    mem_record[my_index].size = size;
    mem_record[my_index].lineno = lineno;
    mem_record[my_index].use_flag = 1;
    strncpy(mem_record[my_index].FILE,FILE,MAX_FILE_NAME-1);
    strncpy(mem_record[my_index].FUNC,FUNC,MAX_FUNC_NAME-1);
    mem->index = my_index;
    mem->address = &mem->address;
    my_index++;
    printf("a\n");
    return mem->address;
}

void w_free(void *address){
    struct memory *mem = (struct memory *)(address- sizeof(size_t));
    mem_record[mem->index].use_flag = 0;
    printf("free\n");
    free(mem);
}


void report(){
    for (int i = 0; i < my_index; ++i) {
        if (mem_record[i].use_flag!=0){
            printf("FILE: %s, FUNCTION: %s, LINE: %u, ADDRESS: 0x%p, SIZE: %u ",
                mem_record[i].FILE,mem_record[i].FUNC,mem_record[i].lineno,
                   mem_record[i].address,mem_record[i].size
            );
        }
    }
}
