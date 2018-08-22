//
// Created by wangh on 18-4-15.
//

#ifndef MYMALLOC_MYMALLOC_H
#define MYMALLOC_MYMALLOC_H
#define malloc(size) w_malloc(size,__FILE__,__FUNCTION__,__LINE__)
#define free(address) w_free(address)
#define MAX_FILE_NAME 1024
#define MAX_FUNC_NAME 1024
#define MAX_RECORD 1024

#include <stdio.h>
struct memory
{
    size_t  index;
    void*   address;
};

struct Mem_record{
    char FILE[MAX_FILE_NAME];
    char FUNC[MAX_FUNC_NAME];
    int use_flag;
    size_t lineno;
    void* address;
    size_t size;
};


void my_init();

/*********************************************************************************
 *
 * @param size
 * @return
 */
void *w_malloc(size_t size,char FILE[MAX_FILE_NAME],char FUNC[MAX_FUNC_NAME],size_t lineno);

/**********************************************************************************
 *
 * @param address
 */
void w_free(void *address);

/*********************************************************************************
 *
 */
void report();

#endif //MYMALLOC_MYMALLOC_H
