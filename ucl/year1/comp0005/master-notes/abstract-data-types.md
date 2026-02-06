# array
- fixed number of items, indexable
- basic operations:
  - `set(index, element)`
  - `get(index)`

# list
- linear
  - stack
  - queue
  - set & multi-set
  - map
  - priority queue
- non-linear
  - tree
  - graph
- basic operations:
  - `append(item)`
  - `prepend(item)`
  - `head()`
  - `tail()`

# stack
- a list that places restrictions on where you can add/remove elements (last in, first out)
- basic operations:
  - `push(item)`
  - `pop()`
  - `isEmpty()`

# queue
- a list that also places restrictions on where you can add/remove (first-in, first-out)
- basic operations:
  - `enqueue(item)`
  - `dequeue()`

# set and multi set
- an ADT to store unindexed, unordered and unrepeated elements
- the bag (or multiset) is an ADT to store unindexed, unordered, possibly duplicated elements 
- basic operations:
  - `insert(item)`
  - `remove(item)`
  - `contains(item)`

# map
- the map (or dictionary, or associative array) is a list that can hold data in `(key, value)` pairs. Key are unique, and can only hold one value
- basic operations:
  - `insert(key, value)`
  - `remove(key)`
  - `update(key, value)`
  - `lookup(key)`

# priority queue
- the priority queue is a queue where items are inserted/removed based on a given priority
- basic operations:
  - `enqueue(item, priority)`
  - `dequeue()`

# ADTs vs data structures
- abstract data types (what):
  - way of classifying data structures based on behaviour they provide
  - point of view of a user
- data structures (how)
  - concrete representations of data
  - point of view of an implementer

| ADTs | common implementation | examples in Java |
| --- | --- | --- |
| array | `array` | `<type>[]` |
| list | `array`, `linked list` | `ArrayList`, `LinkedList` |
| queue | `array`, `linked list` | `LinkedList` |
| stack | `array`, `linked list` | `stack` |
| multi-set | `hash table` | `HashSet` |
| map/dictionary | `hash table` | `HashMap` | 
| priority queue | `heap` | `priority`/`queue` |

# adt implementation
- linear ADTs are commonly implemented in one of two ways:
  - array data structure
  - linked list data structure
- time complexity for the same ADT may vary substantially depending on its implementation

# adt implementation: array
- an array data structure used to store homogenous items in contiguous memory
- often used to implement arrays (ADT) and stacks
- resizing array to implement a StackADT
  - grow: if array is full, create a new array twice the size and copy items over
  - shrink: if array is one-quarter full, halve the size
  - property: array is between 25% and 100% full at any time

# adt implementation: linked list
- a linked list is a data structure used to maintain a dynamic collection of heterogenous items
- it is often used to implement Stacks and Queues ADTs
  - singly linked list
    - 
  - doubly linked list