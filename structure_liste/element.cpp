#include "list.h"

Element::Element(const InfoElement & _info, int id,List * _parent):
    identifiant(id),type(ELEMENT),parent(_parent),info(_info)
{
}

Element::~Element(){
    if(type==LIST)
    {
        List * tmp=static_cast<List *>(this);
        while(tmp->childCount()>0)
            delete tmp->child(0);
    }
    parent->removeChild(getNumberInParentList());
}

QString Element::getTitle()const{
    return info.title;
}

QString Element::getDescription()const
{
    return info.description;
}

QString Element::getCreationDate()const
{
    return info.creationDate;
}

QString Element::getModifDate()const
{
    return info.modificationDate;
}

List * Element::getParent()const{
    return parent;
}

int Element::getNumberInParentList()const{
    if(parent)
    {
        for(int i=0;i<parent->childCount();i++)
        {
            if(parent->child(i)==this){
                return i;
            }
        }
    }
    return 0;
}

int Element::getId()const
{
    return identifiant;
}

bool Element::isList()const{
    if(type==LIST)
        return true;
    else
        return false;
}
