#include "LList.h"
LList::LNode::LNode ()
{ // This function will set data to 0, set value of next to NULL.
    data = 0;
    next = NULL;
}

LList::LList ()
{ // This function will set data to 0 and first to NULL.
    size = 0;
    first = NULL;
}

LList::LList (const LList & other)
{ // This function will
    first = NULL;
    last = NULL;
    size = 0;
    for (LNode * n = other.first; n != NULL; n = n->next)
        InsertLast (n->data);
}

LList::~LList ()
{ // This function will
    while (first)
        DeleteFirst();
}

LList & LList::operator = (const LList & other)
{ // This function will
    if (this == &other)
        return * this;
    while (first)
        DeleteFirst();
    for (LNode * n = other.first; n != NULL; n = n->next)
        InsertLast (n->data);
    return * this;
}

bool LList::operator == (const LList & other)
{ // This function will 
    if (size != other.size)
        return false;
    LNode * n = first;
    LNode * m = other.first;
    while (n != NULL)
    {
        if (n->data != m->data)
            return false;
        n = n->next;
        m = m->next;
    }
    return true;
}

int LList::Size () const
{ // This function will return size
	return size;
}

ostream & operator << (ostream & outs, const LList & L)
{ // This function will output the data values.
    LList::LNode * np = NULL;
    np = L.first;
    while(np != NULL)
    {
        outs << np -> data << ' ';
        np = np -> next;
    }
	return outs;
}

bool LList::InsertFirst (const int & value)
{ // This function will
    LNode * np = NULL;
    np = new LNode;
    if(np == NULL)
    {
        return false;
    }
    np -> data = value;
    np -> next = first;
    first = np;
    size++;
    return true;
}

bool LList::InsertLast (const int & value)
{ // This function will
    if (size == 0)
    {
        return InsertFirst(value);
    }
    LNode * np = first;
    LNode * mid = NULL;
    while (np != NULL)
    {
       // cout << np -> value << endl;
        mid = np;
        np = np->next;
    }
    LNode * alast = new LNode;
    if (alast == NULL)
        return false;
    cout << mid -> data << endl;
    mid -> next = alast;
    alast -> data = value;
    size++;
	return true;
}

bool LList::DeleteFirst ()
{ // This function will
	return false;
}

bool LList::DeleteLast ()
{ // This function will
	return false;
}

