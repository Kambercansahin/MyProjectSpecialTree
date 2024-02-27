#include <stdio.h>
#include <stdlib.h>
//KAMBER CAN SAHIN 	



struct node {//First, we create a node here
    int data;//then we define our data and frequency values
    int frequency;
    struct node* right;
    struct node* left;
};
struct node*IfNodeIsNull(int data ,int frekans){//Here, we ensure that it enters if the node value is NULL
	    struct node* iterNode = (struct node*)malloc(sizeof(struct node));
        iterNode->data = data;
        iterNode->frequency = frekans;
        iterNode->left = NULL;
        iterNode->right = NULL;
}
struct node* Insertial(struct node* NewNode, int data, int frequency) {//Here, we are performing the insertion operation
    if (NewNode == NULL) {//Here, if the node value is NULL, we send it to our "IfNodeIsNULL" function
        
        return IfNodeIsNull(data,frequency);
    }


    if (frequency > NewNode->frequency) {//Here, we ensure that it enters the condition if the new frequency value is greater than the value in our node.
        struct node* temp=IfNodeIsNull(data,frequency);//We define a node value named "temp" and send it to our "IfNodeIsNull" function with data and frequency values
        if(temp->data>NewNode->data){
        	temp->left=NewNode;//If our temp->data value is greater than the NewNode->data value, we set temp->left equal to "NewNode"
		}
        else{
        	temp->right=NewNode;//In the other case, we set temp->right equal to "NewNode"
		}
		return temp;
	  }

    if (data < NewNode->data) {//If the data value to be entered here is smaller than the NewNode data value, we send the NewNode->left value back to our Insertial function.
        NewNode->left = Insertial(NewNode->left, data, frequency);
    } 
	else {
        NewNode->right = Insertial(NewNode->right, data, frequency);//In the other case
    }
    return NewNode;
}
void deleteTree(struct node* root) {
    if (root == NULL) 
	    return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int Traversal(struct node* root) {//We print the data values using our Traversal function.
    if (root != NULL) {
        printf("(%d,%d) ", root->data,root->frequency);//If our root value is not null, we first print root->data to initiate Pre-order traversal.
        Traversal(root->left);//For Pre-order traversal, we then send the left child to the Traversal function.
        Traversal(root->right);//For Pre-order traversal, we then send the right child to the Traversal function.
    }
	return 1;
	}
int main() {
    
	int temp1[100][2]={0,0};//Here, I created a [100][2]-sized array to input values.
	int size=0,value;
	FILE *file=fopen("myprog.exe input.txt","r");//We define a pointer named "file" and open it for reading using the fopen function
    if(file==NULL){
    	printf("File is not find");//It enters the if condition when file == NULL.
    	return 1;
	}
    while(fscanf(file,"%d ",&value)!=EOF){
    	temp1[size][1]=0;// Here, we set [size][1] equal to 0.
    	temp1[size][0]=value;//Here,we set [size][0] equal to value.
		size++;
	}
    fclose(file);
	int numbers[size][2];
	int i,j,a,b;
	for(i=0;i<size;i++){
	    for(j=0;j<2;j++){
	     	numbers[i][j]=temp1[i][j];//We fill the temp1[i][j] array with the values of numbers[i][j] using for loops
		 }
    } 
    int searchNumber,k;//Here, we create a searchNumber and k value for searching.
	while(1){
		struct node* Head = NULL;//We define a node value named "Head" and then set it equal to NULL.
		printf("\nEnter a value to search: ");
		scanf("%d",&searchNumber);//We use scanf to prompt for the searchNumber value.
		if(searchNumber==-1){//if we want to end  the program we have to enter -1
			break;
		}
		for(k=0;k<size;k++){//We set k to zero and increment it up to the size value.
		 	if(numbers[k][0]==searchNumber){
		 		numbers[k][1]++;//If numbers[k][0] is equal to searchNumber, we increment the value of numbers[k][1].
				}
			}
		for(a=0;a<size;a++){
		    Head=Insertial(Head,numbers[a][0],numbers[a][1]);//We call the Insertial function for the Head node up to the size value.
		   }
			printf(">Pre-order traversal of constructed NewNode :");
            Traversal(Head);//
			
			deleteTree(Head);//Delete 
		}
			
	return 0;
}
