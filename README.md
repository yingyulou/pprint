# pprint

## Introduction

Pretty print any common data, containers, container adapters, pairs, tuples and initializer_lists.

To use this module, simply include the ```pprint``` herader file:

``` Cpp
#include <pprint/pprint>
```

The only thing you need to do is call the function ```print``` like this:

``` Cpp
pprint::print(xxx /* , xxx, xxx, ... */);
```

Or import the namespace ```pprint``` then call the ```print```:

``` Cpp
using pprint::print;

print(xxx /* , xxx, xxx, ... */);
```

## Common Data

The ```Common Data``` are like: ```int```, ```double```, ```char```, ```string```, ```pointer```, ```bool```, ```enum```, etc:

``` Cpp
enum class COLOR { RED, GREEN, BLUE };

int sampleInt       = 123;
double sampleDouble = 123.;
char sampleChar     = 'a';
string sampleStr    = "abc";
int *samplePtr      = nullptr;
bool sampleBool     = false;
COLOR sampleEnum    = COLOR::RED;

print(sampleInt);     // 123
print(sampleDouble);  // 123
print(sampleChar);    // 'a'
print(sampleStr);     // "abc"
print(samplePtr);     // 0
print(sampleBool);    // false
print(sampleEnum);    // 5COLOR::0
```

## Sequence Container

The ```Sequence Container``` are: ```std::array```, ```std::deque```, ```std::forward_list```, ```std::list``` and ```std::vector``` of the STL:

``` Cpp
array<int, 3> sampleArray {1, 2, 3};
vector<string> sampleVector {"abc", "def", "ghi"};
list<deque<forward_list<string>>> sampleComplexContainer {{{"abc", "def"}, {"ghi", "jkl"}}, {{"mno", "pqr"}, {"stu", "vwx"}}};

print(sampleArray);   // [1, 2, 3]
print(sampleVector);  // ["abc", "def", "ghi"]

/*
[
    [
        ["abc", "def"],
        ["ghi", "jkl"],
    ],
    [
        ["mno", "pqr"],
        ["stu", "vwx"],
    ],
]
*/
print(sampleComplexContainer);
```

## Map Container

The ```Map Container``` are: ```std::map```, ```std::multimap```, ```std::unordered_map``` and ```std::unordered_multimap``` of the STL:

``` Cpp
map<int, string> sampleMap {{1, "abc"}, {2, "def"}, {3, "ghi"}};
multimap<int, vector<string>> sampleComplexMap {{1, {"abc", "def"}}, {2, {"ghi", "jkl"}}, {3, {"mno", "pqu"}}};

/*
{
    (1: "abc"),
    (2: "def"),
    (3: "ghi"),
}
*/
print(sampleMap);

/*
{
    (
        1:
        ["abc", "def"],
    ),
    (
        2:
        ["ghi", "jkl"],
    ),
    (
        3:
        ["mno", "pqu"],
    ),
}
*/
print(sampleComplexMap);
```

## Set Container

The ```Set Container``` are: ```std::set```, ```std::multiset```, ```std::unordered_set``` and ```std::unordered_multiset``` of the STL:

``` Cpp
set<int> sampleSet {1, 2, 3};
multiset<vector<bool>> sampleComplexSet {{true, false}, {false, true}, {true, false, false, true}};

print(sampleSet);  // {1, 2, 3}

/*
{
    [false, true],
    [true, false],
    [true, false, false, true],
}
*/
print(sampleComplexSet);
```

## Pair

The ```Pair``` is: ```std::pair``` of the STL:

``` Cpp
pair<int, string> samplePair {1, "abc"};
pair<int, vector<string>> sampleComplexPair {1, {"abc", "def", "ghi"}};

print(samplePair);  // (1, "abc")

/*
(
    1,
    ["abc", "def", "ghi"],
)
*/
print(sampleComplexPair);
```

## Tuple

The ```Tuple``` is: ```std::tuple``` of the STL:

``` Cpp
tuple<int, double, char, string> sampleTuple {1, 2., 'a', "abc"};
tuple<int, double, char, string, vector<string>> sampleComplexTuple {1, 2., 'a', "abc", {"abc", "def", "ghi"}};

print(sampleTuple);  // (1, 2, 'a', "abc")

/*
(
    1,
    2,
    'a',
    "abc",
    ["abc", "def", "ghi"],
)
*/
print(sampleComplexTuple);
```

## Stack

The ```Stack``` is: ```std::stack``` of the STL:

``` Cpp
stack<int> sampleStack;

sampleStack.push(1);
sampleStack.push(2);
sampleStack.push(3);

stack<vector<string>> sampleComplexStack;

sampleComplexStack.push({"abc", "def"});
sampleComplexStack.push({"ghi", "jkl"});
sampleComplexStack.push({"mno", "pqr"});

/*
Bottom --------> Top
       [1, 2, 3]
*/
print(sampleStack);

/*
                     Bottom
[                      |
    ["abc", "def"],    |
    ["ghi", "jkl"],    |
    ["mno", "pqr"],    |
]                      v
                      Top
*/
print(sampleComplexStack);
```

## Queue

The ```Queue``` are: ```std::queue``` and ```std::priority_queue``` of the STL:

``` Cpp
queue<int> sampleQueue;

sampleQueue.push(1);
sampleQueue.push(2);
sampleQueue.push(3);

priority_queue<vector<string>> sampleComplexPriorityQueue;

sampleComplexPriorityQueue.push({"abc", "def"});
sampleComplexPriorityQueue.push({"ghi", "jkl"});
sampleComplexPriorityQueue.push({"mno", "pqr"});

/*
Front <-------- Back
      [1, 2, 3]
*/
print(sampleQueue);

/*
                     Front
[                      ^
    ["mno", "pqr"],    |
    ["ghi", "jkl"],    |
    ["abc", "def"],    |
]                      |
                      Back
*/
print(sampleComplexPriorityQueue);
```

## Initializer List

The ```Initializer List``` is: ```std::initializer_list``` of the STL:

``` Cpp
print({1, 2, 3});  // {1, 2, 3}

/*
{
    [1, 2, 3],
    [4, 5, 6],
}
*/
print({list<int>{1, 2, 3}, list<int>{4, 5, 6}});
```
