#include "oneobj.h"

OneObj::OneObj()
{
    if(_obj==0) {
        cout<<"\n对象数目达到上限\n";
        return;
    }
    _obj--;
}

OneObj::~OneObj()
{
    _obj=1;
}

