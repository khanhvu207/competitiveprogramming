/*
    Vector
    Number transform

    New:
    print P before type
    transform_1: D
    transform_2: W
    transform_3: L

    **How to run this code correctly:
    - Erase everything that use dummy[] (not necessary)
    or
    - Make allow_dummy = 0
*/
const bool allow_dummy = 0;

#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <utility>
#include <assert.h>
#include <iostream>
int n;
std::vector <char> output_mapping = {'-', 'D', 'W', 'L'};
std::map <int, int> prime_list[2];
std::vector<std::pair<int,int> > ans;

// testing purposes only
int dummy[2] = {1,1};
void update_dummy(int type,int val = -1,int id = -1){
    // check allow_dummy

    if (!allow_dummy)
        return;

    /*  type:
        - 0: constructing from input purposes
        - 1, 2, 3: transform type
    */
    switch(type){
        case 0:{
            dummy[id] *= val;
            return;
            break;
        }
        case 1:{
            dummy[1] *= val;
            break;
        }
        case 2:{
            dummy[0] *= val;
            dummy[1] /= (val * val);
            break;
        }
        case 3:{
            dummy[0] /= (val * val);
            break;
        }
        default: {
            assert(0 && "Doan xem");
        }
    }

    std::cerr << dummy[0] << ' ' << dummy[1] << std::endl;
    return;
}

void transform_1(int val) {
    prime_list[1][val] ++;

    ans.push_back({1, val});

    // testing
    update_dummy(1, val);
}
void transform_2(int val) {
    assert(prime_list[1][val] >= 2);

    prime_list[0][val] ++;
    prime_list[1][val] -= 2;

    ans.push_back({2, val});

    // testing
    update_dummy(2, val);
}
void transform_3(int val) {
    assert(prime_list[0][val] >= 2);

    prime_list[0][val] -= 2;

    ans.push_back({3, val});

    // testing
    update_dummy(3, val);
}
int main() {
    for(int type=0; type<2; type++) {
        // read n, m
        scanf("%d",&n);

        for(int i=0; i<n; i++) {
            // read array
            int x;
            scanf("%d",&x);

            // testing zone
                update_dummy(0, x, type);   // 0, val, id
            // end of testing zone

            // factorize x
            for(int j=2; j<=(int)sqrt(x); j++) {
                while(x % j == 0) {
                    prime_list[type][j] ++;
                    x /= j;
                }
            }
            if (x > 1)
                prime_list[type][x] ++;
        }
    }

    // step 1: clear B
    for(auto v: prime_list[1]){
        int prime = v.first;
        int no = v.second;
        while(no >= 2){
            transform_2(prime);
            no -= 2;
        }
        if (no == 1){
            transform_1(prime);
            transform_2(prime);
        }
    }

    // step 2: clear A
    for(auto v: prime_list[0]){
        int prime = v.first;
        int no = v.second;
        while(no >= 2){
            transform_3(prime);
            no -= 2;
        }
        if (no == 1){
            transform_1(prime);
            transform_1(prime);
            transform_2(prime);
            transform_3(prime);
        }
    }

    // output
    printf("%d\n",ans.size());
    for(auto v: ans){
        printf("%d %c\n", v.second, output_mapping[v.first]);
    }
}

