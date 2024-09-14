# Linked List Library (C++)

This is an **unfinished** Linked List library implemented in C++. It is designed for educational purposes and currently features basic operations such as adding, removing, searching, and printing elements in the list. The library uses an internal struct to represent each node (element) and provides functionality for managing the linked list.

## Features

- **Add elements** to the list by index, head, or tail.
- **Remove elements** from the list by index, head, or tail.
- **Print elements** of the list in order.
- **Search by index** or **search by data** to find specific elements.
- **Automatic memory management** with destructors that clean up all elements when the list is deleted.

## Available Functions

1. `addElement(index, value, data)` – Add a new element to the list at the specified index, head (index 0), or tail (index -1).
2. `removeElement(index)` – Remove an element from the specified index, head (index 0), or tail (index -1).
3. `findData(value)` – Find the first occurrence of an element by its value.
4. `findIndex(index)` – Find an element at the specified index.
5. `printList()` – Print all elements in the list.
6. Destructor – Automatically deletes all elements in the list when the list object is destroyed.

## Code Demo

Here is an example of how to use **every function** available in the library:

```cpp
int main()
{
    // Create a LinkedList object
    LinkedList myList;

    // Add elements to the list
    std::cout << "Adding elements:" << std::endl;
    myList.addElement(0, 1, "First Element");       // Add to head (index 0)
    myList.addElement(-1, 2, "Second Element");     // Add to tail (index -1)
    myList.addElement(1, 3, "Third Element");       // Add to index 1
    myList.addElement(3, 4, "Fourth Element");      // Add to index 3 (end)
    myList.addElement(2, 5, "Fifth Element");       // Add to index 2
    myList.addElement(0, 6, "New Head");            // Add to new head (index 0)
    myList.addElement(10, 7, "New Tail");            // Add to out of range index

    // Print the list contents
    std::cout << "List after adding elements:" << std::endl;
    myList.printList();

    // Remove elements from different positions
    std::cout << "Removing elements:" << std::endl;
    myList.removeElement(0); // Remove head
    myList.removeElement(5); // Remove tail
    myList.removeElement(2); // Remove element from middle
    myList.removeElement(0); // Remove new head (after previous removals)

    // Print the list contents
    std::cout << "List after some removals:" << std::endl;
    myList.printList();

    // Attempt to remove from an empty list (should handle gracefully)
    std::cout << "Attempting to remove from an empty list:" << std::endl;
    myList.deleteList(); // Ensure list is empty
    myList.removeElement(0); // Attempt to remove from empty list

    // Add and remove elements again to test consistency
    myList.addElement(0, 8, "New Element After Empty"); // Add to head
    myList.addElement(-1, 9, "Another Element");       // Add to tail
    myList.addElement(1, 10, "Middle Element");        // Add to middle

    myList.indexSearch(2);                              // Search for an existing index
    myList.indexSearch(-4);                             // SEarch for an invalid negative index
    myList.indexSearch(4);                              // Search for an out of bound index

    myList.findData(8);                                 // Search for data by ID for existing ID
    myList.findData(20);                                // SEarch for data by ID for non-existing ID
    

    std::cout << "List after re-adding elements:" << std::endl;
    myList.printList();
}
```
## Future Work

This project is a **work in progress**. Planned updates include:

- Proper conversion of this code into a full library with:
- Separate header files (.h) and implementation files (.cpp)
- Cleaner interface and documentation
- Additional list functionalities, such as sorting, reversing, etc.

## Usage

To use this Linked List in your C++ project, simply include the class in your code and create an instance of `LinkedList`. The methods `addElement`, `removeElement`, `findData`, and `printList` allow basic list manipulation.

## Educational Purpose

This project is intended for **educational purposes only**. It demonstrates how a simple linked list can be implemented in C++ using basic object-oriented principles. The code has been structured to help others learn and understand how linked lists function internally.

Feel free to clone, modify, and explore the code as you wish!
