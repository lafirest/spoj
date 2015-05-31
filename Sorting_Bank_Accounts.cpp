// 因为map是有序的,所以这里用map计数后,直接输出即可
// 需要注意的是cin使用的是格式符,会丢弃换行,如果不加
// cin.get(),则换行会被getline()读取到,读取空行使用getline()
#include<iostream>
#include<string>
#include<map>
using namespace std;

typedef map<string, int> counter_map;

int
main(void)
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int num = 0;
        cin >> num;
        cin.get();
        counter_map counter;
        string accounts;
        while (num--)
        {
            getline(cin, accounts);
            ++counter[accounts];
        }
        counter_map::iterator it;
        for(it = counter.begin(); it != counter.end(); ++it)
            cout << it->first << " " << it->second << endl;
        cout << endl;
        getline(cin, accounts);
    }
    return 0;
}
