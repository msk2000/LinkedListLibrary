#include <iostream>
#include <string>

class LinkedList
{
    private:
    // This struct represents a single element/node in the list
    struct listElement
    {
        // sample data
        int dataInt;
        std::string dataName;
        //Pointer to the next element of the same type (the link!)
        listElement* next;

        // Constructor for listElement
        listElement(int id, std::string name, listElement* nxt = nullptr)
            : dataInt(id), dataName(name), next(nxt) {}

    };

    // Pointer to the first element in the list
    listElement* head;
    

    public:
    //Constructor: This is to construct the class NOT the LL
    LinkedList() : head(nullptr){}

    //Destructor: This is what ensures all the nodes are hunted down and deleted
    ~LinkedList()
    {
        deleteList(); 
    }


    // Getter and Setter functions for the "next"
    listElement* getNext(listElement* element)
    {
        return element->next;
    }

    void setNext(listElement* element, listElement* nextElement)
    {
        element->next = nextElement;
    }

    int getDataInt(listElement* element)
    {
        return element->dataInt;
    }

    std::string getDataName(listElement* element)
    {
        return element->dataName;
    }

    // General functions \\

    // Function to add an element to the list
    int addElement(int targetIndex, int intID, std::string stringData)
    {
        listElement* tempElement = new listElement(intID, stringData);

        // Condition 1: For empty list, link the start address of list to newly allocated element
        if (head == nullptr)
        {
            head = tempElement;
        }

        //Condition 2: If inserting to head (index = 0)
        else if (targetIndex == 0)
        {
            tempElement->next = head; // The newly inserted element points to the current head
            head = tempElement;       // Updates the head to the newly inserted node at index 0
        }

        //Condition 3: If we insert to the tail (index = -1)
        else if(targetIndex == -1)
        {
            // We start from the head address
            listElement* currentElement = head;
            // traverse to end of list
            while(currentElement->next != nullptr)
            {
                currentElement = currentElement->next;
            }
            // while loop stops when next points to null in the current element
            // Then we link the old last element to the new last element
            currentElement->next = tempElement;

        }

        //Condition 4: Every other type of insertion
        else
        {
            listElement* currentElement = head;

            for(int i = 0; i <targetIndex-1; i++) // Move to element right before the target
            {
                //First check if we are going out of bound
                if(currentElement->next == nullptr) // signifying we arrived at the end of list
                {
                    std::cerr <<"ERROR: Index is out of range, element not added!"<<std::endl;
                    delete tempElement;
                    return 1;
                }
                else
                {
                    currentElement = currentElement->next;
                }
            }
            // If we get to this position, wer are right before the target index
            // We make the original element at the target index the next element
            tempElement->next = currentElement-> next;
            // The element before target position now should link to the newly added element
            currentElement->next = tempElement;
        }

        return 0; //Yay success!

    }

    //Function to remove an element from the lsit
    int removeElement(int targetIndex)
    {
        listElement* currentElement = head;

        // Checking first if the list has anything in it
        if(head == nullptr)
        {
            std::cout << "The list is empty! Cannot remove elements from an empty list!" <<std::endl;
            return 1;
        }
        // Condition: Removing from the head
        else if (targetIndex == 0)
        {
            listElement* targetElement; // For the subsequent manipulation

            targetElement = currentElement; // the element we want to delete is assigned to targetelement
            currentElement = currentElement->next; // move pointer to the next element
            head = currentElement; // Reassign the head to the new element
            targetElement->next = nullptr; // break the connection of the target to be removed from the rest of the list

            std::cout<<"Removing Element ID " << targetElement->dataInt<<" from index " <<targetIndex<<std::endl;

            delete targetElement; // get rid of it

        }
        // Condition: Removing from the tail
        else if (targetIndex == -1)
        {
            // Special case where there is only one item in the list
            if(head->next == nullptr)
            {
                std::cout << "Removing Element ID " << head->dataInt << " from index " << targetIndex << std::endl;
                delete head; //remove the only element
                head = nullptr; //set head to null to indicate empty list
                return 0;
            }

            //Otherwise: If there are more than one item in the list

            listElement* tempElement;   // Used to store the last element details after the loop ends

            while(currentElement->next != nullptr)
            {
                tempElement = currentElement; // keeping a record of the most recently processed element
                currentElement = currentElement->next; // Using the link to move to the next element per iteration
            }

            tempElement->next = nullptr; // since the last node to point to nullptr to indicate end of list

            std::cout<<"Removing Element ID " << currentElement->dataInt<<" from index " <<targetIndex<<std::endl;

            delete currentElement;
        }
        // Condition: Any other index 
        else
        {
            listElement* tempElement;

            for (int i = 0; i < targetIndex; i++) //traverses the linked list until it reaches the targetIndex position
            {
                if (currentElement->next == nullptr)
                {
                    std::cerr<<"Cannot remove element as index is out of bound!"<<std::endl;
                    return 2;
                }
                tempElement = currentElement;// tempElement stores the previous node 
                currentElement = currentElement->next; // currentElement moves to the next node
            }
            tempElement->next = currentElement->next;//tempElement (previous node) has its next pointer updated to skip the currentElement (target node). 

            std::cout<<"Removing Element ID "<<currentElement->dataInt << " from index "<<targetIndex<<std::endl;

            delete currentElement;

            
        }


    return 0;
    }
    // Function to delete the list elements
    int deleteList()
    {
        //Sanity check
        if(head == nullptr)
        {
            std::cout <<"!!!!! The list is empty, nothing to delete!!"<<std::endl;
            return 1;
        }
        else
        {
            listElement* currentElement = head; // starting from first element position

            while(currentElement != nullptr)
            {
                listElement* nextElement = currentElement->next; // get position of next item
                delete currentElement; // Now we can remove the current one
                currentElement = nextElement;   // move to the next one 
            }

            // reset the head to nullptr after deletion
            head = nullptr;
            
        }
        std::cout << "****** LIST DELETED ******"<<std::endl;

        return 0;
    }

    // Print function
    void printList()
    {
        listElement* currentElement = head;

        if(currentElement == nullptr) // empty lsit
        {
            std::cout << "!! CANNOT PRINT!! List is Empty!" <<std::endl;
            return;
        }
        else
        {
            std::cout << "================= LIST CONTENTS ================="<<std::endl;
            while(currentElement->next != nullptr) // until we reach the end
            {
                std::cout<< "Element ID "<<currentElement->dataInt<<": "<<currentElement->dataName<<std::endl;
                currentElement = currentElement->next; // move to next item
            }

            // Once out of the loop, we will arrive at the last element
            std::cout<< "Element ID "<<currentElement->dataInt<<": "<<currentElement->dataName<<std::endl;
            std::cout<<"=========== End of List ==========" <<std::endl;


        }
    }

};


// TESTING MAIN
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

    std::cout << "List after re-adding elements:" << std::endl;
    myList.printList();

    

    return 0;
}