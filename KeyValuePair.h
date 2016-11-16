//
// Created by Ben on 11/15/2016.
//

#ifndef DATABASEASSIGNMENT_KEYVALUEPAIR_H
#define DATABASEASSIGNMENT_KEYVALUEPAIR_H

template <typename Key, typename Value>
class KeyValuePair
{
public:
    KeyValuePair();
    ~KeyValuePair();

    Key& key();
    Value& value();


};


#endif //DATABASEASSIGNMENT_KEYVALUEPAIR_H
