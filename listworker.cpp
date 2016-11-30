#include "listworker.h"
#include "datalayer.h"
#include <iostream>
#include <string>

using namespace std;

ListWorker::ListWorker()
{
    data.readFromFile(getPersons);
}

void ListWorker::addNewPerson(string name, char gender, int yearOfBirth, int yearOfDeath, string comment)
{

    Person p(name, gender, yearOfBirth, yearOfDeath, comment);
    getPersons.push_back(p);
    data.writeToFile(name, gender, yearOfBirth, yearOfDeath, comment);
}




void ListWorker::sortNames()
{
    data.sortNames(getPersons);
}
void ListWorker::sortBirth()
{
    data.sortBirth(getPersons);
}


bool ListWorker::removePerson(string name)
{

    for(size_t i = 0; i < getPersons.size(); ++i)
    {
        if(name == getPersons[i]._getName())
        {
            getPersons.erase(getPersons.begin() + i);
            return true;
        }
    }
    return false;
}
void ListWorker::saveFile()
{
    string saveName, saveComment;
    char saveGender;
    int saveYearOfBirth, saveYearOfDeath;
    data.deleteFile();
    for(unsigned int i = 0; i < getPersons.size(); i++)
    {
        saveName = getName(i);
        saveGender = getGender(i);
        saveYearOfBirth = getBirth(i);
        saveYearOfDeath = getDeath(i);
        saveComment = getComment(i);
        data.writeToFile(saveName, saveGender, saveYearOfBirth, saveYearOfDeath, saveComment);
    }

}
