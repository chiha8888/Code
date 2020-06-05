#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
int main() {
    set_t s;
    for ( int i=0; i<5; i++ ) s.insert(10*i);
    assert(*s.find_by_order(0) == 0);
    assert(*s.find_by_order(3) == 30);
    assert(s.find_by_order(5) == s.end());
    assert(s.order_of_key(0) == 0);
    assert(s.order_of_key(30) == 3);
    assert(s.order_of_key(35) == 4);
    assert(s.order_of_key(100) == 5);
    return 0;
}
