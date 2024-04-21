#include <iostream>
using namespace std;
#include "linkedlist1.cpp"
#ifndef container_H
#define container_H
template < class T>

class container
{
private:
    linkedlist1<T>list;
    size_t size;

public:
    container() : size(0) {}
    void Add(T element)
    {
        list.push_back(element);
        size++;
    }
    void Push_Pos(T replace, T original)
    {
        list.push_pos(replace, original);
        size++;
    }
    template <typename Y>
    void DeletePos(Y pos)
    {
        list.removeByPos(pos);
        size--;
    }
    template <typename Y>
    void DeleteVal(Y value)
    {
        list.removeByValue(value);
        size--;
    }
    void Display()
    {
        list.dispaly();
    }
    void Display(node<T>*p)
    {
        list.dispaly(p);
    }
    void Reverse()
    {
        list.reverse();
    }
    template <typename Y>
    node<T> *SearchsPos(Y pos)
    {
        return list.searchByPos(pos);
    }
    template <typename Y>
    node<T> *SearchsVal(Y value)
    {
        return list.searchByValue(value);
    }
    void Sort()
    {
        //  typename container<T>::Iterator min(list.head);
        //  typename container<T>::Iterator curr(list.head);

        // while (curr != list.end())
        // {
        //     typename container<T>::Iterator next = curr.getNode()->next;
        //     while (next != list.end())
        //     {
        //         if (*next < *min)
        //         {
        //             min = next;
        //         }
        //         ++next;
        //     }
        //     if (min != curr)
        //     {
        //         list.swap(list.head, min.getNode(), curr.getNode());
        //     }
        //     ++curr;
        //     min = curr;
        // }

        list.head = list.mergeSort(list.head);
    }
    void Merge(container<T> other)
    {
        list.merge(other.list);
    }
    class Iterator
    {
    private:
        node<T> *current;

    public:
        Iterator(node<T> *currentNode) : current(currentNode) {}

        Iterator &operator++()
        {
            if (current)
            {
                current = current->next;
            }
            return *this;
        }

        T &operator*()
        {
            return current->data;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }
        node<T> *getNode()
        {
            return current;
        };
    };
    Iterator begin()
    {
        return Iterator(list.head);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }
    void Swap(T left, T right)
    {
        list.swap(list.head, SearchsVal(left), SearchsVal(right));
    }
};
#endif
// delete by pos
//  if (pos > list.count)
//  {
//      cout << "Invalid Postion !";
//      return;
//  }
//  else if (list.isempty())
//  {
//      cout << "Your List Is Empty ,Nothing to Delete\n";
//      return;
//  }
//  bool found = false;
//  size_t counter = 1;
//  typename linkedlist1<T>::Iterator prev = list.end();
//  typename linkedlist1<T>::Iterator temp = list.begin();
//  while (temp != list.end())
//  {
//      if (counter == pos)
//      {
//          if (prev == nullptr)
//          {

//             list.head = temp.getNode()->next;
//         }
//         else
//         {
//             prev.getNode()->next = temp.getNode()->next;
//         }

//         delete temp.getNode();
//         found = true;
//         // cout << "Value : " << value << "' removed.\n";
//         break;
//     }
//     prev = temp;
//      ++temp;
//     counter++;
// }
// if (!found)
// {
//     cout << " Not Found.\n";
//     return;
// }
// typename container<T>::Iterator min = list.begin();
// // typename container<T>::Iterator prev = list.head;
// typename container<T>::Iterator start = list.begin();
// // typename container<T>::Iterator curr = start.getNode()->next;
// //   for(int i =1  ; i< list.count()-1 ; i++ )
// //   {
// //     min = start;
// //     for(int j = i+1 ; j< list.count() ; j++)
// //     {
// //         if(curr.getNode()->data < min.getNode()->data)
// //             min=curr;
// //         ++curr;
// //     }
// //     if(min != start)
// //      list.swap(list.head , min.getNode() , start.getNode());
// //     start = prev.getNode()->next;
// //     ++prev;

// //   }
// for (typename container<T>::Iterator curr = start; curr != list.end(); ++curr)
// {
//     min = curr;
//     for (typename container<T>::Iterator next = curr; next != list.end(); ++next)
//     {
//         if (*next < *min)
//             min = next;
//     }
//     if (min != curr)
//         list.swap(list.head ,min.getNode(), curr.getNode());

// }
// size--;