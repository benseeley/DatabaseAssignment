//
// Created by Benjamin on 11/16/2016.
//

#ifndef DATABASEASSIGNMENT_DATABASE_H
#define DATABASEASSIGNMENT_DATABASE_H

template <typename Elem>
class DataBase
{
public:
    DataBase();
    ~DataBase();
    void insert(const Elem& elem);
    void erase(const Elem& elem);
};


#endif //DATABASEASSIGNMENT_DATABASE_H
