// C++ implementation of the approach 

#include <bits/stdc++.h> 
using namespace std; 

// Structure for Trie 

struct Trie { 
	bool isEndOfName; 
	unordered_map<char, Trie*> map; 
	int marks; 
}; 


// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
	Trie* node = new Trie; 
	node->isEndOfName = false; 
	return node; 
} 


// Function to insert a student with its marks
// in the dictionary built using a Trie 


void insert(Trie*& root, const string& str, 
			const int& marks) 
{ 

	// If root is null 
	if (root == NULL) 
		root = getNewTrieNode(); 

	Trie* temp = root; 

	for (int i = 0; i < str.length(); i++) { 
		char x = str[i]; 

		// Make a new node if there is no path 
		if (temp->map.find(x) == temp->map.end()) 
			temp->map[x] = getNewTrieNode(); 

		temp = temp->map[x]; 
	} 

	// Mark end of Name and store the meaning 
	temp->isEndOfName = true; 
	temp->marks = marks; 
} 


// Function to search a student in the Trie and return its marks if it exists

 
int getMarks(Trie* root, const string& student) 
{ 

	// If root is null i.e. the dictionary is empty 
	if (root == NULL) 
		return -1; 

	Trie* temp = root; 

	// Search a student in the Trie 

	for (int i = 0; i < student.length(); i++) { 
		temp = temp->map[student[i]]; 
		if (temp == NULL) 
			return -1; 
	} 

	// If it is the end of a valid name stored then return its marks
 
	if (temp->isEndOfName) 
		return temp->marks; 
	return -1; 
} 

// Main function
 
int main() 
{ 
	Trie* root = NULL; 

	// Build the dictionary 
	insert(root, "Alice", 80); 
	insert(root, "Pooja", 85); 
	insert(root, "Ramesh", 83); 
	insert(root, "Mark", 88); 
	
	string str = "Mark"; 
	cout << getMarks(root, str); 

	return 0; 
} 