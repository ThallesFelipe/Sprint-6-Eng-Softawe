#ifndef FLOWHANDLE_H
#define FLOWHANDLE_H

#include <iostream>
#include <string>

#include "system.h"
#include "flow.h"
#include "handleBodySemDebug.h"

template <typename T>
class FlowHandle : public Flow, public Handle<T>
{
public:
    FlowHandle() {};

    FlowHandle(string id, System *source, System *destiny)
    {
        Handle<T>::pImpl_->setId(id);
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setDestiny(destiny);
    };

    virtual ~FlowHandle() {};

    string getId() const
    {
        return Handle<T>::pImpl_->getId();
    };

    void setId(const string id)
    {
        Handle<T>::pImpl_->setId(id);
    };

    System *getSource() const
    {
        return Handle<T>::pImpl_->getSource();
    };

    void setSource(System *source)
    {
        Handle<T>::pImpl_->setSource(source);
    };

    System *getDestiny() const
    {
        return Handle<T>::pImpl_->getDestiny();
    };

    void setDestiny(System *destiny)
    {
        return Handle<T>::pImpl_->setDestiny(destiny);
    };

    virtual float execute()
    {
        return Handle<T>::pImpl_->execute();
    };
};

#endif // FLOWHANDLE_H