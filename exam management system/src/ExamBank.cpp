#include "ExamBank.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

ExamBank::ExamBank() : courseCount(0) {
    loadOOPExam();
    loadDSAExam();
    loadOSExam();
}

int ExamBank::getCourseCount() const { return courseCount; }
const Exam& ExamBank::getCourse(int index) const { return courses[index]; }

void ExamBank::displayCourseMenu() const {
    cout << "\n  +---------------------------------------+\n";
    cout << "  |         AVAILABLE COURSES             |\n";
    cout << "  +---------------------------------------+\n";
    for (int i = 0; i < courseCount; i++) {
        cout << "  |  [" << (i + 1) << "]  "
             << left << setw(32) << courses[i].getCourseName() << "|\n";
    }
    cout << "  |  [0]  Exit                            |\n";
    cout << "  +---------------------------------------+\n";
    cout << "  Select a course: ";
}

int ExamBank::selectCourse() const {
    int choice;
    while (true) {
        displayCourseMenu();
        if (cin >> choice && choice >= 0 && choice <= courseCount) {
            cin.ignore(1000, '\n');
            return choice - 1;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Invalid choice. Please try again.\n";
    }
}

static Question makeQ(const char* q,
                      const char* a, const char* b,
                      const char* c, const char* d,
                      char ans) {
    string opts[4];
    opts[0] = a; opts[1] = b; opts[2] = c; opts[3] = d;
    return Question(string(q), opts, ans);
}

void ExamBank::loadOOPExam() {
    Exam oop("Object-Oriented Programming", "CS-201");
    oop.addQuestion(makeQ("Which concept allows a class to inherit properties from another class?","Polymorphism","Encapsulation","Inheritance","Abstraction",'C'));
    oop.addQuestion(makeQ("Which keyword is used to create an object in C++?","class","new","object","create",'B'));
    oop.addQuestion(makeQ("What is encapsulation in OOP?","Hiding implementation details inside a class","Creating multiple methods with the same name","Defining a class inside another class","Calling a function recursively",'A'));
    oop.addQuestion(makeQ("Which of the following is NOT a pillar of OOP?","Inheritance","Compilation","Polymorphism","Encapsulation",'B'));
    oop.addQuestion(makeQ("What does a constructor do?","Destroys an object","Returns a value from a method","Initialises an object when it is created","Allocates heap memory only",'C'));
    oop.addQuestion(makeQ("Which access specifier makes a member accessible only within the class?","public","protected","private","internal",'C'));
    oop.addQuestion(makeQ("What is function overloading?","Defining a function in a derived class","Multiple functions with same name but different parameters","A function that calls itself","A function with no return type",'B'));
    oop.addQuestion(makeQ("What is a virtual function used for?","Memory management","Achieving runtime polymorphism","Operator overloading","Constructor chaining",'B'));
    oop.addQuestion(makeQ("Which operator is used to access a member via a pointer?",".","::","->"," *",'C'));
    oop.addQuestion(makeQ("What is an abstract class?","A class with no members","A class that cannot be instantiated and has at least one pure virtual function","A class declared inside a function","A class with only static members",'B'));
    oop.addQuestion(makeQ("What does the 'this' pointer refer to?","The base class","The derived class","The current object","The next object in memory",'C'));
    oop.addQuestion(makeQ("Which concept allows the same function name to behave differently based on object type?","Encapsulation","Inheritance","Polymorphism","Abstraction",'C'));
    oop.addQuestion(makeQ("What is a destructor?","A function called when an object is created","A function called when an object goes out of scope or is deleted","A function that destroys static members","A friend function",'B'));
    oop.addQuestion(makeQ("What is multiple inheritance?","A class with multiple constructors","A class that inherits from more than one base class","Inheriting from a class multiple times","Having multiple objects of the same class",'B'));
    oop.addQuestion(makeQ("What keyword prevents a class from being inherited in Java/C#?","sealed","static","final","const",'C'));
    oop.addQuestion(makeQ("What is operator overloading?","Defining new operators","Giving existing operators new meanings for user-defined types","Using operators in loops","Removing default operator behaviour",'B'));
    oop.addQuestion(makeQ("What is a friend function?","A function inside a class","A function that can access private members of a class","A static member function","A function that returns an object",'B'));
    oop.addQuestion(makeQ("Which of the following is a pure virtual function declaration?","virtual void f() {}","void f() = 0;","virtual void f() = 0;","abstract void f();",'C'));
    oop.addQuestion(makeQ("What is the scope resolution operator in C++?","->","::",".",":",'B'));
    oop.addQuestion(makeQ("What does 'new' return in C++?","A reference","A value","A pointer to allocated memory","An iterator",'C'));
    courses[courseCount++] = oop;
}

void ExamBank::loadDSAExam() {
    Exam dsa("Data Structures & Algorithms", "CS-301");
    dsa.addQuestion(makeQ("Which data structure uses FIFO order?","Stack","Queue","Tree","Graph",'B'));
    dsa.addQuestion(makeQ("What is the time complexity of binary search?","O(n)","O(n^2)","O(log n)","O(1)",'C'));
    dsa.addQuestion(makeQ("Which traversal visits the root node first?","Inorder","Postorder","Preorder","Level-order",'C'));
    dsa.addQuestion(makeQ("What is a linked list?","A contiguous block of memory","A collection of nodes where each node points to the next","A key-value store","A circular array",'B'));
    dsa.addQuestion(makeQ("What does a stack's push operation do?","Remove top element","Add element to top","Search element","Sort elements",'B'));
    dsa.addQuestion(makeQ("Which sorting algorithm has worst-case O(n log n)?","Bubble Sort","Insertion Sort","Merge Sort","Selection Sort",'C'));
    dsa.addQuestion(makeQ("What is the height of a balanced binary tree with n nodes?","O(n)","O(log n)","O(n^2)","O(1)",'B'));
    dsa.addQuestion(makeQ("Which data structure is used for BFS traversal?","Stack","Priority Queue","Queue","Deque",'C'));
    dsa.addQuestion(makeQ("What is a hash collision?","Two keys mapped to the same hash index","A hash table that is full","An invalid hash function","A hash value of zero",'A'));
    dsa.addQuestion(makeQ("What is the worst-case time complexity of quicksort?","O(n log n)","O(n)","O(n^2)","O(log n)",'C'));
    dsa.addQuestion(makeQ("In a min-heap, the root always contains?","Maximum value","Median value","Minimum value","Random value",'C'));
    dsa.addQuestion(makeQ("What is a graph with no cycles called?","Directed Graph","Weighted Graph","Tree","Acyclic Graph",'D'));
    dsa.addQuestion(makeQ("Which algorithm finds the shortest path in a weighted graph?","DFS","BFS","Dijkstra's","Prim's",'C'));
    dsa.addQuestion(makeQ("What is the space complexity of merge sort?","O(1)","O(log n)","O(n)","O(n^2)",'C'));
    dsa.addQuestion(makeQ("What type of linked list has no NULL pointer at the end?","Singly Linked List","Doubly Linked List","Circular Linked List","Skip List",'C'));
    dsa.addQuestion(makeQ("Which tree property ensures O(log n) operations in an AVL tree?","Height balance","Full binary property","Complete binary property","Sorted order",'A'));
    dsa.addQuestion(makeQ("What does DFS use to keep track of visited nodes?","Queue","Stack","Heap","Array",'B'));
    dsa.addQuestion(makeQ("What is an adjacency matrix?","A list of all edges","A 2D array representing graph connections","A tree of nodes","A hash of vertices",'B'));
    dsa.addQuestion(makeQ("Which operation removes the front element from a queue?","pop","push","dequeue","peek",'C'));
    dsa.addQuestion(makeQ("What is dynamic programming?","Programming with pointers","Solving problems by breaking into overlapping subproblems and storing results","Allocating memory at runtime","A type of recursion",'B'));
    courses[courseCount++] = dsa;
}

void ExamBank::loadOSExam() {
    Exam os("Operating Systems", "CS-401");
    os.addQuestion(makeQ("What is the main function of an operating system?","Run user applications only","Manage hardware and software resources","Provide internet connectivity","Compile source code",'B'));
    os.addQuestion(makeQ("What is a process in OS terminology?","A program stored on disk","A program in execution","A thread of a program","A hardware interrupt",'B'));
    os.addQuestion(makeQ("Which scheduling algorithm can cause starvation?","Round Robin","FCFS","Priority Scheduling","Shortest Job First",'C'));
    os.addQuestion(makeQ("What is virtual memory?","RAM that is faster than cache","A technique that allows execution of processes not fully in memory","A type of ROM","Memory allocated for the OS kernel",'B'));
    os.addQuestion(makeQ("Which of the following is a deadlock condition?","Mutual Exclusion","Preemption","No Hold and Wait","Unlimited resources",'A'));
    os.addQuestion(makeQ("What does CPU scheduling decide?","Which process gets CPU time next","How much RAM a process gets","When to start the OS","Which disk sector to read",'A'));
    os.addQuestion(makeQ("What is thrashing in OS?","Too many processes running","Excessive paging causing low CPU utilisation","A CPU overheating","Disk fragmentation",'B'));
    os.addQuestion(makeQ("Which memory allocation strategy leaves the smallest leftover hole?","First Fit","Best Fit","Worst Fit","Next Fit",'B'));
    os.addQuestion(makeQ("What is a semaphore?","A CPU register","A synchronisation primitive used to control access to shared resources","A type of memory","A file descriptor",'B'));
    os.addQuestion(makeQ("What is the difference between a process and a thread?","Threads have separate memory; processes share memory","Processes have separate memory; threads share memory within a process","There is no difference","Threads are slower than processes",'B'));
    os.addQuestion(makeQ("Which page replacement algorithm replaces the least recently used page?","FIFO","Optimal","LRU","MRU",'C'));
    os.addQuestion(makeQ("What is context switching?","Switching between user and kernel mode","Saving and restoring CPU state when switching between processes","Changing the priority of a process","Allocating new memory to a process",'B'));
    os.addQuestion(makeQ("What is a critical section?","The OS kernel code","Code accessing shared resources not executable by multiple processes simultaneously","A protected memory segment","A high-priority interrupt handler",'B'));
    os.addQuestion(makeQ("Which of the following is NOT a process state?","Running","Waiting","Compiled","Ready",'C'));
    os.addQuestion(makeQ("What does RAID stand for?","Redundant Array of Independent Disks","Random Access Input Device","Rapid Array of Integrated Data","Remote Array of Interconnected Drives",'A'));
    os.addQuestion(makeQ("What is the purpose of the page table?","Store process code","Map virtual addresses to physical addresses","Track free memory blocks","Schedule CPU processes",'B'));
    os.addQuestion(makeQ("Which IPC mechanism uses shared memory?","Pipes","Message Queues","Shared Memory Segments","Sockets",'C'));
    os.addQuestion(makeQ("What is preemptive scheduling?","The OS can forcibly take CPU from a running process","A process runs until it voluntarily releases the CPU","Only one process runs at a time","Processes are scheduled in FIFO order only",'A'));
    os.addQuestion(makeQ("What is a file descriptor?","A description of a file's content","A non-negative integer used to identify an open file","A pointer to a file on disk","The file's inode number",'B'));
    os.addQuestion(makeQ("Which OS concept prevents two processes writing to the same resource simultaneously?","Paging","Segmentation","Mutual Exclusion","Virtual Memory",'C'));
    courses[courseCount++] = os;
}
