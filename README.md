# pprint

## Introduction

Pretty print any common data, containers, container adapters, pairs and tuples.

To use this module, simply include the ```pprint``` herader file:

``` Cpp
#include <pprint/pprint>
```

The only thing you need to do is call the function ```print``` like this:

``` Cpp
pprint::print(xxx);
```

Or import the namespace ```pprint``` then call the ```print```:

``` Cpp
using pprint::print;

print(xxx);
```

## Common Data

The ```Common Data``` is like: ```int```, ```double```, ```string```, ```pointer```, etc:

``` Cpp
int sampleInt = 123;
double *samplePtr = nullptr;
string sampleStr = "abc";

print(sampleInt);  // 123
print(samplePtr);  // 0
print(sampleStr);  // abc
```

## Sequence Container

The ```Sequence Container``` is: ```array```, ```deque```, ```forward_list```, ```list``` and ```vector``` of the STL:

``` Cpp
array<int, 3> sampleArray {1, 2, 3};
vector<string> sampleVector {"abc", "def", "ghi"};
list<deque<forward_list<string>>> sampleComplexContanier {{{"abc", "def"}, {"ghi", "jkl"}}, {{"mno", "pqr"}, {"stu", "vwx"}}};

print(sampleArray);   // [1, 2, 3]
print(sampleVector);  // [abc, def, ghi]

/*
[
    [
        [abc, def],
        [ghi, jkl],
    ],
    [
        [mno, pqr],
        [stu, vwx],
    ],
]
*/
print(sampleComplexContanier);
```

## Map Container

The ```Map Container``` is: ```map```, ```multimap```, ```unordered_map``` and ```unordered_multimap``` of the STL:

``` Cpp
map<int, string> sampleMap {{1, "abc"}, {2, "def"}, {3, "ghi"}};
multimap<int, vector<string>> sampleComplexMap {{1, {"abc", "def"}}, {2, {"ghi", "jkl"}}, {3, {"mno", "pqu"}}};

/*
{
    (1: abc),
    (2: def),
    (3: ghi),
}
*/
print(sampleMap);

/*
{
    (
        1:
        [abc, def],
    ),
    (
        2:
        [ghi, jkl],
    ),
    (
        3:
        [mno, pqu],
    ),
}
*/
print(sampleComplexMap);
```

## Set Container

The ```Set Container``` is: ```set```, ```multiset```, ```unordered_set``` and ```unordered_multiset``` of the STL:

``` Cpp
set<int> sampleSet {1, 2, 3};
multiset<vector<bool>> sampleComplexSet {{true, false}, {false, true}, {true, false, false, true}};

print(sampleSet);  // {1, 2, 3}

/*
{
    [0, 1],
    [1, 0],
    [1, 0, 0, 1],
}
*/
print(sampleComplexSet);
```

## Pair

The ```Pair``` is: ```pair``` of the STL:

``` Cpp
pair<int, string> samplePair {1, "abc"};
pair<int, vector<string>> sampleComplexPair {1, {"abc", "def", "ghi"}};

print(samplePair);  // (1, abc)

/*
(
    1,
    [abc, def, ghi],
)
*/
print(sampleComplexPair);
```

## Tuple

The ```Tuple``` is: ```tuple``` of the STL:

``` Cpp
tuple<int, double, char, string> sampleTuple {1, 2., 'a', "abc"};
tuple<int, double, char, string, vector<string>> sampleComplexTuple {1, 2., 'a', "abc", {"abc", "def", "ghi"}};

print(sampleTuple);  // (1, 2, a, abc)

/*
(
    1,
    2,
    a,
    abc,
    [abc, def, ghi],
)
*/
print(sampleComplexTuple);
```

## Stack

The ```Stack``` is: ```stack``` of the STL:

``` Cpp
stack<int> sampleStack;

sampleStack.push(1);
sampleStack.push(2);
sampleStack.push(3);

stack<vector<string>> sampleComplexStack;

sampleComplexStack.push({"abc", "def"});
sampleComplexStack.push({"ghi", "jkl"});
sampleComplexStack.push({"mno", "pqr"});

print(sampleStack);  // [3, 2, 1]

/*
[
    [mno, pqr],
    [ghi, jkl],
    [abc, def],
]
*/
print(sampleComplexStack);
```

## Queue

The ```Queue``` is: ```queue``` and ```priority_queue``` of the STL:

``` Cpp
queue<int> sampleQueue;

sampleQueue.push(1);
sampleQueue.push(2);
sampleQueue.push(3);

priority_queue<vector<string>> sampleComplexPriorityQueue;

sampleComplexPriorityQueue.push({"abc", "def"});
sampleComplexPriorityQueue.push({"ghi", "jkl"});
sampleComplexPriorityQueue.push({"mno", "pqr"});

print(sampleQueue);  // [1, 2, 3]

/*
[
    [mno, pqr],
    [ghi, jkl],
    [abc, def],
]
*/
print(sampleComplexPriorityQueue);
```
