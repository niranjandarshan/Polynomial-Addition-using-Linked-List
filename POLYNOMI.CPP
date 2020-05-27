#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>

//Self referencial structure for single link list
typedef struct lklist{
	 int pow,coff;
	 struct lklist*next;

} node;
void main(){

	node *loc,*ptr,*result; //starting pointer to point first node of linklist

	char ch;
	int choice;
	clrscr();

	void insert_in(node*);
	void show_result(node*);
	void polyadd(node*,node*,node*);

		ptr=(node*)malloc(sizeof(node));
		loc=(node*)malloc(sizeof(node));
		result=(node*)malloc(sizeof(node));


		printf("\n \nThe first Polynomial:->");
		show_result(ptr);
		printf("\n\n  The second Polynomial:->");
		show_result(loc);

		printf("\n Enter all the expression for first Polynomial:->");

		insert_in(ptr);
		printf("\n Enter Second Polynomial in three expression:-");

		insert_in(loc);
		polyadd(ptr,loc,result);
		printf("\n \n Added Polynomial:->");
		show_result(result);



		  getchar();

}
//ptr for one input and loc for second input and result for saving the answer
void polyadd(node*ptr,node *loc,node*result){
       //while ptr ka next and loc ka nextpresent rhe th
   while(ptr!=NULL&&loc!=NULL){
       //checking if power are equal
	if(ptr->pow==loc->pow){
		//storing the sum in result coff
		result->coff=loc->coff + ptr->coff;
		//storing the power in result power
		result->pow=ptr->pow;
		//moving to the next of ptr and loc
		ptr=ptr->next;

		loc=loc->next;
	}
	//if power of  one polynomial is greaterthan other
       else  if(ptr->pow >loc->pow){
		result->pow=ptr->pow;
		result->coff=ptr->coff;
		ptr=ptr->next;

	}
       else {
		result->pow=loc->pow;
		result->coff=loc->coff;
		loc=loc->next;

	}
	//moving to the next of result node till NULL(for all expression in result )
	//otherwise it deote only first of the expression

	result->next=(node*)malloc(sizeof(node));
	result=result->next;
	result->next=NULL;


}
	while(ptr!=NULL||loc!=NULL){
       // Any of the unmatched power will be pointed in bothe pointer
	if(ptr->next){
		result->pow=ptr->pow;
		result->coff=ptr->coff;
		ptr=ptr->next;
	}
	if(loc->next){
		result->pow=loc->pow;
		result->coff=loc->coff;
		loc-loc->next;
	}
	//to store the data in othernode which is not matched
	result->next=(node*)malloc(sizeof(node));
	result=result->next;
	result->next=NULL;
}
}


void insert_in(node*temp){
	char ch;
	int count=1,expnum;
	printf("\n Enter number of Expression in a polynomial");
	scanf("%d",&expnum);
	while(count<=expnum){


		printf("\n Enter cofficient");
		scanf("%d",&temp->coff);
		printf("\n Enter Power");
		scanf("%d",&temp->pow);
		//to store other expressive expression after first one
		temp->next=(node*)malloc(sizeof(node));
		temp=temp->next;
		temp->next=NULL;
		count++;
		}



}
 void show_result(node*temp){
	while(temp->next!=NULL){
		printf("%dx^%d",temp->coff,temp->pow);
			temp=temp->next;
			if(temp->next!=NULL)
				printf("+");
	}
}

