#ifndef MYITEM_H
#define MYITEM_H

class MyItem
{
public:
    MyItem();
    unsigned char* getItem();
    int currentItem_endPos(unsigned char *currentItem,unsigned char end);
    unsigned char* itemChange(unsigned char *currentItem);
};

#endif // MYITEM_H
