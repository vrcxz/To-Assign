#ifndef TO_ASSIGN_FLASHCARD_H_
#define TO_ASSIGN_FLASHCARD_H_

namespace flashcard{
	
	void start_flashcard(){
		sqlite3_stmt* stmt;
    const char* select_query = "SELECT * FROM Flashcard";
    sqlite3_prepare_v2(database::db, select_query, -1, &stmt, NULL);

    // Loop table
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* front = (const char*)sqlite3_column_text(stmt, 1); // Get front
        const char* back = (const char*)sqlite3_column_text(stmt, 2); // Get back

        // Show flashcard
        cout << "Front: " << front << endl;
        cout << "Press enter to see the answer...";
        cin.ignore(); getch();
        cout << "Back: " << back;
        cin.ignore(); getch();
        cout<<endl;
 		   }
		}
		
		
	void add_flashcard(string front, string back){
		string statement = "INSERT INTO Flashcard (front,back) VALUES ('"+front+"', '"+back+"');";
		sqlite3_exec(database::db,statement.c_str(),NULL,NULL,NULL);
		}
		
	void delete_flashcard(int id){
		string statement = "DELETE FROM Flashcard WHERE id = " + to_string(id) + ";";
		sqlite3_exec(database::db,statement.c_str(),NULL,NULL,NULL);
		
		}
		
	void create_flashcard_table(){
		string statement = "CREATE TABLE IF NOT EXISTS Flashcard (id INTEGER PRIMARY KEY AUTOINCREMENT, front TEXT, back TEXT);";
		sqlite3_exec(database::db,statement.c_str(),NULL,NULL,NULL);
		}
	
	
	
	void main(){
		create_flashcard_table();
		
		cout<<"Flashcard\n\n"
		   	     "[1] - Start Flashcard\n"
		   	     "[2] - Add Flashcard\n"
		   	     "[3] - Delete Flashcard\n"
		   	     "[4] - Exit\n\n";
		int choice = -1;
		misc::arrow();
		cin>>choice;
		switch (choice){
			case 1: start_flashcard();
				break;
			case 2: {
				string front,back;
				cout<<"Enter front text: ";
				cin>>front;
				cout<<"Enter back text: ";
				cin>>back;
				add_flashcard(front,back);
				break;}
			case 3: {
				int id_number;
				cout<<"Enter id: ";
				cin>>id_number;
				delete_flashcard(id_number);
				break;}
			case 4: return;
				break;
			default: cout<<"Invalid input."; cin.clear(); cin.ignore(); 
		}
		
		}
	
}

#endif