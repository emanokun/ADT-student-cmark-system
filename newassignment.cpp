#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;



class Assessment{
public:
    string type;
    float mark;
    Assessment *next;
};


class Student{
public:
    string ID;
    float cmark;
    Assessment* head;
    Assessment* tail;

};

class List{
public:
    int index;
    Student* record[100];
};



int main_menu(int option){
        cout    << "CARRY MARK PROGRAM"<<endl;
        cout    <<  "1. Add new Student\n2. Update Assessment \n3. Carry mark summary\n4. Carry mark summary(update to file)\n5. Exit\n";
        cout    <<  "Select menu:";
        cin     >> option;
        return option;
}

int menu_1(int option1){
  
   cout  << "Assessment menu:\n1. Quiz\n2.Assignment \n3. Mid term test\n4.Lab exercise\n5. Back to main menu\nSelect option: ";
   cin   >> option1;
    return  option1;                        
}

int menu_2(int option2){
    cout  << "Assessment menu:\n1. Quiz\n2.Assignment \n3. Mid term test\n4.Lab exercise\n5. Back to main menu\nSelect option: ";
    cin   >> option2;
    return option2;
}

int menu_3(int option3){
   cout<<"Display Menu: "<<endl;
    cout<<"1. Individual "<<endl;
    cout<<"2. All "<<endl;
    cout<<"3. Highest carry mark"<<endl;
    cout<<"Select option: ";
    cin>>option3;
    
    return option3;
}


void pushAssessment(Assessment** headref,string new_type,int new_mark){

    Assessment* new_assessment = new Assessment();
    new_assessment->type = new_type;
    new_assessment->mark = new_mark;
    new_assessment = new_assessment->next;


}

float sumCmark(Assessment* headref, float* sumcmark){
    
    sumCmark(headref->next,sumcmark);
    *sumcmark = *sumcmark + headref->mark;

}

void pushStudent(Student** head,  string new_ID){
        float sumcmark; 
        Assessment* assessment;
        Student* new_student = new Student();
        Assessment* new_assessment = new Assessment();
        
        /*Assessment* last = NULL;
       
        new_student->ID = new_ID;
        new_student->cmark = sumCmark(assessment,&sumcmark);
        */
        new_assessment->next = new_student->head;
        new_student->head =new_assessment;
    

}

float pushCmark(Student* head, Assessment** headref){
    float sum = 0;
    Student* n = head;
    sumCmark((*headref),&sum);
    n->cmark = sum;

}

void findAssessmentMark(Assessment* headref,string type){
    Assessment* last = NULL;
    
    while(last != NULL){
    cout <<"Current percentage of " << last->type << " : " << setprecision(2) << last->mark;
    last = headref;
    headref = headref->next;
    }

}
/*
void display_individual(Student **head, Assessment **headref, string id){
    Student * p = (*head);
    Assessment * q = p->head;
    while ( id != p->ID){
           cout<<"Student ID: "<<p->ID<<endl;
           cout<<q->type<<" "<<q->mark<<endl;
           
           p -> head = p->head;
           q = q->next;
    }
    
    cout<<"End of Summary"<<endl;
    exit(0);
}
void display_all(Student **head, Assessment **headref){
    Student * p = (*head);
    Assessment * q = p->head;
    
    cout<<"STUDENT ID NO \t QUIZ \t ASSIGNMENT \t MD TEST \t LAB EXE TOTAL CMARK"<<endl;
    while(p!= NULL){
           cout<<p->ID<<"\t"<<q->mark<<"\t"<<endl;
           if(q->mark == NULL){
                cout<<"NA \t";   
           }
           p->head = q;
           q = q->next;
    }
     cout<<"End of Summary"<<endl;
    exit(0);
}
void display_highest(Student **head,Assessment **headref){
    Student * p = (*head);
    Assessment *q = p->head;
    int max = 0;
    cout<<"::Carry Mark Details::"<<endl;
    while( (*head) != NULL){
        if(max > p->cmark){
            cout<<"Student ID : "<<p->ID;
            cout<<q->type<<" : "<<q->mark<<endl;
        }
        max = p->cmark;
        p->head = q->next;
    }
    
    cout<<"End of Summary"<<endl;
    exit(0);
    
}*/


void save(Student* head,Assessment* headref){

    Student* p = head;
    Assessment* q = p -> head;
    string filename;
    ofstream myfile;
    cout << "Enter file name:";
    cin  >> filename;
    myfile.open(filename);
    while(p != NULL){
        myfile << "Student ID NO\n" << p->ID << "\n";

    
    p -> head = p->head;
    q = q->next;
    }
    
    myfile.close();

}


int main(){
    Student* head = NULL;
    Assessment* headref = NULL;
    List list;
    list.index = 0;

    int i,option,option1,option2,option3;
    char optiony;

    string studentID,typeq,IDq;
    float markq;
    float cmarkq;

    for(i=0;i<=100;i++){
    loopoption:
    do{
        system("CLS");
        
        option = main_menu(option);

        if(option==1){
            system("CLS");
           
            cout  << "::MAIN MENU:ADD NEW STUDENT::\n";
            cout  << "Enter student ID: "; 
            cin   >> studentID;
            list.record[list.index];
            pushStudent(&head,studentID);
           loopoption1:
            option1 = menu_1(option1);
             
            do{
                if(option1==1){
                    system("CLS");
                    typeq ="Quiz";
                    cout << "Enter Quiz mark(40):";
                    cin  >> markq;
                    markq = (markq/40)*15;
                    cout << "Percentage of quiz is " << markq <<"%\n ";
                    pushAssessment(&headref,typeq,markq);
                    pushCmark(head,&headref);

                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption1;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }

                }
                if(option1==2){
                    system("CLS");
                    typeq ="Midterm";
                    cout << "Enter Midterm mark(50):";
                    cin  >> markq;
                    markq = (markq/50)*20;
                    cout << "Percentage of midterm is " << markq <<"%\n ";
                    pushAssessment(&headref,typeq,markq);

                    
                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption1;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }
                }

                if(option1==3){
                    system("CLS");
                    typeq ="Assignment";
                    cout << "Enter Assignment mark(10):";
                    cin  >> markq;
                    markq = (markq/10)*10;
                    cout << "Percentage of quiz is " << markq <<"%\n ";
                   pushAssessment(&headref,typeq,markq);

                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption1;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }
                    
                }
                
                if(option1==4){
                    system("CLS");
                    typeq ="Lab Exercise";
                    cout << "Enter Lab Exercise mark(14):";
                    cin  >> markq;
                    markq = (markq/14)*15;
                    cout << "Percentage of quiz is " << markq <<"%\n ";
                    
                    pushAssessment(&headref,typeq,markq);


                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption1;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }
                    
                }
                if(option1==5){
                    goto loopoption;
                }
            
            }while(option1!=5);
            break;
        
        
        }

        
        if(option==2){
            
            int flag = 0;
            cout  << "::MAIN MENU: UPDATE CARRY MARK::\n";
            cout  << "Enter student ID : ";
            cin   >> studentID;
            Student* n = head;

            if(head==NULL){
                cout << "No student with the ID found in database";
            }    

            else{
                while(n!= NULL){
            loopoption2:
            menu_2(option2);

            do{
                if(option2==1){
                    typeq = "Quiz";
                    findAssessmentMark(headref,typeq);
            
                    cout << "Enter new Quiz mark(40):";
                    cin  >> markq;
                    markq = (markq/40)*15;
                    cout << "New Percentage of quiz is "  << setprecision(2) << markq <<"%\n ";
                    pushAssessment(&headref,typeq,markq);
                    pushCmark(head,&headref);
                    

                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption2;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }
                    

                }
                if(option2==2){
                    typeq = "Midterm";
                    findAssessmentMark(headref,typeq);
                    cout << "Enter new Midterm mark(50):";
                    cin  >> markq;
                    markq = (markq/50)*20;
                    cout << "New Percentage of Midterm is "  << setprecision(2) << markq <<"%\n ";
                    pushAssessment(&headref,typeq,markq);
                    pushCmark(head,&headref);


                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption2;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }

                }
                if(option2==3){
                    typeq = "Assignment";
                    findAssessmentMark(headref,typeq);
            
                    cout << "Enter new Assignment mark(40):"; 
                    cin  >> markq;
                    markq = (markq/10)*10;
                    cout << "New Percentage of quiz is " << setprecision(2) << markq <<"%\n ";
                    pushAssessment(&headref,typeq,markq);
                    pushCmark(head,&headref);
                    
                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption2;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }

                }
                if(option2==4){
                     typeq ="Lab Exercise";
                    findAssessmentMark(headref,typeq);
            
                    cout << "Enter new Lab exercise mark(14):";
                    cin  >> markq;
                    markq = (markq/15)*15;
                    cout << "New Percentage of lab exercise is " << setprecision(2)  << markq <<"%\n ";
                    pushAssessment(&headref,typeq,markq);
                    pushCmark(head,&headref);
                    

                            cout << "Add Another Option?[Y/N]:";
	                        cin >> optiony;
	                        if (optiony == 'Y' || optiony == 'y')
		                    {
		                        system ("CLS");
		                        goto loopoption2;
		                    }
                            else if(optiony == 'N' || optiony == 'n')
		                    {
		                        system ("CLS");
		                        goto loopoption;
		                    }

                }
                if(option2==5){
                    goto loopoption;

                }

            }while(option2!=5);
        
            }
        }  
            if (flag == 0)
			cout << "\nSearch Status: No Record found" <<endl;
        }

        
        if(option==3){
            
            system("CLS");
            cout  << "::MAIN MENU: CARRY MARK SUMMARY::\n";
            option3 = menu_3(option3);
            do{

                if(option == 1){
                    cout<<"Enter student ID :";
                
                }
                else if(option == 2){
                       
                }
                else if(option ==3){
                      
                }
                else if(option ==4){
                    goto loopoption;
                }

            }while(option3!=5);

            break;
            
        }

        
        if(option==4){
              system("CLS");
              cout  << "::MAIN MENU: CARRY MARK SUMMARY (SAVE TO FILE)::\n";
              save(head,headref);

            break;
            
        }

        
        if(option==5){
            system("CLS");
            cout << "Thank you and have a nice day!";
            
            exit(0);

            
        }

        else{
            cout <<"Wrong option!";
            goto loopoption;
        }

    }while(option!=6);
    list.record[list.index+1];
 }
    return 0;
}