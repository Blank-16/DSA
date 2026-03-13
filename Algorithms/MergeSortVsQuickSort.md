1. Why Merge Sort fits Linked Lists well

Key reason: Splitting and merging linked lists is very easy and efficient.

Easy splitting

In a linked list you can find the middle using the slow/fast pointer technique, then just break the list into two halves by changing a pointer. No element shifting is needed.

Easy merging

Merging two sorted linked lists is extremely efficient:

You just reconnect pointers

No copying or moving of elements

Example idea:

List A: 1 → 4 → 7
List B: 2 → 3 → 6

You simply relink nodes:

1 → 2 → 3 → 4 → 6 → 7

No memory movement required.

Time complexity

Merge sort works by dividing the list repeatedly:

T(n) = 2T\left(\frac{n}{2}\right) + O(n)

This recurrence leads to O(n log n) consistently.

Important advantage for linked lists

No random access required

Only sequential traversal

Stable

Works in O(1) extra space (if done carefully)

2. Why Quick Sort fits Arrays better

Quick sort relies heavily on random access.

Partitioning needs fast indexing

Quick sort repeatedly partitions around a pivot.

Example array:

[8, 3, 1, 7, 0, 10, 2]

You constantly access elements like:

arr[i], arr[j], arr[pivot]

Arrays support this in O(1) time.

Linked lists do not.
To access the i-th element you must traverse from the head.

O(n) access time

This makes partitioning slow.

3. Swapping is cheap in arrays

Quick sort swaps elements frequently.

In arrays:

swap(arr[i], arr[j])

This is constant time.

In linked lists:

You must change multiple pointers

Often requires tracking previous nodes

Code becomes complicated and slower

4. Memory locality (huge practical factor)

Arrays store elements contiguously in memory.

This improves CPU cache performance, making quick sort extremely fast in practice.

Linked lists are scattered in memory, so quick sort loses efficiency.

5. Worst-case behavior

Quick sort worst case:

O(n²)

Merge sort:

O(n log n) guaranteed

Linked lists benefit from the predictable performance of merge sort.

Summary

Data Structure	Preferred Sort	Reason
Linked List	Merge Sort	Easy splitting and pointer-based merging
Array	Quick Sort	Fast random access and cheap swaps
Linked List + Quick Sort	Poor	No random access
Array + Merge Sort	Needs extra memory	

Interview shortcut explanation

Merge sort is preferred for linked lists because merging can be done by changing pointers without extra memory or shifting elements. Quick sort is preferred for arrays because partitioning and swapping require fast random access, which arrays provide but linked lists do not.
