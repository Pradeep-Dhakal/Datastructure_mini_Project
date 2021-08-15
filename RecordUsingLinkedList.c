#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Person
{
   
    char name[100];
    char phone[100];
    int C_ID;
    
    struct Person *next;
    
}* head;
void insert(int C_ID, char* name, char* phone)
{
    
    struct Person * Person = (struct Person *) malloc(sizeof(struct Person));
    Person->C_ID = C_ID;
    strcpy(Person->name, name);
    strcpy(Person->phone, phone);
    
    Person->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set Person as the new head
        head = Person;
    }
    else{
        // if list is not empty
        // insert Person in beginning of head
        Person->next = head;
        head = Person;
    }
    
}
void search(int C_ID)
{
    struct Person * temp = head;
    while(temp!=NULL){
        if(temp->C_ID==C_ID){
            printf("Citizenship number: %d\n", temp->C_ID);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
           
            return;
        }
        temp = temp->next;
    }
    printf("Person with citizenship id %d is not found !!!\n", C_ID);
}
void update(int C_ID)
{
    
    struct Person * temp = head;
    while(temp!=NULL){
        
        if(temp->C_ID==C_ID){
            printf("Record with citizenship is %d Found !!!\n", C_ID);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("Person with citizenship id %d is not found !!!\n", C_ID);
    
}
void Delete(int C_ID)
{
    struct Person * temp1 = head;
    struct Person * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->C_ID==C_ID){
            
            printf("Record with citizenship id %d Found !!!\n", C_ID);
            
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Successfully Deleted !!!\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Person with citizenship id %d is not found !!!\n", C_ID);
    
}
void display()
{
    struct Person * temp = head;
    while(temp!=NULL){
        
        
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("citizenship number: %d\n", temp->C_ID);
       
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int C_ID;
    
    printf("\n press 1 to insert details : \n press 2 to search details : \n press 3 to delete details : \n press 4 to update entered details : \n prerss 5 display all details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("enter citizenship id: ");
                scanf("%d", &C_ID);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                
                
                insert(C_ID, name, phone);
                break;
            case 2:
                printf("Enter Citizenship id to search: ");
                scanf("%d", &C_ID);
                search(C_ID);
                break;
            case 3:
                printf("Enter citizenship id to delete: ");
                scanf("%d", &C_ID);
                Delete(C_ID);
                break;
            case 4:
                printf("Enter citizenship id to update: ");
                scanf("%d", &C_ID);
                update(C_ID);
                break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);
}