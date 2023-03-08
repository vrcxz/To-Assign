#ifndef TO_ASSIGN_DICTIONARY_H_
#define TO_ASSIGN_DICTIONARY_H_
using json = nlohmann::json;

namespace dictionary {
	
	
	void search_dictionary(json &data, string input){
  if (data.find(input) != data.end()) {
    string text = data[input].get<string>();

    istringstream ss(text);
    string word;
    vector<string> words;

    while (std::getline(ss, word, ' ')) {
      words.push_back(word);
    }

    int character_count = 0;
    for (const auto &w : words) {
      if (w.find("--") != string::npos||w.find('.') != string::npos && isdigit(w[w.find('.') - 1])) {
        cout << endl << endl << w << " ";
        character_count = 0;
      } else if (character_count + w.length() + 1 > 50) {
        cout << endl << w << " ";
        character_count = w.length() + 1;
      } else {
        cout << w << " ";
        character_count += w.length() + 1;
      }
    }
  } else {
    cout << "\nNo such word in the directory.\n" << endl;
  }
}
	
	
	void main(){
		ifstream english_dictionary("dictionary/dictionary.json");   
    json data = json::parse(english_dictionary);
		
		string word;
		cout<<"Enter a word: ";
		cin>>word;
		search_dictionary(data,word);
		
	}
	
	
	
}

#endif