#ifndef TO_ASSIGN_DATABASE_H_
#define TO_ASSIGN_DATABASE_H_

namespace database {
	
	sqlite3 *db;
	sqlite3_stmt *res;
	
}


//for printing
int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] != nullptr) {
            cout << azColName[i] << ": " << argv[i] << endl;
        } else {
            cout << azColName[i] << ": NULL" << endl;
        }
    }
    std::cout << std::endl;
    return 0;
}


//for printing in main menu
int callback_front(void* NotUsed, int argc, char** argv, char** azColName)
{
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] != nullptr) {
            cout << /*azColName[i] <<* ": " <<*/ argv[i] << " ";
        } else {
            cout << /*azColName[i] <<*/"NULL ";
        }
    }
    std::cout << std::endl;
    return 0;
}

void view_tasks_sorted(){
	string priority_types[]= {"HIGH","MEDIUM","LOW"};
	sqlite3_stmt* stmt;
    string query = "SELECT * FROM Tasks WHERE priority='HIGH';";
    
    for(int i=0; i<3 ; ++i){
    	query = "SELECT * FROM Tasks WHERE priority='"+priority_types[i]+"';";
    	
    
    sqlite3_prepare_v2(database::db, query.c_str(), -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* priority = sqlite3_column_text(stmt, 1);
        const unsigned char* task_name = sqlite3_column_text(stmt, 2);
        const unsigned char* date = sqlite3_column_text(stmt, 3);
        int progress = sqlite3_column_int(stmt, 4);

        std::cout <<priority<< " " << task_name << " " << date << " " << progress << std::endl;
    }
    }
}

void view_tasks_main(){
	string statement1 = "SELECT priority, task_name, date, progress FROM Tasks";
	
	string statement2 = "SELECT priority, task_name, date, progress FROM Tasks";
	
	string statement3 = "SELECT priority, task_name, date, progress FROM Tasks";
	
    sqlite3_exec(database::db, statement1.c_str(), callback_front, 0, NULL);
    cout<<endl;
	}

void view_tasks(){
	string statement = "SELECT id, priority, task_name, date, progress FROM Tasks";
    sqlite3_exec(database::db, statement.c_str(), callback, 0, NULL);
	}
	

void add_tasks(string task_name, string date, string priority, int progress){
	string statement = "INSERT INTO Tasks (task_name,date,priority,progress) VALUES ('"+task_name+"','"+date+"' ,'" + priority + "',  "+to_string(progress)+");";
 	sqlite3_exec(database::db,statement.c_str(),NULL,0,NULL);
	}
	
	
void edit_task_progress(int id, string progress){
	string statement = "UPDATE Tasks Set progress = '"+ progress +"' WHERE id="+ to_string(id) +";";
	sqlite3_exec(database::db,statement.c_str(),NULL,NULL,NULL);
	}
	
	
void delete_tasks(int id){
	string statement = "DELETE FROM Tasks WHERE id=" + to_string(id) + ";";
	sqlite3_exec(database::db,statement.c_str(),NULL,0,NULL);
	}



void start_database(){
		int rc = sqlite3_open("db/0001.sqlite", &database::db);
	if (rc) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(database::db) << std::endl;
        sqlite3_close(database::db);
        return;
    }
        
        
        
        char* error_message;
    rc = sqlite3_exec(database::db,  "CREATE TABLE Tasks ("
                                      "id INTEGER PRIMARY KEY,"
                                      "priority VARCHAR(255),"
                                      "task_name VARCHAR(255),"
                                      "date VARCHAR(255),"
                                      "progress VARCHAR"
                                      ");", NULL, 0, &error_message);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << error_message << std::endl;
        sqlite3_free(error_message);
    } else {
        std::cout << "Table created successfully." << std::endl;
    }
 cout<<rc;
 getch();
 
		}
	

#endif