class Tree {
	public:
		class TreeNode;
		Tree()
		{
			rootPtr = NULL;
			rootPtr.setlength(0);
		}

		void CreateTree(char *x, int n);

		bool isEmpty()
		{
			return (rootPtr==NULL);
		}

		private:
			TreeNode* rootPtr;
}

class Tree::TreeNode
{
	public:
		TreeNode(int x, TreeNode *A, TreeNode *T, TreeNode *C, TreeNode *G, TreeNode *back)
		{
			length = x;

			this->A = A;
			this->G = G;
			this->C = C;
			this->T = T;
			this->back = back;
		}
		
		void setlength(int x)
		{
			length = x;
		}
		TreeNode* getback()
			{return back;}
		TreeNode* getA()
			{return A;}
		TreeNode* getC()
			{return C;}
		TreeNode* getG()
			{return G;}
		TreeNode* getT()
			{return T;}
		int getlength()
		{	return length;}
		void setA(TreeNode* ptr)
		{	A=ptr;}
		void setG(TreeNode* ptr)
		{	G=ptr;}
		void setC(TreeNode* ptr)
		{	C=ptr;}
		void setT(TreeNode* ptr)
		{	T=ptr;}
		void setback(TreeNode* ptr)
		{	back = ptr;}

	private:
		int length;
		TreeNode* A;
		TreeNode* T;
		TreeNode* C;
		TreeNode* G;
		TreeNode* back;
}
			
void Tree::CreateTree(char* x, int n)
{
	TreeNode *p = rootPtr;
	
	for(int i=0; i<n; i++)
	{
		switch(x[0])
		{
			case 'A':	
				if( p->getA == NULL)
				{
					TreeNode *a = new TreeNode(i+1, NULL, NULL, NULL, NULL, p);




		
