#include<iostream>
using namespace std;
class Node{
    public:
    string data;
    Node* next;
    Node(string a){
        data = a;
        next = NULL;
    }
    friend class Linkedlist;  
};
class Linkedlist{
    public:
    Node* head;
    Node* end;
    Linkedlist(){
        head =NULL;
        end =NULL;
    }
    void insert(string a){
        Node* new_node = new Node(a);
        if(head==NULL){
            head = new_node;
            end = new_node;
            head->next = NULL;
        }
        else{
            end->next = new_node;
            end = new_node;
        }
    }
    void display(){
        Node* temp = head;
        do{
            cout << temp->data <<" ";
            temp=temp->next;
        }while(temp!=NULL);

    }
    void getlist(int n){
        string str;
        for(int i=0;i<n;i++){
            cout <<"Enter name - ";
            cin >> str;
            this->insert(str);
        }
    }
    Linkedlist intersection(Linkedlist* setb){
        Node* temp = head;
        int count=0;
        Linkedlist inter;
        while(temp!=NULL){
            Node* tempb = setb->head;
            while(tempb!=NULL){
                    if(temp->data==tempb->data){
                    inter.insert(temp->data);
                }
                tempb = tempb->next;
            }
            temp = temp->next;
        }
        return inter;
    }  
    Linkedlist unnion(Linkedlist* setb){
        Node* tempa = head;
        Linkedlist un;
        while(tempa!=NULL){
            un.insert(tempa->data);
            tempa = tempa->next;
        }
        Node* tempb = setb->head;
        while(tempb!=NULL){
            int count=0;
            Node* tempi = un.head;
            while(tempi!=NULL){
                if(tempi->data==tempb->data){
                    count=1;
                }
                tempi=tempi->next;
            }
            if(count==0){
            un.insert(tempb->data);
            }
            tempb=tempb->next;
        }
        return  un;
    }
    Linkedlist difference(Linkedlist* setb){
        Node* tempa = head;
        Linkedlist diff;
        while(tempa!=NULL){
            int count=0;
            Node* tempb = setb->head;
            while(tempb !=NULL){
                if(tempa->data ==tempb->data){
                    count=1;
                }
                tempb=tempb->next;
            }
            if(count==0){
                diff.insert(tempa->data);
            }
        tempa=tempa->next;
        }
        return diff;
    }

};

int main(){
    Linkedlist clas;
    Linkedlist seta;
    Linkedlist setb;
    int c;
    cout << "Enter number of student in class"<<endl;
    cin >> c;
    clas.getlist(c);
    clas.display();
    int a;
    cout <<"Enter numnber of stundent who like vanilla icecream"<<endl;
    cin >> a;
    seta.getlist(a);
    seta.display();
    int b;
    cout <<"Enter number of studnet who like Butterscotch icecream"<<endl;
    cin >> b;
    setb.getlist(b);
    setb.display();

    Linkedlist inter=seta.intersection(&setb);
    inter.display();
    
    Linkedlist uninonlist  =seta.unnion(&setb);
    uninonlist.display();


    Linkedlist diff =  clas.difference(&inter);
    diff.display();
    
    Linkedlist diff3 = clas.difference(&uninonlist);
    diff3.display();
   

    int count=0;
    while(count==0){
        cout <<"  ****** ****** Welcome ***** *******"<<endl;
        cout <<"Choose correct option"<<endl;
        cout <<"(1) Set of students who like both vanilla and butterscotch"<<endl;
        cout <<"(2) Set of students who like either vanilla or butterscotch or not both "<<endl;
        cout <<"(3) Number of students who like neither vanilla nor butterscotch "<<endl;
        cout <<"(4) Exit"<<endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            inter.display();
            break;
        case 2:
         diff.display();
         break;
        case 3:
         diff3.display();
         break;
        case 4:
        count==1;
        default:
            break;
        }
        
    }
}
   

