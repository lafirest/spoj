// 3次SIGSEGV，因为arr大小不够,一次compilation error因为arr太大了
// 2次WA,因为data的类型用了char，所以以后编译时记得用-Wall，把警告都消除了
#include <stdio.h>
#include <memory.h>

struct node
{
    int data[10];           // 保存后继节点的位置
    unsigned char has;      // 从头节点到这儿是否构成了一个phone number
};

struct node arr[30000000];
int alloc = 1;              // 下一个分配的节点位置

int search (int pos, char* str)
{
    unsigned char value = 0, i;
    while(*str && pos < alloc)
    {
        value = *str - 48;

        // 如果当前这个节点已经构成了一个phone number，则冲突了
        if(arr[pos].has)
            return 0;
        // 如果当前这个value有后继节点,则转到后继节点
        else if(arr[pos].data[value])
            pos = arr[pos].data[value];
        else
        {
            // 如果没有,则为这个value分配一个节点
            arr[pos].data[value] = alloc;
            pos = alloc;

            // 节点初始化(因为这个节点之前可能就被用过了)
            memset(&arr[alloc], 0, sizeof(struct node));
            ++alloc;
        }
        ++str;
    }

    // 字符串处理完毕后,设置当前节点构成了一个phone number
    arr[pos].has = 1;

    // 字符串处理完毕后,判断当前节点是否有后继节点,如果有的话,
    // 说明当前字符串和之前的某个长字符串拥有共同前缀
    for(i = 0; i < 10; ++i)
        if(arr[pos].data[i])
            return 0;

    return 1;
}

int main(void)
{
    char buffer[11] = "";
    int n,t,searchp;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &t);
        searchp = 1;

        // 重置起始分配的节点和初始化根节点
        alloc = 1;
        memset(&arr[0], 0, sizeof(struct node));

        while(t--)
        {
            scanf("%s", buffer);
            if(searchp)
                searchp = search(0, buffer);
        }

        if(searchp)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
