#ifndef TO_ASSIGN_NOTES_H_
#define TO_ASSIGN_NOTES_H_

namespace notes {


//void create_notes_table();
//void view_notes();
//void add_note();
//void delete_note();

void view_notes(){
	sqlite3_stmt* stmt;
    string query = "SELECT id, title FROM Notes;";
    
    
    sqlite3_prepare_v2(database::db, query.c_str(), -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* title = sqlite3_column_text(stmt, 1);
       
        std::cout <<id<< " " << title << std::endl;
    }
}



void add_note(string title, string content){
	char* error_message;
	string statement = "INSERT INTO Notes (title,content) VALUES ('"
	                   + title + "','"
	                   + content + "');";
	int rc = sqlite3_exec(database::db,statement.c_str(),NULL,NULL,&error_message);
	if (rc != SQLITE_OK) {
        std::cerr << "Error inserting notes: " << error_message << std::endl;
        sqlite3_free(error_message);
    } else {
        std::cout << "Table created successfully." << std::endl;
    }
	}

void delete_note(int id){
	string statement = "DELETE FROM Notes WHERE id=" + to_string(id) + ";";
	sqlite3_exec(database::db,statement.c_str(),NULL,NULL,NULL);
	}



void create_notes_table(){
	char* error_message;
	string statement = "CREATE TABLE IF NOT EXISTS Notes ("
	                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
	                   "title TEXT,"
	                   "content TEXT"
	                   ");";
	 int rc= sqlite3_exec(database::db,statement.c_str(),NULL,0,&error_message);
	  if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << error_message << std::endl;
        sqlite3_free(error_message);
    } else {
        std::cout << "Table created successfully." << std::endl;
    }
 cout<<rc;
 getch();
   
 
	}


void main()
{
	//create_notes_table();
	cout<<"Notes\n\n"
				"[1] - View Notes\n"
				"[2] - Add Note\n"
				"[3] - Delete Note\n"
				"[4] - Exit\n\n";
				
				misc::arrow();
				int choice=-1;
				cin>>choice;
				
				switch(choice){
					case 1: view_notes();
						break;
					
					case 2: {
						string title_name,content_name;
						cout<<"Enter title: ";
						cin>>title_name;
						cout<<"Enter content: ";
						cin>>content_name;
						add_note(title_name,content_name);
						break;}
						
					case 3: {
						int id_number;
						cout<<"Enter id: ";
						cin>>id_number;
						delete_note(id_number);
						break;}
						
					case 4: return;
						break;
						
					default: cout<<"Invalid input\n";
					}
}



}

#endif