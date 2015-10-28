#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 126
int counter[MAX];

int main(void)
{
    int t;
    char p;
    scanf("%d", &t);

    while(t--)
    {
        string str;

        do
        {
            getline(cin, str);
        }while(str.size() == 0 || (str.size() == 1 && (str[0] < 'A' || str[0] > 'Z')));

        int len = str.size();

        for(int i = 0; i < len; ++i)
            ++counter[str[i]];

        int max = 0;
        int index = 0;
        for(int i = 'A'; i <= 'Z'; ++i)
        {
            int ci = counter[i];
            if(ci > max)
            {
                max = ci;
                index = i;
            }
        }

        int check = 0;
        for(int i = 'A'; i <= 'Z'; ++i)
        {
            if(counter[i] == max)
            {
                ++check;
                if(check == 2)
                    break;
            }
        }

        if(check > 1)
            puts("NOT POSSIBLE");
        else
        {
            int dis = index - 'E';
            if(dis < 0)
                dis = 26 + dis;

            for(int i = 0; i < len; ++i)
            {
                char ci = str[i];
                if(ci <= ' ')
                    continue;

                char cir = ci - dis;
                if(cir < 'A')
                    cir += 26;

                str[i] = cir;
            }

            printf("%d %s\n", dis, str.c_str());
        }

        for(int i = 'A'; i <= 'Z'; ++i)
            counter[i] = 0;
    }

    return 0;
}
