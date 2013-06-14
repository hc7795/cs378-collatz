// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <map>
#include "Collatz.h"

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------
std::map<int, int> cache;
int collatz_eval (int i, int j) {
    using namespace std;
    assert(i > 0);
    assert(j > 0);
    // <your code>
    int v = 1;    
    if(i>j) {
    	int temp = i;
    	i = j;
    	j = temp;
    }
    while (i <= j) {
        int k = i;
        int cycleLen = 1;
        while (k != 1) {
            if (cache.count(k) == 0) {
                if (k%2 != 0) {
                    k = k * 3 +1;
                    cycleLen++;
                }
                k /= 2;
                cycleLen++;
            }
            else {
                cycleLen += ((cache.find(k) -> second)-1);
                break;
            }
            assert(k>0);
        }
        assert(cycleLen>0);
        cache[i] = cycleLen;
        if (cycleLen > v)
            v = cycleLen;
        i++;
    }
    assert(v > 0);
    return v;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
