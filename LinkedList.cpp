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

    // Add some elements to the list
    myList.addElement(0, 1, "First Element");
    myList.addElement(-1, 2, "Second Element"); // Add to the end of the list
    myList.addElement(1, 3, "Third Element"); // Add to index 1

    // Print the list contents
    std::cout << "List after adding elements:" << std::endl;
    myList.printList();

    // Delete the list and verify deletion
    myList.deleteList();
    
    // Try to print the list after deletion
    std::cout << "List after deletion:" << std::endl;
    myList.printList();

    return 0;
}