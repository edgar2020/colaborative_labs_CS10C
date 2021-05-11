#include <iostream>
#include <limits>
#include "BSTree.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand

using namespace std;

using std::cout;
using std::cerr;
using std::endl;
using std::string;

void run_tests() {
    cout << "Constructing BS Tree...";
    BSTree bst = BSTree();
    cout << "complete." << endl;

    int totalTests = 0,failedTests = 0;
    totalTests++;
    cout << "Test: testing largest on empty tree...";
    if (bst.largest() == "") {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }
    totalTests++;
    cout << "Test: testing smallest on empty tree...";
    if (bst.smallest() == "") {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }
    /* Test insert (assume search works) */
    totalTests++;
    cout << "Test: testing insert and search...";
    string test_input = "Hello";
    bst.insert(test_input);
    if (bst.search(test_input)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing insert second word and search first and second...";
    string test_input2 = "World";
    bst.insert(test_input2);
    if (bst.search(test_input) && bst.search(test_input2)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing insert duplicate and search first (duplicate) and second...";
    string test_input_duplicate = "Hello";
    bst.insert(test_input_duplicate);
    if (bst.search(test_input) && bst.search(test_input2)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing remove duplicate and search first (duplicate) second...";
    bst.remove(test_input);
    if (bst.search(test_input)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    totalTests++;
    cout << "Test: testing remove first (now gone)...";
    bst.remove(test_input);
    if (!bst.search(test_input) && bst.search(test_input2)) {
        cerr << "Passed" << endl;
    } else {
        cerr << "Failed" << endl;
        failedTests++;
    }

    // TODO: Add tests for largest and smallest on non-empty trees
    // TODO: Add tests for insert and remove on larger trees
    // TODO: Add tests for height of nodes (empty and larger trees)
    // Manually inspect pre post and inorder traversals

    cout << "Passed " << totalTests - failedTests << " / " << totalTests << " tests." << endl;
}

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout<<endl;
  cout << "Inorder = ";
  tree->inOrder( );
  cout<<endl;
  cout << "Postorder = ";
  tree->postOrder( );
  cout<<endl;
}

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main( ) {
    // Pass all your tests before running the executable main
    // run_tests();  // TODO: Remove before submitting
   // return 0;

//    apple(1), cherry(1), bannana(1), watermelon(1), orange(1), date(1), dragonfruit(1), grapes(1), grapefruit(1), eggplant(1), kiwi(1), i dont know any more fruits(1), starfruit(1), pear(1), tomato(1)
    BSTree tree;
    cout<<boolalpha;
    
    vector<string> tests = {"apple", "cherry", "bannana", "bannana", "orange", "date", "dragonfruit", "grapes", "grapefruit", "eggplant", "kiwi", "i dont know any more fruits", "starfruit", "pear", "tomato", "date", "bannana", "apple", "orange", "cherry", "strawberry", "watermelon", "grape", "starfruit", "tomato", "dragonfruit", "pomegranate", "void fruit", "papaya", "mango"};
    // vector<string> tests = {"papa", "quebec", "alpha", "hotel", "india", "juliet", "kilo", "bravo", "alpha", "lima", "charlie", "alpha", "india", "delta", "epsilon", "mike", "nov", "oscar", "foxtrot", "golf"};
    // // tests = random_shuffle(tests.begin(), tests.end());
    for(string word : tests)
    {
        tree.insert(word);
    }
    // tree.remove("alpha");
    // tree.remove("bravo");
    // tree.remove("oscar");
    // tree.remove("epsilon");
    // tree.remove("lima");
    // tree.remove("alpha");
    
    // tree.remove("hotel");
    // tree.remove("alpha");
    // int num;
    // for(int i = 0; i < 40; i++)
    // {
    //   num = rand() % tests.size();
      // tree.insert(tests.at(num));
    // }

    // tree.visualizeTree("expr5.dot");
// 
    int choice = menu();

    string entry;
  
    while (choice != 8) {
    
        if (choice == 1) {
          cout << "Enter string to insert: " << endl;
          getline(cin, entry);
          tree.insert(entry);
          // tree.visualizeTree("expr5.dot");
        } else if (choice == 2) {
          cout << "Enter string to remove: " << endl;
          getline(cin, entry);
          tree.remove(entry);
          // tree.visualizeTree("expr5.dot");
        } else if (choice == 3) {
            printOrders(&tree);
        } else if (choice == 4) {
          cout << "Enter string to search for: " << endl;
          getline(cin, entry);
          if(!tree.search(entry))
            cout<<"Not Found"<<endl;
          else
            cout<<"Found"<<endl;
        } else if (choice == 5) {
          cout << "Smallest: ";
          cout<<tree.smallest() << endl;
        } else if (choice == 6) {
          cout << "Largest: ";
          cout<<tree.largest() << endl;
        } else if (choice == 7) {
          cout << "Enter string: "<<endl;
          getline(cin, entry);
          cout<<"Height of subtree rooted at "<<entry<<": "<<tree.height(entry)<<endl;
        }
        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }
    return 0;
}

/**
 * 
 * 
 * 
1
Victor
5
1
Bravo
5
1
Hotel
5
1
Charlie
5
1
Wiskey
5
1
Alpha
5
8
 * */