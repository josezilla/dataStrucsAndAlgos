// genSLLst.h
// generic singly linked list class with head only

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

template<class genType>
class SinglyLinkedList {
protected:	// added for compatability;
	struct Node {
		genType info;
		Node *next;
		Node() { }
		Node(genType el, Node *ptr = 0) { info = el; next = ptr; }
	} *head, *tmp;
	genType el;
public:
	SinglyLinkedList() { head = 0; }
	~SinglyLinkedList() { Clear(); }
	void Clear();
	void SetToNull()	{ head = 0; }
	void PrintAll(std::ostream& out) const; // added for compatability;
	genType* Find(const genType&) const;
	void Add(const genType& el) { head = new Node(el,head); }
	genType* Remove();			// remove the head and return its info;
	void Remove(genType&);		// find a node and remove it;
	int IsEmpty() const			{ return head == 0; }
	genType* First()			{ return &head->info; }
	Node* Head()				{ return head; }
};

template<class genType>
void
SinglyLinkedList<genType>::Clear()
{
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<class genType>
genType*
SinglyLinkedList<genType>::Remove()
{
	if (head) {					// if nonempty ist;
		el = head->info;
		tmp = head;
		head = head->next;
		delete tmp;
		return &el;
	}
	else return 0;
}

template<class genType>
void
SinglyLinkedList<genType>::PrintAll(std::ostream& out) const
{	Node *tmp;

	for (tmp = head; tmp; tmp = tmp->next)
		out << tmp->info << " ";				// overloaded <<
}

template<class genType>
genType*
SinglyLinkedList<genType>::Find(const genType& el) const
{	Node *tmp;

	for (tmp = head; tmp && !(tmp->info == el); // overloaded ==
							tmp = tmp->next);
	if (!tmp)
		return 0;
	else return &(tmp->info);
}

template<class genType>
void
SinglyLinkedList<genType>::Remove(genType& el)
{
	if (head)		// if nonempty list;
		if (el == head->info) { //if head needs to be removed;
			Node *pred = head;
			head = head->next;
			delete pred;
		}
		else {
			Node *pred;
			for (pred = head, tmp = head->next;  // non-head
				tmp && !(tmp->info == el);		// is deleted;
				pred = pred->next, tmp = tmp->next);
		if (tmp) { // if found
				pred->next = tmp->next;
				delete tmp;
			}	
		}	
}

#endif






















