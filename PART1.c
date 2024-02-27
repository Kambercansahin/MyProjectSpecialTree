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

int Traversal(struct node* root) {//We print the data values using our Traversal function.
    if (root != NULL) {
        printf("%d, ", root->data);//If our root value is not null, we first print root->data to initiate Pre-order traversal.
        Traversal(root->left);//For Pre-order traversal, we then send the left child to the Traversal function.
        Traversal(root->right);//For Pre-order traversal, we then send the right child to the Traversal function.
    }
	return 1;
	}

int main() {
    struct node* Head = NULL;//We define a node value named "Head" and then set it equal to NULL.
  
    FILE *file=fopen("prj1.exe input.txt","r");//We define a pointer named "file" and open it for reading using the fopen function
    if(file==NULL){
    	printf("File is not find");//It enters the if condition when file == NULL.
    	return 1;
	}
    int valueData,valueFrequence;
    while(fscanf(file,"%d %d",&valueData,&valueFrequence)!=EOF){//It reads two integer values from the file, assigns them to the variables valueData and valueFrequency.
    	
		Head=Insertial(Head,valueData,valueFrequence);
    	
	}
    fclose(file);
	printf(">Pre-order traversal of constructed NewNode :");
    Traversal(Head);
    
    return 0;
}

