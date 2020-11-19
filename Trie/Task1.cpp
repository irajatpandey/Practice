#include <bits/stdc++.h> 
using namespace std; 

// Structure for Trie 

struct Trie { 
	bool isEndOfName; 
	unordered_map<char, Trie*> map; 
	int frequency; 
}; 


// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
	Trie* node = new Trie; 
	node->isEndOfName = false; 
	return node; 
} 


// Function to insert a student with its frequency
// in the dictionary built using a Trie 


void insert(Trie*& root, const string& str, 
			const int& frequency) 
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
	temp->frequency = frequency; 
} 


// Function to search a student in the Trie and return its frequency if it exists

 int search(Trie * root, string word){
     if(root == NULL) return -1;
     Trie* temp = root; 

	// Search a student in the Trie 

	for (int i = 0; i < word.length(); i++) { 
		temp = temp->map[word[i]]; 
		if (temp == NULL) 
			return -1; 
	} 

    if (temp->isEndOfName) 
		return temp->frequency; 
    return -1;    
 }

// Main function
 
int main() 
{ 
	Trie* root = NULL; 

	// Build the dictionary 
	ifstream myFile;
	myFile.open("EnglishDictionary.csv");
	string line, word;
	string fre;
	vector<pair<string, int>> v;
	int f;

	while(getline(myFile, line)){
		stringstream ss(line);
		getline(ss, word, ',');
		getline(ss, fre, ',');
		f = stoi(fre);
		v.push_back({word,f});
	}

	for(auto it : v){
		insert(root, it.first, it.second);
	}
	

    int ans = search(root, "keyboard");
	if(ans != -1) cout << "YES " << ans << endl;
	else cout << "NO\n";

	return 0;              
} 