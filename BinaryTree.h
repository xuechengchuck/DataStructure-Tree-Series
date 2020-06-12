namespace chuckxue{
	template<class DataType>
	struct BiNode
	{
		DataType data;
		//int lvisited, rvisited;
		BiNode<DataType> *lchild, *rchild;
	};

	template<class DataType>
	class BiTree{
	public:
		BinaryTree(void){ root = StructureBiTree(root) };
		~BinaryTree(void){ DestructBiTree(root) };
		void PreOrder(void){ PreOrder(root) };
		void InOrder(void){ InOrder(root) };
		void PostOrder(void){ PostOrder(root) };

		void NonRecursivePreOrder(void){ NonRecursivePreOrder(root) };
		void NonRecursiveInOrder(void){ NonRecursiveInOrder(root) };
		void NonRecursivePostOrder(void){ NonRecursivePostOrder(root) };
	private:
		BiNode<DataType>* root;
		BiNode<DataType>* StructureBiTree(BiNode<DataType>* bt);
		void DestructBiTree(BiNode<DataType>* bt);
		void PreOrder(BiNode<DataType>* bt);
		void InOrder(BiNode<DataType>* bt);
		void PostOrder(BiNode<DataType>* bt);

		void NonRecursivePreOrder(BiNode<DataType>* bt);
		void NonRecursiveInOrder(BiNode<DataType>* bt);
		void NonRecursivePostOrder(BiNode<DataType>* bt);
	};
}