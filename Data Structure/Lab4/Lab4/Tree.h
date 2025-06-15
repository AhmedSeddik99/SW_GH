#ifndef TREE_H
#define TREE_H

#include "Node.h"
using namespace std;
class Tree
{
    Node * root;
    public:

        Tree() {
            root=NULL;
        }

        void add(int data){
            //Create Node
            Node * newNode=new Node(data);
            Node * parent=NULL;
            //1- NO Root First Node
            if(root == NULL){
                root=newNode;
            }
            else{
                  Node * current=root;
                  while(current != NULL){
                    parent=current;
                    if(data>current->data){
                        current=current->Right;
                    }
                    else{
                       current=current->Left;
                    }
                    //1 pointer,current+1
                  }
                  //Parent
                  if(data > parent->data){
                    parent->Right=newNode;
                  }
                  else{
                    parent->Left=newNode;
                  }

            }
        }

        Node * getNodeByData(int data){
            Node * current=root;
            while(current != NULL){
                if (data == current->data){
                    return current;
                }
                if(data>current->data){
                    current=current->Right;
                }
                else{
                    current=current->Left;
                }
            }
            return NULL;

        }

        void getMaxDepth(){
            cout << "Max Depth of the Tree = " << getMaxDepth(root) << endl;

        }

        void remove(int data){
          //Remove Pointers
          // Deallocate
           Node * current = getNodeByData(data);
           if(current == NULL)
                return;
           if (current==root){
                if(root->Right==NULL && root->Left==NULL){
                    root=NULL;
                }
                else if(current->Right==NULL){
                    root=root->Left;
                }
                else if(current->Left==NULL){
                    root=root->Right;
                }
                else{
                    Node * newRoot=root->Left;//40
                    Node * maxRight=getMaxRight(newRoot);//45
                    maxRight->Right=root->Right;//45->R=50->R(70)
                    root=newRoot;
                }
           }
           else{
                //Node Without Childerns
                Node * parent=getParent(current);
                Node * child=NULL;
                if(current->Left==NULL && current->Right==NULL){
                    child=NULL;
                    /*if(parent->Right==current){
                        parent->Right=NULL;
                    }
                    else{
                        parent->Left=NULL;
                    }*/
                }
                //Node With Left Childerns Only
                else if(current->Right==NULL ){
                    child=current->Left;
                    /*if(parent->Right==current){
                        parent->Right=child;
                    }
                    else{
                        parent->Left=child;
                    }*/

                }
                //Node With Right Childerns Only
                else if(current->Left==NULL){
                    child=current->Right;
                    /*if(parent->Right==current){
                        parent->Right=child;
                    }
                    else{
                        parent->Left=child;
                    }*/

                }
                //Node With Left&Right Childerns
                else{
                    Node * NewParent=current->Left;//30
                    Node * maxRight=getMaxRight(NewParent);//36
                    maxRight->Right=current->Right;//36-->43
                    child=NewParent;
                    /*if(parent->Right==current){
                        parent->Right=NewParent;
                    }
                    else{
                        parent->Left=NewParent;
                    }*/

                }

              if(parent->Right==current){
                    parent->Right=child;
                }
                else{
                    parent->Left=child;
                }

           }
          delete current;
        }
        void traverse(){
            display(root);
        }
        ~Tree() {}

    protected:

    private:
        void display(Node * node){
            if(node==NULL)
                return
            display(node->Left);//30
            cout<<node->data<<"  ";
            display(node->Right);//
        }
        Node * getMaxRight(Node * current){//(Node * current){
        //Node * current = getNodeByData(data);
          if(current != NULL){
                while(current->Right != NULL){
                    current=current->Right;
                }
                return current;
         }

        }
        Node * getParent(Node * current){//Node * node
           //Node * current = getNodeByData(data);
            if(current != NULL){
                Node * parent=root;

                while(parent != NULL){
                    if(parent->Left == current || parent->Right == current){
                        return parent;
                    }
                    if(current->data>parent->data){
                        parent=parent->Right;
                    }
                    else{
                        parent=parent->Left;
                    }

                }
            }
        }


        int getMaxDepth(Node* current){
            int depthRight;
            int depthLeft;
            int maxdepth;

            if (current == NULL)
                return 0;

            depthRight = getMaxDepth(current -> Right);
            depthLeft  = getMaxDepth(current -> Left);

            if(depthRight > depthLeft)
                maxdepth = depthRight;
            else
                maxdepth = depthLeft;

            return maxdepth + 1;

        }
};

#endif // TREE_H
