//# Author : nuclear852 ========================#
//# Solution : 2328552 =========================#
//# Time Stamp : 2016-03-16 15:31:26 ===========#
//# Problem Title : 트리 =====================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
class BT{
        public:
                class BTNode;
                BT(int x, int y);
                BTNode *getrootPtr();
                void makeTree(BTNode *p,int a, int b);
                void postorder( BTNode* a);
        private:
                BTNode *rootPtr;
};

class BT::BTNode{
        private:
                int val;
                int order;
                BTNode *left;
                BTNode *right;
        public:
                BTNode(int temp=0, int y=-1){val = temp; order=y; left= NULL; right=NULL;}
                ~BTNode();
                int getvalue() {return val;}
                int getorder() {return order;}
                BTNode *getleft() {return left;}
                BTNode *getright() {return right;}
                void setleft(BTNode *a){left = a;}
                void setright(BTNode *a){right = a;}
};

BT::BTNode::~BTNode(){
        delete left;
        delete right;
}

BT::BT(int x, int y){
        BTNode *a = new BTNode(x,y);
        rootPtr = a;
}

BT::BTNode* BT::getrootPtr() { return rootPtr;}

void BT::makeTree(BTNode *p, int a, int b){
        int temp = p->getorder();
        if(b>temp)
        {
                if(p->getright() != NULL)
                        makeTree(p->getright(),a,b);
                else{
                        BTNode *newPtr = new BTNode(a,b);
                        p->setright(newPtr);
                }
        }
        else
        {
                if(p->getleft() != NULL)
                        makeTree(p->getleft(), a, b);
                else{
                        BTNode *newPtr = new BTNode(a,b);
                        p->setleft(newPtr);
                }
        }
}

void BT::postorder( BTNode *a)
{
        if(a->getleft() !=NULL)
                postorder(a->getleft());
        if(a->getright() !=NULL)
                postorder(a->getright());
        printf("%d ",a->getvalue());
}


int main(void) {
        int T;
        cin>>T;
        while(T--)
        {
                int n;
                cin>>n;
                int preorder[n];
                int inorder[n];
                int number[n];
                for(int i=0; i<n; i++)
                        scanf("%d", &preorder[i]);
                for(int i=0; i<n; i++){
                        scanf("%d", &inorder[i]);
                        number[ inorder[i]] = i;
                }

                BT Tree(preorder[0], number[preorder[0]]);
                for(int i=1; i<n; i++)
                {
                        Tree.makeTree( Tree.getrootPtr(), preorder[i], number[preorder[i]]);
                }

                Tree.postorder( Tree.getrootPtr() );
                cout<<endl;
        }
}