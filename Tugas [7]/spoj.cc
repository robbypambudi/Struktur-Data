/***********************************************************

* Program to create binary search tree with all words in *

* the text file and store the line numbers of each word *

* into corresponding nodes linked list. *

***********************************************************/

// Include the header files

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Define a structure for linked list to store the line numbers

struct positions

{

    // Data part of the node in linked list

    int pos;

    // Pointer of linked list

    struct positions *next;
};

// Define a structure for node in a tree to store the words

struct Tree_node

{

    // Data part of the node

    string word;

    // Linked list to store the line numbers

    struct positions *head;

    // Two pointers of the node

    struct Tree_node *left, *right;

} * root;

// Function to create a node in the tree

struct Tree_node *createNode(string word, int pos)

{

    // Create a new node temp of typre Tree_node

    struct Tree_node *temp = new Tree_node();

    // Create a new node tmp of type positions

    struct positions *tmp = new positions();

    // Given word is assigned to temp

    temp->word = word;

    // Set left pointer of temp as null

    temp->left = NULL;

    // Set the right pointer of temp as null

    temp->right = NULL;

    // Given position is assigned to tmp

    tmp->pos = pos;

    // Set next pointer of tmp as null

    tmp->next = NULL;

    // Assign tmp to head of temp node

    temp->head = tmp;

    // Return created node

    return temp;
}

// Function to check the word is present in the tree

bool checkNode(Tree_node *tree_node, string word)
{

    // If tree is empty

    if (tree_node == NULL)
    {

        // Return false since there is no node

        return false;
    }

    /* If the current node word is same as that of word to be searched */

    else if (word == tree_node->word)
    {

        /* Return true since tree contain the searched node */

        return true;
    }

    /* If the word to be searched is less than current node word*/

    else if (word < tree_node->word)
    {

        /* Call the recursive function checkNode() with left sub tree as parameter */

        return checkNode(tree_node->left, word);
    }

    /* If the word to be searched is equal or greater than current node word */

    else
    {

        /* Call the recursive function checkNode() with right sub tree as parameter */

        return checkNode(tree_node->right, word);
    }
}

// Function to add the line number to linked list

void addList(struct positions *head, int pos)

{

    // Create a new node temp of type positions

    struct positions *temp = new positions();

    // Assign position to temp

    temp->pos = pos;

    // Set next pointer of temp as null

    temp->next = NULL;

    // Declare a pointer and assign head to it

    struct positions *p = head;

    // Loop until the last node

    while (p->next != NULL)

    {

        // Assign next node to p

        p = p->next;
    }

    // Assign temp to next of p

    p->next = temp;
}

/* Function to find the node of which line number has to be added */

void addPosition(string word, int pos)

{

    // Declare a pointer p and assign root to it

    struct Tree_node *p = root;

    // Loop until all the nodes are traversed

    while (p)

    {

        /* If current node word is same as that of given word */

        if (p->word == word)
        {

            /* Call the recursive function addList() with head of current node as parameter */

            addList(p->head, pos);

            // Return from the function

            break;
            ;
        }
        else if (word < p->word)

            // Assign left child of p to p

            p = p->left;

        /* If word to be searched is greater than current node */

        else

            // Assign right child of p to p

            p = p->right;
    }
}

// Function to insert node in the tree

struct Tree_node *insertTree(struct Tree_node *node, string word, int pos)

{

    // Declare variable

    bool found;

    // Check given word is there in the tree

    found = checkNode(root, word);

    // If word is present the tree

    if (found == true)

    {

        /* Call function addPosition() to add the line number to list */

        addPosition(word, pos);

        // Return the node

        return node;
    }

    // If word is not present in the tree

    else

    {

        /* Create a new node temp with given word and position */

        struct Tree_node *temp = createNode(word, pos);

        // If tree is empty assign new node to it

        if (node == NULL)

        {

            // Assign temp to node

            node = temp;

            // Return node

            return node;
        }

        // If word is less than current node word

        if (word < node->word)

        {

            /* Call recursive function insertTree() with left sub tree as parameter */

            node->left = insertTree(node->left, word, pos);
        }

        // If word is greater than current node word

        else

            /* Call recursive function insertTree() with right sub tree as parameter */

            node->right = insertTree(node->right, word, pos);

        // Return the node

        return node;
    }
}

// Function to display nodes in the tree in in-order

void inorderTraversal(Tree_node *tree_node)

{

    // If tree is empty

    if (tree_node == NULL)

        // Return

        return;

    // Traverse the left sub tree of node

    inorderTraversal(tree_node->left);
    // Output the word in the node

    cout << tree_node->word << " ";

    // Decalre a pointer p and assign head of node to it

    struct positions *p = tree_node->head;

    // cout << "The line numbers in which this word occurs" << endl;

    // Loop all the nodes in linked list

    while (p)

    {

        // Display the line numbers

        cout << p->pos << " ";

        // Assign next node of p to p

        p = p->next;
    }

    // Print next line character

    cout << endl;

    // Traverse the right sub tree of the node

    inorderTraversal(tree_node->right);
}

// Function to read file and insert each word into the tree

void readFile()

{

    // Declare variables

    string name;

    ifstream infile;

    string fin1;

    // Declare variables

    int i = 1;

    string line;

    // Open the input file

    infile.open("input.txt");

    /* Until the file is empty read each line and extract the name of the software and version then assign it to the name*/

    while (getline(infile, line))

    {

        // Assign each line to string stream

        istringstream iss(line);

        // Loop until all the words are read

        while ((iss >> fin1))

        {

            // Insert each word into the tree

            root = insertTree(root, fin1, i);
        }

        // Increment line number index

        i++;
    }
}

// Main function

int main()

{

    // Call function readFile()

    readFile();

    // Call function inorderTraversal()

    inorderTraversal(root);

    // Pause the output console

    system("pause");

    // Return 0

    return 0;
}