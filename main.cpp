/*************************************************************************\
 Program      : To-Assign
 Author          : Von Ryan Nogadas
 Version        : 0.1 (Beta)
 Description : General School To-Do Task Console Assistant Application
 License        : GNU
\*************************************************************************/

///PREPROCESSORS///
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stack>
#include <vector>
#include <sstream>
#include <ctime>
#include <fstream>
#include <sqlite3.h>

//Bad practice, sorry
//extern sqlite3* db;
//extern sqlite3_stmt* res;

using namespace std;

#include "json/json.hpp"
#include "database.hpp"

#include "misc.hpp"
#include "dictionary.hpp"
#include "flashcard.hpp"
#include "notes.hpp"
#include "calendar.hpp"
#include "calculator.hpp"
#include "deadline.hpp"
#include "main_menu.hpp"
///PREPROCESSORS///



///////////////MAIN///////////////
int main()
{
	start_database();
	main_menu::main();
	
	sqlite3_finalize(database::res);
	sqlite3_close(database::db);
	return 0;
}
////////////////END////////////////
