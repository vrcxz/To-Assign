#ifndef TO_ASSIGN_DEADLINE_H_
#define TO_ASSIGN_DEADLINE_H_

namespace deadline {
	
/////////////////////////////////////////////////
	
	///Task Deadline Setter///
	//Actions:						//
	//								  	//
	//Add to Database		//
	//Print out Database 	//
	//Edit Progress              //
	//Delete at Database    //
	
/////////////////////////////////////////////////
	
	
	
	//MENU//
	void front_page(){
		cout<<
		"Set Task Deadlines\n\n"
		"[1] - View Task\n"
		"[2] - Add Task\n"
		"[3] - Edit Task Progress\n"
		"[4] - Delete Task\n\n";
		int choice=-1;
		
		misc::arrow();
		cin>>choice;
		
		switch(choice){
		case 1:
			view_tasks();
			break;
			
		case 2: {
			string task,date,priority;
			int progress;
			
			cout<<"Enter task: ";
			cin>>task;
			cout<<"Enter date: ";
			cin>>date;
			cout<<"Enter priority: ";
			cin>>priority;
			cout<<"Enter progress: ";
			cin>>progress;
			add_tasks(task,date,priority,progress);
			
			break;
			}
			
		case 3: {
			int id_number;
			string priority_type;
			
			cout<<"Enter id: ";
			cin>>id_number;
			cout<<"Enter priority: ";
			cin>>priority_type;
			
			edit_task_progress(id_number,priority_type);
			break; }
			
			case 4: {
				int id_number;
				
				cout<<"Enter id: ";
				cin>>id_number;
				
				delete_tasks(id_number);
				break; }
			
		default: cout<<"";
		}
	}
	
}

#endif