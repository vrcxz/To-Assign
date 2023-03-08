#ifndef TO_ASSIGN_H_
#define TO_ASSIGN_H_

namespace main_menu {

 void main(){
	clrscr();
	int current_page_number=0;
	int choice=-1;
	
	cout<<"To Assign\n\n";
	
	///Add deadlines list here///
	//view_tasks_main();
	view_tasks_sorted();
	cout<<"\n";
	///Add last/next page option///
	switch(current_page_number){
		case 0: cout<<"[0] - Next Page\n";
		break;
		
		default: cout<<"[0] - Last Page\n"
							 	  "[00] - Next Page\n";
	}
	
	
	std::cout<<
	"[1] - Set Task Deadline (Add/Delete/Sort)\n"
	"[2] - Notes\n"
	"[3] - Calendar\n"
	"[4] - Flashcard\n"
	"[5] - Dictionary\n"
	"[6] - Calculator \n"
	"[7] - Export\n"
	"[8] - Exit\n\n";
	
	
	///INPUT CHOICE///
	misc::arrow();
	cin>>choice;
	
	switch(choice){
		case 1: deadline::front_page();
			break;
			
		case 2: notes::main();
			break;
			
		case 3: calendar::main();
			break;
			
		case 4: flashcard::main();
			break;
			
		case 5: dictionary::main();
			break;
			
		case 6: calculator::main();
			break;
			
		case 7: //Still on the work//
		cout<<"Still in progress...\n"; getch();
			break;
			
		case 8: exit(0);
			break;
			
		default: return;
	}
	
	}

}

#endif