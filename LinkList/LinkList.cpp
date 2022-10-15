#include <iostream>
using namespace std;

class LinkList
{
    friend class List;
private:
    int data = 0;
    LinkList* next;
    LinkList* previuos;
    LinkList(int Data)
    {
        data = Data;
        next = nullptr;
        previuos = nullptr;
    }
};
class List
{
private:
    int size;
    LinkList* head;
    LinkList* end;
public:
    List()
    {
        size = 0;
        head = nullptr;
        end = nullptr;
    }
    void destroy_list()
    {
        LinkList* Distroy_List = head;
        LinkList* tmp;
        if (Distroy_List == nullptr)
            return ;
        while (Distroy_List->previuos != nullptr)
        {
            tmp = Distroy_List->previuos;
            delete Distroy_List;
            Distroy_List = tmp;
        }
        delete Distroy_List;
        size = 0;
        this->head = nullptr;
        this->end = nullptr;
    }
    void push_head(int data)
    {
        LinkList* LL_new = new LinkList(data);
        LL_new->previuos = this->head;
        LinkList* tmp = this->head;
        if (tmp != nullptr)
            tmp->next = LL_new;

        else
            this->end = LL_new;
        this->head = LL_new;
        size++;
    }
    void push_end(int data)
    {
        LinkList* ll_new = new LinkList(data);
        ll_new->next = this->end;
        LinkList* tmp = this->end;
        if (tmp != nullptr)
        {
            tmp->previuos = ll_new;
        }
        else
        {
            this->head = ll_new;
        }
        size++;
        this->end = ll_new;
    }
    void print_end()
    {
        if (this->end == nullptr)
            return;
        LinkList* tmp = this->end;
        do
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        } while (tmp != nullptr);
        cout << "______________________________\n------------------------------\n\n";
    }
    void print_head()
    {
        if (this->end == nullptr)
            return;
        LinkList* tmp = this->head;
        do
        {
            cout << tmp->data << endl;
            tmp = tmp->previuos;
        } while (tmp != nullptr);
        cout << "______________________________\n------------------------------\n\n";
    }
    int item(int item_num)
    {
        item_num--;
        List finder = *this;
        if (finder.head == nullptr)
            return NULL;
        for (int i = 0; i < item_num && finder.head->previuos != nullptr; i++)
        {
            finder.head = finder.head->previuos;
        }
        return finder.head->data;
    }
    bool find(int value) {
        if (head == nullptr)
            return false;
        
        LinkList* Founder = this->head;
        do
        {
            if (Founder->data == value)
                return true;
            Founder = Founder->previuos;
        } while (Founder != nullptr);
        return false;
    }
    bool remove(int value) {
        if (head == nullptr)
            return false;
        if (head == end)
        {
            if (head->data == value)
            {
                LinkList* remover = head;
                delete remover;
                head = nullptr;
                end = nullptr;
                size --;
                return true;
            }
            return false;
        }

        if (head != end) {

            LinkList* finder = head;
            do
            {
                if (finder->data == value)
                {
                    LinkList* deleter = finder;
                    LinkList* nexter = finder->next;
                    LinkList* previuoser = finder->previuos;
                    
                    
                    if (finder == head) {
                        previuoser->next = nexter;
                        head = previuoser;
                    }
                    else if (finder == end) {
                        nexter->previuos = previuoser;
                        end = nexter;
                    }
                    else {
                        nexter->previuos = previuoser;
                        previuoser->next = nexter;
                    }
                    delete deleter;
                    size--;
                    return true;
                }
                finder = finder->previuos;
            } while (finder != nullptr);
        }
        return false;
    }
};

int main()
{
    List* linklist = new List();

    int voroodi, init;

    while (true)
    {
        cout << "1- push new number to head\n2- push new number to end\n3- print from start"
            "\n4- print from end\n5- print item\n6- clear screen\n7- remove item\n8- find item\n0- Exit\n-> ";
        cin >> voroodi;
        switch (voroodi)
        {

        case 3:linklist->print_end();
            break;
        case 4:linklist->print_head()
            ;break;
        case 0:
            linklist->destroy_list();
            return 0;

        case 1:
            cin >> init;
            linklist->push_head(init);
            break;
        case 2:
            cin >> init;
            linklist->push_end(init);
            break;
        case 5:
            cout << "Please enter which item-> ";
            int itemnum;
            cin >> itemnum;
            cout << linklist->item(itemnum) << "\n____________________\n--------------------\n\n";
            break;
        case 6:
            system("cls");
            break;
        case 7:
            int value;
            cout << "Meghdar item -> ";
            cin >> value ;

            if (linklist->remove(value))
                cout << "Item removed" << "\n_____\n-----\n";

            else
                cout << "* Item not found *" << "\n_____\n-----\n";
            break;
        case 8:
            int value2;
            cout << "Meghdar item -> ";
            cin >> value2;
            if (linklist->find(value2)) 
                cout << "Item found"<<"\n_____\n-----\n";
            
            else
                cout << "* Item not found *" << "\n_____\n-----\n";
            break;
        }
    }
    linklist->destroy_list();
    return -1;
}