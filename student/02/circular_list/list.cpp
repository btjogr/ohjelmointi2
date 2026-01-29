#include "list.hh"
#include <iostream>

using namespace std;


List::List()
{

}

List::~List()
{

    while(first_!=nullptr){
        first_ = first_->next;
    }

}

void List::insert_at_the_beginning(int i)
{
    std::shared_ptr<List_item> item = std::make_shared<List_item>();

    item->data=i;

    if(first_!=nullptr){

        item->next=first_;
    }
    if(last_==nullptr){

        last_=item;
    }

    first_=item;



}

void List::insert_at_the_end(int i)
{
    std::shared_ptr<List_item> item = std::make_shared<List_item>();
    item->data=i;

    if(last_!=nullptr){

        last_->next=item;
    }
    if(first_==nullptr){

        first_=item;
    }

    last_=item;



}

void List::remove_first()
{
    if (!first_) return;

    if (first_ == last_) { // Jos listassa on vain yksi alkio
        first_ = last_ = nullptr;
    } else {
        first_ = first_->next;
    }




}

void List::remove_last()
{


    if (!first_) return;


    if (first_ == last_) { // Jos listassa on vain yksi alkio
        first_ = last_ = nullptr;
        return;
    }

    shared_ptr<List_item> sp=first_;

    while (true){


        if(sp->next==last_){

            sp->next.reset();
            last_=sp;

            break;

        }
        sp=sp->next;
    }

}

void List::print()
{
    if(first_==nullptr){
        cout<<"No elements"<<endl;
        return;
    }


    shared_ptr<List_item> sp=first_;

    cout<<"List elements:";

    while (true){

         cout<<" "<<sp->data;


        if(sp->next==nullptr){

            break;

        }
        sp=sp->next;
    }
    cout<<endl;




}

