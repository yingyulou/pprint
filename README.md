# pprint

## Introduction

Pretty print any data, containers, pairs and tuples.

To use this module, simply include the `pprint` herader file:

```cpp
#include <pprint/pprint>
```

The only thing you need to do is call the function `print` like this:

```cpp
pprint::print(xxx /* , xxx, xxx, ... */);
```

Or using the namespace `pprint` then call the `print`:

```cpp
using pprint::print;

print(xxx /* , xxx, xxx, ... */);
```

## Common Data

Common data, include: `int`, `double`, `char`, `string`, `pointer`, `bool`, `enum` and etc can be print:

```cpp
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
print(sampleEnum);    // COLOR::0
```

## Sequence Container

Sequence container, include: `std::array`, `std::vector`, `std::list`, `std::forward_list`, and `std::deque` can be print:

```cpp
array<int, 3> sampleArray {1, 2, 3};
vector<string> sampleVector {"abc", "def", "ghi"};
list<forward_list<deque<string>>> sampleComplexContainer {{{"abc", "def"}, {"ghi", "jkl"}}, {{"mno", "pqr"}, {"stu", "vwx"}}};

print(sampleArray);   // (1, 2, 3)
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

Map container, include: `std::map`, `std::multimap`, `std::unordered_map` and `std::unordered_multimap` can ba print:

```cpp
unordered_map<int, string> sampleMap {{1, "abc"}, {2, "def"}, {3, "ghi"}};
unordered_multimap<int, string> sampleMultiMap {{1, "abc"}, {2, "def"}, {3, "ghi"}};
map<int, multimap<int, int>> sampleComplexMap {{1, {{2, 2}, {3, 3}}}, {4, {{5, 5}, {6, 6}}}, {7, {{8, 8}, {9, 9}}}};

/*
{
    (3, "ghi"),
    (2, "def"),
    (1, "abc"),
}
*/
print(sampleMap);

/*
{
    (3, "ghi"),
    (2, "def"),
    (1, "abc"),
}
*/
print(sampleMultiMap);

/*
{
    (
        1,
        {
            (2, 2),
            (3, 3),
        },
    ),
    (
        4,
        {
            (5, 5),
            (6, 6),
        },
    ),
    (
        7,
        {
            (8, 8),
            (9, 9),
        },
    ),
}
*/
print(sampleComplexMap);
```

## Set Container

Set container, include: `std::set`, `std::multiset`, `std::unordered_set`, and `std::unordered_multiset` can be print:

```cpp
unordered_set<int> sampleSet {1, 2, 3};
unordered_multiset<int> sampleMultiSet {1, 2, 3};
set<multiset<bool>> sampleComplexSet {{true, false}, {false, true}, {true, false, false, true}};

print(sampleSet);       // {3, 2, 1}
print(sampleMultiSet);  // {3, 2, 1}

/*
{
    {false, false, true, true},
    {false, true},
}
*/
print(sampleComplexSet);
```

## Pair

`std::pair` can be print:

```cpp
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

`std::tuple` can be print:

```cpp
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

`std::stack` can be print:

```cpp
stack<int> sampleStack;

sampleStack.push(1);
sampleStack.push(2);
sampleStack.push(3);

stack<vector<string>> sampleComplexStack;

sampleComplexStack.push({"abc", "def"});
sampleComplexStack.push({"ghi", "jkl"});
sampleComplexStack.push({"mno", "pqr"});

/*
       [1, 2, 3]
Bottom --------> Top
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

`std::queue` and `std::priority_queue` can be print:

```cpp
queue<int> sampleQueue;

sampleQueue.push(1);
sampleQueue.push(2);
sampleQueue.push(3);

priority_queue<vector<string>> sampleComplexPriorityQueue;

sampleComplexPriorityQueue.push({"abc", "def"});
sampleComplexPriorityQueue.push({"ghi", "jkl"});
sampleComplexPriorityQueue.push({"mno", "pqr"});

/*
      [1, 2, 3]
Front <-------- Back
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

## Other

Any other type which defined `cout << ...` operator can be print:

```cpp
print(complex(1, 2), filesystem::path("6"));  // (1,2) "6"

struct Coord { double x; double y; };

ostream &operator<<(ostream &os, const Coord &coordObj)
{
    return os << '(' << coordObj.x << ", " << coordObj.y << ")\n";
}

print(Coord {2, 3});  // (2, 3)
```

Otherwise, print will use the default format: `<Typename, Pointer>`:

```cpp
// <std::integer_sequence<unsigned long long, 0ull, 1ull, 2ull>, 0x...>
print(index_sequence_for<int, double, string>());

struct Coord { double x; double y; };

print(Coord {2, 3});  // <Coord, 0x...>
```

