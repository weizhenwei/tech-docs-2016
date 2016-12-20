#include <stdio.h>

#include <vector>

void print_array(std::vector<int>& array) {
    std::vector<int>::iterator iter;
    for (iter = array.begin(); iter != array.end(); iter++) {
        printf("%d\n", *iter);
    }

}

// 1 2 3 4 5 6 7 8 9 10 ; idx = 0; => 2 3 4 5 6 7 8 9 10; idx = 1; 
// 2 3 4 5 6 7 8 9 10;    idx = 1; => 2 4 5 6 7 8 9 10;   idx = 2;
// 2 4 5 6 7 8 9 10;      idx = 2; => 2 4 6 7 8 9 10;     idx = 3;
// 2 4 6 7 8 9 10;        idx = 3; => 2 4 6 8 9 10;       idx = 4;
// 2 4 6 8 9 10;          idx = 4; => 2 4 6 8 10;         idx = 5;
// done;
std::vector<int>& delete_odd(std::vector<int>& array) {
    int total = array.size();
    std::vector<int>::iterator iter_begin;
    int idx = 0;
    while (idx < total / 2) {
        iter_begin = array.begin();
        array.erase(iter_begin + idx);

        idx++;
    }

    // odd situation;
    if (total % 2 == 1) {
        array.erase(array.begin() + idx);
    }

    return array;
}


int main() {
    std::vector<int> vArray;

    // case 1;
    printf("\n");
    vArray.clear();
    for (int i = 1; i <= 99; i++) {
        vArray.push_back(i);
    }
    vArray = delete_odd(vArray);
    print_array(vArray);

    // case 2;
    printf("\n");
    vArray.clear();
    for (int i = 1; i <= 100; i++) {
        vArray.push_back(i);
    }
    vArray = delete_odd(vArray);
    print_array(vArray);

    // case 3;
    printf("\n");
    vArray.clear();
    vArray = delete_odd(vArray);
    print_array(vArray);

    // case 4;
    printf("\n");
    vArray.clear();
    vArray.push_back(1);
    vArray = delete_odd(vArray);
    print_array(vArray);

    // case 5;
    printf("\n");
    vArray.clear();
    vArray.push_back(1);
    vArray.push_back(2);
    vArray = delete_odd(vArray);
    print_array(vArray);

    return 0;
}

